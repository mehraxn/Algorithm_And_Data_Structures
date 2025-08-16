#include <stdio.h>  // Standard input/output library
#include <stdlib.h> // Standard library for memory allocation functions

// Function to demonstrate dynamic memory allocation
void allocateAndPrint() {
    char *p1, *p2;  // Declare two character pointers

    // Allocate memory for a single character using malloc and cast to char*
    p1 = (char *) malloc(sizeof(char));
    if (p1 == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed for p1\n");
        return;
    }
    *p1 = 'A';  // Assign a value to the allocated memory
    printf("Value pointed by p1: %c\n", *p1);  // Print the value

    // Allocate memory for a single character without casting
    p2 = malloc(sizeof(*p2));
    if (p2 == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed for p2\n");
        free(p1);  // Free previously allocated memory
        return;
    }
    *p2 = 'B';  // Assign a value to the allocated memory
    printf("Value pointed by p2: %c\n", *p2);  // Print the value

    // Free the allocated memory
    free(p1);
    free(p2);
}

