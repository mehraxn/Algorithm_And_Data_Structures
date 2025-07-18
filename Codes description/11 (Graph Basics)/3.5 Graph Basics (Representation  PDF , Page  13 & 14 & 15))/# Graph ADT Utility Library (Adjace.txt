# Graph ADT Utility Library (Adjacency Matrix)

This document presents the **complete code** for a simple Graph Abstract Data Type (ADT) and provides **step-by-step explanations** for each component. All code is shown **unchanged**; explanations follow immediately after.

---

## 1. Constants & Type Definitions

```c
#define MAX_LINE 100
```

* Maximum buffer length for reading lines from a file.

```c
enum { WHITE, GREY, BLACK };
```

* Vertex states for graph traversals:

  * `WHITE` (0): Unvisited
  * `GREY`  (1): Discovered but not finished
  * `BLACK` (2): Fully explored

```c
typedef struct graph_s graph_t;
typedef struct struct vertex_s vertex_t;
```

* Aliases for `struct graph_s` and `struct vertex_s`.

```c
struct graph_s {
    vertex_t *g;  // Dynamic array of vertices
    int nv;       // Number of vertices
};
```

* `graph_t` holds:

  1. `g`: pointer to an array of `vertex_t` of size `nv`.
  2. `nv`: total vertex count.

```c
struct vertex_s {
    int id;         // User-defined vertex identifier
    int color;      // Traversal state (WHITE/GREY/BLACK)
    int dist;       // Distance (e.g., BFS or Dijkstra)
    int disc_time;  // DFS discovery timestamp
    int endp_time;  // DFS finish timestamp
    int pred;       // Predecessor index in search tree
    int scc;        // Strongly connected component ID
    int *rowAdj;    // Adjacency row: weights to other vertices
};
```

* `vertex_t` stores per-vertex data for various graph algorithms.

---

## 2. Loading a Graph (`graph_load`)

```c
graph_t *graph_load(char *filename) {
    graph_t *g;
    char line[MAX_LINE];
    int i, j, weight, dir;
    FILE *fp;

    // Allocate graph wrapper
    g = util_calloc(1, sizeof(graph_t));

    // Open file and read header
    fp = util_fopen(filename, "r");
    fgets(line, MAX_LINE, fp);
    if (sscanf(line, "%d%d", &g->nv, &dir) != 2) {
        sscanf(line, "%d", &g->nv);
        dir = 1;  // default: directed
    }

    // Allocate vertex array
    g->g = util_calloc(g->nv, sizeof(vertex_t));

    // Initialize each vertex
    for (i = 0; i < g->nv; i++) {
        g->g[i].id = i;
        g->g[i].color = WHITE;
        g->g[i].dist = INT_MAX;
        g->g[i].pred = -1;
        g->g[i].scc = -1;
        g->g[i].disc_time = -1;
        g->g[i].endp_time = -1;
        g->g[i].rowAdj = util_calloc(g->nv, sizeof(int));
    }

    // Read edges
    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (sscanf(line, "%d%d%d", &i, &j, &weight) != 3) {
            sscanf(line, "%d%d", &i, &j);
            weight = 1;
        }
        g->g[i].rowAdj[j] = weight;
        if (dir == 0) {
            g->g[j].rowAdj[i] = weight; // undirected
        }
    }
    fclose(fp);
    return g;
}
```

* **Purpose:** Parse a text file to build an adjacency matrix representation.
* **File format:**

  1. First line: `<nv> [dir]`

     * `nv` = number of vertices.
     * `dir` = 0 (undirected) or 1 (directed, default).
  2. Subsequent lines: `<u> <v> [weight]`

     * Edge from `u` to `v`; weight defaults to 1.
* **Steps:**

  1. Allocate memory for `graph_t`.
  2. Read header and set `nv` and `dir`.
  3. Allocate and initialize each `vertex_t`.
  4. Read edges and fill `rowAdj`.
  5. Return the populated graph.

---

## 3. Resetting Vertex Attributes (`graph_attribute_init`)

```c
void graph_attribute_init(graph_t *g) {
    for (int i = 0; i < g->nv; i++) {
        g->g[i].color = WHITE;
        g->g[i].dist = INT_MAX;
        g->g[i].disc_time = -1;
        g->g[i].endp_time = -1;
        g->g[i].pred = -1;
        g->g[i].scc = -1;
    }
}
```

* **Purpose:** Clear all per-vertex state before running algorithms.
* **When to use:** Call before each new traversal (DFS, BFS, SCC, etc.).

---

## 4. Finding a Vertex (`graph_find`)

```c
int graph_find(graph_t *g, int id) {
    for (int i = 0; i < g->nv; i++) {
        if (g->g[i].id == id) {
            return i;
        }
    }
    return -1;
}
```

* **Purpose:** Map a user-defined vertex identifier (`id`) to its array index.
* **Complexity:** O(nv) linear search.
* **Note:** Can be optimized with a hash table for large graphs.

---

## 5. Disposing the Graph (`graph_dispose`)

```c
void graph_dispose(graph_t *g) {
    // Free each adjacency row
    for (int i = 0; i < g->nv; i++) {
        free(g->g[i].rowAdj);
    }
    // Free vertex array and wrapper
    free(g->g);
    free(g);
}
```

* **Purpose:** Release all memory allocated for the graph.
* **Steps:**

  1. Free `rowAdj` for each vertex.
  2. Free the vertex array.
  3. Free the `graph_t` struct.

---

*End of documentation.*
