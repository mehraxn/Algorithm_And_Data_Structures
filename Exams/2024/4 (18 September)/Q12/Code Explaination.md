# README for `BST of Lists` Implementation

This document provides a comprehensive explanation of the `BST of Lists` C program, its functionality, and how to use it effectively. The program reads data from a file, organizes it into a binary search tree (BST), and stores a linked list of integers for each unique key.

## Overview
The program processes an input file containing key-value pairs where:
- Each `key` is a string.
- Each `value` is an integer.
- A key can have multiple associated values.

The program organizes these into a BST where each node corresponds to a key. Each node stores a linked list of integers representing the values associated with the key. This BST can be printed, and all allocated memory is freed before the program terminates.

## Code Components
### 1. **Structures**
#### Linked List Node (`list_t`)
```c
typedef struct list_node {
    int value;
    struct list_node *next;
} list_t;
```
Represents a node in the linked list.
- **Fields:**
  - `value`: Stores an integer.
  - `next`: Points to the next node in the list.

#### Binary Search Tree Node (`bst_t`)
```c
typedef struct bst_node {
    char *key;
    list_t *values;
    struct bst_node *left;
    struct bst_node *right;
} bst_t;
```
Represents a node in the BST.
- **Fields:**
  - `key`: A string representing the unique key.
  - `values`: Pointer to the linked list of integers.
  - `left`: Pointer to the left child node.
  - `right`: Pointer to the right child node.

### 2. **Functions**

#### `create_bst_node`
```c
bst_t *create_bst_node(const char *key);
```
- **Purpose:** Allocates and initializes a new BST node with the given key.
- **Parameters:**
  - `key`: String key for the node.
- **Returns:** Pointer to the newly created BST node.

#### `create_list_node`
```c
list_t *create_list_node(int value);
```
- **Purpose:** Allocates and initializes a new linked list node with the given value.
- **Parameters:**
  - `value`: Integer value for the node.
- **Returns:** Pointer to the newly created list node.

#### `add_to_list`
```c
void add_to_list(list_t **head, int value);
```
- **Purpose:** Adds a value to the front of the linked list.
- **Parameters:**
  - `head`: Pointer to the head of the linked list.
  - `value`: Integer value to add.
- **Behavior:** Creates a new list node and prepends it to the list.

#### `insert_to_bst`
```c
bst_t *insert_to_bst(bst_t *root, const char *key, int *values, int count);
```
- **Purpose:** Inserts a key and its associated values into the BST.
- **Parameters:**
  - `root`: Root of the BST.
  - `key`: Key to insert.
  - `values`: Array of integers to associate with the key.
  - `count`: Number of values in the array.
- **Returns:** Pointer to the updated BST root.
- **Behavior:**
  - If the key exists, appends the values to the linked list.
  - Otherwise, creates a new BST node and adds it to the tree.

#### `free_list`
```c
void free_list(list_t *head);
```
- **Purpose:** Frees all nodes in a linked list.
- **Parameters:**
  - `head`: Head of the linked list.

#### `free_bst`
```c
void free_bst(bst_t *root);
```
- **Purpose:** Frees all nodes in the BST, including linked lists and keys.
- **Parameters:**
  - `root`: Root of the BST.

#### `print_bst`
```c
void print_bst(const bst_t *root);
```
- **Purpose:** Prints the contents of the BST in sorted order.
- **Parameters:**
  - `root`: Root of the BST.
- **Behavior:** Recursively traverses the BST in in-order fashion and prints each key and its associated values.

#### `file_to_bst_of_lists`
```c
bst_t *file_to_bst_of_lists(const char *name);
```
- **Purpose:** Parses the input file and constructs a BST of linked lists.
- **Parameters:**
  - `name`: Name of the input file.
- **Returns:** Pointer to the root of the BST.
- **File Format:** Each line contains a key followed by the number of values and the values themselves. For example:
  ```
  key1 3 10 20 30
  key2 2 40 50
  ```

### 3. **Main Function**
```c
int main();
```
- **Purpose:** Entry point of the program.
- **Behavior:**
  1. Reads the filename (`input.txt`).
  2. Constructs the BST using `file_to_bst_of_lists`.
  3. Prints the BST.
  4. Frees all allocated memory.

## Example Execution
### Input File (`input.txt`):
```
key1 3 10 20 30
key2 2 40 50
key3 1 60
```
### Output:
```
BST of lists:
key1: 30 20 10
key2: 50 40
key3: 60
```

## Error Handling
- **File Handling:** If the file cannot be opened, an error message is printed, and the program exits gracefully.
- **Memory Management:**
  - Memory for nodes and lists is dynamically allocated.
  - All memory is freed before program termination to prevent leaks.

## Compilation and Execution
### Compilation:
```bash
gcc bst_of_lists.c -o bst_of_lists
```
### Execution:
```bash
./bst_of_lists
```
Ensure the input file (`input.txt`) exists in the same directory or provide the correct path.

## Key Notes
- **BST Properties:** The BST maintains keys in lexicographical order.
- **Linked List Order:** New values are prepended to the linked list.
- **Flexibility:** Supports arbitrary keys and multiple values per key.

This program demonstrates efficient data organization using a combination of BSTs and linked lists, showcasing foundational data structure concepts in C.

