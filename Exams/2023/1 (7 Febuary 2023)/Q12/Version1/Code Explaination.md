# README: Binary Search Tree with Linked List Program

## Overview
This program processes data from an input file and constructs a binary search tree (BST), where each node has a key and is associated with a linked list. The linked list stores strings associated with that key. The program supports insertion of nodes and strings, traversal of the BST, and dynamic memory management to free all allocated resources.

---

## Features
- **Binary Search Tree Construction**: Builds a BST from input data.
- **Linked List Integration**: Each node in the BST has an associated linked list for storing strings.
- **File Input**: Reads data from a specified file to populate the tree.
- **Traversal**: Prints the keys and their associated linked lists in sorted order.
- **Dynamic Memory Management**: Ensures all allocated memory is freed.

---

## Code Structure
### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Reads data from `infile.txt` and builds the BST using the `insert` function.
  - Traverses the BST using the `traverse` function.
  - Frees all dynamically allocated memory using the `freeAll` function.

---

#### 2. **insert**
```c
bst_t *insert(char *name);
```
- **Purpose**: Reads data from a file and constructs the BST.
- **Parameters**:
  - `name`: Name of the input file.
- **Logic**:
  - Opens the file and reads key-value pairs (`key` and `string`).
  - For each key-value pair:
    - Inserts the key into the BST if it does not already exist.
    - Appends the string to the linked list of the corresponding node.
- **Returns**: Pointer to the root of the BST.

---

#### 3. **new_node**
```c
bst_t *new_node(int key);
```
- **Purpose**: Creates a new BST node.
- **Parameters**:
  - `key`: The key value for the node.
- **Logic**:
  - Allocates memory for a new `bst_t` structure.
  - Initializes the key, left and right child pointers, and linked list head.
- **Returns**: Pointer to the newly created node.

---

#### 4. **add_list**
```c
list_t *add_list(list_t *head, char *str);
```
- **Purpose**: Adds a string to the linked list associated with a BST node.
- **Parameters**:
  - `head`: Pointer to the head of the linked list.
  - `str`: String to add.
- **Logic**:
  - Allocates memory for a new `list_t` node.
  - Duplicates the string and links the new node at the head of the list.
- **Returns**: Pointer to the new head of the linked list.

---

#### 5. **traverse**
```c
void traverse(bst_t *root);
```
- **Purpose**: Performs an in-order traversal of the BST and prints each key with its associated linked list.
- **Parameters**:
  - `root`: Pointer to the root of the BST.
- **Logic**:
  - Recursively visits the left subtree, prints the current node's key and its linked list, and then visits the right subtree.

---

#### 6. **freeAll**
```c
void freeAll(bst_t *root);
```
- **Purpose**: Frees all memory allocated for the BST and its linked lists.
- **Parameters**:
  - `root`: Pointer to the root of the BST.
- **Logic**:
  - Frees each node in the linked list.
  - Recursively frees the left and right subtrees.
  - Frees the current BST node.

---

## Data Structures

### Binary Search Tree Node
```c
struct bst_t {
    bst_t *left, *rigth;
    list_t *l_head;
    int key;
};
```
- Represents a node in the BST.
- **Fields**:
  - `left`: Pointer to the left child.
  - `rigth`: Pointer to the right child.
  - `l_head`: Pointer to the head of the associated linked list.
  - `key`: Integer key for the node.

### Linked List Node
```c
struct list_t {
    char *str;
    list_t *next;
};
```
- Represents a node in a linked list.
- **Fields**:
  - `str`: Pointer to the stored string.
  - `next`: Pointer to the next node in the list.

---

## Example Execution

### Input File (`infile.txt`):
```
10 apple
5 banana
10 orange
15 grape
5 cherry
```

### Output:
```
- 5 - cherry - banana
- 10 - orange - apple
- 15 - grape
```

### Explanation:
- The keys `10`, `5`, and `15` correspond to BST nodes.
- Each node's linked list contains the strings associated with that key.

---

## Memory Management
- **Dynamic Allocation**:
  - Allocates memory for each BST node and each linked list node.
  - Duplicates strings for storage in the linked list.
- **Deallocation**:
  - Frees each linked list node before freeing the BST node.
  - Ensures no memory leaks.

---

## Limitations
- **File Handling**: Assumes the input file exists and is formatted correctly.
- **Key Uniqueness**: Multiple strings with the same key are stored in the same node's linked list.
- **Error Handling**: Minimal error handling for memory allocation and file reading.

---

## Future Improvements
- Add error handling for file I/O and memory allocation failures.
- Extend support for duplicate keys with separate nodes.
- Optimize the traversal function to provide more flexible output formats.

---

## How to Compile and Run
1. Save the code in a file (e.g., `bst_linkedlist.c`).
2. Compile the program:
   ```bash
   gcc -o bst_linkedlist bst_linkedlist.c
   ```
3. Run the program:
   ```bash
   ./bst_linkedlist
   ```

