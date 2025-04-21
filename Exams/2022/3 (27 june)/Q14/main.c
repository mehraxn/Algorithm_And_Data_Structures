#include <stdio.h>
#define N 8 // Define the size of the chessboard

// Function to calculate the maximum reachable value by a knight
void knight(int mat[N][N], int *r, int *c) {
    // All possible moves for a knight in chess
    int moves[8][2] = {
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };

    int max_sum = 0; // To store the maximum sum of reachable pieces
    *r = -1;         // To store the row of the best position
    *c = -1;         // To store the column of the best position

    // Iterate through each cell of the chessboard
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Only consider empty cells (value 0)
            if (mat[i][j] == 0) {
                int current_sum = 0;

                // Check all knight moves from this cell
                for (int k = 0; k < 8; k++) {
                    int ni = i + moves[k][0]; // New row
                    int nj = j + moves[k][1]; // New column

                    // Ensure the new position is within bounds
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                        current_sum += mat[ni][nj]; // Add the value of the reachable cell
                    }
                }

                // Update maximum sum and best position if needed
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    *r = i;
                    *c = j;
                }
            }
        }
    }
}