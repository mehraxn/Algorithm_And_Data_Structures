#include <stdio.h>   // Include standard input-output library for printf function
#include <stdlib.h>  // Include standard library for memory allocation (if needed in further development)

// Define a structure for a binary tree node
typedef struct node_t node;
struct node_t {
    int key;     // Data stored in the node
    node *left;  // Pointer to the left child node
    node *right; // Pointer to the right child node
};


// Function to perform a recursive post-order traversal of the binary tree
void post_order_r(node *root) {
    if (root == NULL)  // Base case: if the node is NULL, return
        return;

    post_order_r(root->left);    // Recursively traverse the left subtree
    post_order_r(root->right);   // Recursively traverse the right subtree
    printf("%d ", root->key); // Print the key value of the current node
}
