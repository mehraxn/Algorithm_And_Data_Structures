# Graph Representation and Loading in C

This document explains a C program that represents a graph using adjacency lists and provides functionality to load a graph from a file. The explanation breaks down the code line by line for comprehensive understanding.

---

## **Code Overview**
This program provides a utility to:
1. Load a graph from a text file.
2. Store the graph's vertices and edges using adjacency lists.
3. Allow traversal-related information (e.g., discovery and finishing times for DFS) to be stored alongside each vertex.

---

## **Code Explanation**

### **Header Inclusions**
```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
```
- `#include <stdio.h>`: Provides standard I/O functions like `fopen`, `fgets`, `printf`.
- `#include <stdlib.h>`: Provides functions for dynamic memory allocation (e.g., `malloc`, `calloc`) and type conversion.
- `#include <limits.h>`: Defines constants like `INT_MAX` for representing infinity (used in shortest path algorithms).

### **Constants and Enumerations**
```c
#define MAX_LINE 100
enum {WHITE, GREY, BLACK};
```
- `#define MAX_LINE 100`: Sets the maximum length for lines read from the input file.
- `enum {WHITE, GREY, BLACK};`: Represents colors used during graph traversal. These colors indicate the state of a vertex during depth-first search (DFS):
  - **WHITE**: Vertex is unvisited.
  - **GREY**: Vertex is visited but not fully explored.
  - **BLACK**: Vertex is fully explored.

### **Type Definitions**
```c
typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;
```
- **`graph_t`**: Alias for the structure representing the entire graph.
- **`vertex_t`**: Alias for the structure representing a single vertex.

### **Graph Structure Definitions**
```c
struct graph_s {
    vertex_t *g;   // Array of vertices
    int nv;        // Number of vertices in the graph
};
```
- `vertex_t *g`: Pointer to an array of vertices. Each vertex is represented by the `vertex_s` structure.
- `int nv`: Total number of vertices in the graph.

```c
struct vertex_s {
    int id;
    int color;
    int dist;
    int disc_time;
    int endp_time;
    int pred;
    int scc;
    int *rowAdj;
};
```
- `int id`: Unique identifier for the vertex.
- `int color`: Tracks the vertex's state (WHITE, GREY, BLACK) during traversal.
- `int dist`: Distance from the source vertex (used in BFS or shortest path algorithms).
- `int disc_time`: Discovery time (DFS-specific).
- `int endp_time`: Finishing time (DFS-specific).
- `int pred`: Predecessor vertex (used in traversal algorithms).
- `int scc`: Strongly Connected Component index (for SCC algorithms).
- `int *rowAdj`: Pointer to an array representing the adjacency list (neighbors of the vertex).

### **Function Prototypes**
```c
graph_t* graph_load(char *filename);
```
- Declares the `graph_load` function, which loads a graph from a file.

### **Graph Loading Function**
```c
graph_t *graph_load(char *filename) {
```
This function loads a graph from a file and returns a pointer to the created `graph_t` object.

#### **Step 1: Variable Initialization**
```c
graph_t *g;
char line[MAX_LINE];
int i, j, weight, dir;
FILE *fp;
```
- `graph_t *g`: Pointer to store the graph object.
- `char line[MAX_LINE]`: Buffer for reading lines from the file.
- `int i, j, weight, dir`: Temporary variables for parsing file contents.
- `FILE *fp`: File pointer for the graph file.

#### **Step 2: Allocate Memory for the Graph**
```c
g = (graph_t *) malloc(sizeof(graph_t));
```
- Allocates memory for the `graph_t` structure.

#### **Step 3: Open the Input File**
```c
fp = fopen(filename, "r");
```
- Opens the file specified by `filename` in read mode. If the file cannot be opened, the program may crash (no error handling is implemented).

#### **Step 4: Read Number of Vertices and Graph Direction**
```c
fgets(line, MAX_LINE, fp);
if (sscanf(line, "%d%d", &g->nv, &dir) != 2) {
    sscanf(line, "%d", &g->nv);
    dir = 1;  // Assume directed graph if direction is not specified
}
```
- Reads the first line of the file to determine the number of vertices (`nv`) and whether the graph is directed (`dir`):
  - If `dir` is not specified, it defaults to `1` (directed).

#### **Step 5: Initialize Vertices**
```c
g->g = (vertex_t *) malloc(g->nv * sizeof(vertex_t));
for (i = 0; i < g->nv; i++) {
    g->g[i].id = i;
    g->g[i].color = WHITE;
    g->g[i].dist = INT_MAX;
    g->g[i].pred = g->g[i].scc = -1;
    g->g[i].disc_time = g->g[i].endp_time = -1;
    g->g[i].rowAdj = (int *) calloc(g->nv, sizeof(int));
}
```
- Allocates memory for an array of `vertex_t` structures.
- Initializes each vertex with default values:
  - `id`: Vertex index.
  - `color`: Set to `WHITE`.
  - `dist`: Set to `INT_MAX` (infinity).
  - `pred`, `scc`: Set to `-1` (no predecessor or SCC initially).
  - `disc_time`, `endp_time`: Set to `-1` (unvisited).
  - `rowAdj`: Allocates memory for an adjacency list (initialized to zeros).

#### **Step 6: Parse Edges**
```c
while (fgets(line, MAX_LINE, fp) != NULL) {
    if (sscanf(line, "%d%d%d", &i, &j, &weight) != 3) {
        sscanf(line, "%d%d", &i, &j);
        weight = 1;  // Default weight of 1 if not provided
    }

    g->g[i].rowAdj[j] = weight;

    if (dir == 0) {
        g->g[j].rowAdj[i] = weight;
    }
}
```
- Reads edges from the file, assuming one edge per line in the format:
  - `i j weight`: Edge from `i` to `j` with the specified weight.
  - If weight is omitted, defaults to `1`.
- Updates the adjacency list:
  - Adds the edge `i -> j`.
  - If the graph is undirected (`dir == 0`), also adds the edge `j -> i`.

#### **Step 7: Finalize and Return the Graph**
```c
fclose(fp);
return g;
```
- Closes the file and returns the constructed graph.

---

## **Input File Format**
The input file should follow these rules:
1. First line: `<number_of_vertices> <direction_flag>` (optional `direction_flag`):
   - `1`: Directed graph (default).
   - `0`: Undirected graph.
2. Subsequent lines: `<start_vertex> <end_vertex> <weight>` (optional `weight`):
   - If weight is not specified, it defaults to `1`.

### **Example Input File**
```
5 1
0 1 2
0 2 3
1 3
3 4 5
```
- Graph with 5 vertices, directed.
- Edges:
  - `0 -> 1` with weight 2.
  - `0 -> 2` with weight 3.
  - `1 -> 3` with weight 1 (default).
  - `3 -> 4` with weight 5.

---

## **Output Structure**
The graph is represented internally as:
1. `graph_t`: Holds the array of vertices and total vertex count.
2. `vertex_t`: Contains vertex-specific data, including adjacency lists.

This modular design makes it easy to extend the graph representation for additional algorithms or functionality.

