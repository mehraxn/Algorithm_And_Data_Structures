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
    if (root == NULL)        // If the tree is empty, create a new node
        return new_node(key, NULL, NULL);

    if (strcmp(key, root->key) < 0)     // If the key is smaller, insert into the left subtree
        root->l = insert_r(root->l, key);
    else                                // If the key is larger, insert into the right subtree
        root->r = insert_r(root->r, key);

    return root;            // Return the updated tree
}

// Function for preorder traversal (Root -> Left -> Right)
void print_preorder(node_t *root) {
    if (root != NULL) {
        printf("%s ", root->key);     // Print the root node
        print_preorder(root->l);      // Visit the left subtree
        print_preorder(root->r);      // Visit the right subtree
    }
}

// Function for inorder traversal (Left -> Root -> Right)
void print_inorder(node_t *root) {
    if (root != NULL) {
        print_inorder(root->l);       // Visit the left subtree
        printf("%s ", root->key);     // Print the root node
        print_inorder(root->r);       // Visit the right subtree
    }
}

// Function for postorder traversal (Left -> Right -> Root)
void print_postorder(node_t *root) {
    if (root != NULL) {
        print_postorder(root->l);     // Visit the left subtree
        print_postorder(root->r);     // Visit the right subtree
        printf("%s ", root->key);     // Print the root node
    }
}

// Main function to demonstrate the tree
int main() {
    node_t *root = NULL;

    // Insert at least 15 names into the binary search tree
    root = insert_r(root, "Alice");
    root = insert_r(root, "Bob");
    root = insert_r(root, "Charlie");
    root = insert_r(root, "Diana");
    root = insert_r(root, "Eve");
    root = insert_r(root, "Frank");
    root = insert_r(root, "Grace");
    root = insert_r(root, "Hank");
    root = insert_r(root, "Ivy");
    root = insert_r(root, "Jack");
    root = insert_r(root, "Karen");
    root = insert_r(root, "Liam");
    root = insert_r(root, "Mona");
    root = insert_r(root, "Nina");
    root = insert_r(root, "Oscar");

    // Print the tree in preorder
    printf("Preorder traversal (Root -> Left -> Right):\n");
    print_preorder(root);
    printf("\n");

    // Print the tree in inorder
    printf("Inorder traversal (Left -> Root -> Right):\n");
    print_inorder(root);
    printf("\n");

    // Print the tree in postorder
    printf("Postorder traversal (Left -> Right -> Root):\n");
    print_postorder(root);
    printf("\n");

    // Free allocated memory (not implemented here for simplicity)
    return 0;
}

/*
 * Explanation of Traversals:
 *
 * 1. Preorder Traversal:
 *    - Visits the root node first, followed by the left subtree, then the right subtree.
 *    - Prints the nodes in the order: Root -> Left -> Right.
 *
 * 2. Inorder Traversal:
 *    - Visits the left subtree first, then the root node, and finally the right subtree.
 *    - Prints the nodes in the order: Left -> Root -> Right.
 *    - In a binary search tree, this traversal gives the keys in sorted order.
 *
 * 3. Postorder Traversal:
 *    - Visits the left subtree first, then the right subtree, and finally the root node.
 *    - Prints the nodes in the order: Left -> Right -> Root.
 *
 * This program demonstrates how to build a binary search tree, insert nodes, and traverse the tree in different ways.
 * These traversal methods can be used for various applications, such as searching, sorting, and tree structure analysis.
 */
