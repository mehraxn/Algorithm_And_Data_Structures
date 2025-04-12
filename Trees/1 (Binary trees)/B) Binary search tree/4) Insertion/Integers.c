#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;
struct node {
    int val;
    struct node* l; // Pointer to left child
    struct node* r; // Pointer to right child
};

node* new_node(int key) {

    node* n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);}

    n->val = key;

    n->l = NULL;
    n->r = NULL;
    return n;
}

node* insert_r (node* root, int key) {

        if (root == NULL)
        return new_node(key);

    if ( key < root->val)
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
    free(root);            // Free the node itself
}
