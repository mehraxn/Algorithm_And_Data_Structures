#include <stdio.h>
#include <stdlib.h>

#define N    12
#define MOVE 8

const int offsetX[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int offsetY[] = {1, 2,  2,  1, -1, -2,-2,-1};

/* function prototypes */
int move_r(int level, int x, int y, int board[N][N]);

/* main program */
int main(void) {
    int i, j, board[N][N];

    /* initialize board */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    fprintf(stdout, "Initial position? ");
    scanf("%d %d", &i, &j);
    board[i][j] = 1;

    if (move_r(2, i, j, board)) {
        fprintf(stdout, "Solution found:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                fprintf(stdout, "%2d ", board[i][j]);
            }
            fprintf(stdout, "\n");
        }
    } else {
        fprintf(stdout, "Solution NOT found!\n");
    }

    return EXIT_SUCCESS;
}

/* compute a knight tour, recursive function */
int move_r(int level, int x, int y, int board[N][N]) {
    int i, j, xx, yy, xxx, yyy;
    int min, imin, count[MOVE];

    if (level == N * N + 1)
        return 1;

    /* count onward moves for each possible move */
    for (i = 0; i < MOVE; i++) {
        xx = x + offsetX[i];
        yy = y + offsetY[i];
        if (xx < N && xx >= 0 && yy < N && yy >= 0 && board[xx][yy] == 0) {
            count[i] = 0;
            for (j = 0; j < MOVE; j++) {
                xxx = xx + offsetX[j];
                yyy = yy + offsetY[j];
                if (xxx < N && xxx >= 0 && yyy < N && yyy >= 0 && board[xxx][yyy] == 0) {
                    count[i]++;
                }
            }
        }
    }

    /* choose move with minimum onward count (Warnsdorff's rule) */
    for (i = 0; i < MOVE; i++) {
        min = MOVE; imin = MOVE;
        for (j = 0; j < MOVE; j++) {
            if (count[j] < min) {
                min = count[j];
                imin = j;
            }
        }
        if (imin < MOVE) {
            xx = x + offsetX[imin];
            yy = y + offsetY[imin];
            if (xx < N && xx >= 0 && yy < N && yy >= 0) {
                if (board[xx][yy] == 0) {
                    board[xx][yy] = level;
                    if (move_r(level + 1, xx, yy, board)) {
                        return 1;
                    }
                    board[xx][yy] = 0;
                }
            }
            count[imin] = MOVE;
        } else {
            break;
        }
    }

    return 0;
}
