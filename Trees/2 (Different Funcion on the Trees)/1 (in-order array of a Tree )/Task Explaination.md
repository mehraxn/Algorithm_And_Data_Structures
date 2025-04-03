# Binary Tree Inorder Traversal

## Problem Description

The task is to perform an **inorder traversal** of a binary tree. Given the root of a binary tree, the goal is to return the **inorder traversal** of its nodes' values. In an inorder traversal, the nodes are visited in the following order:

1. **Left Subtree**: Visit the left child.
2. **Root Node**: Visit the root node.
3. **Right Subtree**: Visit the right child.

This traversal ensures that the nodes are visited in a sorted order for binary search trees.

### Examples

**Example 1:**

- **Input**: `root = [1, null, 2, 3]`
- **Output**: `[1, 3, 2]`

**Example 2:**

- **Input**: `root = [1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9]`
- **Output**: `[4, 2, 6, 5, 7, 1, 3, 9, 8]`

**Example 3:**

- **Input**: `root = []`
- **Output**: `[]`

**Example 4:**

- **Input**: `root = [1]`
- **Output**: `[1]`

### Constraints
- The number of nodes in the tree is in the range `[0, 100]`.
- Each node value is between `-100` and `100`.

