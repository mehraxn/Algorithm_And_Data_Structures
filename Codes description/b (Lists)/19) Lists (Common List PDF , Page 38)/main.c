#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly linked list node structure
typedef struct list_s {
    int key;                   // The value stored in the node
    struct list_s *left;       // Pointer to the previous node
    struct list_s *right;      // Pointer to the next node
} list_t;

// Function to create a new doubly linked list node
list_t* create_node(int key) {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into the doubly linked list at the end
list_t* insert_end(list_t *head, int key) {
    list_t *new_node = create_node(key);
    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        return new_node;
    }

    list_t *current = head;
    while (current->right != NULL) {
        current = current->right;  // Traverse to the last node
    }

    // Insert the new node at the end
    current->right = new_node;
    new_node->left = current;

    return head;  // Return the updated head of the list
}

// Function to remove a node from the doubly linked list
list_t* remove_node(list_t *head, int key) {
    if (head == NULL) {
        fprintf(stderr, "Error: empty list\n");
        return NULL;
    }

    list_t *current = head;

    // Traverse the list to find the node to be removed
    while (current != NULL && current->key != key) {
        current = current->right;
    }

    if (current == NULL) {
        // If the key is not found
        fprintf(stderr, "Error: value not found in the list\n");
        return head;
    }

    // If the node to be removed is the head
    if (current == head) {
        head = current->right;
        if (head != NULL) {
            head->left = NULL;
        }
    } else {
        // Update the pointers of the adjacent nodes
        if (current->left != NULL) {
            current->left->right = current->right;
        }
        if (current->right != NULL) {
            current->right->left = current->left;
        }
    }

    free(current);  // Free the memory of the removed node
    return head;  // Return the updated head of the list
}

// Function to print the doubly linked list from head to tail
void print_list_forward(list_t *head) {
    list_t *current = head;
    printf("List (forward): ");
    while (current != NULL) {
        printf("%d <-> ", current->key);
        current = current->right;
    }
    printf("NULL\n");
}

// Function to print the doubly linked list from tail to head
void print_list_backward(list_t *head) {
    if (head == NULL) {
        printf("List (backward): NULL\n");
        return;
    }

    // Traverse to the last node
    list_t *current = head;
    while (current->right != NULL) {
        current = current->right;
    }

    // Print the list from tail to head
    printf("List (backward): ");
    while (current != NULL) {
        printf("%d <-> ", current->key);
        current = current->left;
    }
    printf("NULL\n");
}

// Main function to demonstrate the doubly linked list operations
int main() {
    list_t *head = NULL;  // Initialize the head of the list as NULL (empty list)

    // Insert values into the doubly linked list
    head = insert_end(head, 10);
    head = insert_end(head, 20);
    head = insert_end(head, 30);
    head = insert_end(head, 40);

    // Print the list in forward and backward directions
    printf("Doubly Linked List after insertions:\n");
    print_list_forward(head);
    print_list_backward(head);

    // Remove a value from the list
    head = remove_node(head, 20);
    printf("Doubly Linked List after removing 20:\n");
    print_list_forward(head);
    print_list_backward(head);

    // Remove a value that does not exist
    head = remove_node(head, 50);
    printf("Doubly Linked List after attempting to remove 50:\n");
    print_list_forward(head);
    print_list_backward(head);

    // Free the remaining list nodes
    while (head != NULL) {
        list_t *temp = head;
        head = head->right;
        free(temp);
    }

    return 0;
}

/*
Summary of Functions in the Code:

1. create_node(int key):
   - Creates a new doubly linked list node with the given value.
   - Allocates memory for the new node, initializes its key, and sets the left and right pointers to NULL.
   - Returns a pointer to the newly created node.

2. insert_end(list_t *head, int key):
   - Inserts a new node with the specified value at the end of the doubly linked list.
   - If the list is empty, the new node becomes the head.
   - Returns the updated head of the list.

3. remove_node(list_t *head, int key):
   - Removes a node with the specified value from the doubly linked list.
   - If the list is empty or the value is not found, an error message is printed.
   - Returns the updated head of the list.

4. print_list_forward(list_t *head):
   - Prints the elements of the doubly linked list from head to tail.

5. print_list_backward(list_t *head):
   - Prints the elements of the doubly linked list from tail to head.

6. main():
   - Demonstrates the use of the `insert_end()`, `remove_node()`, `print_list_forward()`, and `print_list_backward()` functions.
   - Inserts values into the list, removes values, and prints the list after each operation.
   - Frees all remaining nodes to avoid memory leaks.
*/
