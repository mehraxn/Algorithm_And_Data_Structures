#include <stdio.h>

int arr(int *val, int *sol, int *mark, int n, int k, int count, int pos) {
    int i;
    if (pos >= k) {
        for (i = 0; i < k; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count + 1;
    }
    for (i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            sol[pos] = val[i];
            count = arr(val, sol, mark, n, k, count, pos + 1);
            mark[i] = 0;
        }
    }
    return count;
}

int main() {
    int val[] = {1, 2, 3}; // Input array with elements to generate combinations
    int n = 3; // Size of input array
    int k = 2; // Size of combinations to be generated
    int sol[2]; // Array to store current combination
    int mark[3] = {0}; // Marker array to indicate used elements
    int count = 0;

    // Call the function to generate combinations
    count = arr(val, sol, mark, n, k, count, 0);

    // Print the total number of combinations generated
    printf("Total combinations: %d\n", count);
    return 0;
}
