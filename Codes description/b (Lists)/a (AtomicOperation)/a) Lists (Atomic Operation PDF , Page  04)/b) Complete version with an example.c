#include <stdio.h>   // For input/output functions
#include <stdlib.h>  // For malloc and exit

// Define a struct named list_t
typedef struct list {
    int data;               // An integer field for data
    struct list *next;      // A pointer to the next element in the list
} list_t;

// Function prototype for creating a new element
list_t *new_element();

// Main function
int main() {
    // Create a new element using the new_element function
    list_t *node = new_element();

    // Assign a value to the data field of the node
    node->data = 42;

    // Assign NULL to the next field to indicate the end of the list
    node->next = NULL;

    // Print the data stored in the node
    printf("The value in the new node is: %d\n", node->data);

    // Free the allocated memory to prevent memory leaks
    free(node);

    // Return 0 to indicate successful program execution
    return 0;
}

// Function to allocate memory for a new list element
list_t *new_element() {
    list_t *e_ptr;

    // Allocate memory for a new list_t object
    e_ptr = (list_t *) malloc(sizeof(list_t));

    // Check if memory allocation was successful
    if (e_ptr == NULL) {
        // Print an error message and terminate the program
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE); // Exit with a failure status
    }

    // Return the pointer to the newly allocated memory
    return e_ptr;
}

/*
Explanation of Functions:
1. list_t:
   - A user-defined data structure representing a node in a linked list.
   - Fields:
     a. `data`: Holds an integer value.
     b. `next`: Points to the next node in the list or NULL if it's the last node.

2. new_element:
   - Dynamically allocates memory for a new `list_t` object.
   - Handles memory allocation errors by printing an error message and terminating the program.
   - Returns a pointer to the newly created list element.

3. main:
   - Demonstrates how to use the `new_element` function to create a node.
   - Assigns a value to the `data` field and sets the `next` pointer to NULL.
   - Outputs the value of the `data` field.
   - Frees the allocated memory to ensure good memory management.

Purpose:
This code is a basic example of dynamically creating and managing a single node in a linked list.
*/
