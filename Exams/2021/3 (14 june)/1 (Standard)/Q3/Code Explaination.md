# README: Graph Edge Cover Function

This document provides a detailed explanation and implementation of the `edge_cover` function, which finds the **minimum edge cover** of an undirected and unweighted graph. The minimum edge cover ensures that every vertex in the graph is incident to at least one edge in the selected set.

## Problem Statement
Given an undirected and unweighted graph represented using an adjacency matrix, the goal is to determine the minimum edge cover of the graph. An edge cover is a set of edges such that every vertex in the graph is connected to at least one edge in the set.

### Example Graph:
For the following graph:
```
  0 --- 1
  |     |
  3 --- 2
```

The minimum edge cover is:
- Edges `(0, 1)` and `(2, 3)`.

## Abstract Data Type (ADT) for Graph Representation

### Graph Representation
The graph is represented using an adjacency matrix, where:
- `matrix[i][j] == 1` if there is an edge between vertex `i` and vertex `j`.
- `matrix[i][j] == 0` if no edge exists between vertex `i` and vertex `j`.

### Client-Implementation Structure
1. **Header File (`graph.h`):**
   - Contains the definition of the `Graph` structure and function prototypes.
2. **Source File (`graph.c`):**
   - Implements the `Graph` functions, including creation, deletion, edge addition, and the recursive `edge_cover` function.
3. **Main Program (`main.c`):**
   - Creates a sample graph, calls the `edge_cover` function, and displays the result.

---

## Header File (`graph.h`)
```c
#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int **matrix;    // Adjacency matrix
    int numVertices; // Number of vertices
} Graph;

// Function prototypes
Graph *createGraph(int numVertices);
void addEdge(Graph *graph, int u, int v);
void freeGraph(Graph *graph);
int edge_cover(Graph *graph);

#endif
```

---

## Source File (`graph.c`)
```c
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Create a new graph with a given number of vertices
Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (!graph) {
        fprintf(stderr, "Memory allocation failed for graph.\n");
        return NULL;
    }

    graph->numVertices = numVertices;

    // Allocate memory for adjacency matrix
    graph->matrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph->matrix[i] = (int *)calloc(numVertices, sizeof(int));
    }

    return graph;
}

// Add an edge between two vertices
void addEdge(Graph *graph, int u, int v) {
    if (u >= graph->numVertices || v >= graph->numVertices) {
        fprintf(stderr, "Invalid vertices for edge.\n");
        return;
    }
    graph->matrix[u][v] = 1;
    graph->matrix[v][u] = 1;
}

// Free the graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

// Recursive function to find the minimum edge cover
int edge_cover_helper(Graph *graph, int *covered, int currentEdgeCount, int currentVertex) {
    int numVertices = graph->numVertices;

    // Check if all vertices are covered
    int allCovered = 1;
    for (int i = 0; i < numVertices; i++) {
        if (!covered[i]) {
            allCovered = 0;
            break;
        }
    }
    if (allCovered) {
        return currentEdgeCount;
    }

    // Initialize minimum edge count to a large value
    int minEdges = numVertices * (numVertices - 1);

    // Try adding an edge for uncovered vertices
    for (int i = 0; i < numVertices; i++) {
        if (!covered[i]) {
            for (int j = 0; j < numVertices; j++) {
                if (graph->matrix[i][j] && !covered[j]) {
                    // Temporarily mark vertices as covered
                    covered[i] = 1;
                    covered[j] = 1;

                    // Recurse with this edge included
                    int edges = edge_cover_helper(graph, covered, currentEdgeCount + 1, i + 1);

                    // Backtrack
                    covered[i] = 0;
                    covered[j] = 0;

                    // Update minimum edge count
                    if (edges < minEdges) {
                        minEdges = edges;
                    }
                }
            }
            break; // Only consider one uncovered vertex at a time
        }
    }

    return minEdges;
}

// Main function to find the minimum edge cover
int edge_cover(Graph *graph) {
    int *covered = (int *)calloc(graph->numVertices, sizeof(int));
    if (!covered) {
        fprintf(stderr, "Memory allocation failed for covered array.\n");
        return -1;
    }
    int result = edge_cover_helper(graph, covered, 0, 0);
    free(covered);
    return result;
}
```

---

## Main Program (`main.c`)
```c
#include <stdio.h>
#include "graph.h"

int main() {
    // Create a graph with 4 vertices
    Graph *graph = createGraph(4);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    // Find and print the minimum edge cover
    int minEdgeCover = edge_cover(graph);
    if (minEdgeCover != -1) {
        printf("Minimum edge cover: %d\n", minEdgeCover);
    }

    // Free the graph
    freeGraph(graph);

    return 0;
}
```

---

## Explanation of the Code

1. **Graph Representation:**
   - The adjacency matrix stores edges between vertices. The matrix is dynamically allocated to handle graphs of varying sizes.

2. **Recursive Edge Cover Function:**
   - The `edge_cover_helper` function recursively explores subsets of edges to determine the minimum set that covers all vertices.
   - Backtracking is used to explore all possibilities and ensure correctness.

3. **Edge Cover Function:**
   - Calls the recursive helper function and tracks covered vertices using an array.
   - Returns the minimum edge count required to cover all vertices.

4. **Main Program:**
   - Demonstrates graph creation, edge addition, and edge cover computation using sample data.

---

## Complexity Analysis

1. **Time Complexity:**
   - Worst-case: \(O(2^E)\), where \(E\) is the number of edges, due to recursive exploration of subsets.
   - Suitable for small graphs.

2. **Space Complexity:**
   - \(O(V)\), where \(V\) is the number of vertices, for tracking covered vertices.

---

## Example Execution

### Input:
Graph with edges:
- `(0, 1)`
- `(1, 2)`
- `(2, 3)`
- `(3, 0)`

### Output:
```
Minimum edge cover: 2
```

---

This implementation provides a robust solution for finding the minimum edge cover of an undirected graph, using modular and reusable components.

