# Height-Balanced Binary Tree

## Definition
A **Height-Balanced Binary Tree** is a binary tree in which the difference in height between the left and right subtrees of every node is **at most 1**. This ensures that the tree remains balanced and prevents it from degenerating into a skewed structure (which would essentially resemble a linked list).

## Formal Condition:
For each node `N` in the tree:
```
| height(left subtree) - height(right subtree) | <= 1
```

## Why Height Balance Matters:
In a balanced binary tree, operations like insertion, deletion, and searching can be performed efficiently with time complexity **O(log N)**, where `N` is the number of nodes in the tree. This efficiency is due to the reduced height compared to unbalanced trees.

## Example:
### 1. Height-Balanced Binary Tree (Balanced)
```
       10
      /  \
     5    15
    / \   /
   3   7 12
```
This tree is balanced because the height difference between the left and right subtrees of every node is at most 1.

### 2. Unbalanced Binary Tree
```
       10
      /  \
     5    15
    /       \
   3         20
               \
                25
```
In this example, the right subtree has a much greater height than the left subtree, violating the height-balanced condition.

## Types of Height-Balanced Trees:
1. **AVL Tree**: A self-balancing binary search tree (BST) where the balance factor of every node (height difference between left and right subtrees) is -1, 0, or 1.
2. **Red-Black Tree**: A balanced BST that maintains balance using specific color properties for each node.

## Benefits of Height-Balanced Trees:
- **Improved Efficiency**: Faster search, insertion, and deletion operations.
- **Logarithmic Time Complexity**: Ensures `O(log N)` performance for key operations in a large dataset.
- **Avoids Degeneration**: Prevents the tree from becoming skewed and reducing performance to `O(N)`.

In summary, a height-balanced binary tree maintains a close-to-minimum possible height, ensuring efficient performance for essential tree operations.

