# Linked List Traversal in C

## Overview
This document provides a comprehensive explanation of a C program that demonstrates how to define, create, traverse, and clean up a linked list. The primary goal is to understand basic linked list operations, including traversal, dynamic node creation, and memory management. The walkthrough will cover the entire code, starting with the `traverse_list` function and concluding with a detailed overview of the entire program.

### 1. `traverse_list` Function
The `traverse_list` function is responsible for traversing the linked list and printing out the value of each node. The traversal begins at the head of the list and continues until the end of the list (which is indicated by a `NULL` pointer).

- **Input**: The function takes a pointer to the head node of the linked list.
- **Process**: The function uses a `while` loop to iterate through each node, printing the `key` value stored in each node and moving to the next node using the `next` pointer.
- **Output**: It prints the key values of each node in the linked list to the console.

#### Code Explanation
```c
void traverse_list(list_t *head) {
    list_t *p = head;  // Initialize pointer p to start at the head of the list

    // Iterate through the list until reaching the end (NULL)
    while (p != NULL) {
        // Visit the current node - for example, print its key value
        printf("Node key: %d\n", p->key);

        // Move to the next node
        p = p->next;
    }
}
```
- `list_t *p = head;` - This line initializes the traversal by setting a pointer `p` to the `head` of the list.
- `while (p != NULL)` - The loop continues as long as `p` is not `NULL`, meaning there are still nodes to visit.
- `printf("Node key: %d\n", p->key);` - The `key` value of the current node is printed.
- `p = p->next;` - The pointer moves to the next node in the list.

### 2. The Complete Program
Now let's explore the entire program, which includes defining a linked list structure, dynamically creating nodes, linking nodes together, traversing the list, and freeing up memory after use.

#### Code Walkthrough

```c
#include <stdio.h>       // Include standard input/output header for printf function
#include <stdlib.h>      // Include standard library header for dynamic memory allocation functions

// Define a structure for list nodes
typedef struct list {
    int key;               // Data field (example: an integer key)
    struct list *next;     // Pointer to the next node in the list
} list_t;

// Function to traverse and print the linked list
void traverse_list(list_t *head) {
    list_t *p = head;  // Initialize pointer p to start at the head of the list

    // Iterate through the list until reaching the end (NULL)
    while (p != NULL) {
        // Visit the current node - for example, print its key value
        printf("Node key: %d\n", p->key);

        // Move to the next node
        p = p->next;
    }
}

// Main function to demonstrate creating and traversing a linked list
int main() {
    // Creating three nodes using dynamic memory allocation
    list_t *node1 = (list_t *)malloc(sizeof(list_t));  // Allocate memory for the first node
    list_t *node2 = (list_t *)malloc(sizeof(list_t));  // Allocate memory for the second node
    list_t *node3 = (list_t *)malloc(sizeof(list_t));  // Allocate memory for the third node

    // Assign key values to the nodes
    node1->key = 10;  // Assigning value 10 to the first node
    node2->key = 20;  // Assigning value 20 to the second node
    node3->key = 30;  // Assigning value 30 to the third node

    // Linking the nodes
    node1->next = node2;  // First node points to second node
    node2->next = node3;  // Second node points to third node
    node3->next = NULL;   // Third node is the last, so it points to NULL

    // Traverse and print the linked list starting from the head (node1)
    printf("Traversing the linked list:\n");  // Print header before traversing the list
    traverse_list(node1);  // Call the function to traverse the list

    // Free the allocated memory
    free(node1);  // Free the memory allocated for the first node
    free(node2);  // Free the memory allocated for the second node
    free(node3);  // Free the memory allocated for the third node

    return 0;  // Return 0 to indicate successful execution
}
```

#### Key Components Explained

1. **Including Headers**:  
   - `#include <stdio.h>` - Provides functions for input and output, such as `printf`.
   - `#include <stdlib.h>` - Includes functions for memory management, such as `malloc` and `free`.

2. **Structure Definition (`list_t`)**:
   - Defines the structure of a node in the linked list.
   - Each node contains an integer `key` and a pointer to the next node (`next`).

3. **Memory Allocation and Node Creation**:
   - In the `main` function, nodes are dynamically allocated using `malloc` to allow flexibility in runtime.
   - The nodes are assigned key values (`node1->key = 10`, etc.) to represent data in each node.

4. **Linking Nodes**:
   - Nodes are linked together by setting their `next` pointers (`node1->next = node2`, etc.).
   - The last node points to `NULL` to indicate the end of the list.

5. **Traversing the List**:
   - The `traverse_list` function is called to traverse and print the key values of each node in the list.

6. **Freeing Allocated Memory**:
   - After the traversal, each node's memory is freed using `free(node1)`, etc., to avoid memory leaks.

### Summary
- **Defining the Structure**: A linked list node is defined with a `key` and a `next` pointer.
- **Creating Nodes**: Nodes are dynamically created using `malloc`.
- **Linking Nodes**: Nodes are linked to form the list.
- **Traversal**: The `traverse_list` function iterates through the list and prints each node's data.
- **Memory Management**: After using the list, memory is freed to prevent leaks.

### How to Run the Code
- Copy the code into a `.c` file (e.g., `linked_list.c`).
- Compile the file using a C compiler, for example:
  ```
  gcc linked_list.c -o linked_list
  ```
- Run the compiled program:
  ```
  ./linked_list
  ```
- The output should display the key values of each node in the linked list.

### Expected Output
```
Traversing the linked list:
Node key: 10
Node key: 20
Node key: 30
```

This output shows that the linked list has been successfully traversed, and each node's data has been printed to the console.

