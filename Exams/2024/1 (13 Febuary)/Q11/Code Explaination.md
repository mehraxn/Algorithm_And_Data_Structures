# README: Matrix Diagonal Averaging Program

## Overview
This program computes the average of all elements along the primary and secondary diagonals of an input matrix `matI` for each element in the matrix. The results are stored in a corresponding output matrix `matO`. The program illustrates matrix traversal, handling edge cases, and modular programming in C.

## Problem Statement
Given:
- An input matrix `matI` of size `R x C`.
- An output matrix `matO` of the same size.

The task is to compute for each element `[r][c]` in `matO` the average of:
1. The element itself.
2. All elements along the diagonals passing through `[r][c]` in `matI`.

The diagonals include:
- **Primary diagonal:** Top-left to bottom-right.
- **Secondary diagonal:** Top-right to bottom-left.

## Functionalities

### Main Function (`main`)
1. **Input Initialization:**
   - Defines a 3x5 input matrix `matI` with integers.
   - Declares an output matrix `matO` of type `float`.

2. **Function Call:**
   - Calls the `avg` function to compute the diagonal averages for all elements in `matI`.

3. **Output Display:**
   - Iterates through `matO` and prints each element rounded to two decimal places.

### `avg`
The `avg` function performs the diagonal averaging operation.

#### Parameters:
- `int matI[R][C]`: Input matrix of size `R x C`.
- `float matO[R][C]`: Output matrix of the same size to store computed averages.

#### Process:
1. **Traversal:**
   - Iterates over each element `[i][j]` in `matI`.

2. **Diagonal Traversal:**
   - For each element, accumulates values from all diagonal elements and counts them.
   - Includes the following diagonal directions:
     - Bottom-right.
     - Bottom-left.
     - Top-left.
     - Top-right.
   - Adds the center element itself (`matI[i][j]`) to the sum.

3. **Average Computation:**
   - Computes the average as `sum / count` and stores it in `matO[i][j]`.

### Example Execution

#### Input:
```
matI = {
    {2, 3, 4, 5, 0},
    {4, 1, 7, 3, 3},
    {2, 9, 8, 1, 0}
}
```

#### Output:
```
matO = {
    {2.00, 3.25, 3.80, 3.33, 1.67},
    {3.25, 4.44, 4.86, 3.40, 1.67},
    {3.00, 4.00, 4.33, 3.33, 1.00}
}
```

### Explanation for `[1][1]` (element `1`):
- Diagonal elements: `9 (bottom-right), 4 (top-left), 7 (top-right), 4 (bottom-left)`.
- Center element: `1`.
- Sum = `1 + 9 + 4 + 7 + 4 = 25`.
- Count = `5`.
- Average = `25 / 5 = 5.00`.

## Data Structures
- **Input Matrix (`matI`):** Stores integers.
- **Output Matrix (`matO`):** Stores computed averages as floats.

## Key Logic
- Uses four nested loops to traverse diagonals in all directions.
- Handles edge cases (matrix boundaries) by checking conditions during traversal.
- Includes the center element in the sum.

## Memory Management
- No dynamic memory allocation is used; static arrays ensure efficient use of stack memory.

## Limitations
1. The program is hardcoded for `R` and `C` values; changes to matrix dimensions require recompilation.
2. Assumes valid input matrix dimensions and values.

## Compilation and Execution
1. Save the program as `matrix_avg.c`.
2. Compile using:
   ```bash
   gcc -o matrix_avg matrix_avg.c
   ```
3. Run the executable:
   ```bash
   ./matrix_avg
   ```

## Conclusion
This program demonstrates how to compute diagonal averages for matrix elements effectively. It emphasizes handling matrix traversal, boundary conditions, and modular programming in C.

