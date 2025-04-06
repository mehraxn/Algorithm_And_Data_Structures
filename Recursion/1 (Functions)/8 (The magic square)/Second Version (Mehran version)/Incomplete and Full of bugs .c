#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
int square_r(int **, int, int, int *, int);
int check(int **, int, int, int);
int check_runtime(int **, int, int, int, int);

/* main program */
int main(int argc, char *argv[]) {
    int **matrix, *used, i, j, n, target;

    n = atoi(argv[1]);
    target = n * (n * n + 1) / 2;

    used = (int *)malloc((n * n + 1) * sizeof(int));
    matrix = (int **)malloc(n * sizeof(int *));
    if (used == NULL || matrix == NULL) {
        fprintf(stdout, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stdout, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < n * n; i++) {
        used[i] = 0;
    }

    if (square_r(matrix, target, n, used, 0)) {
        fprintf(stdout, "Magic square of size %d:\n", n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                fprintf(stdout, "%2d ", matrix[i][j]);
            }
            fprintf(stdout, "\n");
        }
    } else {
        fprintf(stdout, "Magic Square NOT found!\n");
    }

    free(used);
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return EXIT_SUCCESS;
}

/*
 * Compute a magic square of given size; return 1 upon success
 */
int square_r(int **matrix, int target, int dim, int *used, int k) {
    int i, j, val;

    if (k == dim * dim) {
        return check(matrix, target, dim, dim);
    }

    i = k / dim;
    j = k % dim;

    for (val = 1; val <= dim * dim; val++) {
        if (used[val] == 0) {
            matrix[i][j] = val;
            used[val] = 1;
            if (check_runtime(matrix, target, dim, i, j) == 0) {
                used[val] = 0;
                continue;
            }
            if (square_r(matrix, target, dim, used, k + 1)) {
                return 1;
            }
            /* backtrack */
            used[val] = 0;
        }
    }
    /* solution not found */
    return 0;
}

/* Check whether a given matrix is a magic square; return 1 if yes */
int check(int **matrix, int target, int dim, int dim1) {
    int i, j, sum;

    /* rows */
    for (i = 0; i < dim; i++) {
        sum = 0;
        for (j = 0; j < dim; j++) {
            sum += matrix[i][j];
        }
        if (sum != target) {
            return 0;
        }
    }

    /* columns */
    for (j = 0; j < dim; j++) {
        sum = 0;
        for (i = 0; i < dim; i++) {
            sum += matrix[i][j];
        }
        if (sum != target) {
            return 0;
        }
    }

    /* diagonals */
    sum = 0;
    for (i = 0; i < dim; i++) {
        sum += matrix[i][i];
    }
    if (sum != target) {
        return 0;
    }

    sum = 0;
    for (i = 0; i < dim; i++) {
        sum += matrix[i][dim - i - 1];
    }
    if (sum != target) {
        return 0;
    }

    return 1;
}

sum += matrix[i][i];
if (sum != target) {
return 0;
}

sum = 0;
for (i = 0; i < dim; i++) {
sum += matrix[i][dim - i - 1];
}
if (sum != target) {
return 0;
}

return 1;
}

/* Check whether a given matrix is a magic square; return 1 if yes */
int check_runtime(int **matrix, int target, int r, int c, int dim) {
    int i, j, sum;

    /* Row */
    sum = 0;
    for (j = 0; j <= c; j++) {
        sum += matrix[r][j];
    }
    if (c < (dim - 1)) {
        if (sum > target) {
            return 0;
        }
    } else {
        if (sum != target) {
            return 0;
        }
    }

    /* Column */
    sum = 0;
    for (i = 0; i <= r; i++) {
        sum += matrix[i][c];
    }
    if (r < (dim - 1)) {
        if (sum > target) {
            return 0;
        }
    } else {
        if (sum != target) {
            return 0;
        }
    }

    return 1;
}

