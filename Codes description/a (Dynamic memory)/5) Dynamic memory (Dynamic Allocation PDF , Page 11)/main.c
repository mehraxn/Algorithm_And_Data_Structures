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

int main() {
    printf("Example 1: Allocate and Print Characters\n");
    allocateAndPrint();  // Call the function to demonstrate memory allocation

    printf("\nExample 2: Allocate and Print Different Characters\n");
    char *p3 = (char *) malloc(sizeof(char));  // Allocate memory for another character
    if (p3 != NULL) {
        *p3 = 'C';  // Assign value 'C'
        printf("Value pointed by p3: %c\n", *p3);  // Print value pointed by p3
        free(p3);  // Free the allocated memory
    } else {
        fprintf(stderr, "Memory allocation failed for p3\n");
    }

    return 0;  // Exit the program successfully
}

/*
 * Explanation:
 *
 * In this simple program, we demonstrate dynamic memory allocation using malloc for two character pointers.
 * - `p1 = (char *) malloc(sizeof(char))`: Allocates memory for a single character and casts it to `char*`. The cast is not mandatory in C, but it is often used for clarity.
 * - `p2 = malloc(sizeof(*p2))`: Allocates memory for a single character without an explicit cast. The size of the allocation is based on the type that `p2` points to.
 *
 * Both `p1` and `p2` are used to store single characters ('A' and 'B', respectively), and their values are printed to the console.
 * After use, the memory is freed using `free(p1)` and `free(p2)` to avoid memory leaks.
 *
 * In `main`, an additional example is provided where `p3` is allocated and assigned the character 'C'. This demonstrates how the functions are similar in allocating memory for characters and printing their values.
 */
