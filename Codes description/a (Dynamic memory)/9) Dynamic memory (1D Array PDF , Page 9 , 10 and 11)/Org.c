#include <stdio.h>   // Standard input/output library
#include <stdlib.h>  // Standard library for memory allocation functions

// Function to allocate and manage an array using array indexing
void allocateWithArrayIndexing() {
    int n, *v;
    fprintf(stdout, "Introduce n: ");
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int));  // Allocate memory for n integers
    if (v == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill the array with user inputs
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    // Print the array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        fprintf(stdout, "v[%d]=%d\n", i, v[i]);
    }

    free(v);  // Free allocated memory
}

// Function to allocate and manage an array using pointer arithmetic
void allocateWithPointerArithmetic() {
    int n, *v, *p;
    fprintf(stdout, "Introduce n: ");
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int));  // Allocate memory for n integers
    if (v == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill the array with user inputs using pointer arithmetic
    for (int i = 0, p = v; i < n; i++, p++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", p);
    }

    // Print the array in reverse order using pointer arithmetic
    for (int i = n - 1, p = v + n - 1; i >= 0; i--, p--) {
        fprintf(stdout, "v[%d]=%d\n", i, *p);
    }

    free(v);  // Free allocated memory
}

// Function to allocate and manage an array using calloc
void allocateWithCalloc() {
    int n, *v;
    fprintf(stdout, "Introduce n: ");
    scanf("%d", &n);

    v = calloc(n, sizeof(int));  // Allocate and initialize memory for n integers
    if (v == NULL) {  // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill the array with user inputs
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    // Print the array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        fprintf(stdout, "v[%d]=%d\n", i, v[i]);
    }

    free(v);  // Free allocated memory
}