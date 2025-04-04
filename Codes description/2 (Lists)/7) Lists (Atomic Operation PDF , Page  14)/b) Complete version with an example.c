#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct list {
    int key;                 // An integer field to store the value of the node
    struct list *next;       // A pointer to the next element in the linked list
} list_t;

// Function to create a new node
list_t *new_element() {
    list_t *new_node = (list_t *)malloc(sizeof(list_t));  // Allocate memory for a new node
    if (new_node == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);  // Exit the program if allocation fails
    }
    new_node->key = 0;       // Initialize the key with a default value (e.g., 0)
    new_node->next = NULL;   // Set the next pointer to NULL
    return new_node;         // Return the pointer to the newly created node
}

// Function to insert a new node at the head of the linked list
list_t *head_insert(list_t *head) {
    list_t *new = new_element();  // Step 1: Create a new node using the new_element function

    new->next = head;  // Step 2: Point new node's next to the current head of the list
    head = new;        // Step 3: Update the head pointer to point to the new node

    return head;      // Return the updated head pointer
}

// Example usage
int main() {
    list_t *head = NULL;  // Initialize the head of the list as NULL

    // Insert new nodes at the head of the list
    head = head_insert(head);  // Insert first node
    head->key = 10;            // Assign value to the first node

    head = head_insert(head);  // Insert second node
    head->key = 20;            // Assign value to the second node

    // Print the linked list
    list_t *current = head;
    while (current != NULL) {
        printf("Node with value: %d\n", current->key);
        current = current->next;
    }

    // Free the allocated memory
    while (head != NULL) {
        list_t *temp = head;
        head = head->next;
        free(temp);  // Free each node to prevent memory leaks
    }

    return 0;
}

/*
Description of the Code:

1. **Structure Definition (`list_t`)**:
   - The linked list node is defined using the `typedef struct list`. Each node contains:
     - `key`: An integer representing the value stored in the node.
     - `next`: A pointer to the next node in the list.

2. **`new_element` Function**:
   - This function allocates memory for a new linked list node and initializes its fields.
   - If memory allocation fails, it prints an error message and exits the program to prevent undefined behavior.
   - The function returns a pointer to the newly created node, with the `key` initialized to 0 and `next` set to NULL.

3. **`head_insert` Function**:
   - This function inserts a new node at the head of the linked list.
   - A new node is created using the `new_element` function, and its `next` pointer is set to the current head of the list.
   - The head pointer is updated to point to the newly inserted node, and the updated head is returned.

4. **Main Function**:
   - The `main` function demonstrates how to use the linked list functions.
   - It initializes an empty list (`head` is initially `NULL`), inserts new nodes at the head, and assigns values to them.
   - The linked list is then printed to show the values of each node.
   - Finally, the program frees the memory allocated for each node to prevent memory leaks.

This code demonstrates basic linked list operations, including node creation, head insertion, and proper memory management. It serves as a foundational example for understanding linked list manipulation in C.
*/
