#include <stdio.h>
#include <stdlib.h>

// Function to generate arrangements with repetition (powerset of size k)
int powerset_1(int *val, int *sol, int k, int count, int pos) {
    int j;

    // Termination condition: if we've filled k positions
    if (pos >= k) {
        printf("{ \t");
        for (j = 0; j < k; j++)
            if (sol[j] != 0)
                printf("%d ", val[j]);
        printf("\t}\n");
        return count + 1;
    }

    // Two choices for each position:
    // Choice 0: Don't include the element at position 'pos'
    sol[pos] = 0;
    count = powerset_1(val, sol, k, count, pos + 1);

    // Choice 1: Include the element at position 'pos'
    sol[pos] = 1;
    count = powerset_1(val, sol, k, count, pos + 1);

    return count;
}

// Wrapper function to initialize and call the recursive function
int generate_powerset(int *val, int n, int k) {
    int *sol = (int*)calloc(k, sizeof(int)); // Solution array initialized to 0
    int count = 0;

    printf("Generating all arrangements with repetition for k=%d elements:\n", k);
    count = powerset_1(val, sol, k, count, 0);

    free(sol);
    return count;
}

int main() {
    // Example usage
    int val[] = {1, 2, 3, 4, 5}; // Input array of values
    int n = 5; // Size of input array
    int k = 3; // Size of each arrangement

    printf("Input array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", val[i]);
    }
    printf("\n\n");

    int total_arrangements = generate_powerset(val, n, k);

    printf("\nTotal arrangements generated: %d\n", total_arrangements);
    printf("Expected total (2^k): %d\n", 1 << k); // 2^k

    return 0;
}

/*
 * EXPLANATION:
 *
 * This code generates all possible arrangements with repetition where:
 * - We have an input array 'val' of n elements
 * - We want to generate all possible combinations of k positions
 * - For each position, we can either include (1) or exclude (0) the element
 *
 * The algorithm works by:
 * 1. For each position from 0 to k-1, make two recursive calls:
 *    - One where sol[pos] = 0 (don't include element at this position)
 *    - One where sol[pos] = 1 (include element at this position)
 * 2. When pos >= k, we've made decisions for all k positions, so print the result
 * 3. The total number of arrangements will be 2^k
 *
 * Note: This generates all binary combinations of length k, where each position
 * can be either 0 or 1, representing whether to include the corresponding element
 * from the val array.
 */