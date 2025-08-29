void graph_dag (graph_t *g){
    int i, *post, loop=0, timer=0;
    post = (int *)util_malloc(g->nv*sizeof(int));
    for (i=0; i<g->nv; i++) {
        if (g->g[i].color == WHITE) {
            timer = graph_dag_r (g, i, post, timer, &loop);
        }
    }
    if (loop != 0) {
        fprintf (stdout, "Loop detected!\n");
    } else {
        fprintf (stdout, "Topological sort (direct):");
        for (i=g->nv-1; i>=0; i--) {
            fprintf(stdout, " %d", post[i]);
        }
        fprintf (stdout, "\n");
    }
    free (post);
}
