// Function to perform bottom-up merge sort on array A of size N
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
