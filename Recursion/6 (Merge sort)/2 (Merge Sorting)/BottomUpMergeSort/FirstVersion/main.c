#include <stdio.h>
#include <stdlib.h>

void merge(int *A, int *B, int l, int c, int r) {
    int i, j, k;

    i = l;
    j = c + 1;
    k = l;

    while (i <= c && j <= r) {
        if (A[i] <= A[j])    // use <= for stability
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }


    while (i <= c)
        B[k++] = A[i++];


    while (j <= r)
        B[k++] = A[j++];

    for (k = l; k <= r; k++)
        A[k] = B[k];
}

void bottom_up_merge_sort(int *array, int size) {
    int i, m;
    int *B = (int *)malloc(size * sizeof(int));
    if (!B) return; // safety check

    for (m = 1; m < size; m += m) {
        for (i = 0; i  < size - m ; i += m + m) {
            int r = (i + m + m - 1 < size) ? (i + m + m - 1) : (size - 1);
            merge(array, B, i, i + m - 1, r);
        }
    }

    free(B);
}

