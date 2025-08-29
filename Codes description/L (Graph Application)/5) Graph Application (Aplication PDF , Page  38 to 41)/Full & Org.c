#include <stdio.h>
#include <stdlib.h>

// Define the structure for an edge
typedef struct edge_t {
    int weight;         // Weight of the edge
    struct vertex_t *dst;  // Destination vertex
    struct edge_t *next;    // Pointer to the next edge in the list
} edge_t;

// Define the structure for a vertex
typedef struct vertex_t {
    int id;             // Vertex ID
    edge_t *head;       // Head of the list of edges (adjacency list)
    int color;          // Color used for DFS (WHITE, GREY, BLACK)
    int *rowAdj;        // Adjacency matrix row for the vertex (if needed for adjacency matrix representation)
    int scc;            // SCC id (assigned during SCC detection)
} vertex_t;

// Define the structure for the graph
typedef struct {
    int nv;             // Number of vertices in the graph
    vertex_t *g;        // Array of vertices in the graph
} graph_t;

// Constants for DFS coloring
#define WHITE 0
#define GREY  1
#define BLACK 2

// Utility function to allocate memory and handle errors
void* util_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit the program if allocation fails
    }
    return ptr;
}

// Function to create a graph transpose (reverse the direction of all edges)
graph_t* graph_transpose(graph_t *g) {
    graph_t *h = (graph_t *) util_malloc(sizeof(graph_t));
    int i, j;

    h->nv = g->nv;
    h->g = (vertex_t *) util_malloc(g->nv * sizeof(vertex_t));

    for (i = 0; i < h->nv; i++) {
        h->g[i] = g->g[i];
        h->g[i].rowAdj = (int *) util_malloc(h->nv * sizeof(int));

        for (j = 0; j < h->nv; j++) {
            h->g[i].rowAdj[j] = g->g[j].rowAdj[i]; // Reverse edges for transpose
        }
    }
    return h;
}

// Recursive DFS function for SCCs
int graph_scc_r(graph_t *g, int i, int *post, int id, int t) {
    int j;
    g->g[i].color = GREY;   // Mark the vertex as being processed
    g->g[i].scc = id;       // Assign SCC id to the vertex

    // Visit all adjacent vertices
    for (j = 0; j < g->nv; j++) {
        if (g->g[i].rowAdj[j] != 0 && g->g[j].color == WHITE) {
            t = graph_scc_r(g, j, post, id, t); // Recursively visit unvisited adjacent vertices
        }
    }

    g->g[i].color = BLACK;  // Mark the vertex as fully processed
    post[t++] = i;          // Record the vertex in the post-order list
    return t;
}

// Function to compute strongly connected components (SCCs)
int graph_scc(graph_t *g) {
    graph_t *h;
    int i, id = 0, timer = 0;
    int *post, *tmp;

    h = graph_transpose(g); // Create the transpose of the graph
    post = (int *) util_malloc(g->nv * sizeof(int));

    // Perform DFS on the transposed graph
    for (i = 0; i < g->nv; i++) {
        if (h->g[i].color == WHITE) {
            timer = graph_scc_r(h, i, post, id, timer); // DFS for transposed graph
        }
    }

    // Clean up the transposed graph
    free(h);

    // Reset variables and perform DFS on the original graph
    id = timer = 0;
    tmp = (int *) util_malloc(g->nv * sizeof(int));

    for (i = g->nv - 1; i >= 0; i--) {
        if (g->g[post[i]].color == WHITE) {
            timer = graph_scc_r(g, post[i], tmp, id, timer); // DFS on the original graph
            id++; // Increment SCC id after each DFS completion
        }
    }

    free(post);
    free(tmp);

    return id;  // Return the number of SCCs
}

// Function to load a graph (stub, would need to be implemented)
graph_t* graph_load(const char* filename) {
    // Implementation of loading a graph from a file would go here.
    // This is a placeholder for the actual file loading logic.
    // For simplicity, we'll return a dummy graph.
    graph_t *g = (graph_t *) util_malloc(sizeof(graph_t));
    g->nv = 4;
    g->g = (vertex_t *) util_malloc(g->nv * sizeof(vertex_t));
    for (int i = 0; i < g->nv; i++) {
        g->g[i].id = i;
        g->g[i].head = NULL;
        g->g[i].color = WHITE;
        g->g[i].scc = -1;
        g->g[i].rowAdj = (int *) util_malloc(g->nv * sizeof(int));
        for (int j = 0; j < g->nv; j++) {
            g->g[i].rowAdj[j] = 0; // Initialize no edges
        }
    }

    // Manually add edges (for testing purposes)
    g->g[0].rowAdj[1] = 1;
    g->g[1].rowAdj[2] = 1;
    g->g[2].rowAdj[3] = 1;
    g->g[3].rowAdj[0] = 1;

    return g;
}

// Main function to test SCC algorithm
int main(int argc, char* argv[]) {
    graph_t *g;
    int sccs, i, j;

    // Load the graph from a file (dummy filename passed for now)
    g = graph_load(argv[1]);

    // Compute SCCs
    sccs = graph_scc(g);

    // Print the number of SCCs
    fprintf(stdout, "Number of SCCs: %d\n", sccs);

    // Print the vertices of each SCC
    for (j = 0; j < sccs; j++) {
        fprintf(stdout, "SCC%d:", j);
        for (i = 0; i < g->nv; i++) {
            if (g->g[i].scc == j) {
                fprintf(stdout, " %d", i);
            }
        }
        fprintf(stdout, "\n");
    }

    // Clean up and dispose of the graph
    free(g);

    return 0;
}

/*
Explanation of Functions in the Code:

1. util_malloc:
   - A utility function that wraps `malloc` to allocate memory.
   - If allocation fails, it prints an error and terminates the program.

2. graph_transpose:
   - This function takes a graph and returns its transpose (reverse of all edges).
   - It creates a new graph and reverses the adjacency matrix for all edges.

3. graph_scc_r:
   - This function is used for DFS traversal during SCC computation.
   - It assigns a Strongly Connected Component (SCC) ID to the visited vertices and records the post-order of traversal.

4. graph_scc:
   - This function computes the SCCs in a directed graph using Kosaraju's algorithm.
   - First, it creates the transpose of the graph and performs DFS on it to get a post-order.
   - Then, it performs DFS on the original graph in reverse post-order to identify SCCs.

5. graph_load:
   - A stub function that simulates loading a graph. In practice, it would read a graph from a file and create the graph structure.

6. main:
   - The main function loads a graph, computes SCCs, and prints the results.
   - It uses the `graph_scc` function to calculate SCCs and prints the number of SCCs and their members.

Conclusion:
The code implements Kosaraju's algorithm for finding Strongly Connected Components (SCCs) in a directed graph. It uses two DFS traversals: the first on the transposed graph and the second on the original graph in reverse post-order. The `graph_load` function simulates loading a graph, and the `graph_scc` function performs the SCC detection. The graph is represented using an adjacency matrix and vertex structures with additional fields for color and SCC ID tracking.
*/
