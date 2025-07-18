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

void findMaxPathSum(int matrix[ROWS][COLS], int row, int col,
                    int visited[ROWS][COLS], int currentSum,
                    int targetRow, int targetCol, int *maxSum) {

    // Add current cell's value
    currentSum += matrix[row][col];

    // Base case: target reached
    if (row == targetRow && col == targetCol) {
        if (currentSum > *maxSum) {
            *maxSum = currentSum;
        }
        return;
    }

    visited[row][col] = TRUE;

    for (int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
            findMaxPathSum(matrix, newRow, newCol, visited,
                           currentSum, targetRow, targetCol, maxSum);
        }
    }

    visited[row][col] = FALSE;  // Backtrack
}

int findMaxPath(int matrix[ROWS][COLS], int startRow, int startCol,
                int targetRow, int targetCol) {
    int visited[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = FALSE;
        }
    }

    int maxSum = MIN_VALUE;
    findMaxPathSum(matrix, startRow, startCol, visited, 0,
                   targetRow, targetCol, &maxSum);
    return maxSum;
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
