#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare strings for qsort
int compare_strings(const void *a, const void *b) {
    const char **str_a = (const char **)a;
    const char **str_b = (const char **)b;
    return strcmp(*str_a, *str_b);
}

// Main function to demonstrate conversion from static 3D array to sorted dynamic 2D array
int main() {
    // Static 3D array of strings (3x2x20), containing random names
    char names[3][2][20] = {
            {"Alice", "Bob"},
            {"Charlie", "David"},
            {"Eve", "Frank"}
    };

    int total_elements = 3 * 2; // Total number of strings in the 3D array
    char **sorted_array;

    // Allocate memory for the dynamic 2D array (1D of pointers)
    sorted_array = (char **)malloc(total_elements * sizeof(char *));
    if (sorted_array == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Copy strings from the static 3D array to the dynamic 2D array
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            sorted_array[index] = (char *)malloc((strlen(names[i][j]) + 1) * sizeof(char));
            if (sorted_array[index] == NULL) {
                fprintf(stderr, "Memory allocation error.\n");
                // Free previously allocated memory in case of failure
                for (int k = 0; k < index; k++) {
                    free(sorted_array[k]);
                }
                free(sorted_array);
                exit(1);
            }
            strcpy(sorted_array[index], names[i][j]);
            index++;
        }
    }

    // Sort the dynamic 2D array of strings
    qsort(sorted_array, total_elements, sizeof(char *), compare_strings);

    // Print the sorted 2D array
    printf("Sorted names:\n");
    for (int i = 0; i < total_elements; i++) {
        printf("%s\n", sorted_array[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < total_elements; i++) {
        free(sorted_array[i]);
    }
    free(sorted_array);

    return 0;
}

/*
Summary of the Code:

1. Static 3D Array Initialization:
   - A static 3D array of strings (`names[3][2][20]`) is defined to store random names.
   - The array contains 3 sets of 2 strings each, representing names such as "Alice", "Bob", etc.

2. Dynamic 2D Array Allocation:
   - A dynamic 2D array (`sorted_array`) is allocated to store all the names from the static 3D array.
   - Memory allocation is performed for each string, and proper error handling is included to ensure successful allocation.

3. Copying Strings:
   - The strings from the static 3D array are copied to the dynamic 2D array.
   - Each string is dynamically allocated to ensure that the memory is managed properly.

4. Sorting the Strings:
   - The `qsort()` function is used to sort the dynamic 2D array of strings in alphabetical order.
   - A custom comparison function (`compare_strings`) is provided to compare the strings correctly.

5. Printing and Freeing Memory:
   - The sorted array of strings is printed to the console.
   - All dynamically allocated memory is freed to avoid memory leaks.
*/
