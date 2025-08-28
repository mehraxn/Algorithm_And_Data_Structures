# Graph Data Structures in C

This README describes the key data structures used to represent and traverse a graph in C, specifically using an adjacency-list approach. It details the `graph_t` and `vertex_t` structures and explains the purpose of each member, indicating whether it is used by Breadth-First Search (BFS), Depth-First Search (DFS), or both.

---

## Constants and Enums

```c
#define MAX_LINE 100
enum { WHITE, GREY, BLACK };
```

* **MAX\_LINE**: Maximum size for reading lines (e.g., from input files).
* **Color Enum** (`WHITE`, `GREY`, `BLACK`): Used in both DFS and BFS to track the visitation state of each vertex.

  * `WHITE`: Unvisited
  * `GREY`: Discovered but not fully explored
  * `BLACK`: Fully explored

---

## Structure Definitions

### `graph_t`

```c
typedef struct graph_s {
    vertex_t *g;   // Array of vertices
    int nv;        // Number of vertices
} graph_t;
```

* **g**: Pointer to an array of `vertex_t`. Represents all vertices in the graph.
* **nv**: Total number of vertices in the graph.

This structure encapsulates the whole graph, providing easy iteration over all vertices and overall size.

### `vertex_t`

```c
typedef struct vertex_s {
    int id;            // Unique vertex identifier
    int color;         // Visitation state (WHITE, GREY, BLACK)
    int dist;          // Distance from source (BFS)
    int disc_time;     // Discovery time (DFS)
    int endp_time;     // Finish time (DFS)
    int pred;          // Predecessor in traversal tree (BFS/DFS)
    int scc;           // Strongly Connected Component index (SCC algorithms)
    int *rowAdj;       // Adjacency list (neighbor indices)
} vertex_t;
```

| Member      | Description                                                              | Used By   |
| ----------- | ------------------------------------------------------------------------ | --------- |
| `id`        | Unique integer identifier for each vertex.                               | All       |
| `color`     | Tracks visitation state: `WHITE`, `GREY`, `BLACK`.                       | BFS, DFS  |
| `dist`      | Distance from the source vertex in BFS.                                  | BFS only  |
| `disc_time` | Timestamp when the vertex is first discovered.                           | DFS only  |
| `endp_time` | Timestamp when DFS finishes exploring the vertex.                        | DFS only  |
| `pred`      | Index of predecessor vertex in the traversal tree.                       | BFS, DFS  |
| `scc`       | Identifier for the strongly connected component (after SCC computation). | SCC algos |
| `rowAdj`    | Dynamic array of adjacent vertex indices (adjacency list).               | All       |

* **`rowAdj`**: Typically implemented as a dynamically allocated array (or list) of integers, each representing the index of a neighbor vertex in the graph's vertex array.

---

## Example Usage

Below is a sketch of how these structures might be initialized and used in a program:

```c
// Allocate graph with N vertices
graph_t graph;
graph.nv = N;
graph.g = malloc(N * sizeof(vertex_t));

// Initialize each vertex
for (int i = 0; i < N; i++) {
    graph.g[i].id = i;
    graph.g[i].color = WHITE;
    graph.g[i].dist = -1;         // Unset distance
    graph.g[i].disc_time = 0;
    graph.g[i].endp_time = 0;
    graph.g[i].pred = -1;         // No predecessor
    graph.g[i].scc = -1;          // Unset component
    graph.g[i].rowAdj = NULL;     // To be filled when reading edges
}

// Read edges and build adjacency lists...
```

Use BFS to compute shortest paths by updating `.color`, `.dist`, and `.pred`. Use DFS to explore the full graph structure and record discovery/finish times via `.disc_time` and `.endp_time`. After computing strongly connected components (e.g., with Kosaraju’s algorithm), fill in each vertex’s `.scc` field.

---

This README should help you understand and extend the graph representation and traversal routines in your C projects. For more detailed implementations of BFS, DFS, and SCC algorithms, refer to accompanying source files.
