#include <stdio.h>
#include <stdlib.h>

// Type definition for linked list node
typedef struct list_s list_t;
struct list_s {
    int key;         // Value stored in the node
    list_t *next;    // Pointer to the next node
};

// Function to create a new linked list node
list_t* create_node(int key) {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

// Function to pop a node from the front of the linked list
void pop(list_t **head, list_t **node) {
    if (*head == NULL) {
        *node = NULL;
        return;
    }
    *node = *head;
    *head = (*head)->next;
    (*node)->next = NULL;
}

// Function to insert a node into a sorted linked list
list_t* insert(list_t *head, list_t *node) {
    if (head == NULL || node->key < head->key) {
        node->next = head;
        return node;
    }
    list_t *current = head;
    while (current->next != NULL && current->next->key < node->key) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    return head;
}

// Function to sort a linked list
list_t* list_sort(list_t *head1) {
    list_t *tmp, *head2 = NULL;
    while (head1 != NULL) {
        pop(&head1, &tmp);
        head2 = insert(head2, tmp);
    }
    return head2;
}

// Function to print the linked list
void print_list(list_t *head) {
    list_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list sorting
int main() {
    // Create a simple linked list: 30 -> 17 -> 21 -> 9 -> NULL
    list_t *head1 = create_node(30);
    head1->next = create_node(17);
    head1->next->next = create_node(21);
    head1->next->next->next = create_node(9);

    // Print the original list
    printf("Original List:\n");
    print_list(head1);

    // Sort the linked list
    list_t *head2 = list_sort(head1);

    // Print the sorted list
    printf("Sorted List:\n");
    print_list(head2);

    // Free the nodes of the sorted list
    list_t *current = head2;
    while (current != NULL) {
        list_t *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

/*
Summary of Functions in the Code:

1. create_node(int key):
   - Creates a new linked list node with the given value.
   - Allocates memory for the new node, initializes its key and next pointer.
   - Returns a pointer to the newly created node.

2. pop(list_t **head, list_t **node):
   - Pops a node from the front of the linked list.
   - Updates the head pointer to the next node and returns the popped node.

3. insert(list_t *head, list_t *node):
   - Inserts a node into a sorted linked list while maintaining the sorted order.
   - Returns the updated head of the list.

4. list_sort(list_t *head1):
   - Sorts the linked list by popping nodes from the original list and inserting them into a new sorted list.
   - Returns the head pointer of the sorted linked list.

5. print_list(list_t *head):
   - Prints all elements of the linked list from the head to the end (`NULL`).

6. main():
   - Demonstrates the use of `create_node()`, `list_sort()`, and `print_list()` functions.
   - Creates a simple linked list, sorts it, prints both the original and sorted lists, and then frees all allocated memory.
*/
