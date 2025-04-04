#include <stdio.h>
#include <stdlib.h>

// Binary tree node definition
typedef struct node_s_binary {
    int key;  // Key value for the node
    struct node_s_binary *l, *r;  // Pointers to left and right children
} node_t_binary;

// Fixed-size N-ary tree node definition
#define N 3
typedef struct node_s_fixed {
    int key;  // Key value for the node
    struct node_s_fixed *children[N];  // Array of pointers to children nodes (fixed-size)
} node_t_fixed;

// Dynamic-size N-ary tree node definition
typedef struct node_s_dynamic {
    int key;  // Key value for the node
    int degree;  // Number of children nodes
    struct node_s_dynamic **children;  // Pointer to an array of pointers to children nodes (dynamic-size)
} node_t_dynamic;

// Function to create a binary tree node
// This function allocates memory for a new binary tree node and initializes it with the given key.
// It sets the left and right children pointers to NULL.
node_t_binary *createBinaryNode(int key) {
    node_t_binary *node = (node_t_binary *)malloc(sizeof(node_t_binary));
    node->key = key;
    node->l = node->r = NULL;
    return node;
}

// Function to create a fixed-size N-ary tree node
// This function allocates memory for a new N-ary tree node and initializes it with the given key.
// It sets all children pointers to NULL.
node_t_fixed *createFixedNode(int key) {
    node_t_fixed *node = (node_t_fixed *)malloc(sizeof(node_t_fixed));
    node->key = key;
    for (int i = 0; i < N; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to create a dynamic-size N-ary tree node
// This function allocates memory for a new N-ary tree node and initializes it with the given key and degree.
// It allocates memory for an array of pointers to the children nodes and sets them to NULL.
node_t_dynamic *createDynamicNode(int key, int degree) {
    node_t_dynamic *node = (node_t_dynamic *)malloc(sizeof(node_t_dynamic));
    node->key = key;
    node->degree = degree;
    node->children = (node_t_dynamic **)malloc(degree * sizeof(node_t_dynamic *));
    for (int i = 0; i < degree; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Example of usage
int main() {
    // Binary tree
    // Create a binary tree root node and add two children to it
    node_t_binary *binaryRoot = createBinaryNode(10);
    binaryRoot->l = createBinaryNode(5);
    binaryRoot->r = createBinaryNode(15);

    // Fixed-size N-ary tree
    // Create a fixed-size N-ary tree root node and add two children to it
    node_t_fixed *fixedRoot = createFixedNode(1);
    fixedRoot->children[0] = createFixedNode(2);
    fixedRoot->children[1] = createFixedNode(3);

    // Dynamic-size N-ary tree
    // Create a dynamic-size N-ary tree root node with two children, and add a grandchild to one of the children
    node_t_dynamic *dynamicRoot = createDynamicNode(1, 2);
    dynamicRoot->children[0] = createDynamicNode(2, 0);
    dynamicRoot->children[1] = createDynamicNode(3, 1);
    dynamicRoot->children[1]->children[0] = createDynamicNode(4, 0);

    // Display examples
    // Print the key values of the root nodes for each tree
    printf("Binary Tree Root Key: %d\n", binaryRoot->key);
    printf("Fixed-Size N-ary Tree Root Key: %d\n", fixedRoot->key);
    printf("Dynamic-Size N-ary Tree Root Key: %d\n", dynamicRoot->key);

    // Free memory
    // Deallocate memory for binary tree nodes
    free(binaryRoot->l);
    free(binaryRoot->r);
    free(binaryRoot);

    // Deallocate memory for fixed-size N-ary tree nodes
    free(fixedRoot->children[0]);
    free(fixedRoot->children[1]);
    free(fixedRoot);

    // Deallocate memory for dynamic-size N-ary tree nodes
    free(dynamicRoot->children[1]->children[0]);
    free(dynamicRoot->children[1]);
    free(dynamicRoot->children[0]);
    free(dynamicRoot->children);
    free(dynamicRoot);

    return 0;
}

/*
Summary of Functions and Data Structures in the Code:

1. Data Structures:
   - `node_t_binary`: Represents a node in a binary tree. It contains an integer key and two pointers (`l` and `r`) to the left and right children.
   - `node_t_fixed`: Represents a node in a fixed-size N-ary tree. It contains an integer key and an array of `N` pointers to children nodes.
   - `node_t_dynamic`: Represents a node in a dynamic-size N-ary tree. It contains an integer key, an integer `degree` to store the number of children, and a pointer to an array of pointers to children nodes.

2. Functions:
   - `createBinaryNode(int key)`: Allocates memory for a binary tree node and initializes it with the given key value. The left and right child pointers are set to NULL.
   - `createFixedNode(int key)`: Allocates memory for a fixed-size N-ary tree node and initializes it with the given key value. All children pointers are set to NULL.
   - `createDynamicNode(int key, int degree)`: Allocates memory for a dynamic-size N-ary tree node and initializes it with the given key value and degree. Memory is allocated for an array of pointers to children nodes, which are set to NULL.

3. Usage Example (main function):
   - Demonstrates the creation of nodes for each of the three types of trees: binary tree, fixed-size N-ary tree, and dynamic-size N-ary tree.
   - The example also includes displaying the key values of the root nodes and freeing the allocated memory to avoid memory leaks.
*/