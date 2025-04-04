# Symmetric Tree Project

## Problem Statement
Given the `root` of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

## Examples

### Example 1:
#### Tree Structure:
```
       1
     /   \
    2     2
   / \   / \
  3   4 4   3
```
#### Input:
```python
root = [1,2,2,3,4,4,3]
```
#### Output:
```python
True
```
#### Explanation:
The left and right subtrees are mirror images of each other.

### Example 2:
#### Tree Structure:
```
       1
     /   \
    2     2
     \     \
      3     3
```
#### Input:
```python
root = [1,2,2,null,3,null,3]
```
#### Output:
```python
False
```
#### Explanation:
The tree is not symmetric because the left subtree does not mirror the right subtree.

## Approach
To determine if a binary tree is symmetric, we need to check if the left and right subtrees are mirrors of each other. This can be achieved using recursion or an iterative approach with a queue.

### Recursive Approach:
1. If both subtrees are `None`, return `True`.
2. If one subtree is `None` while the other is not, return `False`.
3. Compare the values of both nodes.
4. Recursively check:
   - The left subtree of the left node with the right subtree of the right node.
   - The right subtree of the left node with the left subtree of the right node.

### Iterative Approach (Using Queue):
1. Use a queue to compare nodes iteratively.
2. Push both left and right subtrees into the queue.
3. While the queue is not empty:
   - Extract two nodes and compare them.
   - If they are different, return `False`.
   - If they are `None`, continue.
   - Push their children into the queue in the correct order to check mirroring.

## Code Implementation (Python)
```python
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isSymmetric(root):
    if not root:
        return True
    
    def isMirror(t1, t2):
        if not t1 and not t2:
            return True
        if not t1 or not t2:
            return False
        return (t1.val == t2.val and
                isMirror(t1.left, t2.right) and
                isMirror(t1.right, t2.left))
    
    return isMirror(root.left, root.right)
```

## Complexity Analysis
- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the tree (since each node is visited once).
- **Space Complexity**: `O(n)`, due to recursive stack space (or queue space in the iterative approach).

## Applications
- Checking for symmetry in data structures.
- Useful in graphical applications where mirroring is required.
- Helps in understanding tree traversal techniques.

## Conclusion
The problem of checking whether a tree is symmetric is a fundamental problem in tree manipulation. By using recursion or iteration, we can efficiently determine if a binary tree is symmetric.

