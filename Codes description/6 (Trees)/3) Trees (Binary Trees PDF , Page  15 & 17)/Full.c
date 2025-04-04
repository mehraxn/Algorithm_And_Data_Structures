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

int main() {
    // Example usage of the functions
    node_t *root = (node_t *)malloc(sizeof(node_t));
    root->data = 1;
    root->left = (node_t *)malloc(sizeof(node_t));
    root->left->data = 2;
    root->right = (node_t *)malloc(sizeof(node_t));
    root->right->data = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;

    printf("Height of the binary tree: %d\n", height(root));
    printf("Number of nodes in the binary tree: %d\n", count(root));

    // Free the allocated memory
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

/*
Summary of Functions in the Code:

1. height(node_t *root):
   - This function calculates the height of a binary tree.
   - The height is defined as the longest path from the root to a leaf.
   - The base case returns -1 when the current node is NULL.
   - Recursively, the function calculates the height of the left and right subtrees and returns the maximum of the two, adding 1 to account for the current node.
   - The time complexity is O(n), where n is the number of nodes in the tree.

2. count(node_t *root):
   - This function counts the number of nodes in a binary tree.
   - The base case returns 0 when the current node is NULL.
   - Recursively, the function counts the nodes in the left and right subtrees and returns the sum of those counts plus 1 for the current node.
   - The time complexity is O(n), where n is the number of nodes in the tree.
*/
