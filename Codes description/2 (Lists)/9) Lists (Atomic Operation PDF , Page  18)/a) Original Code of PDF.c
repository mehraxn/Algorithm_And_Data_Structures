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

// Function to insert a new node after a given node (tail insertion)
void tail_insert(list_t *p) {
    if (p == NULL) {
        fprintf(stderr, "Provided node cannot be NULL.\n");
        return;
    }
    list_t *new = new_element();  // Step 1: Create a new node using the new_element function

    new->next = p->next;  // Step 2: Point new node's next to the node after p
    p->next = new;        // Step 3: Update p's next to point to the new node
}