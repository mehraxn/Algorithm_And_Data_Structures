#include <stdio.h>
#include <stdlib.h>

// Constants for vertex colors
#define WHITE 0 // Unvisited
#define GRAY 1  // Visiting
#define BLACK 2 // Fully visited

// Structure for an edge in the adjacency list
typedef struct Edge {
    struct Vertex *dst; // Destination vertex
    struct Edge *next;  // Pointer to the next edge
} edge_t;

// Structure for a vertex
typedef struct Vertex {
    int id;             // Unique identifier for the vertex
    int color;          // Color of the vertex (WHITE, GRAY, BLACK)
    int dtime;          // Discovery time
    int endtime;        // Finish time
    struct Vertex *pred; // Predecessor vertex
    struct Edge *head;  // Head of the adjacency list (edges)
    struct Vertex *next; // Pointer to the next vertex
} vertex_t;

// Structure for the graph
typedef struct Graph {
    vertex_t *g; // Pointer to the list of vertices
} graph_t;

// Global time variable for DFS
int time;

// Function prototypes
void DFS(graph_t *G);
void DFS_r(graph_t *G, vertex_t *u);

// Depth-First Search (DFS) function
void DFS(graph_t *G) {
    vertex_t *v = G->g;
    time = 0;

    // Initialize all vertices in the graph
    while (v != NULL) {
        v->color = WHITE;
        v->dtime = -1;    // Discovery time set to -1 (uninitialized)
        v->endtime = -1;  // Finish time set to -1 (uninitialized)
        v->pred = NULL;   // No predecessor at the beginning
        v = v->next;
    }

    // Perform DFS for each unvisited vertex
    v = G->g;
    while (v != NULL) {
        if (v->color == WHITE) {
            DFS_r(G, v);
        }
        v = v->next;
    }
}

// Recursive DFS helper function
void DFS_r(graph_t *G, vertex_t *u) {
    edge_t *e = u->head;

    time++;
    u->dtime = time; // Set discovery time
    u->color = GRAY; // Mark the vertex as being visited

    // Traverse all adjacent vertices
    while (e != NULL) {
        vertex_t *v = e->dst; // Get the destination vertex
        if (v->color == WHITE) { // If the vertex is unvisited
            v->pred = u; // Set predecessor
            DFS_r(G, v); // Recursively visit it
        }
        e = e->next; // Move to the next edge
    }

    u->color = BLACK; // Mark the vertex as fully visited
    time++;
    u->endtime = time; // Set finish time
}

// Main function (example usage)
int main() {
    // Example graph creation (replace with actual graph loading logic)
    graph_t *G = (graph_t *)malloc(sizeof(graph_t));
    G->g = NULL; // Initialize an empty graph (for simplicity)

    // Add your graph building logic here

    // Run DFS
    DFS(G);

    // Free memory and clean up
    // Freeing the graph structure would go here (not implemented for simplicity)
    free(G);

    return 0;
}

/*
===========================================
Explanation of the Functions in the Code
===========================================
1. **DFS(graph_t *G):**
   - This is the main function for Depth-First Search.
   - Initializes all vertices in the graph by setting their color to `WHITE` (unvisited), discovery and finish times to `-1`, and their predecessors to `NULL`.
   - Iterates through all vertices in the graph. If a vertex is unvisited (`WHITE`), it starts a recursive DFS using `DFS_r`.

2. **DFS_r(graph_t *G, vertex_t *u):**
   - A recursive helper function that performs the actual depth-first traversal.
   - Marks the vertex `u` as being visited (`GRAY`) and assigns a discovery time.
   - Recursively visits all adjacent vertices that are unvisited (`WHITE`), setting their predecessor to the current vertex.
   - Once all adjacent vertices are visited, marks the vertex as fully visited (`BLACK`) and assigns a finish time.

3. **Main Function:**
   - Initializes an example graph structure and runs the DFS algorithm.
   - This serves as a placeholder; in real use, you would implement graph building/loading logic before calling `DFS`.

4. **Graph Data Structures:**
   - `vertex_t`: Represents a vertex in the graph with fields for ID, color, discovery/finish times, a predecessor pointer, and adjacency list.
   - `edge_t`: Represents an edge in the adjacency list, with a pointer to the destination vertex.
   - `graph_t`: Encapsulates the graph as a collection of vertices.

===========================================
How the Code Works
===========================================
- The `DFS` function iterates through all vertices and ensures all components of the graph are traversed.
- `DFS_r` performs the actual depth-first traversal, exploring as far as possible along each branch before backtracking.
- The graph is represented using an adjacency list to efficiently store edges and vertices.
- This implementation uses discovery (`dtime`) and finish (`endtime`) times to capture the time order of traversal, useful for many graph-related problems.
*/
