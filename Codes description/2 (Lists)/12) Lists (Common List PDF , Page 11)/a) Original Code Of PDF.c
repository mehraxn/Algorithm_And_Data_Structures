#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list
typedef struct list {
    int key;                // The value stored in the node
    struct list *next;      // Pointer to the next node in the list
} list_t;

// Function to create a new element
list_t* new_element() {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}

// Push function to add a new element to the top of the list
list_t* push(list_t *top, int val) {
    list_t *new;               // Pointer for the new node
    new = new_element();       // Allocate memory for the new node

    new->key = val;            // Set the value for the new node
    new->next = top;           // Link the new node to the current top
    top = new;                 // Update the top to point to the new node

    return top;                // Return the new top of the list
}