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
    // Manually define the distinct values and their occurrences
    int val_dist[] = {1, 2, 3, 8, 0, 0};  // Distinct values
    int mark[] = {1, 2, 2, 1, 0, 0};     // Occurrences of each distinct value
    int n_dist = 4;                      // Number of distinct values

    int n = 6;  // Length of each permutation

    // Array to store the current permutation
    int sol[n];

    int count = 0;  // Variable to keep track of the total number of permutations

    // Generate all permutations with repetition allowed
    count = perm_rep(val_dist, sol, mark, n, n_dist, count, 0);

    // Print the total count of permutations generated
    printf("Total permutations: %d\n", count);

    return 0;
}
