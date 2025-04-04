#include <stdio.h>   // Standard input/output library
#include <stdlib.h>  // Standard library for memory allocation functions

// First version of the function using a double pointer directly
void read_and_store(int **ptr, int *n) {
    FILE *file = fopen("input.txt", "r");  // Open the file in read mode
    if (file == NULL) {  // Check if the file was successfully opened
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);  // Exit if the file cannot be opened
    }

    fscanf(file, "%d", n);  // Read the number of elements

    *ptr = (int *) malloc(*n * sizeof(int));  // Allocate memory for n integers
    if (*ptr == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        fclose(file);  // Close the file before exiting
        exit(1);  // Exit the program if memory allocation fails
    }

    for (int i = 0; i < *n; i++) {  // Read the integers from the file
        fscanf(file, "%d", &(*ptr)[i]);
    }

    fclose(file);  // Close the file
}

// Second version of the function using a local pointer
void read_and_store_v2(int **ptr, int *n) {
    int *lptr;
    FILE *file = fopen("input.txt", "r");  // Open the file in read mode
    if (file == NULL) {  // Check if the file was successfully opened
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);  // Exit if the file cannot be opened
    }

    fscanf(file, "%d", n);  // Read the number of elements

    lptr = (int *) malloc(*n * sizeof(int));  // Allocate memory for n integers
    if (lptr == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        fclose(file);  // Close the file before exiting
        exit(1);  // Exit the program if memory allocation fails
    }

    for (int i = 0; i < *n; i++) {  // Read the integers from the file
        fscanf(file, "%d", &lptr[i]);
    }

    fclose(file);  // Close the file

    *ptr = lptr;  // Assign the allocated memory to the double pointer
}
