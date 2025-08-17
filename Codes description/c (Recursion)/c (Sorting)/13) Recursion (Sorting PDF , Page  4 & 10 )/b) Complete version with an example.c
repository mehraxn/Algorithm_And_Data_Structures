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

// Function to merge two sorted subarrays of A into a temporary array B
// Subarrays are A[l..c] and A[c+1..r]
// This function combines two sorted subarrays into a single sorted subarray.
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

// Main function to demonstrate bottom-up merge sort
// This function initializes an array, sorts it using bottom-up merge sort, and prints the result.
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

    return 0;
}

/*
Summary of the Functions:

1. bottom_up_merge_sort Function:
   - The `bottom_up_merge_sort` function sorts an array using the bottom-up merge sort algorithm.
   - It iteratively merges subarrays of increasing size until the entire array is sorted.
   - The function uses a temporary array (`B`) to store merged results before copying them back to the original array (`A`).

2. merge Function:
   - The `merge` function combines two sorted subarrays into a single sorted subarray.
   - It takes the original array (`A`), a temporary array (`B`), and the indices of the subarrays to be merged (`l`, `c`, and `r`).
   - The function first merges the elements into `B` and then copies the merged elements back to `A`.

3. main Function:
   - The `main` function demonstrates the usage of the `bottom_up_merge_sort` function.
   - It initializes an example array, sorts it, and prints both the original and sorted arrays to show the result.

This program demonstrates the use of an iterative approach to merge sort, which is an efficient, stable sorting algorithm with a time complexity of O(n log n). The bottom-up approach avoids the need for recursion, making it suitable for environments where deep recursion could lead to stack overflow.
*/
