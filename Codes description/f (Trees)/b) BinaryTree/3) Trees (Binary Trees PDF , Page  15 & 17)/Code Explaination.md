# Binary Tree Operations

This repository contains a C implementation for performing basic operations on a binary tree, such as computing the height of the tree and counting the number of nodes. The functions are designed to illustrate fundamental recursive techniques used in binary tree traversal and manipulation.

## Overview

Binary trees are hierarchical data structures in which each node has at most two children: the left child and the right child. This implementation includes the following functionalities:

1. **Height Calculation**: Computes the height of the binary tree.
2. **Node Count**: Computes the total number of nodes in the binary tree.

## Files

- **main.c**: The main implementation file that includes the definition of the binary tree and functions to calculate the height and count of nodes.

## Functions

### `int height(node_t *root)`

This function computes the height of a binary tree. The height is defined as the length of the longest path from the root node to a leaf. In terms of recursive calculation:
- If the current node is `NULL`, the height is `-1`.
- Otherwise, the height is the maximum height between the left and right subtrees, plus `1` for the current node.

**Parameters**:
- `node_t *root`: A pointer to the root node of the binary tree.

**Returns**:
- An integer representing the height of the tree. If the tree is empty, it returns `-1`.

**Time Complexity**: O(n), where `n` is the number of nodes in the tree.

### `int count(node_t *root)`

This function counts the total number of nodes in the binary tree.
- If the current node is `NULL`, it returns `0`.
- Otherwise, it recursively counts the nodes in the left and right subtrees and returns their sum, plus `1` for the current node.

**Parameters**:
- `node_t *root`: A pointer to the root node of the binary tree.

**Returns**:
- An integer representing the total number of nodes in the tree.

**Time Complexity**: O(n), where `n` is the number of nodes in the tree.

## Example Usage

An example of how to use these functions is provided in the `main.c` file:

- The program initializes a simple binary tree with three nodes and computes its height and node count.
- The `main()` function outputs the height and node count of the tree using the `height()` and `count()` functions.

### Example Output

```
Height of the binary tree: 1
Number of nodes in the binary tree: 3
```

## Compilation and Execution

To compile and run the program, you can use `gcc` as follows:

```bash
gcc main.c -o binary_tree
./binary_tree
```

This will output the height and number of nodes for the binary tree defined in the `main()` function.

## Memory Management

The program includes basic memory management to allocate and free nodes. Each node is allocated using `malloc()`, and the allocated memory is freed at the end to prevent memory leaks.

## Contributions

Contributions are welcome! Feel free to submit a pull request or open an issue for any feature requests or improvements.

## License

This project is open-source and available under the MIT License. See the `LICENSE` file for more details.

## Contact

If you have any questions or suggestions, feel free to reach out to the repository maintainer.