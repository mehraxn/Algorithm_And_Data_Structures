#include <stdio.h>
#include <stdlib.h>

// Function 1: Using pointer arithmetic to traverse and fill an array
void fill_and_print_array_with_pointer(int n) {
    int *v, *p;
    // Allocate memory for n integers
    v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill the array using pointer arithmetic
    for (int i = 0, p = v; i < n; i++, p++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", p); // Store user input at the current pointer location
    }

    // Print the array in reverse order using pointer arithmetic
    for (int i = n - 1, p--; i >= 0; i--, p--) {
        fprintf(stdout, "v[%d]: %d\n", i, *p); // Print value at the current pointer location
    }

    // Free the allocated memory
    free(v);
}

// Function 2: Using array notation to fill and print an array
void fill_and_print_array_with_index(int n) {
    int *v;
    // Allocate memory for n integers
    v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill the array using array indexing
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", &v[i]); // Store user input at the array index
    }

    // Print the array in reverse order using array indexing
    for (int i = n - 1; i >= 0; i--) {
        fprintf(stdout, "v[%d] = %d\n", i, v[i]); // Print value at the array index
    }

    // Free the allocated memory
    free(v);
}

// Function 3: Using calloc to allocate memory and filling an array
void fill_and_print_array_with_calloc(int n) {
    int *v;
    // Allocate memory for n integers using calloc (initializes memory to zero)
    v = (int *)calloc(n, sizeof(int));
    if (v == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill the array using array indexing
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", &v[i]); // Store user input at the array index
    }

    // Print the array in reverse order using array indexing
    for (int i = n - 1; i >= 0; i--) {
        fprintf(stdout, "v[%d] = %d\n", i, v[i]); // Print value at the array index
    }

    // Free the allocated memory
    free(v);
}

// Main function to demonstrate that all three functions achieve the same result
int main() {
    int n;
    fprintf(stdout, "Enter the size of the array: ");
    scanf("%d", &n);

    fprintf(stdout, "\nUsing pointer arithmetic:\n");
    fill_and_print_array_with_pointer(n);

    fprintf(stdout, "\nUsing array indexing:\n");
    fill_and_print_array_with_index(n);

    fprintf(stdout, "\nUsing calloc for memory allocation:\n");
    fill_and_print_array_with_calloc(n);

    return 0;
}

/*
Explanation of Functions:
1. Function `fill_and_print_array_with_pointer(int n)`:
   - This function uses pointer arithmetic to fill and print an array of size `n`.
   - It dynamically allocates memory using `malloc()`, fills the array using pointers, and prints the array in reverse order.
   - Pointer arithmetic is used to traverse the array, demonstrating how to work with pointers directly.

2. Function `fill_and_print_array_with_index(int n)`:
   - This function uses standard array indexing to fill and print an array of size `n`.
   - It allocates memory using `malloc()`, fills the array using array indexing, and prints the array in reverse order.
   - This approach is simpler and more intuitive for beginners compared to pointer arithmetic.

3. Function `fill_and_print_array_with_calloc(int n)`:
   - This function uses `calloc()` to allocate memory for an array of size `n`.
   - `calloc()` initializes the allocated memory to zero, which can be useful in some scenarios.
   - The function fills the array using array indexing and prints the values in reverse order.

All three functions achieve similar results, demonstrating different methods to allocate memory, fill an array, and print its values. The use of `malloc()`, `calloc()`, pointer arithmetic, and array indexing provides a comprehensive overview of dynamic memory management in C.
*/
