# README: Common Strings in Multiple BSTs

This document provides a detailed explanation of the code functionality, design, and usage. The program identifies strings that are common across multiple Binary Search Trees (BSTs).

## Overview

The program defines a set of functions to:
1. Create and manage BSTs.
2. Traverse BSTs in an in-order manner.
3. Identify and display strings that are common across all the BSTs.

### Key Features
- Each node of a BST stores a string as its key.
- Multiple BST roots are stored in an array for easy management.
- The `display_common` function identifies and prints the strings that exist in all the BSTs.

---

## Code Details

### Constants
```c
#define N 3
```
Defines the number of BST roots to be managed. Here, `N = 3` means the program is designed to handle 3 BSTs.

---

### Structures
```c
typedef struct node {
    char *key;
    struct node *left;
    struct node *right;
} node_t;
```
Defines the structure of a BST node:
- **key**: Stores a string value.
- **left**: Pointer to the left child.
- **right**: Pointer to the right child.

---

### Functions

#### 1. `create_node`
```c
node_t *create_node(const char *key);
```
**Purpose**: Allocates memory and initializes a new node with a given string key.
- **Input**: `key` (const char*): The string to store in the new node.
- **Output**: Returns a pointer to the newly created node.
- **Error Handling**: Exits the program if memory allocation fails.

---

#### 2. `insert`
```c
node_t *insert(node_t *root, const char *key);
```
**Purpose**: Inserts a string key into the BST while maintaining BST properties.
- **Input**:
  - `root` (node_t*): Pointer to the root of the BST.
  - `key` (const char*): The string to insert.
- **Output**: Returns the updated root of the BST.
- **Behavior**:
  - Compares the key to the current node’s key.
  - Inserts recursively into the left or right subtree as appropriate.

---

#### 3. `is_present_in_all_bsts`
```c
int is_present_in_all_bsts(node_t *roots[], const char *key);
```
**Purpose**: Checks if a given string key is present in all BSTs.
- **Input**:
  - `roots` (node_t*[]): Array of pointers to BST roots.
  - `key` (const char*): The string to search for.
- **Output**: Returns `1` if the key is found in all BSTs, `0` otherwise.
- **Logic**:
  - Iterates through each BST.
  - Searches for the key in each BST using standard BST traversal.

---

#### 4. `inorder_traversal`
```c
void inorder_traversal(node_t *root, node_t *roots[], int (*callback)(node_t *roots[], const char *key));
```
**Purpose**: Performs an in-order traversal of a BST and applies a callback function to each node’s key.
- **Input**:
  - `root` (node_t*): The root of the BST to traverse.
  - `roots` (node_t*[]): Array of pointers to BST roots.
  - `callback` (function pointer): A function that takes `roots` and `key` as parameters.
- **Behavior**:
  - Visits left subtree, root, and right subtree in order.
  - Calls the callback function for each node's key and prints the key if the callback returns `1`.

---

#### 5. `display_common`
```c
void display_common(node_t *roots[]);
```
**Purpose**: Displays strings that are common to all BSTs.
- **Input**:
  - `roots` (node_t*[]): Array of pointers to BST roots.
- **Behavior**:
  - Calls `inorder_traversal` on the first BST in the array.
  - Passes `is_present_in_all_bsts` as the callback to check for commonality.
- **Edge Case**: If `roots` is null or the first BST is empty, prints a message and exits.

---

### Example Usage
```c
int main() {
    node_t *roots[N] = {NULL};

    // Initialize BSTs
    roots[0] = insert(roots[0], "apple");
    roots[0] = insert(roots[0], "banana");
    roots[0] = insert(roots[0], "cherry");

    roots[1] = insert(roots[1], "banana");
    roots[1] = insert(roots[1], "cherry");
    roots[1] = insert(roots[1], "date");

    roots[2] = insert(roots[2], "banana");
    roots[2] = insert(roots[2], "cherry");
    roots[2] = insert(roots[2], "elderberry");

    // Display common strings
    printf("Common strings in all BSTs:\n");
    display_common(roots);

    return 0;
}
```
**Output**:
```
Common strings in all BSTs:
banana
cherry
```

---

### Design Considerations
1. **Memory Management**: Dynamically allocates memory for each node and uses `strdup` for string storage. Ensure to free memory if extended functionality is added.
2. **Flexibility**: The code uses callback functions, making it extensible for additional operations during traversal.
3. **Performance**:
   - Each key search runs in \(O(\log n)\) for a balanced BST.
   - For \(N\) BSTs with \(M\) nodes, the total complexity is \(O(M \times N \times \log M)\).

---

### Limitations
1. The program does not handle duplicate keys in a single BST.
2. Memory deallocation for the BSTs is not implemented.
3. Assumes input strings are unique and the BSTs are well-formed.

---

### Potential Enhancements
1. Add memory deallocation to free the dynamically allocated nodes and strings.
2. Handle edge cases for malformed inputs or non-unique strings.
3. Support dynamically adjustable sizes for the `roots` array.
4. Allow user interaction to build BSTs.

---

This document should provide a comprehensive understanding of the program's structure, functionality, and usage.

