# Linked List Count and Traverse Program

## Overview
        This program demonstrates how to use recursion to count and traverse elements in a linked list. It includes three main components:
1. The `count` function: A recursive function that counts the number of elements in the linked list.
2. The `traverse` function: A recursive function that traverses and prints each element in the linked list.
3. The `main` function: A function that creates a linked list, calls both `count` and `traverse`, and then frees the memory used by the list.

## Function Descriptions

### 1. `count` Function
        The `count` function is responsible for calculating the total number of elements in the linked list. It follows these steps:
- **Input Parameter**: Takes a pointer (`p`) to the head of the linked list.
- **Base Case**: If the pointer `p` is `NULL`, it means the end of the list has been reached, and the function returns `0`.
- **Recursive Step**: Otherwise, the function returns `1 + count(p->next)`. This means that for each node, it adds `1` to the total count and proceeds to the next node.

This function uses recursion to traverse each node in the linked list, accumulating a count of all the nodes until the end is reached.

### 2. `traverse` Function
        The `traverse` function is used to print the values of each element in the linked list. It follows these steps:
- **Input Parameter**: Takes a pointer (`p`) to the head of the linked list.
- **Base Case**: If the pointer `p` is `NULL`, the function simply returns, indicating that the end of the list has been reached.
- **Recursive Step**: If `p` is not `NULL`, the function prints the value of the current node (`p->key`) and then recursively calls itself with the next node (`p->next`).

This function demonstrates how recursion can be used to traverse a linked list and print each element in sequence.

### 3. `main` Function
        The `main` function creates a simple linked list for demonstration purposes and calls both the `count` and `traverse` functions:
- **Linked List Creation**: The linked list is manually constructed with three nodes containing the values `1`, `2`, and `3`, forming the structure `1 -> 2 -> 3 -> NULL`.
- **Counting Elements**: The `count` function is called with the head of the list, and the total number of elements is printed.
- **Traversing Elements**: The `traverse` function is called with the head of the list to print the values of all elements.
- **Memory Deallocation**: Finally, a loop is used to free the memory allocated for each node to avoid memory leaks.

## How to Compile and Run the Program
        To compile and run the program, use the following commands in your terminal:

```sh
        gcc list_count_traverse.c -o list_count_traverse
./list_count_traverse
```

### Expected Output
The program will create a linked list with three elements (`1`, `2`, `3`), count the elements, and print their values:

```
Total number of elements: 3
Elements in the list: 1 2 3
```

## Summary
        The linked list count and traverse program provides a simple demonstration of how recursion can be used to manipulate linked data structures. The **`count`** function recursively counts the number of elements in the list, while the **`traverse`** function recursively prints each element.

The **`main`** function ties everything together by creating a linked list, calling the recursive functions to demonstrate their functionality, and freeing the allocated memory to ensure there are no memory leaks.

This program is a good introduction to working with linked lists and recursion, offering insights into how recursive functions can be used to perform common operations on linked data structures efficiently.

