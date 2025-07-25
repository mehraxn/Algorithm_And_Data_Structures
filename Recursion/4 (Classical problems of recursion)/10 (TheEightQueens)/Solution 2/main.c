#include <stdio.h>
#include <stdlib.h>

#define N 8

/* function prototypes */
int move_r(int board[N][N], int n);
void set_queen(int board[N][N], int r, int c, int val);

/*
 * main program
 */
int main(void) {
    int i, j;
    int board[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (move_r(board, 0)) {
        fprintf(stdout, "Solution found:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (board[i][j] == 6) {
                    fprintf(stdout, "Q");
                } else {
                    fprintf(stdout, "*");
                }
            }
            fprintf(stdout, "\n");
        }
    } else {
        fprintf(stdout, "Solution NOT found!\n");
    }

    return EXIT_SUCCESS;
}

/*
 * place N queens on the NxN board, recursive function
 */
int move_r(int board[N][N], int n) {
    int r, c;

    if (n == N) {
        return 1;
    }

    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            if (board[r][c] == 0) {
                set_queen(board, r, c, +1);
                if (move_r(board, n + 1)) {
                    return 1;
                }
                set_queen(board, r, c, -1);
            }
        }
    }

    return 0;
}

/*
 * mark all the reachable cells when a queen is placed in position r,c
 */
void set_queen(int board[N][N], int r, int c, int val) {
    int i, j;

    for (j = 0; j < N; j++) {
        board[r][j] += val;
    }
    for (i = 0; i < N; i++) {
        board[i][c] += val;
    }
    for (i = r, j = c; i < N && j < N; i++, j++) {
        board[i][j] += val;
    }
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        board[i][j] += val;
    }
    for (i = r, j = c; i < N && j >= 0; i++, j--) {
        board[i][j] += val;
    }
    for (i = r, j = c; i >= 0 && j < N; i--, j++) {
        board[i][j] += val;
    }
}
