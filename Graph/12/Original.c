g = graph_load(argv[1]);
printf("Initial vertex? ");
scanf("%d", &i);
src = graph_find(g, i);

graph_attribute_init (g);
graph_bfs (g, src);

n = g->g;
printf ("List of vertices:\n");
while (n != NULL) {
if (n->color != WHITE) {
printf("%2d: %d (%d)\n",
n->id, n->dist, n->pred ? n->pred->id : -1);
}
n = n->next;
}

graph_dispose(g);

void graph_bfs (graph_t *g, vertex_t *n) {
    queue_t *qp;
    vertex_t *d;
    edge_t *e;

    qp = queue_init (g->nv);
    n->color = GREY;
    n->dist = 0;
    n->pred = NULL;
    queue_put (qp, (void *)n);

    while (!queue_empty_m(qp)) {
        queue_get(qp, (void **)&n);
        e = n->head;
        while (e != NULL) {
            d = e->dst;
            if (d->color == WHITE) {
                d->color = GREY;
                d->dist = n->dist + 1;
                d->pred = n;
                queue_put (qp, (void *)d);
            }
            e = e->next;
        }
        n->color = BLACK;
    }
    queue_dispose (qp, NULL);
}