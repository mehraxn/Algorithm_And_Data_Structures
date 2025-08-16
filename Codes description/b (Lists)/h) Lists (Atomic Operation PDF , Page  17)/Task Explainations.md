**README for Linked List Implementation in C**

**Overview**
This README provides a detailed explanation of a C program that demonstrates how to create and manipulate a linked list using dynamic memory allocation. The program includes functions for node creation, extracting the head node, and printing the remaining nodes in the list. It serves as an example for beginners to understand linked list operations and memory management in C.

**1. Structure Definition (`list_t`)**
The linked list is implemented using a structure named `list_t`. Each node in the list contains:
- **`key`**: An integer representing the value stored in the node.
- **`next`**: A pointer to the next node in the linked list.

This structure allows for the creation of a dynamic linked list where each node is linked to the next, forming a chain of elements.

**2. `extract_head` Function**

- **Purpose**: The `extract_head` function is designed to extract and remove the head node from the linked list and update the head pointer to point to the next node.
- **Parameters**: The function takes a double pointer to the head of the linked list (`list_t **head`), allowing the function to modify the original head pointer.
- **Process**:
  - **Step 1**: Set a pointer `p` to the current head of the list.
  - **Step 2**: Update the head pointer to point to the next node in the list.
  - **Step 3**: Free the memory occupied by the original head node to prevent memory leaks.
  - **Step 4**: Return `NULL` after freeing the node.
- **Usage**: This function is helpful when we need to remove and free the first element of the linked list, such as when implementing a queue.

**3. Memory Management**
Dynamic memory allocation is used throughout the program to ensure flexibility in creating and manipulating nodes.
- **`malloc`**: The `malloc` function is used to allocate memory for each new node.
- **Error Handling**: Memory allocation is checked to ensure it was successful. If `malloc` returns `NULL`, an error message is printed, and the program terminates to prevent undefined behavior.
- **`free`**: After operations are complete, each node is freed to prevent memory leaks. The `free` function is used to release the memory allocated for each node.

**4. Main Function Overview**
The `main` function demonstrates how to create a linked list, extract the head node, and print the remaining list:
- **Creates** three linked list nodes (`head`, `second`, `third`) using `malloc`.
- **Links** the nodes together to form a list with values 10, 20, and 30.
- **Extracts** the head node using the `extract_head` function, which also frees the memory occupied by the extracted node.
- **Prints** the remaining list to demonstrate the updated structure of the linked list.
- **Frees** all dynamically allocated memory to ensure proper cleanup.

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
   Node with value: 30
   ```

**6. Summary**
This linked list implementation in C demonstrates key operations such as:
- **Dynamic Memory Allocation**: Using `malloc` to create new nodes and `free` to deallocate memory.
- **Node Extraction and Deallocation**: The `extract_head` function provides a simple mechanism to remove and free the head node from the list while maintaining the rest of the list.
- **Linked List Manipulation**: Creating, linking, extracting, and printing nodes are all fundamental operations needed to work with linked lists effectively.

This example serves as a foundation for more advanced linked list operations, such as inserting nodes at arbitrary positions, deleting specific nodes, or reversing the list.
