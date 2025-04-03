#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the binary search tree (BST)
typedef struct node {
    char *key;         // Key (string) of the node
    struct node *l;    // Pointer to the left child
    struct node *r;    // Pointer to the right child
} node_t;


// Helper function to delete the maximum node in a subtree and get its value
node_t* max_delete_r(char **val, node_t *root) {
    node_t *tmp;

    // If there is no right child, we are at the max node
    if (root->r == NULL) {
        *val = root->key;          // Set val to the key of this node (the max key)
        tmp = root->l;             // Temporarily store the left child
        free(root);                // Free memory of the max node
        return tmp;                // Return the left subtree to reconnect with the parent
    }
    // Otherwise, move to the right child
    root->r = max_delete_r(val, root->r);
    return root;                   // Return the root after deleting the max node
}

// Function to delete a node with a specified key from the BST
node_t* delete_r(node_t *root, char *key) {
    node_t *p;                     // Temporary pointer used for handling deletion cases
    char *val;                     // To store the key value of the in-order predecessor

    // Base case: If the tree is empty or the key is not found in the tree
    if (root == NULL)              // If the tree is empty or we reach a leaf with no match
        return root;

    // Step 1: Search for the node to be deleted
    // If the key to delete is less than the current node's key, move to the left subtree
    if (strcmp(key, root->key) < 0) {
        root->l = delete_r(root->l, key);  // Recursive call on the left child
        return root;                       // Return the root after deletion in the left subtree
    }

    // If the key to delete is greater than the current node's key, move to the right subtree
    if (strcmp(key, root->key) > 0) {
        root->r = delete_r(root->r, key);  // Recursive call on the right child
        return root;                       // Return the root after deletion in the right subtree
    }

    // Step 2: Node with the specified key is found (strcmp(key, root->key) == 0)
    p = root;    // Save a reference to the node to be deleted

    // Case 1: Node has no right child (only left child or no children)
    if (root->r == NULL) {          // If there's no right child
        root = root->l;             // Replace the current node with its left child
        free(p);                    // Free the memory of the deleted node
        return root;                // Return the new root of the subtree
    }

    // Case 2: Node has no left child (only right child)
    if (root->l == NULL) {          // If there's no left child
        root = root->r;             // Replace the current node with its right child
        free(p);                    // Free the memory of the deleted node
        return root;                // Return the new root of the subtree
    }

    // Case 3: Node with two children (both left and right children exist)
    // We need to replace the current node's key with the in-order predecessor's key
    // The in-order predecessor is the largest node in the left subtree
    root->l = max_delete_r(&val, root->l);  // Find and delete the max node in the left subtree
    root->key = val;                        // Set the current node's key to the in-order predecessor's key

    return root;   // Return the root after restructuring to maintain BST properties
}