#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct list {
    int key;                 // An integer field to store the value of the node
    struct list *next;       // A pointer to the next element in the linked list
} list_t;

// Function to extract and remove the tail node from the linked list
list_t *extract_tail(list_t *q) {
    list_t *p = q->next;  // Step 1: Set p to point to the node after q
    if (p != NULL) {
        q->next = p->next;  // Step 2: Update q->next to skip p and point to p's next node
    }

    // Free the extracted node to prevent memory leaks
    if (p != NULL) {
        free(p);
    }

    return NULL;  // Return NULL after freeing the extracted tail node
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

    // Extract the tail node
    extract_tail(second);  // Extract and free the third node (tail node)

    // Print the remaining list
    list_t *current = head;
    while (current != NULL) {
        printf("Node with value: %d\n", current->key);
        current = current->next;
    }

    // Free the remaining nodes
    free(head);
    free(second);

    return 0;
}

/*
Description of the Code:

1. **Structure Definition (`list_t`)**:
   - The linked list node is defined using the `typedef struct list`. Each node contains:
     - `key`: An integer representing the value stored in the node.
     - `next`: A pointer to the next node in the list.

2. **`extract_tail` Function**:
   - This function takes a pointer to a node (`q`) in the linked list.
   - It extracts the node following `q` (the tail node in this context) and updates the list to bypass the extracted node.
   - The extracted node is freed to prevent memory leaks, and the function returns `NULL`.

3. **Memory Allocation**:
   - The `malloc` function is used to dynamically allocate memory for the linked list nodes.
   - Memory allocation is checked to ensure it was successful. If `malloc` returns `NULL`, an error message is printed, and the program exits.

4. **Linking Nodes**:
   - The nodes are linked together by setting the `next` pointer of each node to point to the next node in the sequence.
   - The last node's `next` pointer is set to `NULL` to indicate the end of the list.

5. **Extracting the Tail Node**:
   - The `extract_tail` function is called to remove the tail node from the list.
   - The removed node is freed to prevent memory leaks.

6. **Printing the Remaining List**:
   - After extracting the tail node, the remaining list is printed to show the updated structure of the linked list.

7. **Memory Deallocation**:
   - After the linked list operations are complete, the `free` function is used to deallocate the memory assigned to each remaining node, preventing memory leaks.

This code demonstrates basic linked list operations, including node creation, linking, extracting a specific node, and proper memory management. It serves as a foundational example for understanding linked list manipulation in C.
*/
