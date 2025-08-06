#include <stdio.h>
#include <stdlib.h>

#define PARENT(i)  (((i)-1)>>1)
#define LEFT(i)    (((i)<<1)+1)
#define RIGHT(i)   (((i)<<1)+2)

typedef struct heap_s heap_t;
struct heap_s {
    int *v;
    int size;
};

static void swap (heap_t *heap, int i ,int j) {
    int tmp;
    tmp = heap->v[i];
    heap->v[i] = heap->v[j];
    heap->v[j] = tmp;
    return;
}

static void heapify (heap_t *heap, int i) {
    int l, r, tmp;
    l = LEFT(i);
    r = RIGHT(i);
    if ((l<heap->size) && (heap->v[l]<heap->v[i]))
        tmp = l;
    else
        tmp = i;
    if ((r<heap->size) && (heap->v[r]<heap->v[tmp]))
        tmp = r;
    if (tmp != i) {
        swap (heap, i, tmp);
        heapify (heap, tmp);
    }
    return;
}

static void build_heap (heap_t *heap) {
    int i;
    for (i=(heap->size>>1)-1; i>=0; i--) {
        heapify (heap, i);
    }
    return;
}

void heapSort (heap_t *heap) {
    int i, size;
    build_heap (heap);
    size = heap->size;
    for (i=heap->size-1; i>=0; i--) {
        swap (heap, 0, i);
        heap->size--;
        heapify (heap, 0);
    }
    heap->size = size;
    return;
}
