/*
 * This code generates all permutations of a given set of integers using recursion.
 * It uses backtracking to explore all possible arrangements by choosing elements and marking them as used.
 */

#include <stdio.h>

// Function to generate all permutations
int perm(int *val, int *sol, int *mark, int n, int count, int pos) {
    int i;

    // Termination condition: if we have filled all positions, print the solution
    if (pos >= n) {
        for (i = 0; i < n; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return count + 1;  // Increment count as we found a valid permutation
    }

    // Iterate over all choices for the current position
    for (i = 0; i < n; i++) {
        if (mark[i] == 0) {  // If this element is not used yet
            mark[i] = 1;     // Mark it as used
            sol[pos] = val[i];  // Place the element in the solution array
            count = perm(val, sol, mark, n, count, pos + 1);  // Recur for next position
            mark[i] = 0;     // Backtrack: unmark the element to be used in future iterations
        }
    }

    return count;  // Return the final count of permutations
}

int main() {
    int val[] = {1, 2, 3};  // Input array of values to permute
    int n = sizeof(val) / sizeof(val[0]);  // Number of elements in the input array
    int sol[n];  // Array to hold a single permutation
    int mark[n];  // Array to mark if an element is used in the current permutation
    int count = 0;  // Counter to keep track of the number of permutations

    // Initialize the mark array to all zeros (none of the elements are used initially)
    for (int i = 0; i < n; i++) {
        mark[i] = 0;
    }

    // Generate all permutations starting from position 0
    count = perm(val, sol, mark, n, count, 0);

    // Print the total number of permutations found
    printf("Total permutations: %d\n", count);

    return 0;
}

/*
 * Function descriptions:
 *
 * 1. int perm(int *val, int *sol, int *mark, int n, int count, int pos)
 *    - This function generates all possible permutations of the given input array using recursion.
 *    - Parameters:
 *      - int *val: The input array of values to be permuted.
 *      - int *sol: The solution array that stores the current permutation.
 *      - int *mark: The array used to mark if an element is already included in the current permutation.
 *      - int n: The number of elements in the input array.
 *      - int count: A counter to keep track of the number of valid permutations generated.
 *      - int pos: The current position in the permutation that we are filling.
 *    - The function works by iterating over the possible choices for each position in the permutation, marking the element as used, and recursively proceeding to the next position.
 *    - Once a complete permutation is found, it prints the result and backtracks to explore other possible arrangements.
 *
 * 2. int main()
 *    - This function initializes the input array and other required variables, and calls the 'perm' function to generate all permutations.
 *    - It also prints the total number of permutations found at the end.
 */