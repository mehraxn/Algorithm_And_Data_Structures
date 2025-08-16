# Sorted Linked List Insert Function in C

This project demonstrates the implementation of a **sorted linked list** in C, with the primary focus on an `insert` function that keeps the list sorted as new elements are added. The linked list is implemented using dynamically allocated nodes, providing an efficient way to maintain sorted data without using additional sorting operations.

## Overview

The code includes the following components:
1. **Node Structure**: Defines the structure of each node in the linked list.
2. **New Element Function**: Dynamically allocates memory for new nodes.
3. **Insert Function**: Inserts elements into the linked list in sorted order.
4. **Print List Function**: Prints all elements in the linked list for easy visualization.
5. **Main Function**: Demonstrates the usage of the `insert` function to maintain a sorted linked list.

## Code Structure

### 1. **Node Structure**
The `list_t` structure represents a node in the linked list:
```c
typedef struct list {
    int key;                // The value stored in the node
    struct list *next;      // Pointer to the next node in the list
} list_t;
```
Each node contains:
- `key`: The value stored in the node.
- `next`: A pointer to the next node in the linked list.

### 2. **New Element Function**
The `new_element` function creates a new node:
```c
list_t* new_element() {
    list_t *new_node = (list_t*)malloc(sizeof(list_t));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}
```
- **Memory Allocation**: Allocates memory for a new node.
- **Error Handling**: If memory allocation fails, it prints an error message and exits the program.

### 3. **Insert Function**
The `insert` function adds a new element into the linked list in sorted order:
```c
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
```
- **Insert at the Beginning**: If the list is empty or if the new value is smaller than the current head's value, the new element becomes the new head.
- **Insert in the Middle or End**: Otherwise, the function traverses the list to find the correct position and inserts the new element to maintain the sorted order.

### 4. **Print List Function**
The `print_list` function prints all elements in the linked list:
```c
void print_list(list_t *head) {
    list_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}
```
- **Traverse and Print**: Iterates through the linked list from the head and prints each node's value.
- **Visual Representation**: Helps to visualize the current state of the linked list.

### 5. **Main Function**
The `main` function demonstrates how to use the `insert` function:
```c
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
```
- **Initialization**: The linked list is initially empty (`head = NULL`).
- **Insert Operations**: The `insert` function is called multiple times to add values `20`, `10`, `30`, and `25` into the linked list in sorted order.
- **Print the List**: The `print_list` function is used to print the linked list after all insertions.

## How to Run
1. **Compile the Code**: Use a C compiler like GCC to compile the code:
   ```sh
   gcc -o sorted_linked_list sorted_linked_list.c
   ```
2. **Run the Executable**:
   ```sh
   ./sorted_linked_list
   ```

## Notes
- **Sorted Insertions**: The `insert` function ensures that the linked list remains sorted as new elements are added, without requiring a separate sorting step.
- **Dynamic Memory Allocation**: Each node is dynamically allocated using `malloc`, and the code handles memory allocation failures by exiting the program with an error message.
- **Scalability**: The linked list structure allows dynamic resizing and efficient insertion, especially for maintaining sorted data without the overhead of shifting elements as in arrays.
- **Edge Cases**: The function handles edge cases such as inserting into an empty list or inserting a value smaller than the current head.

## Benefits of Using a Linked List for Sorted Data
- **Efficient Insertion**: Inserting a new value into a linked list can be done in O(n) time, as it only requires traversal and pointer manipulation.
- **Dynamic Size**: Unlike arrays, linked lists do not require a predefined size, making them flexible for applications where the number of elements is not known in advance.
- **Maintaining Order**: The `insert` function makes it easy to keep the list in a sorted state, which is useful for applications like priority queues or maintaining sorted collections.

