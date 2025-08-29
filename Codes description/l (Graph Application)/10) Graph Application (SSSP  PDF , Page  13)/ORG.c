#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
typedef struct {
    int dist;
    int pred;
} Node;

void initialize_single_source(Node nodes[], int graph[][V], int s) {
    for (int i = 0; i < V; i++) {
        nodes[i].dist = INT_MAX; // Set all distances to infinity
        nodes[i].pred = -1;      // Set all predecessors to NULL
    }
    nodes[s].dist = 0; // Set the source node distance to 0
}
