#include <stdio.h>
#include <stdlib.h>

typedef struct e {
    int key;                // The value stored in the node
    struct e *next;         // Pointer to the next node in the queue
} queue_t;

#define SUCCESS 1
#define FAILURE 0

// Function to create a new element in the queue
queue_t* new_element(int val) {
    queue_t *new_node = (queue_t*)malloc(sizeof(queue_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = val;
    new_node->next = NULL;
    return new_node;
}

// Function to enqueue a new element into a circular queue
queue_t* enqueue(queue_t *tail, int val) {
    queue_t *new = new_element(val);  // Create a new element with the given value

    if (tail == NULL) {
        // If the queue is empty, the new node points to itself
        tail = new;
        tail->next = tail;
    } else {
        // Point the new node to the current head (tail->next)
        new->next = tail->next;
        // Set the tail's next to the new node
        tail->next = new;
        // Update the tail to the new node
        tail = new;
    }

    return tail;
}

// Function to dequeue an element from a circular queue
queue_t* dequeue(queue_t *tail, int *val, int *status) {
    if (tail == NULL) {
        // If the queue is empty, set status to FAILURE
        *status = FAILURE;
        return NULL;
    }

    queue_t *old = tail->next;  // Step 1: Get the head node (tail->next)
    *val = old->key;            // Step 2: Retrieve the value from the head node

    if (old == tail) {
        // If the queue has only one element
        tail = NULL;
    } else {
        // Update the tail's next to skip the old head
        tail->next = old->next;
    }

    free(old);  // Step 3: Free the old head node
    *status = SUCCESS;  // Set status to SUCCESS

    return tail;  // Return the updated tail pointer
}

// Function to print the circular queue
void print_queue(queue_t *tail) {
    if (tail == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    queue_t *current = tail->next;  // Start from the head
    do {
        printf("%d -> ", current->key);
        current = current->next;
    } while (current != tail->next);
    printf("(back to head)\n");
}

int main() {
    queue_t *tail = NULL;  // Initialize the tail of the queue as NULL (empty queue)
    int val, status;

    // Enqueue values into the queue
    tail = enqueue(tail, 10);
    tail = enqueue(tail, 20);
    tail = enqueue(tail, 30);

    // Print the queue
    printf("Circular Queue after enqueuing 10, 20, 30:\n");
    print_queue(tail);

    // Dequeue a value from the queue
    tail = dequeue(tail, &val, &status);
    if (status == SUCCESS) {
        printf("Dequeued value: %d\n", val);
    } else {
        printf("Queue is empty, cannot dequeue.\n");
    }

    // Print the queue after dequeue
    printf("Circular Queue after dequeuing:\n");
    print_queue(tail);

    return 0;
}

/*
Explanation of Functions in the Code:

1. Struct Definition:
   - `typedef struct e` defines a linked list node structure (`queue_t`) used to represent each element in the circular queue.
   - Each node contains an integer `key` (the value stored in the node) and a pointer `next` to the next node in the queue.

2. new_element Function:
   - This function allocates memory for a new node and initializes it with a given value.
   - If memory allocation fails, it prints an error message and exits the program.

3. enqueue Function:
   - Adds a new element to the circular queue.
   - If the queue is empty, the new node points to itself and becomes the `tail` of the queue.
   - Otherwise, the new node is added after the current `tail` and the `tail` pointer is updated to the new node.

4. dequeue Function:
   - Removes an element from the front of the circular queue.
   - If the queue has only one element, it sets `tail` to `NULL`.
   - Otherwise, it updates the `tail->next` pointer to skip the old head and frees the old head node.
   - Returns the updated tail pointer and sets `status` to indicate success or failure.

5. print_queue Function:
   - Prints the entire circular queue starting from the head (`tail->next`) and loops until it reaches the starting point again.
   - If the queue is empty, it prints an appropriate message.

6. main Function:
   - Demonstrates the use of the enqueue and dequeue functions by adding and removing elements from the queue.
   - Calls `print_queue` to print the current state of the queue.
   - This function serves as an entry point to illustrate the functionality of the circular queue.
*/
