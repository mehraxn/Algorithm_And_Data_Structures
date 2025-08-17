#include <stdio.h>
#include <stdlib.h>

// Function to perform bottom-up merge sort on array A of size N
// This function sorts the array A using an iterative, bottom-up merge sort approach.
void bottom_up_merge_sort(int *A, int N) {
    int i, m, l = 0, r = N - 1;
    int *B = (int *)malloc(N * sizeof(int));

    // Iteratively merge subarrays of increasing size
    for (m = 1; m <= r - l; m = m + m) {
        for (i = l; i <= r - m; i += m + m) {
            // Merge subarrays of size m
            merge(A, B, i, i + m - 1, (i + m + m - 1 < r) ? (i + m + m - 1) : r);
        }
    }

    // Free the allocated memory for the temporary array
    free(B);
}

// Function to merge two sorted arrays v1 and v2 into v3
// Arrays v1 and v2 have size n each
// This function combines two sorted arrays into a single sorted array.
void merge(int *v1, int *v2, int *v3, int n) {
    int i1 = 0, i2 = 0, i3 = 0;

    // Merge elements from v1 and v2 into v3
    while (i1 < n && i2 < n) {
        if (v1[i1] < v2[i2]) {
            v3[i3++] = v1[i1++];
        } else {
            v3[i3++] = v2[i2++];
        }
    }

    // Copy remaining elements from v1, if any
    while (i1 < n) {
        v3[i3++] = v1[i1++];
    }

    // Copy remaining elements from v2, if any
    while (i2 < n) {
        v3[i3++] = v2[i2++];
    }
}

// Main function to demonstrate bottom-up merge sort and merging two arrays
// This function initializes example arrays, sorts them, and prints the result.
int main() {
    int A[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int N = sizeof(A) / sizeof(A[0]);

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Sort the array using bottom-up merge sort
    bottom_up_merge_sort(A, N);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Demonstrate merging two sorted arrays
    int v1[] = {1, 3, 5, 7};
    int v2[] = {2, 4, 6, 8};
    int v3[8];
    int n = 4;

    // Merge v1 and v2 into v3
    merge(v1, v2, v3, n);

    // Print the merged array
    printf("Merged array: ");
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    return 0;
}

/*
Summary of the Functions:

1. bottom_up_merge_sort Function:
   - The `bottom_up_merge_sort` function sorts an array using the bottom-up merge sort algorithm.
   - It iteratively merges subarrays of increasing size until the entire array is sorted.
   - The function uses a temporary array (`B`) to store merged results before copying them back to the original array (`A`).

2. merge Function:
   - The `merge` function combines two sorted arrays (`v1` and `v2`) into a single sorted array (`v3`).
   - It takes three arrays (`v1`, `v2`, and `v3`) and their size (`n`), and merges them in sorted order.
   - The function ensures that all elements from both input arrays are copied to the output array in the correct order.

3. main Function:
   - The `main` function demonstrates the usage of both the `bottom_up_merge_sort` and `merge` functions.
   - It initializes an example array, sorts it, and prints both the original and sorted arrays to show the result.
   - It also demonstrates merging two sorted arrays (`v1` and `v2`) into a new array (`v3`) and prints the merged result.

This program demonstrates the use of an iterative approach to merge sort, which is an efficient, stable sorting algorithm with a time complexity of O(n log n). Additionally, the `merge` function is used to combine two sorted arrays, showing how merging works as a fundamental part of the merge sort algorithm.
*/
