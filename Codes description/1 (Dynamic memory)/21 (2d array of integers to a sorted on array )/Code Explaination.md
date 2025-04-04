# README: Static 2D Array to Sorted Dynamic 1D Array

## Overview

This project demonstrates how to convert a static 2D array of integers into a dynamically allocated 1D array, which is then sorted in ascending order. The code covers several key programming concepts, including dynamic memory allocation, copying data between arrays, sorting integers using `qsort()`, and proper memory management to avoid memory leaks.

### Files Included

- `2d_to_1d_sorted_array.c`: Contains the implementation of the main function that performs the conversion, sorting, and memory deallocation.

## Functions

### 1. compare_integers(const void *a, const void *b)

The `compare_integers()` function is used as a custom comparison function for `qsort()` to sort the integers in ascending order.

- **Parameters**:
  - `const void *a`: A pointer to the first element to be compared.
  - `const void *b`: A pointer to the second element to be compared.

- **Return Value**: Returns a negative value, zero, or a positive value, depending on whether the first integer is less than, equal to, or greater than the second integer.

- **Implementation Details**:
  - The function takes two pointers (`const void *`) and casts them to `int *` to correctly access the integer values.
  - It then returns the difference between the two integers to determine their ordering.

### 2. main()

The `main()` function demonstrates how to convert a static 2D array of integers into a sorted dynamic 1D array.

- **Implementation Details**:
  - **Static 2D Array Initialization**: Defines a static 2D array of integers (`numbers[3][3]`), which contains sample values such as `{3, 1, 4}`, `{1, 5, 9}`, and `{2, 6, 5}`.
  - **Dynamic 1D Array Allocation**: Allocates memory for a dynamic 1D array (`sorted_array`) to store all integers from the static 2D array.
  - **Copying Elements**: Copies the elements from the static 2D array into the dynamically allocated 1D array.
  - **Sorting the Elements**: Uses the `qsort()` function with the `compare_integers()` function to sort the 1D array of integers in ascending order.
  - **Printing and Freeing Memory**: Prints the sorted array to the console and then frees the allocated memory to avoid memory leaks.

## Usage Instructions

1. **Compilation**:
   - Use the following command to compile the code:
     ```sh
     gcc -o 2d_to_1d_sorted_array 2d_to_1d_sorted_array.c
     ```
   - This will produce an executable named `2d_to_1d_sorted_array`.

2. **Running the Program**:
   - Run the program using:
     ```sh
     ./2d_to_1d_sorted_array
     ```
   - The program will convert the static 2D array to a sorted dynamic 1D array and print the sorted integers.

## Example Output

When you run the program, it will produce the following output:

```
Sorted numbers:
1 1 2 3 4 5 5 6 9 
```

## Memory Management

- **Dynamic Allocation**: Memory is dynamically allocated for a 1D array of integers using `malloc()`. This allows flexibility in managing the size of the array.
- **Proper Memory Deallocation**: After processing the integers, the dynamically allocated memory is freed using `free()`. This is crucial to prevent memory leaks.
- **Error Handling**: Proper checks are performed to ensure that memory allocation is successful. In case of allocation failure, the program exits gracefully after printing an error message.

## Key Concepts Demonstrated

- **Static to Dynamic Conversion**: Converting a statically defined 2D array into a dynamically allocated 1D array for easier manipulation and sorting.
- **Integer Sorting**: Using `qsort()` with a custom comparison function to sort integers in ascending order.
- **Dynamic Memory Management**: Allocating and deallocating memory dynamically, handling errors appropriately, and ensuring proper memory cleanup.

## Notes

- The size of the 2D array (`3x3`) and the values used are for demonstration purposes and can be modified as needed.
- This code is intended for educational purposes, demonstrating dynamic memory allocation, sorting, and safe memory management in C.

## Dependencies

- **Standard Libraries**: The code uses the following standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For dynamic memory management functions such as `malloc()`, `free()`, and sorting (`qsort()`).

## License

This code is provided as-is for educational purposes. Feel free to modify and use it in your projects, but please note that no warranty is provided.