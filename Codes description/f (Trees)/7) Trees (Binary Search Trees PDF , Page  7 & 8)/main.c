#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a binary tree node
typedef struct node {
    char *key;
    struct node *l, *r;
} node_t;

// Recursive implementation of search
node_t *search_r(node_t *root, char *key) {
    if (root == NULL) {
        return NULL;  // Search miss
    }
    if (strcmp(key, root->key) < 0) {
        return search_r(root->l, key);  // Left recursion
    }
    if (strcmp(key, root->key) > 0) {
        return search_r(root->r, key);  // Right recursion
    }
    return root;  // Search hit
}

// Iterative implementation of search
node_t *search_i(node_t *root, char *key) {
    while (root != NULL) {
        if (strcmp(key, root->key) == 0) {
            return root;  // Search hit
        }
        if (strcmp(key, root->key) < 0) {
            root = root->l;  // Move down left
        } else {
            root = root->r;  // Move down right
        }
    }
    return NULL;  // Search miss
}

// Utility function to create a new node
node_t *new_node(char *key) {
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->key = strdup(key);
    temp->l = temp->r = NULL;
    return temp;
}

// Utility function to insert a new node into the BST
node_t *insert(node_t *node, char *key) {
    if (node == NULL) {
        return new_node(key);
    }
    if (strcmp(key, node->key) < 0) {
        node->l = insert(node->l, key);
    } else if (strcmp(key, node->key) > 0) {
        node->r = insert(node->r, key);
    }
    return node;
}

int main() {
    // Create a sample binary search tree
    node_t *root = NULL;
    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "cherry");
    root = insert(root, "date");
    root = insert(root, "fig");
    root = insert(root, "grape");

    // Search for a key using both implementations
    char *key_to_search = "cherry";

    // Recursive search
    node_t *result_r = search_r(root, key_to_search);
    if (result_r != NULL) {
        printf("Recursive search: Found key '%s'\n", result_r->key);
    } else {
        printf("Recursive search: Key '%s' not found\n", key_to_search);
    }

    // Iterative search
    node_t *result_i = search_i(root, key_to_search);
    if (result_i != NULL) {
        printf("Iterative search: Found key '%s'\n", result_i->key);
    } else {
        printf("Iterative search: Key '%s' not found\n", key_to_search);
    }

    return 0;
}

/*
Example Execution:

The binary search tree is constructed with the following elements: "apple", "banana", "cherry", "date", "fig", "grape".

Both the recursive and iterative implementations are used to search for the key "cherry".

Output:
Recursive search: Found key 'cherry'
Iterative search: Found key 'cherry'

This shows that both recursive and iterative implementations have the same performance and yield the same result when searching for a key in the BST.
*/
