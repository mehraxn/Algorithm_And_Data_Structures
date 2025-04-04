# Simple Memory Allocation Example in C

## Overview

This program demonstrates dynamic memory allocation for an integer using the `malloc` function in the C programming language. It provides a simple example of how to allocate memory at runtime, store a value entered by the user, and then release the allocated memory to ensure proper memory management.

### Purpose

The primary objectives of this program are:
1. To show how to dynamically allocate memory for a single integer using `malloc`.
2. To demonstrate the importance of checking for successful memory allocation.
3. To provide an example of proper memory management by releasing the allocated memory using `free()`.

## File Contents

### Header Files

- **`#include <stdio.h>`**: Provides standard input and output functions such as `printf`, `scanf`, and `fprintf`.
- **`#include <stdlib.h>`**: Provides memory allocation functions (`malloc`, `free`) and process control functions (`exit`).

### Main Function

#### 1. Memory Allocation

- **Declaration**: The program starts by declaring a pointer to an integer (`int *p`). This pointer will hold the address of the allocated memory.

- **Allocation of Memory**:
  - `p = (int *) malloc(1 * sizeof(int))`: Allocates memory for a single integer and explicitly casts the result of `malloc` to `int*`. Although the cast is not mandatory in C, it makes the type more explicit and can improve readability.
  - The program checks whether the allocation was successful by verifying if `p` is `NULL`. If `malloc` fails to allocate memory, `p` will be `NULL`, indicating that there is insufficient memory available.
  - If allocation fails, an error message is printed to `stderr`, and the program exits with a non-zero status (`exit(1)`).

#### 2. User Input and Output

- **Prompting User for Input**:
  - The program prompts the user to enter an integer value (`fprintf(stdout, "Introduce an integer value: ")`), and the value is read using `scanf("%d", p)`. The value entered by the user is stored in the dynamically allocated memory.

- **Printing the Entered Value**:
  - The value entered by the user is then printed using `printf("You entered: %d\n", *p)`. The dereference operator (`*p`) is used to access the value stored at the memory location pointed to by `p`.

#### 3. Memory Deallocation

- **Freeing Allocated Memory**:
  - The memory allocated for the integer is released using `free(p)`. This ensures that the program does not cause a memory leak by retaining allocated memory after it is no longer needed.

- **Exit the Program**:
  - The program returns `0` to indicate successful termination.

## Example Output

When the program runs, it will produce the following output:

```
Introduce an integer value: 42
You entered: 42
```

- The user is prompted to enter an integer value (in this example, `42`). The program then prints the value that was entered.

## Explanation

### Key Concepts

1. **Dynamic Memory Allocation**:
   - The `malloc` function is used to allocate memory at runtime, which is particularly useful when the exact size of the data is not known at compile time. In this program, memory is allocated for a single integer.
   - The `sizeof(int)` ensures that the correct amount of memory is allocated for the type of data being stored.

2. **Pointer Usage**:
   - The pointer `p` is used to store the address of the allocated memory. Using pointers allows direct access to the allocated memory, enabling the program to store and retrieve values.

3. **Error Handling**:
   - It is crucial to check if `malloc` was successful in allocating memory by verifying that the returned pointer (`p`) is not `NULL`. If `malloc` returns `NULL`, it indicates a memory allocation failure.

4. **Memory Management**:
   - Proper memory management is demonstrated by freeing the allocated memory using `free(p)`. Failure to free dynamically allocated memory can lead to memory leaks, which are a common issue in C programs.

### Summary

This program serves as a simple demonstration of dynamic memory allocation in C. By using `malloc` to allocate memory and `free` to release it, the program provides a foundational example of how to manage memory at runtime. The use of pointers, error handling, and proper deallocation are all key elements of good memory management practices, making this example a valuable learning tool for beginners in C programming.

