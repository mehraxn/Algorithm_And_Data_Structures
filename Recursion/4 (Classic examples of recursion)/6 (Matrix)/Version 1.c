#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3
#define TRUE 1
#define FALSE 0
#define MIN_VALUE -2147483648

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

int findMaxPathSum(int matrix[ROWS][COLS], int row, int col,
                   int visited[ROWS][COLS], int currentSum,
                   int targetRow, int targetCol) {

    visited[row][col] = TRUE;
    currentSum += matrix[row][col];

    if (row == targetRow && col == targetCol) {
        visited[row][col] = FALSE;  // Backtrack
        return currentSum;
    }

    int maxSum = MIN_VALUE;


    for (int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];


        if (isValid(newRow, newCol) && !visited[newRow][newCol]) {

            int sum = findMaxPathSum(matrix, newRow, newCol, visited,
                                     currentSum, targetRow, targetCol);

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }


    visited[row][col] = FALSE;

    return maxSum;
}


int findMaxPath(int matrix[ROWS][COLS], int startRow, int startCol,
                int targetRow, int targetCol) {
    int visited[ROWS][COLS];
    int i, j;


    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            visited[i][j] = FALSE;
        }
    }

    return findMaxPathSum(matrix, startRow, startCol, visited, 0,
                          targetRow, targetCol);
}


int main() {

    int matrix[ROWS][COLS] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };


    int maxSum = findMaxPath(matrix, 0, 0, 2, 2);

    if (maxSum == MIN_VALUE) {
        printf("No valid path exists from (%d,%d) to (%d,%d).\n", 0, 0, 2, 2);
    } else {
        printf("Maximum path sum: %d\n", maxSum);
    }

    return 0;
}