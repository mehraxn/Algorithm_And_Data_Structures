# README for Linked List Reverse Traverse and Delete Program

## Overview
This program demonstrates how to manipulate a linked list using recursion to traverse and delete elements. It includes three primary functions:
1. The `traverse_reverse` function: A recursive function to print the elements of a linked list in reverse order.
2. The `delete` function: A recursive function to delete a node with a specified value from the linked list.
3. The `main` function: A function that creates a sample linked list, demonstrates both the reverse traversal and delete operations, and frees the memory used by the list.

## Function Descriptions

### 1. `traverse_reverse` Function
The `traverse_reverse` function is responsible for printing the elements of the linked list in reverse order. It follows these steps:
- **Input Parameter**: Takes a pointer (`p`) to the head of the linked list.
- **Base Case**: If the pointer `p` is `NULL`, the function returns, indicating the end of the list has been reached.
- **Recursive Step**: The function first recursively calls itself with the next node (`p->next`). Once the recursion reaches the end of the list, each node's value is printed during the return phase.

This function demonstrates how recursion can be used to effectively traverse the linked list backward without explicitly using a stack or additional data structure.

### 2. `delete` Function
The `delete` function is responsible for removing a node with a specific value from the linked list. It follows these steps:
- **Input Parameters**: Takes a pointer (`p`) to the head of the linked list and an integer (`val`) representing the value to be deleted.
- **Base Case**: If the pointer `p` is `NULL`, it means the end of the list has been reached, and the function returns `NULL`.
- **Deletion Logic**: If the current node's key matches the value to be deleted (`p->key == val`), the function stores the next node in a temporary pointer (`t`), frees the current node, and returns the pointer to the next node (`t`).
- **Recursive Step**: If the current node does not match the value, the function recursively calls itself on the next node (`p->next`) and updates the `next` pointer accordingly.

This function efficiently deletes the specified node while maintaining the linked list structure.

### 3. `main` Function
The `main` function demonstrates the usage of the `traverse_reverse` and `delete` functions:
- **Linked List Creation**: A linked list with three nodes is created, containing the values `1`, `2`, and `3`.
- **Reverse Traversal**: The `traverse_reverse` function is called with the head of the list, and the elements are printed in reverse order.
- **Node Deletion**: The `delete` function is called to remove a node with a specified value (`2`), and the updated list is printed.
- **Memory Deallocation**: Finally, the allocated memory for the linked list is freed to avoid memory leaks.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc list_reverse_delete_functions.c -o list_reverse_delete
./list_reverse_delete
```

### Expected Output
The program will create a linked list with three elements (`1`, `2`, `3`), print the elements in reverse order, delete a specific node, and print the updated list:

```
Elements in reverse order: 3 2 1
List after deleting element 2: 1 3
```

## Summary
The linked list reverse traverse and delete program demonstrates how to manipulate linked lists using recursion. The **`traverse_reverse`** function is a simple yet effective example of how to print elements in reverse order using recursion, while the **`delete`** function shows how to recursively locate and remove a node with a specific value.

The **`main`** function ties everything together by creating a sample linked list, invoking both recursive functions to demonstrate their functionality, and ensuring that all dynamically allocated memory is properly freed.

This program is a helpful example for learning about linked lists, recursion, and efficient memory management in C programming.

