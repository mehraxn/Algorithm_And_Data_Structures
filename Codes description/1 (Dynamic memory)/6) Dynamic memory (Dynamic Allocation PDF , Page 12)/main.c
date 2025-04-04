#include <stdio.h>  // Standard input/output library
#include <stdlib.h> // Standard library for memory allocation functions

// Define a struct named mys
struct mys {
    int data;  // Member of the struct
};

// Function to demonstrate explicit casting in memory allocation
void allocateWithExplicitCast() {
    struct mys *p1;  // Declare a pointer to struct mys

    // Allocate memory for a struct mys and cast to struct mys*
    p1 = (struct mys *) malloc(sizeof(struct mys));
    if (p1 == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed for p1\n");
        return;
    }

    // Assign a value to the struct member and print it
    p1->data = 100;
    printf("Value of p1->data: %d\n", p1->data);

    // Free the allocated memory
    free(p1);
}

// Function to demonstrate implicit casting in memory allocation
void allocateWithImplicitCast() {
    struct mys *p2;  // Declare a pointer to struct mys

    // Allocate memory for a struct mys without casting
    p2 = malloc(sizeof(*p2));
    if (p2 == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed for p2\n");
        return;
    }

    // Assign a value to the struct member and print it
    p2->data = 200;
    printf("Value of p2->data: %d\n", p2->data);

    // Free the allocated memory
    free(p2);
}

int main() {
    printf("Example 1: Allocate with Explicit Cast\n");
    allocateWithExplicitCast();  // Call function with explicit casting

    printf("\nExample 2: Allocate with Implicit Cast\n");
    allocateWithImplicitCast();  // Call function with implicit casting

    return 0;  // Exit the program successfully
}

/*
 * Explanation:
 *
 * This program demonstrates dynamic memory allocation for a struct named 'mys' using both explicit and implicit casting.
 *
 * 1. allocateWithExplicitCast():
 *    - Allocates memory for a struct mys and explicitly casts the result to 'struct mys*'.
 *    - Assigns a value to the struct member and prints it.
 *
 * 2. allocateWithImplicitCast():
 *    - Allocates memory for a struct mys without explicitly casting the result.
 *    - Assigns a value to the struct member and prints it.
 *
 * Both functions illustrate the same process of allocating memory, assigning values, and freeing the memory.
 * The explicit cast is often used for clarity, but it is not strictly necessary in C (though required in C++).
 */
