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
