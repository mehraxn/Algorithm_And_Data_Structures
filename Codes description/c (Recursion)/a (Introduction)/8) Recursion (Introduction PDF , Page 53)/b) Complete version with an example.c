#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
typedef struct list {
    int key;
    struct list *next;
} list_t;

// Function to traverse the linked list in reverse order and print elements
// This function uses recursion to go to the end of the list and prints each element on the way back.
void traverse_reverse(list_t *p) {
    if (p == NULL)
        return;
    traverse_reverse(p->next);
    printf("%d ", p->key);
}

// Function to delete a node with a specific value from the linked list
// This function recursively searches for the node with the given value and deletes it.
list_t* delete(list_t *p, int val) {
    if (p == NULL)
        return NULL;
    if (p->key == val) {
        list_t *t = p->next;
        free(p);
        return t;
    }
    p->next = delete(p->next, val);
    return p;
}

// Main function to demonstrate the reverse traversal and delete functions
int main() {
    // Create a simple linked list for demonstration: 1 -> 2 -> 3 -> NULL
    list_t *head = malloc(sizeof(list_t));
    head->key = 1;
    head->next = malloc(sizeof(list_t));
    head->next->key = 2;
    head->next->next = malloc(sizeof(list_t));
    head->next->next->key = 3;
    head->next->next->next = NULL;

    // Traverse the list in reverse order
    printf("Elements in reverse order: ");
    traverse_reverse(head);
    printf("\n");

    // Delete a node with a specific value
    int val_to_delete = 2;
    head = delete(head, val_to_delete);
    printf("List after deleting element %d: ", val_to_delete);
    list_t *current = head;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");

    // Free the allocated memory
    current = head;
    list_t *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

/*
Summary of the Functions:

1. traverse_reverse Function:
   - The `traverse_reverse` function takes a pointer to the head of a linked list and prints the elements in reverse order.
   - It uses recursion to traverse to the end of the list and prints each element on the way back through the recursive calls.
   - This approach demonstrates the use of recursion for reverse traversal without explicitly using a stack.

2. delete Function:
   - The `delete` function takes a pointer to the head of a linked list and a value to be deleted.
   - It recursively searches for the node with the given value. If the value is found, it deletes the node and returns the updated list.
   - If the value is not found, the function continues to the next node until the end of the list is reached.

3. main Function:
   - The `main` function demonstrates the usage of both `traverse_reverse` and `delete` functions.
   - It creates a simple linked list with three nodes (1 -> 2 -> 3), prints the elements in reverse order, deletes a specific node, and prints the updated list.
   - Finally, it frees the allocated memory to ensure there are no memory leaks.
*/
