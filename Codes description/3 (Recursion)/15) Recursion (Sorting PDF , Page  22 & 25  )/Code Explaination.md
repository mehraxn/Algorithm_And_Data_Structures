#Quick Sort Program

## Overview
This program demonstrates the implementation of the Quick Sort algorithm in C. Quick Sort is a well-known and efficient sorting algorithm that uses the divide-and-conquer approach. It recursively partitions the array around a pivot element and sorts the subarrays before and after the pivot. The average time complexity of Quick Sort is **O(n log n)**, making it suitable for sorting large datasets efficiently.

The program includes several main components:
1. **`quick_sort` Function**: A wrapper function that initializes the sorting process.
2. **`quick_sort_r` Function**: A recursive function that performs the core sorting logic by partitioning and sorting the subarrays.
3. **`partition` Function**: A function that partitions the array around a pivot element.
4. **`swap` Function**: A utility function to swap two elements in the array.
5. **`main` Function**: A function that demonstrates the Quick Sort algorithm by sorting an example array and printing the results.

## Function Descriptions

### 1. `quick_sort` Function
The `quick_sort` function serves as a wrapper for the recursive Quick Sort algorithm.
- **Input Parameters**: Takes an integer array (`A`) and its size (`N`).
- **Initial Range Setup**: Sets the initial range for sorting (`0` to `N-1`) and calls the `quick_sort_r` function.

This function is responsible for initializing the sorting process and provides an easy way for the user to sort an entire array without having to manually manage indices.

### 2. `quick_sort_r` Function
The `quick_sort_r` function is the core recursive implementation of the Quick Sort algorithm.
- **Input Parameters**: Takes an integer array (`A`) and the indices defining the current range (`l` and `r`).
- **Termination Condition**: If the range has one or no elements (`r <= l`), the function returns without further action.
- **Partitioning**: Partitions the array around a pivot using the `partition` function.
- **Recursive Sorting**: Recursively sorts the subarrays before and after the pivot.

This function effectively divides the problem into smaller subproblems, allowing for efficient sorting using recursion.

### 3. `partition` Function
The `partition` function is responsible for partitioning the array around a pivot element.
- **Input Parameters**: Takes an integer array (`A`) and the indices defining the current range (`l` and `r`).
- **Pivot Selection**: Uses the last element in the current range as the pivot.
- **Partitioning Process**: Rearranges the elements such that all elements less than the pivot are to its left, and all elements greater are to its right.
- **Returning Pivot Index**: Returns the final position of the pivot element, which is used by the `quick_sort_r` function to divide the array for further sorting.

The `partition` function is a crucial part of the Quick Sort algorithm, as it ensures that each partitioned subarray can be sorted independently.

### 4. `swap` Function
The `swap` function is a utility function used to exchange the values of two elements in an array.
- **Input Parameters**: Takes an integer array (`v`) and two indices (`n1` and `n2`) representing the elements to be swapped.
- **Swapping Process**: Uses a temporary variable to swap the values of the two elements.

This function is used by the `partition` function to place elements in their correct positions during the partitioning process.

### 5. `main` Function
The `main` function serves as the entry point of the program and demonstrates the Quick Sort algorithm.
- **Array Initialization**: Initializes an example array (`A`) to be sorted.
- **Printing Original Array**: Prints the original unsorted array.
- **Sorting**: Calls the `quick_sort` function to sort the array (`A`) and prints the sorted result.

The `main` function provides a clear and concise demonstration of the Quick Sort algorithm in action, showing both the original and sorted versions of the array.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc quick_sort_program.c -o quick_sort_program
./quick_sort_program
```

### Expected Output
The program will print the original and sorted versions of the array. For example:

```
Original array: 34 7 23 32 5 62 32
Sorted array: 5 7 23 32 32 34 62
```

## Summary
The Quick Sort program is a practical demonstration of an efficient sorting algorithm using a recursive, divide-and-conquer approach. The **`quick_sort` function** provides a simple wrapper for the recursive sorting process, while the **`quick_sort_r` function** performs the core sorting logic. The **`partition` function** is used to organize elements around a pivot, and the **`swap` function** is used to exchange elements during partitioning.

The **`main` function** shows how these functions work together to sort an array of integers, providing a clear and effective example of the Quick Sort algorithm in C.

Quick Sort is an efficient algorithm for sorting, with an average time complexity of **O(n log n)**. It is well-suited for many applications where fast sorting is required, and this implementation provides an easy-to-understand example of how recursion can be used to solve complex problems effectively.

