#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node_t node;
struct node_t {
    char* key;
    struct node_t* left;
    struct node_t* right;
};

node * minimum_node (node * root) {
    if (root == NULL)
        return root;

    if (root->left == NULL)
        return root;

    return minimum_node(root->left);
}