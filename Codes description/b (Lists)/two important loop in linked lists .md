# Linked List in C

## Overview
This project demonstrates a simple singly linked list implementation in C. It includes functions for creating nodes, linking them, traversing the list, and freeing the allocated memory.

## Code Explanation
- **Structure Definition:**
  ```c
  typedef struct List list;
  struct List {
      int number;
      list *next;
  };
  ```
  This defines a `list` struct where each node holds an integer and a pointer to the next node.

- **Node Creation Function:**
  ```c
  list *make_struct(int input_number) {
      list *new = (list *)malloc(sizeof(list));
      if (new == NULL) {
          printf("Memory allocation failed\n");
          exit(1);
      }
      new->number = input_number;
      new->next = NULL;
      return new;
  }
  ```
  This function allocates memory for a new node, initializes it with the given value, and sets its `next` pointer to NULL.

- **Traversal and Memory Deallocation:**
  The program first prints the list, then deallocates all dynamically allocated nodes to prevent memory leaks.

## Difference between `while (head != NULL)` and `while (head->next != NULL)`

### 1. `while (head != NULL)`
- This loop **traverses the entire list**, including the last node.
- Example:
  ```c
  list *temp = head;
  while (temp != NULL) {
      printf("%d ", temp->number);
      temp = temp->next;
  }
  ```
- The loop continues **until `temp` becomes NULL**, meaning it processes every node in the list.

### 2. `while (head->next != NULL)`
- This loop **stops at the second-to-last node** because `head->next == NULL` for the last node.
- Example:
  ```c
  list *temp = head;
  while (temp->next != NULL) {
      printf("%d ", temp->number);
      temp = temp->next;
  }
  ```
- The last node is **not processed** inside this loop.

### **Key Difference**
| Condition | Last Node Processed? | Use Case |
|-----------|---------------------|----------|
| `while (head != NULL)` | ✅ Yes | Printing, Traversing, and Deleting the Entire List |
| `while (head->next != NULL)` | ❌ No | Stopping Before the Last Node (e.g., for linking operations) |

## Conclusion
Use `while (head != NULL)` when you want to **process all nodes**, and use `while (head->next != NULL)` when you **only need to process up to the second-to-last node** (e.g., when inserting at the end).

