#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants to represent the direction in the LCS matrix
#define DIAG 1  // Diagonal direction for matching characters
#define UP 2    // Up direction for when we don't match and take value from the row above
#define LEFT 3  // Left direction for when we don't match and take value from the column to the left

// Function prototypes
int **matrix_malloc(int rows, int cols, size_t size);
void matrix_dispose(void ***array, int rows, int cols, void (*freeFunc)(void *));
int lcsLength(char *strX, char *strY, int **b, int **c);
void lcsPrint(char *strX, int **b, int **c, int i, int j);

// Main function
int main() {
    // Strings to compare
    char *strX = "ABCBDAB";  // First string
    char *strY = "BDCAB";    // Second string
    int lX, lY, l;           // Lengths of the strings + 1 for DP matrix dimensions
    int **b, **c;             // Matrices to store directions and LCS lengths

    // Calculate string lengths and allocate space for the matrices
    lX = strlen(strX) + 1;
    lY = strlen(strY) + 1;

    // Allocate memory for the direction matrix 'b' and the LCS length matrix 'c'
    b = (int **)matrix_malloc(lX, lY, sizeof(int));
    c = (int **)matrix_malloc(lX, lY, sizeof(int));

    // Compute the length of the longest common subsequence
    l = lcsLength(strX, strY, b, c);

    // Print the length of the LCS
    printf("LCS length: %d\n", l);
    // Print the actual LCS
    printf("LCS: ");
    lcsPrint(strX, b, c, lX - 1, lY - 1);
    printf("\n");

    // Free the allocated memory for the matrices
    matrix_dispose((void ***)b, lX, lY, NULL);
    matrix_dispose((void ***)c, lX, lY, NULL);

    return 0;
}

// Function to allocate memory for a 2D array dynamically
int **matrix_malloc(int rows, int cols, size_t size) {
    int **array;

    // Allocate memory for an array of row pointers
    array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * size);
        if (array[i] == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
    }

    return array;
}

// Function to free memory allocated for a 2D array
void matrix_dispose(void ***array, int rows, int cols, void (*freeFunc)(void *)) {
    // Free each row in the array
    for (int i = 0; i < rows; i++) {
        free((*array)[i]);
    }

    // Free the array of row pointers
    free(*array);
    *array = NULL;  // Set the pointer to NULL to avoid dangling pointers
}

// Function to calculate the LCS length using dynamic programming
int lcsLength(char *strX, char *strY, int **b, int **c) {
    int i, j, m = strlen(strX), n = strlen(strY);

    // Fill the DP matrices
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (strX[i - 1] == strY[j - 1]) {  // Characters match
                c[i][j] = c[i - 1][j - 1] + 1;  // Increment the length from the diagonal
                b[i][j] = DIAG;  // Set direction to diagonal
            } else {
                // Characters don't match, pick the max value from up or left
                if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];  // Take value from the top
                    b[i][j] = UP;  // Set direction to up
                } else {
                    c[i][j] = c[i][j - 1];  // Take value from the left
                    b[i][j] = LEFT;  // Set direction to left
                }
            }
        }
    }

    return c[m][n];  // Return the length of the LCS
}

// Function to print the LCS (using backtracking from the matrices)
void lcsPrint(char *strX, int **b, int **c, int i, int j) {
    if (i != 0 && j != 0) {  // If we haven't reached the start of the strings
        if (b[i][j] == DIAG) {  // If the direction is diagonal, print the character
            lcsPrint(strX, b, c, i - 1, j - 1);  // Recursively move diagonally
            printf("%c", strX[i - 1]);  // Print the character from strX
        } else {
            if (b[i][j] == UP) {
                lcsPrint(strX, b, c, i - 1, j);  // Move up in the matrix
            } else {
                lcsPrint(strX, b, c, i, j - 1);  // Move left in the matrix
            }
        }
    }
}


// Functions Overview and Explanation:

// 1. **`2D_malloc()` function:**
//    - **Purpose:** This function dynamically allocates memory for a 2D array of integers.
//    - **How it works:** It first allocates memory for the rows (an array of pointers) and then, for each row, allocates memory for the columns (the elements of that row). The function checks if the memory allocation is successful, and if not, it reports an error and exits the program.
//    - **Why it's used:** We need to store and manipulate a 2D structure (a matrix) to track the lengths of subsequences and directions in the LCS computation, and this function provides a clean and safe way to handle dynamic memory allocation for the matrix.


// 2. **`2D_dispose()` function:**
//    - **Purpose:** This function frees the dynamically allocated memory for a 2D array.
//    - **How it works:** It iterates through each row of the 2D array and frees the memory allocated for that row, then it frees the array of row pointers itself. Finally, it sets the pointer to NULL to prevent accidental use of deallocated memory.
//    - **Why it's used:** Proper memory management is crucial in programs that deal with dynamic memory allocation. This function ensures that the memory used by the 2D arrays is properly released once it is no longer needed, preventing memory leaks and dangling pointers.


// 3. **`lcsLength()` function:**
//    - **Purpose:** This function calculates the length of the Longest Common Subsequence (LCS) between two input strings using dynamic programming.
//    - **How it works:** It initializes two matrices: `b` for storing the direction of the backtracking process, and `c` for storing the LCS lengths at each step. It then iterates over each character of both input strings and fills the matrices according to the following rules:
//        - If the characters match, the LCS length is incremented from the diagonal cell (i.e., the previous common subsequence length).
//        - If the characters don't match, it takes the maximum value from either the cell above (up) or the cell to the left (left), ensuring that the LCS is as long as possible.
//    - **Why it's used:** This function implements the core logic for solving the LCS problem using dynamic programming, which provides an efficient way to compute the LCS length in polynomial time.


// 4. **`lcsPrint()` function:**
//    - **Purpose:** This function prints the actual Longest Common Subsequence by backtracking through the direction matrix `b`.
//    - **How it works:** Starting from the bottom-right of the matrix, it recursively follows the directions stored in `b` (DIAG, UP, or LEFT) to print the characters of the LCS. When the direction is diagonal (DIAG), it prints the character and moves diagonally, indicating a match. If the direction is UP or LEFT, it simply moves up or left in the matrix, skipping characters that are not part of the LCS.
//    - **Why it's used:** After calculating the LCS length, this function reconstructs and prints the actual subsequence by traversing the direction matrix, effectively providing the solution to the problem.

