#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

typedef struct {
    int dist; // Distance from the source node
    int pred; // Predecessor node
} Node;

// Function to initialize the distance and predecessor for all nodes
void initialize_single_source(Node nodes[], int graph[][V], int s) {
    for (int i = 0; i < V; i++) {
        nodes[i].dist = INT_MAX; // Set all distances to infinity
        nodes[i].pred = -1;      // Set all predecessors to -1 (indicating no predecessor)
    }
    nodes[s].dist = 0; // Set the source node distance to 0
}

// Function to find the vertex with the minimum distance that has not yet been processed
int extract_min(Node nodes[], bool visited[]) {
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && nodes[i].dist < min) {
            min = nodes[i].dist;
            min_index = i;
        }
    }

    return min_index;
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[][V], int source) {
    Node nodes[V];
    bool visited[V] = {false}; // Track visited vertices

    initialize_single_source(nodes, graph, source); // Initialize distances and predecessors

    for (int count = 0; count < V - 1; count++) {
        // Find the unvisited vertex with the smallest distance
        int u = extract_min(nodes, visited);

        if (u == -1) {
            break; // If no vertex can be processed, terminate early
        }

        visited[u] = true; // Mark the chosen vertex as visited

        // Update distances of the adjacent vertices of the current vertex
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && nodes[u].dist != INT_MAX
                && nodes[u].dist + graph[u][v] < nodes[v].dist) {
                nodes[v].dist = nodes[u].dist + graph[u][v];
                nodes[v].pred = u;
            }
        }
    }

    // Print the result
    printf("Vertex\tDistance from Source\tPredecessor\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t\t%d\n", i, nodes[i].dist, nodes[i].pred);
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
            {0, 2, 0, 0, 0},
            {2, 0, 3, 1, 0},
            {0, 3, 0, 7, 0},
            {0, 1, 7, 0, 2},
            {0, 0, 0, 2, 0}
    };

    int source = 0; // Define the source vertex
    printf("Dijkstra's Algorithm from source vertex %d:\n", source);
    dijkstra(graph, source);

    return 0;
}

// Explanation of Functions:

// initialize_single_source:
// Sets all node distances to infinity (INT_MAX) and predecessors to -1.
// Initializes the source node distance to 0 since it is the starting point of traversal.

// extract_min:
// Finds and returns the index of the vertex with the minimum distance that hasn't been processed yet.
// Uses a simple linear search through the nodes array.

// dijkstra:
// Implements Dijkstra's algorithm to calculate the shortest path from the source to all vertices in the graph.
// Updates distances and predecessors for each vertex as it processes the graph.

// main:
// Defines the graph as an adjacency matrix.
// Sets the source vertex and calls the dijkstra function to calculate and print the shortest paths.

// Final Notes:
// This code demonstrates a simple Dijkstra's algorithm implementation using an adjacency matrix for graph representation.
// The initialize_single_source function prepares the nodes for traversal by assigning initial distances and predecessors.
// While this implementation is clear and simple, it can be optimized by using priority queues for faster selection of the minimum distance vertex.
