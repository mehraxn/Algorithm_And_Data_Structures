#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} node;

// Check if current node's value is within (min, max)
int check(node *root, int min, int max) {
    if (root == NULL)
        return 1;
    if (root->val <= min || root->val >= max)
        return 0;
    return 1;
}

// Recursively traverse the tree, updating the allowed range.
void pre_order_util(int *flag, node *root, int min, int max) {
    if (root == NULL)
        return;

    if (!check(root, min, max)) {
        *flag = 0;
        return;  // Stop further checking on violation.
    }

    pre_order_util(flag, root->left, min, root->val);
    pre_order_util(flag, root->right, root->val, max);
}

// isValidBST uses pre_order_util to determine if the tree is a valid BST.
bool isValidBST(struct TreeNode* root) {
    int flag = 1;
    pre_order_util(&flag, root, INT_MIN, INT_MAX);
    return flag;
}
