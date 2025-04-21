# README: Explanation of the Weighted Graph Functions

This document provides a comprehensive, line-by-line explanation of the code for the `isRegular` and `findSimplePath` functions, which operate on a weighted directed graph represented as an adjacency list.

---

## **Code Breakdown**

### **Header Files**
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
```
- **`#include <stdio.h>`**: Provides functions for input and output operations (e.g., `printf`).
- **`#include <stdlib.h>`**: Provides functions for dynamic memory management (e.g., `malloc`, `free`).
- **`#include <stdbool.h>`**: Provides the `bool` data type to use `true` and `false` values.

---

### **Graph Structures**
#### 1. **Edge Structure**
```c
typedef struct Edge {
    int destination; // Destination vertex
    int weight;      // Weight of the edge
    struct Edge *next; // Pointer to the next edge
} Edge;
```
- Represents a directed edge in the graph.
- **Fields**:
  - `destination`: The ID of the vertex this edge points to.
  - `weight`: The weight of the edge.
  - `next`: Pointer to the next edge in the adjacency list.

#### 2. **Vertex Structure**
```c
typedef struct Vertex {
    int id;         // Vertex identifier
    Edge *edges;    // Adjacency list of edges
} Vertex;
```
- Represents a vertex in the graph.
- **Fields**:
  - `id`: Unique identifier for the vertex.
  - `edges`: Pointer to the first edge in the adjacency list.

#### 3. **Graph Structure**
```c
typedef struct Graph {
    int numVertices; // Number of vertices in the graph
    Vertex *vertices; // Array of vertices
} Graph;
```
- Represents the entire graph.
- **Fields**:
  - `numVertices`: Total number of vertices in the graph.
  - `vertices`: Array of vertices, where each vertex contains its adjacency list.

---

### **`isRegular` Function**
#### Prototype
```c
int isRegular(Graph *graph);
```
- **Purpose**: Determines if the graph is "regular" (all vertices have the same degree).
- **Parameters**:
  - `Graph *graph`: Pointer to the graph.
- **Return Value**:
  - Returns `1` if the graph is regular.
  - Returns `0` if the graph is not regular.

#### Implementation
```c
if (graph->numVertices == 0) return 1;
```
- If the graph has no vertices, it is trivially regular.

```c
int degree = 0;
for (Edge *edge = graph->vertices[0].edges; edge != NULL; edge = edge->next) {
    degree++;
}
```
- Calculates the degree of the first vertex by counting its outgoing edges.

```c
for (int i = 1; i < graph->numVertices; i++) {
    int currentDegree = 0;
    for (Edge *edge = graph->vertices[i].edges; edge != NULL; edge = edge->next) {
        currentDegree++;
    }
    if (currentDegree != degree) {
        return 0;
    }
}
```
- Iterates over all vertices and compares their degree to the degree of the first vertex.
- If any vertex has a different degree, the function returns `0` (not regular).

```c
return 1;
```
- If all vertices have the same degree, the function returns `1` (regular).

---

### **`findSimplePath` Function**
#### Prototype
```c
int findSimplePath(Graph *graph, int startVertex);
```
- **Purpose**: Finds the maximum-weight simple path starting from a given vertex.
- **Parameters**:
  - `Graph *graph`: Pointer to the graph.
  - `int startVertex`: ID of the vertex from which to start the path.
- **Return Value**:
  - Returns `1` if a path with positive weight is found.
  - Returns `0` otherwise.

#### Helper Function: `findSimplePathHelper`
```c
void findSimplePathHelper(Graph *graph, int vertex, bool *visited, int currentWeight, int *maxWeight, int *path, int *maxPath, int depth);
```
- **Purpose**: Recursively explores paths from the current vertex.
- **Parameters**:
  - `bool *visited`: Array to track visited vertices.
  - `int currentWeight`: Weight of the current path.
  - `int *maxWeight`: Pointer to the maximum weight found so far.
  - `int *path`: Array to store the current path.
  - `int *maxPath`: Array to store the maximum-weight path.
  - `int depth`: Current depth of the recursion.

#### Key Steps
```c
visited[vertex] = true;
path[depth] = vertex;
```
- Marks the current vertex as visited and adds it to the path.

```c
if (currentWeight > *maxWeight) {
    *maxWeight = currentWeight;
    for (int i = 0; i <= depth; i++) {
        maxPath[i] = path[i];
    }
    maxPath[depth + 1] = -1; // Mark the end of the path
}
```
- Updates the maximum weight and path if the current path's weight exceeds the maximum found so far.

```c
for (Edge *edge = graph->vertices[vertex].edges; edge != NULL; edge = edge->next) {
    if (!visited[edge->destination]) {
        findSimplePathHelper(graph, edge->destination, visited, currentWeight + edge->weight, maxWeight, path, maxPath, depth + 1);
    }
}
```
- Explores all unvisited adjacent vertices recursively.

```c
visited[vertex] = false;
```
- Marks the vertex as unvisited before backtracking.

#### Main Function Implementation
```c
bool *visited = (bool *)calloc(graph->numVertices, sizeof(bool));
int *path = (int *)malloc(graph->numVertices * sizeof(int));
int *maxPath = (int *)malloc((graph->numVertices + 1) * sizeof(int));
int maxWeight = 0;
```
- Allocates memory for visited array, path array, and maxPath array.

```c
findSimplePathHelper(graph, startVertex, visited, 0, &maxWeight, path, maxPath, 0);
```
- Calls the helper function to find the maximum-weight path.

```c
printf("Maximum-weight simple path starting from vertex %d:\n", startVertex);
printf("Path: ");
for (int i = 0; maxPath[i] != -1; i++) {
    printf("%d ", maxPath[i]);
}
printf("\nTotal weight: %d\n", maxWeight);
```
- Prints the path and its weight.

```c
free(visited);
free(path);
free(maxPath);
```
- Frees allocated memory.

```c
return (maxWeight > 0) ? 1 : 0;
```
- Returns `1` if a valid path is found; otherwise, `0`.

---

### **Example Usage**
1. Create a graph.
2. Add edges to represent connections between vertices.
3. Call `isRegular` to check if the graph is regular.
4. Call `findSimplePath` to find the maximum-weight simple path from a specified vertex.

---

