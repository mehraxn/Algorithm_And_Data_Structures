# README: Graph with Adjacency Matrix in C

This document provides a comprehensive explanation of the C program that implements a directed (or undirected) weighted graph using an adjacency matrix. The code reads the graph data from a text file, stores it internally, and then prints the adjacency matrix. It also includes functions to initialize, allocate, free, and dispose of the graph. Below, each part of the code is explained in detail.

---

## Table of Contents

1. [Overview of the Code](#overview-of-the-code)
2. [Header Inclusions and Macros](#header-inclusions-and-macros)
3. [Enumerations (enum)](#enumerations-enum)
4. [Data Structures](#data-structures)
   - [Vertex Structure (`vertex_t`)](#vertex-structure-vertext)
   - [Graph Structure (`graph_t`)](#graph-structure-grapht)
5. [Function Explanations](#function-explanations)
   - [1. `allocate_matrix`](#1-allocate_matrix)
   - [2. `free_matrix`](#2-free_matrix)
   - [3. `graph_attribute_init`](#3-graph_attribute_init)
   - [4. `graph_load`](#4-graph_load)
   - [5. `graph_dispose`](#5-graph_dispose)
   - [6. `graph_print_matrix`](#6-graph_print_matrix)
6. [The `main` Function](#the-main-function)
7. [Example Input File Format](#example-input-file-format)
8. [How to Compile and Run](#how-to-compile-and-run)

---

## Overview of the Code

The program implements a **graph** where each vertex is stored in an array (`vertex_t *v`), and all edges are stored in a **2D adjacency matrix** (`int **rowAdj`). Each cell in `rowAdj[i][j]` holds the **weight** of the edge from vertex `i` to vertex `j`. If there is **no edge**, the weight remains `0` (by default) or you could assign another sentinel value.

The **graph** can be **directed** or **undirected**. This is controlled by a flag (`directed`). If the graph is **undirected**, each edge `i -> j` is automatically mirrored as `j -> i`.

---

## Header Inclusions and Macros

```c
#include <stdio.h>    // For printf, fopen, fclose, etc.
#include <stdlib.h>   // For malloc, calloc, free, exit, etc.
#include <limits.h>   // For INT_MAX (used to initialize distances)

// Define a maximum line length for reading lines from the input file
#define MAX_LINE 100
```

1. **`#include <stdio.h>`**: We need this for standard input/output functions such as `printf`, `fprintf`, `fgets`, etc.  
2. **`#include <stdlib.h>`**: Provides memory allocation functions (`malloc`, `calloc`, `free`) and `exit`.  
3. **`#include <limits.h>`**: Allows us to use `INT_MAX`, which is a convenient maximum integer value (used to initialize distances in graph algorithms).  
4. **`#define MAX_LINE 100`**: Sets a constant for the maximum number of characters to read from a file per line.

---

## Enumerations (`enum`)

```c
enum { WHITE, GREY, BLACK };
```

- This enumeration is typically used in **graph traversal algorithms** (like **Depth-First Search** or **Breadth-First Search**):
  - `WHITE` = The vertex has not been visited yet.  
  - `GREY` = The vertex is in the process of being visited.  
  - `BLACK` = The vertex has been completely visited.  

Even if you do not use these color states in this particular program, it’s a common practice to include them in a graph library for BFS/DFS or other algorithms.

---

## Data Structures

### Vertex Structure (`vertex_t`)

```c
typedef struct vertex_s {
    int id;      // The unique identifier (index) of the vertex
    int color;   // The color (WHITE, GREY, or BLACK)
    int dist;    // Distance (used in BFS/DFS or shortest-path algorithms)
    int pred;    // Predecessor vertex index (for path reconstruction)
    int dtime;   // Discovery time (for DFS)
    int ftime;   // Finishing time (for DFS)
    int scc;     // Strongly Connected Component ID (if needed)
} vertex_t;
```

1. **`id`**: Each vertex has an integer identifier, usually the same as its index in the array.  
2. **`color`**: Holds the state of the vertex during traversals (`WHITE`, `GREY`, or `BLACK`).  
3. **`dist`**: Commonly used for BFS to store the distance from a source vertex. Initially set to `INT_MAX` (unknown).  
4. **`pred`**: The predecessor vertex in a path. Helpful for path reconstruction.  
5. **`dtime` / `ftime`**: Discovery and finishing times used in **DFS**.  
6. **`scc`**: The strongly connected component ID (used in algorithms like Tarjan’s or Kosaraju’s for SCC detection).

### Graph Structure (`graph_t`)

```c
typedef struct graph_s {
    vertex_t *v;     // Array of vertex_t structures
    int **rowAdj;    // 2D adjacency matrix storing edge weights
    int nv;          // Number of vertices
    int ne;          // Number of edges
    int directed;    // 1 if the graph is directed, 0 if undirected
} graph_t;
```

1. **`v`**: A dynamically allocated array of vertices (`vertex_t`). Size is `nv`.  
2. **`rowAdj`**: A **pointer to a 2D array** (allocated dynamically) representing the adjacency matrix.  
   - `rowAdj[i][j]` = weight of edge from `i` to `j`.  
3. **`nv`**: The total number of vertices in the graph.  
4. **`ne`**: The total number of edges in the graph.  
5. **`directed`**: A flag that indicates if the graph is directed (`1`) or undirected (`0`).

---

## Function Explanations

### 1. `allocate_matrix`

```c
int **allocate_matrix(int n) {
    int **matrix = (int **)calloc(n, sizeof(int *));
    if (!matrix) {
        fprintf(stderr, "Error: could not allocate adjacency matrix.
");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));
        if (!matrix[i]) {
            fprintf(stderr, "Error: could not allocate adjacency matrix row.
");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}
```

- **Purpose**: Allocate memory for an `n x n` matrix of integers.  
- **Process**:  
  1. Call `calloc` to create an array of `n` pointers to `int`.  
  2. For each row (0 to n-1), allocate an array of `n` integers, all set to `0`.  
  3. Return the pointer to this 2D array.  
- **Error Handling**: If memory allocation fails, the function prints an error message and calls `exit(EXIT_FAILURE)`.

### 2. `free_matrix`

```c
void free_matrix(int **matrix, int n) {
    if (!matrix) return;
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
```

- **Purpose**: Free the memory used by a 2D matrix.
- **Process**:  
  1. If `matrix` is `NULL`, do nothing.  
  2. Loop through each row and free it.  
  3. Free the matrix array itself.

### 3. `graph_attribute_init`

```c
void graph_attribute_init(graph_t *g) {
    for (int i = 0; i < g->nv; i++) {
        g->v[i].id    = i;
        g->v[i].color = WHITE;
        g->v[i].dist  = INT_MAX;
        g->v[i].pred  = -1;
        g->v[i].dtime = -1;
        g->v[i].ftime = -1;
        g->v[i].scc   = -1;
    }
}
```

- **Purpose**: Initialize all vertices in the graph with default values.  
- **Process**:  
  1. Loop through each vertex and assign it an `id` corresponding to its index.  
  2. Set color to `WHITE` (unvisited).  
  3. Set distance (`dist`) to `INT_MAX`.  
  4. Set predecessor (`pred`) to `-1`.  
  5. Set discovery (`dtime`) and finishing (`ftime`) times to `-1`.  
  6. Set SCC (`scc`) to `-1`.

### 4. `graph_load`

```c
graph_t *graph_load(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file '%s'.
", filename);
        return NULL;
    }
    graph_t *g = (graph_t *)calloc(1, sizeof(graph_t));
    if (!g) {
        fprintf(stderr, "Error: cannot allocate graph.
");
        fclose(fp);
        return NULL;
    }
    char line[MAX_LINE];
    if (!fgets(line, MAX_LINE, fp)) {
        fprintf(stderr, "Error: file is empty or invalid.
");
        free(g);
        fclose(fp);
        return NULL;
    }
    if (sscanf(line, "%d %d", &g->nv, &g->directed) != 2) {
        fprintf(stderr, "Error: invalid first line (should be 'nv directed_flag').
");
        free(g);
        fclose(fp);
        return NULL;
    }
    g->v = (vertex_t *)calloc(g->nv, sizeof(vertex_t));
    if (!g->v) {
        fprintf(stderr, "Error: cannot allocate vertex array.
");
        free(g);
        fclose(fp);
        return NULL;
    }
    graph_attribute_init(g);
    g->rowAdj = allocate_matrix(g->nv);
    int i, j, w;
    g->ne = 0;
    while (fgets(line, MAX_LINE, fp)) {
        if (sscanf(line, "%d %d %d", &i, &j, &w) == 3) {
            if (i < 0 || i >= g->nv || j < 0 || j >= g->nv) {
                fprintf(stderr, "Warning: invalid edge (%d %d %d) ignored.
", i, j, w);
                continue;
            }
            g->rowAdj[i][j] = w;
            g->ne++;
            if (!g->directed) {
                g->rowAdj[j][i] = w;
            }
        }
    }
    fclose(fp);
    return g;
}
```

- **Purpose**: Read graph data from a text file and build a `graph_t` structure with an adjacency matrix.  
- **Process**:  
  1. Open the file and read the number of vertices and whether the graph is directed.  
  2. Allocate memory for the `graph_t` structure and its components.  
  3. Read the edges, store them in the adjacency matrix, and adjust for undirected graphs.  
  4. Close the file and return the constructed graph.

### 5. `graph_dispose`

```c
void graph_dispose(graph_t *g) {
    if (!g) return;
    free_matrix(g->rowAdj, g->nv);
    free(g->v);
    free(g);
}
```

- **Purpose**: Frees all memory associated with the `graph_t` structure.
- **Process**:
  1. If `g` is `NULL`, do nothing.
  2. Free the adjacency matrix using `free_matrix`.
  3. Free the array of vertices (`g->v`).
  4. Free the `graph_t` structure itself (`g`).

### 6. `graph_print_matrix`

```c
void graph_print_matrix(const graph_t *g) {
    printf("Adjacency Matrix (%d vertices):
", g->nv);
    for (int i = 0; i < g->nv; i++) {
        for (int j = 0; j < g->nv; j++) {
            printf("%4d ", g->rowAdj[i][j]);
        }
        printf("
");
    }
}
```

- **Purpose**: Prints the adjacency matrix in a formatted grid.
- **Process**:
  1. Print a header showing the number of vertices.
  2. Loop through each row `i` from 0 to `g->nv - 1`.
  3. Loop through each column `j`, printing the weight `g->rowAdj[i][j]` with proper formatting.
  4. Print a newline after each row.

---

## The `main` Function

```c
int main(void) {
    const char *filename = "graph_data.txt";

    graph_t *myGraph = graph_load(filename);
    if (!myGraph) {
        fprintf(stderr, "Graph loading failed.
");
        return EXIT_FAILURE;
    }

    printf("Graph loaded from '%s'
", filename);
    printf("Number of vertices: %d
", myGraph->nv);
    printf("Directed: %s
", myGraph->directed ? "Yes" : "No");
    printf("Number of edges read: %d
", myGraph->ne);

    graph_print_matrix(myGraph);

    graph_dispose(myGraph);

    return 0;
}
```

- **Purpose**: The entry point of the program, responsible for loading the graph, displaying its adjacency matrix, and freeing allocated memory.
- **Process**:
  1. Define `filename` as the name of the file containing the graph data.
  2. Call `graph_load` to create and populate the graph from the file.
  3. If loading fails, print an error and exit.
  4. Print information about the loaded graph.
  5. Print the adjacency matrix using `graph_print_matrix`.
  6. Free memory using `graph_dispose`.
  7. Return `0` if everything is successful.

---

## Example Input File Format

A typical **input file** named `graph_data.txt` might look like this:

```
10 1
0 1 3
0 2 5
1 3 2
2 3 4
2 4 6
3 9 10
4 5 2
5 6 1
6 7 4
7 8 5
8 9 2
```

- **Line 1**: `10 1` means:
  - `10` = number of vertices (`nv` = 10), labeled `0` through `9`
  - `1` = the graph is directed (if this was `0`, it would be undirected)
- **Subsequent lines**: Each line is `i j w`, meaning an edge from `i` to `j` with weight `w`.

---

## How to Compile and Run

1. **Create the input file** `graph_data.txt` in the same directory as `graph.c`.
2. **Compile** the code with a C compiler, for example:
   ```bash
   gcc graph.c -o graph
   ```
3. **Run** the compiled program:
   ```bash
   ./graph
   ```
4. You should see output that includes:
   - A message indicating the graph was loaded.
   - The number of vertices and edges.
   - Whether the graph is directed.
   - A printed **10×10** adjacency matrix.

---

## Final Notes

- This code provides a **foundation** for more advanced graph algorithms (DFS, BFS, shortest paths, etc.).
- You can **adapt** it for **undirected** graphs by changing the second number on the first line of the input file to `0`.
- You can **change** the adjacency matrix to store special values (e.g., `-1`) for no edge, if desired. Currently, the matrix defaults to `0` where there is no edge.
- The **`color`**, **`dist`**, **`pred`**, **`dtime`**, **`ftime`**, and **`scc`** fields in `vertex_t` are placeholders for typical graph algorithms you might add in the future.

---

**Thank you for using this code!** If you have any questions or want to add new features, you can build upon this template by adding BFS, DFS, shortest-path algorithms, or any other graph-related functionality.

