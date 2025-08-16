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

// Function to reverse the linked list
list_t* list_reverse(list_t *head1) {
    list_t *tmp, *head2 = NULL;

    while (head1 != NULL) {
        // Extract from list1
        tmp = head1;
        head1 = head1->next;

        // Insert into list2
        tmp->next = head2;
        head2 = tmp;
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

// Main function to demonstrate the linked list reversal
int main() {
    // Create a simple linked list: 30 -> 17 -> 21 -> 9 -> NULL
    list_t *head1 = create_node(30);
    head1->next = create_node(17);
    head1->next->next = create_node(21);
    head1->next->next->next = create_node(9);

    // Print the original list
    printf("Original List:\n");
    print_list(head1);

    // Reverse the linked list
    list_t *head2 = list_reverse(head1);

    // Print the reversed list
    printf("Reversed List:\n");
    print_list(head2);

    // Free the nodes of the reversed list
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

2. list_reverse(list_t *head1):
   - Reverses the linked list by extracting each node from the original list (head1) and inserting it at the beginning of the new list (head2).
   - Returns the head pointer of the reversed list (head2).

3. print_list(list_t *head):
   - Prints all elements of the linked list from the head to the end (`NULL`).

4. main():
   - Demonstrates the use of `create_node()`, `list_reverse()`, and `print_list()` functions.
   - Creates a simple linked list, reverses it, prints both the original and reversed lists, and then frees all allocated memory.
*/
