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
        free(p);  // Step 3: Free the extracted head node to prevent memory leaks
        return NULL;  // Return NULL after freeing the node
    }
    return NULL;  // Return NULL if the list was empty
}

// Function to dispose of the entire linked list
void dispose_list(list_t *head) {
    list_t *p;
    while (head != NULL) {  // Traverse the list
        p = head;           // Set p to point to the current head
        head = head->next;  // Move head to the next node
        free(p);            // Free the current node to prevent memory leaks
    }
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
    extract_head(&head);  // Extract and free the head node

    // Print the remaining list
    list_t *current = head;
    while (current != NULL) {
        printf("Node with value: %d\n", current->key);
        current = current->next;
    }

    // Dispose of the entire linked list
    dispose_list(head);

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
   - The extracted head node is then freed to prevent memory leaks.

3. **`dispose_list` Function**:
   - This function takes a pointer to the head of the linked list and traverses the entire list, freeing each node.
   - This ensures that all dynamically allocated memory is properly released, preventing memory leaks.

4. **Memory Allocation**:
   - The `malloc` function is used to dynamically allocate memory for the linked list nodes.
   - Memory allocation is checked to ensure it was successful. If `malloc` returns `NULL`, an error message is printed, and the program exits.

5. **Linking Nodes**:
   - The nodes are linked together by setting the `next` pointer of each node to point to the next node in the sequence.
   - The last node's `next` pointer is set to `NULL` to indicate the end of the list.

6. **Extracting the Head Node**:
   - The `extract_head` function is called to remove and free the head node from the list.
   - This ensures that the memory occupied by the head node is released to prevent memory leaks.

7. **Printing the Remaining List**:
   - After extracting the head node, the remaining list is printed to show the updated structure of the linked list.

8. **Disposing of the Entire List**:
   - The `dispose_list` function is called to free all remaining nodes in the linked list, ensuring proper cleanup of dynamically allocated memory.

This code demonstrates basic linked list operations, including node creation, linking, extracting the head node, disposing of the entire list, and proper memory management. It serves as a foundational example for understanding linked list manipulation in C.
*/
