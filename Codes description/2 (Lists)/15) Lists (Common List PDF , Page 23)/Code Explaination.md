# Circular Queue Enqueue Function in C

This project demonstrates the implementation of a **circular queue** in C, focusing on the `enqueue` operation and providing a way to visualize the queue using a linked list structure. A circular queue is a data structure where the end of the queue connects back to the beginning, making it efficient for cyclic data handling.

## Overview

The code includes the following components:
1. **Node Structure**: Defines the structure of each node in the circular queue.
2. **New Element Function**: Dynamically allocates memory for new nodes.
3. **Enqueue Function**: Adds elements to the circular queue while maintaining the circular linkage.
4. **Print Queue Function**: Prints all elements in the queue starting from the head.
5. **Main Function**: Demonstrates the enqueue operation and the state of the circular queue.

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
queue_t* new_element() {
    queue_t *new_node = (queue_t*)malloc(sizeof(queue_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}
```
- **Memory Allocation**: Allocates memory for a new node and returns a pointer to it.
- **Error Handling**: If memory allocation fails, it prints an error message and exits the program.

### 3. **Enqueue Function**
The `enqueue` function adds a new element to the circular queue:
```c
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
```
- **Adding Elements**: If the queue is empty, the new node points to itself. Otherwise, the new node is added after the current `tail` and the `tail` pointer is updated.
- **Circular Link**: The new element maintains the circular nature of the queue by pointing back to the head.

### 4. **Print Queue Function**
The `print_queue` function prints all elements in the queue:
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
- **Starting from Head**: Begins printing from the head (`tail->next`) and continues until the queue wraps back to the head.
- **Empty Queue**: If the queue is empty, it prints an appropriate message.

### 5. **Main Function**
The `main` function demonstrates how to use the `enqueue` function:
```c
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
```
- **Initialization**: The circular queue is initially empty (`tail = NULL`).
- **Enqueue Operations**: The `enqueue` function is called to add values `10`, `20`, and `30` to the queue.
- **Print the Queue**: The `print_queue` function prints the current state of the queue to visualize the circular linkage.

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
- **Circular Queue**: The circular queue is useful for applications that require buffering and cyclic data access, such as in scheduling or buffering.
- **Memory Management**: The current version of the code does not include memory deallocation for simplicity. In a complete implementation, it would be necessary to free allocated nodes to prevent memory leaks.
- **Scalability**: The current implementation uses a linked list to provide dynamic resizing of the queue, which avoids the need for a fixed size compared to an array-based implementation.

