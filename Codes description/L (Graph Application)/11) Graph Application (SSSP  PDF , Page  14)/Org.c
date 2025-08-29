#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
typedef struct {
    int dist;
    int pred;
} Node;

void relax(Node nodes[], int u, int v, int w) {
    if (nodes[v].dist > nodes[u].dist + w) {
        nodes[v].dist = nodes[u].dist + w;
        nodes[v].pred = u;
    }
}