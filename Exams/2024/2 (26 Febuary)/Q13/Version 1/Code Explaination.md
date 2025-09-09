# Longest Weighted Path with Alternating Colors in a Graph

This README provides a comprehensive explanation of the function `longest_weight_path` and its supporting logic for finding the longest path in a graph with alternating vertex colors.

## Problem Description
The task is to find the longest path in a weighted, directed graph while ensuring that the path alternates between vertices of two colors: WHITE (0) and BLACK (1). The graph is represented using an adjacency matrix.

## Implementation Details

### Core Functions

#### `longest_weight_path`
This function serves as the entry point for finding the longest path with alternating vertex colors. It initializes necessary data structures, performs a depth-first search (DFS) from each vertex, and outputs the path with the maximum weight.

#### `dfs`
This function is a recursive helper used to perform a depth-first search on the graph. It explores paths while adhering to the color alternation constraint and updates the maximum weight path if a longer valid path is found.

### Graph Representation
1. **Adjacency Matrix (`g`)**:
   - `g[i][j]` stores the weight of the edge from vertex `i` to vertex `j`.
   - If no edge exists, `g[i][j] = 0`.

2. **Color Array (`color`)**:
   - An array where `color[i]` represents the color of vertex `i`. Values can be:
     - `0` (WHITE)
     - `1` (BLACK)

3. **Vertex Identifiers (`vertex_id`)**:
   - An array of strings where `vertex_id[i]` is the identifier (e.g., name) of vertex `i`.

### Algorithm
1. **Initialization**:
   - Allocate memory for `visited`, `current_path`, and `best_path` arrays.
   - Set `max_weight` to a very low value (initially `INT_MIN`).

2. **Depth-First Search**:
   - Starting from each vertex, perform a DFS.
   - Ensure the current vertex's color is different from the previous vertex's color.
   - Accumulate the path weight and track the path.

3. **Backtracking**:
   - Mark vertices as unvisited upon returning from recursive calls.
   - This allows exploration of other potential paths.

4. **Output**:
   - Print the path with the maximum weight and its total weight.

### Memory Management
Memory is dynamically allocated for data structures to handle paths and adjacency matrices. Proper deallocation ensures no memory leaks.

## Example

### Input Data
```c
int n = 5; // Number of vertices

// Adjacency matrix representation of the graph
int **g = (int **)malloc(n * sizeof(int *));
for (int i = 0; i < n; i++) {
    g[i] = (int *)calloc(n, sizeof(int));
}

// Defining edges and weights
g[0][1] = 2;
g[1][2] = 3;
g[2][3] = 5;
g[3][4] = 1;

// Vertex colors
int color[] = {WHITE, BLACK, WHITE, BLACK, WHITE};

// Vertex identifiers
char *vertex_id[] = {"this", "is", "the", "selected", "path"};
```

### Execution
```c
longest_weight_path(g, color, vertex_id, n);
```

### Output
```
Maximum weight path with alternating colors:
this is the selected path
Total Weight: 11
```

## Code Explanation

### `longest_weight_path`
- **Parameters**:
  - `int **g`: Adjacency matrix of the graph.
  - `int *color`: Array of vertex colors.
  - `char **vertex_id`: Array of vertex identifiers.
  - `int n`: Number of vertices in the graph.

- **Steps**:
  1. Allocate memory for auxiliary arrays (`visited`, `current_path`, `best_path`).
  2. Iterate over each vertex and call `dfs` to explore paths.
  3. Print the best path and its total weight.
  4. Free allocated memory.

### `dfs`
- **Parameters**:
  - `int **g`: Adjacency matrix of the graph.
  - `int *color`: Array of vertex colors.
  - `char **vertex_id`: Array of vertex identifiers.
  - `int n`: Number of vertices in the graph.
  - `int current`: Current vertex being explored.
  - `int prev_color`: Color of the previous vertex.
  - `int current_weight`: Weight of the current path.
  - `int *visited`: Array to track visited vertices.
  - `int *max_weight`: Pointer to the maximum weight variable.
  - `char **current_path`: Array to store the current path.
  - `char **best_path`: Array to store the best path.
  - `int path_index`: Current depth in the path.

- **Logic**:
  1. Mark the current vertex as visited.
  2. Add the vertex to the current path.
  3. Update the best path if the current weight exceeds `max_weight`.
  4. Recursively explore adjacent vertices while ensuring alternating colors.
  5. Backtrack by unmarking the vertex as visited.

## Edge Cases
1. Graph with no edges: Output should indicate no valid paths.
2. Graph with all vertices of the same color: No path can satisfy the alternating color constraint.
3. Cyclic graphs: Handled by the `visited` array to avoid revisiting vertices.

## Complexity
- **Time Complexity**: `O(V^2)`
  - DFS explores each vertex and edge in the worst-case scenario.
- **Space Complexity**: `O(V)`
  - Additional space for `visited`, `current_path`, and `best_path` arrays.

## Conclusion
The implementation provides an efficient and robust solution to find the longest weighted path with alternating vertex colors in a graph. Proper memory management and adherence to constraints ensure correctness and scalability.

