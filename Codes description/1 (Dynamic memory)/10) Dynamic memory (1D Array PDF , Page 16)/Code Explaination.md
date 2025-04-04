# Dynamic Array File Reader

This program is a simple C application that reads integers from a file and stores them in a dynamically allocated array. If the array's capacity is reached, the program resizes the array to accommodate more values, ensuring all data from the file can be stored. The program demonstrates basic file operations, dynamic memory allocation, and memory management in C.

## Overview

The main objective of this program is to:

1. **Read integers from a file** named `data.txt`.
2. **Store the integers in a dynamically allocated array**.
3. **Resize the array dynamically** if more integers are read than the initial allocated capacity.
4. **Print all the integers** after reading the entire file.

The program effectively showcases the use of `malloc()`, `realloc()`, `fopen()`, `fscanf()`, `fclose()`, and `free()` functions in C for memory allocation and file handling.

## Key Features

- **Dynamic Memory Allocation**: Initially allocates memory for an array of 1000 integers using `malloc()`. If the number of integers read exceeds this limit, the program resizes the array using `realloc()`, doubling its size each time.
- **File Handling**: Opens a file named `data.txt` for reading integers. If the file cannot be opened, an appropriate error message is printed, and the program terminates.
- **Memory Management**: Ensures that all dynamically allocated memory is freed before the program exits, preventing memory leaks.
- **Error Handling**: Implements error checks for memory allocation (`malloc` and `realloc`) and file operations (`fopen`), printing descriptive error messages and freeing memory before exiting if an error occurs.

## Usage

To use this program, follow these steps:

1. **Create a file named `data.txt`** in the same directory as the compiled executable. The file should contain a list of integers separated by spaces or newlines.

2. **Compile the code** using a C compiler like `gcc`:
   ```
   gcc dynamic_array_file_reader.c -o dynamic_array_file_reader
   ```

3. **Run the executable**:
   ```
   ./dynamic_array_file_reader
   ```

The program will read all integers from `data.txt` and print them to the console.

## Code Walkthrough

1. **Memory Allocation**: The initial array is allocated with space for `N` (1000) integers using `malloc()`.
   ```c
   v1 = malloc(N * sizeof(int));
   if (v1 == NULL) {
       fprintf(stderr, "Failed to allocate memory\n");
       return 1;
   }
   ```
   If the allocation fails, an error message is printed, and the program exits.

2. **File Opening**: The program attempts to open `data.txt` for reading. If unsuccessful, it prints an error and exits.
   ```c
   file = fopen("data.txt", "r");
   if (file == NULL) {
       fprintf(stderr, "Failed to open file\n");
       free(v1);
       return 1;
   }
   ```

3. **Reading Data**: The program reads integers from the file using `fscanf()` and stores them in the array. If the array becomes full, it doubles the size using `realloc()`.
   ```c
   while (fscanf(file, "%d", &v1[count]) == 1) {
       count++;
       if (count >= size) {
           size *= 2;
           v2 = realloc(v1, size * sizeof(int));
           if (v2 == NULL) {
               fprintf(stderr, "Failed to reallocate memory\n");
               free(v1);
               fclose(file);
               return 1;
           }
           v1 = v2;
       }
   }
   ```

4. **Printing Data**: After reading all the integers, the program prints them to the console.
   ```c
   for (int i = 0; i < count; i++) {
       printf("%d\n", v1[i]);
   }
   ```

5. **Cleanup**: Finally, the program frees the allocated memory and closes the file.
   ```c
   fclose(file);
   free(v1);
   ```

## Error Handling

- **Memory Allocation Failures**: If `malloc()` or `realloc()` fails, the program prints an error message and exits gracefully, ensuring no memory leaks occur.
- **File Access Errors**: If the file cannot be opened, the program prints an error message and exits.

## Important Functions Used

1. **`malloc(size_t size)`**: Allocates a block of memory of the specified size. Used to allocate memory for the initial array.
2. **`realloc(void *ptr, size_t size)`**: Resizes the memory block pointed to by `ptr` to the new size. Used to expand the array as needed.
3. **`fopen(const char *filename, const char *mode)`**: Opens the specified file in the given mode. Used here to read data from `data.txt`.
4. **`fscanf(FILE *stream, const char *format, ...)`**: Reads formatted input from a file. Used to read integers from the file.
5. **`fclose(FILE *stream)`**: Closes the specified file, releasing any resources used.
6. **`free(void *ptr)`**: Frees dynamically allocated memory. Used to prevent memory leaks.

## Notes

- The program expects that `data.txt` contains only integers. If the file contains non-integer values, `fscanf()` will fail, and the program will stop reading further.
- This program demonstrates fundamental concepts in C, including dynamic memory allocation, file handling, and error management, making it suitable for beginners learning C programming.

