int graph_dag_r(graph_t *g, int i, int *post, int t, int *loop) {
    int j;
    g->g[i].color = GREY;
    for (j = 0; j < g->nv; j++) {
        if (g->g[i].rowAdj[j] != 0) {
            if (g->g[j].color == GREY) {
                *loop = 1;
            }
            if (g->g[j].color == WHITE) {
                t = graph_dag_r(g, j, post, t, loop);
            }
        }
    }
    g->g[i].color = BLACK;
    post[t++] = i;
    return t;
}
