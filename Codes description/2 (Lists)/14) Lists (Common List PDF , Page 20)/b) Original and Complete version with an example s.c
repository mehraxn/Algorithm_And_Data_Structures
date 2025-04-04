#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct e {
    int key;                // The value stored in the node
    struct e *next;         // Pointer to the next node in the queue
} queue_t;

// Function to enqueue a new element into the queue
queue_t* enqueue(queue_t *tail, int val) {
    queue_t *new_node = (queue_t*)malloc(sizeof(queue_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = val;
    new_node->next = NULL;

    if (tail == NULL) {
        // If the queue is empty, the new node is both the head and the tail
        return new_node;
    } else {
        // Add the new node at the end of the queue
        tail->next = new_node;
    }

    return new_node; // Return the new tail of the queue
}

// Function to dequeue an element from the queue
queue_t* dequeue(queue_t *head, int *val, int *status) {
    if (head == NULL) {
        // If the queue is empty, set status to FAILURE
        *status = FAILURE;
        return NULL;
    }

    *status = SUCCESS;      // Set status to SUCCESS
    *val = head->key;       // Store the value from the head node

    queue_t *temp = head;   // Store the head node to free later
    head = head->next;      // Update the head to the next element in the queue

    free(temp);             // Free the old head node

    return head;            // Return the new head of the queue
}

// Function to print the queue
void print_queue(queue_t *head) {
    queue_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    queue_t *head = NULL;  // Initialize the head of the queue as NULL (empty queue)
    queue_t *tail = NULL;  // Initialize the tail of the queue as NULL
    int val, status;

    do {
        // Enqueue values into the queue
        tail = enqueue(tail, 10);
        if (head == NULL) head = tail; // Update head if queue was empty
        tail = enqueue(tail, 20);
        tail = enqueue(tail, 30);

        // Print the queue
        printf("Queue after enqueuing 10, 20, 30:\n");
        print_queue(head);

        // Dequeue a value from the queue
        head = dequeue(head, &val, &status);
        if (status == SUCCESS) {
            printf("Dequeued value: %d\n", val);
        } else {
            printf("Queue is empty, cannot dequeue.\n");
        }

        // Print the queue after dequeue
        printf("Queue after dequeuing:\n");
        print_queue(head);
    } while (status == SUCCESS);

    // Free the allocated memory
    queue_t *current = head;
    queue_t *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
