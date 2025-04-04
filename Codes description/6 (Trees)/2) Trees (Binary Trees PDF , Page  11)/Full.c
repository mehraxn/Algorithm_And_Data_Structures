#include <stdio.h>
#include <stdlib.h>

// Binary tree node definition
// This structure defines a node in a binary tree.
typedef struct node_s_binary {
    int key;  // Data field to store the key value of the node
    struct node_s_binary *l, *r; // Left and right children pointers
} node_t_binary;

// Function to create a binary tree node
// This function takes a key as input and allocates memory for a new node with the given key.
// The left and right pointers are initialized to NULL.
node_t_binary *createBinaryNode(int key) {
    node_t_binary *node = (node_t_binary *)malloc(sizeof(node_t_binary));
    node->key = key;
    node->l = node->r = NULL; // Initializing both left and right children to NULL
    return node;
}

// Pre-order traversal: Root, Left, Right
// This function traverses the tree in a pre-order manner: it first visits the root node,
// then recursively traverses the left subtree, followed by the right subtree.
void preorder_r(node_t_binary *root) {
    if (root == NULL) // Base case: if the node is NULL, simply return
        return;
    printf("%d ", root->key); // Print the value of the current node
    preorder_r(root->l); // Recur on the left subtree
    preorder_r(root->r); // Recur on the right subtree
}

// In-order traversal: Left, Root, Right
// This function traverses the tree in an in-order manner: it first recursively traverses
// the left subtree, then visits the root node, and finally traverses the right subtree.
void inorder_r(node_t_binary *root) {
    if (root == NULL) // Base case: if the node is NULL, simply return
        return;
    inorder_r(root->l); // Recur on the left subtree
    printf("%d ", root->key); // Print the value of the current node
    inorder_r(root->r); // Recur on the right subtree
}

// Post-order traversal: Left, Right, Root
// This function traverses the tree in a post-order manner: it first recursively traverses
// the left subtree, then the right subtree, and finally visits the root node.
void postorder_r(node_t_binary *root) {
    if (root == NULL) // Base case: if the node is NULL, simply return
        return;
    postorder_r(root->l); // Recur on the left subtree
    postorder_r(root->r); // Recur on the right subtree
    printf("%d ", root->key); // Print the value of the current node
}

// Example of usage
int main() {
    // Create a binary tree with at least 10 nodes
    node_t_binary *root = createBinaryNode(10);
    root->l = createBinaryNode(5);
    root->r = createBinaryNode(15);
    root->l->l = createBinaryNode(2);
    root->l->r = createBinaryNode(7);
    root->r->l = createBinaryNode(12);
    root->r->r = createBinaryNode(20);
    root->l->l->l = createBinaryNode(1);
    root->l->r->r = createBinaryNode(8);
    root->r->r->r = createBinaryNode(25);

    // Display traversal results
    printf("Pre-order Traversal: ");
    preorder_r(root);
    printf("\n");

    printf("In-order Traversal: ");
    inorder_r(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder_r(root);
    printf("\n");

    // Free memory to avoid memory leaks
    // Since memory for each node was allocated dynamically, we need to free it.
    free(root->l->l->l);
    free(root->l->l);
    free(root->l->r->r);
    free(root->l->r);
    free(root->l);
    free(root->r->l);
    free(root->r->r->r);
    free(root->r->r);
    free(root->r);
    free(root);

    return 0;
}

/*
Explanation of Functions:

1. createBinaryNode(int key):
   - This function is responsible for creating a new node in the binary tree.
   - It takes an integer key as input, allocates memory for a new node, sets the key value, and initializes left and right pointers to NULL.

2. preorder_r(node_t_binary *root):
   - This function performs a pre-order traversal of the binary tree.
   - Pre-order traversal visits the root node first, followed by the left subtree, and then the right subtree.
   - The order of printing is Root, Left, Right.

3. inorder_r(node_t_binary *root):
   - This function performs an in-order traversal of the binary tree.
   - In-order traversal visits the left subtree first, then the root node, and finally the right subtree.
   - The order of printing is Left, Root, Right. It is commonly used when you want to print values in ascending order for binary search trees.

4. postorder_r(node_t_binary *root):
   - This function performs a post-order traversal of the binary tree.
   - Post-order traversal visits the left subtree first, followed by the right subtree, and finally the root node.
   - The order of printing is Left, Right, Root. It is often used for operations like deleting nodes in the tree.

In the example usage in the main function, a binary tree with ten nodes is created. The program demonstrates the different traversal methods (pre-order, in-order, post-order) and then frees the dynamically allocated memory for each node.
*/
