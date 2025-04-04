#include <stdio.h>
#include <stdlib.h>

// Define a structure for the priority queue
typedef struct {
    Item *A;           // Array to store the items in the priority queue
    int pqsize;        // Current number of items in the priority queue
    int capacity;      // Maximum capacity of the priority queue
} pq_t;

// Define the Item type (assuming it's an integer for simplicity)
typedef int Item;

// Macro to get the index of the parent of the current node
#define PARENT(i) ((i - 1) / 2)

// Function to compare two items, assumes max heap (larger values have higher priority)
int item_less(Item item1, Item item2) {
    return item1 < item2;
}

// Function to insert an item into the priority queue
void pq_insert(pq_t *pq, Item item) {
    int i;

    // Insert the item at the end of the priority queue (array)
    i = pq->pqsize++;  // Increment the size of the priority queue

    // Move the item up to its correct position in the heap
    // The item will be moved up the heap as long as it is larger than its parent
    while (i >= 1 && item_less(pq->A[PARENT(i)], item)) {
        pq->A[i] = pq->A[PARENT(i)];  // Move the parent down to make space for the new item
        i = PARENT(i);  // Move to the parent index
    }

    // Place the item at the correct position
    pq->A[i] = item;

    return;
}

// Function to initialize the priority queue
void pq_init(pq_t *pq, int capacity) {
    pq->A = (Item *)malloc(capacity * sizeof(Item));  // Allocate memory for the priority queue array
    pq->pqsize = 0;  // Initial size is 0
    pq->capacity = capacity;  // Set the capacity of the priority queue
}

// Function to print the contents of the priority queue
void pq_print(pq_t *pq) {
    for (int i = 0; i < pq->pqsize; i++) {
        printf("%d ", pq->A[i]);
    }
    printf("\n");
}

// Main function for testing the priority queue insert operation
int main() {
    pq_t pq;
    pq_init(&pq, 10);  // Initialize the priority queue with a capacity of 10

    // Insert some items into the priority queue
    pq_insert(&pq, 10);
    pq_insert(&pq, 20);
    pq_insert(&pq, 15);
    pq_insert(&pq, 30);
    pq_insert(&pq, 25);

    // Print the priority queue after inserting items
    printf("Priority Queue after insertions:\n");
    pq_print(&pq);

    // Free the allocated memory for the priority queue array
    free(pq.A);

    return 0;
}
