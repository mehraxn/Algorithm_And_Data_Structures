#include <stdio.h>
#include <stdlib.h>

// Define constants for colors during graph traversal (used for DFS or BFS)
#define MAX_LINE 100
enum {WHITE, GREY, BLACK};  // WHITE: unvisited, GREY: visited but not fully explored, BLACK: fully explored

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
