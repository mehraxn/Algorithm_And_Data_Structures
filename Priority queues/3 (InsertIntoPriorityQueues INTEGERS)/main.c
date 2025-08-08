#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * (i) + 1)
#define RIGHT(i)  (2 * (i) + 2)

// Compare function for max-heap
int item_less(Item a, Item b) {
    return a < b; // returns 1 if a is smaller than b
}

typedef struct pq_s {
    Item *A;      // array to store heap elements
    int pqsize;   // current size
    int capacity; // max capacity
} pq_t;

pq_t *pq_create(int capacity) {
    pq_t *pq = malloc(sizeof(pq_t));
    pq->A = malloc(sizeof(Item) * capacity);
    pq->pqsize = 0;
    pq->capacity = capacity;
    return pq;
}

void pq_insert(pq_t *pq, Item item) {
    if (pq->pqsize == pq->capacity) {
        printf("Priority Queue is full!\n");
        return;
    }

    int i = pq->pqsize++;
    while (i >= 1 && item_less(pq->A[PARENT(i)], item)) {
        pq->A[i] = pq->A[PARENT(i)];
        i = PARENT(i);
    }
    pq->A[i] = item;
}

void pq_print(pq_t *pq) {
    for (int i = 0; i < pq->pqsize; i++) {
        printf("%d ", pq->A[i]);
    }
    printf("\n");
}

void pq_free(pq_t *pq) {
    free(pq->A);
    free(pq);
}

int main() {
    pq_t *pq = pq_create(10);

    pq_insert(pq, 5);
    pq_insert(pq, 10);
    pq_insert(pq, 3);
    pq_insert(pq, 7);

    pq_print(pq); // Should print max-heap order

    pq_free(pq);
    return 0;
}
