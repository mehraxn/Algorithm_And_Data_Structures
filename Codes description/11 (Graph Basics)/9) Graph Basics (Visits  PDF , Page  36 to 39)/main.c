#include <stdio.h>
#include <stdlib.h>

#define WHITE 0 // Unvisited
#define GREY 1  // Visiting
#define BLACK 2 // Fully visited

// Structure for an edge in the adjacency list
typedef struct Edge {
    struct Vertex *dst; // Destination vertex
    struct Edge *next;  // Pointer to the next edge
} edge_t;

// Structure for a vertex
typedef struct Vertex {
    int id;             // Unique identifier for the vertex
    int color;          // Color of the vertex (WHITE, GREY, BLACK)
    int disc_time;      // Discovery time
    int endp_time;      // Finish time
    struct Vertex *pred; // Predecessor vertex
    struct Edge *head;  // Head of the adjacency list (edges)
    struct Vertex *next; // Pointer to the next vertex
} vertex_t;

// Structure for the graph
typedef struct Graph {
    vertex_t *g; // Pointer to the list of vertices
} graph_t;

// Function prototypes
void graph_attribute_init(graph_t *g);
void graph_dfs(graph_t *g, vertex_t *n);
int graph_dfs_r(graph_t *g, vertex_t *n, int currTime);
void graph_dispose(graph_t *g);

// Function to initialize graph attributes
void graph_attribute_init(graph_t *g) {
    vertex_t *n = g->g;
    while (n != NULL) {
        n->color = WHITE;
        n->disc_time = -1;
        n->endp_time = -1;
        n->pred = NULL;
        n = n->next;
    }
}

// Depth-First Search (DFS) function
void graph_dfs(graph_t *g, vertex_t *n) {
    int currTime = 0;
    vertex_t *t1, *t2;

    printf("List of edges:\n");
    currTime = graph_dfs_r(g, n, currTime);

    // Handle disconnected components
    for (t1 = g->g; t1 != NULL; t1 = t1->next) {
        if (t1->color == WHITE) {
            currTime = graph_dfs_r(g, t1, currTime);
        }
    }

    printf("List of vertices:\n");
    for (t1 = g->g; t1 != NULL; t1 = t1->next) {
        t2 = t1->pred;
        printf("%2d: %2d/%2d (%d)\n",
               t1->id, t1->disc_time, t1->endp_time,
               (t2 != NULL) ? t2->id : -1);
    }
}

// Recursive helper for DFS
int graph_dfs_r(graph_t *g, vertex_t *n, int currTime) {
    edge_t *e;
    vertex_t *t;

    n->color = GREY;
    n->disc_time = ++currTime;
    e = n->head;

    while (e != NULL) {
        t = e->dst;

        switch (t->color) {
            case WHITE: // Tree edge
                printf("%d -> %d : T\n", n->id, t->id);
                t->pred = n; // Set predecessor
                currTime = graph_dfs_r(g, t, currTime);
                break;

            case GREY: // Back edge
                printf("%d -> %d : B\n", n->id, t->id);
                break;

            case BLACK: // Forward or cross edge
                if (n->disc_time < t->disc_time) {
                    printf("%d -> %d : F\n", n->id, t->id);
                } else {
                    printf("%d -> %d : C\n", n->id, t->id);
                }
                break;
        }

        e = e->next;
    }

    n->color = BLACK;
    n->endp_time = ++currTime;
    return currTime;
}

// Function to dispose of the graph
void graph_dispose(graph_t *g) {
    vertex_t *n = g->g;
    while (n != NULL) {
        edge_t *e = n->head;
        while (e != NULL) {
            edge_t *temp_e = e;
            e = e->next;
            free(temp_e);
        }
        vertex_t *temp_n = n;
        n = n->next;
        free(temp_n);
    }
    free(g);
}

// Main function (example usage)
int main() {
    // Example graph setup
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->g = NULL; // Initialize empty graph (add your setup here)

    // Example source vertex (replace with actual graph creation logic)
    vertex_t *src = NULL;

    // Initialize graph attributes
    graph_attribute_init(g);

    // Run DFS
    if (src != NULL) {
        graph_dfs(g, src);
    } else {
        printf("No source vertex provided.\n");
    }

    // Clean up
    graph_dispose(g);
    return 0;
}

/*
=====================================================
Explanation of Functions in the Code
=====================================================
1. **graph_attribute_init(graph_t *g):**
   - Initializes all vertices in the graph to prepare for DFS.
   - Sets all vertex colors to WHITE, discovery/finish times to -1, and predecessors to NULL.

2. **graph_dfs(graph_t *g, vertex_t *n):**
   - Performs Depth-First Search starting from a given vertex `n`.
   - Handles disconnected components by checking for WHITE vertices in the graph.
   - Prints lists of edges (classified as tree, back, forward, or cross edges) and vertices with their discovery and finish times.

3. **graph_dfs_r(graph_t *g, vertex_t *n, int currTime):**
   - Recursive helper function for `graph_dfs`.
   - Traverses edges and classifies them as tree (T), back (B), forward (F), or cross (C).
   - Updates discovery and finish times for each vertex.

4. **graph_dispose(graph_t *g):**
   - Frees all memory associated with the graph, including vertices and edges.

=====================================================
How the Code Works
=====================================================
- The `graph_dfs` function initializes and starts DFS on the given graph.
- Edges are classified during traversal based on the state of their destination vertex:
  - Tree (T): Destination is unvisited (WHITE).
  - Back (B): Destination is currently being visited (GREY).
  - Forward (F): Destination is fully visited (BLACK) with a higher discovery time.
  - Cross (C): Destination is fully visited with a lower discovery time.
- Discovery and finish times help track the order of traversal, useful for advanced graph algorithms.
*/
