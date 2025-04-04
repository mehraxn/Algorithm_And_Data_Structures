#include <stdio.h>
#include <stdlib.h>

// Define vertex structure
typedef struct vertex_t {
    int *rowAdj; // Pointer to adjacency matrix row for this vertex
} vertex_t;

// Define graph structure
typedef struct graph_t {
    int nv;         // Number of vertices
    vertex_t *g;    // Array of vertices
} graph_t;

// Utility function for memory allocation with error checking
void *util_calloc(size_t num, size_t size) {
    void *ptr = calloc(num, size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to transpose the graph
graph_t *graph_transpose(graph_t *g) {
    graph_t *h;
    int i, j;

    // Allocate memory for the transposed graph
    h = (graph_t *)util_calloc(1, sizeof(graph_t));
    h->nv = g->nv; // Copy the number of vertices
    h->g = (vertex_t *)util_calloc(g->nv, sizeof(vertex_t));

    for (i = 0; i < h->nv; i++) {
        h->g[i] = g->g[i]; // Shallow copy of vertex structure
        h->g[i].rowAdj = (int *)util_calloc(h->nv, sizeof(int)); // Allocate new adjacency row
        for (j = 0; j < h->nv; j++) {
            h->g[i].rowAdj[j] = g->g[j].rowAdj[i]; // Transpose adjacency matrix
        }
    }

    return h; // Return the transposed graph
}

// Function to create a graph with adjacency matrix representation
graph_t *create_graph(int nv) {
    graph_t *g = (graph_t *)util_calloc(1, sizeof(graph_t));
    g->nv = nv; // Set number of vertices
    g->g = (vertex_t *)util_calloc(nv, sizeof(vertex_t));
    for (int i = 0; i < nv; i++) {
        g->g[i].rowAdj = (int *)util_calloc(nv, sizeof(int)); // Initialize adjacency matrix rows
    }
    return g;
}

// Function to add a directed edge to the graph
void add_edge(graph_t *g, int from, int to) {
    if (from >= 0 && from < g->nv && to >= 0 && to < g->nv) {
        g->g[from].rowAdj[to] = 1; // Set edge in adjacency matrix
    }
}

// Function to print the adjacency matrix of a graph
void print_graph(graph_t *g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->nv; i++) {
        for (int j = 0; j < g->nv; j++) {
            printf("%d ", g->g[i].rowAdj[j]);
        }
        printf("\n");
    }
}

// Function to free the memory used by a graph
void free_graph(graph_t *g) {
    for (int i = 0; i < g->nv; i++) {
        free(g->g[i].rowAdj); // Free adjacency matrix row
    }
    free(g->g); // Free vertex array
    free(g);    // Free graph structure
}

// Main function to demonstrate the transpose operation
int main() {
    // Create a graph with 4 vertices
    graph_t *g = create_graph(4);

    // Add edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 0);

    // Print the original graph
    printf("Original Graph:\n");
    print_graph(g);

    // Compute the transpose of the graph
    graph_t *h = graph_transpose(g);

    // Print the transposed graph
    printf("\nTransposed Graph:\n");
    print_graph(h);

    // Free the memory used by both graphs
    free_graph(g);
    free_graph(h);

    return 0;
}
