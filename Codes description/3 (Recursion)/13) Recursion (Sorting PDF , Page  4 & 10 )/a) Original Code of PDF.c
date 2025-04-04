#include <stdio.h>
#include <stdlib.h>

// Function to perform bottom-up merge sort on array A of size N
void bottom_up_merge_sort(int *A, int N) {
    int i, m, l = 0, r = N - 1;
    int *B = (int *)malloc(N * sizeof(int));

    // Iteratively merge subarrays of increasing size
    for (m = 1; m <= r - l; m = m + m) {
        for (i = l; i <= r - m; i += m + m) {
            merge(A, B, i, i + m - 1, (i + m + m - 1 < r) ? (i + m + m - 1) : r);
        }
    }
    free(B);
}

// Function to merge two sorted subarrays of A into a temporary array B
// Subarrays are A[l..c] and A[c+1..r]
void merge(int *A, int *B, int l, int c, int r) {
    int i, j, k;

    // Merge the two subarrays into B
    for (i = l, j = c + 1, k = l; i <= c && j <= r; ) {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    // Copy remaining elements from the left subarray, if any
    while (i <= c)
        B[k++] = A[i++];

    // Copy remaining elements from the right subarray, if any
    while (j <= r)
        B[k++] = A[j++];

    // Copy the merged elements back into the original array A
    for (k = l; k <= r; k++)
        A[k] = B[k];
}
