#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to check if there exist three numbers whose sum is 17
int findSumRecursive(int matrix[ROWS][COLS], int r, int c, int count, int sum, int target) {
    // Base case: if 3 numbers are chosen, check their sum
    if (count == 3) {
        return sum == target ? 1 : 0;
    }

    // If we have reached the end of the matrix, return 0
    if (r >= ROWS) {
        return 0;
    }

    // Move to the next row if the column index exceeds the limit
    if (c >= COLS) {
        return findSumRecursive(matrix, r + 1, 0, count, sum, target);
    }

    // Include the current element in the sum
    if (findSumRecursive(matrix, r, c + 1, count + 1, sum + matrix[r][c], target)) {
        return 1;
    }

    // Exclude the current element and move to the next one
    return findSumRecursive(matrix, r, c + 1, count, sum, target);
}

int main() {
    // Static 2D matrix
    int matrix[ROWS][COLS] = {
        {4, 6, 3},
        {7, 1, 2},
        {8, 9, 5}
    };

    int target = 17;

    if (findSumRecursive(matrix, 0, 0, 0, 0, target)) {
        printf("Yes, there exist three numbers in the matrix whose sum is %d.\n", target);
    } else {
        printf("No, there do not exist three numbers in the matrix whose sum is %d.\n", target);
    }

    return 0;
}
