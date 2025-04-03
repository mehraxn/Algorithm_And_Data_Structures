#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a binary search tree node
typedef struct node {
    char *key;             // Key of the node (string)
    struct node *l;        // Pointer to the left child
    struct node *r;        // Pointer to the right child
} node_t;

// Function to create a new node
node_t *new_node(char *key, node_t *left, node_t *right) {
    // Allocate memory for the new node
    node_t *n = (node_t *)malloc(sizeof(node_t));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    // Allocate memory for the key string and copy the key value
    n->key = (char *)malloc(strlen(key) + 1);
    if (n->key == NULL) {
        fprintf(stderr, "Memory allocation for key failed\n");
        exit(1);
    }
    strcpy(n->key, key);
    // Set left and right children pointers
    n->l = left;
    n->r = right;

    return n;
}

// Function to insert a key into the binary search tree
node_t *insert_i(node_t *root, char *key) {
    node_t *p, *r;

    // If the tree is empty, create a new node and return it as the root
    if (root == NULL) {
        return new_node(key, NULL, NULL);
    }

    // Traverse the tree to find the correct insertion point
    r = root;
    p = r;
    while (r != NULL) {
        p = r;
        // Compare the key to decide the direction of traversal
        r = (strcmp(key, r->key) < 0) ? r->l : r->r;
    }

    // Create a new node
    r = new_node(key, NULL, NULL);

    // Insert the new node as the left or right child of the parent
    if (strcmp(key, p->key) < 0) {
        p->l = r;
    } else {
        p->r = r;
    }

    return root;
}
