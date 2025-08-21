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

// Recursive function to find and remove the maximum value in a subtree
node_t *max_delete_r(char **max_key, node_t *root) {
    if (root->r == NULL) {    // If there is no right child, this is the max node
        *max_key = root->key; // Capture the key to be returned
        node_t *temp = root->l; // Save the left child
        free(root);           // Free the current node
        return temp;          // Return the left child to replace the current node
    }

    root->r = max_delete_r(max_key, root->r); // Recursively find the max node in the right subtree
    return root;           // Return the updated root
}

// Recursive function to delete a node with a specific key
node_t *delete_r(node_t *root, char *key) {
    node_t *p;             // Temporary pointer for handling the node to be deleted
    char *val;             // Temporary variable to hold replacement key

    if (root == NULL)      // If the tree is empty, return NULL
        return root;

    if (strcmp(key, root->key) < 0) {  // If the key is smaller, search in the left subtree
        root->l = delete_r(root->l, key);
        return root;
    }

    if (strcmp(key, root->key) > 0) {  // If the key is larger, search in the right subtree
        root->r = delete_r(root->r, key);
        return root;
    }

    // Node to be deleted is found
    p = root;

    if (root->r == NULL) { // Case: Node has no right child
        root = root->l;    // Replace the node with its left child
        free(p);           // Free the memory of the deleted node
        return root;
    }

    if (root->l == NULL) { // Case: Node has no left child
        root = root->r;    // Replace the node with its right child
        free(p);           // Free the memory of the deleted node
        return root;
    }

    // Case: Node has two children
    root->l = max_delete_r(&val, root->l); // Replace with the maximum value from the left subtree
    root->key = val;                       // Update the key with the max value

    return root;         // Return the updated root
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
    node_t *root = NULL;

    // Helper function for inserting nodes (same as `insert_r` from earlier)
    node_t *insert_r(node_t *root, char *key) {
        if (root == NULL)
            return new_node(key, NULL, NULL);
        if (strcmp(key, root->key) < 0)
            root->l = insert_r(root->l, key);
        else
            root->r = insert_r(root->r, key);
        return root;
    }

    // Insert some nodes
    root = insert_r(root, "apple");
    root = insert_r(root, "banana");
    root = insert_r(root, "cherry");
    root = insert_r(root, "date");
    root = insert_r(root, "elderberry");

    printf("Tree before deletion: ");
    print_in_order(root);
    printf("\n");

    // Delete a node
    root = delete_r(root, "cherry");

    printf("Tree after deleting 'cherry': ");
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
 *    - Dynamically allocates memory for both the node and the key string.
 *
 * 2. `max_delete_r(char **max_key, node_t *root)`:
 *    - Finds and deletes the node with the maximum value in a subtree.
 *    - Returns the maximum value via a pointer and adjusts the tree structure.
 *    - Useful for replacing a node during deletion in a binary tree.
 *
 * 3. `delete_r(node_t *root, char *key)`:
 *    - Deletes a node with the specified key from the binary tree.
 *    - Handles three cases:
 *      a) Node has no children (simply deletes it).
 *      b) Node has one child (replaces the node with its child).
 *      c) Node has two children (replaces the node with the maximum value from the left subtree).
 *
 * 4. `print_in_order(node_t *root)`:
 *    - Prints the keys in the binary tree in ascending order.
 *    - Useful for verifying the tree structure after operations like insertion or deletion.
 *
 * Binary Tree Deletion:
 * - Deletion in a binary search tree ensures the tree remains a valid BST.
 * - The use of `max_delete_r` to replace a node with two children helps maintain the tree's order property.
 *
 * This code demonstrates dynamic memory allocation, recursive tree manipulation, and structured traversal.
 */
