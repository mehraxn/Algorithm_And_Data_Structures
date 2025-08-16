# Graph Representation in C – README

## Overview

This C code implements basic functionality for loading and managing a graph using an adjacency matrix representation. It includes robust error handling for memory allocation and file I/O operations and provides utility functions and graph-related operations. The graph is stored as an array of vertices, with each vertex containing an array that represents its adjacency row (i.e., edge weights).

---

## Detailed Explanation

### Header Files

- **`<stdio.h>`**: Provides standard input and output functions (e.g., `printf`, `fopen`).
- **`<stdlib.h>`**: Offers functions for memory allocation (`calloc`, `free`), process control, conversions, etc.
- **`<string.h>`**: Contains string manipulation functions (although not directly used in this code).
- **`<limits.h>`**: Defines constants for variable limits; here, `INT_MAX` is used to initialize discovery times.

---

### Macro Definitions

- **`#define MAX_LINE 100`**: Sets a constant to define the maximum length (in characters) for a line when reading from the file.

---

### Enumerations

An enumeration is defined to represent the color state of each vertex during graph traversal:

```c
enum { WHITE = 0, GREY = 1, BLACK = 2 };
```

- **WHITE (0)**: Indicates that the vertex has not been visited.
- **GREY (1)**: Marks a vertex that is currently being processed (e.g., in a depth-first search).
- **BLACK (2)**: Signifies that the vertex has been completely processed.

---

### Utility Functions

#### `util_calloc`

```c
void *util_calloc(size_t nmemb, size_t size);
```
- **Purpose**: Safely allocates memory for an array.
- **How it works**:
  - Uses `calloc` to allocate memory for `nmemb` elements of `size`.
  - If the allocation fails, an error message is printed and the program exits.

#### `util_fopen`

```c
FILE *util_fopen(const char *filename, const char *mode);
```
- **Purpose**: Safely opens a file.
- **How it works**:
  - Attempts to open the file with the given filename and mode.
  - If the file cannot be opened, it prints an error message and exits the program.

---

### Data Structures

#### Vertex Structure (`vertex_t`)

```c
typedef struct vertex_s {
    int id;
    int color;
    int disc_time;
    int endp_time;
    int pred;
    int scc;
    int *rowadj;  /* adjacency row (array of weights) */
} vertex_t;
```

- **id**: Identifier for the vertex.
- **color**: Holds the vertex’s color (used in graph traversal algorithms).
- **disc_time**: Records the discovery time of the vertex during traversal.
- **endp_time**: Records the finishing time after the vertex is processed.
- **pred**: Stores the predecessor (or parent) vertex in traversal.
- **scc**: Used to label the strongly connected component (SCC) the vertex belongs to.
- **rowadj**: Points to an array that represents the adjacency row, holding the weights of edges from this vertex to others.

#### Graph Structure (`graph_t`)

```c
typedef struct graph_s {
    vertex_t *g;  /* array of vertices */
    int nv;       /* number of vertices */
} graph_t;
```

- **g**: A pointer to an array of vertices.
- **nv**: The number of vertices in the graph.

---

### Graph-Related Functions

#### `graph_load`

```c
graph_t *graph_load(const char *filename);
```

- **Purpose**: Loads a graph from a file using an adjacency matrix representation.
- **File Format**:
  - **First line**: Two integers, `nv` (number of vertices) and `dir` (direction flag: 0 for undirected, 1 for directed).
  - **Subsequent lines**: Three integers per line (`i j weight`), meaning there is an edge from vertex `i` to vertex `j` with the given weight.
- **Steps in the Function**:
  1. Allocates memory for the graph structure.
  2. Opens the file using `util_fopen`.
  3. Reads the number of vertices (`nv`) and the direction flag (`dir`).
  4. Allocates an array of `vertex_t` structures.
  5. Initializes each vertex and allocates memory for its adjacency row.
  6. Reads edges from the file and populates the adjacency matrix.
  7. Closes the file and returns the constructed graph.

#### `graph_attribute_init`

```c
void graph_attribute_init(graph_t *g);
```

- **Purpose**: Resets or initializes attributes needed for graph traversal.
- **Actions**:
  - Iterates over each vertex in the graph.
  - Resets `color` to WHITE.
  - Sets `disc_time` to `INT_MAX`.
  - Sets `endp_time`, `pred`, and `scc` to `-1`.

#### `graph_find`

```c
int graph_find(graph_t *g, int id);
```

- **Purpose**: Searches for a vertex by its identifier.
- **How it Works**:
  - Iterates through the vertex array.
  - Returns the index of the vertex if found; otherwise, returns `-1`.

#### `graph_dispose`

```c
void graph_dispose(graph_t *g);
```

- **Purpose**: Frees all memory allocated for the graph.
- **Actions**:
  - Iterates over each vertex and frees the memory allocated for its adjacency row.
  - Frees the memory allocated for the vertex array.
  - Finally, frees the graph structure itself.

---

### Missing Parts in the Code

1. **No Main Function**: The code does not include a `main()` function to demonstrate usage. A `main()` function would:
   - Call `graph_load("graph.txt")`.
   - Perform graph operations (like traversal or analysis).
   - Call `graph_dispose(...)` to free resources.

2. **Traversal Algorithms**: The code lacks a **Depth-First Search (DFS)** or **Breadth-First Search (BFS)** function. The color states (`WHITE`, `GREY`, `BLACK`) are useful for traversal, but no traversal logic is implemented.

3. **Edge Weight Usage**: The adjacency matrix stores weights, but no shortest-path or minimum spanning tree algorithms are included (e.g., Dijkstra’s, Prim’s, or Kruskal’s algorithms).

---

## How to Use the Code

### Compilation
```bash
gcc -o graph_program your_source_file.c
```

### Input File Format
Example `graph.txt`:
```
5 0
0 1 10
0 2 5
1 2 3
1 3 2
2 3 2
3 4 7
```

### Running the Program
```bash
./graph_program
```

---

## Conclusion
This code offers a foundation for graph operations in C. By providing structures and initialization routines for an adjacency matrix, you can extend it to support:
- **Graph traversal** (DFS, BFS).
- **Shortest path calculations** (Dijkstra's, Floyd-Warshall).
- **Strongly connected components detection** (Kosaraju's, Tarjan's algorithm).

Feel free to modify and expand upon this code for your project!

