#include <stdio.h>
#include <stdlib.h>

// Definition of the val_t structure to store the number of choices and the choices array
typedef struct val_s {
    int num_choice; // Number of choices available
    int *choices;   // Pointer to an array of choices
} val_t;

// Recursive function to generate combinations and print them
// This function recursively prints all possible combinations of the choices.
int mult_princ(val_t *val, int *sol, int n, int count, int pos) {
    int i;

    // Termination condition: if the current position is equal to or greater than n, print the solution
    if (pos >= n) {
        for (i = 0; i < n; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return count + 1;
    }

    // Iterate over all choices available at the current position
    for (i = 0; i < val[pos].num_choice; i++) {
        sol[pos] = val[pos].choices[i];
        count = mult_princ(val, sol, n, count, pos + 1); // Recur for the next position
    }

    return count;
}

// Main function to demonstrate the generation of combinations
// This function initializes the values and solutions, then calls mult_princ to print all combinations.
int main() {
    int n = 3; // Number of positions
    int i;
    val_t *val = (val_t *)malloc(n * sizeof(val_t));
    int *sol = (int *)malloc(n * sizeof(int));

    // Initialize the choices for each position
    for (i = 0; i < n; i++) {
        val[i].num_choice = 3; // Each position has 3 choices
        val[i].choices = (int *)malloc(val[i].num_choice * sizeof(int));
        for (int j = 0; j < val[i].num_choice; j++) {
            val[i].choices[j] = j + 1; // Choices are 1, 2, 3
        }
    }

    // Call the mult_princ function to generate and print all combinations
    printf("All combinations:\n");
    int total_count = mult_princ(val, sol, n, 0, 0);
    printf("Total combinations: %d\n", total_count);

    // Free the allocated memory
    for (i = 0; i < n; i++) {
        free(val[i].choices);
    }
    free(val);
    free(sol);

    return 0;
}

/*
Summary of the Functions:

1. val_t Structure:
   - The `val_t` structure is used to store the number of choices for each position and the array of choices.
   - Each instance of `val_t` contains an integer (`num_choice`) representing the number of choices and a pointer (`choices`) to an array of those choices.

2. mult_princ Function:
   - The `mult_princ` function generates all possible combinations of choices for each position.
   - It takes the array of `val_t` structures (`val`), the solution array (`sol`), the number of positions (`n`), the current count of combinations (`count`), and the current position (`pos`).
   - The function prints each valid combination and returns the total count of combinations generated.

3. main Function:
   - The `main` function initializes the data needed for generating combinations, including allocating memory for the `val` and `sol` arrays.
   - It sets up each position with a fixed number of choices and then calls `mult_princ` to generate all combinations.
   - Finally, it frees all allocated memory to prevent memory leaks.

This program demonstrates the use of recursion to generate combinations in a combinatorial setting. The `mult_princ` function systematically iterates over all choices for each position, generating every possible combination. The recursive approach provides a straightforward way to explore all options, making this implementation a useful educational tool for understanding recursion and combinatorics.
*/
