#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function prototypes
int *readSizes(char *filename, int *num);
int matrixChainOrder(int *p, int **m, int n);
void matrixChainPrint(int **m, int i, int j);
FILE *util_fopen(char *filename, char *mode);
void *util_malloc(size_t size);
void util_free(void *ptr);

// The main code
int main(int argc, char *argv[]) {
    int *p, **m, n, i, j, best;
    p = readSizes(argv[1], &n);
    m = (int **)util_malloc((n+1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        m[i] = (int *)util_malloc((n+1) * sizeof(int));
        for (j = 0; j <= n; j++) {
            m[i][j] = ((i == j) ? 0 : INT_MAX);
        }
    }
    best = matrixChainOrder(p, m, n);
    matrixChainPrint(m, 1, n);

    // Free the allocated memory
    for (i = 0; i <= n; i++) {
        util_free(m[i]);
    }
    util_free(m);
    util_free(p);

    return 0;
}

// Reads matrix sizes from a file
int *readSizes(char *filename, int *num) {
    int i, n, *p;
    FILE *fp;
    fp = util_fopen(filename, "r");
    fscanf(fp, "%d", &n);
    p = (int *)util_malloc((n+1) * sizeof(int));
    for (i = 0; i < n; i++) {
        fscanf(fp, "%dx%d", &p[i], &p[i+1]);
    }
    fclose(fp);
    *num = n;
    return p;
}

// Matrix chain multiplication dynamic programming function
int matrixChainOrder(int *p, int **m, int n) {
    int i, j, k, l, cost;
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            for (k = i; k <= j - 1; k++) {
                cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    m[j][i] = k;
                }
            }
        }
    }
    return m[1][n];
}

// Print the optimal parenthesization of matrix chain multiplication
void matrixChainPrint(int **m, int i, int j) {
    int k;
    if (i == j) {
        printf("A%d", i);
        return;
    }
    k = m[j][i];
    printf("(");
    matrixChainPrint(m, i, k);
    printf(" * ");
    matrixChainPrint(m, k+1, j);
    printf(")");
}

// Utility function to open a file
FILE *util_fopen(char *filename, char *mode) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Utility function to allocate memory
void *util_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Utility function to free memory
void util_free(void *ptr) {
    free(ptr);
}
