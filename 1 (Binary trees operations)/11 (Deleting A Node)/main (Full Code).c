#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the binary search tree (BST)
typedef struct node {
    char *key;         // Key (string) of the node
    struct node *l;    // Pointer to the left child
    struct node *r;    // Pointer to the right child
} node_t;

// Function to create a new node with the given key
node_t* create_node(char *key) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t)); // Allocate memory for a new node
    new_node->key = strdup(key);   // Duplicate the string and assign it to the node's key
    new_node->l = new_node->r = NULL; // Initialize left and right children as NULL
    return new_node;               // Return the pointer to the newly created node
}

// Function to insert a new node with the specified key into the BST
node_t* insert(node_t *root, char *key) {
    if (root == NULL)              // Base case: If the tree is empty
        return create_node(key);    // Create and return a new node as the root

    // If the key is less than the root's key, insert into the left subtree
    if (strcmp(key, root->key) < 0)
        root->l = insert(root->l, key); // Recursive call on the left child
    // If the key is greater than the root's key, insert into the right subtree
    else if (strcmp(key, root->key) > 0)
        root->r = insert(root->r, key); // Recursive call on the right child

    return root;                   // Return the root pointer after insertion
}

// Helper function to delete the maximum node in a subtree and return its key
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
    node_t *p;                     // Temporary pointer for deletion cases
    char *val;                     // To store the in-order predecessor key

    if (root == NULL)              // If the tree is empty or key not found, return NULL
        return root;

    // If the key is less than the root's key, search in the left subtree
    if (strcmp(key, root->key) < 0) {
        root->l = delete_r(root->l, key); // Recursive call on the left subtree
        return root;               // Return the root after deleting in left subtree
    }

    // If the key is greater than the root's key, search in the right subtree
    if (strcmp(key, root->key) > 0) {
        root->r = delete_r(root->r, key); // Recursive call on the right subtree
        return root;               // Return the root after deleting in right subtree
    }

    // If the key is equal to root's key, this is the node to delete
    p = root;                      // Store a reference to the node to be deleted

    // Case 1: Node with only left child
    if (root->r == NULL) {         // If there is no right child
        root = root->l;            // Replace the root with its left child
        free(p);                   // Free the memory of the deleted node
        return root;               // Return the new root of the subtree
    }

    // Case 2: Node with only right child
    if (root->l == NULL) {         // If there is no left child
        root = root->r;            // Replace the root with its right child
        free(p);                   // Free the memory of the deleted node
        return root;               // Return the new root of the subtree
    }

    // Case 3: Node with two children
    root->l = max_delete_r(&val, root->l); // Delete max node in left subtree and get its key
    root->key = val;              // Set the root's key to the in-order predecessor's key

    return root;                   // Return the root after restructuring
}

// Function to print the BST in in-order traversal (left-root-right) for sorted order
void print_in_order(node_t *root) {
    if (root != NULL) {
        print_in_order(root->l);    // Visit left subtree
        printf("%s ", root->key);   // Print root node's key
        print_in_order(root->r);    // Visit right subtree
    }
}

// Main function to test the insert, delete, and print operations
int main() {
    node_t *root = NULL;            // Initialize an empty BST

    // Insert nodes into the BST
    root = insert(root, "Mango");
    root = insert(root, "Apple");
    root = insert(root, "Peach");
    root = insert(root, "Banana");
    root = insert(root, "Cherry");

    // Print the BST in in-order traversal before deletion
    printf("BST before deletion:\n");
    print_in_order(root);           // Should print: Apple Banana Cherry Mango Peach
    printf("\n");

    // Delete the "Apple" node from the BST
    root = delete_r(root, "Apple");
    printf("BST after deleting 'Apple':\n");
    print_in_order(root);           // Check BST structure after deletion
    printf("\n");

    // Delete the "Mango" node from the BST
    root = delete_r(root, "Mango");
    printf("BST after deleting 'Mango':\n");
    print_in_order(root);           // Check BST structure after deletion
    printf("\n");

    // Free memory for all nodes (in a real program, we would free all nodes to avoid memory leaks)
    return 0;
}
