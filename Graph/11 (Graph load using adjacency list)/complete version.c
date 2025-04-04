#define MAX_LINE 100
#include <stdio.h>     // This part is added to the original code
#include <stdlib.h>    // This part is added to the original code
#include <limits.h>    // This part is added to the original code
enum {WHITE, GREY, BLACK};

typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;
typedef struct edge_s edge_t;

/* graph wrapper */
struct graph_s {
    int nv;
    vertex_t *g;
};

/* Adjacency list structures */
struct edge_s {
    int weight;
    vertex_t *dst;
    edge_t *next;
};

struct vertex_s {
    int id;
    int color;
    int dist;
    int disc_time;
    int endp_time;
    int scc;
    vertex_t *pred;
    edge_t *head;
    vertex_t *next;
};

// This part is added to the original code
// Forward declarations of utility functions
void *util_malloc(size_t size);
void *util_calloc(size_t nmemb, size_t size);
FILE *util_fopen(const char *filename, const char *mode);
// Forward declarations of static functions
static vertex_t *new_node(vertex_t *g, int id);
static void new_edge(graph_t *g, int i, int j, int weight);
// Forward declaration for graph_find
vertex_t *graph_find(graph_t *g, int id);
// End of added forward declarations

/* Load graph from file */
graph_t *graph_load (char *filename) {
    graph_t *g;
    char line[MAX_LINE];
    int i, j, weight, dir;
    FILE *fp;
    g = (graph_t *) util_calloc (1, sizeof(graph_t));
    fp = util_fopen(filename, "r");
    fgets(line, MAX_LINE, fp);
    if (sscanf(line, "%d%d", &g->nv, &dir) != 2) {
        sscanf(line, "%d", &g->nv);
        dir = 1;
    }
    /* create initial structure for vertices */
    for (i=g->nv-1; i>=0; i--) {
        g->g = new_node (g->g, i);
    }

    /* load edges */
    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (sscanf(line,"%d%d%d",&i,&j,&weight) != 3) {
            sscanf(line, "%d%d",&i,&j);
            weight = 1;
        }
        new_edge (g, i, j, weight);
        if (dir == 0) {
            new_edge (g, j, i, weight);
        }
    }
    fclose(fp);
    return g;
}

/* Create new vertex node */
static vertex_t *new_node (vertex_t *g, int id) {
    vertex_t *v;

    v = (vertex_t *)util_malloc(sizeof(vertex_t));
    v->id = id;
    v->color = WHITE;
    v->dist = INT_MAX;
    v->scc = v->disc_time = v->endp_time = -1;  // This part is added to the original code: fixed typo  'n' to 'v'
    v->pred = NULL;
    v->head = NULL;
    v->next = g;
    return v;  // Head insertion
}

/* Create new edge */
static void new_edge  (graph_t *g, int i, int j, int weight) {
    vertex_t *src, *dst;
    edge_t *e;

    src = graph_find (g, i);
    dst = graph_find (g, j);

    e = (edge_t *) util_malloc (sizeof (edge_t));
    e->dst = dst;  // This part is added to the original code: changed 'dst' to 'dat' to match struct definition
    e->weight = weight;
    e->next = src->head;
    src->head = e;
    return;
}

/* Initialize vertex attributes */
void graph_attribute_init (graph_t *g) {
    vertex_t *v;

    v = g->g;
    while (v!=NULL) {
        v->color = WHITE;
        v->dist = INT_MAX;
        v->disc_time = -1;
        v->endp_time = -1;
        v->scc = -1;  // This part is added to the original code: changed 'sec' to 'soc' to match the structure
        v->pred = NULL;
        v = v->next;
    }
    return;
}

/* Find vertex by ID */
vertex_t *graph_find (graph_t *g, int id) {
    vertex_t *v;

    v = g->g;
    while (v != NULL) {
        if (v->id == id) {
            return v;
        }
        v = v->next;
    }
    return NULL;
}

/* Dispose graph memory */
void graph_dispose (graph_t *g) {
    vertex_t *v;
    edge_t *e;

    v = g->g;
    while (v != NULL) {
        while (v->head != NULL) {
            e = v->head;
            v->head = e->next;
            free(e);
        }
        vertex_t *temp = v;  // This part is added to the original code: fixed memory management issue
        v = v->next;
        free(temp);  // This part is added to the original code: fixed freeing of current vertex instead of next
    }
    free(g);  // This part is added to the original code: free the graph structure itself
    return;
}

// This part is added to the original code: implementation of utility functions
void *util_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *util_calloc(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

FILE *util_fopen(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);
    if (!fp) {
        fprintf(stderr, "File opening failed for %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return fp;
}
// End of added utility functions