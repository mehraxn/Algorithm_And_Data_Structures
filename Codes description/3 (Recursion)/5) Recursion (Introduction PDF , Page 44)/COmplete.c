#include <stdio.h>

// Function to perform binary search
// This function returns the index of the element `k` in the array `v` if it is present.
// If the element is not found, it returns -1.
int bin_search(int v[], int l, int r, int k) {
    int c;
    // Base case: if the left index exceeds the right, the element is not present
    if (l > r)
        return -1;

    // Calculate the midpoint of the current segment
    c = (l + r) / 2;

    // If the target element is less than the midpoint, search in the left half
    if (k < v[c])
        return bin_search(v, l, c - 1, k);

    // If the target element is greater than the midpoint, search in the right half
    if (k > v[c])
        return bin_search(v, c + 1, r, k);

    // If the element is found, return the index
    return c;
}

// Main function to demonstrate binary search
int main() {
    // Define a sorted array of integers
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(v) / sizeof(v[0]);
    int k;

    // Prompt the user to input the element to search for
    printf("Input the value to search: ");
    scanf("%d", &k);

    // Perform binary search on the array
    int result = bin_search(v, 0, n - 1, k);

    // Print the result
    if (result != -1)
        printf("Element %d found at index %d\n", k, result);
    else
        printf("Element %d not found in the array\n", k);

    return 0;
}

/*
Summary of the Functions:

1. bin_search Function:
   - The `bin_search` function implements the binary search algorithm to find the position of a given element in a sorted array.
   - It takes four parameters: `v[]` (the array), `l` (the left index), `r` (the right index), and `k` (the element to search for).
   - The function calculates the midpoint and decides whether the element is in the left half or the right half of the current segment.
   - If the element matches the midpoint, it returns the index of the element.
   - If the element is not found, it returns `-1`.

2. main Function:
   - The `main` function demonstrates the usage of the `bin_search` function.
   - It defines a sorted array, takes input from the user, and calls `bin_search` to find the target element.
   - It then prints whether the element was found and at which index.

Binary search is a very efficient algorithm for finding an element in a sorted array, with a time complexity of O(log n). This implementation uses recursion to repeatedly divide the array into smaller segments until the target element is found or determined to be absent.
*/
