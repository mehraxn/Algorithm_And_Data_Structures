#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a linked list node
typedef struct list_node {
    int value;
    struct list_node *next;
} list_t;

// Define the structure for a BST node
typedef struct bst_node {
    char *key;
    list_t *values;
    struct bst_node *left;
    struct bst_node *right;
} bst_t;

// Function prototypes
bst_t *create_bst_node(const char *key);
list_t *create_list_node(int value);
void add_to_list(list_t **head, int value);
bst_t *insert_to_bst(bst_t *root, const char *key, int *values, int count);
void free_list(list_t *head);
void free_bst(bst_t *root);
void print_bst(const bst_t *root);
bst_t *file_to_bst_of_lists(const char *name);

// Main function
int main() {
    const char *filename = "input.txt";
    bst_t *root = file_to_bst_of_lists(filename);

    if (root) {
        printf("BST of lists:\n");
        print_bst(root);
        free_bst(root);
    } else {
        printf("Failed to process the file or empty file.\n");
    }

    return 0;
}

// Function to create a new BST node
bst_t *create_bst_node(const char *key) {
    bst_t *node = (bst_t *)malloc(sizeof(bst_t));
    node->key = strdup(key);
    node->values = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new list node
list_t *create_list_node(int value) {
    list_t *node = (list_t *)malloc(sizeof(list_t));
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to add a value to the linked list
void add_to_list(list_t **head, int value) {
    list_t *new_node = create_list_node(value);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a key and its values into the BST
bst_t *insert_to_bst(bst_t *root, const char *key, int *values, int count) {
    if (root == NULL) {
        root = create_bst_node(key);
        for (int i = 0; i < count; i++) {
            add_to_list(&root->values, values[i]);
        }
        return root;
    }

    int cmp = strcmp(key, root->key);
    if (cmp < 0) {
        root->left = insert_to_bst(root->left, key, values, count);
    } else if (cmp > 0) {
        root->right = insert_to_bst(root->right, key, values, count);
    } else {
        // If the key already exists, append values to the list
        for (int i = 0; i < count; i++) {
            add_to_list(&root->values, values[i]);
        }
    }

    return root;
}

// Function to free a linked list
void free_list(list_t *head) {
    while (head) {
        list_t *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to free a BST
void free_bst(bst_t *root) {
    if (root) {
        free_bst(root->left);
        free_bst(root->right);
        free_list(root->values);
        free(root->key);
        free(root);
    }
}

// Function to print the BST
void print_bst(const bst_t *root) {
    if (root) {
        print_bst(root->left);
        printf("%s: ", root->key);
        list_t *curr = root->values;
        while (curr) {
            printf("%d ", curr->value);
            curr = curr->next;
        }
        printf("\n");
        print_bst(root->right);
    }
}

// Function to parse the file and build the BST
bst_t *file_to_bst_of_lists(const char *name) {
    FILE *file = fopen(name, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    bst_t *root = NULL;
    char key[101];
    int count;

    while (fscanf(file, "%100s %d", key, &count) == 2) {
        int *values = (int *)malloc(count * sizeof(int));
        for (int i = 0; i < count; i++) {
            fscanf(file, "%d", &values[i]);
        }
        root = insert_to_bst(root, key, values, count);
        free(values);
    }

    fclose(file);
    return root;
}
