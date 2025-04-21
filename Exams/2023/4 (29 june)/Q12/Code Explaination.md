# README: Tree Traversal and Analysis Program

## Overview
This program represents a tree structure and provides functionalities to:
1. Calculate the depth of the tree.
2. Determine the level with the maximum number of nodes (crowded depth).
3. Print the nodes at the most crowded depth.

The tree is implemented as a general tree using a `node_t` structure with pointers to the first child and next sibling.

---

## Features
- **Tree Representation**: Uses a custom `node_t` structure to represent the tree.
- **Depth Calculation**: Computes the depth of the tree.
- **Crowded Depth Analysis**: Finds and prints the level with the maximum number of nodes.
- **Tree Traversal**: Recursively traverses and prints the nodes of the tree.

---

## Code Structure
### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Constructs a sample tree using the `newNode` function.
  - Computes and prints the depth of the tree using `getDepth`.
  - Determines and prints the most crowded level using `display_crowded_depth`.

#### 2. **newNode**
```c
node_t *newNode(int key);
```
- **Purpose**: Creates a new node with the given key.
- **Parameters**:
  - `key`: Value to assign to the new node.
- **Returns**: Pointer to the newly created node.
- **Logic**:
  - Allocates memory for a `node_t` structure.
  - Initializes the `key`, `first_child`, and `brother` fields.

#### 3. **visitTree**
```c
void visitTree(node_t *root);
```
- **Purpose**: Traverses the tree and prints the key of each node.
- **Parameters**:
  - `root`: Pointer to the root node of the tree.
- **Logic**:
  - Recursively visits the current node, its first child, and its siblings.

#### 4. **getDepth**
```c
int getDepth(node_t *root, int l);
```
- **Purpose**: Computes the depth of the tree.
- **Parameters**:
  - `root`: Pointer to the root node of the tree.
  - `l`: Current level being traversed.
- **Logic**:
  - Recursively calculates the depth by comparing the depths of the first child and sibling.
- **Returns**: Depth of the tree.

#### 5. **display_crowded_depth**
```c
int display_crowded_depth(node_t *root);
```
- **Purpose**: Finds the level with the maximum number of nodes and prints the nodes at that level.
- **Parameters**:
  - `root`: Pointer to the root node of the tree.
- **Logic**:
  - Allocates an array to count the number of nodes at each level.
  - Uses `recursiveCountLevel` to populate the array.
  - Identifies the level with the maximum count.
  - Prints the nodes at the most crowded level using `printLevel`.
- **Returns**: Level with the maximum number of nodes.

#### 6. **recursiveCountLevel**
```c
void recursiveCountLevel(node_t *root, int *levelCounter, int l);
```
- **Purpose**: Recursively counts the number of nodes at each level.
- **Parameters**:
  - `root`: Pointer to the root node of the tree.
  - `levelCounter`: Array to store the count of nodes at each level.
  - `l`: Current level being traversed.
- **Logic**:
  - Increments the count for the current level.
  - Recursively processes the first child and sibling.

#### 7. **printLevel**
```c
void printLevel(node_t *root, int levelToPrint, int l);
```
- **Purpose**: Prints the keys of nodes at a specified level.
- **Parameters**:
  - `root`: Pointer to the root node of the tree.
  - `levelToPrint`: Target level to print.
  - `l`: Current level being traversed.
- **Logic**:
  - Prints the key of the node if the current level matches the target level.
  - Recursively processes the first child and sibling.

---

## Code Logic
### Tree Representation
- A `node_t` structure is used to represent each node of the tree.
- Each node contains:
  - `key`: Integer value representing the node.
  - `first_child`: Pointer to the first child node.
  - `brother`: Pointer to the next sibling node.

### Depth Calculation
- The depth of the tree is the maximum level reached by any node.
- Calculated recursively by comparing the depths of the first child and sibling.

### Crowded Depth Analysis
- Uses an array (`levelCounter`) to count the number of nodes at each level.
- Identifies the level with the highest count and prints the nodes at that level.

---

## Example Execution

### Input (Tree Structure)
```
Root: 17
  - First Child: 22
    - First Child: 1
      - First Child: 9
    - Brother: 5
  - Brother: 2
    - First Child: 12
  - Brother: 31
    - First Child: 7
      - First Child: 3
    - Brother: 4
      - First Child: 15
```

### Output
```
Depth: 4
Maximum level: 2
Nodes at level 2: 1 5 12 7 4
```

---

## Limitations
- **Memory Usage**: Uses an array to store node counts for each level, which may be inefficient for very deep trees.
- **Static Example**: The tree is hardcoded in `main`. No dynamic input is supported.

---

## Future Improvements
- Implement dynamic tree construction with user input.
- Optimize memory usage for counting levels in deep trees.
- Extend functionality to print all levels of the tree.

---

## How to Compile and Run
1. Save the code in a file (e.g., `tree_analysis.c`).
2. Compile the program:
   ```bash
   gcc -o tree_analysis tree_analysis.c
   ```
3. Run the program:
   ```bash
   ./tree_analysis
   ```

