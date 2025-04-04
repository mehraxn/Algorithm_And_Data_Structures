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

// Main program
int main(int argc, char *argv[]) {
    int *p, **m, n, i, j, best;

    // Read the matrix chain sizes from the file
    p = readSizes(argv[1], &n);

    // Allocate memory for the matrix m (n+1 by n+1)
    m = (int **)util_malloc((n+1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        m[i] = (int *)util_malloc((n+1) * sizeof(int));
        // Initialize the matrix with zeroes on the diagonal and infinity elsewhere
        for (j = 0; j <= n; j++) {
            m[i][j] = ((i == j) ? 0 : INT_MAX);
        }
    }

    // Compute the minimum cost of matrix chain multiplication
    best = matrixChainOrder(p, m, n);

    // Print the optimal parenthesization of matrix chain multiplication
    matrixChainPrint(m, 1, n);

    // Free the dynamically allocated memory
    for (i = 0; i <= n; i++) {
        util_free(m[i]);
    }
    util_free(m);
    util_free(p);

    return 0;
}

// Function to read matrix chain sizes from a file
int *readSizes(char *filename, int *num) {
    int i, n, *p;
    FILE *fp;

    // Open the file for reading
    fp = util_fopen(filename, "r");

    // Read the number of matrices
    fscanf(fp, "%d", &n);

    // Allocate memory for the array p to store matrix dimensions
    p = (int *)util_malloc((n + 1) * sizeof(int));

    // Read the dimensions of the matrices
    for (i = 0; i < n; i++) {
        fscanf(fp, "%dx%d", &p[i], &p[i + 1]);
    }

    // Close the file
    fclose(fp);

    // Store the number of matrices in the num pointer
    *num = n;

    // Return the array of dimensions
    return p;
}

// Function to compute the minimum multiplication cost using dynamic programming
int matrixChainOrder(int *p, int **m, int n) {
    int i, j, k, l, cost;

    // Loop through different chain lengths
    for (l = 2; l <= n; l++) {
        // Loop through different starting points
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            // Try all possible places to split the matrix chain
            for (k = i; k <= j - 1; k++) {
                // Calculate the cost of the current split
                cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                // Update the minimum cost and store the split point
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    m[j][i] = k;
                }
            }
        }
    }

    // Return the minimum cost of multiplying matrices from 1 to n
    return m[1][n];
}

// Function to print the optimal parenthesization of the matrix chain multiplication
void matrixChainPrint(int **m, int i, int j) {
    int k;

    // If only one matrix is involved, print its index
    if (i == j) {
        printf("A%d", i);
        return;
    }

    // Find the split point and recursively print the parenthesization
    k = m[j][i];
    printf("(");
    matrixChainPrint(m, i, k);
    printf(" * ");
    matrixChainPrint(m, k + 1, j);
    printf(")");
}

// Function to open a file
FILE *util_fopen(char *filename, char *mode) {
    FILE *fp = fopen(filename, mode);
    // If the file cannot be opened, print an error and exit
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return fp;
}

// Function to allocate memory
void *util_malloc(size_t size) {
    void *ptr = malloc(size);
    // If memory allocation fails, print an error and exit
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to free allocated memory
void util_free(void *ptr) {
    free(ptr);
}

