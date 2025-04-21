#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Function to calculate the sum of all elements in a given row.
 */
int row_sum(int **mat, int n, int row) {
    int sum = 0;
    for (int col = 0; col < n; col++) {
        sum += mat[row][col];
    }
    return sum;
}

/**
 * Function to calculate the sum of all elements in a given column.
 */
int col_sum(int **mat, int n, int col) {
    int sum = 0;
    for (int row = 0; row < n; row++) {
        sum += mat[row][col];
    }
    return sum;
}

/**
 * Function to increment all elements in a given row by 1.
 */
void increment_row(int **mat, int n, int row) {
    for (int col = 0; col < n; col++) {
        mat[row][col]++;
    }
}

/**
 * Function to decrement all elements in a given column by 1.
 */
void decrement_col(int **mat, int n, int col) {
    for (int row = 0; row < n; row++) {
        mat[row][col]--;
    }
}

/**
 * Function to find the shortest sequence of commands to equalize the matrix.
 */
void matrix_equalizer(int **mat, int n) {
    int target = INT_MAX;

    // Find the minimum sum row or column (target value to make all cells equal)
    for (int i = 0; i < n; i++) {
        int r_sum = row_sum(mat, n, i);
        int c_sum = col_sum(mat, n, i);
        if (r_sum < target) {
            target = r_sum;
        }
        if (c_sum < target) {
            target = c_sum;
        }
    }

    printf("Target value: %d\n", target);

    // Commands to transform matrix
    printf("Commands:\n");

    // Equalize each row and column
    for (int i = 0; i < n; i++) {
        // Reduce rows to the target
        while (row_sum(mat, n, i) > target) {
            increment_row(mat, n, i);
            printf("r%d++\n", i);
        }

        // Reduce columns to the target
        while (col_sum(mat, n, i) > target) {
            decrement_col(mat, n, i);
            printf("c%d--\n", i);
        }
    }
}
