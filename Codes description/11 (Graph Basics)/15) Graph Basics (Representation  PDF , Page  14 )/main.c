int graph_find (graph_t *g, int id) {
    int i;
    for (i = 0; i < g->nv; i++) {
        if (g->g[i].id == id) {
            return i;
        }
    }
    return -1;
}
