#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node structure
typedef struct list {
    int key;                  // This stores the value of the node
    struct list *next;        // This points to the next node in the list
} list_t;

// Function to create a new node with a given value
list_t *create_node(int value) {
    list_t *new_node = (list_t *)malloc(sizeof(list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->key = value;
    new_node->next = NULL;
    return new_node;
}

// Function to append a new node at the end of the linked list
void append_node(list_t **head, int value) {
    list_t *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    list_t *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new_node;
}

// Function to print all nodes in the linked list
void print_list(list_t *head) {
    list_t *p = head;
    while (p != NULL) {
        printf("%d -> ", p->key);
        p = p->next;
    }
    printf("NULL\n");
}

// Function to find a node by value in a linked list
list_t *find_node(list_t *head, int value) {
    list_t *p = head;         // Set a pointer 'p' to start at the head of the list

    // Traverse through the linked list
    while (p != NULL) {
        if (value == p->key) {
            // If the value matches, return the pointer to the node
            return p;
        } else {
            // Move to the next node
            p = p->next;
        }
    }

    // If the value is not found in the linked list, return NULL
    return NULL;
}

// Main function to demonstrate the linked list operations
int main() {
    list_t *head = NULL;

    // Append nodes to the linked list
    append_node(&head, 10);
    append_node(&head, 20);
    append_node(&head, 30);
    append_node(&head, 40);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Find a node with a specific value
    int value_to_find = 20;
    list_t *found_node = find_node(head, value_to_find);
    if (found_node != NULL) {
        printf("Node with value %d found.\n", value_to_find);
    } else {
        printf("Node with value %d not found.\n", value_to_find);
    }

    return 0;
}

/*
Description of the code:

This code defines a linked list and includes several functions to manipulate the list:

1. The structure of the linked list node is defined using 'typedef struct list'. It has two members:
   - 'key': An integer representing the value stored in the node.
   - 'next': A pointer to the next node in the linked list.

2. The 'create_node' function allocates memory for a new node, initializes it with the given value, and returns a pointer to the new node.

3. The 'append_node' function adds a new node with the given value at the end of the linked list.

4. The 'print_list' function prints all the nodes in the linked list, displaying their values in sequence.

5. The 'find_node' function takes two parameters:
   - 'head': A pointer to the head node of the linked list.
   - 'value': The value to be searched for in the linked list.

   Inside the function, the pointer 'p' starts at the head of the list and iterates through each node, comparing the given value with the value stored in each node ('key').
   - If a match is found, the function returns a pointer to that node.
   - If the value is not found in the list, the function returns 'NULL'.

6. The 'main' function demonstrates the usage of the linked list functions by creating a linked list, appending nodes, printing the list, and finding a node by value.

7. The function performs a linear search through the linked list, so the time complexity is O(n), where n is the number of nodes in the list.
*/
