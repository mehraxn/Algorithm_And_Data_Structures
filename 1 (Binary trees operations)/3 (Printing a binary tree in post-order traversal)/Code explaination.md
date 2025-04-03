# README: Binary Tree Post-Order Traversal in C

## Overview
This C program defines a simple binary tree structure and implements a recursive post-order traversal function to print the values stored in the tree nodes. The `post_order_r` function is designed to traverse the tree in the following order:

1. Visit the left subtree.
2. Visit the right subtree.
3. Print the value of the current node.

## Code Explanation (Line-by-Line)

### **Header Files**
```c
#include <stdio.h>   // Include standard input-output library for printf function
#include <stdlib.h>  // Include standard library for memory allocation (if needed in further development)
```
- `#include <stdio.h>`: This header file is required for using the `printf` function, which is used to display the output.
- `#include <stdlib.h>`: This library is included to allow dynamic memory allocation (`malloc`, `free`) in case the program is extended to include tree creation and deletion dynamically.

### **Defining the Node Structure**
```c
typedef struct node_t node;
struct node_t {
    int key;     // Data stored in the node
    node *left;  // Pointer to the left child node
    node *right; // Pointer to the right child node
};
```
- `typedef struct node_t node;` - Defines a type alias `node` for `struct node_t` to simplify usage.
- `struct node_t {` - Defines a structure to represent a node in the binary tree.
- `int key;` - Stores an integer value, which is the data in the node.
- `node *left;` - Pointer to the left child of the node.
- `node *right;` - Pointer to the right child of the node.

This structure is the fundamental building block for representing a binary tree.

### **Post-Order Traversal Function**
```c
void post_order_r(node *root) {
    if (root == NULL)  // Base case: if the node is NULL, return
        return;

    post_order_r(root->left);    // Recursively traverse the left subtree
    post_order_r(root->right);   // Recursively traverse the right subtree
    printf("%d ", root->key); // Print the key value of the current node
}
```

#### **Explanation:**
1. **Base Case**:
   ```c
   if (root == NULL) return;
   ```
   - If the `root` is `NULL`, the function returns immediately. This is the stopping condition to prevent dereferencing `NULL` pointers.

2. **Recursive Calls**:
   ```c
   post_order_r(root->left);
   ```
   - Recursively calls `post_order_r` on the left child. The function continues to explore all left children before moving to the right subtree.
   
   ```c
   post_order_r(root->right);
   ```
   - Recursively calls `post_order_r` on the right child after completing the left subtree traversal.

3. **Printing Node Value**:
   ```c
   printf("%d ", root->key);
   ```
   - Once both left and right subtrees have been processed, the function prints the value of the current node.
   - The traversal follows **post-order sequence: Left → Right → Root**.

## **Time and Space Complexity Analysis**

### **Time Complexity**
- The function visits each node exactly **once**, making the **time complexity O(n)**, where `n` is the number of nodes in the binary tree.
- Each recursive call performs constant-time operations (`printf`, `return` checks, recursive calls), contributing to **O(1)** per node.
- Since all nodes are visited recursively, the total complexity remains **O(n)**.

### **Space Complexity**
- **Best Case (Balanced Tree):**
  - The recursive function calls are stored in the function call stack.
  - In a balanced binary tree, the depth of the recursion stack is **O(log n)** since the height of a balanced tree is **log₂(n)**.

- **Worst Case (Skewed Tree):**
  - In an unbalanced (linked-list-like) tree, the recursion stack grows to **O(n)**, as there is only one child per node.

- **Overall Space Complexity:**
  - **O(h)**, where `h` is the height of the tree.
  - For a balanced tree, **O(log n)**.
  - For a skewed tree, **O(n)**.

## **Example Usage**

To test this function, you would need a driver function that creates a binary tree and calls `post_order_r`.

```c
#include <stdio.h>
#include <stdlib.h>

// Define the same node structure
typedef struct node_t node;
struct node_t {
    int key;
    node *left, *right;
};

// Function to create a new node
node* create_node(int key) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Post-order traversal function
void post_order_r(node *root) {
    if (root == NULL) return;
    post_order_r(root->left);
    post_order_r(root->right);
    printf("%d ", root->key);
}

int main() {
    // Create a simple tree
    node *root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);
    
    // Perform post-order traversal
    printf("Post-order traversal: ");
    post_order_r(root);
    printf("\n");
    
    return 0;
}
```

### **Expected Output**
```
Post-order traversal: 4 5 2 6 7 3 1
```

## **Conclusion**
This program efficiently demonstrates how to perform a recursive post-order traversal of a binary tree. The function correctly follows the post-order sequence **Left → Right → Root**, visiting each node exactly once. It runs in **O(n) time** with a space complexity of **O(h)**, where `h` is the height of the tree. This makes it a fundamental algorithm for tree-based applications such as expression tree evaluations, tree deletions, and more.

