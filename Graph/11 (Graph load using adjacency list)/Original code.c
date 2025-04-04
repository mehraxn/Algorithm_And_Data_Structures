#define MAX_LINE 100
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
    vertex_t *dat;
    edge_t *next;
};

struct vertex_s {
    int id;
    int color;
    int dist;
    int disc_time;
    int endp_time;
    int soc;
    vertex_t *pred;
    edge_t *head;
    vertex_t *next;
};

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
    v->sec = v->disc_time = n->endp_time = -1;  // Original typo 'n' instead of 'v'
    v->pred = NULL;
    v->head = NULL;
    v->next = g;
    return v;  // Head insertion
}

/* Create new edge */
static void new_edge (
        graph_t *g, int i, int j, int weight) {
    vertex_t *src, *dst;
    edge_t *e;

    src = graph_find (g, i);
    dst = graph_find (g, j);

    e = (edge_t *) util_malloc (sizeof (edge_t));
    e->dst = dst;  // Mixed 'dat' and 'dst' in edge struct
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
        v->sec = -1;
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
        v = v->next;
        free (v);  // Original memory management error
    }
    return;
}