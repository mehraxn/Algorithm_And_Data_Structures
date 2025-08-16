# README: List of Lists Example in C

## Overview

This project demonstrates the creation, insertion, and traversal of a data structure called a "list of lists" in C. The implementation includes two types of linked lists: `list_s1` and `list_s2`, where `list_s1` is a list of nodes, and each node can have an associated linked list (`list_s2`). This allows us to create a list of lists structure, where each node of the first list can link to another sub-list. The code provides various functions to manage the insertion of new elements, traversal of the lists, and printing of the list hierarchy. This README provides details on the functionality, usage, and memory management practices implemented in the code.

### Files Included

- `list_of_lists_example.c`: Contains the implementation of the list of lists, including the node structures and functions to create, insert, and print nodes.

## Data Structures

### 1. Struct Definitions

#### `list_s1`
The first linked list node structure, `list_s1`, represents the primary list, and each node can contain a pointer to a secondary list (`list_s2`).
- **Fields**:
  - `int key`: Stores the value of the node.
  - `list_t1 *next`: Pointer to the next node in the linked list.
  - `list_t2 *right`: Pointer to a `list_s2` linked list node.

#### `list_s2`
The secondary linked list node structure, `list_s2`, represents the sub-lists that each `list_s1` node can link to.
- **Fields**:
  - `int key`: Stores the value of the node.
  - `list_t2 *next`: Pointer to the next node in the linked list.

## Functions

### 1. create_node_list1(int key)

The `create_node_list1()` function is responsible for creating and initializing a new `list_s1` node.
- **Parameters**:
  - `int key`: The value to be stored in the new node.
- **Return Value**: Returns a pointer to the newly created `list_s1` node (`list_t1*`).
- **Implementation Details**: Allocates memory for the new node and initializes the key, `next`, and `right` pointers. If memory allocation fails, the program exits with an error message.

### 2. create_node_list2(int key)

The `create_node_list2()` function is responsible for creating and initializing a new `list_s2` node.
- **Parameters**:
  - `int key`: The value to be stored in the new node.
- **Return Value**: Returns a pointer to the newly created `list_s2` node (`list_t2*`).
- **Implementation Details**: Allocates memory for the new node and initializes the key and `next` pointer. If memory allocation fails, the program exits with an error message.

### 3. insert_end_list1(list_t1 *head, int key)

The `insert_end_list1()` function inserts a new `list_s1` node at the end of the `list_s1` linked list.
- **Parameters**:
  - `list_t1 *head`: The head of the `list_s1` linked list.
  - `int key`: The value to be inserted into the linked list.
- **Return Value**: Returns the updated head of the `list_s1` linked list.
- **Implementation Details**: If the list is empty, the new node becomes the head. Otherwise, the function traverses to the last node and inserts the new node at the end.

### 4. insert_list2_to_list1(list_t1 *node, int key)

The `insert_list2_to_list1()` function inserts a new `list_s2` node into a `list_s1` node's `right` pointer.
- **Parameters**:
  - `list_t1 *node`: The `list_s1` node to which the `list_s2` node should be linked.
  - `int key`: The value to be inserted into the `list_s2` linked list.
- **Return Value**: Returns the updated `list_s1` node (`list_t1*`).
- **Implementation Details**: If there are no existing `list_s2` nodes linked, the new node becomes the first `list_s2` node. Otherwise, the function traverses to the end of the `list_s2` linked list and inserts the new node there.

### 5. print_list_of_lists(list_t1 *head)

The `print_list_of_lists()` function prints all elements of the list of lists, including `list_s1` nodes and their associated `list_s2` linked lists.
- **Parameters**:
  - `list_t1 *head`: The head of the `list_s1` linked list.
- **Implementation Details**: The function traverses each `list_s1` node and prints its value, followed by traversing and printing all linked `list_s2` nodes.

### 6. main()

The `main()` function demonstrates the use of the above functions to create a list of lists.
- **Implementation Details**:
  - Initializes an empty `list_s1` linked list.
  - Inserts values into `list_s1` to create nodes.
  - Inserts values into `list_s2` linked to each `list_s1` node.
  - Prints the entire list of lists using `print_list_of_lists()`.
  - Frees all allocated memory to prevent memory leaks.

## Usage Instructions

1. **Compilation**:
   - Use the following command to compile the code:
     ```sh
     gcc -o list_of_lists_example list_of_lists_example.c
     ```
   - This will produce an executable named `list_of_lists_example`.

2. **Running the Program**:
   - Run the program using:
     ```sh
     ./list_of_lists_example
     ```
   - The program will create a list of lists, print the structure, and then deallocate all allocated memory.

## Example Output

When you run the program, it will produce the following output:

```
List of Lists:
List1 Node Key: 1
  List2 Nodes: 10 -> 20 -> NULL
List1 Node Key: 2
  List2 Nodes: 30 -> 40 -> NULL
List1 Node Key: 3
  List2 Nodes: 50 -> NULL
```

## Memory Management

- **Dynamic Allocation**: Memory is dynamically allocated for each `list_s1` and `list_s2` node using `malloc()`.
- **Proper Memory Deallocation**: After all operations, the program frees the remaining nodes using `free()` to prevent memory leaks.
- **Error Handling**: Proper checks are performed to ensure that memory allocation is successful. If memory allocation fails, an error message is printed, and the program exits.

## Key Concepts Demonstrated

- **List of Lists Structure**: Creating a linked list of linked lists, where each node in the first list can link to another sub-list.
- **Dynamic Memory Management**: Allocating and deallocating memory dynamically, handling errors appropriately, and ensuring proper memory cleanup.
- **Linked List Operations**: Inserting nodes at the end of a linked list, and printing linked list structures.

## Notes

- The values inserted into the `list_s1` and `list_s2` lists can be modified as needed to test different scenarios.
- The code is intended for educational purposes, demonstrating basic linked list operations, dynamic memory management, and handling of a list of lists structure in C.

## Dependencies

- **Standard Libraries**: The code uses the following standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For dynamic memory management functions such as `malloc()` and `free()`.

## License

This code is provided as-is for educational purposes. Feel free to modify and use it in your projects, but please note that no warranty is provided.

