#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main() {
    // Pointer to the array to hold data from the file
    int *v1, *v2;
    int size = N;  // Initial size of the array
    int count = 0; // Counter to track the number of elements read
    FILE *file;    // File pointer for reading input

    // Allocate initial memory for the array
    v1 = malloc(N * sizeof(int));
    if (v1 == NULL) {
        // Error handling if initial allocation fails
        fprintf(stderr, "Failed to allocate memory\n");
        return 1; // Exit with error code
    }

    // Open the file named "data.txt" for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        // Error handling if file cannot be opened
        fprintf(stderr, "Failed to open file\n");
        free(v1); // Free allocated memory before exiting
        return 1; // Exit with error code
    }

    // Read the file and store the values in the array
    while (fscanf(file, "%d", &v1[count]) == 1) {
        count++;
        // Check if the array is full
        if (count >= size) {
            // Double the size of the array
            size *= 2;
            v2 = realloc(v1, size * sizeof(int));
            if (v2 == NULL) {
                // Error handling if reallocation fails
                fprintf(stderr, "Failed to reallocate memory\n");
                free(v1); // Free the original memory before exiting
                fclose(file); // Close the file before exiting
                return 1; // Exit with error code
            }
            // Update the pointer to the newly allocated memory
            v1 = v2;
        }
    }

    // Close the file after reading all the values
    fclose(file);

    // Use the array - here we are printing the values
    for (int i = 0; i < count; i++) {
        printf("%d\n", v1[i]);
    }

    // Free the allocated memory after use
    free(v1);

    return 0; // Successful execution
}

/*
Functions and Operations Summary:

1. `malloc(size_t size)`: Allocates `size` bytes of memory and returns a pointer to the allocated memory. Here, `malloc` is used to allocate space for the initial array `v1` of integers.

2. `fopen(const char *filename, const char *mode)`: Opens a file with the given `filename` in the specified `mode` ("r" for reading). If the file cannot be opened, an error message is printed.

3. `fscanf(FILE *stream, const char *format, ...)`: Reads formatted data from the specified file `stream`. Here, `fscanf` is used to read integers from the file into the array.

4. `realloc(void *ptr, size_t size)`: Resizes the memory block pointed to by `ptr` to `size` bytes. If `realloc` fails, it returns `NULL`, and the original block remains unchanged. In this code, `realloc` is used to expand the size of the array dynamically as more values are read.

5. `fclose(FILE *stream)`: Closes the specified file to release resources. The `fclose` function is called after all the reading is done.

6. `free(void *ptr)`: Deallocates the memory previously allocated by `malloc`, `realloc`, or `calloc`. The `free` function is used at various points in the code to ensure there are no memory leaks.

This program reads integers from a file, dynamically allocating and expanding memory as needed to accommodate all values. It provides examples of memory management, error handling, and file operations in C.
*/
