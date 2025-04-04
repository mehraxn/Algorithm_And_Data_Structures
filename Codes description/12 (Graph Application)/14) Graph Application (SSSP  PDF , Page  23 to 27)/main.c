#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Constants for vertex colors
enum { WHITE, GREY, BLACK };

// Structures for the graph representation
typedef struct edge_s {
    int weight; // Weight of the edge
    int dst;    // Destination vertex
} edge_t;

typedef struct vertex_s {
    int id;         // Vertex ID
    int ne;         // Number of edges
    int color;      // Vertex color (WHITE, GREY, BLACK)
    int dist;       // Distance from source
    int pred;       // Predecessor
    edge_t *edges;  // Pointer to array of edges
} vertex_t;

typedef struct graph_t {
    vertex_t *g;    // Pointer to array of vertices
    int nv;         // Number of vertices
} graph_t;

// Function prototypes
void initialize_graph(graph_t *g, int nv);
void add_edge(graph_t *g, int src, int dst, int weight);
void sssp_dijkstra(graph_t *g, int start_vertex);
int graph_min(graph_t *g);
void graph_dispose(graph_t *g);

int main() {
    int nv, ne, src, dst, weight, start_vertex;

    // Read the number of vertices and edges
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &nv, &ne);

    // Initialize the graph
    graph_t graph;
    initialize_graph(&graph, nv);

    // Read edges and add them to the graph
    printf("Enter the edges (src dst weight):\n");
    for (int i = 0; i < ne; i++) {
        scanf("%d %d %d", &src, &dst, &weight);
        add_edge(&graph, src, dst, weight);
    }

    // Read the start vertex for Dijkstra's algorithm
    printf("Enter the start vertex: ");
    scanf("%d", &start_vertex);

    // Run Dijkstra's algorithm
    sssp_dijkstra(&graph, start_vertex);

    // Print the shortest distances and predecessors
    printf("Shortest distances from vertex %d:\n", start_vertex);
    for (int i = 0; i < graph.nv; i++) {
        if (graph.g[i].dist != INT_MAX) {
            printf("Node %d: Distance = %d, Predecessor = %d\n", i, graph.g[i].dist, graph.g[i].pred);
        } else {
            printf("Node %d: Distance = INF (No Path)\n", i);
        }
    }

    // Dispose of the graph
    graph_dispose(&graph);

    return 0;
}

// Function to initialize the graph
void initialize_graph(graph_t *g, int nv) {
    g->nv = nv;
    g->g = (vertex_t *)malloc(nv * sizeof(vertex_t));
    for (int i = 0; i < nv; i++) {
        g->g[i].id = i;
        g->g[i].ne = 0;
        g->g[i].color = WHITE;
        g->g[i].dist = INT_MAX; // Set initial distances to infinity
        g->g[i].pred = -1;      // No predecessor initially
        g->g[i].edges = NULL;   // No edges initially
    }
}

// Function to add an edge to the graph
void add_edge(graph_t *g, int src, int dst, int weight) {
    vertex_t *v = &g->g[src];
    v->edges = (edge_t *)realloc(v->edges, (v->ne + 1) * sizeof(edge_t));
    v->edges[v->ne].dst = dst;
    v->edges[v->ne].weight = weight;
    v->ne++;
}

// Function to find the vertex with the minimum distance among unprocessed vertices
int graph_min(graph_t *g) {
    int min_index = -1, min_value = INT_MAX;
    for (int i = 0; i < g->nv; i++) {
        if (g->g[i].color == WHITE && g->g[i].dist < min_value) {
            min_value = g->g[i].dist;
            min_index = i;
        }
    }
    return min_index;
}

// Function implementing Dijkstra's algorithm
void sssp_dijkstra(graph_t *g, int start_vertex) {
    g->g[start_vertex].dist = 0; // Set source distance to 0
    int current_vertex = start_vertex;

    while (current_vertex >= 0) {
        g->g[current_vertex].color = GREY; // Mark vertex as being processed
        for (int k = 0; k < g->g[current_vertex].ne; k++) { // Process all edges from the current vertex
            int neighbor = g->g[current_vertex].edges[k].dst;
            if (g->g[neighbor].color == WHITE) { // If the neighbor is unvisited
                // Relax the edge
                if (g->g[current_vertex].dist + g->g[current_vertex].edges[k].weight < g->g[neighbor].dist) {
                    g->g[neighbor].dist = g->g[current_vertex].dist + g->g[current_vertex].edges[k].weight;
                    g->g[neighbor].pred = current_vertex;
                }
            }
        }
        g->g[current_vertex].color = BLACK; // Mark vertex as fully processed
        current_vertex = graph_min(g); // Find the next vertex with the smallest distance
    }
}

// Function to dispose of the graph and free memory
void graph_dispose(graph_t *g) {
    for (int i = 0; i < g->nv; i++) {
        free(g->g[i].edges); // Free the edge list for each vertex
    }
    free(g->g); // Free the vertex array
}

// Explanation of Functions:
//
// 1. **initialize_graph**:
//    - Initializes the graph with `nv` vertices, sets distances to infinity, and prepares memory for vertices and their attributes.
//
// 2. **add_edge**:
//    - Adds a directed edge between two vertices with a specified weight. Dynamically adjusts memory to store edges.
//
// 3. **graph_min**:
//    - Finds the vertex with the minimum distance that hasn't been fully processed. Returns -1 if all vertices are processed.
//
// 4. **sssp_dijkstra**:
//    - Implements Dijkstra's algorithm to calculate the shortest path from the source vertex to all others.
//    - Updates distances and predecessors as it explores the graph.
//
// 5. **graph_dispose**:
//    - Frees dynamically allocated memory for edges and vertices to prevent memory leaks.
//
// 6. **main**:
//    - Reads input data for the graph, initializes it, adds edges, and calls Dijkstra's algorithm.
//    - Displays the shortest path distances and predecessors for each vertex starting from the source vertex.
//
// Notes:
// - This implementation is simple and straightforward, but it can be optimized using priority queues for better performance.
// - The graph is represented as an adjacency list, making it efficient for sparse graphs.
