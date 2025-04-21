#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Function to multiply two large numbers represented as arrays of digits.
 *
 * @param v1 Array representing the first number (one digit per element).
 * @param v2 Array representing the second number (one digit per element).
 * @param n The number of digits in both numbers.
 * @param pv Pointer to the resulting array of digits (allocated dynamically).
 */
void mul(int *v1, int *v2, int n, int **pv) {
    // Allocate space for the result (2 * n digits)
    int result_size = 2 * n;
    *pv = (int *)calloc(result_size, sizeof(int));
    if (*pv == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Perform multiplication using the sum-and-shift algorithm
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int product = v1[i] * v2[j];
            int pos = (n - 1 - i) + (n - 1 - j); // Calculate position in result array

            // Add product to the current position, including carry
            (*pv)[pos] += product;
            (*pv)[pos + 1] += (*pv)[pos] / 10; // Carry to the next position
            (*pv)[pos] %= 10; // Keep only the single digit
        }
    }

    // Reverse the result array for correct order
    for (int i = 0; i < result_size / 2; i++) {
        int temp = (*pv)[i];
        (*pv)[i] = (*pv)[result_size - 1 - i];
        (*pv)[result_size - 1 - i] = temp;
    }
}
