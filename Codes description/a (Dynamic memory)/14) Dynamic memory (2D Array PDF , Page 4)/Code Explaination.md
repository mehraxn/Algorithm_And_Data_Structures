# README: Dynamic Array of C Structures

## Overview
This C program demonstrates the use of dynamic memory allocation for an array of structures, specifically focusing on managing static strings within these structures. It covers how to allocate memory dynamically, fill the structures with data, and print their content, all while ensuring proper memory management.

## Features
- **Dynamic Memory Allocation**: Uses `malloc` to allocate memory for an array of structures, enabling flexible memory usage based on user input.
- **Static Strings within Structures**: Each structure contains a static character array that holds a string of fixed size (`N` = 100).
- **Safe String Operations**: Uses `snprintf` to fill strings, ensuring safe operations without overflow.

## Code Files
- **main.c**: Contains the complete program, including functions to allocate memory, fill the structures, and print their contents.

## How to Compile and Run
To compile and run the program, you need a C compiler (such as GCC). Follow these steps:

1. Save the code in a file named `main.c`.
2. Open a terminal and navigate to the directory where `main.c` is saved.
3. Compile the program using GCC:
   ```
   gcc -o array_of_structs main.c
   ```
4. Run the executable:
   ```
   ./array_of_structs
   ```
5. Enter the desired number of elements when prompted.

## Code Explanation
### Structure Definition
```c
#define N 100

typedef struct e_s {
    char str[N];  // Static array of characters
} e_t;
```
The program defines a structure `e_t` that contains a static array `str` of fixed size `N` (100 characters). This structure is used to create an array of structures.

### Functions
#### 1. `fillArray(e_t *v, int n)`
- **Purpose**: Fills the array of structures with strings.
- **Parameters**:
  - `v`: Pointer to the array of structures.
  - `n`: Number of elements in the array.
- **Details**: Uses `snprintf` to safely format and assign a string to each element's `str` field.

#### 2. `printArray(e_t *v, int n)`
- **Purpose**: Prints each string stored in the array of structures.
- **Parameters**:
  - `v`: Pointer to the array of structures.
  - `n`: Number of elements in the array.
- **Details**: Iterates over the array and prints each string.

#### 3. `main()`
- **Purpose**: Entry point of the program.
- **Details**: Prompts the user to enter the number of elements, allocates memory for the array, fills the array, prints its content, and then frees the allocated memory.

### Memory Management
- **Allocation**: Memory for the array of structures is allocated dynamically using `malloc`.
- **Deallocation**: `free()` is used to release the allocated memory, preventing memory leaks.
- **Null Check**: After calling `malloc`, the program checks if the pointer is `NULL` to ensure memory allocation succeeded.

## Example Output
```
Enter the number of elements: 3
String 1
String 2
String 3
```
The program will prompt the user for the number of elements, and then print each element as "String X", where `X` is the index + 1.

## Key Concepts
- **Structures in C**: The program defines a structure with a static string and demonstrates how to use structures to store related data.
- **Dynamic Memory Allocation**: Uses `malloc` for runtime memory allocation, allowing flexibility in the size of the data.
- **Safety in C Programming**: Using `snprintf` helps prevent buffer overflows, which is a common problem in C programming when dealing with strings.

## Improvements and Notes
- **Input Validation**: This program does not perform input validation, so negative numbers or non-numeric input may cause unintended behavior.
- **Dynamic String Size**: Currently, the size of the string (`N`) is fixed. Future versions could use pointers to dynamically allocate the string size, depending on user needs.

## License
This program is open source and available under the MIT License. Feel free to use, modify, and distribute the code.

## Contact
For any questions or suggestions, please contact the author via email at `example@example.com`.

