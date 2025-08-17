#include <stdio.h>

// Wrapper function for Quick Sort
// This function sets up the initial range for sorting and calls the recursive Quick Sort function.
void quick_sort(int *A, int N) {
    int l, r;
    l = 0;
    r = N - 1;
    quick_sort_r(A, l, r);
}

// Recursive function to perform Quick Sort
// This function sorts the elements between indices l and r by partitioning them around a pivot.
void quick_sort_r(int *A, int l, int r) {
    int c;

    // Termination condition: if the range has one or no elements, return
    if (r <= l)
        return;

    // Partition the array and get the pivot index
    c = partition(A, l, r);

    // Recursively sort elements before and after the partition
    quick_sort_r(A, l, c - 1);
    quick_sort_r(A, c + 1, r);
}

// Partition function to arrange elements based on a pivot
// This function selects a pivot element and rearranges the array such that all elements less than the pivot
// are to its left and all elements greater are to its right.
int partition(int *A, int l, int r) {
    int i, j, pivot;

    i = l - 1;
    j = r;
    pivot = A[r];

    while (i < j) {
        // Find element greater than or equal to pivot
        while (A[++i] < pivot);
        // Find element less than pivot
        while (j > l && A[--j] >= pivot);
        if (i < j)
            swap(A, i, j);
    }
    // Place pivot in its correct position
    swap(A, i, r);
    return i;
}

// Function to swap two elements in an array
// This function exchanges the values of two elements in the array.
void swap(int *v, int n1, int n2) {
    int temp;
    temp = v[n1];
    v[n1] = v[n2];
    v[n2] = temp;
    return;
}

// Main function to demonstrate Quick Sort
// This function initializes an array, sorts it using Quick Sort, and prints the result.
int main() {
    int A[] = {34, 7, 23, 32, 5, 62, 32};
    int N = sizeof(A) / sizeof(A[0]);

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Sort the array using Quick Sort
    quick_sort(A, N);

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

1. quick_sort Function:
   - The `quick_sort` function acts as a wrapper for the recursive Quick Sort function.
   - It sets the initial range for sorting, from index `0` to `N-1`, and calls the `quick_sort_r` function.

2. quick_sort_r Function:
   - The `quick_sort_r` function is the recursive implementation of the Quick Sort algorithm.
   - It partitions the array around a pivot and then recursively sorts the subarrays before and after the pivot.
   - The recursion continues until the base condition is met (i.e., one or no elements in the range).

3. partition Function:
   - The `partition` function selects a pivot element (in this case, the last element of the range) and rearranges the elements.
   - Elements less than the pivot are placed to the left, and elements greater are placed to the right.
   - The function returns the final position of the pivot, which is then used to divide the array for further sorting.

4. swap Function:
   - The `swap` function is a utility function that exchanges two elements in the array.
   - It is used by the `partition` function to place elements in their correct positions during the partitioning process.

5. main Function:
   - The `main` function demonstrates the Quick Sort algorithm by initializing an example array, sorting it, and printing both the original and sorted arrays.

Quick Sort is an efficient sorting algorithm with an average time complexity of **O(n log n)**. It uses the divide-and-conquer approach to partition the array and sort the subarrays independently. This program provides a clear demonstration of how Quick Sort works and the role of recursion in dividing and conquering the problem.
*/
