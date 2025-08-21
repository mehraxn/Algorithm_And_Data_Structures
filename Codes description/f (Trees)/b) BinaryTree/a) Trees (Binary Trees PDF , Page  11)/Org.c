#include <stdio.h>
#include <stdlib.h>

// Binary tree node definition
typedef struct node_s_binary {
    int key;
    struct node_s_binary *l, *r;
} node_t_binary;

// Pre-order traversal: Root, Left, Right
void preorder_r(node_t_binary *root) {
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preorder_r(root->l);
    preorder_r(root->r);
}

// In-order traversal: Left, Root, Right
void inorder_r(node_t_binary *root) {
    if (root == NULL)
        return;
    inorder_r(root->l);
    printf("%d ", root->key);
    inorder_r(root->r);
}

// Post-order traversal: Left, Right, Root
void postorder_r(node_t_binary *root) {
    if (root == NULL)
        return;
    postorder_r(root->l);
    postorder_r(root->r);
    printf("%d ", root->key);
}

