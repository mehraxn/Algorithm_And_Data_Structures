# Graph (List of Lists) in C — Complete Guide & Code

This README walks you **from A to Z** through a small but complete C project that **reads a graph** from a text file and stores it as an **adjacency list** ("list of lists"). It includes:

* A clear **input file format** (directed/undirected, weighted/unweighted).
* A working **CLI** that loads a graph and prints it.
* Clean **data structures**, safe **utilities**, and a **Makefile**.
* A **line‑by‑line walkthrough** of the code so you understand exactly what every line does.

---

## 1) What you’ll build

A graph reader using adjacency lists:

* Each **vertex** has a **linked list** of outgoing **edges**.
* **Directed** (default) or **undirected** (flag in the input header).
* **Weighted** or **unweighted** edges (missing weight → default `1`).
* A small **graph\_print** to verify the result.

---

## 2) Project layout

```
.
├─ include/
│  ├─ graph.h      // public graph API and data structures
│  └─ util.h       // safe wrappers: util_malloc/util_calloc/util_fopen
├─ src/
│  ├─ graph.c      // graph implementation (load, print, find, free)
│  ├─ util.c       // utilities implementation
│  └─ main.c       // demo CLI entrypoint
└─ Makefile
```

> You can copy the code blocks below into these files.

---

## 3) Input file format

**Header (first line):**

```
N [dir]
```

* `N` = number of vertices (IDs are `0..N-1`).
* `dir` is **optional**: `1` for **directed** (default), `0` for **undirected**.

**Edges (subsequent lines):**

```
u v [w]
```

* `u v` = edge from `u` to `v`.
* Optional `w` = weight (defaults to `1` if omitted).
* If `dir = 0` (undirected), we insert **both** `(u→v)` and `(v→u)`.

**Example — directed, weighted**

```
5 1
0 1 3
0 2 1
1 3 2
2 3 5
3 4 4
```

**Example — undirected, unweighted**

```
4 0
0 1
1 2
2 3
0 3
```

---

## 4) Build and run

### Requirements

* A C compiler (GCC or Clang)
* `make`

### Commands

```bash
make          # builds the demo executable: graph_demo
./graph_demo sample_graph.txt
make clean    # removes build artifacts
```

For convenience, create `sample_graph.txt` using one of the examples above.

---

## 5) Full code (copy into files)

### `include/graph.h`

```c
#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

// Colors for search algorithms (unused by the demo, but kept from the design)
enum { WHITE, GREY, BLACK };

// Forward declarations
typedef struct graph_s   graph_t;
typedef struct vertex_s  vertex_t;
typedef struct edge_s    edge_t;

// Graph wrapper: holds number of vertices and a linked list of all vertices
struct graph_s {
    int nv;         // number of vertices
    vertex_t *g;    // head of the vertex list (0..nv-1 in ascending order)
};

// Edge node: destination pointer, weight, and next edge in adjacency list
struct edge_s {
    int weight;     // edge weight (>= 1)
    vertex_t *dst;  // destination vertex
    edge_t *next;   // next edge from the same source vertex
};

// Vertex node: id and per-vertex metadata + adjacency list head
struct vertex_s {
    int id;             // vertex identifier (0..nv-1)
    int color;          // WHITE/GREY/BLACK (for algorithms)
    int dist;           // distance (for BFS/Dijkstra); INT_MAX by default
    int disc_time;      // discovery time (for DFS)
    int endp_time;      // finish time (for DFS)
    int scc;            // strongly connected component id (unused here)
    vertex_t *pred;     // predecessor in traversals (unused here)
    edge_t *head;       // head of adjacency list (outgoing edges)
    vertex_t *next;     // next vertex in the global vertex list
};

// Public API

graph_t *graph_load(const char *filename);          // parse a file and build the graph
void      graph_attribute_init(graph_t *g);          // reset vertex attributes
vertex_t *graph_find(graph_t *g, int id);            // find a vertex by id (O(n))
void      graph_print(const graph_t *g, FILE *out);  // print adjacency lists
void      graph_dispose(graph_t *g);                 // free all memory

#endif // GRAPH_H
```

### `include/util.h`

```c
#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>

void *util_malloc(size_t size);                 // malloc with error check
void *util_calloc(size_t n, size_t size);       // calloc with error check
FILE *util_fopen(const char *fn, const char *mode); // fopen with error check

#endif // UTIL_H
```

### `src/util.c`

```c
#include "util.h"

void *util_malloc(size_t size) {
    void *p = malloc(size);
    if (!p) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

void *util_calloc(size_t n, size_t size) {
    void *p = calloc(n, size);
    if (!p) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

FILE *util_fopen(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);
    if (!fp) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return fp;
}
```

### `src/graph.c`

```c
#include <limits.h>
#include <string.h>
#include "graph.h"
#include "util.h"

#define MAX_LINE 256

// Forward-private helpers (file-local)
static vertex_t *new_node(vertex_t *g_head, int id);
static void      new_edge(graph_t *g, int i, int j, int weight);

// Build a graph from a file (see README for the format)
graph_t *graph_load(const char *filename) {
    graph_t *g;
    char line[MAX_LINE];
    int i, j, weight, dir;
    FILE *fp;

    g = (graph_t *)util_calloc(1, sizeof(graph_t));
    fp = util_fopen(filename, "r");

    if (!fgets(line, MAX_LINE, fp)) {
        fprintf(stderr, "Empty input file or read error\n");
        exit(EXIT_FAILURE);
    }

    if (sscanf(line, "%d %d", &g->nv, &dir) != 2) {
        if (sscanf(line, "%d", &g->nv) != 1) {
            fprintf(stderr, "Invalid header line. Expected: N [dir]\n");
            exit(EXIT_FAILURE);
        }
        dir = 1; // default: directed
    }

    // Create the vertex list 0..nv-1 in ascending order
    for (i = g->nv - 1; i >= 0; --i) {
        g->g = new_node(g->g, i);
    }

    // Read edges until EOF
    while (fgets(line, MAX_LINE, fp)) {
        // Skip blank lines and comments starting with '#'
        if (line[0] == '\n' || line[0] == '\r' || line[0] == '#') {
            continue;
        }

        if (sscanf(line, "%d %d %d", &i, &j, &weight) != 3) {
            if (sscanf(line, "%d %d", &i, &j) != 2) {
                // ignore malformed lines quietly
                continue;
            }
            weight = 1;
        }

        new_edge(g, i, j, weight);
        if (dir == 0) {
            new_edge(g, j, i, weight); // undirected → mirror edge
        }
    }

    fclose(fp);
    return g;
}

// Initialize per-vertex attributes to defaults
void graph_attribute_init(graph_t *g) {
    for (vertex_t *v = g->g; v != NULL; v = v->next) {
        v->color = WHITE;
        v->dist = INT_MAX;
        v->disc_time = -1;
        v->endp_time = -1;
        v->scc = -1;
        v->pred = NULL;
    }
}

// Linear search by id (sufficient for small/medium graphs)
vertex_t *graph_find(graph_t *g, int id) {
    for (vertex_t *v = g->g; v != NULL; v = v->next) {
        if (v->id == id) return v;
    }
    return NULL;
}

// Print adjacency lists in a readable form
void graph_print(const graph_t *g, FILE *out) {
    for (const vertex_t *v = g->g; v != NULL; v = v->next) {
        fprintf(out, "%d:", v->id);
        for (const edge_t *e = v->head; e != NULL; e = e->next) {
            fprintf(out, " (%d,w=%d)", e->dst->id, e->weight);
        }
        fprintf(out, "\n");
    }
}

// Free every edge and vertex, then the wrapper
default:
void graph_dispose(graph_t *g) {
    if (!g) return;
    vertex_t *v = g->g;
    while (v) {
        edge_t *e = v->head;
        while (e) {
            edge_t *enext = e->next;
            free(e);
            e = enext;
        }
        vertex_t *vnext = v->next;
        free(v);
        v = vnext;
    }
    free(g);
}

// ---------- private helpers ----------

static vertex_t *new_node(vertex_t *g_head, int id) {
    vertex_t *v = (vertex_t *)util_malloc(sizeof(vertex_t));
    v->id = id;
    v->color = WHITE;
    v->dist = INT_MAX;
    v->disc_time = -1;
    v->endp_time = -1;
    v->scc = -1;
    v->pred = NULL;
    v->head = NULL;

    // Head insertion so final order (after loop) is 0..nv-1
    v->next = g_head;
    return v;
}

static void new_edge(graph_t *g, int i, int j, int weight) {
    vertex_t *src = graph_find(g, i);
    vertex_t *dst = graph_find(g, j);
    if (!src || !dst) {
        // Ignore edges that reference non-existing vertices
        return;
    }
    edge_t *e = (edge_t *)util_malloc(sizeof(edge_t));
    e->dst = dst;
    e->weight = weight;
    e->next = src->head; // push-front into adjacency list
    src->head = e;
}
```

### `src/main.c`

```c
#include <stdio.h>
#include "graph.h"

static void usage(const char *prog) {
    fprintf(stderr, "Usage: %s <graph_file>\n", prog);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }

    const char *path = argv[1];
    graph_t *g = graph_load(path);

    // Optional: ensure attributes are in a known state
    graph_attribute_init(g);

    // Show what we read
    graph_print(g, stdout);

    graph_dispose(g);
    return 0;
}
```

### `Makefile`

```make
CC      := cc
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic -O2 -Iinclude
LDFLAGS :=

SRCS := \
    src/util.c \
    src/graph.c \
    src/main.c

OBJS := $(SRCS:.c=.o)
BIN  := graph_demo

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(BIN)
```

---

## 6) Line‑by‑line walkthrough

Below is a concise but thorough walkthrough. Keep the code open while reading this section.

### `graph.h`

* `#ifndef/#define/#endif` — header guard to prevent double inclusion.
* `#include <stdio.h>` — needed for `FILE*` in `graph_print` declaration.
* `enum { WHITE, GREY, BLACK };` — standard colors (DFS/BFS conventions).
* Forward `typedef`s let us reference struct names before defining them.
* `struct graph_s` — the **wrapper** with total vertex count `nv` and head pointer `g` to the list of all vertices.
* `struct edge_s` — a single edge with `weight`, destination pointer `dst`, and `next` pointer to the next edge from the same source.
* `struct vertex_s` — holds `id`, traversal metadata, head of adjacency list (`head`), and `next` (the next vertex in the global list).
* Prototypes: `graph_load`, `graph_attribute_init`, `graph_find`, `graph_print`, `graph_dispose`.

### `util.h` + `util.c`

* Provide **safe wrappers**:

  * `util_malloc`/`util_calloc` — abort on allocation failure.
  * `util_fopen` — abort if file can’t be opened.
* These minimize repetitive error checks in `graph.c` and keep the core logic clean.

### `graph.c`

* Includes: `<limits.h>` for `INT_MAX`, `<string.h>` (not strictly required for this demo, but common when handling strings), and our headers.
* `#define MAX_LINE 256` — buffer size for reading lines from the file.
* Forward-private helpers:

  * `new_node` — creates a vertex, initializes fields, inserts at list head.
  * `new_edge` — creates and prepends an edge to the source’s adjacency list.

**`graph_load`** (core parser):

1. Allocate `graph_t` with `util_calloc` (zero-initialized); open file with `util_fopen`.
2. Read the first line into `line` and parse `nv` and optional `dir`.
3. Create vertices in ascending order by inserting IDs `nv-1..0` at the head (so the final ordering is `0→1→…→nv-1`).
4. Loop over the rest of the lines:

   * Skip blank/comment lines.
   * Parse `i j w` or fall back to `i j` with default weight `1`.
   * Insert the edge `(i→j)`; if `dir==0`, also insert `(j→i)`.
5. Close file, return the built graph.

**`graph_attribute_init`**: reset each vertex’s traversal fields to clean defaults (useful before algorithms).

**`graph_find`**: linear scan over the vertex list; fine for small to mid-sized graphs; can be replaced with a symbol table later if needed.

**`graph_print`**: for each vertex `v`, prints its adjacency list as:

```
<id>: (neighbor,w=weight) (neighbor,w=weight) ...
```

**`graph_dispose`**: frees **every edge**, then the **vertex**, and finally the **graph wrapper**. The order matters: you must not lose pointers before freeing their lists.

**`new_node`** (private): allocate/initalize a vertex and push it to the head of the global list.

**`new_edge`** (private): find `src` and `dst` by ID, allocate an edge, and push it to `src->head`.

### `main.c`

* Simple CLI that expects exactly one argument (path to the graph file).
* Loads the graph, resets attributes (optional but nice), prints adjacency lists, then frees memory.

### `Makefile`

* `CFLAGS` has warnings enabled and uses `-Iinclude` so headers are found.
* Pattern rules build `.o` files, then link them into `graph_demo`.
* `make clean` deletes objects and the binary.

---

## 7) Try it quickly

1. Create `sample_graph.txt`:

```
5 1
0 1 3
0 2 1
1 3 2
2 3 5
3 4 4
```

2. Build & run:

```bash
make
./graph_demo sample_graph.txt
```

3. Expected output (order may differ if you change insertion policy):

```
0: (2,w=1) (1,w=3)
1: (3,w=2)
2: (3,w=5)
3: (4,w=4)
4:
```

---

## 8) Customization tips

* **Undirected input:** put `0` after `N` on the first line; the loader inserts mirrored edges.
* **Default weights:** omit the third number on an edge line to get `weight=1`.
* **Skipping noise:** lines starting with `#` or empty lines are ignored.
* **Scaling up:** replace `graph_find` with a faster structure (e.g., array index or hash table) if vertex IDs are sparse or very large.

---

## 9) What’s next?

* Add algorithms (BFS/DFS/Toposort/Dijkstra/Kosaraju) using the fields already present (`color`, `dist`, `pred`, `disc_time`, `endp_time`, `scc`).
* Add a writer to output the graph in the same format (for round-tripping).
* Add unit tests.

Happy hacking! 🎯
