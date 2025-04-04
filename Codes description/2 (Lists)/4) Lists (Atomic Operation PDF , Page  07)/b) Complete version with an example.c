#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct list {
    int key;                 // An integer field to store the value of the node
    struct list *next;       // A pointer to the next element in the linked list
} list_t;

// Function to find a node by value in a linked list
list_t *find_node(list_t *head, int value) {
    list_t *p;
    p = head;  // Set the pointer 'p' to start at the head of the list

    // Traverse the list until the value is found or the end is reached
    while ((p != NULL) && (p->key != value)) {
        p = p->next;  // Move to the next node in the list
    }

    // Return the pointer to the node if found, otherwise return NULL
    return p;
}

// Example usage
int main() {
    // Create linked list nodes using dynamic memory allocation
    list_t *head = (list_t *)malloc(sizeof(list_t));
    list_t *second = (list_t *)malloc(sizeof(list_t));
    list_t *third = (list_t *)malloc(sizeof(list_t));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Assign data and link the nodes
    head->key = 10;           // Assign value to the first node
    head->next = second;      // Link the first node to the second node

    second->key = 20;         // Assign value to the second node
    second->next = third;     // Link the second node to the third node

    third->key = 30;          // Assign value to the third node
    third->next = NULL;       // The third node is the last, so its next pointer is NULL

    // Find a node with a specific value
    int value_to_find = 20;
    list_t *found_node = find_node(head, value_to_find);
    if (found_node != NULL) {
        printf("Node with value %d found.\n", value_to_find);
    } else {
        printf("Node with value %d not found.\n", value_to_find);
    }

    // Free allocated memory to prevent memory leaks
    free(head);
    free(second);
    free(third);

    return 0;
}

/*
Description of the Code:

1. **Structure Definition (`list_t`)**:
   - The linked list node is defined using the `typedef struct list`. Each node contains:
     - `key`: An integer representing the value stored in the node.
     - `next`: A pointer to the next node in the list.

2. **`find_node` Function**:
   - This function takes two parameters:
     - `head`: A pointer to the head node of the linked list.
     - `value`: The value to be searched for in the list.
   - The function starts at the head and iterates through the list using a pointer `p`.
   - If a node with the specified value is found, the function returns a pointer to that node. If no such node is found, it returns `NULL`.

3. **Memory Allocation**:
   - The `malloc` function is used to dynamically allocate memory for the linked list nodes.
   - Memory allocation is checked to ensure it was successful. If `malloc` returns `NULL`, an error message is printed, and the program exits.

4. **Linking Nodes**:
   - The nodes are linked together by setting the `next` pointer of each node to point to the next node in the sequence.
   - The last node's `next` pointer is set to `NULL` to indicate the end of the list.

5. **Finding a Node**:
   - The `find_node` function is called to search for a node with a specific value.
   - The result is printed to indicate whether the node was found or not.

6. **Memory Deallocation**:
   - After the linked list operations are complete, the `free` function is used to deallocate the memory assigned to each node, preventing memory leaks.

This code demonstrates basic linked list operations, including node creation, linking, searching, and proper memory management. It serves as a foundational example for understanding linked list manipulation in C.
*/
