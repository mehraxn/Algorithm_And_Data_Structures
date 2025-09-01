Item pq_extract_max(pq_t pq) {
    Item item;

    swap(pq, 0, pq->pqsize - 1);

    item = pq->A[pq->pqsize - 1];

    pq->pqsize--;

    heapify(pq, 0);

    return item;
}
