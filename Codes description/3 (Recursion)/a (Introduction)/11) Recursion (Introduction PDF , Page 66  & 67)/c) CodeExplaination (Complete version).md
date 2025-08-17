#Matrix Determinant Calculation Program

## Overview
This program calculates the determinant of a given `n x n` matrix using recursion and the cofactor expansion method. It is implemented in C and uses helper functions to compute determinants for smaller matrices (minors). The program includes the following main components:
1. **`det` Function**: A recursive function to calculate the determinant of an `n x n` matrix.
2. **`det2x2` Function**: A function to directly compute the determinant of a `2x2` matrix.
3. **`minor` Function**: A function to create a minor matrix by excluding a specified row and column.
4. **`main` Function**: A function to demonstrate the determinant calculation with a sample `3x3` matrix.

## Function Descriptions

### 1. `det` Function
The `det` function is the core of the determinant calculation. It computes the determinant of an `n x n` matrix recursively using cofactor expansion.
- **Input Parameters**: Takes an `n x n` matrix (`m`) and its size (`n`) as inputs.
- **Base Case**: If the matrix size is `2x2`, the function calls the `det2x2` function to compute the determinant directly.
- **Recursive Expansion**: For larger matrices, the function iteratively expands along the first row, creating minor matrices by excluding one row and one column at a time, and recursively calculates their determinants. The cofactors are used to find the overall determinant.

This function provides an elegant way to break down a complex matrix into smaller subproblems until the base case is reached.

### 2. `det2x2` Function
The `det2x2` function calculates the determinant of a `2x2` matrix using the formula:
```
|a  b|
|c  d|
```
The determinant is computed as `(a * d - b * c)`.
- **Input Parameters**: Takes a `2x2` matrix (`m`) as input.
- **Output**: Returns the computed determinant.

This function serves as the base case for the recursive determinant calculation.

### 3. `minor` Function
The `minor` function creates a minor matrix by excluding a specified row and column from the original matrix. This minor matrix is used for the recursive determinant calculation in the `det` function.
- **Input Parameters**: Takes the original matrix (`m`), row (`i`) and column (`j`) to be excluded, size (`n`), and the resulting minor matrix (`m2`).
- **Output**: Populates the minor matrix (`m2`) by excluding the specified row and column.

The minor matrix is crucial for implementing the cofactor expansion method of calculating determinants.

### 4. `main` Function
The `main` function demonstrates how to use the `det` function:
- **Matrix Initialization**: Initializes a `3x3` matrix with predefined values.
- **Determinant Calculation**: Calls the `det` function to calculate the determinant of the matrix.
- **Output**: Prints the result of the determinant calculation to the console.

The `main` function provides a clear example of how to use the determinant calculation functions to solve real problems involving matrices.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc determinant_minor_functions.c -o determinant_minor
./determinant_minor
```

### Expected Output
The program will initialize a sample `3x3` matrix and calculate its determinant:

```
The determinant of the matrix is: -18
```

## Summary
The matrix determinant calculation program is a straightforward demonstration of how recursion can be used to solve problems involving matrices. The **`det`** function implements the cofactor expansion method, which is a fundamental approach for calculating determinants by breaking down larger matrices into smaller components until the base case (`2x2` matrix) is reached.

The **`det2x2`** function serves as the base case for calculating the determinant of small matrices, while the **`minor`** function helps create submatrices necessary for the recursive process.

The **`main`** function demonstrates the usage of these functions, providing a practical example of determinant calculation. This program is an excellent educational tool for understanding recursion, matrix operations, and the cofactor expansion method for finding determinants.