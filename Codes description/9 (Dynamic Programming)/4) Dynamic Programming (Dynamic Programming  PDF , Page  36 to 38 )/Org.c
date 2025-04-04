#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for the directions in the LCS matrix
#define DIAG 1
#define UP 2
#define LEFT 3

// Function prototypes
int **2D_malloc(int rows, int cols, size_t size);
void 2D_dispose(void ***array, int rows, int cols, void (*freeFunc)(void *));
int lcsLength(char *strX, char *strY, int **b, int **c);
void lcsPrint(char *strX, int **b, int **c, int i, int j);

// Main function
int main() {
    char *strX = "ABCBDAB";
    char *strY = "BDCAB";
    int lX, lY, l;
    int **b, **c;

    lX = strlen(strX) + 1;
    lY = strlen(strY) + 1;

    // Allocate memory for the matrices
    b = (int **)2D_malloc(lX, lY, sizeof(int));
    c = (int **)2D_malloc(lX, lY, sizeof(int));

    // Calculate the LCS length
    l = lcsLength(strX, strY, b, c);

    // Output the LCS length and print the LCS itself
    printf("LCS length: %d\n", l);
    printf("LCS: ");
    lcsPrint(strX, b, c, lX - 1, lY - 1);
    printf("\n");

    // Free the allocated memory
    2D_dispose((void ***)b, lX, lY, NULL);
    2D_dispose((void ***)c, lX, lY, NULL);

    return 0;
}

// Function to allocate memory for a 2D array
int **2D_malloc(int rows, int cols, size_t size) {
int **array;
array = (int **)malloc(rows * sizeof(int *));
if (array == NULL) {
fprintf(stderr, "Memory allocation error\n");
exit(EXIT_FAILURE);
}

for (int i = 0; i < rows; i++) {
array[i] = (int *)malloc(cols * size);
if (array[i] == NULL) {
fprintf(stderr, "Memory allocation error\n");
exit(EXIT_FAILURE);
}
}
return array;
}

// Function to dispose of a 2D array
void 2D_dispose(void ***array, int rows, int cols, void (*freeFunc)(void *)) {
for (int i = 0; i < rows; i++) {
free((*array)[i]);
}
free(*array);
*array = NULL;
}

// Function to compute the LCS length using dynamic programming
int lcsLength(char *strX, char *strY, int **b, int **c) {
    int i, j, m = strlen(strX), n = strlen(strY);

    // Fill the matrices c and b
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (strX[i - 1] == strY[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = DIAG;
            } else {
                if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = UP;
                } else {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = LEFT;
                }
            }
        }
    }

    return c[m][n];  // Return the LCS length
}

// Function to print the LCS from the matrices b and c
void lcsPrint(char *strX, int **b, int **c, int i, int j) {
    if (i != 0 && j != 0) {
        if (b[i][j] == DIAG) {
            lcsPrint(strX, b, c, i - 1, j - 1);
            printf("%c", strX[i - 1]);
        } else {
            if (b[i][j] == UP) {
                lcsPrint(strX, b, c, i - 1, j);
            } else {
                lcsPrint(strX, b, c, i, j - 1);
            }
        }
    }
}
