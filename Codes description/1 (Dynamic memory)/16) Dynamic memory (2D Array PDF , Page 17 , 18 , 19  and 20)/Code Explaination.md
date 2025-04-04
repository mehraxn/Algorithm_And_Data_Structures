# README: Matrix Manipulation Functions

## Overview
This project contains several C functions designed to demonstrate memory allocation, manipulation, and deallocation for both integer and string matrices. The code also demonstrates the usage of the `sizeof()` operator on static and dynamic arrays.

### Files Included
- `matrix_functions.c`: Contains the implementation of functions for allocating, manipulating, and freeing matrices.

## Functions

### 1. allocate_int_matrix(int *r, int *c)
This function is responsible for allocating memory for an integer matrix based on user-specified dimensions.
- **Parameters**: Takes pointers to row (`*r`) and column (`*c`) counts as input.
- **Return Value**: Returns a pointer to the allocated matrix (`int**`).
- **Implementation Details**:
  - Prompts the user to input the number of rows and columns.
  - Allocates memory for each row and handles any memory allocation errors.
  - If any memory allocation fails, it ensures proper cleanup of already allocated memory.

### 2. manipulate_and_free_matrix(int **mat, int r, int c)
This function is used to manipulate the values of an integer matrix and free the allocated memory.
- **Parameters**: Takes the allocated matrix (`int**`), row count (`r`), and column count (`c`) as input.
- **Implementation Details**:
  - Prompts the user to input values for each element of the matrix.
  - After use, the memory allocated for the matrix is deallocated to avoid memory leaks.

### 3. allocate_string_matrix(int *r)
This function allocates memory for a matrix of strings based on user input.
- **Parameters**: Takes a pointer to the row count (`*r`) as input.
- **Return Value**: Returns a pointer to the allocated matrix (`char**`).
- **Implementation Details**:
  - Prompts the user for the number of rows.
  - Allocates memory for each string and handles any memory allocation errors.
  - Prompts the user to input strings for each row, ensuring the memory is correctly allocated for each string.
  - Proper cleanup is implemented in case of any errors during allocation.

### 4. sizeof_demo()
This function demonstrates the usage of the `sizeof()` operator on both statically and dynamically allocated arrays.
- **Implementation Details**:
  - Defines a statically allocated 2D array and prints the sizes of different elements using `sizeof()`.
  - Dynamically allocates a 2D array, prints the sizes of different elements, and then deallocates the memory.
  - The `sizeof()` operator is used to showcase the differences in memory size between static and dynamic arrays.

## Usage Instructions
The main function in this program executes the following steps:
1. **Integer Matrix Allocation and Manipulation**:
   - Calls `allocate_int_matrix()` to allocate memory for an integer matrix.
   - Allows the user to input values for the matrix.
   - Calls `manipulate_and_free_matrix()` to manipulate and then free the matrix.

2. **String Matrix Allocation**:
   - Calls `allocate_string_matrix()` to allocate memory for a matrix of strings.
   - Prompts the user to input strings, stores them, and then prints the stored strings.
   - Deallocates the memory used by the strings.

3. **Sizeof Demonstration**:
   - Calls `sizeof_demo()` to demonstrate how `sizeof()` works with static and dynamic arrays.

## Memory Management
- All functions are designed to properly manage memory, ensuring that no memory leaks occur.
- The functions that allocate memory also include error handling to free any memory that was partially allocated if an error occurs.

## Example Output
Below is an example output of running the program:
```
Example: Integer Matrix Allocation and Manipulation
Number of rows: 2
Number of columns: 3
Enter values for the integer matrix:
mat[0][0]: 1
mat[0][1]: 2
mat[0][2]: 3
mat[1][0]: 4
mat[1][1]: 5
mat[1][2]: 6

Example: String Matrix Allocation
Number of rows: 2
Enter string for row 0: hello
Enter string for row 1: world
Stored Strings:
String 0: hello
String 1: world

Example: sizeof() Demonstration
sizeof(mat): 120
sizeof(mat[i]): 20
sizeof(mat[i][j]): 4
sizeof(dyn_mat): 8
sizeof(dyn_mat[i]): 8
sizeof(dyn_mat[i][j]): 4

All functions executed successfully and behaved as expected.
```

## Dependencies
- The code uses the standard libraries `<stdio.h>`, `<stdlib.h>`, and `<string.h>` for input/output operations, dynamic memory allocation, and string handling, respectively.

## Compilation
To compile the code, use the following command:
```sh
gcc -o matrix_functions matrix_functions.c
```
To run the program, use:
```sh
./matrix_functions
```

## Notes
- The program requires the user to input the matrix dimensions and values, making it interactive.
- Proper memory management is critical to ensure the program runs without memory leaks or crashes.

## License
This code is provided as-is for educational purposes, and no warranty is provided. Feel free to modify and use it in your projects.

