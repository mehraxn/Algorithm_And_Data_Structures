# Dynamic Memory Allocation from File in C

## Overview

This program demonstrates how to dynamically allocate memory for an integer array by reading data from a file in the C programming language. The program includes a function that opens a file, reads an integer value representing the number of elements (`n`), allocates memory for an array of `n` integers, fills the array with values from the file, and returns a pointer to the allocated memory.

### Purpose

The purpose of this program is to:
1. Show how to read an integer value from a file to determine the size of an array.
2. Demonstrate how to dynamically allocate memory for an array based on the value read from a file.
3. Provide a complete example of reading values from a file, storing them in dynamically allocated memory, and ensuring proper memory management by deallocating the memory when done.

## File Contents

### Header Files

- **`#include <stdio.h>`**: Provides standard input and output functions such as `printf`, `fscanf`, and `fprintf`.
- **`#include <stdlib.h>`**: Provides functions for dynamic memory allocation (`malloc`, `free`) and process control (`exit`).

### Function Details

#### `int *allocateArrayFromFile(const char *filename, int *n)`

This function is responsible for reading the size of an array from a file, dynamically allocating memory for the array, and filling the array with values from the file.

- **Parameters**:
  - `const char *filename`: The name of the file that contains the size of the array (`n`) and the array elements.
  - `int *n`: A pointer to an integer where the function will store the number of elements read from the file.

- **Steps**:
  1. **Open the File**: The function attempts to open the file specified by `filename` in read mode (`"r"`). If the file cannot be opened, an error message is printed to `stderr`, and the program exits with an error code (`1`).
  2. **Read the Size of the Array (`n`)**: The function reads the value of `n` from the file using `fscanf(file, "%d", n)`. This value determines how many elements the array will hold.
  3. **Allocate Memory for the Array**: The function uses `malloc` to allocate memory for `n` integers (`*n * sizeof(int)`). If `malloc` returns `NULL`, indicating that the memory allocation failed, an error message is printed, the file is closed, and the program exits.
  4. **Read Array Elements**: The function reads `n` integers from the file and stores them in the allocated memory. A loop iterates from `0` to `n - 1`, reading each value into `ptr[i]`.
  5. **Close the File**: Once all values have been read, the function closes the file.
  6. **Return the Pointer**: The function returns a pointer to the dynamically allocated array.

#### `int main()`

The `main` function serves as a demonstration of how to use `allocateArrayFromFile` to read an array from a file and manage the dynamically allocated memory.

- **Steps**:
  1. **Declare Variables**: An integer `n` to hold the size of the array and a pointer `array` to store the address of the allocated memory.
  2. **Call `allocateArrayFromFile`**: The function is called with the name of the input file (`"input.txt"`) and the address of `n`. The function returns a pointer to the allocated array, which is assigned to `array`.
  3. **Print Array Elements**: The program iterates through the array, printing each element.
  4. **Free Allocated Memory**: The program releases the allocated memory using `free(array)` to avoid memory leaks.

### Example Output

If the input file (`input.txt`) contains the following data:

```
5
10 20 30 40 50
```

The output of the program would be:

```
Array elements:
10 20 30 40 50 
```

### Explanation

This program showcases a common scenario in C programming where dynamic memory allocation is necessary. The `allocateArrayFromFile` function reads the size of an array from a file and uses `malloc` to allocate memory based on that size. Once allocated, the memory is used to store the values read from the file, and the array elements are printed.

### Key Concepts

1. **Dynamic Memory Allocation**:
   - The program uses `malloc` to allocate memory at runtime based on the value read from the file. This is particularly useful when the size of the data is not known at compile time.

2. **File Handling**:
   - The function opens a file, reads data, and closes the file once the data is no longer needed. Proper file handling ensures that system resources are managed effectively.

3. **Memory Management**:
   - Proper memory management is demonstrated by freeing the allocated memory with `free()`. This prevents memory leaks, which can lead to issues in larger or more complex programs.

4. **Error Handling**:
   - The program includes error handling for file operations (`fopen`) and memory allocation (`malloc`). If an error occurs, appropriate messages are displayed, and the program exits gracefully.

### Summary

This program provides a complete example of dynamic memory allocation, file handling, and memory management in C. The function `allocateArrayFromFile` reads an integer (`n`) from a file to determine the size of an array, allocates memory accordingly, and fills the array with values read from the file. The `main` function demonstrates the use of this dynamically allocated array and ensures that the allocated memory is freed before the program exits. This is a foundational example for learning how to handle dynamic data sizes and manage memory effectively in C programming.