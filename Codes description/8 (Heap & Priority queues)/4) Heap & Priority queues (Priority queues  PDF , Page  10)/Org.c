void pq_insert(pq_t pq, Item item) {
    int i;

    // Insert the item at the end of the priority queue
    i = pq->pqsize++;

    // Move the item up to its correct position in the heap
    while (i >= 1 && item_less(pq->A[PARENT(i)], item)) {
        pq->A[i] = pq->A[PARENT(i)];  // Move the parent down
        i = PARENT(i);  // Move to the parent index
    }

    // Place the item at the correct position
    pq->A[i] = item;

    return;
}
