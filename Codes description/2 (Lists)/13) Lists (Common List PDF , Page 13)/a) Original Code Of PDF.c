#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct list {
    int key;                // The value stored in the node
    struct list *next;      // Pointer to the next node in the list
} list_t;

// Pop function to remove the top element from the list
list_t* pop(list_t *top, int *val, int *status) {
    list_t *old;                // Pointer to hold the node being removed

    if (top != NULL) {          // Check if the list is not empty
        *status = SUCCESS;      // Set status to SUCCESS
        *val = top->key;        // Store the value of the top node

        // Step 1: Store the top node in old pointer
        old = top;

        // Step 2: Update top to point to the next node
        top = top->next;

        // Step 3: Free the old top node
        free(old);
    } else {
        *status = FAILURE;      // Set status to FAILURE if the list is empty
    }

    return top;                 // Return the new top of the list
}