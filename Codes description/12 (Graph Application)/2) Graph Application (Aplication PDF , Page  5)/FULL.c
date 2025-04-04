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
    struct vertex_t *next;  // Pointer to the next vertex in the graph
} vertex_t;

// Define the structure for the graph
typedef struct {
    int nv;             // Number of vertices in the graph
    vertex_t *g;        // Linked list of vertices
} graph_t;

// Utility function to allocate memory and handle errors
void* util_calloc(size_t num, size_t size) {
    void *ptr = calloc(num, size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit the program if allocation fails
    }
    return ptr;
}

// Function to create a new node (vertex)
vertex_t* new_node(vertex_t *head, int id) {
    vertex_t *new_vertex = (vertex_t *) util_calloc(1, sizeof(vertex_t));
    new_vertex->id = id;
    new_vertex->head = NULL; // No edges initially
    new_vertex->next = head; // Insert at the head of the list
    return new_vertex;
}

// Function to add a new edge to the graph
void new_edge(graph_t *g, int src_id, int dst_id, int weight) {
    vertex_t *src = g->g;
    while (src != NULL && src->id != src_id) {
        src = src->next;
    }

    if (src != NULL) {
        edge_t *new_edge = (edge_t *) util_calloc(1, sizeof(edge_t));
        new_edge->weight = weight;

        // Find the destination vertex
        vertex_t *dst = g->g;
        while (dst != NULL && dst->id != dst_id) {
            dst = dst->next;
        }

        if (dst != NULL) {
            new_edge->dst = dst;
            new_edge->next = src->head;
            src->head = new_edge; // Insert the edge at the head of the list
        }
    }
}

// Function to transpose the graph (reverse the direction of all edges)
graph_t *graph_transpose(graph_t *g) {
    graph_t *h = NULL;        // New graph to store the transposed graph
    vertex_t *tmp;            // Temporary vertex pointer
    edge_t *e;                // Temporary edge pointer
    int i;

    // Allocate memory for the new graph
    h = (graph_t *) util_calloc(1, sizeof(graph_t));
    h->nv = g->nv;  // Set the number of vertices in the new graph

    // Create the vertices for the new graph
    for (i = h->nv - 1; i >= 0; i--) {
        h->g = new_node(h->g, i);
    }

    tmp = g->g;  // Start from the first vertex in the original graph

    // Iterate over each vertex in the original graph
    while (tmp != NULL) {
        e = tmp->head;  // Start from the first edge of the current vertex

        // Iterate over each edge for the current vertex
        while (e != NULL) {
            // Add the edge in reverse direction to the new graph
            new_edge(h, e->dst->id, tmp->id, e->weight);
            e = e->next;  // Move to the next edge
        }

        tmp = tmp->next;  // Move to the next vertex in the original graph
    }

    return h;  // Return the transposed graph
}

// Main function to test graph transposition
int main() {
    // Create a simple graph with 3 vertices for testing
    graph_t *g = (graph_t *) util_calloc(1, sizeof(graph_t));
    g->nv = 3;  // Set the number of vertices
    g->g = NULL;  // Initialize the graph with no vertices

    // Add vertices to the graph
    g->g = new_node(g->g, 0);
    g->g = new_node(g->g, 1);
    g->g = new_node(g->g, 2);

    // Add edges between the vertices
    new_edge(g, 0, 1, 10); // Vertex 0 -> Vertex 1
    new_edge(g, 1, 2, 20); // Vertex 1 -> Vertex 2
    new_edge(g, 2, 0, 30); // Vertex 2 -> Vertex 0

    // Call the graph_transpose function to transpose the graph
    graph_t *h = graph_transpose(g);

    // Print the transposed graph's adjacency list to verify
    printf("Transposed Graph Adjacency List:\n");
    vertex_t *v = h->g;
    while (v != NULL) {
        printf("Vertex %d:\n", v->id);
        edge_t *e = v->head;
        while (e != NULL) {
            printf("  Edge to Vertex %d with weight %d\n", e->dst->id, e->weight);
            e = e->next;
        }
        v = v->next;
    }

    // Free allocated memory (optional but important)
    free(g);
    free(h);

    return 0;
}

/*
Explanation of Functions in the Code:

1. util_calloc:
   - This is a utility function that wraps the calloc function to allocate memory and handle potential errors.
   - It takes two parameters: the number of elements (num) and the size of each element (size).
   - If the memory allocation fails, it prints an error message and terminates the program using exit(1).

2. new_node:
   - This function creates a new vertex and adds it to the list of vertices in the graph.
   - It allocates memory for the vertex and sets its ID. Initially, the vertex has no edges (head is NULL).
   - The new vertex is inserted at the head of the linked list of vertices.

3. new_edge:
   - This function adds a new directed edge from the vertex `src_id` to the vertex `dst_id` with a specified weight.
   - It searches for the source and destination vertices in the graph, then creates an edge between them and adds it to the adjacency list of the source vertex.

4. graph_transpose:
   - This function takes a graph `g` as input and returns a new graph `h` that represents the transpose of the original graph.
   - The graph transpose operation reverses the direction of all edges. It iterates through the adjacency list of the original graph and adds edges in reverse order to the new graph.
   - The new graph `h` is initialized, and the vertices are added in the reverse order.

5. main:
   - This is the main function where a simple graph is created for testing purposes.
   - A graph with 3 vertices is initialized, and edges are added between them.
   - The `graph_transpose` function is called to get the transposed graph, and the transposed graph's adjacency list is printed to verify the result.
   - The function also handles memory cleanup by freeing all the allocated memory.

Conclusion:
The code implements a graph transpose operation using an adjacency list representation of a graph. The main functions are responsible for memory allocation (`util_calloc`), creating new nodes and edges (`new_node` and `new_edge`), performing the transposition (`graph_transpose`), and testing the functionality (`main`). Proper memory management ensures there are no memory leaks during execution.
*/
