#include <stdio.h>   // Standard input/output library
#include <stdlib.h>  // Standard library for memory allocation functions

// First version of the function using a double pointer directly
void read_and_store(int **ptr, int *n) {
    FILE *file = fopen("input.txt", "r");  // Open the file in read mode
    if (file == NULL) {  // Check if the file was successfully opened
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);  // Exit if the file cannot be opened
    }

    fscanf(file, "%d", n);  // Read the number of elements from the file

    *ptr = (int *) malloc(*n * sizeof(int));  // Allocate memory for n integers
    if (*ptr == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        fclose(file);  // Close the file before exiting
        exit(1);  // Exit the program if memory allocation fails
    }

    for (int i = 0; i < *n; i++) {  // Read the integers from the file
        fscanf(file, "%d", &(*ptr)[i]);  // Store each integer in the allocated array
    }

    fclose(file);  // Close the file
}

// Second version of the function using a local pointer
void read_and_store_v2(int **ptr, int *n) {
    int *lptr;  // Declare a local pointer
    FILE *file = fopen("input.txt", "r");  // Open the file in read mode
    if (file == NULL) {  // Check if the file was successfully opened
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);  // Exit if the file cannot be opened
    }

    fscanf(file, "%d", n);  // Read the number of elements from the file

    lptr = (int *) malloc(*n * sizeof(int));  // Allocate memory for n integers
    if (lptr == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        fclose(file);  // Close the file before exiting
        exit(1);  // Exit the program if memory allocation fails
    }

    for (int i = 0; i < *n; i++) {  // Read the integers from the file
        fscanf(file, "%d", &lptr[i]);  // Store each integer in the allocated array
    }

    fclose(file);  // Close the file

    *ptr = lptr;  // Assign the allocated memory to the double pointer
}

int main() {
    int *array;  // Pointer to hold the address of the allocated memory
    int n;  // Variable to store the number of elements

    // Using the first version of the function
    printf("Using the first version:\n");
    read_and_store(&array, &n);  // Call the first version of the function
    for (int i = 0; i < n; i++) {  // Print the array elements
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);  // Free the allocated memory

    // Using the second version of the function
    printf("\nUsing the second version:\n");
    read_and_store_v2(&array, &n);  // Call the second version of the function
    for (int i = 0; i < n; i++) {  // Print the array elements
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);  // Free the allocated memory

    return 0;  // Exit the program successfully
}

/*
 * Explanation:
 *
 * This code provides two versions of the `read_and_store` function to read data from a file and allocate memory for an integer array:
 *
 * 1. **First Version (`read_and_store`)**:
 *    - Uses a double pointer (`**ptr`) directly to allocate memory and store values.
 *    - Opens the file, reads the size (`n`), allocates memory using `malloc`, reads the values, and assigns the allocated memory to `*ptr`.
 *    - This version is straightforward, directly working with the double pointer to manage the memory allocation.
 *
 * 2. **Second Version (`read_and_store_v2`)**:
 *    - Uses a local pointer (`lptr`) to allocate memory, and then assigns the allocated memory to `*ptr`.
 *    - This approach makes it clear that memory allocation is done separately and then assigned to the double pointer.
 *
 * Both versions perform the same functionality: reading an integer (`n`) from a file, allocating memory for `n` integers, and storing those values in dynamically allocated memory. Both functions properly handle file errors and memory allocation failures.
 *
 * The main function demonstrates the usage of both versions by:
 * - Calling each function to read data from a file and allocate memory.
 * - Printing the values stored in the allocated memory.
 * - Freeing the allocated memory to ensure there are no memory leaks.
 */
