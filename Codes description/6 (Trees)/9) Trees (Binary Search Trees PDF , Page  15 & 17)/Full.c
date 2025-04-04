#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a binary tree node
typedef struct node {
    char *key;           // Key stored in the node
    struct node *l;      // Pointer to the left child
    struct node *r;      // Pointer to the right child
} node_t;

// Function to create a new node
node_t *new_node(char *key, node_t *left, node_t *right) {
    node_t *node = (node_t *)malloc(sizeof(node_t)); // Allocate memory for the node
    node->key = strdup(key);  // Allocate memory and copy the key
    node->l = left;           // Set the left child
    node->r = right;          // Set the right child
    return node;
}

// Recursive function to insert a key into the binary tree
node_t *insert_r(node_t *root, char *key) {
    if (root == NULL)    // If the tree is empty, create a new node and return it
        return new_node(key, NULL, NULL);

    if (strcmp(key, root->key) < 0)     // If the key is less than the root's key
        root->l = insert_r(root->l, key); // Recursively insert into the left subtree
    else                                // If the key is greater or equal
        root->r = insert_r(root->r, key); // Recursively insert into the right subtree

    return root;         // Return the updated tree
}

// Iterative function to insert a key into the binary tree
node_t *insert_i(node_t *root, char *key) {
    if (root == NULL)    // If the tree is empty, create a new node and return it
        return new_node(key, NULL, NULL);

    node_t *p = root;    // Pointer to traverse the tree
    node_t *r = NULL;    // Temporary pointer for the current position

    while (p != NULL) {  // Traverse the tree until the correct position is found
        r = p;           // Store the parent node
        p = (strcmp(key, p->key) < 0) ? p->l : p->r; // Move left or right
    }

    // Create a new node at the correct position
    p = new_node(key, NULL, NULL);

    // Link the new node to its parent
    if (strcmp(key, r->key) < 0)
        r->l = p;        // Attach to the left child if key is smaller
    else
        r->r = p;        // Attach to the right child otherwise

    return root;         // Return the root of the tree
}

// Helper function to print the tree in-order
void print_in_order(node_t *root) {
    if (root != NULL) {
        print_in_order(root->l); // Visit left subtree
        printf("%s ", root->key); // Print the current node
        print_in_order(root->r); // Visit right subtree
    }
}

// Example usage
int main() {
    node_t *root = NULL; // Initialize an empty tree

    // Insert nodes using the recursive method
    root = insert_r(root, "apple");
    root = insert_r(root, "banana");
    root = insert_r(root, "cherry");

    printf("Tree after recursive inserts: ");
    print_in_order(root);
    printf("\n");

    // Insert nodes using the iterative method
    root = insert_i(root, "date");
    root = insert_i(root, "elderberry");

    printf("Tree after iterative inserts: ");
    print_in_order(root);
    printf("\n");

    // Free allocated memory (not implemented here for simplicity)

    return 0;
}

/*
 * Explanation of Functions:
 *
 * 1. `new_node(char *key, node_t *left, node_t *right)`:
 *    - Creates a new node with the specified key and left/right children.
 *    - Allocates memory dynamically for both the node and the key.
 *
 * 2. `insert_r(node_t *root, char *key)`:
 *    - Recursively inserts a key into the binary tree.
 *    - If the tree is empty, it creates a new node.
 *    - Compares the key to the root's key to decide whether to go left or right.
 *
 * 3. `insert_i(node_t *root, char *key)`:
 *    - Iteratively inserts a key into the binary tree.
 *    - Traverses the tree using a `while` loop until it finds the correct position.
 *    - Creates a new node and links it to the parent.
 *
 * 4. `print_in_order(node_t *root)`:
 *    - Performs an in-order traversal of the tree to print the keys in sorted order.
 *    - Visits the left subtree, then the root, then the right subtree.
 *
 * Binary Tree Concept:
 * - A binary tree is a hierarchical structure where each node has at most two children.
 * - In this implementation, the tree is organized as a Binary Search Tree (BST).
 * - Keys smaller than the current node are stored in the left subtree, and larger keys are stored in the right subtree.
 *
 * This code demonstrates how to build and traverse a binary tree using both recursive and iterative insertion methods.
 */
