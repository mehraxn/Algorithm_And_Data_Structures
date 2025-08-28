#include <stdlib.h>   // malloc, calloc, free
#include <stdio.h>    // FILE, fopen, fgets, sscanf, fclose
#include <limits.h>   // INT_MAX



#define MAX_LINE 100

enum { WHITE, GREY, BLACK };

typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;

struct graph_s {
    vertex_t *g;
    int nv;
};

struct vertex_s {
    int id;
    int color;
    int dist;
    int disc_time;
    int endp_time;
    int pred;
    int scc;
    int *rowAdj;
};

graph_t *graph_load(char *filename) {
    graph_t *g;
    char line[MAX_LINE];
    int i, j, weight, dir;
    FILE *fp;

    g = util_calloc(1, sizeof(graph_t));

    fp = util_fopen(filename, "r");
    fgets(line, MAX_LINE, fp);
    if (sscanf(line, "%d%d", &g->nv, &dir) != 2) {
        sscanf(line, "%d", &g->nv);
        dir = 1;
    }

    g->g = util_calloc(g->nv, sizeof(vertex_t));

    for (i = 0; i < g->nv; i++) {
        g->g[i].id = i;
        g->g[i].color = WHITE;
        g->g[i].dist = INT_MAX;
        g->g[i].pred = -1;
        g->g[i].scc = -1;
        g->g[i].disc_time = -1;
        g->g[i].endp_time = -1;
        g->g[i].rowAdj = util_calloc(g->nv, sizeof(int));
    }

    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (sscanf(line, "%d%d%d", &i, &j, &weight) != 3) {
            sscanf(line, "%d%d", &i, &j);
            weight = 1;
        }
        g->g[i].rowAdj[j] = weight;
        if (dir == 0) {
            g->g[j].rowAdj[i] = weight;
        }
    }
    fclose(fp);
    return g;
}

void graph_attribute_init(graph_t *g) {
    for (int i = 0; i < g->nv; i++) {
        g->g[i].color = WHITE;
        g->g[i].dist = INT_MAX;
        g->g[i].disc_time = -1;
        g->g[i].endp_time = -1;
        g->g[i].pred = -1;
        g->g[i].scc = -1;
    }
}

int graph_find(graph_t *g, int id) {
    for (int i = 0; i < g->nv; i++) {
        if (g->g[i].id == id) {
            return i;
        }
    }
    return -1;
}

void graph_dispose(graph_t *g) {
    for (int i = 0; i < g->nv; i++) {
        free(g->g[i].rowAdj);
    }
    free(g->g);
    free(g);
}
