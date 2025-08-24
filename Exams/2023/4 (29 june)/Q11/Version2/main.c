#include <stdio.h>
#include <limits.h>

void diagonal (int **mat , int r , int c, int r0 , int c0 , int *max , int *min){
    int i , j;

    for (i = r0, j = c0; i < r && j < c; i++, j++) {
        if (mat[i][j] >= *max) *max = mat[i][j];
        if (mat[i][j] <= *min) *min = mat[i][j];
    }

    for (i = r0, j = c0; i >= 0 && j >= 0; i--, j--) {
        if (mat[i][j] >= *max) *max = mat[i][j];
        if (mat[i][j] <= *min) *min = mat[i][j];
    }
}

void inverse_diagonal (int **mat , int r , int c, int r0 , int c0 , int *max , int *min){
    int i , j;

    for (i = r0, j = c0; i < r && j >= 0; i++, j--) {
        if (mat[i][j] >= *max) *max = mat[i][j];
        if (mat[i][j] <= *min) *min = mat[i][j];
    }

    for (i = r0, j = c0; i >= 0 && j < c; i--, j++) {
        if (mat[i][j] >= *max) *max = mat[i][j];
        if (mat[i][j] <= *min) *min = mat[i][j];
    }
}

int max_diff (int **mat , int r , int c){
    int final = INT_MIN;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int max = INT_MIN;
            int min = INT_MAX;

            diagonal(mat, r, c, i, j, &max, &min);
            inverse_diagonal(mat, r, c, i, j, &max, &min);

            if (max - min > final) final = max - min;
        }
    }
    return final;
}
