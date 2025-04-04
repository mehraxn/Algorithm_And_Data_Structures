# README: Linked List Sorting in C

## Overview

This project demonstrates the sorting of a simple linked list in C. The code provides functions to create nodes, pop nodes from a linked list, insert nodes into a sorted linked list, sort a linked list, and print the list. The `list_sort()` function is the key function that takes an existing linked list and sorts its elements in ascending order.

### Files Included

- `linked_list_sort.c`: Contains the implementation of the linked list sorting, including node creation, sorting, and list printing functions.

## Data Structures

### 1. Struct Definition

The linked list node is defined using the `list_s` structure (`list_t`).

- **Fields**:
  - `int key`: Stores the value of the node.
  - `list_t *next`: Pointer to the next node in the linked list.

## Functions

### 1. create_node(int key)

The `create_node()` function is responsible for creating and initializing a new linked list node.

- **Parameters**:
  - `int key`: The value to be stored in the new node.
- **Return Value**: Returns a pointer to the newly created linked list node (`list_t*`).
- **Implementation Details**: Allocates memory for the new node and initializes the key and `next` pointer to `NULL`. If memory allocation fails, the program exits with an error message.

### 2. pop(list_t **head, list_t **node)

The `pop()` function removes a node from the front of the linked list.

- **Parameters**:
  - `list_t **head`: A double pointer to the head of the linked list.
  - `list_t **node`: A double pointer to store the node that is removed.
- **Implementation Details**: The function updates the head pointer to point to the next node and sets the `next` pointer of the removed node to `NULL`. If the list is empty, the `node` is set to `NULL`.

### 3. insert(list_t *head, list_t *node)

The `insert()` function inserts a node into a sorted linked list while maintaining the sorted order.

- **Parameters**:
  - `list_t *head`: The head of the sorted linked list.
  - `list_t *node`: The node to be inserted into the linked list.
- **Return Value**: Returns the updated head of the sorted linked list (`list_t*`).
- **Implementation Details**: If the list is empty or if the node should be inserted at the beginning, it is directly linked as the new head. Otherwise, the function traverses the list to find the correct position and inserts the node while maintaining the sorted order.

### 4. list_sort(list_t *head1)

The `list_sort()` function sorts the linked list by extracting nodes from the original list and inserting them into a new sorted list.

- **Parameters**:
  - `list_t *head1`: The head of the linked list to be sorted.
- **Return Value**: Returns the head pointer of the sorted linked list (`list_t*`).
- **Implementation Details**: The function iteratively pops nodes from the original list (`head1`) and inserts them into a new sorted list (`head2`). This results in the linked list being sorted in ascending order.

### 5. print_list(list_t *head)

The `print_list()` function prints all elements of the linked list from the head to the end (`NULL`).

- **Parameters**:
  - `list_t *head`: The head of the linked list.
- **Implementation Details**: The function traverses each node of the linked list, printing its key until reaching the end.

### 6. main()

The `main()` function demonstrates the creation, sorting, and printing of the linked list.

- **Implementation Details**:
  - Initializes an empty linked list.
  - Inserts values into the list using `create_node()` to create a simple linked list: `30 -> 17 -> 21 -> 9 -> NULL`.
  - Prints the original linked list using `print_list()`.
  - Sorts the linked list using `list_sort()` and prints the sorted list.
  - Frees all allocated memory to avoid memory leaks.

## Usage Instructions

1. **Compilation**:
   - Use the following command to compile the code:
     ```sh
     gcc -o linked_list_sort linked_list_sort.c
     ```
   - This will produce an executable named `linked_list_sort`.

2. **Running the Program**:
   - Run the program using:
     ```sh
     ./linked_list_sort
     ```
   - The program will create a linked list, print the original list, sort it, print the sorted list, and then deallocate all allocated memory.

## Example Output

When you run the program, it will produce the following output:

```
Original List:
30 -> 17 -> 21 -> 9 -> NULL
Sorted List:
9 -> 17 -> 21 -> 30 -> NULL
```

## Memory Management

- **Dynamic Allocation**: Memory is dynamically allocated for each linked list node using `malloc()`.
- **Proper Memory Deallocation**: After all operations, the program frees the remaining nodes using `free()` to prevent memory leaks.
- **Error Handling**: Proper checks are performed to ensure that memory allocation is successful. If memory allocation fails, an error message is printed, and the program exits.

## Key Concepts Demonstrated

- **Linked List Sorting**: Sorting a linked list by extracting each node from the original list and inserting it into a new sorted list.
- **Dynamic Memory Management**: Allocating and deallocating memory dynamically, handling errors appropriately, and ensuring proper memory cleanup.
- **Linked List Operations**: Creating, sorting, and printing linked list structures.

## Notes

- The values inserted into the linked list can be modified as needed to test different scenarios.
- The code is intended for educational purposes, demonstrating basic linked list operations, dynamic memory management, and linked list sorting in C.

## Dependencies

- **Standard Libraries**: The code uses the following standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For dynamic memory management functions such as `malloc()` and `free()`.

## License

This code is provided as-is for educational purposes. Feel free to modify and use it in your projects, but please note that no warranty is provided.