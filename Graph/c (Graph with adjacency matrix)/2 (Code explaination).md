# README: Full BFS Analysis and Code Explanation

## Complete Code

```
#include <stdio.h>    // Includes standard I/O functions (printf, fopen, etc.)
#include <stdlib.h>   // Includes standard library functions (malloc, calloc, free, exit, etc.)
#include <limits.h>   // Includes INT_MAX (used for initializing distances)

// Define a maximum line length for reading from the file
#define MAX_LINE 100

// Define colors for graph algorithms (e.g., BFS/DFS)
enum { WHITE, GREY, BLACK };
// WHITE = unvisited, GREY = visiting, BLACK = visited

/*
 * Structure representing a single vertex in the graph.
 */

typedef struct vertex_s vertex_t;
typedef struct graph_s  graph_t;

struct vertex_s {
    int id;      // The integer identifier of the vertex
    int color;   // The color of the vertex (WHITE, GREY, BLACK)
    int dist;    // Distance value (used in BFS/DFS or shortest path)
    int pred;    // Predecessor vertex index
    int dtime;   // Discovery time (for DFS)
    int ftime;   // Finishing time (for DFS)
    int scc;     // Strongly connected component identifier (if needed)
};

/*
 * Structure representing the entire graph.
 * It contains:
 *   - An array of vertices (v)
 *   - A 2D adjacency matrix (rowAdj)
 *   - The number of vertices (nv)
 *   - The number of edges (ne)
 *   - A flag indicating if the graph is directed (directed)
 */
struct graph_s {
    vertex_t *v;     // Array of vertices
    int **rowAdj;    // 2D adjacency matrix for edges/weights
    int nv;          // Number of vertices
    int ne;          // Number of edges
    int directed;    // 1 if directed, 0 if undirected
};

/*************************************************************
 * Function: allocate_matrix
 * Purpose:
 *   Allocates a 2D matrix of size n x n (each element is int).
 *   Returns a pointer to the allocated matrix.
 *************************************************************/
int **allocate_matrix(int n) {
    int **matrix = (int **)calloc(n, sizeof(int *)); // Allocate an array of int* for n rows
    if (!matrix) {
        fprintf(stderr, "Error: could not allocate adjacency matrix.\n");
        exit(EXIT_FAILURE);
    }

    // For each row, allocate an array of n integers
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));   // Allocate n ints (initialized to 0)
        if (!matrix[i]) {
            fprintf(stderr, "Error: could not allocate adjacency matrix row.\n");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

/*************************************************************
 * Function: free_matrix
 * Purpose:
 *   Frees the memory used by a 2D integer matrix of size n x n.
 *************************************************************/
void free_matrix(int **matrix, int n) {
    if (!matrix) return;

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/*************************************************************
 * Function: graph_attribute_init
 * Purpose:
 *   Initializes the attributes of each vertex in the graph
 *   to default values (id, color, distance, etc.).
 *************************************************************/
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

/*************************************************************
 * Function: graph_load
 * Purpose:
 *   Reads a graph definition from a file. The file format is:
 *       nv directed_flag
 *       i j weight
 *       i j weight
 *       ...
 *   It allocates and returns a pointer to a new graph_t object
 *   containing the adjacency matrix and vertex array.
 *************************************************************/
graph_t *graph_load(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file '%s'.\n", filename);
        return NULL;
    }

    graph_t *g = (graph_t *)calloc(1, sizeof(graph_t));
    if (!g) {
        fprintf(stderr, "Error: cannot allocate graph.\n");
        fclose(fp);
        return NULL;
    }

    char line[MAX_LINE];

    if (!fgets(line, MAX_LINE, fp)) {
        fprintf(stderr, "Error: file is empty or invalid.\n");
        free(g);
        fclose(fp);
        return NULL;
    }

    if (sscanf(line, "%d %d", &g->nv, &g->directed) != 2) {
        fprintf(stderr, "Error: invalid first line (should be 'nv directed_flag').\n");
        free(g);
        fclose(fp);
        return NULL;
    }

    g->v = (vertex_t *)calloc(g->nv, sizeof(vertex_t));
    if (!g->v) {
        fprintf(stderr, "Error: cannot allocate vertex array.\n");
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
                fprintf(stderr, "Warning: invalid edge (%d %d %d) ignored.\n", i, j, w);
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

/*************************************************************
 * Function: graph_dispose
 * Purpose:
 *   Frees all the memory associated with the graph, including
 *   the adjacency matrix and the vertex array.
 *************************************************************/
void graph_dispose(graph_t *g) {
    if (!g) return;
    free_matrix(g->rowAdj, g->nv);
    free(g->v);
    free(g);
}

/*************************************************************
 * Function: graph_print_matrix
 * Purpose:
 *   Prints the adjacency matrix of the graph in a formatted
 *   manner for debugging or visualization.
 *************************************************************/
void graph_print_matrix(const graph_t *g) {
    printf("Adjacency Matrix (%d vertices):\n", g->nv);
    for (int i = 0; i < g->nv; i++) {
        for (int j = 0; j < g->nv; j++) {
            printf("%4d ", g->rowAdj[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    const char *filename = "graph_data.txt";

    graph_t *myGraph = graph_load(filename);
    if (!myGraph) {
        fprintf(stderr, "Graph loading failed.\n");
        return EXIT_FAILURE;
    }

    printf("Graph loaded from '%s'\n", filename);
    printf("Number of vertices: %d\n", myGraph->nv);
    printf("Directed: %s\n", myGraph->directed ? "Yes" : "No");
    printf("Number of edges read: %d\n", myGraph->ne);

    graph_print_matrix(myGraph);

    graph_dispose(myGraph);

    return 0;
}
```

---

# BFS Explanation and Step-by-Step Tables

Below is one way to "update" the vertex‐attribute table after **each** of the eleven edge insertions, ultimately ending with a final table once the graph is fully built. The code you showed **initializes** each vertex’s attributes (`color=WHITE`, `dist=∞`, `pred=−1`, `dtime=−1`, `ftime=−1`, `scc=−1`) but does **not** actually run a BFS/DFS to update them.

However, since your table has columns (`color`, `dist`, `pred`, `dtime`, `ftime`, `scc`) that are typically maintained by a Breadth‐First Search (BFS) or Depth‐First Search (DFS), the most common interpretation is:

1. **After you insert each edge**, run BFS (or DFS) from a chosen source (often 0) to see how `color`, `dist`, `pred` (and possibly `dtime`, `ftime`) change.
2. Record the table of vertex attributes after each insertion.

Below, we demonstrate **BFS from vertex 0** after each edge is added. (DFS would also work, but BFS is simpler to illustrate for the `dist` and `pred` fields. Note that `dtime`, `ftime`, `scc` remain unused in a plain BFS, so they stay at −1.)

---
## The Graph Edges

We start with a graph of 10 vertices (ID 0 through 9), directed (the line `10 1`), and then read these 11 edges one at a time:

```
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

We will show how a BFS from vertex **0** updates `(color, dist, pred)` after each insertion. **Remember** that in a standard BFS, "weights" are not used for distance—every edge just counts as one hop.

---
## Conventions for BFS

- **color**:
  - WHITE = unvisited
  - GRAY = discovered but not fully processed
  - BLACK = finished

- **dist[u]**: The number of edges (hops) from the source (here 0) to reach vertex `u`.
- **pred[u]**: The immediate predecessor of `u` in the BFS tree (or -1 if none).
- **dtime, ftime, scc**: Not used by a basic BFS, so these remain −1.

At the **end** of BFS (once the queue is empty), all vertices reached are typically BLACK.

---
## Step-by-Step BFS Updates

### After Edge #1: Insert `0 -> 1`

Edges so far:
```
0 -> 1
```

#### BFS(0) Analysis:
1. Initialize all vertices: color=WHITE, dist=∞, pred=–1.
2. Start at 0:
   - color(0)=GRAY, dist(0)=0, pred(0)=–1
   - Enqueue(0)
3. Dequeue(0):
   - Look at adjacency: 0 -> 1
   - 1 was WHITE ⇒ color(1)=GRAY, dist(1)=1, pred(1)=0, Enqueue(1)
   - color(0)=BLACK
4. Dequeue(1):
   - Currently no further edges out of 1 (the next edges come in later).
   - color(1)=BLACK
5. Queue is empty, BFS ends.

#### Resulting table (only 0 and 1 got discovered; everything else is WHITE, ∞, –1):

| id | color | dist  | pred | dtime | ftime | scc |
|----|-------|-------|------|-------|-------|-----|
| 0  | BLACK | 0     | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1     | 0    | -1    | -1    | -1  |
| 2  | WHITE | ∞     | -1   | -1    | -1    | -1  |
| 3  | WHITE | ∞     | -1   | -1    | -1    | -1  |
| 4  | WHITE | ∞     | -1   | -1    | -1    | -1  |
| 5  | WHITE | ∞     | -1   | -1    | -1    | -1  |
| 6  | WHITE | ∞     | -1   | -1    | -1    | -1  |
| 7  | WHITE | ∞     | -1   | -1    | -1    | -1  |
| 8  | WHITE | ∞     | -1   | -1    | -1    | -1  |
| 9  | WHITE | ∞     | -1   | -1    | -1    | -1  |

---
### After Edge #2: Insert `0 -> 2`

Edges so far:
```
0 -> 1
0 -> 2
```

#### BFS(0) again:
- color(0)=GRAY, dist(0)=0, Enqueue(0)
- Dequeue(0): adjacency => 1 and 2
  - 1 is WHITE => color(1)=GRAY, dist(1)=1, pred(1)=0
  - 2 is WHITE => color(2)=GRAY, dist(2)=1, pred(2)=0
  - color(0)=BLACK
- Dequeue(1): no new edges out of 1 yet => color(1)=BLACK
- Dequeue(2): no new edges out of 2 yet => color(2)=BLACK
- BFS ends.

#### Updated table:

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 4  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 5  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 6  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 7  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 8  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 9  | WHITE | ∞    | -1   | -1    | -1    | -1  |

---
### After Edge #3: Insert `1 -> 3`

Edges so far:
```
0 -> 1
0 -> 2
1 -> 3
```

#### BFS(0):
- 0: dist(0)=0, GRAY;
  - adjacency => 1 (WHITE), 2 (WHITE) ⇒ dist(1)=1, dist(2)=1
- 1: adjacency => 3 (WHITE) ⇒ dist(3)=2, pred(3)=1
- 2: no new adjacency (besides #4 coming next)
- 3: no new edges out of 3 yet
- Final:

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 5  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 6  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 7  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 8  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 9  | WHITE | ∞    | -1   | -1    | -1    | -1  |

---
### After Edge #4: Insert `2 -> 3`

Edges so far:
```
0 -> 1
0 -> 2
1 -> 3
2 -> 3
```

If you run BFS(0) again, 3 will still get discovered first via **1 -> 3**, so the final BFS tree is unchanged (it does not reduce the distance to 3). Hence the table remains:

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 5  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 6  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 7  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 8  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 9  | WHITE | ∞    | -1   | -1    | -1    | -1  |

---
### After Edge #5: Insert `2 -> 4`

Edges so far:
```
0 -> 1
0 -> 2
1 -> 3
2 -> 3
2 -> 4
```

#### BFS(0):
- 0 discovers 1, 2.
- 1 discovers 3.
- 2 discovers 3 (already GRAY) and **4** (which is WHITE).
  - So dist(4)=2, pred(4)=2.
- 3 has no out-edges yet (the next one is #6).
- 4 no out-edges yet.

Result:

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | BLACK | 2    | 2    | -1    | -1    | -1  |
| 5  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 6  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 7  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 8  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 9  | WHITE | ∞    | -1   | -1    | -1    | -1  |

---
### After Edge #6: Insert `3 -> 9`

Edges so far:
```
0 -> 1
0 -> 2
1 -> 3
2 -> 3
2 -> 4
3 -> 9
```

#### BFS(0):
- 0 -> 1,2
- 1 -> 3
- 2 -> 3,4
- 3 -> 9 ⇒ dist(9)=3, pred(9)=3
- 4 no out-edges yet
- 9 no out-edges yet

Result:

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | BLACK | 2    | 2    | -1    | -1    | -1  |
| 5  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 6  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 7  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 8  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 9  | BLACK | 3    | 3    | -1    | -1    | -1  |

---
### After Edge #7: Insert `4 -> 5`

Edges so far:
```
0 -> 1
0 -> 2
1 -> 3
2 -> 3
2 -> 4
3 -> 9
4 -> 5
```

#### BFS(0):
- 0 -> (1,2)
- 1 -> (3)
- 2 -> (3,4)
- 3 -> (9)
- 4 -> (5) ⇒ dist(5)=3, pred(5)=4
- 5 -> (none yet)
- 9 -> (none)

Result:

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | BLACK | 2    | 2    | -1    | -1    | -1  |
| 5  | BLACK | 3    | 4    | -1    | -1    | -1  |
| 6  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 7  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 8  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 9  | BLACK | 3    | 3    | -1    | -1    | -1  |

---
### After Edge #8: Insert `5 -> 6`

Edges so far:
```
0 -> 1
0 -> 2
1 -> 3
2 -> 3
2 -> 4
3 -> 9
4 -> 5
5 -> 6
```

#### BFS(0):
- 0 -> 1,2
- 1 -> 3
- 2 -> 3,4
- 3 -> 9
- 4 -> 5
- 5 -> 6 ⇒ dist(6)=4, pred(6)=5
- 6 -> (none yet)
- 9 -> (none)

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | BLACK | 2    | 2    | -1    | -1    | -1  |
| 5  | BLACK | 3    | 4    | -1    | -1    | -1  |
| 6  | BLACK | 4    | 5    | -1    | -1    | -1  |
| 7  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 8  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 9  | BLACK | 3    | 3    | -1    | -1    | -1  |

---
### After Edge #9: Insert `6 -> 7`

Edges so far:
```
0 -> 1
0 -> 2
1 -> 3
2 -> 3
2 -> 4
3 -> 9
4 -> 5
5 -> 6
6 -> 7
```

#### BFS(0):
- Same discovery until we reach 6
- 6 -> 7 ⇒ dist(7)=5, pred(7)=6

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | BLACK | 2    | 2    | -1    | -1    | -1  |
| 5  | BLACK | 3    | 4    | -1    | -1    | -1  |
| 6  | BLACK | 4    | 5    | -1    | -1    | -1  |
| 7  | BLACK | 5    | 6    | -1    | -1    | -1  |
| 8  | WHITE | ∞    | -1   | -1    | -1    | -1  |
| 9  | BLACK | 3    | 3    | -1    | -1    | -1  |

---
### After Edge #10: Insert `7 -> 8`

Edges so far:
```
0 -> 1
0 -> 2
1 -> 3
2 -> 3
2 -> 4
3 -> 9
4 -> 5
5 -> 6
6 -> 7
7 -> 8
```

#### BFS(0) again:
- Eventually 7 -> 8 ⇒ dist(8)=6, pred(8)=7

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | BLACK | 2    | 2    | -1    | -1    | -1  |
| 5  | BLACK | 3    | 4    | -1    | -1    | -1  |
| 6  | BLACK | 4    | 5    | -1    | -1    | -1  |
| 7  | BLACK | 5    | 6    | -1    | -1    | -1  |
| 8  | BLACK | 6    | 7    | -1    | -1    | -1  |
| 9  | BLACK | 3    | 3    | -1    | -1    | -1  |

---
### After Edge #11: Insert `8 -> 9`

Edges so far (the full graph):
```
0 -> 1 (3)
0 -> 2 (5)
1 -> 3 (2)
2 -> 3 (4)
2 -> 4 (6)
3 -> 9 (10)
4 -> 5 (2)
5 -> 6 (1)
6 -> 7 (4)
7 -> 8 (5)
8 -> 9 (2)
```

#### BFS(0) one final time:
- The presence of 8->9 does not lower the distance to 9, because we already discovered 9 at distance=3 (via 3). If we visited 9 from 8, that would be distance(8)+1=7, which is worse. So dist(9) remains 3, with pred(9)=3.

Hence the final BFS table is:

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | BLACK | 2    | 2    | -1    | -1    | -1  |
| 5  | BLACK | 3    | 4    | -1    | -1    | -1  |
| 6  | BLACK | 4    | 5    | -1    | -1    | -1  |
| 7  | BLACK | 5    | 6    | -1    | -1    | -1  |
| 8  | BLACK | 6    | 7    | -1    | -1    | -1  |
| 9  | BLACK | 3    | 3    | -1    | -1    | -1  |

---
## Why dtime, ftime, and scc Are Not Changed

**`dtime`, `ftime`, and `scc`** are fields commonly used in depth‐first search (DFS) or strongly connected component (SCC) algorithms, **not** in plain BFS. Since we only show BFS (or simply load the graph without running DFS), there is never a point where these three fields get updated. Hence, they remain at their initial values of −1.

### Purpose of Each Field
- **`dtime` (Discovery Time):**
  In a DFS, each vertex gets a "discovery time" the first time it is encountered. This is often stored in a global counter that increments each time a vertex is discovered.
- **`ftime` (Finishing Time):**
  Also in DFS, each vertex gets a "finishing time" when DFS finishes processing all of its adjacent vertices. Another global counter value assigned at the time the vertex is fully explored.
- **`scc` (Strongly Connected Component):**
  Used in algorithms like **Tarjan’s** or **Kosaraju’s** to label each vertex with the ID/index of the SCC it belongs to.

Because BFS does not track discovery/finish times or SCCs, these fields remain -1.

---
## Final Comments

1. **Why the table stays all WHITE/∞ if you do nothing but "load" the graph:**
   The C code we have never calls BFS or DFS. It only initializes attributes (`color=WHITE`, etc.) and loads edges. So if you rely solely on that code, all vertices would remain `color=WHITE, dist=INT_MAX, pred=-1, dtime=-1, ftime=-1, scc=-1` for every vertex, even after reading all edges.
2. **How to "see" the updates:**
   To get a table like the one above, you must actually run BFS (or DFS) after each insertion (or at least once at the end). That is where the updates for `color, dist, pred`, etc. come from.
3. **Weights in BFS:**
   Traditional BFS treats all edges as "weight=1." The numeric weights (3,5,2,4,…) you gave do not affect BFS’s `dist`. If you needed weighted shortest paths, you’d use e.g. **Dijkstra’s algorithm**, and that would reflect actual edge weights in `dist`.

---
# Final BFS Table Once the Graph Is Complete

If all you want is the **final** snapshot once the graph is complete (and we run BFS from 0), here it is again:

| id | color | dist | pred | dtime | ftime | scc |
|----|-------|------|------|-------|-------|-----|
| 0  | BLACK | 0    | -1   | -1    | -1    | -1  |
| 1  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 2  | BLACK | 1    | 0    | -1    | -1    | -1  |
| 3  | BLACK | 2    | 1    | -1    | -1    | -1  |
| 4  | BLACK | 2    | 2    | -1    | -1    | -1  |
| 5  | BLACK | 3    | 4    | -1    | -1    | -1  |
| 6  | BLACK | 4    | 5    | -1    | -1    | -1  |
| 7  | BLACK | 5    | 6    | -1    | -1    | -1  |
| 8  | BLACK | 6    | 7    | -1    | -1    | -1  |
| 9  | BLACK | 3    | 3    | -1    | -1    | -1  |

All vertices end as **BLACK**, showing they were visited; the `dist` and `pred` fields form the BFS tree rooted at 0.


**End of Complete Explanation**

