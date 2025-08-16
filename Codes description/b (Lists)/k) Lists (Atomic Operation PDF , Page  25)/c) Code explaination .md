# Sentinel Search Function in a Linked List

This project demonstrates a C program that implements a linked list and a search function using a **sentinel node**. The goal is to simplify the search logic by adding a temporary sentinel node to the linked list, which helps avoid extra boundary checks during the search.

## Overview

The main components of the program are:
1. **Node Structure**: Defines the structure of a linked list node with an integer key and a pointer to the next node.
2. **Node Creation**: Function to create new nodes dynamically.
3. **Sentinel Search**: Function to search for a value in a linked list using a sentinel node to handle edge cases effectively.
4. **Printing the List**: Utility function to print all elements of the linked list.
5. **Main Function**: Demonstrates the usage of the above functions to create a list, search for a value, and print results.

## Code Structure

### 1. **Node Structure**
The `Node` structure represents an element in the linked list:
```c
typedef struct Node {
    int key;
    struct Node* next;
} Node;
```
Each node contains:
- `key`: The value stored in the node.
- `next`: A pointer to the next node in the list.

### 2. **Node Creation Function**
```c
Node* create_node(int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}
```
This function allocates memory for a new node, assigns it a key value, and initializes the `next` pointer to `NULL`.

### 3. **Sentinel Search Function**
The `sentinel_search` function adds a sentinel node to the end of the list, simplifying the search by eliminating the need to check if we've reached the end of the list:
```c
Node* sentinel_search(Node* head, int value) {
    // Create a sentinel node with the target value
    Node sentinel;
    sentinel.key = value;
    sentinel.next = NULL;

    // Attach the sentinel to the end of the list
    Node* p = head;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = &sentinel;

    // Search for the value
    while (value != p->key) {
        p = p->next;
    }

    // Remove the sentinel
    tail->next = NULL;

    // Return the found node or NULL
    if (p != &sentinel) {
        return p;
    } else {
        return NULL;
    }
}
```
- **Sentinel Node**: A temporary node with the target value is added to ensure that the loop always terminates.
- **List Restoration**: After the search, the list is restored by removing the sentinel.

### 4. **Print List Function**
The `print_list` function prints the linked list:
```c
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}
```
This function traverses the linked list from `head` to the end, printing each node's key.

### 5. **Main Function**
The `main` function demonstrates the use of the linked list and the sentinel search function:
```c
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
```
The `main` function performs the following steps:
- **Create** a linked list with nodes containing values 1, 2, 3, and 4.
- **Print** the list.
- **Search** for a target value (3) using the `sentinel_search` function.
- **Print** whether the target value was found.
- **Free** the allocated memory for all nodes to avoid memory leaks.

## How to Run
1. Compile the program using a C compiler, such as GCC:
   ```sh
   gcc -o linked_list_search linked_list_search.c
   ```
2. Run the executable:
   ```sh
   ./linked_list_search
   ```

## Notes
- The sentinel node simplifies the search logic but requires careful handling to avoid modifying the original list structure permanently.
- The program is designed to demonstrate a basic linked list and a search operation, suitable for educational purposes or as a basis for more advanced linked list operations.

