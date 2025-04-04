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
// Macro to get the index of the left child of the current node
#define LEFT(i) (2 * i + 1)
// Macro to get the index of the right child of the current node
#define RIGHT(i) (2 * i + 2)

// Function to compare two items, assumes max heap (larger values have higher priority)
int item_less(Item item1, Item item2) {
    return item1 < item2;
}

// Function to swap two items in the priority queue array
void swap(pq_t *pq, int i, int j) {
    Item temp = pq->A[i];
    pq->A[i] = pq->A[j];
    pq->A[j] = temp;
}

// Function to heapify the subtree rooted at index i in the heap
void heapify(pq_t *pq, int i) {
    int largest = i;
    int left = LEFT(i);
    int right = RIGHT(i);

    // If left child exists and is greater than the current largest
    if (left < pq->pqsize && item_less(pq->A[largest], pq->A[left])) {
        largest = left;
    }

    // If right child exists and is greater than the current largest
    if (right < pq->pqsize && item_less(pq->A[largest], pq->A[right])) {
        largest = right;
    }

    // If the largest element is not the root, swap and heapify the affected subtree
    if (largest != i) {
        swap(pq, i, largest);
        heapify(pq, largest);  // Recursively heapify the affected subtree
    }
}

// Function to initialize the priority queue
void pq_init(pq_t *pq, int capacity) {
    pq->A = (Item *)malloc(capacity * sizeof(Item));  // Allocate memory for the priority queue array
    pq->pqsize = 0;  // Initial size is 0
    pq->capacity = capacity;  // Set the capacity of the priority queue
}

// Function to insert an item into the priority queue
void pq_insert(pq_t *pq, Item item) {
    int i;

    // Insert the item at the end of the priority queue (array)
    i = pq->pqsize++;  // Increment the size of the priority queue

    // Move the item up to its correct position in the heap
    while (i >= 1 && item_less(pq->A[PARENT(i)], item)) {
        pq->A[i] = pq->A[PARENT(i)];  // Move the parent down to make space for the new item
        i = PARENT(i);  // Move to the parent index
    }

    // Place the item at the correct position
    pq->A[i] = item;
}

// Function to extract the maximum item (remove the root of the heap)
Item pq_extract_max(pq_t *pq) {
    Item item;

    // Swap the root with the last item
    swap(pq, 0, pq->pqsize - 1);

    // Extract the last item (which was originally the root)
    item = pq->A[pq->pqsize - 1];

    // Decrease the size of the heap (we've removed the last item)
    pq->pqsize--;

    // Restore the heap property by calling heapify
    heapify(pq, 0);

    return item;  // Return the extracted item
}

// Function to print the contents of the priority queue
void pq_print(pq_t *pq) {
    for (int i = 0; i < pq->pqsize; i++) {
        printf("%d ", pq->A[i]);
    }
    printf("\n");
}

// Function to change an item in the priority queue (either increase or decrease its value)
void pq_change(pq_t *pq, int i, Item item) {
    if (item_less(item, pq->A[i])) {
        decrease_key(pq, i, item);  // Decrease the value of the item
    } else {
        increase_key(pq, i, item);  // Increase the value of the item
    }
}

// Function to decrease the key of an item in the priority queue
void decrease_key(pq_t *pq, int i, Item item) {
    pq->A[i] = item;  // Set the item's value to the new value
    heapify(pq, i);    // Heapify the tree to restore the heap property
}

// Function to increase the key of an item in the priority queue
void increase_key(pq_t *pq, int i, Item item) {
    while (i >= 1 && item_less(pq->A[PARENT(i)], item)) {
        pq->A[i] = pq->A[PARENT(i)];  // Move the parent down
        i = PARENT(i);  // Move to the parent index
    }
    pq->A[i] = item;  // Set the item's value to the new value
}

// Main function for testing the priority queue and key change operations
int main() {
    pq_t pq;
    pq_init(&pq, 10);  // Initialize the priority queue with a capacity of 10

    // Insert some items into the priority queue
    pq_insert(&pq, 10);
    pq_insert(&pq, 20);
    pq_insert(&pq, 15);
    pq_insert(&pq, 30);
    pq_insert(&pq, 25);

    // Print the priority queue after insertions
    printf("Priority Queue after insertions:\n");
    pq_print(&pq);

    // Change the value of an item in the priority queue
    pq_change(&pq, 2, 5);  // Decrease key of item at index 2 to 5

    // Print the priority queue after the change
    printf("Priority Queue after changing an item:\n");
    pq_print(&pq);

    // Extract the maximum item (root of the heap)
    Item max_item = pq_extract_max(&pq);
    printf("Extracted max item: %d\n", max_item);

    // Print the priority queue after extraction
    printf("Priority Queue after extraction:\n");
    pq_print(&pq);

    // Free the allocated memory for the priority queue array
    free(pq.A);

    return 0;
}
