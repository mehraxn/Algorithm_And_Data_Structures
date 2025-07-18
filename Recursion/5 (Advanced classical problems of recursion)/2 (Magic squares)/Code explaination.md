# Magic Square Implementation: Line-by-Line Analysis

This article provides a comprehensive line-by-line explanation of the magic square implementation code, identifying the algorithmic techniques used in each part.

## Header Inclusions and Function Prototypes

```c
#include <stdio.h>
#include <stdlib.h>
```
These lines include standard C libraries:
- `stdio.h`: Provides input/output functionality like `fprintf`
- `stdlib.h`: Provides memory allocation functions (`malloc`, `free`) and utility functions (`atoi`, `exit`)

```c
/* function prototypes */
int square_r(int **matrix, int dim, int *used, int k);
int check(int **matrix, int dim);
```
These function prototypes declare two functions:
- `square_r`: The recursive function implementing backtracking and DFS to fill the magic square
- `check`: A validation function that determines if a completed square is "magic"

## Main Function

```c
int main(int argc, char *argv[]) {
```
The main function receives command-line arguments: 
- `argc`: Argument count
- `argv`: Array of argument strings

```c
    int **matrix, *used, i, j, n;
```
Declares variables:
- `matrix`: 2D array to hold the magic square values
- `used`: Array to track which numbers have been used (part of the backtracking algorithm)
- `i`, `j`: Loop counters
- `n`: Dimension of the magic square

```c
    n = atoi(argv[1]);
```
Converts the first command-line argument to an integer, representing the dimension of the magic square.

```c
    used = (int *)malloc((n * n + 1) * sizeof(int));
```
Allocates memory for the `used` array. It needs to track numbers from 1 to n², so its size is n²+1 (index 0 is not used).

```c
    matrix = (int **)malloc(n * sizeof(int *));
```
Allocates memory for an array of n pointers, each will point to a row of the matrix.

```c
    if (used == NULL || matrix == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
```
Error handling: checks if memory allocation failed and exits if it did.

```c
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
```
Allocates memory for each row of the matrix and checks for allocation failures.

```c
        used[i] = 0;
    }
```
Initializes the first n elements of the `used` array to 0, indicating no numbers have been used yet. This is part of the backtracking algorithm's state tracking.

```c
    if (square_r(matrix, n, used, 0)) {
```
Calls the recursive function to fill the magic square. The initial position is 0 (which will be converted to row 0, column 0). If the function returns 1, a magic square was found.

```c
        fprintf(stdout, "Magic square of size %d:\n", n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                fprintf(stdout, "%2d ", matrix[i][j]);
            }
            fprintf(stdout, "\n");
        }
```
If a magic square was found, prints it to the standard output with proper formatting.

```c
    } else {
        fprintf(stdout, "Magic square NOT found!\n");
    }
```
If no magic square was found, prints a message indicating failure.

```c
    free(used);
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
```
Frees all allocated memory to prevent memory leaks.

```c
    return EXIT_SUCCESS;
}
```
Returns a success status code, indicating the program completed without errors.

## Square_r Function

```c
int square_r(int **matrix, int dim, int *used, int k) {
```
This is the core recursive function implementing backtracking and DFS:
- `matrix`: The 2D array being filled
- `dim`: Dimension of the square
- `used`: Array tracking which numbers have been used
- `k`: Current position in the square (will be converted to row and column)

```c
    int i, j, val;
```
Local variables:
- `i`, `j`: Row and column indices
- `val`: The current value being tried at position (i, j)

```c
    if (k == dim * dim) {
        return check(matrix, dim);
    }
```
Base case of the recursion: If k equals dim², all positions have been filled.
- This is where the DFS algorithm reaches its deepest point
- Calls `check` to determine if the completed square is magic
- Returns the result of `check` (1 for success, 0 for failure)

```c
    i = k / dim;
    j = k % dim;
```
Converts the 1D position `k` to 2D coordinates (i, j):
- `i` (row) is k divided by the dimension
- `j` (column) is k modulo the dimension
This implements a row-major traversal of the matrix.

```c
    for (val = 1; val <= dim * dim; val++) {
```
This loop is the brute force aspect of the algorithm:
- Tries each possible value from 1 to dim² at the current position
- Combined with backtracking, this systematically explores all possibilities

```c
        if (used[val] == 0) {
```
Checks if the current value has not been used yet, which is part of the backtracking state tracking.

```c
            /* put a new value and recur */
            matrix[i][j] = val;
            used[val] = 1;
```
- Places the value in the matrix
- Marks the value as used (part of backtracking)
- These two lines represent a "forward step" in the backtracking algorithm

```c
            if (square_r(matrix, dim, used, k + 1)) {
                /* solution found: stop the process */
                return 1;
            }
```
- Recursively calls `square_r` to fill the next position (k+1)
- This is the core of the DFS algorithm, exploring deeper before trying alternatives
- If the recursive call returns 1, a solution was found, so return 1 to propagate success upward

```c
            /* backtrack */
            used[val] = 0;
```
The backtracking step:
- If the recursive call didn't find a solution, undo the current choice
- Mark `val` as unused again
- This allows trying a different value at the current position

```c
        }
    }
```
End of the loop and the conditional.

```c
    /* solution not found */
    return 0;
}
```
If all values have been tried at this position without success, return 0 to indicate failure.
This triggers backtracking in the caller.

## Check Function

```c
int check(int **matrix, int dim) {
```
Function to verify if a square is magic:
- `matrix`: The completed square to check
- `dim`: Dimension of the square

```c
    int i, j, sum, target;
```
Local variables:
- `i`, `j`: Loop counters
- `sum`: To hold the sum of a row, column, or diagonal
- `target`: The magic constant that all sums must equal

```c
    target = dim * (dim * dim + 1) / 2;
```
Calculates the magic constant using the formula n(n²+1)/2.

```c
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
```
Checks if each row sums to the magic constant:
- Iterates through each row
- Calculates the sum of values in the row
- If any row sum doesn't equal the target, returns 0 (failure)

```c
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
```
Checks if each column sums to the magic constant:
- Iterates through each column
- Calculates the sum of values in the column
- If any column sum doesn't equal the target, returns 0 (failure)

```c
    /* diagonals */
    sum = 0;
    for (i = 0; i < dim; i++) {
        sum += matrix[i][i];
    }
    if (sum != target) {
        return 0;
    }
```
Checks the main diagonal (top-left to bottom-right):
- Calculates the sum of elements where row index equals column index
- Returns 0 if the sum doesn't equal the target

```c
    sum = 0;
    for (i = 0; i < dim; i++) {
        sum += matrix[i][dim - 1 - i];
    }
    if (sum != target) {
        return 0;
    }
```
Checks the other diagonal (top-right to bottom-left):
- Calculates the sum of elements where row index plus column index equals dim-1
- Returns 0 if the sum doesn't equal the target

```c
    return 1;
}
```
If all checks pass, returns 1 indicating that the square is indeed a magic square.

## Algorithmic Analysis Summary

1. **Main Function**:
   - Uses dynamic memory allocation to set up data structures
   - Initiates the recursive backtracking/DFS process
   - Handles output and cleanup

2. **square_r Function**:
   - Implements backtracking by trying values and undoing them if they don't lead to a solution
   - Uses DFS to explore each partial solution deeply before trying alternatives
   - Uses brute force by systematically trying all possible values

3. **check Function**:
   - Implements validation logic for the magic square property
   - Uses simple iteration and summation algorithms to verify row, column, and diagonal sums

The combination of these algorithms creates an effective solution for finding magic squares, though the exponential complexity means it's only practical for small dimensions.