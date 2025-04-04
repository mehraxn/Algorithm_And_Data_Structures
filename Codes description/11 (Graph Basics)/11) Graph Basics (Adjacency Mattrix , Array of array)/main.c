#include <stdio.h>
#include <stdlib.h>

int main() {
    int numVertices = 4; // Number of vertices in the graph

    // Allocate memory for the adjacency matrix
    int **adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    if (!adjMatrix) {
        printf("Memory allocation failed for adjacency matrix.\n");
        return 1;
    }

    // Allocate memory for each row of the adjacency matrix
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));
        if (!adjMatrix[i]) {
            printf("Memory allocation failed for row %d of adjacency matrix.\n", i);
            return 1;
        }
    }

    // Define the graph (example edges)
    adjMatrix[0][1] = 1; // Vertex 0 -> Vertex 1
    adjMatrix[0][3] = 1; // Vertex 0 -> Vertex 3
    adjMatrix[1][0] = 1; // Vertex 1 -> Vertex 0
    adjMatrix[1][2] = 1; // Vertex 1 -> Vertex 2
    adjMatrix[2][1] = 1; // Vertex 2 -> Vertex 1
    adjMatrix[2][3] = 1; // Vertex 2 -> Vertex 3
    adjMatrix[3][0] = 1; // Vertex 3 -> Vertex 0
    adjMatrix[3][2] = 1; // Vertex 3 -> Vertex 2

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
