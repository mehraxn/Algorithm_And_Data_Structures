# Binary Tree In-Order Traversal in C

## Overview
This C program implements a **binary tree node structure** and an **in-order traversal function**. The **in-order traversal** follows the order:
1. Visit the left subtree
2. Visit the root node
3. Visit the right subtree

This traversal technique is commonly used to retrieve sorted elements from a binary search tree (BST). The code provided allows users to understand and implement a recursive in-order traversal on a binary tree.

---

## Code Explanation (Line-by-Line)

### **Header Files**
```c
#include <stdio.h>
```
- **Purpose:** This includes the standard **input-output library**, which allows the program to use the `printf` function for printing values.

```c
#include <stdlib.h>
```
- **Purpose:** The standard library (`stdlib.h`) is included to provide functions like `malloc()` and `free()`, which are commonly used for **dynamic memory allocation**. Although they are not used in this snippet, they may be needed for further development when dynamically creating tree nodes.

---

### **Defining the Node Structure**
```c
typedef struct node_t node;
```
- **Purpose:** This line introduces a `typedef` alias for `struct node_t` to simplify references to `node_t` in the rest of the code.

```c
struct node_t {
    int key;
    node *left;
    node *right;
};
```
- **Purpose:** This defines a **binary tree node structure**, named `node_t`, that contains:
  - An integer **key** (stores the value of the node)
  - A pointer to the **left child** (`left`)
  - A pointer to the **right child** (`right`)

Each node in the binary tree will be represented using this structure.

---

### **In-Order Traversal Function**
```c
void inorder_r(node *root) {
```
- **Purpose:** This function performs a **recursive in-order traversal** on the given binary tree.
- **Parameter:**
  - `node *root`: A pointer to the root node of the binary tree.

#### **Base Condition**
```c
if (root == NULL)
    return;
```
- **Purpose:** This checks if the `root` is `NULL` (i.e., an empty tree or a leaf node’s child). If so, it returns without performing any action.

#### **Recursive Calls**
```c
inorder_r(root->left);
```
- **Purpose:** The function **recursively traverses the left subtree** before processing the current node.

```c
printf("%d ", root->key);
```
- **Purpose:** Once the left subtree is traversed, the function **prints the current node's key**.

```c
inorder_r(root->right);
```
- **Purpose:** Finally, the function **recursively traverses the right subtree**.

### **How In-Order Traversal Works?**
For a binary tree:
```
      5
     / \
    3   7
   / \   \
  2   4   8
```
The **in-order traversal output** will be: `2 3 4 5 7 8`

---

## **Time and Space Complexity**

### **Time Complexity**
- **Best, Average, and Worst Case: O(n)**
- Explanation: Since the function visits **each node exactly once**, the time complexity is **O(n)**, where `n` is the total number of nodes in the tree.

### **Space Complexity**
- **Best Case (Balanced Tree): O(log n)** (Recursive Stack)
- **Worst Case (Skewed Tree): O(n)**
- Explanation: The function uses a recursive stack to traverse the tree. The maximum depth of recursion depends on the height of the tree:
  - **Balanced Tree:** The depth is `O(log n)`.
  - **Skewed Tree (like a linked list):** The depth is `O(n)`.

---

## **Summary**
- This program implements a **binary tree node structure**.
- It provides a **recursive in-order traversal** function.
- The traversal follows **Left → Root → Right** order.
- **Time Complexity:** O(n) for visiting each node once.
- **Space Complexity:** O(log n) for balanced trees, O(n) for skewed trees.

This function is useful for printing a **sorted order** of values if applied to a **Binary Search Tree (BST)**.

---

## **Potential Enhancements**
- Implement **iterative in-order traversal** (to avoid recursion overhead using a stack).
- Add a **function to construct a binary tree dynamically**.
- Implement **pre-order and post-order traversal functions**.
- Allow user **input to create a custom binary tree**.

