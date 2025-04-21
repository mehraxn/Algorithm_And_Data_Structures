#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3 // Example constant size of the array storing BST roots

typedef struct node {
    char *key;
    struct node *left;
    struct node *right;
} node_t;

// Function prototypes
node_t *create_node(const char *key);
node_t *insert(node_t *root, const char *key);
int is_present_in_all_bsts(node_t *roots[], const char *key);
void inorder_traversal(node_t *root, node_t *roots[], int (*callback)(node_t *roots[], const char *key));
void display_common(node_t *roots[]);

// Function to create a new node
node_t *create_node(const char *key) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->key = strdup(key);
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to insert a key into the BST
node_t *insert(node_t *root, const char *key) {
    if (!root)
        return create_node(key);

    if (strcmp(key, root->key) < 0)
        root->left = insert(root->left, key);
    else if (strcmp(key, root->key) > 0)
        root->right = insert(root->right, key);

    return root;
}

// Function to check if a key is present in all BSTs
int is_present_in_all_bsts(node_t *roots[], const char *key) {
    for (int i = 0; i < N; i++) {
        node_t *current = roots[i];
        while (current) {
            int cmp = strcmp(key, current->key);
            if (cmp == 0)
                break;
            else if (cmp < 0)
                current = current->left;
            else
                current = current->right;
        }
        if (!current)
            return 0; // Key not found in one of the BSTs
    }
    return 1; // Key is present in all BSTs
}

// Inorder traversal of a BST
void inorder_traversal(node_t *root, node_t *roots[], int (*callback)(node_t *roots[], const char *key)) {
    if (!root)
        return;

    inorder_traversal(root->left, roots, callback);
    if (callback(roots, root->key))
        printf("%s\n", root->key);
    inorder_traversal(root->right, roots, callback);
}

// Function to display common strings in all BSTs
void display_common(node_t *roots[]) {
    if (!roots || !roots[0]) {
        printf("No BSTs to process\n");
        return;
    }

    inorder_traversal(roots[0], roots, is_present_in_all_bsts);
}

// Example usage
int main() {
    node_t *roots[N] = {NULL};

    // Example BSTs
    roots[0] = insert(roots[0], "apple");
    roots[0] = insert(roots[0], "banana");
    roots[0] = insert(roots[0], "cherry");

    roots[1] = insert(roots[1], "banana");
    roots[1] = insert(roots[1], "cherry");
    roots[1] = insert(roots[1], "date");

    roots[2] = insert(roots[2], "banana");
    roots[2] = insert(roots[2], "cherry");
    roots[2] = insert(roots[2], "elderberry");

    printf("Common strings in all BSTs:\n");
    display_common(roots);

    return 0;
}
