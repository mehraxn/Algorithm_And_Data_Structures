// Wrapper function for Quick Sort
void quick_sort(int *A, int N) {
    int l, r;
    l = 0;
    r = N - 1;
    quick_sort_r(A, l, r);
}

// Recursive function to perform Quick Sort
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
void swap(int *v, int n1, int n2) {
    int temp;
    temp = v[n1];
    v[n1] = v[n2];
    v[n2] = temp;
    return;
}
