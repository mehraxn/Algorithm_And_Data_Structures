# README: Submatrix Analysis Program

## Overview
This program identifies the submatrices of size `k x k` within a given `n x n` matrix that have the smallest and largest sums. It achieves this by iterating through all possible submatrices of the specified size, calculating their sums, and tracking the coordinates of the minimum and maximum sum submatrices.

---

## Features
- **Submatrix Sum Calculation**: Calculates the sum of all elements in a `k x k` submatrix.
- **Min-Max Submatrix Detection**: Identifies the submatrices with the smallest and largest sums.
- **Matrix Display**: Prints the identified submatrices for visualization.
- **Dynamic Memory Management**: Allocates and frees memory dynamically for matrix processing.

---

## Code Structure
### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Initializes a static 6x6 matrix.
  - Dynamically allocates memory for processing the matrix.
  - Copies the static matrix into dynamically allocated memory.
  - Calls the `check` function to analyze the matrix for minimum and maximum submatrices.
  - Frees all allocated memory after processing.

---

#### 2. **check**
```c
void check(int **m, int n, int k);
```
- **Purpose**: Finds the `k x k` submatrices with the smallest and largest sums.
- **Parameters**:
  - `m`: Pointer to the matrix.
  - `n`: Dimension of the square matrix (n x n).
  - `k`: Dimension of the submatrix (k x k).
- **Logic**:
  - Iterates through all possible `k x k` submatrices within the matrix.
  - Calculates the sum of each submatrix.
  - Updates coordinates and sums for the minimum and maximum submatrices.
  - Prints the smallest and largest submatrices using `display_sub`.

---

#### 3. **display_sub**
```c
void display_sub(int **m, int i, int j, int k);
```
- **Purpose**: Displays a `k x k` submatrix starting at a specific position.
- **Parameters**:
  - `m`: Pointer to the matrix.
  - `i`: Starting row index of the submatrix.
  - `j`: Starting column index of the submatrix.
  - `k`: Dimension of the submatrix (k x k).
- **Logic**:
  - Iterates through the rows and columns of the specified submatrix.
  - Prints each element in a formatted manner.

---

## Example Execution

### Input Matrix
The program uses the following static 6x6 matrix:
```
0 1 0 1 0 1
1 0 1 0 1 0
0 1 0 0 0 1
1 0 1 0 1 0
0 1 0 0 0 0
3 0 1 0 2 0
```

### Parameters
- `n = 6`: Size of the square matrix.
- `k = 3`: Size of the submatrix.

### Output
```
min submatrix:
0 1 0
0 1 0
0 0 0

max submatrix:
1 0 2
0 1 0
3 0 1
```

---

## Data Structures
- **Matrix Representation**: The matrix is represented as a dynamically allocated 2D array (`int **m`).
- **Static Input**: The initial matrix is defined as a static array and copied into dynamically allocated memory for processing.

---

## Memory Management
- **Dynamic Allocation**:
  - Allocates memory for a 2D array to hold the matrix values.
  - Each row of the matrix is individually allocated.
- **Deallocation**:
  - Frees each row of the matrix after processing.
  - Ensures no memory leaks.

---

## Limitations
- **Fixed Dimensions**: The program assumes the matrix dimensions (`n`) and submatrix size (`k`) are predefined.
- **No Input Validation**: Assumes the matrix and parameters are always valid.
- **Square Submatrices Only**: Only supports square submatrices of size `k x k`.

---

## Future Improvements
- Add support for user input to define the matrix and submatrix size.
- Extend functionality to handle non-square matrices and submatrices.
- Optimize the algorithm for large matrices to reduce computational overhead.
- Implement error handling for invalid memory allocation or parameters.

---

## How to Compile and Run
1. Save the code in a file (e.g., `submatrix_analysis.c`).
2. Compile the program:
   ```bash
   gcc -o submatrix_analysis submatrix_analysis.c
   ```
3. Run the program:
   ```bash
   ./submatrix_analysis
   ```

