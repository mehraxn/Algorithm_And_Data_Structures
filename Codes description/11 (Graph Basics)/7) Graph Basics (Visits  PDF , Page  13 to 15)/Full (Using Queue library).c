#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX
#include "queue.h" // Include a queue library for BFS

// Define colors for BFS traversal
typedef enum { WHITE, GREY, BLACK } color_t;

// Edge struct (for adjacency list)
typedef struct edge_s {
    int weight;               // Weight of the edge (optional)
    struct vertex_s *dst;     // Pointer to the destination vertex
    struct edge_s *next;      // Pointer to the next edge in the adjacency list
} edge_t;

// Vertex struct
typedef struct vertex_s {
    int id;                   // Vertex identifier
    color_t color;            // Color: WHITE, GREY, or BLACK
    int dist;                 // Distance from the source
    struct vertex_s *pred;    // Predecessor in BFS
    edge_t *head;             // Head of the adjacency list for this vertex
    struct vertex_s *next;    // Pointer to the next vertex in the vertex list
} vertex_t;

// Graph struct
typedef struct graph_s {
    int nv;                   // Number of vertices
    vertex_t *g;              // Pointer to the list of vertices
} graph_t;

// Function to initialize vertex attributes
void graph_attribute_init(graph_t *graph) {
    vertex_t *v = graph->g;
    while (v != NULL) {
        v->color = WHITE;
        v->dist = INT_MAX; // Infinite distance initially
        v->pred = NULL;
        v = v->next;
    }
}

// BFS function
void graph_bfs(graph_t *g, vertex_t *n) {
    queue_t *qp;              // Queue for BFS
    vertex_t *d;              // Destination vertex pointer
    edge_t *e;                // Edge pointer for adjacency list traversal

    // Initialize queue
    qp = queue_init(g->nv);
    n->color = GREY;          // Mark the starting node as discovered (GREY)
    n->dist = 0;              // Distance from the source is 0
    n->pred = NULL;           // No predecessor for the source
    queue_put(qp, (void *)n); // Enqueue the source vertex

    // Start BFS
    while (!queue_empty(qp)) {
        queue_get(qp, (void **)&n); // Dequeue the front vertex
        e = n->head;               // Access adjacency list of current vertex

        // Explore all adjacent vertices
        while (e != NULL) {
            d = e->dst; // Get the destination vertex from the edge
            if (d->color == WHITE) { // If vertex is unvisited
                d->color = GREY;     // Mark as discovered
                d->dist = n->dist + 1; // Update distance
                d->pred = n;         // Set predecessor
                queue_put(qp, (void *)d); // Enqueue the vertex
            }
            e = e->next; // Move to the next edge in the adjacency list
        }
        n->color = BLACK; // Mark the current vertex as fully processed
    }

    // Clean up
    queue_dispose(qp, NULL);
}

// Function to load a graph (dummy implementation for demonstration)
graph_t *graph_load(const char *filename) {
    // This function should parse a file to build the graph.
    // For now, we return NULL as a placeholder.
    printf("graph_load: Functionality not implemented.\n");
    return NULL;
}

// Function to dispose of the graph and free memory
void graph_dispose(graph_t *graph) {
    vertex_t *v = graph->g;
    while (v != NULL) {
        edge_t *e = v->head;
        while (e != NULL) {
            edge_t *temp = e;
            e = e->next;
            free(temp);
        }
        vertex_t *temp = v;
        v = v->next;
        free(temp);
    }
    free(graph);
}

// Function to find a vertex by ID
vertex_t *graph_find(graph_t *graph, int id) {
    vertex_t *v = graph->g;
    while (v != NULL) {
        if (v->id == id)
            return v;
        v = v->next;
    }
    return NULL;
}

// Main function to test BFS
int main() {
    // Example placeholder to integrate graph_load when implemented
    graph_t *graph = graph_load("graph.txt");

    if (!graph) {
        printf("Failed to load graph.\n");
        return 1;
    }

    // Prompt user for starting vertex
    int i;
    printf("Initial vertex? ");
    scanf("%d", &i);
    vertex_t *src = graph_find(graph, i);

    if (src == NULL) {
        printf("Vertex %d not found in the graph.\n", i);
        graph_dispose(graph);
        return 1;
    }

    // Perform BFS starting from the user-specified vertex
    graph_attribute_init(graph);
    printf("BFS starting from vertex %d:\n", i);
    graph_bfs(graph, src);

    // Print results
    vertex_t *v = graph->g;
    while (v != NULL) {
        printf("Vertex %d: Distance = %d, Predecessor = %d\n",
               v->id, v->dist, v->pred ? v->pred->id : -1);
        v = v->next;
    }

    graph_dispose(graph);
    return 0;
}
