#include <stdio.h>       // Include standard input/output header for printf function
#include <stdlib.h>      // Include standard library header for dynamic memory allocation functions

// Define a structure for list nodes
typedef struct list {
    int key;               // Data field (example: an integer key)
    struct list *next;     // Pointer to the next node in the list
} list_t;

// Function to traverse and print the linked list
void traverse_list(list_t *head) {
    list_t *p = head;  // Initialize pointer p to start at the head of the list

    // Iterate through the list until reaching the end (NULL)
    while (p != NULL) {
        // Visit the current node - for example, print its key value
        printf("Node key: %d\n", p->key);

        // Move to the next node
        p = p->next;
    }
}

// Main function to demonstrate creating and traversing a linked list
int main() {
    // Creating three nodes using dynamic memory allocation
    list_t *node1 = (list_t *)malloc(sizeof(list_t));  // Allocate memory for the first node
    list_t *node2 = (list_t *)malloc(sizeof(list_t));  // Allocate memory for the second node
    list_t *node3 = (list_t *)malloc(sizeof(list_t));  // Allocate memory for the third node

    // Assign key values to the nodes
    node1->key = 10;  // Assigning value 10 to the first node
    node2->key = 20;  // Assigning value 20 to the second node
    node3->key = 30;  // Assigning value 30 to the third node

    // Linking the nodes
    node1->next = node2;  // First node points to second node
    node2->next = node3;  // Second node points to third node
    node3->next = NULL;   // Third node is the last, so it points to NULL

    // Traverse and print the linked list starting from the head (node1)
    printf("Traversing the linked list:\n");  // Print header before traversing the list
    traverse_list(node1);  // Call the function to traverse the list

    // Free the allocated memory
    free(node1);  // Free the memory allocated for the first node
    free(node2);  // Free the memory allocated for the second node
    free(node3);  // Free the memory allocated for the third node

    return 0;  // Return 0 to indicate successful execution
}

/*
Explanation of Functions:

This code demonstrates how to define, create, traverse, and clean up a linked list using a C
program. A linked list is a data structure consisting of nodes connected through pointers.
The nodes hold data and a reference to the next node in the sequence.

In this program, the linked list node is defined as a structure named `list_t`, containing an
integer `key` to store data and a pointer `next` to reference the next node. The `traverse_list`
function takes the head of the list and iteratively visits each node, printing its key value.

In the `main` function, three nodes are dynamically created using `malloc`, and values are assigned
to them. The nodes are linked together to form a simple list. The `traverse_list` function is then
used to print the data values of the linked list. After the traversal, the allocated memory for each
node is freed to prevent memory leaks. This example provides a basic understanding of linked list
operations, including creation, traversal, and memory management.
*/
