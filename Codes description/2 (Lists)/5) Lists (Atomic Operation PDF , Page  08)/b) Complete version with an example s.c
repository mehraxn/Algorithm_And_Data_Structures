#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct list {
    int key;                 // An integer field to store the value of the node
    struct list *next;       // A pointer to the next element in the linked list
} list_t;

// Function to extract the head node from the linked list
list_t *extract_head(list_t **head) {
    list_t *p = *head;  // Step 1: Set p to point to the head of the list
    if (*head != NULL) {
        *head = (*head)->next;  // Step 2: Update head to point to the next node
    }
    return p;  // Return the original head node
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

    // Extract the head node
    list_t *extracted_node = extract_head(&head);
    if (extracted_node != NULL) {
        printf("Extracted node with value: %d\n", extracted_node->key);
        free(extracted_node);  // Free the extracted node to prevent memory leaks
    }

    // Print the remaining list
    list_t *current = head;
    while (current != NULL) {
        printf("Node with value: %d\n", current->key);
        current = current->next;
    }

    // Free the remaining nodes
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

2. **`extract_head` Function**:
   - This function takes a double pointer to the head of the linked list (`list_t **head`).
   - The function extracts the current head node and updates the head pointer to point to the next node in the list.
   - The original head node is returned, allowing the caller to access or free it.

3. **Memory Allocation**:
   - The `malloc` function is used to dynamically allocate memory for the linked list nodes.
   - Memory allocation is checked to ensure it was successful. If `malloc` returns `NULL`, an error message is printed, and the program exits.

4. **Linking Nodes**:
   - The nodes are linked together by setting the `next` pointer of each node to point to the next node in the sequence.
   - The last node's `next` pointer is set to `NULL` to indicate the end of the list.

5. **Extracting the Head Node**:
   - The `extract_head` function is called to remove the head node from the list.
   - The extracted node's value is printed, and the node is freed to prevent memory leaks.

6. **Printing the Remaining List**:
   - After extracting the head node, the remaining list is printed to show the updated structure of the linked list.

7. **Memory Deallocation**:
   - After the linked list operations are complete, the `free` function is used to deallocate the memory assigned to each node, preventing memory leaks.

This code demonstrates basic linked list operations, including node creation, linking, extracting the head node, and proper memory management. It serves as a foundational example for understanding linked list manipulation in C.
*/
