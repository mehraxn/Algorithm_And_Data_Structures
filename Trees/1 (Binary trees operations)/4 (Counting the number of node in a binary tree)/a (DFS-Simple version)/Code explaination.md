# Counting the Nodes of a Binary Tree

## Overview
This program defines a binary tree structure and implements a function to count the number of nodes in the tree. The counting is performed using a recursive Depth-First Search (DFS) approach.

## Code Explanation

```c
#include <stdio.h>
```
### 1. Header File Inclusion
This line includes the standard input-output library in C, which allows the use of functions like `printf` for output.

```c
typedef struct node_t node;
```
### 2. Typedef for `struct node_t`
This line defines `node` as an alias for `struct node_t`, simplifying references to the structure in the code.

```c
struct node_t{
    int key;
    node *left;
    node *right;
};
```
### 3. Definition of Binary Tree Node Structure
- Each node in the tree has:
  - An integer `key`, which stores a value.
  - A pointer `left` pointing to the left child.
  - A pointer `right` pointing to the right child.
  
This structure enables the formation of a binary tree where each node can have at most two children.

```c
int count (node* root){
```
### 4. `count` Function Definition
This function takes a pointer to the root of the binary tree and returns the total number of nodes in the tree.

```c
    if (root==NULL)
        return 0;
```
### 5. Base Case
- If the `root` is `NULL`, it means the tree is empty, so the function returns 0.
- This base case prevents unnecessary recursive calls and ensures the function terminates when reaching a leaf node.

```c
    int l,r;
```
### 6. Variable Declarations
- `l` will store the count of nodes in the left subtree.
- `r` will store the count of nodes in the right subtree.

```c
    l=count(root->left);
    r=count(root->right);
```
### 7. Recursive Calls (DFS Traversal)
- The function calls itself recursively on the left subtree (`root->left`).
- Then, it calls itself recursively on the right subtree (`root->right`).
- These recursive calls traverse the entire tree, summing up all nodes.

```c
    return (l+r+1);
```
### 8. Returning the Total Node Count
- The function returns the sum of nodes in the left and right subtrees, plus 1 for the current node (`root`).
- The recursion ensures that all nodes are counted by aggregating results from child nodes up to the root.

## Why This Code Uses DFS
The function follows a Depth-First Search (DFS) traversal pattern because:
1. **Recursive Approach**: The function explores the entire left subtree before moving to the right subtree, similar to a DFS traversal.
2. **Stack-Based Execution**: Each recursive call is placed on the call stack until a leaf node is reached, then it backtracks.
3. **Efficient for Tree Structure**: DFS is well-suited for operations like counting nodes, where each node needs to be visited exactly once.
4. **Memory Usage**: The space complexity of DFS in this case is **O(h)** (where `h` is the height of the tree), which is optimal compared to other traversal methods like BFS that require a queue.

## Example Execution
### Given the tree:
```
        1
       / \
      2   3
     / \   \
    4   5   6
```
The function will execute in the following order:
1. `count(1)` calls `count(2)` and `count(3)`.
2. `count(2)` calls `count(4)` and `count(5)`, returning 3.
3. `count(3)` calls `count(6)`, returning 2.
4. Summing up: `1 + 3 + 2 = 6`.

The total number of nodes in the tree is **6**.

## Complexity Analysis
- **Time Complexity:** O(N) (Each node is visited once)
- **Space Complexity:** O(h) (Recursive stack space, where `h` is the height of the tree)

## Conclusion
This code efficiently counts the number of nodes in a binary tree using a Depth-First Search (DFS) approach. It recursively traverses each subtree and aggregates the count, making it a simple and effective solution for this problem.

