# README: Doubly Linked List Insert Function

This document provides a detailed explanation of the `insert` function for maintaining a doubly linked list where strings are stored alphabetically in sorted order. The implementation ensures correct manipulation of pointers, proper handling of memory allocation, and the ability to traverse and free the list efficiently.

## Function Signature
```c
void insert(element_t **head, element_t **tail, char *str);
```

- **Parameters:**
  - `head`: A pointer to the pointer of the head node of the doubly linked list.
  - `tail`: A pointer to the pointer of the tail node of the doubly linked list.
  - `str`: The string to be inserted into the list in its correct (alphabetical) position.
- **Return Value:**
  - The function does not return a value but modifies the list structure directly.

## Node Structure
The doubly linked list is implemented using the following structure:
```c
typedef struct element_s {
    char *name;              // The string stored in the node
    struct element_s *left;  // Pointer to the previous node
    struct element_s *right; // Pointer to the next node
} element_t;
```
- Each node stores a dynamically allocated string (`name`).
- `left` points to the previous node in the list, and `right` points to the next node.

## Algorithm Description

### Purpose
The `insert` function ensures that the list remains alphabetically sorted after inserting a new string. It handles the following scenarios:
1. **Empty List:** If the list is empty, the new node becomes both the head and the tail.
2. **Insert at Head:** If the new string is smaller than the current head, it is inserted at the beginning.
3. **Insert at Tail:** If the new string is larger than the current tail, it is appended to the end.
4. **Insert in Middle:** The function traverses the list to find the correct position and inserts the new node between two existing nodes.

### Steps:
1. **Node Creation:**
   - Allocate memory for the new node.
   - Copy the string into dynamically allocated memory.
2. **Empty List Case:**
   - If the list is empty, set both `head` and `tail` to the new node.
3. **Traverse the List:**
   - Use a pointer to traverse the list and locate the correct position for the new string.
   - Compare strings using `strcmp`.
4. **Insert at the Correct Position:**
   - Adjust the `left` and `right` pointers of the new node and adjacent nodes to maintain the doubly linked structure.
5. **Handle Edge Cases:**
   - Properly manage insertion at the beginning, end, or middle of the list.

## Code Implementation
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element_s {
    char *name;
    struct element_s *left;
    struct element_s *right;
} element_t;

void insert(element_t **head, element_t **tail, char *str) {
    element_t *newNode = (element_t *)malloc(sizeof(element_t));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    newNode->name = strdup(str);
    if (!newNode->name) {
        fprintf(stderr, "Memory allocation for string failed\n");
        free(newNode);
        return;
    }

    newNode->left = NULL;
    newNode->right = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    element_t *current = *head;
    while (current && strcmp(current->name, str) < 0) {
        current = current->right;
    }

    if (current == *head) {
        newNode->right = *head;
        (*head)->left = newNode;
        *head = newNode;
        return;
    }

    if (current == NULL) {
        newNode->left = *tail;
        (*tail)->right = newNode;
        *tail = newNode;
        return;
    }

    newNode->right = current;
    newNode->left = current->left;
    if (current->left) {
        current->left->right = newNode;
    }
    current->left = newNode;
}

void printListForward(element_t *head) {
    element_t *current = head;
    while (current) {
        printf("%s ", current->name);
        current = current->right;
    }
    printf("\n");
}

void printListBackward(element_t *tail) {
    element_t *current = tail;
    while (current) {
        printf("%s ", current->name);
        current = current->left;
    }
    printf("\n");
}

void freeList(element_t *head) {
    while (head) {
        element_t *temp = head;
        head = head->right;
        free(temp->name);
        free(temp);
    }
}

int main() {
    element_t *head = NULL;
    element_t *tail = NULL;

    insert(&head, &tail, "delta");
    insert(&head, &tail, "alpha");
    insert(&head, &tail, "charlie");
    insert(&head, &tail, "bravo");

    printf("List from head to tail:\n");
    printListForward(head);

    printf("List from tail to head:\n");
    printListBackward(tail);

    freeList(head);

    return 0;
}
```

## Example Execution

### Input:
Insert the strings:
- `"delta"`
- `"alpha"`
- `"charlie"`
- `"bravo"`

### Output:
```
List from head to tail:
alpha bravo charlie delta

List from tail to head:
delta charlie bravo alpha
```

## Complexity Analysis

1. **Time Complexity:**
   - Insertion: \(O(n)\) (traverses the list to find the correct position).
   - Printing: \(O(n)\) (traverses the entire list).
   - Freeing: \(O(n)\).
2. **Space Complexity:**
   - Each node requires additional space for the string and two pointers.

## Key Features

1. **Efficiency:**
   - The function maintains sorted order without needing to sort the list explicitly.
2. **Dynamic Memory Management:**
   - Nodes and strings are dynamically allocated and properly freed to avoid memory leaks.
3. **Traversal:**
   - Provides functions to traverse the list in both forward and backward directions.

## Limitations

1. **Memory Allocation:**
   - The function may fail if memory allocation fails for the node or string.
2. **String Comparison:**
   - Assumes strings are valid null-terminated strings.

## Conclusion
The `insert` function efficiently maintains a sorted doubly linked list. Its modular design and proper memory management make it a reliable solution for applications requiring dynamically ordered data. The implementation is easy to extend for additional functionality, such as deleting nodes or finding specific elements.

