#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Create a new graph with a given number of vertices
Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (!graph) {
        fprintf(stderr, "Memory allocation failed for graph.\n");
        return NULL;
    }

    graph->numVertices = numVertices;

    // Allocate memory for adjacency matrix
    graph->matrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph->matrix[i] = (int *)calloc(numVertices, sizeof(int));
    }

    return graph;
}

// Add an edge between two vertices
void addEdge(Graph *graph, int u, int v) {
    if (u >= graph->numVertices || v >= graph->numVertices) {
        fprintf(stderr, "Invalid vertices for edge.\n");
        return;
    }
    graph->matrix[u][v] = 1;
    graph->matrix[v][u] = 1;
}

// Free the graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

// Recursive function to find the minimum edge cover
int edge_cover_helper(Graph *graph, int *covered, int currentEdgeCount, int currentVertex) {
    int numVertices = graph->numVertices;

    // Check if all vertices are covered
    int allCovered = 1;
    for (int i = 0; i < numVertices; i++) {
        if (!covered[i]) {
            allCovered = 0;
            break;
        }
    }
    if (allCovered) {
        return currentEdgeCount;
    }

    // Initialize minimum edge count to a large value
    int minEdges = numVertices * (numVertices - 1);

    // Try adding an edge for uncovered vertices
    for (int i = 0; i < numVertices; i++) {
        if (!covered[i]) {
            for (int j = 0; j < numVertices; j++) {
                if (graph->matrix[i][j] && !covered[j]) {
                    // Temporarily mark vertices as covered
                    covered[i] = 1;
                    covered[j] = 1;

                    // Recurse with this edge included
                    int edges = edge_cover_helper(graph, covered, currentEdgeCount + 1, i + 1);

                    // Backtrack
                    covered[i] = 0;
                    covered[j] = 0;

                    // Update minimum edge count
                    if (edges < minEdges) {
                        minEdges = edges;
                    }
                }
            }
            break; // Only consider one uncovered vertex at a time
        }
    }

    return minEdges;
}

// Main function to find the minimum edge cover
int edge_cover(Graph *graph) {
    int *covered = (int *)calloc(graph->numVertices, sizeof(int));
    if (!covered) {
        fprintf(stderr, "Memory allocation failed for covered array.\n");
        return -1;
    }
    int result = edge_cover_helper(graph, covered, 0, 0);
    free(covered);
    return result;
}