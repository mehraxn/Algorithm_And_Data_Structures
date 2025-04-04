#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph
typedef struct {
    int *rowAdj;  // Adjacency list for the vertex
} vertex_t;

typedef struct {
    int nv;       // Number of vertices in the graph
    vertex_t *g;  // Array of vertices
} graph_t;

// A utility function to allocate memory and handle errors
void* util_calloc(size_t num, size_t size) {
    void *ptr = calloc(num, size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit the program if allocation fails
    }
    return ptr;
}

// Function to transpose the graph (reverse the direction of all edges)
graph_t *graph_transpose(graph_t *g) {
    graph_t *h; // New graph to store the transposed graph
    int i, j;

    // Allocate memory for the new graph
    h = (graph_t *) util_calloc(1, sizeof(graph_t));

    // Set the number of vertices for the new graph
    h->nv = g->nv;

    // Allocate memory for the vertices array of the new graph
    h->g = (vertex_t *) util_calloc(g->nv, sizeof(vertex_t));

    // Loop through each vertex in the original graph
    for (i = 0; i < h->nv; i++) {
        // Copy the original vertex information
        h->g[i] = g->g[i];

        // Allocate memory for the rowAdj array for the new vertex
        h->g[i].rowAdj = (int *) util_calloc(h->nv, sizeof(int));

        // Reverse the direction of edges by transposing the adjacency matrix
        for (j = 0; j < h->nv; j++) {
            h->g[i].rowAdj[j] = g->g[j].rowAdj[i]; // Swap row and column
        }
    }

    return h; // Return the transposed graph
}

// Main function to test graph transposition
int main() {
    // Create a simple graph with 3 vertices for testing
    graph_t *g = (graph_t *) util_calloc(1, sizeof(graph_t));
    g->nv = 3;  // Set the number of vertices
    g->g = (vertex_t *) util_calloc(3, sizeof(vertex_t));

    // Example adjacency matrix (directed edges)
    g->g[0].rowAdj = (int *) util_calloc(3, sizeof(int));
    g->g[0].rowAdj[1] = 1; // Vertex 0 -> Vertex 1
    g->g[1].rowAdj = (int *) util_calloc(3, sizeof(int));
    g->g[1].rowAdj[2] = 1; // Vertex 1 -> Vertex 2
    g->g[2].rowAdj = (int *) util_calloc(3, sizeof(int));
    g->g[2].rowAdj[0] = 1; // Vertex 2 -> Vertex 0

    // Call the graph_transpose function
    graph_t *h = graph_transpose(g);

    // Print the transposed graph's adjacency matrix to verify
    printf("Transposed Graph Adjacency Matrix:\n");
    for (int i = 0; i < h->nv; i++) {
        for (int j = 0; j < h->nv; j++) {
            printf("%d ", h->g[i].rowAdj[j]);
        }
        printf("\n");
    }

    // Free allocated memory (optional but important)
    free(g->g[0].rowAdj);
    free(g->g[1].rowAdj);
    free(g->g[2].rowAdj);
    free(g->g);
    free(g);

    free(h->g[0].rowAdj);
    free(h->g[1].rowAdj);
    free(h->g[2].rowAdj);
    free(h->g);
    free(h);

    return 0;
}

/*
Explanation of Functions in the Code:

1. util_calloc:
   - This is a utility function that wraps the calloc function to allocate memory and handle potential errors.
   - It takes two parameters: the number of elements (num) and the size of each element (size).
   - If the memory allocation fails, it prints an error message and terminates the program using exit(1).

2. graph_transpose:
   - This function takes a graph (graph_t *g) as input and returns a new graph (graph_t *h) that represents the transpose of the original graph.
   - The graph transpose operation essentially reverses the direction of all edges. In terms of the adjacency matrix, this means that for every edge from vertex i to vertex j in the original graph, there will be an edge from j to i in the transposed graph.
   - The function allocates memory for the new graph and its vertices. It then iterates through the adjacency matrix of the original graph and swaps the rows and columns to transpose the edges.

3. main:
   - This is the main function where a simple graph is created for testing purposes.
   - A graph with 3 vertices is initialized, and its adjacency matrix is populated with directed edges.
   - The graph_transpose function is called to get the transposed graph, and its adjacency matrix is printed to verify the result.
   - The function also handles memory cleanup at the end by freeing all the allocated memory for both the original and transposed graphs.

Conclusion:
The code provides a basic implementation of a graph transpose operation using an adjacency matrix. The key functions include memory allocation (util_calloc), the core transposition operation (graph_transpose), and testing the functionality in main. Proper memory management ensures there are no memory leaks during execution.
*/
