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

// Function to push a new element onto the list
list_t* push(list_t *top, int val) {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = val;
    new_node->next = top;
    return new_node;
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

int main() {
    list_t *top = NULL;    // Initialize the top of the list as NULL (empty list)
    int val, status;

    // Push values onto the list
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    // Print the linked list
    printf("Stack after pushing 30, 20, 10:\n");
    print_list(top);

    // Pop a value from the stack
    top = pop(top, &val, &status);
    if (status == SUCCESS) {
        printf("Popped value: %d\n", val);
    } else {
        printf("Stack is empty, cannot pop.\n");
    }

    // Print the linked list after pop
    printf("Stack after popping:\n");
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
