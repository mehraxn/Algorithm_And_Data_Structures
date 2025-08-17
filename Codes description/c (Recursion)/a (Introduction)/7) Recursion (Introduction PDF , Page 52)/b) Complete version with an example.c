#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
typedef struct list {
    int key;
    struct list *next;
} list_t;

// Function to count the number of elements in the linked list
// This function returns the number of nodes in the linked list starting from the given node `p`.
int count(list_t *p) {
    if (p == NULL)
        return 0;
    return (1 + count(p->next));
}

// Function to traverse and print the elements of the linked list
// This function prints the value of each node starting from the given node `p`.
void traverse(list_t *p) {
    if (p == NULL)
        return;
    printf("%d ", p->key);
    traverse(p->next);
}

// Main function to demonstrate the count and traverse functions
int main() {
    // Create a simple linked list for demonstration: 1 -> 2 -> 3 -> NULL
    list_t *head = malloc(sizeof(list_t));
    head->key = 1;
    head->next = malloc(sizeof(list_t));
    head->next->key = 2;
    head->next->next = malloc(sizeof(list_t));
    head->next->next->key = 3;
    head->next->next->next = NULL;

    // Count the number of elements in the list
    int total_count = count(head);
    printf("Total number of elements: %d\n", total_count);

    // Traverse and print the elements in the list
    printf("Elements in the list: ");
    traverse(head);
    printf("\n");

    // Free the allocated memory
    list_t *current = head;
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

1. count Function:
   - The `count` function takes a pointer to the head of a linked list and returns the number of nodes in the list.
   - It uses recursion to traverse each node in the list, adding `1` for each node until it reaches the end (`NULL`).
   - The base case is when `p` is `NULL`, which indicates that the end of the list has been reached, and the function returns `0`.

2. traverse Function:
   - The `traverse` function takes a pointer to the head of a linked list and prints the value (`key`) of each node.
   - It uses recursion to traverse each node in the list, printing the key value and then calling itself with the next node.
   - The base case is when `p` is `NULL`, which indicates that the end of the list has been reached, and the function returns.

3. main Function:
   - The `main` function demonstrates the usage of the `count` and `traverse` functions.
   - It creates a simple linked list with three nodes (1 -> 2 -> 3) and then calls `count` to print the total number of elements.
   - It also calls `traverse` to print each element in the list.
   - Finally, it frees the allocated memory to avoid memory leaks.
*/
