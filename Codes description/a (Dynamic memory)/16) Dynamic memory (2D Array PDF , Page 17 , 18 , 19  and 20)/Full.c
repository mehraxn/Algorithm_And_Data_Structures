#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

// Function to allocate memory for an integer matrix
// Takes pointers to row and column counts as input and returns a pointer to the allocated matrix
int **allocate_int_matrix(int *r, int *c) {
    int i;
    int **mat;

    printf("Number of rows: ");
    scanf("%d", r);

    mat = (int **)malloc(*r * sizeof(int *));
    if (mat == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    printf("Number of columns: ");
    scanf("%d", c);

    for (i = 0; i < *r; i++) {
        mat[i] = (int *)malloc(*c * sizeof(int));
        if (mat[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            exit(1);
        }
    }

    return mat;
}

// Function to manipulate and free an integer matrix
// Takes the matrix, row count, and column count as input
void manipulate_and_free_matrix(int **mat, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Matrix manipulation goes on...

    for (i = 0; i < r; i++) {
        free(mat[i]);
    }
    free(mat);
}

// Function to allocate memory for a string matrix
// Takes a pointer to row count as input and returns a pointer to the allocated matrix
char **allocate_string_matrix(int *r) {
    int i;
    char s[N], **mat;

    printf("Number of rows: ");
    scanf("%d", r);

    mat = (char **)malloc(*r * sizeof(char *));
    if (mat == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    for (i = 0; i < *r; i++) {
        printf("Enter string for row %d: ", i);
        scanf("%s", s);
        mat[i] = (char *)malloc((strlen(s) + 1) * sizeof(char));
        if (mat[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            exit(1);
        }
        strcpy(mat[i], s);
    }

    return mat;
}

// Function to demonstrate usage of sizeof() operator on static and dynamic arrays
void sizeof_demo() {
    int mat[6][5];

    // Size calculations for statically allocated array
    printf("sizeof(mat): %lu\n", sizeof(mat));     // 6 * 5 * sizeof(int) = 120
    printf("sizeof(mat[i]): %lu\n", sizeof(mat[0]));  // 5 * sizeof(int) = 20
    printf("sizeof(mat[i][j]): %lu\n", sizeof(mat[0][0])); // sizeof(int) = 4

    int r = 6, c = 5, **dyn_mat;
    dyn_mat = (int **)malloc(r * sizeof(int *));
    if (dyn_mat == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    for (int i = 0; i < r; i++) {
        dyn_mat[i] = (int *)malloc(c * sizeof(int));
        if (dyn_mat[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            for (int j = 0; j < i; j++) {
                free(dyn_mat[j]);
            }
            free(dyn_mat);
            exit(1);
        }
    }

    // Size calculations for dynamically allocated array
    printf("sizeof(dyn_mat): %lu\n", sizeof(dyn_mat));     // Size of pointer, typically 8 (or 4 on 32-bit systems)
    printf("sizeof(dyn_mat[i]): %lu\n", sizeof(dyn_mat[0]));  // Size of pointer, typically 8 (or 4)
    printf("sizeof(dyn_mat[i][j]): %lu\n", sizeof(dyn_mat[0][0])); // sizeof(int) = 4

    for (int i = 0; i < r; i++) {
        free(dyn_mat[i]);
    }
    free(dyn_mat);
}

int main() {
    int r, c;
    int **int_matrix;
    char **string_matrix;

    // Allocate and manipulate an integer matrix
    printf("\nExample: Integer Matrix Allocation and Manipulation\n");
    int_matrix = allocate_int_matrix(&r, &c);
    printf("\nEnter values for the integer matrix:\n");
    manipulate_and_free_matrix(int_matrix, r, c);

    // Allocate a string matrix
    printf("\nExample: String Matrix Allocation\n");
    string_matrix = allocate_string_matrix(&r);
    printf("\nStored Strings:\n");
    for (int i = 0; i < r; i++) {
        printf("String %d: %s\n", i, string_matrix[i]);
        free(string_matrix[i]);
    }
    free(string_matrix);

    // Demonstrate sizeof() usage
    printf("\nExample: sizeof() Demonstration\n");
    sizeof_demo();

    printf("\nAll functions executed successfully and behaved as expected.\n");
    return 0;
}

/*
Summary of Functions in the Code:

1. allocate_int_matrix(int *r, int *c):
   - Allocates memory for an integer matrix with given row and column counts.
   - Takes pointers to row and column counts as input.
   - Returns a pointer to the allocated matrix.
   - Handles memory allocation errors and ensures proper cleanup on failure.

2. manipulate_and_free_matrix(int **mat, int r, int c):
   - Accepts an integer matrix, row count, and column count as input.
   - Allows user to input values for the matrix.
   - Frees the memory allocated for the matrix after use.

3. allocate_string_matrix(int *r):
   - Allocates memory for a string matrix with given row count.
   - Takes a pointer to the row count as input.
   - Prompts the user to enter strings and stores them in the allocated matrix.
   - Handles memory allocation errors and ensures proper cleanup on failure.
   - Returns a pointer to the allocated string matrix.

4. sizeof_demo():
   - Demonstrates the use of the sizeof() operator on both statically and dynamically allocated arrays.
   - Prints the size of a statically allocated 2D array and a dynamically allocated 2D array.
   - Frees the dynamically allocated memory after use.
*/
