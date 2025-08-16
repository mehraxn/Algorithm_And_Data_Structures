# README: Dynamic Memory Allocation and File Handling in C

## Overview

This program demonstrates two different approaches to dynamically allocate memory for an integer array by reading the data from a file in the C programming language. It provides two versions of a function (`read_and_store` and `read_and_store_v2`) that handle reading an integer (`n`) from a file to determine the number of elements, allocating memory for those elements, and storing them in dynamically allocated memory. The allocated memory is then utilized to print the data, and proper memory management is ensured by freeing the allocated memory.

### Purpose

The primary objectives of this program are:
1. To show different techniques for working with dynamic memory allocation in C.
2. To demonstrate the use of file handling to read input data and allocate memory accordingly.
3. To emphasize the importance of proper memory allocation, error handling, and memory management.

## File Contents

### Header Files

- **`#include <stdio.h>`**: Provides standard input and output functions like `printf`, `fscanf`, and `fprintf`.
- **`#include <stdlib.h>`**: Provides functions for dynamic memory allocation (`malloc`, `free`) and process control (`exit`).

### Function Descriptions

#### 1. `void read_and_store(int **ptr, int *n)`

- **Purpose**: This function reads the number of elements (`n`) from a file, allocates memory for an integer array of size `n`, and stores the values from the file into the allocated memory.

- **Steps**:
  1. **Open the File**: Opens the file `input.txt` in read mode (`"r"`). If the file cannot be opened, an error message is printed, and the program exits.
  2. **Read the Size (`n`)**: Reads the number of elements (`n`) from the file.
  3. **Allocate Memory**: Uses `malloc` to allocate memory for `n` integers. If memory allocation fails, an error message is printed, the file is closed, and the program exits.
  4. **Read Values into Array**: Reads `n` integers from the file and stores them in the allocated memory (`*ptr`).
  5. **Close the File**: Closes the file after reading all the values.

- **Note**: This version works directly with a double pointer (`**ptr`) to manage the memory allocation.

#### 2. `void read_and_store_v2(int **ptr, int *n)`

- **Purpose**: This function performs the same task as `read_and_store`, but it uses a local pointer (`lptr`) to manage the memory allocation separately before assigning it to the double pointer.

- **Steps**:
  1. **Open the File**: Opens the file `input.txt` in read mode. If the file cannot be opened, an error message is printed, and the program exits.
  2. **Read the Size (`n`)**: Reads the number of elements (`n`) from the file.
  3. **Allocate Memory**: Uses a local pointer (`lptr`) to allocate memory for `n` integers using `malloc`. If memory allocation fails, an error message is printed, the file is closed, and the program exits.
  4. **Read Values into Array**: Reads `n` integers from the file and stores them in the allocated memory (`lptr`).
  5. **Assign Pointer**: Assigns the allocated memory (`lptr`) to the double pointer (`*ptr`).
  6. **Close the File**: Closes the file after reading all the values.

- **Note**: This version makes it explicit that memory allocation is done separately using a local pointer, and then the allocated memory is assigned to the double pointer.

### Main Function

The `main` function demonstrates how to use both versions of the `read_and_store` function to read data from a file and manage dynamically allocated memory.

- **Steps**:
  1. **First Version**: Calls `read_and_store(&array, &n)` to read data and allocate memory. Then, it prints the elements of the array and frees the allocated memory.
  2. **Second Version**: Calls `read_and_store_v2(&array, &n)` to read data and allocate memory. It also prints the elements of the array and frees the allocated memory.

### Example Output

Assuming the input file (`input.txt`) contains the following data:
```
5
10 20 30 40 50
```

The output of the program will be:
```
Using the first version:
10 20 30 40 50

Using the second version:
10 20 30 40 50
```

### Key Concepts

1. **Dynamic Memory Allocation**:
   - The program uses `malloc` to allocate memory at runtime based on the number of elements read from the file. This allows flexibility in handling data sizes that are determined during execution.

2. **File Handling**:
   - The program reads the input data from a file, allowing dynamic data management rather than using hard-coded values.
   - Proper file handling is demonstrated by opening, reading from, and closing the file to ensure system resources are managed effectively.

3. **Error Handling**:
   - Both functions include error checks for file operations (`fopen`) and memory allocation (`malloc`). If an error occurs, appropriate messages are displayed, and the program exits safely to prevent undefined behavior.

4. **Memory Management**:
   - The `free()` function is used to deallocate the memory that was dynamically allocated, preventing memory leaks.

### Summary

This program provides two approaches to reading data from a file and dynamically allocating memory for an array in C. The two versions of the `read_and_store` function illustrate different ways to manage pointers and allocate memory, emphasizing flexibility in function design. The use of both direct double pointer manipulation and local pointer assignment helps in understanding how memory can be allocated and managed in different scenarios. Proper error handling and memory management are also demonstrated to help ensure that the program operates safely and efficiently.

