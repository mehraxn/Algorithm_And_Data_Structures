#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define constants
#define MAX_LINE 100
enum {WHITE, GREY, BLACK};  // Colors used for graph traversal (WHITE: unvisited, GREY: visited but not fully explored, BLACK: fully explored)

// Forward declarations of structures
typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;

// Structure representing a graph
struct graph_s {
    vertex_t *g;   // Array of vertices
    int nv;        // Number of vertices in the graph
};

// Structure representing a vertex (node in the graph)
struct vertex_s {
    int id;            // Unique identifier for each vertex
    int color;         // Color used for traversal (WHITE, GREY, BLACK)
    int dist;          // Distance from the source in shortest path algorithms (e.g., BFS)
    int disc_time;     // Discovery time for DFS (used in depth-first search)
    int endp_time;     // Finish time for DFS (used in depth-first search)
    int pred;          // Predecessor vertex in shortest path algorithms (e.g., BFS)
    int scc;           // Strongly connected component index (used in SCC algorithms)
    int *rowAdj;       // Array of adjacency list (neighbors of the vertex)
};

// Function prototypes (basic graph operations)
void graph_attribute_init(graph_t *g);
int graph_find(graph_t *g, int id);
void graph_dispose(graph_t *g);

// Function to initialize attributes for all vertices in the graph
void graph_attribute_init(graph_t *g) {
    int i;
    for (i = 0; i < g->nv; i++) {
        g->g[i].color = WHITE;         // Set color to WHITE (unvisited)
        g->g[i].dist = INT_MAX;        // Set distance to infinity (unreachable initially)
        g->g[i].disc_time = -1;        // Set discovery time to -1 (undefined)
        g->g[i].endp_time = -1;        // Set end time to -1 (undefined)
        g->g[i].pred = -1;             // Set predecessor to -1 (no predecessor initially)
        g->g[i].scc = -1;              // Set SCC index to -1 (no SCC initially)
    }
    return;
}

// Function to find a vertex by its ID
int graph_find(graph_t *g, int id) {
    int i;
    // Search through the vertices to find the one with the matching ID
    for (i = 0; i < g->nv; i++) {
        if (g->g[i].id == id) {
            return i;  // Return the index of the vertex if found
        }
    }
    return -1;  // Return -1 if the vertex with the given ID is not found
}

// Function to free the memory allocated for the graph
void graph_dispose(graph_t *g) {
    int i;
    // Free the memory allocated for each vertex's adjacency list
    for (i = 0; i < g->nv; i++) {
        free(g->g[i].rowAdj);
    }

    // Free the memory for the array of vertices
    free(g->g);

    // Free the memory for the graph structure itself
    free(g);

    return;
}

