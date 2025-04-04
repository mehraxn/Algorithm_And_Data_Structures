#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare_integers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Main function to demonstrate conversion from static 2D array to sorted dynamic 1D array
int main() {
    // Static 2D array of integers (3x3)
    int numbers[3][3] = {
            {3, 1, 4},
            {1, 5, 9},
            {2, 6, 5}
    };

    int rows = 3;
    int cols = 3;
    int total_elements = rows * cols;
    int *sorted_array;

    // Allocate memory for the dynamic 1D array
    sorted_array = (int *)malloc(total_elements * sizeof(int));
    if (sorted_array == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Copy elements from the static 2D array to the dynamic 1D array
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sorted_array[index] = numbers[i][j];
            index++;
        }
    }

    // Sort the dynamic 1D array of integers
    qsort(sorted_array, total_elements, sizeof(int), compare_integers);

    // Print the sorted 1D array
    printf("Sorted numbers:\n");
    for (int i = 0; i < total_elements; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(sorted_array);

    return 0;
}

/*
Summary of the Code:

1. Static 2D Array Initialization:
   - A static 2D array of integers (`numbers[3][3]`) is defined to store some sample numbers.
   - The array contains 3 rows and 3 columns with values such as {3, 1, 4}, {1, 5, 9}, etc.

2. Dynamic 1D Array Allocation:
   - A dynamic 1D array (`sorted_array`) is allocated to store all the integers from the static 2D array.
   - Memory allocation is performed, and proper error handling is included to ensure successful allocation.

3. Copying Elements:
   - The elements from the static 2D array are copied to the dynamic 1D array.

4. Sorting the Elements:
   - The `qsort()` function is used to sort the dynamic 1D array of integers in ascending order.
   - A custom comparison function (`compare_integers`) is provided to compare the integers correctly.

5. Printing and Freeing Memory:
   - The sorted array of integers is printed to the console.
   - The dynamically allocated memory is freed to avoid memory leaks.
*/
