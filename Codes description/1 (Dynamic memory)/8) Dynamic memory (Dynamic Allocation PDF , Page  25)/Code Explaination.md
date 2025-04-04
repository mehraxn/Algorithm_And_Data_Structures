# README for Dynamic Memory Allocation Program in C

## Overview

This project contains two C programs that demonstrate the use of dynamic memory allocation techniques. The main focus is to show how to allocate, reallocate, and free memory in C using functions like `malloc()`, `realloc()`, and `free()`. This README provides an overview of the functionality, usage instructions, and key concepts demonstrated by the code.

## Structure of the Programs

The project consists of two main programs, each illustrating different aspects of dynamic memory management:

1. **Memory Allocation and Reallocation Program**: This program demonstrates how to allocate memory dynamically, reallocate it to increase capacity, and properly handle errors during memory operations.

2. **Dynamic and Static Array Handling Program**: This program illustrates both dynamic allocation and static array usage, showing how to interact with dynamically allocated memory as well as stack-allocated arrays.

## Program Descriptions

### 1. Memory Allocation and Reallocation Program

This program demonstrates how to allocate memory dynamically for an array of integers, expand the size using `realloc()`, and eventually release the memory using `free()`. The steps involved are as follows:

- Allocate memory for an array of 50 integers using `malloc()`.
- Reallocate the memory to expand the array to hold 100 integers using `realloc()`.
- Further reallocate to expand the array to hold 200 integers.
- Initialize all elements of the final array to zero.
- Free the allocated memory at the end to prevent memory leaks.

The program also includes error handling to check if memory allocation or reallocation fails. If an error occurs, an appropriate error message is printed, and the program terminates safely.

### 2. Dynamic and Static Array Handling Program

This program demonstrates how to use both static and dynamic arrays in C:

- A static array of size 100 (`v`) is declared on the stack.
- The user is prompted to enter the value of `n` (must be <= 100).
- Dynamic memory is allocated for an array of size `n` using `malloc()`.
- Error handling is included to ensure memory allocation succeeds.
- The dynamically allocated memory (`p`) is initialized to a specific value (all elements set to 1).
- The static array (`v`) is also initialized (all elements set to 2).
- Finally, the dynamically allocated memory is freed to avoid memory leaks.

## How to Run the Code

To run the programs, follow these steps:

1. **Compile the Code**: Use a C compiler, such as GCC, to compile the code. You can use the following command:
   ```sh
   gcc dynamic_memory_allocation.c -o dynamic_memory_allocation
   ```
2. **Execute the Program**: After compiling, run the program using:
   ```sh
   ./dynamic_memory_allocation
   ```
3. **Input Prompt**: The second program will prompt you to enter a value for `n`:
   ```
   Introduce n (<= 100):
   ```
   You can then enter a value for `n` that should be less than or equal to 100.

### Example Output

```
Introduce n (<= 100): 50
```
The program then initializes both the static and dynamic arrays and completes successfully.

## Explanation of Functions

### Memory Allocation Functions Used

1. **`malloc()`**: Allocates the specified number of bytes and returns a pointer to the allocated memory. In both programs, `malloc()` is used to allocate memory for arrays.

2. **`realloc()`**: Reallocates memory, expanding or shrinking the previously allocated memory block. It is used in the first program to increase the capacity of the array.

3. **`free()`**: Frees previously allocated memory to avoid memory leaks. Both programs use `free()` to release the dynamically allocated memory once it is no longer needed.

### Error Handling

The programs check if memory allocation (`malloc()` or `realloc()`) fails by verifying if the returned pointer is `NULL`. If allocation fails, an error message is printed, and the program exits gracefully, ensuring no undefined behavior.

## Key Concepts Demonstrated

- **Dynamic Memory Allocation**: Using `malloc()` and `realloc()` to allocate and manage memory during runtime.
- **Memory Reallocation**: Using `realloc()` to expand an existing memory block while preserving its content.
- **Error Handling**: Properly checking for memory allocation failures and handling them safely.
- **Static vs. Dynamic Arrays**: Demonstrating the difference between stack-allocated arrays (static) and heap-allocated arrays (dynamic).

## Learning Objectives

By studying and running these programs, you will:

- Understand how to use `malloc()`, `realloc()`, and `free()` to manage dynamic memory in C.
- Learn how to use dynamic memory safely, including handling errors and preventing memory leaks.
- Get a practical understanding of when and why to use dynamic memory versus static arrays.

## Prerequisites

- Basic knowledge of C programming.
- Understanding of pointers and arrays in C.
- Familiarity with standard I/O functions (`printf` and `scanf`).

## Conclusion

These programs provide a foundational understanding of dynamic memory allocation in C. By working through the examples, you will learn how to manage memory dynamically, safely expand memory blocks, and handle potential errors effectively. Dynamic memory allocation is a crucial concept in C programming, especially for managing large datasets or when the required memory size is not known at compile time.

Feel free to experiment with the code by changing the values, adding new operations, or extending the functionality to handle more complex scenarios.

