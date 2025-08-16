#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;  // The value stored in the node
    struct Node* next;  // Pointer to the next node in the list
} Node;

// Function to create a new node
Node* create_node(int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

// Function to search for a value in a linked list using a sentinel node
Node* sentinel_search(Node* head, int value) {
    // Create a sentinel node and set its key to the target value
    Node sentinel;
    sentinel.key = value;
    sentinel.next = NULL;

    // Set the end of the linked list to point to the sentinel
    Node* p = head;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;  // Traverse to the end of the list
    }
    tail->next = &sentinel;  // Attach the sentinel node to the end

    // Search for the value in the list
    while (value != p->key) {
        p = p->next;  // Move to the next node
    }

    // Restore the list by removing the sentinel
    tail->next = NULL;

    // Check if the value was found (if p is not the sentinel node)
    if (p != &sentinel) {
        // Value found
        return p;
    } else {
        // Value not found
        return NULL;
    }
}

// Function to print the linked list
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);

    // Print the original list
    printf("Original list: \n");
    print_list(head);

    // Search for a value in the list
    int target_value = 3;
    Node* result = sentinel_search(head, target_value);

    // Print the result of the search
    if (result != NULL) {
        printf("Value %d found in the list.\n", target_value);
    } else {
        printf("Value %d not found in the list.\n", target_value);
    }

    // Free the allocated memory
    Node* current = head;
    Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}

/*
Explanation of Functions in the Code:
1. Struct Definition:
   - `typedef struct Node` defines a linked list node structure.
   - Each node contains an `int key` (the value stored in the node) and a pointer `next` to the next node in the list.

2. create_node Function:
   - Allocates memory for a new node, initializes it with the given key, and sets the next pointer to `NULL`.

3. sentinel_search Function:
   - This function searches for a specific value in a linked list using a sentinel node to simplify the search logic.
   - It creates a sentinel node with the target value, attaches it to the end of the list, and then searches for the value.
   - If the value is found, it returns a pointer to the node containing the value.
   - If the value is not found, it returns `NULL`.
   - The function restores the list to its original state by removing the sentinel node after the search is complete.

4. print_list Function:
   - Prints the linked list from the head node to the end (`NULL`).

5. main Function:
   - Creates a linked list with nodes containing the values 1, 2, 3, and 4.
   - Prints the original list.
   - Searches for a target value (3) in the list using the `sentinel_search` function.
   - Prints whether the target value was found.
   - Frees the allocated memory for all nodes before exiting.
*/
