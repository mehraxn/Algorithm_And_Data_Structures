#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkHeight(struct TreeNode *root) {
    int u, v;

    if (root == NULL)
        return -1;

    u = checkHeight(root->left);
    if (u == -2)
        return -2;

    v = checkHeight(root->right);
    if (v == -2)
        return -2;

    if (u - v > 1 || v - u > 1)
        return -2;

    if (u > v)
        return (u + 1);
    else
        return (v + 1);
}

bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -2;
}
