#include <stdio.h>
#include <stdlib.h>

#define E 0  /* empty cell */
#define F 1  /* full cell */
#define O 255 /* out of the board */

#define SIZE 6 /* board size */

/* offset for the moves */
const int xOff[4] = { 0, 1, 0, -1 };
const int yOff[4] = { -1, 0, 1, 0 };

/* function prototypes */
int move_r (int board[SIZE+1][SIZE+1], int moves[31][4], int n);

/* main program */
int main (void) {
    int i, moves[31][4], board[SIZE+1][SIZE+1] =
            {
                    {O, O, O, O, O, O, O},
                    {O, O, O, O, O, O, O},
                    {O, O, O, F, F, O, O},
                    {O, F, F, F, F, F, O},
                    {O, O, F, F, F, O, O},
                    {O, O, O, F, F, O, O},
                    {O, O, O, O, O, O, O}
            };

    if (move_r(board, moves, 0) == 0) {
        fprintf(stdout, "No solution exists!\n");
    } else {
        for (i = 0; i < 31; i++) {
            fprintf(stdout, "%d %d -> %d %d\n",
                    moves[i][0], moves[i][1], moves[i][2], moves[i][3]);
        }
    }

    return EXIT_SUCCESS;
}

/* make a move (recursive function) */
int move_r (int board[SIZE+1][SIZE+1], int moves[31][4], int n) {
    int x1, y1, x2, y2, x3, y3, k;

    if (n == 31) {
        return 1;
    }

    /* for each board cell ... */
    for (x1 = 1; x1 < SIZE; x1++) {
        for (y1 = 1; y1 < SIZE; y1++) {
            /* ... if there is a pawn ... */
            if (board[x1][y1] == F) {
                /* ... look whether it is possible to eat ... */
                for (k = 0; k < 4; k++) {
                    x2 = x1 + xOff[k];
                    y2 = y1 + yOff[k];
                    if (board[x2][y2] == F) {
                        x3 = x1 + 2 * xOff[k];
                        y3 = y1 + 2 * yOff[k];
                        if (board[x3][y3] == E) {
                            /* ... then make the move ... */
                            board[x3][y3] = F;
                            board[x2][y2] = E;
                            board[x1][y1] = E;

                            /* ... and recur ... */
                            if (move_r(board, moves, n + 1) == 1) {
                                /* ... storing the move if it was ok ... */
                                moves[n][0] = x1;
                                moves[n][1] = y1;
                                moves[n][2] = x3;
                                moves[n][3] = y3;
                                return 1;
                            }

                            /* ... otherwise backtrack */
                            board[x3][y3] = E;
                            board[x2][y2] = F;
                            board[x1][y1] = F;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
