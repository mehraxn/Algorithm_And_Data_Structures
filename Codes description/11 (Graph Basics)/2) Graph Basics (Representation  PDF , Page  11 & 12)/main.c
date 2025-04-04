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
void free_graph(graph_t *graph);
void initialize_single_vertex(vertex_t *v);

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

// Function to free the allocated memory for the graph
void free_graph(graph_t *graph) {
    // Free the adjacency lists for each vertex
    for (int i = 0; i < graph->nv; i++) {
        free(graph->g[i].rowAdj);
    }

    // Free memory for the array of vertices and the graph structure
    free(graph->g);
    free(graph);
}

// Function to initialize a single vertex with default values
void initialize_single_vertex(vertex_t *v) {
    v->color = WHITE;         // Initially, the vertex is unvisited
    v->dist = INT_MAX;        // Distance is undefined at first
    v->disc_time = -1;        // Discovery time is undefined
    v->endp_time = -1;        // Finish time is undefined
    v->pred = -1;             // No predecessor initially
    v->scc = -1;              // No SCC assigned initially
}

// Main function to demonstrate the graph loading functionality
int main() {
    // Load the graph from a file (assuming "graph.txt" is the filename)
    graph_t *graph = graph_load("graph.txt");

    // Print the adjacency list of the graph
    for (int i = 0; i < graph->nv; i++) {
        printf("Vertex %d: ", graph->g[i].id);
        for (int j = 0; j < graph->nv; j++) {
            if (graph->g[i].rowAdj[j] != 0) {
                printf("-> %d (weight %d) ", j, graph->g[i].rowAdj[j]);
            }
        }
        printf("\n");
    }

    // Free the allocated memory for the graph
    free_graph(graph);

    return 0;
}

/*
Explanation of Functions in the Code:

1. **graph_load**:
    - This function loads a graph from a file. It reads the number of vertices and whether the graph is directed or undirected.
    - Then, it allocates memory for the vertices and initializes their properties (color, distance, predecessor, etc.).
    - The adjacency list for each vertex is constructed by reading the edges from the file. If the graph is undirected, it adds edges in both directions.

2. **free_graph**:
    - This function is used to free the dynamically allocated memory for the graph. It frees the adjacency lists of all vertices, and then the memory for the vertices array and the graph structure itself.

3. **initialize_single_vertex**:
    - This function initializes the properties of a single vertex with default values, such as setting the color to WHITE (unvisited), distance to infinity, and others to undefined states.

4. **main**:
    - In the `main` function, the graph is loaded from a file using `graph_load`. Then, the adjacency list of the graph is printed to the console to verify that the graph has been loaded correctly.
    - Finally, the memory used by the graph is freed using `free_graph`.

The `graph_load` function is the key part of this code. It handles loading the graph data from a file, setting up the vertices and edges, and ensuring the graph structure is correctly populated.