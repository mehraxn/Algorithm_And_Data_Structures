#include <stdio.h>

int arr_rep(int *val, int *sol, int n, int k, int count, int pos) {
    int i;
    if (pos >= k) {
        for (i = 0; i < k; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count + 1;
    }
    for (i = 0; i < n; i++) {
        sol[pos] = val[i];
        count = arr_rep(val, sol, n, k, count, pos + 1);
    }
    return count;
}

int main() {
    int val[] = {1, 2, 3, 4, 5, 6}; // Input array with elements to generate combinations with repetition
    int n = 6; // Size of input array
    int k = 4; // Size of combinations to be generated
    int sol[4]; // Array to store current combination
    int count = 0;

    // Call the function to generate combinations with repetition
    count = arr_rep(val, sol, n, k, count, 0);

    // Print the total number of combinations generated
    printf("Total combinations with repetition: %d\n", count);
    return 0;
}
