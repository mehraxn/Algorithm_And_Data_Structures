# Circular Queue Implementation in C

This project demonstrates the implementation of a **circular queue** in C, focusing on the `enqueue` and `dequeue` operations. The circular queue is implemented using a linked list structure, making it efficient for handling dynamic data.

## Overview

The code includes the following components:
1. **Node Structure**: Defines the structure of each node in the circular queue.
2. **New Element Function**: Dynamically allocates memory for new nodes.
3. **Enqueue Function**: Adds elements to the circular queue while maintaining the circular linkage.
4. **Dequeue Function**: Removes elements from the circular queue and updates pointers accordingly.
5. **Print Queue Function**: Prints all elements in the queue starting from the head.
6. **Main Function**: Demonstrates the enqueue and dequeue operations and prints the resulting state of the circular queue.

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

### 2. **New Element Function**
The `new_element` function creates a new node:
```c
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
```
- **Memory Allocation**: Allocates memory for a new node and initializes it with the given value.
- **Error Handling**: If memory allocation fails, it prints an error message and exits the program.

### 3. **Enqueue Function**
The `enqueue` function adds a new element to the circular queue:
```c
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
```
- **Adding Elements**: If the queue is empty, the new node points to itself. Otherwise, the new node is added after the current `tail`, and the `tail` pointer is updated.
- **Circular Link**: Maintains the circular nature of the queue by linking the new node back to the head.

### 4. **Dequeue Function**
The `dequeue` function removes an element from the front of the queue:
```c
queue_t* dequeue(queue_t *tail, int *val, int *status) {
    if (tail == NULL) {
        // If the queue is empty, set status to FAILURE
        *status = FAILURE;
        return NULL;
    }

    queue_t *old = tail->next;  // Get the head node (tail->next)
    *val = old->key;            // Retrieve the value from the head node

    if (old == tail) {
        // If the queue has only one element
        tail = NULL;
    } else {
        // Update the tail's next to skip the old head
        tail->next = old->next;
    }

    free(old);  // Free the old head node
    *status = SUCCESS;  // Set status to SUCCESS

    return tail;  // Return the updated tail pointer
}
```
- **Removing Elements**: Retrieves the value from the head node and frees the memory.
- **Updating Pointers**: Updates the `tail` to maintain the correct circular linkage.
- **Status Handling**: Sets `status` to indicate whether the operation was successful or if the queue was empty.

### 5. **Print Queue Function**
The `print_queue` function prints all elements in the circular queue:
```c
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
```
- **Starting from Head**: Begins printing from the head (`tail->next`) and continues until it reaches the starting point again.
- **Empty Queue**: Prints an appropriate message if the queue is empty.

### 6. **Main Function**
The `main` function demonstrates how to use the `enqueue` and `dequeue` functions:
```c
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
```
- **Initialization**: Initializes the circular queue as empty.
- **Enqueue Operations**: Adds values `10`, `20`, and `30` to the queue.
- **Dequeue Operation**: Removes an element from the front of the queue.
- **Print Queue**: Prints the state of the queue after each operation.

## How to Run
1. **Compile the Code**: Use a C compiler like GCC to compile the code:
   ```sh
   gcc -o circular_queue circular_queue.c
   ```
2. **Run the Executable**:
   ```sh
   ./circular_queue
   ```

## Notes
- **Circular Queue**: The circular queue is useful for applications that require buffering and cyclic data access, such as task scheduling or buffering in communication systems.
- **Memory Management**: Proper memory allocation and deallocation are handled in the code to prevent memory leaks.
- **Scalability**: The linked list-based implementation provides dynamic resizing, avoiding the fixed size limitation of array-based queues.

