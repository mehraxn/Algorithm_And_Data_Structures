graph_t *graph_transpose (graph_t *g) {
    graph_t *h = NULL;
    vertex_t *tmp;
    edge_t *e;
    int i;
    h = (graph_t *) util_calloc (1, sizeof(graph_t));
    h->nv = g->nv;
    for (i=h->nv-1; i>=0; i--)
        h->g = new_node (h->g, i);
    tmp = g->g;
    while (tmp != NULL) {
        e = tmp->head;
        while (e != NULL) {
            new_edge (h, e->dst->id, tmp->id, e->weight);
            e = e->next;
        }
        tmp = tmp->next;
    }
    return h;
}
