#include <stdio.h>

// Function to generate permutations with repetition
int perm_rep(int *val_dist, int *sol, int *mark, int n, int n_dist, int count, int pos) {
    int i;

    // Base case: if we have filled all positions in the solution array
    if (pos >= n) {
        // Print the current solution
        for (i = 0; i < n; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return count + 1;  // Increase the count of valid permutations
    }

    // Recursive case: iterate over all possible values
    for (i = 0; i < n_dist; i++) {
        if (mark[i] > 0) {  // Check if there are occurrences left for val_dist[i]
            mark[i]--;  // Use one occurrence of val_dist[i]
            sol[pos] = val_dist[i];  // Place the element in the solution array
            // Recur to the next position
            count = perm_rep(val_dist, sol, mark, n, n_dist, count, pos + 1);
            mark[i]++;  // Backtrack: restore the occurrence for other iterations
        }
    }

    return count;  // Return the total count of permutations
}

int main() {
    int val_dist[] = {1, 2, 3};  // Array of distinct values to use in permutations
    int n_dist = 3;  // Number of distinct values
    int n = 3;  // Length of each permutation

    int sol[n];  // Array to store the current permutation
    int mark[] = {1, 1, 1};  // Array to keep track of the remaining occurrences of each value

    int count = 0;  // Variable to keep track of the total number of permutations

    // Generate all permutations with repetition allowed
    count = perm_rep(val_dist, sol, mark, n, n_dist, count, 0);

    // Print the total count of permutations generated
    printf("Total permutations: %d\n", count);

    return 0;
}

/*
Explanation of the Functions in the Code:

1. perm_rep():
   - This is a recursive function that generates all possible permutations with repetition allowed, given a set of distinct values (val_dist).
   - Parameters:
     - val_dist: Array of distinct values.
     - sol: Array to store the current permutation.
     - mark: Array to track the remaining occurrences of each value in val_dist.
     - n: Length of each permutation to generate.
     - n_dist: Number of distinct values in val_dist.
     - count: Variable to keep track of the number of valid permutations generated so far.
     - pos: Current position in the permutation that we are trying to fill.
   - The function uses a base case to print the current permutation when all positions are filled and a recursive case to iterate over all values that still have available occurrences.
   - Backtracking is used to restore the state after each recursive call, ensuring that all possible permutations are generated.

2. main():
   - Initializes the distinct values, the length of the permutation, and the array to store the solution.
   - Calls perm_rep() to generate and print all permutations.
   - Finally, prints the total count of permutations generated.
*/
