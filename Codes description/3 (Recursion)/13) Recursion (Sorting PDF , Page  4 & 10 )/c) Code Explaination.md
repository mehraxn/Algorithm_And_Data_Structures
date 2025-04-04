#Bottom-Up Merge Sort Program

## Overview
This program demonstrates the use of an iterative, bottom-up merge sort algorithm to sort an array of integers. Merge sort is a well-known sorting algorithm that divides an array into smaller parts, sorts them, and then merges them back together in sorted order. The bottom-up merge sort approach iteratively merges subarrays of increasing size until the entire array is sorted. This implementation is efficient, stable, and avoids the risk of deep recursion that can cause stack overflow.

The program includes three main components:
1. **`bottom_up_merge_sort` Function**: A function that sorts the array using the bottom-up merge sort approach.
2. **`merge` Function**: A helper function that merges two sorted subarrays.
3. **`main` Function**: A function that demonstrates the sorting process by initializing an example array, sorting it, and displaying the result.

## Function Descriptions

### 1. `bottom_up_merge_sort` Function
The `bottom_up_merge_sort` function sorts an array of integers using an iterative, bottom-up approach. It performs the following tasks:
- **Input Parameters**: Takes a pointer to the array (`A`) and its size (`N`).
- **Temporary Array**: Allocates a temporary array (`B`) of size `N` to assist in merging subarrays.
- **Iteration and Merging**: Iteratively merges subarrays of increasing size (`m`). The merging process is repeated until the entire array is sorted.
- **Freeing Memory**: Frees the temporary array (`B`) after sorting is complete.

This function avoids recursion by using a loop to merge subarrays, which makes it more suitable for environments where deep recursion could cause problems, such as embedded systems or large datasets.

### 2. `merge` Function
The `merge` function is responsible for merging two sorted subarrays into a single sorted subarray.
- **Input Parameters**: Takes the original array (`A`), the temporary array (`B`), and the indices representing the range of the subarrays to be merged (`l`, `c`, and `r`). The subarrays are `A[l..c]` and `A[c+1..r]`.
- **Merging Process**: Compares elements from the two subarrays and places them in the correct order in the temporary array (`B`).
- **Copying Back**: Once the subarrays are merged, the function copies the merged elements back into the original array (`A`).

The `merge` function ensures that the merge sort maintains its stability, meaning that equal elements retain their relative order from the original array.

### 3. `main` Function
The `main` function serves as the entry point of the program and demonstrates the usage of the `bottom_up_merge_sort` function.
- **Array Initialization**: Initializes an example array of integers to be sorted.
- **Printing Original Array**: Prints the original unsorted array.
- **Sorting**: Calls the `bottom_up_merge_sort` function to sort the array.
- **Printing Sorted Array**: Prints the sorted array after the merge sort is complete.

The `main` function provides a simple and clear demonstration of how the bottom-up merge sort works, making it easy to understand the effect of the sorting process.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc bottom_up_merge_sort.c -o bottom_up_merge_sort
./bottom_up_merge_sort
```

### Expected Output
The program will print the original and sorted versions of the array. For example:

```
Original array: 5 3 8 4 2 7 1 6
Sorted array: 1 2 3 4 5 6 7 8
```

## Summary
The bottom-up merge sort program is a practical example of how an iterative approach can be used to implement the merge sort algorithm. The **`bottom_up_merge_sort` function** sorts the entire array by iteratively merging subarrays of increasing size, while the **`merge` function** combines two sorted subarrays into a single sorted subarray. The **`main` function** demonstrates the complete process by sorting an example array and printing the result.

Merge sort is an efficient, stable sorting algorithm with a time complexity of **O(n log n)**. The bottom-up approach offers an alternative to the traditional recursive implementation, making it well-suited for systems with limited stack space or for sorting large datasets. This program provides a clear and concise demonstration of the bottom-up merge sort technique in C.

