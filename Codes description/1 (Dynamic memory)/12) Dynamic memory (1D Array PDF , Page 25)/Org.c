#include <stdio.h>   // Standard input/output library
#include <stdlib.h>  // Standard library for memory allocation functions

// Function to open a file, read an integer value n, allocate memory, and return a pointer to the allocated array
int *allocateArrayFromFile(const char *filename, int *n) {
    FILE *file = fopen(filename, "r");  // Open the file in read mode
    if (file == NULL) {  // Check if the file was successfully opened
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);  // Exit the program if the file could not be opened
    }

    // Read the value of n from the file
    fscanf(file, "%d", n);

    // Allocate memory for n integers
    int *ptr = (int *) malloc(*n * sizeof(int));
    if (ptr == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        fclose(file);  // Close the file before exiting
        exit(1);  // Exit the program if memory allocation fails
    }

    // Read n integers from the file and store them in the allocated array
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d", &ptr[i]);
    }

    fclose(file);  // Close the file
    return ptr;  // Return the pointer to the allocated array
}