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

// Function prototypes (basic graph operations)
graph_t* create_graph(int num_vertices);
void add_edge(graph_t *graph, int u, int v);
void dfs(graph_t *graph, int start);
void initialize_single_vertex(vertex_t *v);
void free_graph(graph_t *graph);

// Global variable to track the discovery and finishing times during DFS
int time = 0;

// Main function to demonstrate the graph creation and traversal
int main() {
    graph_t *graph = create_graph(5);  // Create a graph with 5 vertices (index 0 to 4)

    // Adding some edges to the graph (directed edges)
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 3, 4);

    // Performing Depth-First Search (DFS) starting from vertex 0
    printf("Starting DFS traversal from vertex 0:\n");
    dfs(graph, 0);

    // Free the allocated memory for the graph
    free_graph(graph);

    return 0;
}

// Function to create a graph with a specified number of vertices
graph_t* create_graph(int num_vertices) {
    graph_t *graph = (graph_t*)malloc(sizeof(graph_t));  // Allocate memory for the graph structure
    graph->nv = num_vertices;  // Set the number of vertices in the graph
    graph->g = (vertex_t*)malloc(num_vertices * sizeof(vertex_t));  // Allocate memory for vertices

    // Initialize each vertex
    for (int i = 0; i < num_vertices; i++) {
        initialize_single_vertex(&graph->g[i]);  // Initialize individual vertices
        graph->g[i].id = i;  // Set the vertex id (unique identifier)
        graph->g[i].rowAdj = (int*)malloc(num_vertices * sizeof(int));  // Allocate memory for adjacency list
    }

    return graph;  // Return the created graph
}

// Function to initialize each vertex (set default values for each field)
void initialize_single_vertex(vertex_t *v) {
    v->color = WHITE;         // Initially, the vertex is unvisited (WHITE)
    v->dist = -1;             // Distance is undefined at first
    v->disc_time = -1;        // Discovery time for DFS is undefined initially
    v->endp_time = -1;        // Finish time for DFS is undefined initially
    v->pred = -1;             // No predecessor initially
    v->scc = -1;              // No SCC assigned initially
}

// Function to add a directed edge between two vertices u and v
void add_edge(graph_t *graph, int u, int v) {
    // Add vertex v to the adjacency list of vertex u (directed edge u -> v)
    graph->g[u].rowAdj[v] = 1;
    // No need to add the reverse edge (v -> u) as the graph is directed
}

// Depth-First Search (DFS) traversal of the graph starting from vertex `start`
void dfs(graph_t *graph, int start) {
    // Mark the starting vertex as being visited (GREY)
    graph->g[start].color = GREY;
    graph->g[start].disc_time = ++time;  // Set the discovery time for DFS
    printf("Visited vertex %d\n", graph->g[start].id);

    // Explore all adjacent vertices of the current vertex
    for (int i = 0; i < graph->nv; i++) {
        if (graph->g[start].rowAdj[i] == 1) {  // If there is an edge from start -> i
            if (graph->g[i].color == WHITE) {  // If vertex i is unvisited
                graph->g[i].pred = start;  // Set the predecessor of i as the current vertex
                dfs(graph, i);  // Recursively perform DFS on vertex i
            }
        }
    }

    // After all adjacent vertices are explored, mark the vertex as fully explored (BLACK)
    graph->g[start].color = BLACK;
    graph->g[start].endp_time = ++time;  // Set the finishing time for DFS
}

// Function to free memory allocated for the graph
void free_graph(graph_t *graph) {
    // Free memory for each vertex's adjacency list
    for (int i = 0; i < graph->nv; i++) {
        free(graph->g[i].rowAdj);  // Free adjacency list memory for vertex i
    }
    free(graph->g);  // Free memory for the array of vertices
    free(graph);     // Free memory for the graph structure
}

/*
Explanation of Changes:

1.  **Global `time` Variable**:
    - The `time` variable is now globally defined outside of any function, before its usage in `dfs()`. This variable keeps track of the discovery and finishing times during the DFS traversal. It is incremented each time a vertex is discovered or finished in DFS.

2.  **DFS Function**:
    - The `dfs()` function uses the `time` variable to store the discovery and finishing times for each vertex as it explores them. The discovery time is set when a vertex is first encountered, and the finishing time is set after all adjacent vertices are explored.

### Summary of Corrected Code:

- The corrected code now properly handles the DFS traversal and tracks the discovery and finishing times for each vertex using the `time` variable. This variable ensures that we can track the order of visiting nodes in a DFS traversal, which can be useful for various algorithms like topological sorting or detecting strongly connected components (SCC).
*/
