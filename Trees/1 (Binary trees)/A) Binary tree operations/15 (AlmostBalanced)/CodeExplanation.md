# README: Explanation of `isBalanced()` Implementation

This document explains the C implementation of a function that checks whether a binary tree is height-balanced.

## Problem Statement

A binary tree is **height-balanced** if for every node, the height difference between its left and right subtrees is at most 1.

---

## Code Structure

```c
#include <stdbool.h>
#include <stdlib.h>
```

These two headers are required:

* `stdbool.h` is for using the `bool` type (`true` or `false`)
* `stdlib.h` is commonly included for utility functions, though it's not strictly necessary in this snippet

```c
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
```

This defines the binary tree node structure:

* `val`: stores the integer value at the node.
* `left` and `right`: pointers to the left and right child nodes, respectively.

```c
int checkHeight(struct TreeNode *root) {
```

Defines a helper function to calculate the height of the tree while checking balance.
It returns:

* Height of the subtree (if balanced)
* `-2` if the subtree is unbalanced

```c
    int u, v;
```

Declares two integers:

* `u`: stores the height of the left subtree
* `v`: stores the height of the right subtree

```c
    if (root == NULL)
        return -1;
```

If the current node is `NULL` (i.e. empty), return height as `-1`.
This is a convention: a leaf node will have children with height `-1`, making its own height `0`.

```c
    u = checkHeight(root->left);
    if (u == -2)
        return -2;
```

* Recursively compute the height of the left subtree.
* If it returned `-2`, it means it's already unbalanced, so propagate that result upward.

```c
    v = checkHeight(root->right);
    if (v == -2)
        return -2;
```

* Same for the right subtree.

```c
    if (u - v > 1 || v - u > 1)
        return -2;
```

* Check if the height difference is more than 1.
* If yes, return `-2` to indicate imbalance.

```c
    if (u > v)
        return (u + 1);
    else
        return (v + 1);
```

* If the subtree is balanced, return its height as `max(u, v) + 1`

```c
bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -2;
}
```

* This is the main function that the user calls.
* It returns `true` if the tree is balanced, otherwise `false`.
* Internally, it uses the `checkHeight` function to determine this.

---

## Time Complexity

* **O(n)**, where `n` is the number of nodes in the tree.
* Each node is visited once.

## Space Complexity

* **O(h)**, where `h` is the height of the tree, due to recursive call stack.

---

## Summary

This implementation combines height computation and balance checking in a single traversal, making it efficient and clean. It returns a special flag (`-2`) to indicate imbalance and avoids unnecessary further computation once imbalance is found.
