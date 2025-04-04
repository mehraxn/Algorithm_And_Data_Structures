# README: Linked List Reversal in C

## Overview

This project demonstrates the reversal of a simple linked list in C. The code provides various functions to create nodes, reverse the linked list, and print the list. The `list_reverse()` function is the key function that takes an existing linked list and reverses its order such that the first element becomes the last, and the last element becomes the first.

### Files Included

- `linked_list_reverse.c`: Contains the implementation of the linked list reversal, including node creation, reversal, and list printing functions.

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

### 2. list_reverse(list_t *head1)

The `list_reverse()` function is used to reverse the linked list.

- **Parameters**:
  - `list_t *head1`: The head of the linked list to be reversed.
- **Return Value**: Returns the head pointer of the reversed linked list (`list_t*`).
- **Implementation Details**: The function iteratively extracts nodes from the original linked list (`head1`) and inserts them at the beginning of a new linked list (`head2`). This process effectively reverses the linked list.

### 3. print_list(list_t *head)

The `print_list()` function prints all elements of the linked list from the head to the end (`NULL`).

- **Parameters**:
  - `list_t *head`: The head of the linked list.
- **Implementation Details**: The function traverses each node of the linked list, printing its key until reaching the end.

### 4. main()

The `main()` function demonstrates the creation, reversal, and printing of the linked list.

- **Implementation Details**:
  - Initializes an empty linked list.
  - Inserts values into the list using `create_node()` to create a simple linked list: `30 -> 17 -> 21 -> 9 -> NULL`.
  - Prints the original linked list using `print_list()`.
  - Reverses the linked list using `list_reverse()` and prints the reversed list.
  - Frees all allocated memory to avoid memory leaks.

## Usage Instructions

1. **Compilation**:
   - Use the following command to compile the code:
     ```sh
     gcc -o linked_list_reverse linked_list_reverse.c
     ```
   - This will produce an executable named `linked_list_reverse`.

2. **Running the Program**:
   - Run the program using:
     ```sh
     ./linked_list_reverse
     ```
   - The program will create a linked list, print the original list, reverse it, print the reversed list, and then deallocate all allocated memory.

## Example Output

When you run the program, it will produce the following output:

```
Original List:
30 -> 17 -> 21 -> 9 -> NULL
Reversed List:
9 -> 21 -> 17 -> 30 -> NULL
```

## Memory Management

- **Dynamic Allocation**: Memory is dynamically allocated for each linked list node using `malloc()`.
- **Proper Memory Deallocation**: After all operations, the program frees the remaining nodes using `free()` to prevent memory leaks.
- **Error Handling**: Proper checks are performed to ensure that memory allocation is successful. If memory allocation fails, an error message is printed, and the program exits.

## Key Concepts Demonstrated

- **Linked List Reversal**: Reversing a linked list by iteratively extracting each node from the original list and inserting it into a new list.
- **Dynamic Memory Management**: Allocating and deallocating memory dynamically, handling errors appropriately, and ensuring proper memory cleanup.
- **Linked List Operations**: Creating, reversing, and printing linked list structures.

## Notes

- The values inserted into the linked list can be modified as needed to test different scenarios.
- The code is intended for educational purposes, demonstrating basic linked list operations, dynamic memory management, and linked list reversal in C.

## Dependencies

- **Standard Libraries**: The code uses the following standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For dynamic memory management functions such as `malloc()` and `free()`.

## License

This code is provided as-is for educational purposes. Feel free to modify and use it in your projects, but please note that no