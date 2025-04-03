# README: Binary Tree Preorder Traversal

## Overview
This project implements a **binary tree** structure in C and a function to perform **preorder traversal** recursively. The program defines a `struct node_t` to represent nodes in the tree and implements a function `preorder_r` to traverse the tree in the sequence:

- **Root Node → Left Subtree → Right Subtree**

This README provides a **detailed, line-by-line explanation** of the code, including function purposes and their **time and space complexity**.

---

## Code Breakdown

### **Header Files**
```c
#include <stdio.h>   // Standard library for input-output functions
#include <stdlib.h>  // Standard library for memory allocation (if needed)
```
- `#include <stdio.h>`: Required for using the `printf` function to display output.
- `#include <stdlib.h>`: Included in case dynamic memory allocation (`malloc`, `free`) is needed in further extensions.

---

### **Defining the Node Structure**
```c
typedef struct node_t node;
struct node_t {
    int key;     // The value stored in the node
    node *left;  // Pointer to the left child node
    node *right; // Pointer to the right child node
};
```
#### **Explanation:**
- A **struct `node_t`** is defined to represent nodes in the binary tree.
- Each node contains:
  - An integer `key` (stores the data value of the node).
  - A pointer `left` pointing to the **left child node**.
  - A pointer `right` pointing to the **right child node**.
- The `typedef struct node_t node;` creates an alias (`node`) to simplify references.

---

### **Preorder Traversal Function**
```c
void preorder_r(node *root) {
    if (root == NULL)  // Base case: If the node is NULL, return
        return;
    
    printf("%d ", root->key);  // Print the value of the current node
    preorder_r(root->left);    // Recursively traverse the left subtree
    preorder_r(root->right);   // Recursively traverse the right subtree
}
```

#### **Purpose:**
- This function performs a **recursive preorder traversal** of the binary tree.
- **Preorder Traversal Order:**
  1. **Visit the root node** (print its value).
  2. **Traverse the left subtree** recursively.
  3. **Traverse the right subtree** recursively.

#### **Line-by-line Explanation:**
1. **`if (root == NULL) return;`**
   - Base case: If the node is `NULL`, return to stop recursion.
2. **`printf("%d ", root->key);`**
   - Print the key (value) of the current node.
3. **`preorder_r(root->left);`**
   - Recursive call to process the left child.
4. **`preorder_r(root->right);`**
   - Recursive call to process the right child.

#### **Time Complexity Analysis:**
- **Best, Average, and Worst Case: O(n)**
  - Each node is visited **exactly once**, making it **O(n)** for `n` nodes.

#### **Space Complexity Analysis:**
- **O(h)** (where `h` is the height of the tree)
  - This is due to **recursive function calls** on the call stack.
  - For a balanced tree, `h = log(n)`, so **O(log n)**.
  - For a skewed tree (all nodes in one direction), `h = n`, so **O(n)**.

---

## **Summary**
- **This program defines a binary tree node structure and implements a recursive preorder traversal.**
- **Preorder traversal visits nodes in Root → Left → Right order.**
- **Time complexity is O(n), and space complexity is O(h) (height of the tree).**
- **This is a fundamental traversal method used in tree-based algorithms, such as expression tree evaluation and tree-based searching.**

