#include <stdio.h>
#include <stdlib.h>

// Define a structure for the heap
typedef struct {
    int *A;           // Array to store the heap elements
    int heapsize;     // Current number of elements in the heap
    int capacity;     // Maximum capacity of the heap
} heap_t;

// Macro to get the index of the left child of the current node
#define LEFT(i) (2 * (i) + 1)

// Macro to get the index of the right child of the current node
#define RIGHT(i) (2 * (i) + 2)

// Function to swap two elements in the heap
void swap(heap_t *heap, int i, int j) {
    int temp = heap->A[i];
    heap->A[i] = heap->A[j];
    heap->A[j] = temp;
}

// Function to compare two elements. This function assumes that we are working with a max heap,
// so it checks if the first element is greater than the second element.
int item_greater(int item1, int item2) {
    return item1 > item2;
}

// Function to heapify the subtree rooted at index i
// This function ensures that the heap property is maintained (max heap).
void heapify(heap_t *heap, int i) {
    int l, r, largest;

    // Get the indices of the left and right children
    l = LEFT(i);
    r = RIGHT(i);

    // Check if left child exists and is larger than the current node
    if ((l < heap->heapsize) && (item_greater(heap->A[l], heap->A[i])))
        largest = l;
    else
        largest = i;

    // Check if right child exists and is larger than the largest so far
    if ((r < heap->heapsize) && (item_greater(heap->A[r], heap->A[largest])))
        largest = r;

    // If the largest element is not the current node, swap them and recursively heapify the affected subtree
    if (largest != i) {
        swap(heap, i, largest);
        heapify(heap, largest); // Recursively heapify the subtree
    }

    return;
}

// Function to build a max heap from the given array
void heapbuild(heap_t *heap) {
    int i;
    // Start from the last non-leaf node (n/2 - 1) and call heapify on each node
    for (i = (heap->heapsize) / 2 - 1; i >= 0; i--) {
        heapify(heap, i);
    }
    return;
}

// Function to perform heap sort
void heapsort(heap_t *heap) {
    int i, tmp;

    // Build the max heap
    heapbuild(heap);

    tmp = heap->heapsize;  // Save the original heap size

    // One by one extract elements from the heap
    for (i = heap->heapsize - 1; i > 0; i--) {
        swap(heap, 0, i);  // Move the current root (maximum) to the end of the array

        heap->heapsize--;  // Decrease the heap size

        heapify(heap, 0);  // Call heapify to restore the heap property
    }

    heap->heapsize = tmp;  // Restore the original heap size

    return;
}

// Function to print the heap array
void printHeap(heap_t *heap) {
    for (int i = 0; i < heap->heapsize; i++) {
        printf("%d ", heap->A[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a heap with a capacity of 10 and initialize with some values
    heap_t heap;
    heap.capacity = 10;
    heap.heapsize = 6;
    heap.A = (int *)malloc(heap.capacity * sizeof(int));

    // Initial heap values
    heap.A[0] = 10;
    heap.A[1] = 15;
    heap.A[2] = 30;
    heap.A[3] = 40;
    heap.A[4] = 50;
    heap.A[5] = 100;

    // Print the original array (before sorting)
    printf("Original Heap: \n");
    printHeap(&heap);

    // Perform heap sort
    heapsort(&heap);

    // Print the sorted heap
    printf("Sorted Heap: \n");
    printHeap(&heap);

    // Free the allocated memory for the heap array
    free(heap.A);

    return 0;
}
