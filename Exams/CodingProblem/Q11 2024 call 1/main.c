#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 3
#define C 5

void avg(int matI[R][C], float matO[R][C]);

int main(void) {
    int matI[R][C] = {
            {2, 3, 4, 5, 0},
            {4, 1, 7, 3, 3},
            {2, 9, 8, 1, 0}
    };

    float matO[R][C];
    avg(matI, matO);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fprintf(stdout, "%.2f ", matO[i][j]);
        }
        fprintf(stdout, "\n");
    }

    return 1;
}

void avg(int matI[R][C], float matO[R][C]) {
    int i, j, ii, jj, n;
    float s;

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            s = n = 0;

            // Traverse diagonals starting from matI[i][j]
            for (ii = i + 1, jj = j + 1; ii < R && jj < C; ii++, jj++) {
                s = s + matI[ii][jj];
                n++;
            }

            for (ii = i + 1, jj = j - 1; ii < R && jj >= 0; ii++, jj--) {
                s = s + matI[ii][jj];
                n++;
            }

            for (ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--) {
                s = s + matI[ii][jj];
                n++;
            }

            for (ii = i - 1, jj = j + 1; ii >= 0 && jj < C; ii--, jj++) {
                s = s + matI[ii][jj];
                n++;
            }

            // Include the center element matI[i][j]
            s = s + matI[i][j];
            n++;

            // Compute the average
            matO[i][j] = s / n;
        }
    }

    return;
}
