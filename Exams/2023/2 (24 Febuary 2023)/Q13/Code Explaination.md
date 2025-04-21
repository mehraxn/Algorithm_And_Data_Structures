# README: Graph Cycles Finder Program

## Overview
This program identifies and prints all cycles of a specified length `k` in a directed graph. The graph is represented as an adjacency matrix, and the program uses Depth First Search (DFS) to traverse the graph and detect cycles.

---

## Features
- **Cycle Detection**: Finds all cycles of a given length `k` in the graph.
- **DFS-Based Traversal**: Utilizes a recursive DFS algorithm to explore all possible paths.
- **Path Tracking**: Maintains the visited nodes in the current path.
- **Dynamic Memory Management**: Allocates memory dynamically for graph representation and traversal.

---

## Code Structure
### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Initializes the graph as an adjacency matrix.
  - Specifies the cycle length `k` and the number of vertices `n`.
  - Calls the `loop` function to find and print cycles of length `k`.
  - Frees dynamically allocated memory.

---

#### 2. **loop**
```c
void loop(int **mat, int n, int k);
```
- **Purpose**: Manages the cycle detection process for all vertices.
- **Parameters**:
  - `mat`: Pointer to the adjacency matrix of the graph.
  - `n`: Number of vertices in the graph.
  - `k`: Desired cycle length.
- **Logic**:
  - Allocates memory for marking visited nodes and storing paths.
  - Calls the `DFS` function for each vertex as the starting point.
  - Prints the total number of cycles found.
- **Memory Management**:
  - Frees allocated memory after processing.

---

#### 3. **DFS**
```c
void DFS(int **graph, int *marked, int n, int k, int vert, int start, int *count, int *path, int fixed_k);
```
- **Purpose**: Performs a Depth First Search to detect cycles.
- **Parameters**:
  - `graph`: Pointer to the adjacency matrix of the graph.
  - `marked`: Array to track visited vertices.
  - `n`: Number of vertices in the graph.
  - `k`: Remaining steps to complete the cycle.
  - `vert`: Current vertex in the traversal.
  - `start`: Starting vertex of the cycle.
  - `count`: Pointer to the counter for cycles found.
  - `path`: Array to store the current path.
  - `fixed_k`: Original cycle length.
- **Logic**:
  - Marks the current vertex as visited and adds it to the path.
  - If `k == 0`, checks if the current vertex connects back to the starting vertex to form a cycle.
  - Recursively explores all unvisited neighbors of the current vertex.
  - Unmarks the current vertex before backtracking.
- **Output**:
  - Prints each detected cycle.

---

## Example Execution

### Input Graph (Adjacency Matrix)
```
0 1 1 0
0 0 1 0
0 0 0 1
1 0 0 0
```
- This represents a directed graph with 4 vertices.

### Parameters
- `n = 4`: Number of vertices.
- `k = 3`: Desired cycle length.

### Output
```
Cycle 1: 0 2 1
Cycle 2: 1 3 2
Cycle 3: 2 0 3
Cycle 4: 3 1 0
Total cycles of length 3 are 4
```

### Explanation
- The program detects all cycles of length 3 in the graph and prints each cycle.

---

## Data Structures
- **Adjacency Matrix**: Represents the directed graph.
  - `mat[i][j] = 1`: Indicates an edge from vertex `i` to vertex `j`.
  - `mat[i][j] = 0`: Indicates no edge.
- **Visited Array (`marked`)**: Tracks whether a vertex is currently in the path to prevent revisiting.
- **Path Array (`path`)**: Stores the current path during DFS traversal.

---

## Memory Management
- **Dynamic Allocation**:
  - Allocates memory for the adjacency matrix, visited array, and path array.
- **Deallocation**:
  - Frees all allocated memory after the traversal and processing are complete.

---

## Limitations
- **Fixed Cycle Length**: The program only searches for cycles of a specific length `k`.
- **Directed Graphs Only**: Does not handle undirected graphs.
- **Efficiency**: The recursive DFS may become computationally expensive for large graphs or high values of `k`.

---

## Future Improvements
- Extend support to handle undirected graphs.
- Optimize the algorithm for large graphs using advanced graph traversal techniques.
- Add functionality to find cycles of all lengths.
- Provide a user interface to input graphs dynamically.

---

## How to Compile and Run
1. Save the code in a file (e.g., `graph_cycles.c`).
2. Compile the program:
   ```bash
   gcc -o graph_cycles graph_cycles.c
   ```
3. Run the program:
   ```bash
   ./graph_cycles
   ```

