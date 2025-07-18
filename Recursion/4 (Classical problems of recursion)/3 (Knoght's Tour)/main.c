#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 6

const int offset_x[]={2,2,1,1,-1,-1,-2,-2};
const int offset_y[]={1,-1,2,-2,2,-2,1,-1};

int move_r(int , int , int , int [][N]);

int main() {
    int i, j, board[N][N];

    // Initialize the board
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            board[i][j] = 0;

    printf("Please insert the first position of the knight.\n");
    printf("(insert row and column with a space. for example 0 3)\n");
    scanf("%d %d", &i, &j);

    // Set the starting position of the knight
    board[i][j] = 1;

    if (move_r(2, i, j, board)) {
        printf("Solution found:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Solution not found!\n");
    }

    return EXIT_SUCCESS;
}

int move_r(int movement, int x, int y, int board[N][N]) {
    int i, xx, yy;

    if (movement == (N * N + 1))
        return 1;

    for (i = 0; i < 8; i++) {
        xx = offset_x[i] + x;
        yy = offset_y[i] + y;

        if (xx < N && xx >= 0 && yy < N && yy >= 0) {
            if (board[xx][yy] == 0) {
                board[xx][yy] = movement;
                if (move_r(movement + 1, xx, yy, board)) {
                    return 1;
                }
                board[xx][yy] = 0; // Backtrack
            }
        }
    }

    return 0;
}
