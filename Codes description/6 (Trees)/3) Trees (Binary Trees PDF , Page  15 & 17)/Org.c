#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node_t;

// Function to compute the height of a binary tree
int height(node_t *root) {
    int u, v;

    // Base case: if the root is NULL, return -1
    if (root == NULL)
        return -1;

    // Recursively compute the height of the left subtree
    u = height(root->left);

    // Recursively compute the height of the right subtree
    v = height(root->right);

    // Return the maximum height between left and right subtrees plus 1 for the current node
    if (u > v)
        return (u + 1);
    else
        return (v + 1);
}

// Function to count the number of nodes in a binary tree
int count(node_t *root) {
    int l, r;

    // Base case: if the root is NULL, return 0 (no nodes)
    if (root == NULL)
        return 0;

    // Recursively count the number of nodes in the left subtree
    l = count(root->left);

    // Recursively count the number of nodes in the right subtree
    r = count(root->right);

    // Return the sum of left count, right count, and 1 for the current node
    return (l + r + 1);
}
