// main.c
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    if (!node) return NULL;
    node->val   = val;
    node->left  = node->right = NULL;
    return node;
}

// Build BST from nums[l  r], picking mid as root each time.
struct TreeNode* buildBST(int *nums, int l, int r) {
    if (l > r)
        return NULL;
    int mid = l + (r - l) / 2;
    struct TreeNode *root = newNode(nums[mid]);
    root->left  = buildBST(nums, l,     mid - 1);
    root->right = buildBST(nums, mid + 1, r);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return NULL;
    } else {
        return buildBST(nums, 0, numsSize - 1);
    }
}

