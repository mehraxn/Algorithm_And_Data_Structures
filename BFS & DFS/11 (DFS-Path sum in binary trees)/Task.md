# Path Sum in Binary Trees

## Problem Statement

Given the root of a binary tree and an integer `targetSum`, determine if the tree has a **root-to-leaf path** such that the sum of all values along the path equals the `targetSum`.

### Important Definitions:
- A **root-to-leaf path** is a path from the root node to any leaf node in the tree.
- A **leaf** is a node with no children.

## Task Requirements

You are required to implement this solution in C language. Your implementation should:

1. Take a binary tree and a target sum as input
2. Determine if there exists any root-to-leaf path where the sum equals the target
3. Return `true` if such a path exists, otherwise return `false`

## Binary Tree Structure in C

For this problem, you may use the following binary tree structure:

```c
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
```

## Function Signature

Implement the following function:

```c
bool hasPathSum(struct TreeNode* root, int targetSum);
```

## Understanding the Problem

This problem asks you to:
1. Traverse the binary tree from root to leaf nodes
2. Calculate the sum of node values along each path
3. Determine if any path sum equals the target sum
4. Return `true` if such a path exists, otherwise return `false`

## Examples

### Example 1:
```
        5
       / \
      4   8
     /   / \
    11  13  4
   / \      \
  7   2      1
```

**Input:** root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22  
**Output:** true  
**Explanation:** The root-to-leaf path with the target sum is shown: 5 → 4 → 11 → 2, and 5 + 4 + 11 + 2 = 22

### Example 2:
```
    1
   / \
  2   3
```

**Input:** root = [1,2,3], targetSum = 5  
**Output:** false  
**Explanation:** There are two root-to-leaf paths in the tree:  
(1 → 2): The sum is 3.  
(1 → 3): The sum is 4.  
There is no root-to-leaf path with sum = 5.

### Example 3:
```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

### Example 4:
```
      10
     /  \
    5   15
   / \    \
  3   7   18
```

**Input:** root = [10,5,15,3,7,null,18], targetSum = 22  
**Output:** true  
**Explanation:** The root-to-leaf path with the target sum is: 10 → 5 → 7, and 10 + 5 + 7 = 22

### Example 5:
```
      1
     / \
    2   3
   /     \
  4       5
 /         \
6           7
```

**Input:** root = [1,2,3,4,null,null,5,6,null,null,7], targetSum = 10  
**Output:** false  
**Explanation:** There are three root-to-leaf paths in the tree:  
(1 → 2 → 4 → 6): The sum is 13.  
(1 → 3 → 5 → 7): The sum is 16.  
Note: The path (1 → 2) is not a valid root-to-leaf path as 2 is not a leaf node.  
None of the paths have a sum of 10.

## Edge Cases to Consider

1. **Empty Tree**: If the tree is empty, there are no paths, so return `false`.
2. **Single Node Tree**: If the tree has only one node (the root), check if the root's value equals the target sum.
3. **Negative Values**: The tree can contain negative values, so don't assume that once a path sum exceeds the target, you can stop exploring that path.

## Constraints

- The number of nodes in the tree is in the range [0, 5000].
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## Input Format

Your function will receive:
- A pointer to the root of a binary tree
- An integer representing the target sum

## Output Format

Your function should return:
- `true` if there exists at least one root-to-leaf path with sum equal to the target sum
- `false` otherwise

## Evaluation Criteria

Your solution will be evaluated based on:
1. Correctness: Does it return the correct result for all cases?
2. Efficiency: Does it have optimal time and space complexity?
3. Coding style: Is the code well-structured and easy to read?