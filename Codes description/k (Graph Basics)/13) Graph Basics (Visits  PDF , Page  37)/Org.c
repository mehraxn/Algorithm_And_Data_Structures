void graph_dfs (graph_t *g, vertex_t *n) {
    int currTime = 0;
    vertex_t *t1, *t2;
    printf("List of edges:\n");
    currTime = graph_dfs_r (g, n, currTime);
    for (t1 = g->g; t1 != NULL; t1 = t1->next) {
        if (t1->color == WHITE) {
            currTime = graph_dfs_r (g, t1, currTime);
        }
    }
    printf("List of vertices:\n");
    for (t1 = g->g; t1 != NULL; t1 = t1->next) {
        t2 = t1->pred;
        printf("%2d: %2d/%2d (%d)\n",
               t1->id, t1->disc_time, t1->endp_time,
               (t2 != NULL) ? t1->pred->id : -1);
    }
}
