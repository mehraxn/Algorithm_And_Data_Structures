#include <stdio.h>

typedef struct node_t node;
struct node_t{
    int key;
    node *left;
    node *right;
};


int count (node* root){
    if (root==NULL)
        return 0;
    int l,r;

    l=count(root->left);
    r=count(root ->right);
    return (l+r+1);
}