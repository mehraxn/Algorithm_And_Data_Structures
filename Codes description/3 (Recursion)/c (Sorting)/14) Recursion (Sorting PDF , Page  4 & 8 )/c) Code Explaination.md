#Bottom-Up Merge Sort Program

## Overview
This program implements a bottom-up merge sort algorithm to sort an array of integers. Merge sort is a classic divide-and-conquer sorting algorithm known for its efficiency and stability. The bottom-up version of merge sort iteratively merges subarrays of increasing sizes until the entire array is sorted. Additionally, the program includes a function to merge two sorted arrays into a third array.

The program is implemented in C and includes three main components:
1. **`bottom_up_merge_sort` Function**: A function that sorts an array using the bottom-up merge sort approach.
2. **`merge` Function**: A function that merges two sorted arrays into a single sorted array.
3. **`main` Function**: A function that demonstrates the sorting process by initializing example arrays, sorting them, and displaying the results.

## Function Descriptions

### 1. `bottom_up_merge_sort` Function
The `bottom_up_merge_sort` function sorts an array using the bottom-up merge sort algorithm.
- **Input Parameters**: Takes an integer array (`A`) and its size (`N`).
- **Temporary Array**: Allocates a temporary array (`B`) of size `N` to assist in merging subarrays.
- **Iteration and Merging**: Iteratively merges subarrays of increasing size (`m`) until the entire array is sorted.
- **Freeing Memory**: Frees the allocated memory (`B`) after sorting is complete.

This function avoids recursion by using a loop to merge subarrays, making it suitable for environments where deep recursion could cause stack overflow issues.

### 2. `merge` Function
The `merge` function is responsible for merging two sorted arrays into a third sorted array.
- **Input Parameters**: Takes two sorted arrays (`v1` and `v2`) of size `n` each, and a third array (`v3`) to store the merged result.
- **Merging Process**: Compares elements from the two input arrays and adds the smaller value to the output array (`v3`). This process continues until all elements from both arrays are merged.
- **Handling Remaining Elements**: Copies any remaining elements from the input arrays into the output array.

The `merge` function ensures that the combined array (`v3`) is sorted, and it serves as a fundamental part of the merge sort algorithm.

### 3. `main` Function
The `main` function serves as the entry point of the program and demonstrates the usage of the sorting and merging functions.
- **Array Initialization**: Initializes an example array (`A`) to be sorted.
- **Sorting**: Calls the `bottom_up_merge_sort` function to sort the array (`A`) and prints both the original and sorted arrays.
- **Merging Sorted Arrays**: Demonstrates merging two sorted arrays (`v1` and `v2`) into a third array (`v3`) and prints the merged result.

The `main` function provides a simple interface for the user to see how the sorting and merging processes work.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc bottom_up_merge_sort.c -o bottom_up_merge_sort
./bottom_up_merge_sort
```

### Expected Output
The program will print the original and sorted versions of the array, as well as the result of merging two sorted arrays. For example:

```
Original array: 5 3 8 4 2 7 1 6
Sorted array: 1 2 3 4 5 6 7 8
Merged array: 1 2 3 4 5 6 7 8
```

## Summary
The bottom-up merge sort program is a practical example of an efficient, stable sorting algorithm. The **`bottom_up_merge_sort` function** uses an iterative approach to avoid deep recursion, making it more suitable for systems with limited stack space. The **`merge` function** combines two sorted arrays into one, which is a crucial part of the merge sort process.

The **`main` function** demonstrates how these functions work together to sort an array and merge sorted arrays, making the program an educational tool for understanding the concepts of merge sort and iterative sorting algorithms.

Merge sort has a time complexity of **O(n log n)** and is known for being stable, which means it maintains the relative order of equal elements. This makes it a great choice for sorting large datasets where stability is required.

