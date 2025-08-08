#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * (i) + 1)
#define RIGHT(i)  (2 * (i) + 2)

// Compare two strings for max-heap order
int str_less(const char *a, const char *b) {
    return strcmp(a, b) < 0; // returns 1 if a < b
}

typedef struct pq_s {
    char **A;     // array to store heap elements
    int pqsize;   // current size
    int capacity; // max capacity
} pq_t;

pq_t *pq_create(int capacity) {
    pq_t *pq = malloc(sizeof(pq_t));
    pq->A = malloc(sizeof(char*) * capacity);
    pq->pqsize = 0;
    pq->capacity = capacity;
    return pq;
}

void pq_insert(pq_t *pq, const char *item) {
    if (pq->pqsize == pq->capacity) {
        printf("Priority Queue is full!\n");
        return;
    }

    // Duplicate the string to store it safely
    char *copy = strdup(item);
    if (!copy) {
        printf("Memory allocation failed!\n");
        return;
    }

    int i = pq->pqsize++;
    while (i >= 1 && str_less(pq->A[PARENT(i)], copy)) {
        pq->A[i] = pq->A[PARENT(i)];
        i = PARENT(i);
    }
    pq->A[i] = copy;
}

void pq_print(pq_t *pq) {
    for (int i = 0; i < pq->pqsize; i++) {
        printf("%s ", pq->A[i]);
    }
    printf("\n");
}

void pq_free(pq_t *pq) {
    for (int i = 0; i < pq->pqsize; i++) {
        free(pq->A[i]);
    }
    free(pq->A);
    free(pq);
}

int main() {
    pq_t *pq = pq_create(10);

    pq_insert(pq, "pear");
    pq_insert(pq, "apple");
    pq_insert(pq, "orange");
    pq_insert(pq, "banana");

    pq_print(pq); // root is lexicographically largest

    pq_free(pq);
    return 0;
}
