# Queue & Dequeue Implementation in C

This project demonstrates a **queue implementation** in C, featuring `enqueue` and `dequeue` operations. A queue is a data structure that follows the **First-In, First-Out (FIFO)** principle, where elements are added at the back and removed from the front.

## Overview

The code includes the following components:
1. **Node Structure**: Defines the structure of each node in the queue, which contains an integer value and a pointer to the next node.
2. **Enqueue Function**: Adds a new element to the back of the queue.
3. **Dequeue Function**: Removes an element from the front of the queue and returns its value.
4. **Print Function**: Prints all elements currently in the queue.
5. **Main Function**: Demonstrates the usage of enqueue and dequeue operations in a loop until the queue is empty.

## Code Structure

### 1. **Node Structure**
The `queue_t` structure represents a node in the queue:
```c
typedef struct e {
    int key;                // The value stored in the node
    struct e *next;         // Pointer to the next node in the queue
} queue_t;
```
Each node contains:
- `key`: The value stored in the node.
- `next`: A pointer to the next node in the queue.

### 2. **Enqueue Function**
The `enqueue` function adds a new element to the back of the queue:
```c
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
```
- **Allocate New Node**: A new node is created and assigned the value `val`.
- **Add to Queue**: If the queue is empty, the new node becomes both the head and the tail. Otherwise, it is added to the end of the queue.

### 3. **Dequeue Function**
The `dequeue` function removes an element from the front of the queue and returns its value:
```c
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
```
- **Check if Empty**: If the queue is empty, the `status` is set to `FAILURE`.
- **Remove Head**: If the queue is not empty, the value of the head node is stored, and the head pointer is updated to point to the next node.

### 4. **Print Queue Function**
The `print_queue` function prints all elements in the queue:
```c
void print_queue(queue_t *head) {
    queue_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}
```
This function traverses the queue from the `head` and prints each node's value until it reaches the end (`NULL`).

### 5. **Main Function**
The `main` function demonstrates how to use the `enqueue` and `dequeue` functions in a loop:
```c
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
```
- **Initialization**: The queue is initially empty (`head = NULL`, `tail = NULL`).
- **Enqueue Operations**: The `enqueue` function is called multiple times to add values `10`, `20`, and `30` to the queue.
- **Print the Queue**: The current state of the queue is printed after each operation.
- **Dequeue Operations**: The `dequeue` function removes values from the front of the queue until it becomes empty.
- **Free Memory**: The allocated memory for all nodes is freed before exiting the program to prevent memory leaks.

## How to Run
1. **Compile the Code**: Use a C compiler like GCC to compile the code:
   ```sh
   gcc -o queue_implementation queue_implementation.c
   ```
2. **Run the Executable**:
   ```sh
   ./queue_implementation
   ```

## Notes
- The **enqueue** and **dequeue** functions implement a simple queue data structure that follows the FIFO (First-In, First-Out) principle.
- **Memory Management**: Proper memory deallocation is included to prevent memory leaks, which is crucial when dynamically allocating memory in C.
- The code serves as a basis for learning and understanding queue operations and can be expanded for more complex use cases.

