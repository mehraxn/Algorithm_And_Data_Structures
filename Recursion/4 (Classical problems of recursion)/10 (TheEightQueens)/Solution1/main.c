#include <stdio.h>
#include <stdlib.h>

#define N 8

/* function prototypes */
int place_r(int board[][N], int, int, int);
int check_solution(int board[][N]);

/* main program */
int main(void) {
    int i, j;
    int board[N][N];

    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            board[i][j] = 0;
        }
    }

    if (place_r(board, 0, -1, 0)) {
        fprintf(stdout, "Solution found:\n");
        for (i=0; i<N; i++) {
            for (j=0; j<N; j++) {
                if (board[i][j] != 0) {
                    fprintf(stdout, "Q");
                } else {
                    fprintf(stdout, ".");
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
int place_r(int board[N][N], int r0, int c0, int n) {
    int r, c;

    if (n == N) {
        if (check_solution(board) == 1) {
            return 1;
        } else
            return 0;
    }

    for (r=0; r<N; r++) {
        for (c = ((r==0) ? (c0+1) : 0); c<N; c++) {
            // Set queen
            board[r][c] = n+1;
            if (place_r(board, r, c, n-1) == 1) {
                return 1;
            }
            // Remove queen = backtrack
            board[r][c] = 0;
        }
    }

    return 0;
}

/*
 * check whether it is possible to set a queen in a given position
 */
int check_solution(int board[N][N]) {
    int r, c, d, n;

    // check rows
    for (r=0; r<N; r++) {
        for (n=0, c=0; c<N; c++) {
            if (board[r][c] != 0) {
                n++;
            }
        }
        if (n>1) {
            return 0;
        }
    }

    // check columns
    for (c=0; c<N; c++) {
        for (n=0, r=0; r<N; r++) {
            if (board[r][c] != 0) {
                n++;
            }
        }
        if (n>1) {
            return 0;
        }
    }

    // check diagonals
    for (d=0; d<2*N-1; d++) {
        n = 0;
        for (r=0; r<N; r++) {
            c = d - r;
            if ((c>=0) && (c<N)) {
                if (board[r][c] != 0) {
                    n++;
                }
            }
        }
        if (n>1) {
            return 0;
        }
    }

    // check reverse diagonals
    for (d=0; d<2*N-1; d++) {
        n = 0;
        for (r=0; r<N; r++) {
            c = r - d + N - 1;
            if ((c>=0) && (c<N)) {
                if (board[r][c] != 0) {
                    n++;
                }
            }
        }
        if (n>1) {
            return 0;
        }
    }

    return 1;
}
