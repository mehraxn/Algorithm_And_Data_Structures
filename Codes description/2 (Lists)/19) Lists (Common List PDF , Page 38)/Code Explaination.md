# README: Doubly Linked List Example

## Overview

This project demonstrates the creation, insertion, removal, and traversal of elements in a doubly linked list in C. The code provides various functions to manage doubly linked list operations, including inserting new elements, removing elements, and printing the list in both forward and backward directions. This README provides details on the functionality, usage, and memory management practices implemented in the code.

### Files Included

- `doubly_linked_list_example.c`: Contains the implementation of the doubly linked list node structure and the functions to create, insert, remove, and print nodes.

## Functions

### 1. Struct Definition

The doubly linked list node is defined using a structure (`list_t`).
- **Fields**:
  - `int key`: Stores the value of the node.
  - `list_t *left`: Pointer to the previous node in the linked list.
  - `list_t *right`: Pointer to the next node in the linked list.

### 2. create_node(int key)

The `create_node()` function is responsible for creating and initializing a new doubly linked list node.
- **Parameters**:
  - `int key`: The value to be stored in the new node.

- **Return Value**: Returns a pointer to the newly created node (`list_t*`).

- **Implementation Details**:
  - Allocates memory for the new node.
  - Initializes the value (`key`) and sets the `left` and `right` pointers to `NULL`.
  - If memory allocation fails, an error message is printed and the program exits.

### 3. insert_end(list_t *head, int key)

The `insert_end()` function inserts a new node at the end of the doubly linked list.
- **Parameters**:
  - `list_t *head`: The head of the doubly linked list.
  - `int key`: The value to be inserted into the linked list.

- **Return Value**: Returns the updated head of the doubly linked list.

- **Implementation Details**:
  - Creates a new node using the `create_node()` function.
  - If the list is empty, the new node becomes the head.
  - Otherwise, the function traverses the list to find the last node and inserts the new node at the end.
  - Updates the pointers to link the new node appropriately.

### 4. remove_node(list_t *head, int key)

The `remove_node()` function is used to remove a node with the specified value from the doubly linked list.
- **Parameters**:
  - `list_t *head`: The head of the doubly linked list.
  - `int key`: The value to be removed from the linked list.

- **Return Value**: Returns the updated head of the doubly linked list.

- **Implementation Details**:
  - If the list is empty, an error message is printed.
  - If the value to be removed is the head, the function updates the head pointer and adjusts the next node's `left` pointer.
  - If the value is found further down the list, the function updates the pointers of the adjacent nodes and frees the memory of the removed node.
  - If the value is not found, an error message is printed.

### 5. print_list_forward(list_t *head)

The `print_list_forward()` function prints all the elements of the doubly linked list from the head to the end.
- **Parameters**:
  - `list_t *head`: The head of the doubly linked list.

- **Implementation Details**:
  - Iterates through the linked list from the head to the end, printing each node's value.

### 6. print_list_backward(list_t *head)

The `print_list_backward()` function prints all the elements of the doubly linked list from the tail to the head.
- **Parameters**:
  - `list_t *head`: The head of the doubly linked list.

- **Implementation Details**:
  - Traverses to the last node of the list and then iterates backward, printing each node's value.

### 7. main()

The `main()` function demonstrates the use of the `insert_end()`, `remove_node()`, `print_list_forward()`, and `print_list_backward()` functions.
- **Implementation Details**:
  - Initializes an empty doubly linked list.
  - Inserts values into the list at the end.
  - Prints the list in both forward and backward directions after insertions.
  - Removes a specific value and prints the list again in both directions.
  - Attempts to remove a non-existent value and prints an appropriate message.
  - Frees all remaining nodes in the list to avoid memory leaks.

## Usage Instructions

1. **Compilation**:
   - Use the following command to compile the code:
     ```sh
     gcc -o doubly_linked_list_example doubly_linked_list_example.c
     ```
   - This will produce an executable named `doubly_linked_list_example`.

2. **Running the Program**:
   - Run the program using:
     ```sh
     ./doubly_linked_list_example
     ```
   - The program will insert elements into a doubly linked list, remove values, and print the resulting list in both forward and backward directions after each operation.

## Example Output

When you run the program, it will produce the following output:

```
Doubly Linked List after insertions:
List (forward): 10 <-> 20 <-> 30 <-> 40 <-> NULL
List (backward): 40 <-> 30 <-> 20 <-> 10 <-> NULL
Doubly Linked List after removing 20:
List (forward): 10 <-> 30 <-> 40 <-> NULL
List (backward): 40 <-> 30 <-> 10 <-> NULL
Error: value not found in the list
Doubly Linked List after attempting to remove 50:
List (forward): 10 <-> 30 <-> 40 <-> NULL
List (backward): 40 <-> 30 <-> 10 <-> NULL
```

## Memory Management

- **Dynamic Allocation**: Memory is dynamically allocated for each node using `malloc()`.
- **Proper Memory Deallocation**: After all operations, the program frees the remaining nodes in the doubly linked list using `free()` to prevent memory leaks.
- **Error Handling**: Proper checks are performed to ensure that memory allocation is successful. If memory allocation fails, an error message is printed, and the program exits to prevent further issues.

## Key Concepts Demonstrated

- **Doubly Linked List Insertion**: Inserting elements at the end of a doubly linked list.
- **Node Removal**: Removing a node with a specific value from the list while properly updating the adjacent nodes' pointers.
- **Traversal in Both Directions**: Printing the elements of the doubly linked list both forward (head to tail) and backward (tail to head).
- **Dynamic Memory Management**: Allocating and deallocating memory dynamically, handling errors appropriately, and ensuring proper memory cleanup.

## Notes

- The values inserted and removed in the example can be modified as needed to test different scenarios.
- The code is intended for educational purposes, demonstrating basic doubly linked list operations, dynamic memory management, and error handling in C.

## Dependencies

- **Standard Libraries**: The code uses the following standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For dynamic memory management functions such as `malloc()` and `free()`.

## License

This code is provided as-is for educational purposes. Feel free to modify and use it in your projects, but please note that no warranty is provided.

