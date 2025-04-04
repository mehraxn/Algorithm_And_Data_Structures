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

// Function to print the linked list
void print_list(list_t *top) {
    list_t *current = top;
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate push
int main() {
    list_t *top = NULL;    // Initialize the top of the list as NULL (empty list)

    // Push values onto the list
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    // Print the linked list
    printf("Stack after pushing 30, 20, 10:\n");
    print_list(top);

    // Free the allocated memory
    list_t *current = top;
    list_t *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
