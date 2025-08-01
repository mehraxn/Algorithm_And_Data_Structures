// main.c
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode* newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    if (!node) return NULL;
    node->val   = val;
    node->left  = node->right = NULL;
    return node;
}

static struct TreeNode* insert(struct TreeNode *root, int val) {
    if (!root)
        return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    // WE IGNORE ANY KIND OF DUPLICATE
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    struct TreeNode *root = newNode(nums[0]);
    for (int i = 1; i < numsSize; i++)
        insert(root, nums[i]);
    return root;
}
