#include <stdio.h>

/**
 * Function to print the elements of a matrix in diagonal order.
 * @param mat - Pointer to the 2D matrix (float array).
 * @param n - Dimension of the matrix (n x n).
 */
void display(float **mat, int n) {
    // Traverse diagonals starting from the top row
    for (int start = 0; start < n; start++) {
        int row = 0, col = start;
        while (col >= 0 && row < n) {
            printf("%.2f ", mat[row][col]);
            row++;
            col--;
        }
    }

    // Traverse diagonals starting from the leftmost column (below the main diagonal)
    for (int start = 1; start < n; start++) {
        int row = start, col = n - 1;
        while (row < n && col >= 0) {
            printf("%.2f ", mat[row][col]);
            row++;
            col--;
        }
    }

    printf("\n");
}

int main() {
    int n = 4; // Example: Size of the matrix
    // Dynamically allocate memory for a 4x4 matrix
    float **mat = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        mat[i] = (float *)malloc(n * sizeof(float));
    }

    // Initialize the matrix with example values
    float example[4][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = example[i][j];
        }
    }

    // Display the matrix in diagonal order
    printf("Diagonal Order Traversal:\n");
    display(mat, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
