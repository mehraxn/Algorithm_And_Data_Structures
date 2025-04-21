#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int **matrix;    // Adjacency matrix
    int numVertices; // Number of vertices
} Graph;

// Function prototypes
Graph *createGraph(int numVertices);
void addEdge(Graph *graph, int u, int v);
void freeGraph(Graph *graph);
int edge_cover(Graph *graph);

#endif