#include <stdio.h>   // Standard input/output library
#include <stdlib.h>  // Standard library for memory allocation functions

int main() {
    int *p;  // Declare an integer pointer

    // Allocate memory for a single integer using malloc
    p = (int *) malloc(1 * sizeof(int));
    if (p == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);  // Exit the program with an error code
    }

    // Prompt the user to enter an integer value
    fprintf(stdout, "Introduce an integer value: ");
    scanf("%d", p);  // Read the value from the user and store it in the allocated memory

    // Print the entered value
    printf("You entered: %d\n", *p);

    // Free the allocated memory
    free(p);

    return 0;  // Exit the program successfully
}

/*
 * Explanation:
 *
 * This program demonstrates simple dynamic memory allocation for an integer variable using `malloc`.
 *
 * - `p = (int *) malloc(1 * sizeof(int))`: Allocates memory for a single integer and explicitly casts the result to `int*`.
 * - The program checks if the allocation was successful by verifying if `p` is not `NULL`.
 * - The user is prompted to input an integer value, which is stored in the allocated memory.
 * - The entered value is then printed using `printf`.
 * - Finally, the allocated memory is freed using `free(p)` to ensure there are no memory leaks.
 */
