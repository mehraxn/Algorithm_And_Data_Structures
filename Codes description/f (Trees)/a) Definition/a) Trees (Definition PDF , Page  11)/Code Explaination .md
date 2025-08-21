# Tree Structures Demo - README

## Overview

This program provides an implementation of three different types of tree structures in C:

1. **Binary Tree**: A tree where each node can have at most two children, named left and right.
2. **Fixed-Size N-ary Tree**: A tree where each node can have a fixed number (N) of children.
3. **Dynamic-Size N-ary Tree**: A tree where each node can have a variable number of children, which is determined during runtime.

The program also includes functions to create nodes for each type of tree and demonstrates their usage by building and printing simple examples of each tree structure.

## Data Structures

1. **Binary Tree Node (`node_t_binary`)**
   - Represents a node in a binary tree.
   - Contains:
     - `key`: Integer value representing the key of the node.
     - `l` and `r`: Pointers to the left and right children, respectively.

2. **Fixed-Size N-ary Tree Node (`node_t_fixed`)**
   - Represents a node in a fixed-size N-ary tree.
   - Contains:
     - `key`: Integer value representing the key of the node.
     - `children[N]`: An array of pointers to children nodes, where `N` is the fixed number of children.

3. **Dynamic-Size N-ary Tree Node (`node_t_dynamic`)**
   - Represents a node in a dynamic-size N-ary tree.
   - Contains:
     - `key`: Integer value representing the key of the node.
     - `degree`: Integer representing the number of children.
     - `children`: Pointer to an array of pointers to children nodes.

## Functions

### 1. `createBinaryNode(int key)`
- Allocates memory for a new binary tree node.
- Initializes the node with the given key.
- Sets both left and right children pointers (`l` and `r`) to `NULL`.
- **Return Value**: Pointer to the created `node_t_binary` structure.

### 2. `createFixedNode(int key)`
- Allocates memory for a new fixed-size N-ary tree node.
- Initializes the node with the given key.
- Sets all children pointers in the array to `NULL`.
- **Return Value**: Pointer to the created `node_t_fixed` structure.

### 3. `createDynamicNode(int key, int degree)`
- Allocates memory for a new dynamic-size N-ary tree node.
- Initializes the node with the given key and the specified number of children (`degree`).
- Allocates memory for the array of children pointers and sets each to `NULL`.
- **Return Value**: Pointer to the created `node_t_dynamic` structure.

## Example Usage

The `main()` function demonstrates the usage of the three types of tree nodes:

1. **Binary Tree**
   - Creates a root node with key `10` and adds two children with keys `5` and `15`.

2. **Fixed-Size N-ary Tree**
   - Creates a root node with key `1` and adds two children with keys `2` and `3`.

3. **Dynamic-Size N-ary Tree**
   - Creates a root node with key `1` and degree `2` (two children).
   - Adds children with keys `2` and `3`, then adds a grandchild with key `4` to one of the children.

The example also prints the key values of each root node and then deallocates all the memory to avoid memory leaks.

## Compilation and Execution

To compile and run this program, use the following commands:

```sh
$ gcc -o tree_structures tree_structures.c
$ ./tree_structures
```

This will compile the program and create an executable named `tree_structures`, which you can then run.

## Output

The program will produce the following output:

```
Binary Tree Root Key: 10
Fixed-Size N-ary Tree Root Key: 1
Dynamic-Size N-ary Tree Root Key: 1
```

## Memory Management

The program allocates memory dynamically for each node, and it is important to free this memory after use to prevent memory leaks. The `main()` function includes the appropriate calls to `free()` for each of the tree nodes created.

## Key Points

- **Binary Tree**: Each node has at most two children.
- **Fixed-Size N-ary Tree**: Each node has a fixed number (`N`) of children, defined by a macro.
- **Dynamic-Size N-ary Tree**: Each node can have a variable number of children, specified at runtime.

This program is a simple demonstration of these tree structures and can be expanded for more complex operations like traversal, insertion, and deletion.

## License

This code is provided as-is for educational purposes. Feel free to modify and use it as needed.

