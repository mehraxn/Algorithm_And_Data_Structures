# Maximum Path Sum in a Matrix (C Program)

## Overview
This program finds the **maximum path sum** from a starting cell to a target cell in a fixed-size 3x3 matrix. It performs a depth-first search (DFS) traversal of the matrix, avoiding revisits to the same cell in a single path.

## Features
- Matrix of fixed size (3x3).
- Finds the **maximum path sum** from a given start to end position.
- Avoids revisiting cells.
- Considers four directions: up, down, left, right.

## Files
- `main.c` - Contains the full implementation of the program.

## How It Works
- The matrix is represented as a 2D array.
- A DFS-based recursive function `findMaxPathSum` explores all paths from start to end, while tracking visited cells.
- The function accumulates the path sum and backtracks after exploring each direction.
- The maximum path sum is returned.

## Constants
```c
#define ROWS 3
#define COLS 3
#define TRUE 1
#define FALSE 0
#define MIN_VALUE -2147483648
```

## Key Functions
### `isValid(row, col)`
Checks whether a cell is within matrix bounds.

### `findMaxPathSum(matrix, row, col, visited, currentSum, targetRow, targetCol)`
Performs DFS to calculate maximum path sum.

### `findMaxPath(matrix, startRow, startCol, targetRow, targetCol)`
Initializes the visited matrix and starts the DFS process.

## Example
Matrix:
```
1 2 3
4 5 6
7 8 9
```
Start: (0, 0)
Target: (2, 2)

**Output:**
```
Maximum path sum: 29
```

## Compilation and Execution
To compile and run the program:
```bash
gcc main.c -o max_path
./max_path
```

## Notes
- The matrix size is hardcoded. To support variable sizes, you'll need to update constants and possibly use dynamic memory.
- The algorithm explores all possible paths, making it inefficient for large matrices.

## Author
Generated with the help of ChatGPT

