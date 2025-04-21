# README: Graph Coloring Program

## Overview
This program implements a graph coloring algorithm to assign the minimum number of colors to the vertices of a graph such that no two adjacent vertices share the same color. The graph is represented as an adjacency matrix, which is read from an input file. The output displays the color assigned to each vertex.

## Features
- Reads an adjacency matrix from a file.
- Implements a backtracking algorithm to find a valid vertex coloring.
- Dynamically determines the minimum number of colors required for the graph.
- Outputs the assigned colors for each vertex.

---

## Code Structure
### Main Functions and Their Purpose

### 1. **isCorrect**
```c
int isCorrect(int vertex, int **matrix, int *colors, int color, int n);
```
- **Purpose**: Checks whether assigning a given `color` to a `vertex` is valid.
- **Parameters**:
  - `vertex`: The index of the vertex to color.
  - `matrix`: The adjacency matrix of the graph.
  - `colors`: The array storing colors assigned to vertices.
  - `color`: The color being checked.
  - `n`: The number of vertices.
- **Logic**: Ensures no adjacent vertex (as per the adjacency matrix) has the same color.
- **Returns**: `1` if the color assignment is valid, otherwise `0`.

---

### 2. **generate_color**
```c
int generate_color(int vertex, int **matrix, int *colors, int numColors, int n);
```
- **Purpose**: Implements the backtracking algorithm to assign colors to vertices.
- **Parameters**:
  - `vertex`: The current vertex to color.
  - `matrix`: The adjacency matrix of the graph.
  - `colors`: The array storing colors assigned to vertices.
  - `numColors`: The maximum number of colors allowed.
  - `n`: The number of vertices.
- **Logic**:
  - Assigns colors to vertices iteratively.
  - Calls itself recursively for the next vertex until all vertices are successfully colored.
  - Backtracks if a valid coloring cannot be found with the current color configuration.
- **Returns**: `1` if all vertices are successfully colored, otherwise `0`.

---

### 3. **color**
```c
void color(int **matrix, int n);
```
- **Purpose**: Manages the coloring process and dynamically determines the minimum number of colors required.
- **Parameters**:
  - `matrix`: The adjacency matrix of the graph.
  - `n`: The number of vertices.
- **Logic**:
  - Initializes the color array with `0`.
  - Incrementally increases the number of allowed colors (`numColors`) until the graph can be successfully colored.
  - Displays the vertex-to-color mapping.
- **Output**: Prints the vertex and its assigned color.

---

### 4. **readAdjacencyMatrixFromFile**
```c
int** readAdjacencyMatrixFromFile(char* filename, int* n);
```
- **Purpose**: Reads the adjacency matrix of the graph from a file.
- **Parameters**:
  - `filename`: The name of the file containing the adjacency matrix.
  - `n`: A pointer to store the number of vertices in the graph.
- **Logic**:
  - Opens the file in read mode.
  - Reads the size of the graph (`n`) and the adjacency matrix values.
  - Dynamically allocates memory for the matrix.
- **Returns**: A pointer to the adjacency matrix or `NULL` if the file cannot be opened.

---

### 5. **main**
```c
int main();
```
- **Purpose**: The entry point of the program.
- **Logic**:
  - Reads the adjacency matrix from a file.
  - Calls the `color` function to perform graph coloring.
  - Frees allocated memory for the adjacency matrix.
- **File Used**: `adjmatrix.txt` (must exist in the working directory).

---

## Input File Format
The input file should contain the adjacency matrix of the graph.
- The first line specifies the number of vertices `n`.
- The next `n` lines contain `n` space-separated integers, representing the adjacency matrix.

**Example File (adjmatrix.txt):**
```
4
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
```

This represents a graph with 4 vertices and edges between adjacent vertices as specified.

---

## Output
The program outputs the vertex-to-color mapping in the format:
```
Vertex;  Color
0	1
1	2
2	3
3	1
```
Here, each vertex is assigned a color such that no two adjacent vertices share the same color.

---

## Memory Management
- Dynamically allocated memory for the adjacency matrix and the colors array is properly freed to avoid memory leaks.

---

## Error Handling
- If the input file cannot be opened, the program outputs an error message: `"Error opening file."`
- Ensures graceful termination if memory allocation or file reading fails.

---

## How to Compile and Run
1. Save the code in a file (e.g., `graph_coloring.c`).
2. Use the following commands to compile and run:
   ```bash
   gcc -o graph_coloring graph_coloring.c
   ./graph_coloring
   ```
3. Ensure the input file (`adjmatrix.txt`) is in the same directory as the executable.

---

## Dependencies
- Standard C libraries: `<stdio.h>`, `<stdlib.h>`

---

## Limitations
- The algorithm uses a brute-force backtracking approach, which may not be efficient for large graphs.
- Assumes the input file format is correct; no extensive validation is performed.

---

## Future Improvements
- Implement heuristic or optimized graph coloring algorithms for better performance on large graphs.
- Add input validation and error recovery for malformed input files.
- Provide user interaction to input the adjacency matrix directly or select the file dynamically.

