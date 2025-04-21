#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an edge in the graph
typedef struct Edge {
    int destination; // Destination vertex
    int weight;      // Weight of the edge
    struct Edge *next; // Pointer to the next edge
} Edge;

// Structure to represent a vertex in the graph
typedef struct Vertex {
    int id;         // Vertex identifier
    Edge *edges;    // Adjacency list of edges
} Vertex;

// Structure to represent the graph
typedef struct Graph {
    int numVertices; // Number of vertices in the graph
    Vertex *vertices; // Array of vertices
} Graph;

// Function to check if the graph is regular
int isRegular(Graph *graph) {
    if (graph->numVertices == 0) return 1;

    // Determine the degree of the first vertex
    int degree = 0;
    for (Edge *edge = graph->vertices[0].edges; edge != NULL; edge = edge->next) {
        degree++;
    }

    // Check if all vertices have the same degree
    for (int i = 1; i < graph->numVertices; i++) {
        int currentDegree = 0;
        for (Edge *edge = graph->vertices[i].edges; edge != NULL; edge = edge->next) {
            currentDegree++;
        }
        if (currentDegree != degree) {
            return 0;
        }
    }

    return 1;
}

// Helper function to find the maximum-weight simple path from a vertex
void findSimplePathHelper(Graph *graph, int vertex, bool *visited, int currentWeight, int *maxWeight, int *path, int *maxPath, int depth) {
    visited[vertex] = true;
    path[depth] = vertex;

    // Update maxWeight and maxPath if current path has a larger weight
    if (currentWeight > *maxWeight) {
        *maxWeight = currentWeight;
        for (int i = 0; i <= depth; i++) {
            maxPath[i] = path[i];
        }
        maxPath[depth + 1] = -1; // Mark the end of the path
    }

    // Explore adjacent vertices
    for (Edge *edge = graph->vertices[vertex].edges; edge != NULL; edge = edge->next) {
        if (!visited[edge->destination]) {
            findSimplePathHelper(graph, edge->destination, visited, currentWeight + edge->weight, maxWeight, path, maxPath, depth + 1);
        }
    }

    visited[vertex] = false;
}

// Function to find the maximum-weight simple path starting from a given vertex
int findSimplePath(Graph *graph, int startVertex) {
    bool *visited = (bool *)calloc(graph->numVertices, sizeof(bool));
    int *path = (int *)malloc(graph->numVertices * sizeof(int));
    int *maxPath = (int *)malloc((graph->numVertices + 1) * sizeof(int)); // +1 to mark the end of the path
    int maxWeight = 0;

    findSimplePathHelper(graph, startVertex, visited, 0, &maxWeight, path, maxPath, 0);

    // Print the result
    printf("Maximum-weight simple path starting from vertex %d:\n", startVertex);
    printf("Path: ");
    for (int i = 0; maxPath[i] != -1; i++) {
        printf("%d ", maxPath[i]);
    }
    printf("\nTotal weight: %d\n", maxWeight);

    // Free allocated memory
    free(visited);
    free(path);
    free(maxPath);

    return (maxWeight > 0) ? 1 : 0;
}
