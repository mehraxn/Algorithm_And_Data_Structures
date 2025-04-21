#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the n-ary tree nodes
typedef struct e_s_t {
    char *str;           // Identifier of the node
    int n;               // Number of children
    struct e_s_t **children; // Array of pointers to child nodes
} e_t;

// Helper function to concatenate strings
char* concatenate_strings(char **strings, int count) {
    if (count == 0) {
        return NULL; // No strings to concatenate
    }

    // Calculate total length of the resulting string
    int total_length = 0;
    for (int i = 0; i < count; i++) {
        total_length += strlen(strings[i]);
    }

    // Allocate memory for the resulting string
    char *result = (char *)malloc((total_length + 1) * sizeof(char));
    if (!result) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Concatenate strings
    result[0] = '\0'; // Initialize as an empty string
    for (int i = 0; i < count; i++) {
        strcat(result, strings[i]);
    }

    return result;
}

// Recursive function to complete the tree
void tree_complete(e_t *root) {
    if (!root) {
        return; // Base case: NULL node
    }

    // If the node has no children (leaf node), do nothing
    if (root->n == 0) {
        return;
    }

    // Recursively process all children
    for (int i = 0; i < root->n; i++) {
        tree_complete(root->children[i]);
    }

    // Collect strings from all children
    char **child_strings = (char **)malloc(root->n * sizeof(char *));
    if (!child_strings) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < root->n; i++) {
        child_strings[i] = root->children[i]->str;
    }

    // Concatenate all children's strings to form the current node's string
    root->str = concatenate_strings(child_strings, root->n);

    // Free the temporary array used for collecting child strings
    free(child_strings);
}

// Function to free the tree and its dynamically allocated memory
void free_tree(e_t *root) {
    if (!root) {
        return;
    }

    // Recursively free all children
    for (int i = 0; i < root->n; i++) {
        free_tree(root->children[i]);
    }

    // Free the node's string
    free(root->str);

    // Free the children array
    free(root->children);

    // Free the node itself
    free(root);
}

// Helper function to create a new node
e_t* create_node(const char *str, int n) {
    e_t *node = (e_t *)malloc(sizeof(e_t));
    if (!node) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    node->str = str ? strdup(str) : NULL; // Duplicate the string if provided
    node->n = n;
    node->children = n > 0 ? (e_t **)malloc(n * sizeof(e_t *)) : NULL;

    return node;
}

// Example usage
int main() {
    // Create an example tree (manually creating nodes for simplicity)
    e_t *root = create_node(NULL, 2);

    root->children[0] = create_node(NULL, 2);
    root->children[0]->children[0] = create_node("123", 0);
    root->children[0]->children[1] = create_node("XYZ", 0);

    root->children[1] = create_node(NULL, 2);
    root->children[1]->children[0] = create_node("ABC", 0);
    root->children[1]->children[1] = create_node("DEF", 0);

    // Complete the tree
    tree_complete(root);

    // Print the resulting tree's root string
    printf("Root string: %s\n", root->str);

    // Free all allocated memory
    free_tree(root);

    return 0;
}
