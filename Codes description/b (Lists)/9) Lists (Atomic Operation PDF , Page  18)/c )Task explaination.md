**`tail_insert` Function in C**

**Overview**
This README provides a detailed explanation of a C program that demonstrates linked list manipulation, specifically focusing on inserting a new node after a given node in the list (tail insertion). This example is designed for beginners to understand dynamic memory allocation, linked list operations, and proper memory management in C.

**1. Structure Definition (`list_t`)**
The linked list is implemented using a structure named `list_t`. Each node in the list contains:
- **`key`**: An integer representing the data stored in the node.
- **`next`**: A pointer to the next node in the linked list.

This structure allows the creation of a dynamic linked list where each node points to the next, forming a sequence of elements.

**2. `new_element` Function**

- **Purpose**: The `new_element` function is responsible for creating a new linked list node.
- **Process**:
  - Allocates memory for a new node using `malloc`.
  - Checks if memory allocation is successful, and if not, prints an error message and terminates the program.
  - Initializes the `key` field to 0 and sets the `next` pointer to `NULL`.
- **Return Value**: Returns a pointer to the newly created node.

The `new_element` function ensures that new nodes are correctly initialized before being added to the list, which is crucial for maintaining data integrity in linked lists.

**3. `tail_insert` Function**

- **Purpose**: The `tail_insert` function is used to insert a new node after a specified node (`p`) in the linked list, effectively adding a new node at the tail or end of a segment of the list.
- **Process**:
  - **Step 1**: Creates a new node using the `new_element` function.
  - **Step 2**: Sets the `next` pointer of the new node to point to the node that follows `p`.
  - **Step 3**: Updates `p->next` to point to the newly created node.
- **Usage**: This function is useful when adding elements at specific positions in the linked list, making it flexible for various data operations.

**4. Main Function**

- **Purpose**: Demonstrates how to use the `new_element` and `tail_insert` functions in a practical example.
- **Process**:
  - Initializes a linked list with two nodes (`head` and `second`) using dynamic memory allocation.
  - Inserts a new node after the second node using the `tail_insert` function and assigns a value to the new node.
  - Prints the entire linked list to verify the order of nodes and their values.
  - Frees the allocated memory for all nodes to prevent memory leaks.

The main function showcases how to build and manipulate a linked list step by step, highlighting how new nodes can be inserted and how memory should be managed.

**5. How to Compile and Run**
To compile and run the program:

1. Save the code to a file, e.g., `linked_list.c`.
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
   Node with value: 10
   Node with value: 20
   Node with value: 30
   ```

**6. Summary**
The `tail_insert` function is an essential tool for managing linked lists, allowing new nodes to be added at specific positions in the list. This program covers several important concepts:

- **Dynamic Memory Allocation**: Uses `malloc` for creating nodes and `free` for deallocating memory, ensuring efficient memory usage.
- **Node Insertion**: Demonstrates how to insert a new node after a given node, providing flexibility in linked list operations.
- **Memory Management**: Ensures that all allocated nodes are freed at the end of the program, preventing memory leaks and maintaining optimal memory use.

This example serves as a fundamental introduction to linked list operations in C, offering a basis for more advanced manipulations such as deleting nodes, reversing the list, or implementing additional data structures.

