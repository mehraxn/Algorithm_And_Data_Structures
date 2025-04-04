# README: Linked List Insert and Extract Functions

## Overview

This project demonstrates the creation, insertion, extraction (removal), and visualization of elements in a sorted linked list in C. The code provides various functions to manage linked list operations, including inserting new elements into a sorted list, extracting elements, and printing the linked list. This README provides details on the usage, functionality, and memory management practices implemented in the code.

### Files Included

- `linkedlist_functions.c`: Contains the implementation of the linked list node structure and the functions to create, insert, extract, and print nodes.

## Functions

### 1. Struct Definition

The linked list node is defined using a structure (`list_t`).
- **Fields**:
  - `int key`: Stores the value of the node.
  - `list_t *next`: Pointer to the next node in the linked list.

### 2. new_element(int val)

The `new_element()` function is responsible for creating and initializing a new linked list node.
- **Parameters**:
  - `int val`: The value to be stored in the new node.

- **Return Value**: Returns a pointer to the newly created node (`list_t*`).

- **Implementation Details**:
  - Allocates memory for the new node.
  - Initializes the value (`key`) and sets the `next` pointer to `NULL`.
  - If memory allocation fails, an error message is printed and the program exits.

### 3. insert(list_t *head, int val)

The `insert()` function inserts a new element into the sorted linked list, ensuring that the list remains sorted.
- **Parameters**:
  - `list_t *head`: The head of the linked list.
  - `int val`: The value to be inserted into the linked list.

- **Return Value**: Returns the updated head of the linked list.

- **Implementation Details**:
  - Creates a new node using the `new_element()` function.
  - If the list is empty or if the value is smaller than the head node's value, the new node is inserted at the beginning and becomes the new head.
  - If the value is larger, the function traverses the list to find the correct position for insertion.
  - Updates the pointers to insert the new node in the appropriate position.

### 4. extract(list_t *head, int val)

The `extract()` function is used to remove a node with the specified value from the linked list.
- **Parameters**:
  - `list_t *head`: The head of the linked list.
  - `int val`: The value to be removed from the linked list.

- **Return Value**: Returns the updated head of the linked list.

- **Implementation Details**:
  - If the list is empty, an error message is printed.
  - If the value to be removed is the head node, the function updates the head pointer and frees the memory of the removed node.
  - If the value is found further down the list, the function traverses the list, updates the pointers, and frees the removed node.
  - If the value is not found, an error message is printed.

### 5. print_list(list_t *head)

The `print_list()` function is used to print all the elements of the linked list from the head to the end.
- **Parameters**:
  - `list_t *head`: The head of the linked list.

- **Implementation Details**:
  - Iterates through the linked list and prints each node's value until reaching the end (`NULL`).

### 6. main()

The `main()` function demonstrates the use of the `insert()`, `extract()`, and `print_list()` functions.
- **Implementation Details**:
  - Initializes an empty linked list.
  - Inserts values into the linked list in a sorted manner.
  - Prints the linked list after insertions.
  - Extracts a specific value and prints the linked list after extraction.
  - Attempts to extract a non-existent value and prints an appropriate message.
  - Frees all remaining nodes in the list to avoid memory leaks.

## Usage Instructions

1. **Compilation**:
   - Use the following command to compile the code:
     ```sh
     gcc -o linkedlist_functions linkedlist_functions.c
     ```
   - This will produce an executable named `linkedlist_functions`.

2. **Running the Program**:
   - Run the program using:
     ```sh
     ./linkedlist_functions
     ```
   - The program will insert elements into a sorted linked list, extract values, and print the resulting linked list after each operation.

## Example Output

When you run the program, it will produce the following output:

```
Sorted Linked List after insertions:
10 -> 20 -> 25 -> 30 -> NULL
Sorted Linked List after extracting 20:
10 -> 25 -> 30 -> NULL
Error: value not found in the list
Sorted Linked List after attempting to extract 40:
10 -> 25 -> 30 -> NULL
```

## Memory Management

- **Dynamic Allocation**: Memory is dynamically allocated for each node using `malloc()`.
- **Proper Memory Deallocation**: After all operations, the program frees the remaining nodes in the linked list using `free()` to prevent memory leaks.
- **Error Handling**: Proper checks are performed to ensure that memory allocation is successful. If memory allocation fails, an error message is printed and the program exits to prevent further issues.

## Key Concepts Demonstrated

- **Sorted Linked List Insertion**: Inserting elements into a linked list while maintaining sorted order.
- **Node Extraction**: Removing a node with a specific value from a linked list.
- **Dynamic Memory Management**: Allocating and deallocating memory dynamically, handling errors appropriately, and ensuring proper memory cleanup.

## Notes

- The values inserted and extracted in the example can be modified as needed to test different scenarios.
- The code is intended for educational purposes, demonstrating basic linked list operations, dynamic memory management, and error handling in C.

## Dependencies

- **Standard Libraries**: The code uses the following standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For dynamic memory management functions such as `malloc()` and `free()`.

## License

This code is provided as-is for educational purposes. Feel free to modify and use it in your projects, but please note that no warranty is provided.

