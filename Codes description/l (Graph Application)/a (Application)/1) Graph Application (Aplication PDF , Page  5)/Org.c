graph_t *graph_transpose (graph_t *g) {
    graph_t *h;
    int i, j;
    h = (graph_t *) util_calloc (1, sizeof (graph_t));
    h->nv = g->nv;
    h->g = (vertex_t *) util_calloc (g->nv, sizeof(vertex_t));
    for (i=0; i<h->nv; i++) {
        h->g[i] = g->g[i];
        h->g[i].rowAdj = (int *) util_calloc (h->nv, sizeof(int));
        for (j=0; j<h->nv; j++) {
            h->g[i].rowAdj[j] = g->g[j].rowAdj[i];
        }
    }
    return h;
}
