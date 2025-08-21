#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void local_max(int **mat, int n, int k);         // Function to find and display local maximums
void display_matrix(int **mat, int n);           // Function to display the matrix
void free_matrix(int **mat, int n);              // Function to free the matrix memory

int main() {
    // Example matrix
    int n = 5; // Size of the matrix
    int k = 1; // Neighborhood size for local maxima
    int **mat = (int **)malloc(n * sizeof(int *)); // Dynamically allocate memory for the matrix

    // Initialize the matrix
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int)); // Allocate memory for each row
        for (int j = 0; j < n; j++) {
            mat[i][j] = (i + 1) * (j + 1); // Example values for the matrix
        }
    }

    // Display the matrix
    printf("Matrix:\n");
    display_matrix(mat, n);

    // Find and display local maximums
    printf("\nLocal maximums with k=%d:\n", k);
    local_max(mat, n, k);

    // Free allocated memory
    free_matrix(mat, n);

    return 0;
}

// Function to find and display local maximums
void local_max(int **mat, int n, int k) {
    // Iterate over each element in the matrix
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int is_local_max = 1; // Assume the current element is a local maximum
            int start_r = (r - k) < 0 ? 0 : (r - k); // Calculate start row for neighborhood
            int end_r = (r + k) >= n ? n - 1 : (r + k); // Calculate end row for neighborhood
            int start_c = (c - k) < 0 ? 0 : (c - k); // Calculate start column for neighborhood
            int end_c = (c + k) >= n ? n - 1 : (c + k); // Calculate end column for neighborhood

            // Check if the current element is the largest in its neighborhood
            for (int i = start_r; i <= end_r; i++) {
                for (int j = start_c; j <= end_c; j++) {
                    if (mat[i][j] > mat[r][c]) {
                        is_local_max = 0; // It's not a local maximum
                        break;
                    }
                }
                if (!is_local_max) break; // Exit early if not a local maximum
            }

            // If the element is a local maximum, display it
            if (is_local_max) {
                printf("Local max: mat[%d][%d] = %d\n", r, c, mat[r][c]);
            }
        }
    }
}

// Function to display the matrix
void display_matrix(int **mat, int n) {
    // Iterate through each row of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]); // Print each element
        }
        printf("\n"); // New line for each row
    }
}

// Function to free the allocated memory for the matrix
void free_matrix(int **mat, int n) {
    // Iterate through each row of the matrix
    for (int i = 0; i < n; i++) {
        free(mat[i]); // Free memory allocated for each row
    }
    free(mat); // Free memory allocated for the matrix itself
}
// Function to find and display local maximums
// Parameters:
// - mat: A 2D integer array representing the matrix
// - n: Size of the matrix (n x n)
// - k: Neighborhood size for local maximum calculation
//
// Logic:
// 1. Iterate over each element in the matrix (outer loop for rows, inner loop for columns).
// 2. For each element `mat[r][c]`:
//    a. Assume it is a local maximum (`is_local_max = 1`).
//    b. Calculate the start and end rows (`start_r`, `end_r`) and columns (`start_c`, `end_c`) of the neighborhood based on `k`.
//       - `start_r` is `r - k` but adjusted to ensure it doesn't go below 0.
//       - `end_r` is `r + k` but adjusted to ensure it doesn't exceed `n-1`.
//       - `start_c` is `c - k` but adjusted to ensure it doesn't go below 0.
//       - `end_c` is `c + k` but adjusted to ensure it doesn't exceed `n-1`.
//    c. Iterate through the neighborhood (`i` for rows, `j` for columns).
//       - If any neighbor `mat[i][j]` is greater than `mat[r][c]`, set `is_local_max` to 0 and break out of the loops.
//    d. If `is_local_max` remains 1, then `mat[r][c]` is a local maximum and print its coordinates and value.


// Function to display the matrix
// Parameters:
// - mat: A 2D integer array representing the matrix
// - n: Size of the matrix (n x n)
//
// Logic:
// 1. Iterate through each row of the matrix.
// 2. For each row, iterate through each column and print the element.
// 3. Print a new line after each row to maintain matrix formatting.


// Function to free the allocated memory for the matrix
// Parameters:
// - mat: A 2D integer array representing the matrix
// - n: Size of the matrix (n x n)
//
// Logic:
// 1. Iterate through each row of the matrix.
// 2. Free the memory allocated for each row.
// 3. Free the memory allocated for the matrix itself.
