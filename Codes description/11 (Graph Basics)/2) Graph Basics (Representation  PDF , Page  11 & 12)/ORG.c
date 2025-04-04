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
graph_t* graph_load(char *filename);

// Function to load a graph from a file
graph_t *graph_load(char *filename) {
    graph_t *g;
    char line[MAX_LINE];
    int i, j, weight, dir;
    FILE *fp;

    // Allocate memory for the graph structure
    g = (graph_t *) malloc(sizeof(graph_t));

    // Open the file for reading
    fp = fopen(filename, "r");

    // Read the first line for number of vertices and direction (if present)
    fgets(line, MAX_LINE, fp);
    if (sscanf(line, "%d%d", &g->nv, &dir) != 2) {
        sscanf(line, "%d", &g->nv);
        dir = 1;  // Assume directed graph if direction is not specified
    }

    // Allocate memory for vertices and initialize their values
    g->g = (vertex_t *) malloc(g->nv * sizeof(vertex_t));
    for (i = 0; i < g->nv; i++) {
        g->g[i].id = i;  // Set vertex id
        g->g[i].color = WHITE;  // Initially, all vertices are unvisited (WHITE)
        g->g[i].dist = INT_MAX;  // Set distance to infinity initially
        g->g[i].pred = g->g[i].scc = -1;  // No predecessor or SCC initially
        g->g[i].disc_time = g->g[i].endp_time = -1;  // No discovery or finishing time initially
        g->g[i].rowAdj = (int *) calloc(g->nv, sizeof(int));  // Allocate memory for adjacency list (initially empty)
    }

    // Read the remaining lines to build the adjacency list (edges)
    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (sscanf(line, "%d%d%d", &i, &j, &weight) != 3) {
            sscanf(line, "%d%d", &i, &j);
            weight = 1;  // Default weight of 1 if not provided
        }

        // Add the edge i -> j with the specified weight
        g->g[i].rowAdj[j] = weight;

        // If the graph is undirected, also add the reverse edge j -> i
        if (dir == 0) {
            g->g[j].rowAdj[i] = weight;
        }
    }

    // Close the file
    fclose(fp);

    // Return the created graph
    return g;
}
