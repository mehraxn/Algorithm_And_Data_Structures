#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *edges; // Dynamic array of edges
} Vertex;

int main() {
    int numVertices = 4; // Number of vertices in the graph

    // Allocate memory for the vertex array
    Vertex *graph = (Vertex *)malloc(numVertices * sizeof(Vertex));
    if (!graph) {
        printf("Memory allocation failed for vertices.\n");
        return 1;
    }

    // Initialize the graph with dynamic arrays for edges
    for (int i = 0; i < numVertices; i++) {
        graph[i].edges = (int *)calloc(numVertices, sizeof(int));
        if (!graph[i].edges) {
            printf("Memory allocation failed for edges of vertex %d.\n", i);
            return 1;
        }
    }

    // Define the graph (example edges)
    graph[0].edges[1] = 1; // Vertex 0 -> Vertex 1
    graph[0].edges[3] = 1; // Vertex 0 -> Vertex 3
    graph[1].edges[0] = 1; // Vertex 1 -> Vertex 0
    graph[1].edges[2] = 1; // Vertex 1 -> Vertex 2
    graph[2].edges[1] = 1; // Vertex 2 -> Vertex 1
    graph[2].edges[3] = 1; // Vertex 2 -> Vertex 3
    graph[3].edges[0] = 1; // Vertex 3 -> Vertex 0
    graph[3].edges[2] = 1; // Vertex 3 -> Vertex 2

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i].edges[j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(graph[i].edges);
    }
    free(graph);

    return 0;
}
