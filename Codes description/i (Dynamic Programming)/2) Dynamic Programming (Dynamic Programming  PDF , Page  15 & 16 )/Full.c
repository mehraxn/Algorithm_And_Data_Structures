#include <stdio.h>

// Function prototype for matrix multiplication
void matrix_multiply(int r1, int c1, int c2, int m1[r1][c1], int m2[c1][c2], int m[r1][c2]);

int main(void) {
    int r1, c1, r2, c2;

    // Input for dimensions of matrix m1
    printf("Enter rows and columns for matrix 1: ");
    scanf("%d %d", &r1, &c1);

    // Input for dimensions of matrix m2
    printf("Enter rows and columns for matrix 2: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible (number of columns of m1 must equal number of rows of m2)
    if (c1 != r2) {
        printf("Matrix multiplication is not possible. Number of columns of matrix 1 must equal number of rows of matrix 2.\n");
        return 1;
    }

    int m1[r1][c1], m2[r2][c2], m[r1][c2];  // Declare the matrices

    // Input for matrix m1
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    // Input for matrix m2
    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    // Call the matrix_multiply function to compute the product
    matrix_multiply(r1, c1, c2, m1, m2, m);

    // Output the result matrix m
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function to multiply two matrices
void matrix_multiply(int r1, int c1, int c2, int m1[r1][c1], int m2[c1][c2], int m[r1][c2]) {
    int i, j, k;

    // Loop through rows of m1
    for (i = 0; i < r1; i++) {
        // Loop through columns of m2
        for (j = 0; j < c2; j++) {
            m[i][j] = 0;  // Initialize the result matrix element to 0
            // Perform the multiplication and sum the results
            for (k = 0; k < c1; k++) {
                m[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

/*
Explanation of Functions:

1. **`main()` function:**
   - **Purpose:** Handles user input, checks for valid matrix dimensions, and manages the matrix multiplication process.
   - **Steps:**
     - The user is prompted to input the dimensions of two matrices (m1 and m2).
     - It checks if matrix multiplication is possible (i.e., the number of columns in `m1` must be equal to the number of rows in `m2`).
     - The program then asks the user to enter the elements of both matrices.
     - After the input is complete, it calls the `matrix_multiply()` function to perform the matrix multiplication.
     - Finally, it prints the resulting matrix after multiplication.

2. **`matrix_multiply()` function:**
   - **Purpose:** Performs the multiplication of two matrices.
   - **Steps:**
     - It takes the dimensions of the matrices and the matrices themselves as input parameters.
     - The function initializes each element of the result matrix `m` to 0.
     - It then uses three nested loops to multiply the rows of matrix `m1` with the columns of matrix `m2`, summing the products to fill in the elements of the result matrix `m`.
     - After the function completes, the resulting matrix `m` contains the product of the two matrices.
*/
