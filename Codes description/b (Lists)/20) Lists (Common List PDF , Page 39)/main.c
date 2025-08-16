#include <stdio.h>
#include <stdlib.h>

// Definition of list_s1 structure, which contains pointers to next list_s1 and list_s2
typedef struct list_s1 {
    int key;                      // The value stored in the node
    struct list_s1 *next;         // Pointer to the next list_s1 node
    struct list_s2 *right;        // Pointer to a list_s2 node
} list_t1;

// Definition of list_s2 structure, which contains pointers to next list_s2
typedef struct list_s2 {
    int key;                      // The value stored in the node
    struct list_s2 *next;         // Pointer to the next list_s2 node
} list_t2;

// Function to create a new list_s1 node
list_t1* create_node_list1(int key) {
    list_t1 *new_node = (list_t1*)malloc(sizeof(list_t1));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed for list_s1.\n");
        exit(1);
    }
    new_node->key = key;
    new_node->next = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to create a new list_s2 node
list_t2* create_node_list2(int key) {
    list_t2 *new_node = (list_t2*)malloc(sizeof(list_t2));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed for list_s2.\n");
        exit(1);
    }
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new list_s1 node at the end of the list
list_t1* insert_end_list1(list_t1 *head, int key) {
    list_t1 *new_node = create_node_list1(key);
    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        return new_node;
    }

    list_t1 *current = head;
    while (current->next != NULL) {
        current = current->next;  // Traverse to the last node
    }

    // Insert the new node at the end
    current->next = new_node;

    return head;  // Return the updated head of the list
}

// Function to insert a new list_s2 node into a list_s1 node's right pointer
list_t1* insert_list2_to_list1(list_t1 *node, int key) {
    if (node == NULL) {
        fprintf(stderr, "Error: list_s1 node is NULL.\n");
        return NULL;
    }

    list_t2 *new_node = create_node_list2(key);
    if (node->right == NULL) {
        // If there are no list_s2 nodes attached, add the first one
        node->right = new_node;
    } else {
        list_t2 *current = node->right;
        while (current->next != NULL) {
            current = current->next;  // Traverse to the last list_s2 node
        }
        current->next = new_node;  // Insert the new node at the end
    }

    return node;
}

// Function to print the list of lists
void print_list_of_lists(list_t1 *head) {
    list_t1 *current_list1 = head;
    while (current_list1 != NULL) {
        printf("List1 Node Key: %d\n", current_list1->key);
        list_t2 *current_list2 = current_list1->right;
        printf("  List2 Nodes: ");
        while (current_list2 != NULL) {
            printf("%d -> ", current_list2->key);
            current_list2 = current_list2->next;
        }
        printf("NULL\n");
        current_list1 = current_list1->next;
    }
}

// Main function to demonstrate the list of lists
int main() {
    list_t1 *head = NULL;  // Initialize the head of list_s1 as NULL (empty list)

    // Insert values into list_s1
    head = insert_end_list1(head, 1);
    head = insert_end_list1(head, 2);
    head = insert_end_list1(head, 3);

    // Insert values into list_s2 linked to list_s1 nodes
    insert_list2_to_list1(head, 10);
    insert_list2_to_list1(head, 20);
    insert_list2_to_list1(head->next, 30);
    insert_list2_to_list1(head->next, 40);
    insert_list2_to_list1(head->next->next, 50);

    // Print the list of lists
    printf("List of Lists:\n");
    print_list_of_lists(head);

    // Free all allocated memory
    list_t1 *current_list1 = head;
    while (current_list1 != NULL) {
        list_t2 *current_list2 = current_list1->right;
        while (current_list2 != NULL) {
            list_t2 *temp_list2 = current_list2;
            current_list2 = current_list2->next;
            free(temp_list2);
        }
        list_t1 *temp_list1 = current_list1;
        current_list1 = current_list1->next;
        free(temp_list1);
    }

    return 0;
}

/*
Summary of Functions in the Code:

1. create_node_list1(int key):
   - Creates a new list_s1 node with the given value.
   - Allocates memory for the new node and initializes its key, next, and right pointers.
   - Returns a pointer to the newly created node.

2. create_node_list2(int key):
   - Creates a new list_s2 node with the given value.
   - Allocates memory for the new node and initializes its key and next pointer.
   - Returns a pointer to the newly created node.

3. insert_end_list1(list_t1 *head, int key):
   - Inserts a new list_s1 node with the specified value at the end of the list_s1.
   - If the list is empty, the new node becomes the head.
   - Returns the updated head of the list.

4. insert_list2_to_list1(list_t1 *node, int key):
   - Inserts a new list_s2 node with the specified value into the right pointer of a given list_s1 node.
   - If there are no existing list_s2 nodes, the new node becomes the first list_s2 node.
   - Returns the updated list_s1 node.

5. print_list_of_lists(list_t1 *head):
   - Prints all elements of the list of lists, including list_s1 nodes and their linked list_s2 nodes.

6. main():
   - Demonstrates the use of the `insert_end_list1()`, `insert_list2_to_list1()`, and `print_list_of_lists()` functions.
   - Inserts values into both list_s1 and list_s2, prints the list of lists, and frees all allocated memory to avoid memory leaks.
*/
