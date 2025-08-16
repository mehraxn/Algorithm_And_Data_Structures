# README: malloc2d and free2d Functions Example

## Overview

This project demonstrates the allocation, usage, and deallocation of a 2D array of characters in C. The key functions involved are `malloc2d()` and `free2d()`. The `malloc2d()` function is used to dynamically allocate memory for a 2D array of characters, while `free2d()` is used to free the allocated memory. The code also includes a `main()` function to demonstrate how these functions are used effectively for memory management.

### Files Included

- `free2d_function.c`: Contains the implementation of the `malloc2d()` and `free2d()` functions along with a `main()` function for demonstration purposes.

## Functions

### 1. malloc2d(char \*\*\*m, int r, int c)

The `malloc2d()` function is used to allocate memory for a 2D array of characters with the specified number of rows and columns.

- **Parameters**:
  - `char ***m`: A triple pointer used to return the address of the allocated memory for the 2D array.
  - `int r`: Number of rows to allocate.
  - `int c`: Number of columns to allocate.

- **Return Value**: This function does not return a value but modifies the provided triple pointer (`*m`) to point to the allocated 2D array.

- **Implementation Details**:
  - First, it allocates memory for an array of pointers, each representing a row of the 2D array.
  - Then, it allocates memory for each row, enough to hold `c` characters.
  - Proper error handling is implemented to check if memory allocation succeeds. If any allocation fails, the function frees any previously allocated memory to avoid memory leaks.
  - Finally, the allocated 2D array is assigned to the provided triple pointer (`*m`).

### 2. free2d(char \*\*\*m, int r)

The `free2d()` function is used to free the memory allocated for a 2D array of characters.

- **Parameters**:
  - `char ***m`: A triple pointer representing the address of the 2D array to be freed.
  - `int r`: Number of rows in the 2D array.

- **Implementation Details**:
  - The function first accesses the double pointer (`*m`) and assigns it to a local variable (`lm`) for easier access.
  - It then iterates over each row and frees the memory allocated for each row.
  - After freeing all rows, it frees the memory allocated for the row pointers.
  - Finally, the triple pointer (`*m`) is set to `NULL` to avoid dangling pointers, ensuring safety.

### 3. main()

The `main()` function demonstrates how to use the `malloc2d()` and `free2d()` functions to create, manipulate, and free a 2D array.

- **Implementation Details**:
  - Defines the number of rows (`rows`) and columns (`cols`) to be allocated.
  - Calls `malloc2d()` to allocate a 2D array with the specified dimensions.
  - Assigns character values (`A`, `B`, `C`, etc.) to the elements of the 2D array.
  - Prints the 2D array to the console.
  - Frees all allocated memory using `free2d()` to ensure proper memory management.

## Usage Instructions

1. **Compilation**:
   - Use the following command to compile the code:
     ```sh
     gcc -o free2d_function free2d_function.c
     ```
   - This will produce an executable named `free2d_function`.

2. **Running the Program**:
   - Run the program using:
     ```sh
     ./free2d_function
     ```
   - The program will allocate a 2D array of characters with 3 rows and 4 columns, fill it with character values (`A`, `B`, `C`, `D`), and display the resulting array.

## Example Output

When you run the program, it will produce the following output:

```
The 2D character array:
A B C D
A B C D
A B C D
```

## Memory Management

- The program uses `malloc()` to dynamically allocate memory for a 2D array of characters and `free()` to release it.
- **Proper Memory Management**: The program demonstrates the importance of freeing dynamically allocated memory after use to prevent memory leaks.
- In case of memory allocation failure, the program includes mechanisms to clean up any partially allocated memory before exiting, ensuring robust memory management.
- **Avoiding Dangling Pointers**: After freeing the memory, the pointers are set to `NULL` to avoid the risk of accessing invalid memory.

## Key Concepts Demonstrated

- **Dynamic Memory Allocation**: Using `malloc()` to allocate memory for both rows and columns of a 2D array.
- **Pointer Usage**: Utilizing a triple pointer (`char ***`) to allocate and return the address of the allocated memory for a 2D array.
- **Error Handling**: Proper checks are performed to ensure that memory allocation is successful. If not, the program exits gracefully after cleaning up.
- **Pointer Arithmetic**: Using pointers to access and manipulate elements of the dynamically allocated 2D array.

## Notes

- The number of rows and columns (`rows = 3`, `cols = 4`) used in the example can be modified to test different sizes of arrays.
- This code is intended for educational purposes, demonstrating the basics of dynamic memory allocation, proper memory management, and preventing dangling pointers in C.

## Dependencies

- **Standard Libraries**: The code uses the following standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For dynamic memory management functions such as `malloc()` and `free()`.

## License

This code is provided as-is for educational purposes. Feel free to modify and use it in your projects, but please note that no warranty is provided.

