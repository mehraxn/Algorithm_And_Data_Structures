# README: Tree Display Program

## Overview
This program defines a tree structure and provides functionalities to:
1. Traverse the tree depth-first.
2. Display all nodes grouped by their depth level.
3. Print nodes at each depth in sorted order by their keys.

It uses dynamic memory management to adapt to varying tree structures and supports efficient depth-based traversal.

---

## Features
- **Tree Representation**: A dynamic tree structure with nodes that can have multiple children.
- **Depth Calculation**: Determines the maximum depth of the tree.
- **Depth-Based Display**: Groups and prints nodes at each depth level in sorted order.
- **Dynamic Memory Management**: Allocates and deallocates memory as needed to handle varying tree sizes and depths.

---

## Code Structure
### Main Functions

#### 1. **displayTree**
```c
void displayTree(node_t* root, int depth, int* depthCounts, node_t*** depthNodes);
```
- **Purpose**: Traverses the tree depth-first and groups nodes by their depth.
- **Parameters**:
  - `root`: Pointer to the root node of the tree.
  - `depth`: Current depth level during traversal.
  - `depthCounts`: Array to store the count of nodes at each depth.
  - `depthNodes`: 2D array to store pointers to nodes at each depth.
- **Logic**:
  - Appends the current node to the appropriate depth level in `depthNodes`.
  - Recursively processes each child node at the next depth level.

---

#### 2. **compareNodes**
```c
int compareNodes(const void* a, const void* b);
```
- **Purpose**: Comparison function for sorting nodes by their keys.
- **Parameters**:
  - `a`, `b`: Pointers to the nodes being compared.
- **Logic**:
  - Compares the `key` values of the two nodes.
- **Returns**: Negative, zero, or positive based on the comparison result.

---

#### 3. **printNodesInOrder**
```c
void printNodesInOrder(node_t** nodes, int count);
```
- **Purpose**: Sorts and prints the nodes at a specific depth level.
- **Parameters**:
  - `nodes`: Array of node pointers at the current depth.
  - `count`: Number of nodes at the current depth.
- **Logic**:
  - Sorts the nodes using `qsort` and the `compareNodes` function.
  - Prints the sorted keys of the nodes.

---

#### 4. **calculateMaxDepth**
```c
void calculateMaxDepth(node_t* node, int depth, int* maxDepth);
```
- **Purpose**: Calculates the maximum depth of the tree.
- **Parameters**:
  - `node`: Pointer to the current node.
  - `depth`: Current depth level during traversal.
  - `maxDepth`: Pointer to store the maximum depth found.
- **Logic**:
  - Recursively explores each branch of the tree.
  - Updates `maxDepth` if the current depth exceeds the stored value.

---

#### 5. **display**
```c
void display(node_t* root);
```
- **Purpose**: Manages the depth-based display of the tree.
- **Parameters**:
  - `root`: Pointer to the root node of the tree.
- **Logic**:
  - Calculates the maximum depth using `calculateMaxDepth`.
  - Allocates memory for `depthCounts` and `depthNodes`.
  - Calls `displayTree` to group nodes by depth.
  - Prints nodes at each depth using `printNodesInOrder`.
  - Frees allocated memory after processing.

---

## Example Execution

### Example Tree Structure
- Root Node Key: 10
- Children:
  - Node 20
    - Children: 40, 50
  - Node 30
    - Children: 60

### Output
```
Depth 0: 10
Depth 1: 20 30
Depth 2: 40 50 60
```

### Explanation
- Depth 0: Root node (10).
- Depth 1: Children of the root (20, 30).
- Depth 2: Grandchildren of the root (40, 50, 60).

---

## Data Structures

### Tree Node Structure
```c
typedef struct node {
    int key;
    struct node** children;
    int numChildren;
} node_t;
```
- **Fields**:
  - `key`: Integer value representing the node.
  - `children`: Array of pointers to the node's children.
  - `numChildren`: Number of children.

---

## Memory Management
- **Dynamic Allocation**:
  - Allocates memory for the `children` array in each node.
  - Dynamically adjusts the size of `depthNodes` arrays during traversal.
- **Deallocation**:
  - Frees all allocated memory after tree traversal and display.

---

## Limitations
- **Fixed Node Structure**: Assumes integer keys for nodes.
- **Single Root**: Handles only one root node.
- **Sorting**: Sorts nodes at each depth level by their keys, which may not be needed in all applications.

---

## Future Improvements
- Extend support for generic data types in nodes.
- Add functionality for user-defined sorting criteria.
- Implement input and creation of the tree structure dynamically.
- Add error handling for invalid or malformed tree structures.

---

## How to Compile and Run
1. Save the code in a file (e.g., `tree_display.c`).
2. Compile the program:
   ```bash
   gcc -o tree_display tree_display.c
   ```
3. Run the program:
   ```bash
   ./tree_display
   ```

