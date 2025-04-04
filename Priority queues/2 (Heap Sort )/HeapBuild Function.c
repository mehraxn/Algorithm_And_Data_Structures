#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *A;      // Array to hold the elements of the heap
    int heapsize; // Current size of the heap
} heap_t;

void swap(heap_t *heap, int i, int j) {
    int temp = heap->A[i];
    heap->A[i] = heap->A[j];
    heap->A[j] = temp;
}

void heapify(heap_t *heap, int i) {
    int l, r, largest;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if ((l < heap->heapsize) && (heap->A[l] > heap->A[i]))
        largest = l;
    else
        largest = i;

    if ((r < heap->heapsize) && (heap->A[r] > heap->A[largest]))
        largest = r;

    if (largest != i) {
        swap(heap, i, largest);
        heapify(heap, largest);
    }

    return;
}

heap_t *create_heap(int capacity) {
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
    heap->A = (int *)malloc(capacity * sizeof(int));
    heap->heapsize = 0;
    return heap;
}

void insert(heap_t *heap, int value) {
    heap->A[heap->heapsize] = value;
    heap->heapsize++;
    // Heapify up (not implemented here for simplicity)
}

void heapbuild(heap_t *heap) {
    int i;
    for (i = (heap->heapsize) / 2 - 1; i >= 0; i--) {
        heapify(heap, i);
    }
    return;
}

void free_heap(heap_t *heap) {
    free(heap->A);
    free(heap);
}
