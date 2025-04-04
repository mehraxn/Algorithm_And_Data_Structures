#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct Vertex {
    int id;
    int color;
    int dtime;    // Discovery time
    int endtime;  // Finish time
    struct Vertex *pred;
    struct Edge *head;
    struct Vertex *next;
} vertex_t;

typedef struct Edge {
    vertex_t *dst;
    struct Edge *next;
} edge_t;

typedef struct Graph {
    vertex_t *g;
} graph_t;

int time;

// Function prototypes
void DFS(graph_t *G);
void DFS_r(graph_t *G, vertex_t *u);

// Depth-First Search
void DFS(graph_t *G) {
    vertex_t *v = G->g;
    time = 0;

    // Initialize all vertices
    while (v != NULL) {
        v->color = WHITE;
        v->dtime = v->endtime = -1; // Represent infinity as -1
        v->pred = NULL;
        v = v->next;
    }

    v = G->g;
    while (v != NULL) {
        if (v->color == WHITE) {
            DFS_r(G, v);
        }
        v = v->next;
    }
}

// Recursive helper function for DFS
void DFS_r(graph_t *G, vertex_t *u) {
    edge_t *e = u->head;

    time++;
    u->dtime = time;
    u->color = GRAY;

    while (e != NULL) {
        vertex_t *v = e->dst;
        if (v->color == WHITE) {
            v->pred = u;
            DFS_r(G, v);
        }
        e = e->next;
    }

    u->color = BLACK;
    time++;
    u->endtime = time;
}
