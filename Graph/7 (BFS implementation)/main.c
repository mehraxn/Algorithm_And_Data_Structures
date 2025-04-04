#include  <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <limits.h>

/***********************************************************
* COMPLETE BREADTH-FIRST SEARCH IMPLEMENTATION IN C
***********************************************************/

/* Color definitions for BFS vertices */
#define WHITE 0  /* Undiscovered vertex */
#define GRAY 1   /* Discovered but not fully explored */
#define BLACK 2  /* Fully explored vertex */
#define GREY GRAY /* Alternative spelling */

// This part is added for making the code working
/* Function prototypes - these are likely defined elsewhere */
typedef struct vertex vertex_t;
typedef struct edge edge_t;
typedef struct graph graph_t;
typedef struct queue queue_t;

// This part is added for making the code working
struct vertex {
    int id;
    int color;
    int dist;
    vertex_t* pred;
    edge_t* head;
    vertex_t* next;
};

// This part is added for making the code working
struct edge {
    vertex_t* dst;
    edge_t* next;
};

// This part is added for making the code working
struct graph {
    int nv;
    vertex_t* g;
};

// This part is added for making the code working
/* Function prototypes */
queue_t* queue_init(int size);
void queue_enqueue(queue_t* Q, void* item);
void* queue_dequeue(queue_t* Q);
int queue_empty(queue_t* Q);
void queue_put(queue_t* Q, void* item);
int queue_empty_m(queue_t* Q);
void queue_get(queue_t* Q, void** item);
void queue_dispose(queue_t* Q, void (*free_item)(void*));
graph_t* graph_load(const char* filename);
vertex_t* graph_find(graph_t* g, int id);
void graph_attribute_init(graph_t* g);
void graph_dispose(graph_t* g);

/* Pseudocode implementation of BFS */
// This part is added for making the code working
// Original pseudocode adapted to compilable form
void BFS(graph_t* G, vertex_t* s) {
    // This part is added for making the code working
    vertex_t* v;
    for (v = G->g; v != NULL; v = v->next) {
        v->color = WHITE;
        v->dist = INT_MAX; // Using INT_MAX instead of infinity
        v->pred = NULL;
    }
    queue_t* Q = queue_init(G->nv);
    s->color = GRAY;
    s->dist = 0;
    s->pred = NULL;
    queue_put(Q, s);
    while (!queue_empty(Q)) {
        vertex_t* u;
        queue_get(Q, (void**)&u);
        edge_t* e;
        for (e = u->head; e != NULL; e = e->next) {
            vertex_t* v = e->dst;
            if (v->color == WHITE) {
                v->color = GRAY;
                v->dist = u->dist + 1;
                v->pred = u;
                queue_put(Q, v);
            }
        }
        u->color = BLACK;
    }
    queue_dispose(Q, NULL);
}

/* Client code that uses BFS */
int main(int argc, char *argv[]) {
    /* Check command line arguments */
    if (argc < 2) {
        printf("Usage: %s <graph_file>\n", argv[0]);
        return 1;
    }

    graph_t* g = graph_load(argv[1]);
    /* Check if graph loaded successfully */
    if (g == NULL) {
        printf("Failed to load graph from %s\n", argv[1]);
        return 1;
    }

    int i;
    printf("Initial vertex? ");
    scanf("%d", &i);
    vertex_t* src = graph_find(g, i);

    /* Check if vertex exists */
    if (src == NULL) {
        printf("Vertex %d not found in graph\n", i);
        graph_dispose(g);
        return 1;
    }

    graph_attribute_init(g);
    BFS(g, src);

    vertex_t* n = g->g;
    printf("List of vertices:\n");
    while (n != NULL) {
        if (n->color != WHITE) {
            printf("%2d: %d (%d)\n", n->id, n->dist, n->pred ? n->pred->id : -1);
        }
        n = n->next;
    }

    graph_dispose(g);
    return 0;
}

/* Actual implementation of BFS using adjacency list representation */
void graph_bfs(graph_t *g, vertex_t *n) {
    queue_t *qp;
    vertex_t *d;
    edge_t *e;

    qp = queue_init(g->nv);
    n->color = GREY;
    n->dist = 0;
    n->pred = NULL;
    queue_put(qp, (void *)n);

    while (!queue_empty_m(qp)) {
        queue_get(qp, (void **)&n);
        e = n->head;
        while (e != NULL) {
            d = e->dst;
            if (d->color == WHITE) {
                d->color = GREY;
                d->dist = n->dist + 1;
                d->pred = n;
                queue_put(qp, (void *)d);
            }
            e = e->next;
        }
        n->color = BLACK;
    }
    queue_dispose(qp, NULL);
}
