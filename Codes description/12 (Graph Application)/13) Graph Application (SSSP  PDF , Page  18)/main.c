#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX    // Represents infinity
#define MAX_NODES 100  // Maximum number of nodes in the graph

// Structure to represent an edge
typedef struct {
    int dst;      // Destination vertex
    int weight;   // Edge weight
} Edge;

// Structure to represent a vertex
typedef struct {
    Edge edges[MAX_NODES]; // List of edges for this vertex
    int ne;                // Number of edges
    int dist;              // Distance from the source
    int pred;              // Predecessor
    int color;             // Vertex color: WHITE, GREY, or BLACK
} Vertex;

// Structure to represent the graph
typedef struct {
    Vertex g[MAX_NODES];   // Array of vertices
    int n;                 // Number of vertices
} graph_t;

// Vertex colors
enum { WHITE, GREY, BLACK };

// Function to find the vertex with the minimum distance among unprocessed vertices
int graph_min(graph_t *g) {
    int min_index = -1, min_value = INF;
    for (int i = 0; i < g->n; i++) {
        if (g->g[i].color == WHITE && g->g[i].dist < min_value) {
            min_value = g->g[i].dist;
            min_index = i;
        }
    }
    return min_index;
}

// Function implementing Dijkstra's algorithm
void sssp_dijkstra(graph_t *g, int i) {
    int j, k;
    g->g[i].dist = 0; // Set source distance to 0
    while (i >= 0) {
        g->g[i].color = GREY; // Mark vertex as being processed
        for (k = 0; k < g->g[i].ne; k++) { // Process all edges from vertex i
            j = g->g[i].edges[k].dst;
            if (g->g[j].color == WHITE) { // If the target vertex is unvisited
                // Relax the edge
                if (g->g[i].dist + g->g[i].edges[k].weight < g->g[j].dist) {
                    g->g[j].dist = g->g[i].dist + g->g[i].edges[k].weight;
                    g->g[j].pred = i;
                }
            }
        }
        g->g[i].color = BLACK; // Mark vertex as fully processed
        i = graph_min(g); // Find the next vertex with the smallest distance
    }
}

// Function to initialize the graph
void initialize_graph(graph_t *g, int n) {
    g->n = n; // Set the number of vertices
    for (int i = 0; i < n; i++) {
        g->g[i].ne = 0;       // No edges initially
        g->g[i].dist = INF;   // Set all distances to infinity
        g->g[i].pred = -1;    // No predecessor initially
        g->g[i].color = WHITE; // All vertices are unvisited
    }
}

// Function to add an edge to the graph
void add_edge(graph_t *g, int src, int dst, int weight) {
    int ne = g->g[src].ne; // Get the number of edges for the source vertex
    g->g[src].edges[ne].dst = dst;     // Set destination vertex
    g->g[src].edges[ne].weight = weight; // Set weight of the edge
    g->g[src].ne++; // Increment the number of edges for the source vertex
}

// Main function
int main() {
    graph_t graph;
    int n = 5; // Number of vertices
    initialize_graph(&graph, n);

    // Add edges to the graph
    add_edge(&graph, 0, 1, 10);
    add_edge(&graph, 0, 4, 5);
    add_edge(&graph, 1, 2, 1);
    add_edge(&graph, 1, 4, 2);
    add_edge(&graph, 2, 3, 4);
    add_edge(&graph, 3, 0, 7);
    add_edge(&graph, 4, 3, 2);

    int source = 0; // Source vertex
    sssp_dijkstra(&graph, source);

    // Print the shortest distances from the source
    printf("Vertex\tDistance from Source\tPredecessor\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%d\n", i,
               (graph.g[i].dist == INF) ? "INF" : (char[20]){0}, graph.g[i].pred);
        if (graph.g[i].dist != INF) printf("%d", graph.g[i].dist);
    }

    return 0;
}

// Explanation of Functions:

// graph_min:
// Finds the unvisited vertex with the minimum distance.
// Returns the index of the vertex or -1 if all vertices are visited.

// sssp_dijkstra:
// Implements Dijkstra's algorithm to find the shortest paths from the source vertex to all other vertices.
// Relaxes edges and updates distances and predecessors for adjacent vertices.

// initialize_graph:
// Initializes the graph structure, setting the number of vertices, clearing edges, and initializing distances, predecessors, and colors.

// add_edge:
// Adds a directed edge to the graph from the source vertex to the destination vertex with a given weight.

// main:
// Sets up the graph by defining vertices and edges.
// Calls the Dijkstra's algorithm function to compute the shortest paths.
// Prints the shortest distances and predecessors for each vertex.

// Final Notes:
// This code uses a graph represented by an adjacency list for better performance and clarity.
// Dijkstra's algorithm is used to compute the shortest paths efficiently.
// The use of `graph_min` makes the algorithm simple but can be optimized using a priority queue for better performance.
