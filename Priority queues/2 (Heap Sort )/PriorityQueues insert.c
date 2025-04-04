#include <stdio.h>

void pq_insert(pq_t* pq, Item item) {
    int i = pq->pqsize;
    pq->pqsize++;

    // Traverse up and maintain heap property
    while (i > 0 && pq->A[(i - 1) / 2] < item) {
        pq->A[i] = pq->A[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    // Place the item at the correct position
    pq->A[i] = item;
    return;
}
