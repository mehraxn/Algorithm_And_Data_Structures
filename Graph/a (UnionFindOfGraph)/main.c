#include <stdio.h>   // Standard I/O library for input/output functions

#define MAX_LINE 100   // Maximum line length (possibly for file input)

// Enumeration for vertex colors (used in graph traversal algorithms like BFS/DFS)
enum {WHITE, GREY, BLACK};
// WHITE: vertex has not been visited yet
// GREY: vertex is discovered but not fully explored
// BLACK: vertex and all its adjacent vertices have been fully explored

// Forward declarations of structures
typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;

/*
 * Structure representing a graph
 */
struct graph_s {
    vertex_t *g;   // Pointer to an array of vertices (the graph's vertex list)
    int nv;        // Number of vertices in the graph
};

/*
 * Structure representing a single vertex in the graph
 */
struct vertex_s {
    int id;           // Unique identifier for the vertex
    int color;        // Traversal state (WHITE, GREY, BLACK)
    int dist;         // Distance from source (used in BFS), or depth level
    int disc_time;    // Discovery time (used in DFS for timestamps)
    int endp_time;    // Finish time (DFS completion timestamp)
    int pred;         // Predecessor vertex in traversal (for paths or union-find)
    int scc;          // Strongly Connected Component ID (for algorithms like Kosaraju/Tarjan)
    int *rowAdj;      // Pointer to adjacency matrix row representing edges
                      // Example: rowAdj[i] = 1 means there is an edge to vertex i
};

/*
 * Union-Find "find" function (without path compression)
 *
 * This function finds the root representative of a given vertex in a disjoint-set structure.
 *
 * Parameters:
 *   g -> pointer to the graph
 *   k -> index of the vertex we want to find the representative for
 *
 * Returns:
 *   The root index (representative) of the set containing vertex k
 */
static int union_find_find(graph_t *g, int k) {
    int i = k;   // Start from the given vertex index
    // Traverse predecessors until the root is found
    // Root is defined as the vertex whose predecessor is itself
    while (i != g->g[i].pred) {
        i = g->g[i].pred;  // Move up the predecessor chain
    }
    return i;  // Return the root representative
}
