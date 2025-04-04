#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* -----------------------------
 * Definitions and data structures
 * ----------------------------- */

#define MAX_LINE 100

/* Enumeration for color states */
enum { WHITE = 0, GREY = 1, BLACK = 2 };

/* Forward declarations for our utility functions */
FILE *util_fopen(const char *filename, const char *mode);
void *util_calloc(size_t nmemb, size_t size);

/* Vertex structure */
typedef struct vertex_s {
    int id;
    int color;
    int disc_time;
    int endp_time;
    int pred;
    int scc;
    int *rowadj;  /* adjacency row (array of weights) */
} vertex_t;

/* Graph structure (wrapper) */
typedef struct graph_s {
    vertex_t *g;  /* array of vertices */
    int nv;       /* number of vertices */
} graph_t;

/* -----------------------------
 * Utility functions
 * ----------------------------- */

/* Safe version of calloc */
void *util_calloc(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if (!ptr) {
        fprintf(stderr, "Error: cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/* Safe version of fopen */
FILE *util_fopen(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);
    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return fp;
}

/* -----------------------------
 * Graph-related functions
 * ----------------------------- */

/* Load a graph from a file using adjacency matrix representation.
   The first line of the file should contain two integers:
       nv  dir
   where:
     nv  = number of vertices
     dir = 0 for undirected, 1 for directed

   Subsequent lines each contain three integers:
       i  j  weight
   meaning there is an edge from i to j with the given weight.
   If dir=0 (undirected), we set both g[i][j] and g[j][i].
*/
graph_t *graph_load(const char *filename) {
    graph_t *g;
    char line[MAX_LINE];
    int i, j, weight, dir;
    FILE *fp;

    /* Allocate the graph structure */
    g = (graph_t *) util_calloc(1, sizeof(graph_t));

    /* Open the file safely */
    fp = util_fopen(filename, "r");

    /* Read the first line to get nv and dir */
    if (fgets(line, MAX_LINE, fp) != NULL) {
        if (sscanf(line, "%d %d", &g->nv, &dir) != 2) {
         sscanf(line, "%d", &g->nv);
         dir = 1;
        }
    } else {
        fprintf(stderr, "Error: empty or invalid file\n");
        exit(EXIT_FAILURE);
    }

    /* Allocate the array of vertices */
    g->g = (vertex_t *) util_calloc(g->nv, sizeof(vertex_t));

    /* Initialize each vertex */
    for (i = 0; i < g->nv; i++) {
        g->g[i].id = i;           /* we store the vertex id as 'i' by default */
        g->g[i].color = WHITE;    /* initial color */
        g->g[i].disc_time = -1;   /* discovery time */
        g->g[i].endp_time = -1;   /* finishing time */
        g->g[i].pred = -1;        /* predecessor */
        g->g[i].scc = -1;         /* strongly connected component index */
        g->g[i].rowadj = (int *) util_calloc(g->nv, sizeof(int));
    }

    /* Read edges (i, j, weight) from each subsequent line */
    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (sscanf(line, "%d %d %d", &i, &j, &weight) == 3) {
            /* Set adjacency from i to j */
            g->g[i].rowadj[j] = weight;
            /* If undirected, set adjacency from j to i as well */
            if (!dir) {
                g->g[j].rowadj[i] = weight;
            }
        }
        /* Ignore lines that don't match "i j weight" */
    }

    /* Close the file and return the graph pointer */
    fclose(fp);
    return g;
}

/* Initialize the “search” attributes of all vertices in a graph */
void graph_attribute_init(graph_t *g) {
    int i;
    for (i = 0; i < g->nv; i++) {
        g->g[i].color = WHITE;
        g->g[i].disc_time = INT_MAX;
        g->g[i].endp_time = -1;
        g->g[i].pred = -1;
        g->g[i].scc = -1;
    }
}

/* Find a vertex by its id (returns index in the g->g array or -1 if not found) */
int graph_find(graph_t *g, int id) {
    int i;
    for (i = 0; i < g->nv; i++) {
        if (g->g[i].id == id) {
            return i;
        }
    }
    return -1;
}

/* Free all allocated memory in the graph structure */
void graph_dispose(graph_t *g) {
    int i;
    /* Free each rowadj array */
    for (i = 0; i < g->nv; i++) {
        free(g->g[i].rowadj);
    }
    /* Free the vertex array and the graph itself */
    free(g->g);
    free(g);
}
