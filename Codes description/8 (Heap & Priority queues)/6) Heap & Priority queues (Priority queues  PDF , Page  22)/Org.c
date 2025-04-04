void pq_change(pq_t pq, int i, Item item) {
    if (item_less(item, pq->A[i])) {
        decrease_key(pq, i, item);
    } else {
        increase_key(pq, i, item);
    }
}

void decrease_key(pq_t pq, int i, Item item) {
    pq->A[i] = item;
    heapify(pq, i);
}

void increase_key(pq_t pq, int i, Item item) {
    while (i >= 1 && item_less(pq->A[PARENT(i)], item)) {
        pq->A[i] = pq->A[PARENT(i)];
        i = PARENT(i);
    }
    pq->A[i] = item;
}
