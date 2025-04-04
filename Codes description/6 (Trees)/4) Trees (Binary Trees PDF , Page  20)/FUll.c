#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node for an n-ary tree
struct node {
    int data;
    int degree;  // Number of children
    struct node **children;  // Array of pointers to children
};

typedef struct node node_t;

// Function to count the number of nodes in an n-ary tree
int count(node_t *root) {
    int i, c;
    if (root == NULL)
        return 0;

    // Initialize count with 0
    c = 0;

    // Recursively count all children nodes
    for (i = 0; i < root->degree; i++) {
        c += count(root->children[i]);
    }

    // Return the count of children plus 1 for the current node
    return (c + 1);
}

// Function to compute the height of an n-ary tree
int height(node_t *root) {
    int i, tmp, max = -1;
    if (root == NULL)
        return -1;

    // Calculate the height of all children and find the maximum height
    for (i = 0; i < root->degree; i++) {
        tmp = height(root->children[i]);
        if (tmp > max)
            max = tmp;
    }

    // Return the maximum height plus 1 for the current node
    return (max + 1);
}

int main() {
    // Example usage of the n-ary tree functions
    node_t *root = (node_t *)malloc(sizeof(node_t));
    root->data = 1;
    root->degree = 2;
    root->children = (node_t **)malloc(root->degree * sizeof(node_t *));

    root->children[0] = (node_t *)malloc(sizeof(node_t));
    root->children[0]->data = 2;
    root->children[0]->degree = 0;
    root->children[0]->children = NULL;

    root->children[1] = (node_t *)malloc(sizeof(node_t));
    root->children[1]->data = 3;
    root->children[1]->degree = 0;
    root->children[1]->children = NULL;

    printf("Height of the n-ary tree: %d\n", height(root));
    printf("Number of nodes in the n-ary tree: %d\n", count(root));

    // Free the allocated memory
    free(root->children[0]);
    free(root->children[1]);
    free(root->children);
    free(root);

    return 0;
}
