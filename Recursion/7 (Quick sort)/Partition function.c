#include <stdio.h>

void swap(int *v, int n1, int n2) {
    int temp;
    temp = v[n1];
    v[n1] = v[n2];
    v[n2] = temp;
}

int partition(int *A, int l, int r) {
    int i, j, pivot;
    i = l - 1;
    j = r;
    pivot = A[r];  // Choosing the last element as pivot

    while (i < j) {
        while (A[++i] < pivot);               // Move i to the right
        while (j > l && A[--j] >= pivot);     // Move j to the left

        if (i < j)
            swap(A, i, j); // Swap elements out of place
    }

    // Place pivot in its correct position
    swap(A, i, r);
    return i;  // Return the partition index
}
