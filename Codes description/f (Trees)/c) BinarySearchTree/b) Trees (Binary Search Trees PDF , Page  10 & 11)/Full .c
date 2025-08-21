#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct node {
    int value;            // Value of the node
    struct node *l;       // Pointer to the left child
    struct node *r;       // Pointer to the right child
} node_t;

// Recursive function to find the minimum value in the binary tree
node_t *min_r(node_t *root) {
    if (root == NULL)    // If the tree is empty, return NULL
        return NULL;
    if (root->l == NULL) // If there is no left child, this is the minimum node
        return root;
    return min_r(root->l); // Recursively search in the left subtree
}

// Recursive function to find the maximum value in the binary tree
node_t *max_r(node_t *root) {
    if (root == NULL)    // If the tree is empty, return NULL
        return NULL;
    if (root->r == NULL) // If there is no right child, this is the maximum node
        return root;
    return max_r(root->r); // Recursively search in the right subtree
}

// Iterative function to find the minimum value in the binary tree
node_t *min_i(node_t *root) {
    if (root == NULL)    // If the tree is empty, return NULL
        return NULL;
    while (root->l != NULL) // Keep going left until there are no more left children
        root = root->l;
    return root;
}

// Iterative function to find the maximum value in the binary tree
node_t *max_i(node_t *root) {
    if (root == NULL)    // If the tree is empty, return NULL
        return NULL;
    while (root->r != NULL) // Keep going right until there are no more right children
        root = root->r;
    return root;
}

// Helper function to create a new node
node_t *create_node(int value) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t)); // Allocate memory for the node
    new_node->value = value;  // Assign the value
    new_node->l = NULL;       // Initialize left child to NULL
    new_node->r = NULL;       // Initialize right child to NULL
    return new_node;
}

// Example usage
int main() {
    // Create a simple binary tree
    node_t *root = create_node(10);
    root->l = create_node(5);
    root->r = create_node(15);
    root->l->l = create_node(2);
    root->l->r = create_node(7);
    root->r->r = create_node(20);

    // Find minimum and maximum using recursive functions
    node_t *min_node_r = min_r(root);
    node_t *max_node_r = max_r(root);

    // Find minimum and maximum using iterative functions
    node_t *min_node_i = min_i(root);
    node_t *max_node_i = max_i(root);

    // Print the results
    printf("Minimum (recursive): %d\n", min_node_r->value);
    printf("Maximum (recursive): %d\n", max_node_r->value);
    printf("Minimum (iterative): %d\n", min_node_i->value);
    printf("Maximum (iterative): %d\n", max_node_i->value);

    // Free allocated memory (not fully implemented here for simplicity)
    free(root->l->l);
    free(root->l->r);
    free(root->r->r);
    free(root->l);
    free(root->r);
    free(root);

    return 0;
}

/*
 * Explanation of Functions:
 *
 * 1. `min_r(node_t *root)`:
 *    - A recursive function to find the node with the minimum value in a binary tree.
 *    - The minimum value is found by continuously traversing the left subtree.
 *
 * 2. `max_r(node_t *root)`:
 *    - A recursive function to find the node with the maximum value in a binary tree.
 *    - The maximum value is found by continuously traversing the right subtree.
 *
 * 3. `min_i(node_t *root)`:
 *    - An iterative function to find the node with the minimum value in a binary tree.
 *    - Instead of recursion, a `while` loop is used to traverse the left subtree.
 *
 * 4. `max_i(node_t *root)`:
 *    - An iterative function to find the node with the maximum value in a binary tree.
 *    - Instead of recursion, a `while` loop is used to traverse the right subtree.
 *
 * These functions are useful for finding boundary values (minimum and maximum) in a binary tree,
 * and they can be applied to binary search trees (BSTs) for more structured data queries.
 */
