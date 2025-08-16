#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct list {
    int key;                // The value stored in the node
    struct list *next;      // Pointer to the next node in the list
} list_t;

// Function to create a new element in the linked list
list_t* new_element(int val) {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = val;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new element into a sorted linked list
list_t* insert(list_t *head, int val) {
    list_t *p, *q = head;
    p = new_element(val);  // Create a new element

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

// Function to extract (remove) an element from a sorted linked list
list_t* extract(list_t *head, int val) {
    list_t *p, *q = head;

    // If the list is empty, print an error message and return NULL
    if (head == NULL) {
        fprintf(stderr, "Error: empty list\n");
        return NULL;
    }

    // If the value to be removed is the head node
    if (val == head->key) {
        p = head->next;
        free(head);  // Free the head node
        return p;    // Return the new head of the list
    }

    // Traverse the list to find the node to be removed
    while (q->next != NULL && val > q->next->key) {
        q = q->next;
    }

    // Handle the removal if the element is found
    if (q->next != NULL && val == q->next->key) {
        p = q->next;
        q->next = q->next->next;
        free(p);  // Free the node to be removed
    } else {
        fprintf(stderr, "Error: value not found in the list\n");
    }

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

    // Extract a value from the linked list
    head = extract(head, 20);
    printf("Sorted Linked List after extracting 20:\n");
    print_list(head);

    // Extract a value that does not exist
    head = extract(head, 40);
    printf("Sorted Linked List after attempting to extract 40:\n");
    print_list(head);

    return 0;
}

/*
Explanation of Functions in the Code:

1. Struct Definition:
   - `typedef struct list` defines a linked list node structure (`list_t`) used to represent each element in the list.
   - Each node contains an integer `key` (the value stored in the node) and a pointer `next` to the next node in the list.

2. new_element Function:
   - Allocates memory for a new node and initializes it with the given value.
   - If memory allocation fails, an error message is printed and the program exits.

3. insert Function:
   - Inserts a new element into the linked list in a sorted order.
   - If the list is empty or the new value is smaller than the head's value, the new element becomes the new head.
   - Otherwise, the function traverses the list to find the appropriate position and inserts the new element.

4. extract Function:
   - Removes an element from the linked list if it matches the given value.
   - If the list is empty, an error message is printed.
   - If the value to be removed is the head, the head node is freed and the new head is returned.
   - Otherwise, the function traverses the list to find and remove the node with the given value.
   - If the value is not found, an error message is printed.

5. print_list Function:
   - Prints all elements in the linked list from the head to the end (`NULL`).
   - Useful for visualizing the current state of the list.

6. main Function:
   - Demonstrates the use of the `insert` and `extract` functions by adding and removing values from the list.
   - Calls `print_list` to print the current state of the linked list after each operation.
*/
