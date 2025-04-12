#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
struct node {
    char* key;      // String key stored in the node
    struct node* l; // Pointer to left child
    struct node* r; // Pointer to right child
};

node* new_node(char* key) {
    node* n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Allocate and copy the key string
    n->key = strdup(key);
    if (n->key == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(n);
        exit(1);
    }

    n->l = NULL;
    n->r = NULL;
    return n;
}

node* insert_r(node* root, char* key) {
    // If the tree is empty, create a new node and return it
    if (root == NULL)
        return new_node(key);

    if (strcmp(key, root->key) < 0)

        root->l = insert_r(root->l, key);
    else

        root->r = insert_r(root->r, key);

    return root;
}

void free_tree(node* root) {
    if (root == NULL)
        return;

    free_tree(root->l);    // Free left subtree
    free_tree(root->r);    // Free right subtree
    free(root->key);       // Free the key string
    free(root);            // Free the node itself
}

