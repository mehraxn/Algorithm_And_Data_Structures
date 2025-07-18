# Depth-First Search (DFS) Implementation in C

## Overview
This C program implements Depth-First Search (DFS) on a directed graph. It is a recursive algorithm used to explore all the vertices and edges of a graph, while classifying edges and maintaining discovery and finishing times for each vertex. The program uses adjacency lists to represent the graph and provides helper functions for creating vertices, edges, and the graph itself.

---

## Code Structure
The code is modular and organized into the following components:

1. **Graph Representation**
2. **Helper Functions**
3. **DFS Implementation**
4. **Example Usage in `main` Function**

### 1. Graph Representation

The program defines three main structures:

#### **Edge (`edge_t`)**
This structure represents an edge in the graph.
- **Fields:**
  - `weight`: The weight of the edge.
  - `dst`: A pointer to the destination vertex.
  - `next`: A pointer to the next edge in the adjacency list.

#### **Vertex (`vertex_t`)**
This structure represents a vertex in the graph.
- **Fields:**
  - `id`: Unique identifier of the vertex.
  - `color`: Current state of the vertex (WHITE, GRAY, BLACK).
  - `dist`: Distance from the source vertex (not used in this implementation).
  - `disc_time`: Discovery time when the vertex is first visited.
  - `endp_time`: Finishing time when all adjacent vertices are processed.
  - `scc`: Strongly Connected Component ID (optional, not used here).
  - `pred`: Pointer to the predecessor vertex in the DFS tree.
  - `head`: Pointer to the head of the adjacency list of edges.
  - `next`: Pointer to the next vertex in the graph.

#### **Graph (`graph_t`)**
This structure represents the entire graph.
- **Fields:**
  - `nv`: Number of vertices in the graph.
  - `g`: Pointer to the linked list of vertices.

---

### 2. Helper Functions

These functions assist in creating and managing the graph and its components.

#### **Creating a Vertex: `create_vertex`**
- **Description:** Allocates memory for a vertex, initializes its fields, and returns a pointer to the created vertex.
- **Parameters:**
  - `id`: The unique ID of the vertex.
- **Usage:**
```c
vertex_t *v1 = create_vertex(1);
```

#### **Adding an Edge: `add_edge`**
- **Description:** Creates a new edge from a source vertex to a destination vertex and inserts it into the source vertex’s adjacency list.
- **Parameters:**
  - `src`: Pointer to the source vertex.
  - `dst`: Pointer to the destination vertex.
  - `weight`: Weight of the edge.
- **Usage:**
```c
add_edge(v1, v2, 5);
```

#### **Creating a Graph: `create_graph`**
- **Description:** Allocates memory for a graph and initializes its fields.
- **Returns:** Pointer to the created graph.
- **Usage:**
```c
graph_t *g = create_graph();
```

#### **Adding a Vertex: `add_vertex`**
- **Description:** Adds a vertex to the graph by inserting it at the head of the vertex list and increments the vertex count.
- **Parameters:**
  - `g`: Pointer to the graph.
  - `v`: Pointer to the vertex to be added.
- **Usage:**
```c
add_vertex(g, v1);
```

---

### 3. DFS Implementation

#### **Recursive DFS: `graph_dfs_r`**
- **Description:**
  This is the core recursive function that implements DFS.
  - Marks the vertex as visited (GRAY).
  - Updates discovery and finishing times.
  - Classifies edges into categories:
    - **Tree Edge (T):** Edge to an unvisited vertex.
    - **Back Edge (B):** Edge to a vertex that is currently being visited (cycle detected).
    - **Forward Edge (F):** Edge to a fully processed descendant.
    - **Cross Edge (C):** Edge to a vertex in another branch of the DFS tree.
- **Parameters:**
  - `g`: Pointer to the graph.
  - `n`: Pointer to the vertex being visited.
  - `currTime`: Current timestamp for discovery/finishing time.
- **Returns:** Updated current time.
- **Usage:**
```c
currTime = graph_dfs_r(g, v1, currTime);
```

#### **Main DFS Function: `graph_dfs`**
- **Description:**
  - Initiates DFS from a given starting vertex.
  - Handles disconnected components by checking for unvisited vertices.
  - Prints the classification of edges and discovery/finishing times for each vertex.
- **Parameters:**
  - `g`: Pointer to the graph.
  - `n`: Pointer to the starting vertex.
- **Usage:**
```c
graph_dfs(g, v1);
```

---

### 4. Example Usage in `main`

The `main` function demonstrates the creation of a graph, addition of vertices and edges, and execution of DFS.

#### **Steps:**
1. **Create a Graph:**
```c
graph_t *g = create_graph();
```

2. **Create and Add Vertices:**
```c
vertex_t *v1 = create_vertex(1);
vertex_t *v2 = create_vertex(2);
vertex_t *v3 = create_vertex(3);
vertex_t *v4 = create_vertex(4);
add_vertex(g, v1);
add_vertex(g, v2);
add_vertex(g, v3);
add_vertex(g, v4);
```

3. **Add Edges:**
```c
add_edge(v1, v2, 5);
add_edge(v1, v3, 10);
add_edge(v2, v4, 15);
add_edge(v3, v4, 20);
```

4. **Perform DFS:**
```c
graph_dfs(g, v1);
```

---

## Sample Output
The program prints:
1. **List of Edges:**
   - Classification of edges (Tree, Back, Forward, Cross).
2. **List of Vertices:**
   - Discovery and finishing times for each vertex.
   - Predecessor for each vertex.

Example:
```
List of edges:
1 -> 2 : T
2 -> 4 : T
1 -> 3 : T
3 -> 4 : F

List of vertices:
 1:  1/ 8 (-1)
 2:  2/ 7 ( 1)
 3:  3/ 6 ( 1)
 4:  4/ 5 ( 2)
```

---

## Key Concepts and Features
- **Graph Representation:**
  - Adjacency list for efficient traversal and storage.
- **DFS Traversal:**
  - Tracks discovery/finishing times and predecessor relationships.
  - Classifies edges into categories to understand graph structure.
- **Modular Design:**
  - Separate helper functions for graph creation, vertex/edge addition, and traversal.
- **Handling Disconnected Components:**
  - Ensures all vertices are visited in disconnected graphs.

---

## Limitations
- The program assumes unique vertex IDs.
- Does not handle edge cases like memory allocation failures.

---

## Potential Extensions
1. **Graph Input:**
   - Accept user input for vertices and edges.
2. **Strongly Connected Components:**
   - Extend the program to identify SCCs.
3. **Cycle Detection:**
   - Explicitly detect cycles in the graph.
4. **Weighted Graph Traversal:**
   - Use edge weights in traversal (e.g., Dijkstra’s algorithm).

---

This implementation provides a clear, educational example of DFS in a graph, emphasizing modularity and clarity.

