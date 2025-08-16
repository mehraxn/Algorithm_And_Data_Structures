** Linked List Head Insertion in C**

**Overview**
This README provides a detailed explanation of a C program that demonstrates how to create and manipulate a linked list by inserting nodes at the head of the list. The program includes functions for creating new nodes, inserting them at the head, printing the list, and properly managing memory by deallocating nodes when they are no longer needed. This example is particularly useful for beginners to understand linked list operations and memory management in C.

**1. Structure Definition (`list_t`)**
The linked list is implemented using a structure named `list_t`. Each node in the list contains:
- **`key`**: An integer representing the value stored in the node.
- **`next`**: A pointer to the next node in the linked list.

This structure allows for dynamic data storage, where each node points to the next, forming a chain of elements.

**2. `new_element` Function**

- **Purpose**: The `new_element` function is designed to create a new linked list node. It dynamically allocates memory for a new node and initializes its fields.
- **Parameters**: This function does not take any parameters.
- **Process**:
  - **Memory Allocation**: Uses `malloc` to allocate memory for the new node. If memory allocation fails, it prints an error message and terminates the program to avoid undefined behavior.
  - **Initialization**: Initializes the `key` field to a default value (0) and sets the `next` pointer to `NULL`.
- **Return Value**: Returns a pointer to the newly created node.

**3. `head_insert` Function**

- **Purpose**: The `head_insert` function is used to add a new node at the beginning (head) of the linked list.
- **Parameters**: Takes a pointer to the current head of the list as an argument.
- **Process**:
  - **Step 1**: Creates a new node using the `new_element` function.
  - **Step 2**: Sets the `next` pointer of the new node to the current head of the list.
  - **Step 3**: Updates the head pointer to point to the newly inserted node.
- **Return Value**: Returns the updated head pointer, which now points to the newly inserted node.

**4. Main Function**

- **Purpose**: Demonstrates the usage of the linked list functions.
- **Process**:
  - **Initialization**: Initializes an empty linked list with `head` set to `NULL`.
  - **Insertion**: Inserts two nodes at the head of the list using the `head_insert` function. The values of the nodes are set to 10 and 20 respectively.
  - **Printing the List**: Traverses the linked list and prints the value of each node to demonstrate the current state of the list.
  - **Memory Deallocation**: Frees all allocated memory to prevent memory leaks.

**5. How to Compile and Run**
To compile and run the program:

1. Save the code to a file (e.g., `linked_list.c`).
2. Use the following command to compile:
   ```bash
   gcc linked_list.c -o linked_list
   ```
3. Run the compiled program:
   ```bash
   ./linked_list
   ```
   The program will output:
   ```
   Node with value: 20
   Node with value: 10
   ```

**6. Summary**
The linked list implementation in C demonstrates several key concepts:
- **Dynamic Memory Allocation**: Uses `malloc` to create new nodes and `free` to deallocate memory, ensuring efficient use of resources and preventing memory leaks.
- **Head Insertion**: The `head_insert` function allows new nodes to be inserted at the beginning of the list, which is a common linked list operation.
- **Memory Management**: Proper memory management is implemented by freeing all allocated nodes at the end of the program.

This foundational example helps understand how linked lists work in C and can be expanded upon to include other operations such as inserting nodes at specific positions, deleting nodes, or reversing the list.

