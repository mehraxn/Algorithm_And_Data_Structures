#include <stdio.h>
#include <math.h>
#define MAX 10

// Function to calculate the determinant of an n x n matrix using recursion
// This function returns the determinant of the matrix `m` of size `n x n`.
int det(int m[][MAX], int n) {
    int sum, c;
    int tmp[MAX][MAX];
    sum = 0;

    // Base case for 2x2 matrix
    if (n == 2)
        return (det2x2(m));

    // Iterate through each column to expand along the first row
    for (c = 0; c < n; c++) {
        // Create the minor matrix by excluding the current row and column
        minor(m, 0, c, n, tmp);
        // Calculate the determinant recursively using cofactor expansion
        sum = sum + m[0][c] * pow(-1, c) * det(tmp, n - 1);
    }

    return sum;
}

// Function to calculate the determinant of a 2x2 matrix
// This function calculates the determinant of a 2x2 matrix directly using the formula: ad - bc
int det2x2(int m[][MAX]) {
    return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

// Function to create a minor matrix by excluding a given row and column
// This function takes the matrix `m` and creates a minor matrix `m2` by excluding row `i` and column `j`.
void minor(int m[][MAX], int i, int j, int n, int m2[][MAX]) {
    int r, c, rr, cc;
    for (rr = 0, r = 0; r < n; r++) {
        if (r != i) { // Skip the specified row
            for (cc = 0, c = 0; c < n; c++) {
                if (c != j) { // Skip the specified column
                    m2[rr][cc] = m[r][c];
                    cc++;
                }
            }
            rr++;
        }
    }
}

// Main function to demonstrate the determinant calculation
// This function initializes a sample matrix and calculates its determinant.
int main() {
    int matrix[MAX][MAX] = {
            {1, 2, 3},
            {0, 4, 5},
            {1, 0, 6}
    };
    int n = 3; // Size of the matrix (3x3)

    // Calculate the determinant of the matrix
    int result = det(matrix, n);
    printf("The determinant of the matrix is: %d\n", result);

    return 0;
}

/*
Summary of the Functions:

1. det Function:
   - The `det` function calculates the determinant of an `n x n` matrix using recursion and the cofactor expansion method.
   - It takes the matrix `m` and its size `n` as input parameters.
   - If the matrix is `2x2`, it directly calls `det2x2`. Otherwise, it recursively calculates the determinant by expanding along the first row.

2. det2x2 Function:
   - The `det2x2` function calculates the determinant of a `2x2` matrix using the formula `ad - bc`.
   - This is the base case for the recursive determinant calculation, providing a direct solution for `2x2` matrices.

3. minor Function:
   - The `minor` function creates a minor matrix by excluding a specified row and column from the original matrix.
   - It is used by the `det` function to create smaller matrices for recursive determinant calculation.

4. main Function:
   - The `main` function demonstrates the use of the `det` function by initializing a sample matrix and calculating its determinant.
   - It prints the result to the console, providing a simple demonstration of the determinant calculation for a `3x3` matrix.

This program demonstrates the use of recursion to solve the problem of finding the determinant of a matrix. The cofactor expansion method is a fundamental approach to calculate determinants, and recursion simplifies the implementation by breaking down the matrix into smaller minors until the base case is reached.
*/