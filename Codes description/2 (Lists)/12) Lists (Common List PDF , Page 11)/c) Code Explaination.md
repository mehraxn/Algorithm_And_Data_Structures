# Linked List Push Function

This project demonstrates the implementation of a **linked list push function** in C. The push function adds an element to the top of a linked list, similar to adding an element to the top of a stack.

## Overview

The main components of the code include:
1. **Node Structure**: Defines the linked list node, which contains an integer value and a pointer to the next node.
2. **Node Creation**: Function to create a new node, dynamically allocating memory for it.
3. **Push Function**: Adds a new element to the top of the linked list.
4. **Print Function**: Utility function to print all elements of the linked list.
5. **Main Function**: Demonstrates the usage of the push function to add elements and prints the resulting linked list.

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

### 2. **Node Creation Function**
The `new_element` function creates a new node:
```c
list_t* new_element() {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}
```
This function allocates memory for a new node. If memory allocation fails, it prints an error message and exits the program.

### 3. **Push Function**
The `push` function adds a new element to the top of the list:
```c
list_t* push(list_t *top, int val) {
    list_t *new;               // Pointer for the new node
    new = new_element();       // Allocate memory for the new node

    new->key = val;            // Set the value for the new node
    new->next = top;           // Link the new node to the current top
    top = new;                 // Update the top to point to the new node

    return top;                // Return the new top of the list
}
```
- **Allocate New Node**: A new node is created and assigned the given value (`val`).
- **Link to Top**: The new node's `next` pointer is set to the current top of the list.
- **Update Top**: The `top` pointer is updated to point to the new node.
- The function returns the updated top of the list.

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
The `main` function demonstrates how to use the `push` function:
```c
int main() {
    list_t *top = NULL;    // Initialize the top of the list as NULL (empty list)

    // Push values onto the list
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    // Print the linked list
    printf("Stack after pushing 30, 20, 10:\n");
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
- **Free Memory**: The allocated memory for all nodes is freed before exiting the program to prevent memory leaks.

## How to Run
1. **Compile the Code**: Use a C compiler like GCC to compile the code:
   ```sh
   gcc -o linked_list_push linked_list_push.c
   ```
2. **Run the Executable**:
   ```sh
   ./linked_list_push
   ```

## Notes
- The **push function** behaves like adding elements to a stack, where new elements are always added at the top (last-in, first-out).
- **Memory Management**: The program includes proper memory deallocation to avoid memory leaks, which is important in C programming when dynamically allocating memory.
- The code is designed to demonstrate a simple stack-like linked list structure and serves as a foundation for more advanced data structure operations.

