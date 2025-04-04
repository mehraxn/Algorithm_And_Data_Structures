#include <stdio.h>
#include <stdlib.h>

#define N 8

/* Function prototypes */
int place_r(int board[N][N], int, int);
int check_solution(int board[N][N]);

/* main program */
int main(void) {
    int i, j;
    int board[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (place_r(board, 0, 1, 0)) {
        fprintf(stdout, "Solution found:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    fprintf(stdout, "Q ");
                else
                    fprintf(stdout, ". ");
            }
            fprintf(stdout, "\n");
        }
    } else {
        fprintf(stdout, "Solution NOT found\n");
    }

    return EXIT_SUCCESS;
}

/* Place N Queens on the NxN board, recursive function */
int place_r(int board[N][N], int r, int c) {
    int i;
    if (c > N) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        if (check_solution(board, r, i)) {
            board[r][i] = 1;
            if (place_r(board, r + 1, c + 1)) {
                return 1;
            }
            board[r][i] = 0; // backtrack
        }
    }
    return 0;
}

/* Check whether it is possible to set a queen in a given position */
int check_solution(int board[N][N], int r, int c) {
    int i, j;

    // Check rows
    for (i = 0; i < N; i++) {
        if (board[r][i] == 1) {
            return 0;
        }
    }

    // Check columns
    for (i = 0; i < N; i++) {
        if (board[i][c] == 1) {
            return 0;
        }
    }

    // Check diagonals
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }
    for (i = r, j = c; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}
