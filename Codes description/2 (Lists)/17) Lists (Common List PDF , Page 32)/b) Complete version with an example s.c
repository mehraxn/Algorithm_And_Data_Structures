#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct list {
    int key;                // The value stored in the node
    struct list *next;      // Pointer to the next node in the list
} list_t;

// Function to create a new element in the linked list
list_t* new_element() {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}

// Function to insert a new element into a sorted linked list
list_t* insert(list_t *head, int val) {
    list_t *p, *q = head;
    p = new_element();  // Create a new element
    p->key = val;
    p->next = NULL;

    // If the list is empty or the new value is smaller than the head's value
    if (head == NULL || val < head->key) {
        p->next = head;  // Insert at the beginning
        return p;        // New element becomes the new head
    }

    // Traverse the list to find the correct position for the new value
    while (q->next != NULL && val > q->next->key) {
        q = q->next;
    }

    // Insert the new element in its correct position
    p->next = q->next;
    q->next = p;

    return head;  // Return the updated head of the list
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

int main() {
    list_t *head = NULL;  // Initialize the head of the list as NULL (empty list)

    // Insert values into the linked list
    head = insert(head, 20);
    head = insert(head, 10);
    head = insert(head, 30);
    head = insert(head, 25);

    // Print the linked list
    printf("Sorted Linked List after insertions:\n");
    print_list(head);

    return 0;
}

/*
Explanation of Functions in the Code:

1. Struct Definition:
   - `typedef struct list` defines a linked list node structure (`list_t`) used to represent each element in the list.
   - Each node contains an integer `key` (the value stored in the node) and a pointer `next` to the next node in the list.

2. new_element Function:
   - Allocates memory for a new node and returns a pointer to it.
   - If memory allocation fails, an error message is printed and the program exits.

3. insert Function:
   - Inserts a new element into the linked list in a sorted order.
   - If the list is empty or the new value is smaller than the head's value, the new element becomes the new head.
   - Otherwise, the function traverses the list to find the appropriate position and inserts the new element.

4. print_list Function:
   - Prints all elements in the linked list from the head to the end (`NULL`).
   - Useful for visualizing the current state of the list.

5. main Function:
   - Demonstrates the use of the `insert` function by adding values to the list in a sorted manner.
   - Calls `print_list` to print the current state of the linked list after insertions.
*/
