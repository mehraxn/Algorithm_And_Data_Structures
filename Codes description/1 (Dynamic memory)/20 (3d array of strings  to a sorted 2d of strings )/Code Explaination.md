# README: Static 3D Array to Sorted Dynamic 2D Array

## Overview

This project demonstrates how to convert a static 3D array of strings into a dynamically allocated 2D array, which is then sorted alphabetically. The key aspects covered include dynamic memory allocation, copying data from a static array to a dynamic one, sorting strings using `qsort()`, and proper memory management.

### Files Included

- `3d_to_2d_array_sort.c`: Contains the implementation of the main function that performs the conversion, sorting, and memory deallocation.

## Functions

### 1. compare_strings(const void *a, const void *b)

The `compare_strings()` function is used as a custom comparison function for `qsort()` to sort the strings alphabetically.

- **Parameters**:
  - `const void *a`: A pointer to the first element to be compared.
  - `const void *b`: A pointer to the second element to be compared.

- **Return Value**: Returns a negative value, zero, or a positive value, depending on whether the first string is less than, equal to, or greater than the second string.

- **Implementation Details**:
  - The function takes two pointers (`const void *`) and casts them to `const char **` to correctly access the strings.
  - It then uses `strcmp()` to compare the strings.

### 2. main()

The `main()` function demonstrates how to convert a static 3D array of strings into a sorted 2D dynamic array.

- **Implementation Details**:
  - **Static 3D Array Initialization**: Defines a 3D array of strings with random names (`names[3][2][20]`), containing 3 sets of 2 names each.
  - **Dynamic 2D Array Allocation**: Allocates memory for the dynamic 2D array (`sorted_array`) to store all the names from the static array.
  - **Copying Strings**: Copies each string from the static 3D array to the dynamically allocated 2D array, ensuring proper memory allocation for each string.
  - **Sorting the Strings**: Uses the `qsort()` function with the `compare_strings()` function to sort the 2D array of strings alphabetically.
  - **Printing and Freeing Memory**: Prints the sorted array to the console and then frees all allocated memory to ensure proper memory management.

## Usage Instructions

1. **Compilation**:
   - Use the following command to compile the code:
     ```sh
     gcc -o 3d_to_2d_array_sort 3d_to_2d_array_sort.c
     ```
   - This will produce an executable named `3d_to_2d_array_sort`.

2. **Running the Program**:
   - Run the program using:
     ```sh
     ./3d_to_2d_array_sort
     ```
   - The program will convert the static 3D array to a sorted dynamic 2D array and print the sorted names.

## Example Output

When you run the program, it will produce the following output:

```
Sorted names:
Alice
Bob
Charlie
David
Eve
Frank
```

## Memory Management

- **Dynamic Allocation**: Memory is dynamically allocated for a 2D array of strings using `malloc()`. Each string is individually allocated to ensure flexibility.
- **Proper Memory Deallocation**: After processing, all dynamically allocated memory is properly deallocated using `free()`. This is crucial to prevent memory leaks.
- **Error Handling**: Proper checks are performed to ensure that memory allocation is successful. In case of allocation failure, the program exits gracefully after cleaning up any previously allocated memory.

## Key Concepts Demonstrated

- **Static to Dynamic Conversion**: Converting a statically defined 3D array into a dynamically allocated 2D array for easier manipulation.
- **String Sorting**: Using `qsort()` with a custom comparison function to sort strings in alphabetical order.
- **Dynamic Memory Management**: Allocating and deallocating memory dynamically, handling errors appropriately, and avoiding memory leaks.

## Notes

- The size of the 3D array and the names used are for demonstration purposes and can be modified as needed.
- The program demonstrates basic concepts of dynamic memory allocation, sorting, and safe memory management in C, making it suitable for educational purposes.

## Dependencies

- **Standard Libraries**: The code uses the following standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For dynamic memory management functions such as `malloc()`, `free()`, and sorting (`qsort()`).
  - `<string.h>`: For string manipulation functions like `strcmp()` and `strcpy()`.

## License

This code is provided as-is for educational purposes. Feel free to modify and use it in your projects, but please note that no warranty is provided.

