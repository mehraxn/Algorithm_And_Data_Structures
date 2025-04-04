#include <stdio.h>
#include <stdlib.h>

typedef struct e {
    int key;                // The value stored in the node
    struct e *next;         // Pointer to the next node in the queue
} queue_t;

// Function to create a new element in the queue
queue_t* new_element() {
    queue_t *new_node = (queue_t*)malloc(sizeof(queue_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}

// Function to enqueue a new element into a circular queue
queue_t* enqueue(queue_t *tail, int val) {
    queue_t *new = new_element();  // Step 1: Create a new element
    new->key = val;

    if (tail == NULL) {
        // If the queue is empty, the new node points to itself
        tail = new;
        tail->next = tail;
    } else {
        // Step 2: Point the new node to the current head (tail->next)
        new->next = tail->next;
        // Step 3: Set the tail's next to the new node
        tail->next = new;
        // Step 4: Update the tail to the new node
        tail = new;
    }

    return tail;
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

    // Enqueue values into the queue
    tail = enqueue(tail, 10);
    tail = enqueue(tail, 20);
    tail = enqueue(tail, 30);

    // Print the queue
    printf("Circular Queue after enqueuing 10, 20, 30:\n");
    print_queue(tail);

    return 0;
}

/*
Explanation of Functions in the Code:

1. Struct Definition:
   - `typedef struct e` defines a linked list node structure (`queue_t`) used to represent each element in the circular queue.
   - Each node contains an integer `key` (the value stored in the node) and a pointer `next` to the next node in the queue.

2. new_element Function:
   - This function allocates memory for a new node.
   - If memory allocation fails, it prints an error message and exits the program.
   - Returns a pointer to the newly allocated node.

3. enqueue Function:
   - Adds a new element to the circular queue.
   - If the queue is empty, the new node points to itself and becomes the `tail` of the queue.
   - Otherwise, the new node is added between the `tail` and the `tail->next` (the current head), and the `tail` pointer is updated to the new node.
   - Returns the updated tail pointer of the queue.

4. print_queue Function:
   - Prints the entire circular queue starting from the head (`tail->next`) and loops until it reaches the starting point again.
   - If the queue is empty, it prints an appropriate message.

5. main Function:
   - Demonstrates the use of the enqueue function by adding three values (10, 20, 30) to the queue.
   - Calls `print_queue` to print the current state of the queue.
   - This function serves as an entry point to illustrate the functionality of the circular queue.
*/
