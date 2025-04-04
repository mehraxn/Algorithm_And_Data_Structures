#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right) {
        return false;
    }
    return (left->val == right->val)
           && isMirror(left->left, right->right)
           && isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) {
        return true;
    }
    return isMirror(root->left, root->right);
}

