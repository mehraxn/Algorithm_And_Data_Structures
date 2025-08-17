#include <stdio.h>

// Function to find the maximum value in an array using recursion
int max(int v[], int l, int r) {
    int c, m1, m2;

    // Base case: if the segment has only one element, return it
    if (l >= r)
        return v[l];

    // Find the midpoint of the current segment
    c = (l + r) / 2;

    // Recursively find the maximum value in the left half and the right half
    m1 = max(v, l, c);
    m2 = max(v, c + 1, r);

    // Return the larger of the two maximum values found
    if (m1 > m2)
        return m1;
    else
        return m2;
}

// Main function to demonstrate the max function
int main() {
    // Define an array of integers
    int v[] = {1, 5, 3, 9, 2, 8, 4};
    int n = sizeof(v) / sizeof(v[0]);

    // Call the max function to find the maximum value in the array
    int maximum = max(v, 0, n - 1);

    // Print the maximum value
    printf("The maximum value in the array is: %d\n", maximum);

    return 0;
}

/*
Summary of the Functions:

1. max Function:
   - The `max` function is a recursive function that finds the maximum value in an integer array.
   - It takes three parameters: `v[]` (the array), `l` (the left index), and `r` (the right index).
   - The base case of the recursion is when the segment has only one element (`l >= r`), in which case it returns that element.
   - The function finds the midpoint of the segment, then recursively finds the maximum value in both the left and right halves.
   - Finally, it compares the two maximum values found and returns the larger of the two.

2. main Function:
   - The `main` function demonstrates the use of the `max` function.
   - It defines an array of integers and calculates its length.
   - The `max` function is called to find the maximum value in the entire array, and the result is printed to the console.
*/
