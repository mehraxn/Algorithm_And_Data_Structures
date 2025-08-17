#include <stdio.h>

// Recursive function to generate combinations with repetition
// This function generates all possible combinations of length k from the given values, allowing repetitions.
int arr_rep(int *val, int *sol, int n, int k, int count, int pos) {
    int i;

    // Termination condition: if the current position is equal to or greater than k, print the solution
    if (pos >= k) {
        for (i = 0; i < k; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return count + 1;
    }

    // Iterate over all choices available
    for (i = 0; i < n; i++) {
        sol[pos] = val[i];
        count = arr_rep(val, sol, n, k, count, pos + 1); // Recur for the next position
    }

    return count;
}

// Main function to demonstrate the generation of combinations with repetition
// This function initializes the values and calls arr_rep to print all possible combinations.
int main() {
    int n = 3; // Number of elements in the input set
    int k = 2; // Length of each combination
    int val[] = {1, 2, 3}; // Input set of values
    int sol[k]; // Array to store the current solution

    // Call the arr_rep function to generate and print all combinations with repetition of length k
    printf("All combinations with repetition of length %d:\n", k);
    int total_count = arr_rep(val, sol, n, k, 0, 0);
    printf("Total combinations: %d\n", total_count);

    return 0;
}

/*
Summary of the Functions:

1. arr_rep Function:
   - The `arr_rep` function generates all possible combinations of a given set of values, allowing repetitions.
   - It takes the input set (`val`), the solution array (`sol`), the number of elements in the input set (`n`), the length of each combination (`k`), the current count of combinations (`count`), and the current position (`pos`).
   - The function prints each valid combination and returns the total count of combinations generated.

2. main Function:
   - The `main` function initializes the data needed for generating combinations, including defining the input set (`val`) and the solution array (`sol`).
   - It sets the parameters (`n` and `k`) and calls `arr_rep` to generate all combinations with repetition.
   - Finally, it prints the total number of combinations generated.

This program demonstrates the use of recursion to generate combinations with repetition, where each element in the input set can appear multiple times in a combination. The recursive approach provides a straightforward way to explore all possible combinations, making this implementation a useful educational tool for understanding recursion and combinatorics with repetition.
*/
