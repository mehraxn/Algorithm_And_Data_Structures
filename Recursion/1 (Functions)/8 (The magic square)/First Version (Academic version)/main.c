#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
int square_r(int **matrix, int dim, int *used, int k);
int check(int **matrix, int dim);

/* main program */
int main(int argc, char *argv[]) {
    int **matrix, *used, i, j, n;

    // Validate arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <size_of_magic_square>\n", argv[0]);
        return EXIT_FAILURE;
    }

    n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Invalid size. Must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory
    used = (int *)malloc((n * n + 1) * sizeof(int));
    matrix = (int **)malloc(n * sizeof(int *));
    if (used == NULL || matrix == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Initialize `used` array and matrix
    for (i = 0; i <= n * n; i++) {
        used[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = 0; // Initialize matrix to 0
        }
    }

    printf("Magic square size: %d\n", n);
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

    // Free memory
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
int square_r(int **matrix, int dim, int *used, int k) {
    int i, j, val;

    if (k == dim * dim) {
        return check(matrix, dim);
    }

    i = k / dim;
    j = k % dim;

    for (val = 1; val <= dim * dim; val++) {
        if (used[val] == 0) {
            /* put a new value and recur */
            matrix[i][j] = val;
            used[val] = 1;
            if (square_r(matrix, dim, used, k + 1)) {
                /* solution found: stop the process */
                return 1;
            }
            /* backtrack */
            matrix[i][j] = 0; // Clear the cell in the matrix
            used[val] = 0;
        }
    }

    /* solution not found */
    return 0;
}

/*
 * Check if the given matrix is a magic square
 */
int check(int **matrix, int dim) {
    int i, j, sum, target;

    target = dim * (dim * dim + 1) / 2;

    // Check rows
    for (i = 0; i < dim; i++) {
        sum = 0;
        for (j = 0; j < dim; j++) {
            sum += matrix[i][j];
        }
        if (sum != target) return 0;
    }

    // Check columns
    for (j = 0; j < dim; j++) {
        sum = 0;
        for (i = 0; i < dim; i++) {
            sum += matrix[i][j];
        }
        if (sum != target) return 0;
    }

    // Check main diagonal
    sum = 0;
    for (i = 0; i < dim; i++) {
        sum += matrix[i][i];
    }
    if (sum != target) return 0;

    // Check secondary diagonal
    sum = 0;
    for (i = 0; i < dim; i++) {
        sum += matrix[i][dim - i - 1];
    }
    if (sum != target) return 0;

    return 1;
}
