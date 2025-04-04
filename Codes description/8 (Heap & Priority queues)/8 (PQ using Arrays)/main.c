#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // Maximum number of elements in the priority queue

// Define the priority queue structure
typedef struct {
    int *arr;    // Array to hold the priority queue items
    int size;    // Current number of items in the priority queue
} PriorityQueue;

// Function to initialize the priority queue
void pq_init(PriorityQueue *pq) {
    pq->arr = (int*)malloc(MAX_SIZE * sizeof(int));  // Allocate memory for the priority queue array
    pq->size = 0;  // Set the initial size of the priority queue to 0
}

// Function to check if the priority queue is empty
int pq_is_empty(PriorityQueue *pq) {
    return pq->size == 0;  // Return 1 if the queue is empty, otherwise return 0
}

// Function to check if the priority queue is full
int pq_is_full(PriorityQueue *pq) {
    return pq->size == MAX_SIZE;  // Return 1 if the queue is full, otherwise return 0
}

// Function to insert an item into the priority queue
void pq_insert(PriorityQueue *pq, int item) {
    if (pq_is_full(pq)) {
        printf("Priority Queue is full!\n");
        return;
    }

    // Insert the item at the end of the array
    pq->arr[pq->size] = item;
    pq->size++;

    // Bubble up the inserted item to restore the max-heap property
    int i = pq->size - 1;
    while (i > 0 && pq->arr[(i - 1) / 2] < pq->arr[i]) {
        // Swap the current item with its parent if it's larger
        int temp = pq->arr[(i - 1) / 2];
        pq->arr[(i - 1) / 2] = pq->arr[i];
        pq->arr[i] = temp;
        i = (i - 1) / 2;  // Move to the parent index
    }
}

// Function to extract the maximum item (root of the heap)
int pq_extract_max(PriorityQueue *pq) {
    if (pq_is_empty(pq)) {
        printf("Priority Queue is empty!\n");
        return -1;  // Return -1 if the queue is empty
    }

    // The maximum item is at the root (index 0)
    int maxItem = pq->arr[0];

    // Move the last item to the root
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;

    // Restore the max-heap property by calling heapify
    int i = 0;
    while (2 * i + 1 < pq->size) {  // While the left child exists
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        // Find the largest among root, left child, and right child
        if (left < pq->size && pq->arr[left] > pq->arr[largest]) {
            largest = left;
        }
        if (right < pq->size && pq->arr[right] > pq->arr[largest]) {
            largest = right;
        }

        // If the largest element is not the root, swap it and heapify
        if (largest != i) {
            int temp = pq->arr[i];
            pq->arr[i] = pq->arr[largest];
            pq->arr[largest] = temp;
            i = largest;  // Move to the child index
        } else {
            break;
        }
    }

    return maxItem;
}

// Function to print the items in the priority queue
void pq_print(PriorityQueue *pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

// Main function to test the priority queue
int main() {
    PriorityQueue pq;
    pq_init(&pq);  // Initialize the priority queue

    // Insert items into the priority queue
    pq_insert(&pq, 20);
    pq_insert(&pq, 15);
    pq_insert(&pq, 30);
    pq_insert(&pq, 10);
    pq_insert(&pq, 50);

    printf("Priority Queue after insertions:\n");
    pq_print(&pq);  // Print the priority queue

    // Extract the maximum item from the priority queue
    printf("Extracted max item: %d\n", pq_extract_max(&pq));
    printf("Priority Queue after extraction:\n");
    pq_print(&pq);  // Print the priority queue after extraction

    return 0;
}
