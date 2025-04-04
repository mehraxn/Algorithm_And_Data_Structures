#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX // Define infinity as the maximum integer value

// Structure to represent an edge
typedef struct edge_s {
    int weight;  // The weight of the edge
    int dst;     // The destination vertex of the edge
    struct edge_s *next;  // Pointer to the next edge in the adjacency list
} edge_t;

// Structure to represent a vertex
typedef struct vertex_s {
    int id;           // The ID of the vertex
    int color;        // The color of the vertex (used in DFS, for example)
    int dist;         // Distance value (used in Dijkstra's or Prim's algorithm)
    int disc_time;    // Discovery time (used in DFS)
    int endp_time;    // Finish time (used in DFS)
    int pred;         // Predecessor of the vertex in the MST (used in Prim's algorithm)
    int scc;          // The strongly connected component (used in SCC algorithms)
    edge_t *head;     // Head of the adjacency list for this vertex
} vertex_t;

// Structure to represent a graph
typedef struct graph_s {
    vertex_t *g;  // Array of vertices
    int nv;       // Number of vertices in the graph
} graph_t;

// Function to allocate memory and handle potential allocation errors
void *util_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

// Function to load the graph (stub implementation for this example)
graph_t* graph_load(const char *filename) {
    // This function would load a graph from a file
    // For this example, we return a dummy graph (this should be implemented)
    graph_t *g = (graph_t *)util_malloc(sizeof(graph_t));
    g->nv = 5;  // Example: 5 vertices
    g->g = (vertex_t *)util_malloc(g->nv * sizeof(vertex_t));

    // Initialize vertices (no edges for simplicity)
    for (int i = 0; i < g->nv; i++) {
        g->g[i].id = i;
        g->g[i].color = 0; // WHITE (0)
        g->g[i].dist = INF;
        g->g[i].pred = -1;
        g->g[i].head = NULL;
    }
    return g;
}

// Function to dispose of the graph (free memory)
void graph_dispose(graph_t *g) {
    free(g->g);
    free(g);
}

// Function to find the Minimum Spanning Tree (MST) using Prim's Algorithm
int mst_prim(graph_t *g) {
    int i, j, min, weight = 0;
    int *fringe;  // Array to store fringe vertices
    edge_t *e;    // Pointer to traverse edges

    // Allocate memory for the fringe array
    fringe = (int *)util_malloc(g->nv * sizeof(int));

    // Initialize the fringe array
    for (i = 0; i < g->nv; i++) {
        fringe[i] = i;
    }

    // Print the list of edges making the MST
    printf("List of edges making an MST:\n");

    // Set the starting vertex (vertex 0)
    min = 0;
    g->g[min].dist = 0;  // Set the distance for the source vertex to 0

    // Prim's algorithm main loop
    while (min != -1) {
        i = min;  // Select the vertex with the minimum distance
        g->g[i].pred = fringe[i];  // Set its predecessor
        weight += g->g[i].dist;  // Add its distance to the total weight

        if (g->g[i].dist != 0) {
            // Print the selected edge
            printf("Edge %d-%d (w=%d)\n", fringe[i], i, g->g[i].dist);
        }

        // Set the next vertex to -1 (indicating that we need to find the next minimum)
        min = -1;
        e = g->g[i].head;  // Traverse the adjacency list of vertex i

        // Update distances for adjacent vertices
        while (e != NULL) {
            j = e->dst;
            if (g->g[j].pred == -1) {
                if (e->weight < g->g[j].dist) {
                    g->g[j].dist = e->weight;
                    fringe[j] = i;
                }
            }
            e = e->next;
        }

        // Find the next vertex with the minimum distance
        for (j = 0; j < g->nv; j++) {
            if (g->g[j].pred == -1) {
                if (min == -1 || g->g[j].dist < g->g[min].dist) {
                    min = j;
                }
            }
        }
    }

    // Free the fringe array and return the total weight of the MST
    free(fringe);
    return weight;
}

// Main function to test the MST Prim implementation
int main(int argc, char *argv[]) {
    graph_t *g;
    int weight;

    // Load the graph from a file (e.g., passed as command line argument)
    g = graph_load(argv[1]);

    // Call the mst_prim function to find the MST weight
    weight = mst_prim(g);

    // Print the total weight of the MST
    printf("Total tree weight: %d\n", weight);

    // Dispose of the graph and free memory
    graph_dispose(g);

    return 0;
}

/*
Explanation of Functions:

1. **graph_load**:
   - Loads a graph from a file. For this example, it creates a dummy graph with 5 vertices and no edges.

2. **graph_dispose**:
   - Frees the memory allocated for the graph structure and its vertices.

3. **util_malloc**:
   - A wrapper function for `malloc` that ensures memory is properly allocated. If memory allocation fails, it terminates the program with an error message.

4. **mst_prim**:
   - Implements Prim's algorithm to find the Minimum Spanning Tree (MST) of a graph. It starts from an arbitrary vertex (vertex 0), sets its distance to 0, and iteratively adds the vertex with the minimum key to the MST.
   - It uses an array `fringe[]` to track the closest vertex for each unprocessed vertex and updates the distances accordingly.
   - The total weight of the MST is calculated by summing the weights of the edges that are added to the MST.

5. **main**:
   - The main function initializes the graph by loading it from a file, calls `mst_prim` to calculate the MST, and prints the total weight of the MST.

In summary, this code implements Prim's algorithm for finding the Minimum Spanning Tree (MST) of a given graph. It uses an array `fringe[]` to keep track of the closest vertex to each unvisited vertex and updates the MST iteratively. The result is the MST along with its total weight.
*/
