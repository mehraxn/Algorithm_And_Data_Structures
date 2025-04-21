#include <stdio.h>
#include "graph.h"

int main() {
    // Create a graph with 4 vertices
    Graph *graph = createGraph(4);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    // Find and print the minimum edge cover
    int minEdgeCover = edge_cover(graph);
    if (minEdgeCover != -1) {
        printf("Minimum edge cover: %d\n", minEdgeCover);
    }

    // Free the graph
    freeGraph(graph);

    return 0;
}