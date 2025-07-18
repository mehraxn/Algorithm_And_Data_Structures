#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
int square_r(int **matrix, int dim, int *used, int k);
int check(int **matrix, int dim);

/* main program */
int main() {
    int **matrix, *used, i, j, n;

    printf("Enter the size of the magic square: ");
    scanf("%d", &n);

    used = (int *)malloc((n * n + 1) * sizeof(int));
    matrix = (int **)calloc(n, sizeof(int *));
    if (used == NULL || matrix == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the used array to all zeros
    for (i = 0; i <= n*n; i++) {
        used[i] = 0;
    }

    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
    }

    if (square_r(matrix, n, used, 0)) {
        fprintf(stdout, "Magic square of size %d:\n", n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                fprintf(stdout, "%2d ", matrix[i][j]);
            }
            fprintf(stdout, "\n");
        }
    } else {
        fprintf(stdout, "Magic square NOT found!\n");
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
int square_r(int **matrix, int dimension, int *marked, int pos) {

    if (pos == dimension * dimension)
        return check(matrix, dimension);

    int i, j, x;

    i = pos / dimension;
    j = pos % dimension;

    for (x = 1; x <= dimension*dimension; x++) {
        if (marked[x] == 0) {
            marked[x] = 1;
            matrix[i][j] = x;
            if (square_r(matrix, dimension, marked, pos+1))
                return 1;
            marked[x] = 0;
        }
    }

    return 0;
}

int check(int **matrix, int dim) {
    int i, j, sum, target;
    target = dim * (dim * dim + 1) / 2;

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
        sum += matrix[i][dim - 1 - i];
    }
    if (sum != target) {
        return 0;
    }

    return 1;
}