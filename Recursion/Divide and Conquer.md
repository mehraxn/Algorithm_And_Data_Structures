# Divide and Conquer: README

## Overview
Divide and Conquer is a fundamental algorithmic paradigm. It is used to solve complex problems by breaking them down into simpler subproblems, solving each subproblem independently, and then combining their solutions to form the overall solution.

This technique is often used in sorting algorithms, matrix multiplication, and many other recursive algorithms.

## Steps of Divide and Conquer

### 1. Divide
- **Start with a problem of size `n`**.
- **Partition** the problem into `a>=1` **independent** subproblems.
- Each subproblem has a size `n^` such that `n^ < n`.

### 2. Conquer
- **Solve** the subproblems recursively.
- At the base level, solve **elementary problems** directly.
- **Termination condition** must be defined:
  - All algorithms must eventually terminate.
  - The recursion must be **finite**.

### 3. Combine
- **Combine** the solutions of the subproblems to form the final solution to the original problem.

## Example in C: Merge Sort
```c
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
```

## Summary
Divide and Conquer works best when a problem can be broken down into subproblems that are:
- Smaller in size
- Solved independently
- Easily combinable into a complete solution

Common examples: Merge Sort, Quick Sort, Binary Search, Strassen's Matrix Multiplication.

