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

// Recursive DFS function to detect cycles and perform topological sort
int graph_dag_r(graph_t *g, int i, int *post, int t, int *loop) {
    int j;
    g->g[i].color = GREY; // Mark the current vertex as GREY (in progress)

    // Iterate over all the adjacent vertices
    for (j = 0; j < g->nv; j++) {
        // Check if there is an edge from vertex i to vertex j (rowAdj is non-zero)
        if (g->g[i].rowAdj[j] != 0) {
            if (g->g[j].color == GREY) {
                *loop = 1;  // If we encounter a GREY vertex, a cycle is detected
            }
            if (g->g[j].color == WHITE) {
                t = graph_dag_r(g, j, post, t, loop); // Recursively visit the unvisited vertex
            }
        }
    }
    g->g[i].color = BLACK; // Mark the vertex as BLACK (visited)
    post[t++] = i;         // Add the vertex to the post-order array
    return t;
}

// Function to detect if the graph is a Directed Acyclic Graph (DAG) and perform topological sorting
void graph_dag(graph_t *g) {
    int i, *post, loop = 0, t = 0;
    post = (int *)util_malloc(g->nv * sizeof(int)); // Allocate memory for the post-order array

    // Perform DFS for all unvisited vertices
    for (i = 0; i < g->nv; i++) {
        if (g->g[i].color == WHITE) {
            t = graph_dag_r(g, i, post, t, &loop); // Call DFS on unvisited vertex
        }
    }

    // Check if a cycle (loop) was detected during the DFS
    if (loop != 0) {
        fprintf(stdout, "Loop detected!\n"); // Print message if a cycle is detected
    } else {
        // Print the topological order (reverse of post-order)
        fprintf(stdout, "Topological sort (direct):");
        for (i = g->nv - 1; i >= 0; i--) {
            fprintf(stdout, " %d", post[i]);
        }
        fprintf(stdout, "\n");
    }

    free(post); // Free the allocated memory for the post-order array
}

// Main function to test the graph DAG functionality
int main() {
    // Example graph with 4 vertices for testing
    graph_t *g = (graph_t *)util_malloc(sizeof(graph_t));
    g->nv = 4;  // Set the number of vertices in the graph
    g->g = (vertex_t *)util_malloc(4 * sizeof(vertex_t));

    // Initialize the vertices
    for (int i = 0; i < 4; i++) {
        g->g[i].id = i;
        g->g[i].head = NULL;
        g->g[i].color = WHITE; // Initialize all vertices as WHITE (unvisited)
        g->g[i].rowAdj = (int *)util_malloc(4 * sizeof(int)); // Allocate memory for adjacency matrix row
        for (int j = 0; j < 4; j++) {
            g->g[i].rowAdj[j] = 0; // Initialize adjacency matrix with no edges
        }
    }

    // Manually add edges to the graph (adjacency matrix representation)
    g->g[0].rowAdj[1] = 1;  // Vertex 0 -> Vertex 1
    g->g[0].rowAdj[2] = 1;  // Vertex 0 -> Vertex 2
    g->g[1].rowAdj[3] = 1;  // Vertex 1 -> Vertex 3
    g->g[2].rowAdj[3] = 1;  // Vertex 2 -> Vertex 3

    // Call graph_dag to perform topological sort and cycle detection
    graph_dag(g);

    // Free allocated memory for the graph
    for (int i = 0; i < 4; i++) {
        free(g->g[i].rowAdj); // Free adjacency matrix row
    }
    free(g); // Free the graph itself

    return 0;
}

/*
Explanation of Functions in the Code:

1. util_malloc:
   - This function wraps the standard `malloc` to allocate memory and handle potential errors.
   - If memory allocation fails, it prints an error message and terminates the program using `exit(1)`.

2. graph_dag_r:
   - This function performs a Depth-First Search (DFS) to check for cycles and compute the topological order of vertices.
   - It uses a recursive approach to visit all vertices and edges.
   - If a cycle is detected (a back edge is found to a GREY vertex), it sets `loop` to 1.
   - It maintains a post-order array (`post`) to store the topologically sorted vertices, which is returned in reverse order to represent the valid topological order.

3. graph_dag:
   - This function initializes the DFS process for all vertices in the graph.
   - It calls `graph_dag_r` for unvisited vertices and checks if a cycle exists in the graph.
   - If no cycles are found, it prints the topological sort (reverse of the post-order).
   - If a cycle is detected, it prints "Loop detected!" indicating that the graph is not a Directed Acyclic Graph (DAG).

4. main:
   - This is the main function where a sample graph is created for testing purposes.
   - The graph is manually constructed with 4 vertices and directed edges (using an adjacency matrix).
   - The `graph_dag` function is called to perform the topological sort and cycle detection.
   - The function also handles memory cleanup by freeing all the allocated memory at the end.

Conclusion:
The code implements a topological sort for Directed Acyclic Graphs (DAGs) using Depth-First Search (DFS). The `graph_dag` function performs the cycle detection and topological sorting, while `graph_dag_r` is responsible for the recursive DFS traversal. The code also checks for cycles in the graph and prints the topological order if no cycles are found. Proper memory management is ensured by freeing the allocated memory.
*/
