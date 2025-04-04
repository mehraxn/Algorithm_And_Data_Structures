# Linked List Pop Function

This project demonstrates the implementation of a **linked list stack** in C, using `push` and `pop` operations. The `push` function adds an element to the top of the stack, while the `pop` function removes and returns the top element, making it behave like a stack (last-in, first-out).

## Overview

The main components of the code include:
1. **Node Structure**: Defines the linked list node, which contains an integer value and a pointer to the next node.
2. **Push Function**: Adds a new element to the top of the linked list.
3. **Pop Function**: Removes the top element from the linked list and returns its value.
4. **Print Function**: Utility function to print all elements of the linked list.
5. **Main Function**: Demonstrates the usage of the push and pop functions and prints the resulting linked list.

## Code Structure

### 1. **Node Structure**
The `list_t` structure represents a linked list node:
```c
typedef struct list {
    int key;                // The value stored in the node
    struct list *next;      // Pointer to the next node in the list
} list_t;
```
Each node contains:
- `key`: The value stored in the node.
- `next`: A pointer to the next node in the linked list.

### 2. **Push Function**
The `push` function adds a new element to the top of the list:
```c
list_t* push(list_t *top, int val) {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = val;
    new_node->next = top;
    return new_node;
}
```
- **Allocate New Node**: A new node is created and assigned the given value (`val`).
- **Link to Top**: The new node's `next` pointer is set to the current top of the list.
- **Update Top**: The `top` pointer is updated to point to the new node.
- The function returns the updated top of the list.

### 3. **Pop Function**
The `pop` function removes the top element from the list and returns its value:
```c
list_t* pop(list_t *top, int *val, int *status) {
    list_t *old;                // Pointer to hold the node being removed

    if (top != NULL) {          // Check if the list is not empty
        *status = SUCCESS;      // Set status to SUCCESS
        *val = top->key;        // Store the value of the top node

        // Step 1: Store the top node in old pointer
        old = top;
        
        // Step 2: Update top to point to the next node
        top = top->next;
        
        // Step 3: Free the old top node
        free(old);
    } else {
        *status = FAILURE;      // Set status to FAILURE if the list is empty
    }

    return top;                 // Return the new top of the list
}
```
- **Check if Empty**: If the list is empty, `status` is set to `FAILURE`, and the function returns the unchanged top pointer.
- **Store and Update**: If the list is not empty, the top value is stored, the top pointer is updated, and the old top node is freed.
- The function returns the updated top pointer and sets `status` to indicate success or failure.

### 4. **Print List Function**
The `print_list` function prints all elements in the linked list:
```c
void print_list(list_t *top) {
    list_t *current = top;
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}
```
This function traverses the linked list from the `top` and prints each node's value until it reaches the end (`NULL`).

### 5. **Main Function**
The `main` function demonstrates how to use the `push` and `pop` functions:
```c
int main() {
    list_t *top = NULL;    // Initialize the top of the list as NULL (empty list)
    int val, status;

    // Push values onto the list
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    // Print the linked list
    printf("Stack after pushing 30, 20, 10:\n");
    print_list(top);

    // Pop a value from the stack
    top = pop(top, &val, &status);
    if (status == SUCCESS) {
        printf("Popped value: %d\n", val);
    } else {
        printf("Stack is empty, cannot pop.\n");
    }

    // Print the linked list after pop
    printf("Stack after popping:\n");
    print_list(top);

    // Free the allocated memory
    list_t *current = top;
    list_t *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
```
- **Initialization**: The linked list is initially empty (`top = NULL`).
- **Push Operations**: The `push` function is called three times to add values `10`, `20`, and `30` to the list.
- **Print the List**: The `print_list` function prints the current state of the linked list.
- **Pop Operation**: The `pop` function removes the top value from the list and prints it.
- **Free Memory**: The allocated memory for all nodes is freed before exiting the program to prevent memory leaks.

## How to Run
1. **Compile the Code**: Use a C compiler like GCC to compile the code:
   ```sh
   gcc -o linked_list_pop linked_list_pop.c
   ```
2. **Run the Executable**:
   ```sh
   ./linked_list_pop
   ```

## Notes
- The **push** and **pop** functions allow the linked list to behave like a stack, where new elements are added and removed from the top (last-in, first-out).
- **Memory Management**: Proper memory deallocation is included to prevent memory leaks, which is crucial when dynamically allocating memory in C.
- The code is designed to demonstrate a simple stack-like linked list structure and serves as a basis for more advanced data structure operations.

