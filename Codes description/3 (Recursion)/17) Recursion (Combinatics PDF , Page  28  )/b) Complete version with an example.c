#include <stdio.h>
#include <stdlib.h>

// Recursive function to generate permutations of a given set of values
// This function generates all possible permutations of the given values and prints them.
int arr(int *val, int *sol, int *mark, int n, int k, int count, int pos) {
    int i;

    // Termination condition: if the current position is equal to or greater than k, print the solution
    if (pos >= k) {
        for (i = 0; i < k; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count + 1;
    }

    // Iterate over all available values
    for (i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1; // Mark the current value as used
            sol[pos] = val[i];
            count = arr(val, sol, mark, n, k, count, pos + 1); // Recur for the next position
            mark[i] = 0; // Unmark the value to allow reuse in other permutations
        }
    }

    return count;
}

// Main function to demonstrate the generation of permutations
// This function initializes the values and solution arrays, then calls arr to print all permutations.
int main() {
    int n = 4; // Number of elements in the input set
    int k = 3; // Length of each permutation
    int val[] = {1, 2, 3, 4}; // Input set of values
    int *sol = (int *)malloc(k * sizeof(int)); // Array to store the current solution
    int *mark = (int *)calloc(n, sizeof(int)); // Array to mark used elements

    // Call the arr function to generate and print all permutations of length k
    printf("All permutations of length %d:\n", k);
    int total_count = arr(val, sol, mark, n, k, 0, 0);
    printf("Total permutations: %d\n", total_count);

    // Free the allocated memory
    free(sol);
    free(mark);

    return 0;
}

/*
Summary of the Functions:

1. arr Function:
   - The `arr` function generates all possible permutations of a given set of values.
   - It takes the input set (`val`), the solution array (`sol`), a marker array (`mark`) to track used elements, the size of the input set (`n`), the length of each permutation (`k`), the current count of permutations (`count`), and the current position (`pos`).
   - The function prints each valid permutation and returns the total count of permutations generated.

2. main Function:
   - The `main` function initializes the data needed for generating permutations, including allocating memory for the `sol` and `mark` arrays.
   - It sets up the input set of values (`val`) and calls `arr` to generate all permutations of a specified length (`k`).
   - Finally, it frees all allocated memory to prevent memory leaks.

This program demonstrates the use of recursion to generate permutations in a combinatorial setting. The `arr` function systematically iterates over all values for each position, generating every possible permutation of a specified length. The recursive approach provides a straightforward way to explore all possible arrangements, making this implementation a useful educational tool for understanding recursion and combinatorics.
*/
