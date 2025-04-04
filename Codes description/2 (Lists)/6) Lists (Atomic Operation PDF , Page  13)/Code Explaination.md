**`extract_tail` Function in C**

**Overview**
This README provides a detailed explanation of a C program that demonstrates how to manipulate a linked list using the `extract_tail` function. The function is used to extract and remove a node from a linked list, specifically removing the node after a given node (`q`). This example focuses on linked list operations, including node creation, deletion, and memory management.

**1. Structure Definition (`list_t`)**
The linked list is implemented using a structure named `list_t`. Each node in the list contains:
- **`key`**: An integer representing the value stored in the node.
- **`next`**: A pointer to the next node in the linked list.

This structure allows the creation of a dynamic linked list where each node can point to the next, forming a chain of elements.

**2. `extract_tail` Function**

- **Purpose**: The `extract_tail` function is designed to extract and remove a node immediately following a given node (`q`) in the linked list. This function effectively updates the list to bypass the removed node.
- **Parameters**:
  - **`q`**: A pointer to the node preceding the node that is to be removed from the linked list.
- **Process**:
  - **Step 1**: Set a temporary pointer `p` to point to the node immediately after `q`.
  - **Step 2**: Update `q->next` to skip `p` and link directly to the node after `p`.
  - **Freeing Memory**: The function frees the memory allocated for the removed node (`p`) to prevent memory leaks.
- **Output**: Returns `NULL` after freeing the extracted node.

**3. Memory Management**
Dynamic memory allocation is used throughout the program to ensure flexibility in creating nodes. Proper memory management is crucial for preventing memory leaks.
- **`malloc`**: The `malloc` function is used to allocate memory for each new node. The memory allocation is checked to ensure it was successful.
- **Error Handling**: If memory allocation fails, an error message is printed, and the program exits.
- **`free`**: After nodes are removed or the program is complete, the `free` function is used to deallocate memory.

**4. Main Function Overview**
The `main` function demonstrates the usage of the above functions to create, manipulate, and manage linked list nodes:
- **Node Creation**: Dynamically allocates memory for three nodes (`head`, `second`, `third`).
- **Linking Nodes**: Links the nodes together to form a list with values 10, 20, and 30.
- **Extracting a Node**: Calls `extract_tail` to remove the node following `second` (i.e., `third` node).
- **Printing the List**: Prints the remaining linked list to verify the updated structure.
- **Memory Cleanup**: Frees the memory allocated for each node to ensure proper cleanup.

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
   Node with value: 10
   Node with value: 20
   ```

**6. Summary**
The `extract_tail` function provides a practical way to remove a specific node from a linked list. The function extracts and frees the node following a given node, which is useful for various linked list manipulations.

- **Purpose**: Extracts and removes the node immediately following a given node.
- **Use Case**: Useful in situations where specific nodes need to be removed or processed, such as deleting the last node in a segment of the list.
- **Memory Management**: Proper use of `malloc` and `free` ensures efficient memory usage, preventing memory leaks.

This example serves as a foundational demonstration of linked list manipulation in C, covering essential operations like node extraction, memory management, and linked list traversal.

