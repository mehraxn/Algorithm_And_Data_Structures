# Binary Tree Traversal in C

## Overview
This project provides an implementation of a simple binary tree structure in C, along with traversal functions that demonstrate pre-order, in-order, and post-order traversal techniques. The program uses recursive functions to traverse the binary tree and prints the keys in each traversal order. Additionally, it includes memory management to prevent memory leaks by deallocating all nodes of the tree after usage.

## Binary Tree Structure
The binary tree is represented using a custom data structure that includes the following components:

- **key**: An integer value that holds the key data for each node.
- **l**: A pointer to the left child of the node.
- **r**: A pointer to the right child of the node.

The binary tree is constructed by dynamically allocating memory for each node and linking them accordingly.

## Functions Explained

### 1. `createBinaryNode(int key)`
This function is responsible for creating a new node in the binary tree. The function takes an integer `key` as input, allocates memory for a new node, and assigns the key value to it. The left and right child pointers are initialized to `NULL`.

```c
node_t_binary *createBinaryNode(int key);
```

### 2. `preorder_r(node_t_binary *root)`
This function performs a pre-order traversal of the binary tree. It starts by visiting the root node, then recursively visits the left subtree followed by the right subtree. Pre-order traversal follows the order **Root, Left, Right**.

```c
void preorder_r(node_t_binary *root);
```

### 3. `inorder_r(node_t_binary *root)`
This function performs an in-order traversal of the binary tree. It recursively visits the left subtree first, followed by the root node, and finally the right subtree. In-order traversal follows the order **Left, Root, Right** and is commonly used for printing the values in ascending order for binary search trees.

```c
void inorder_r(node_t_binary *root);
```

### 4. `postorder_r(node_t_binary *root)`
This function performs a post-order traversal of the binary tree. It starts by recursively visiting the left and right subtrees, and then visits the root node. Post-order traversal follows the order **Left, Right, Root** and is useful for operations such as deleting nodes in a tree.

```c
void postorder_r(node_t_binary *root);
```

## Example Usage
In the `main()` function, a binary tree with at least 10 nodes is created. The tree is constructed manually by calling the `createBinaryNode()` function for each node and linking the nodes appropriately.

The program then demonstrates each of the traversal methods:

1. **Pre-order Traversal**: Root, Left, Right.
2. **In-order Traversal**: Left, Root, Right.
3. **Post-order Traversal**: Left, Right, Root.

### Sample Output
```sh
Pre-order Traversal: 10 5 2 1 7 8 15 12 20 25 
In-order Traversal: 1 2 5 7 8 10 12 15 20 25 
Post-order Traversal: 1 2 8 7 5 12 25 20 15 10 
```

## Memory Management
Since each node is dynamically allocated, it is essential to free the memory to prevent memory leaks. The program deallocates all nodes of the binary tree after traversals are completed.

## How to Compile
To compile the code, use a C compiler such as `gcc`:

```sh
gcc binary_tree.c -o binary_tree
```

## How to Run
Once compiled, you can run the executable to see the traversal outputs:

```sh
./binary_tree
```

## Key Concepts Covered
- **Binary Tree Structure**: Understanding nodes, root, left, and right children.
- **Tree Traversals**: Pre-order, in-order, and post-order traversals to visit all nodes.
- **Recursive Functions**: Using recursion to traverse the tree effectively.
- **Dynamic Memory Management**: Allocating and freeing memory to ensure efficient use of resources.

## Conclusion
This project is a basic implementation of a binary tree in C, covering key concepts such as dynamic memory allocation, recursive traversals, and the construction of binary trees. It serves as a fundamental exercise for anyone learning data structures in C programming.