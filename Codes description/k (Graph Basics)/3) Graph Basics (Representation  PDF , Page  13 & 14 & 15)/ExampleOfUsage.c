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

// Main function for testing
int main() {
    // Assuming graph creation, population, and initialization are done earlier
    graph_t *graph; // Placeholder for the actual graph loading code

    // Initialize the attributes of the graph (set color, dist, etc.)
    graph_attribute_init(graph);

    // Find a vertex with a specific ID in the graph
    int index = graph_find(graph, 2); // Searching for vertex with ID 2
    if (index != -1) {
        printf("Vertex found at index: %d\n", index);
    } else {
        printf("Vertex not found.\n");
    }

    // Dispose of the graph's resources (free memory)
    graph_dispose(graph);

    return 0;
}

/*
Explanation of Functions in the Code:

1. **graph_attribute_init**:
    - This function initializes the attributes of all vertices in the graph to default values:
        - `color` is set to WHITE (indicating unvisited).
        - `dist` is set to `INT_MAX` (indicating the vertex is not reachable initially).
        - `disc_time` and `endp_time` are set to -1 (no discovery or finishing times).
        - `pred` is set to -1 (indicating no predecessor).
        - `scc` is set to -1 (no strongly connected component assigned).
    - The function iterates over all vertices in the graph and updates their attributes.

2. **graph_find**:
    - This function searches the graph for a vertex with a specified ID.
    - It iterates over all vertices in the graph and checks the `id` attribute.
    - If a vertex with the matching ID is found, it returns the index of that vertex.
    - If no vertex with the specified ID is found, it returns -1.

3. **graph_dispose**:
    - This function is used to free the dynamically allocated memory for the graph.
    - It first frees the adjacency list (`rowAdj`) of each vertex.
    - Then, it frees the memory for the array of vertices (`g`).
    - Finally, it frees the memory allocated for the graph structure itself.

4. **main**:
    - The `main` function demonstrates how the above functions are used:
        - It initializes the attributes of the graph using `graph_attribute_init`.
        - It tries to find a vertex with ID 2 using `graph_find`.
        - It frees the allocated memory using `graph_dispose`.
    - The code assumes that the graph is already created and populated, which would typically be done through other functions like `graph_load`.

The `graph_attribute_init`, `graph_find`, and `graph_dispose` functions are essential for managing the graph's state and memory. `graph_attribute_init` ensures that all vertices are initialized before any graph traversal or algorithm. `graph_find` helps locate a vertex in the graph by its unique ID, and `graph_dispose` is responsible for cleaning up memory when the graph is no longer needed.
*/
