#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Helper function to perform recursive inorder traversal
void inorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return; // Base case: If the node is NULL, return

    // Traverse the left subtree
    inorderHelper(root->left, result, index);

    // Visit the current node
    result[(*index)++] = root->val;

    // Traverse the right subtree
    inorderHelper(root->right, result, index);
}

// Main function to perform inorder traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Initialize the return size to 0
    *returnSize = 0;

    // Allocate memory for the result array (maximum possible size = 100 nodes)
    int* result = (int*)malloc(100 * sizeof(int));

    // Perform the recursive traversal and fill the result array
    inorderHelper(root, result, returnSize);

    // Return the result array
    return result;
}

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Main function for testing
int main() {
    // Example: Create a binary tree
    //        1
    //         \
    //          2
    //         /
    //        3
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    // Perform inorder traversal
    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    // Print the result
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    // Free allocated memory
    free(result);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
