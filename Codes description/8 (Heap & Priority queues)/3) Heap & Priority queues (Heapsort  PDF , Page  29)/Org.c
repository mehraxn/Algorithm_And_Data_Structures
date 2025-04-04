void heapify(heap_t heap, int i) {
    int l, r, largest;
    l = LEFT(i);
    r = RIGHT(i);

    if ((l < heap->heapsize) && (item_greater(heap->A[l], heap->A[i])))
        largest = l;
    else
        largest = i;

    if ((r < heap->heapsize) && (item_greater(heap->A[r], heap->A[largest])))
        largest = r;

    if (largest != i) {
        swap(heap, i, largest);
        heapify(heap, largest);
    }

    return;
}


void heapbuild(heap_t heap) {
    int i;
    for (i = (heap->heapsize) / 2 - 1; i >= 0; i--) {
        heapify(heap, i);
    }
    return;
}


void heapsort(heap_t heap) {
    int i, tmp;

    heapbuild(heap);

    tmp = heap->heapsize;  // Save the original heap size

    for (i = heap->heapsize - 1; i > 0; i--) {
        swap(heap, 0, i);

        heap->heapsize--;

        heapify(heap, 0);
    }

    heap->heapsize = tmp;

    return;
}
