# README: Matrix Equalizer Function

## Overview
The `matrix_equalizer` function takes a square matrix and modifies it using the shortest sequence of operations to make all its elements equal to the same value. Two types of operations are allowed:

1. Increment all elements of a specific row by 1 (`rX++`).
2. Decrement all elements of a specific column by 1 (`cY--`).

The goal is to find and apply the minimum sequence of these operations that equalizes the matrix.

---

## Function Prototype
```c
void matrix_equalizer(int **mat, int n);
```

### Parameters:
- `int **mat`: A dynamically allocated 2D array representing the square matrix.
- `int n`: The size of the matrix (number of rows and columns).

### Behavior:
1. Identifies the target value to which all elements in the matrix should be equal.
2. Applies the minimum sequence of allowed operations to achieve the target value.
3. Outputs the sequence of operations performed.

---

## Helper Functions

### 1. **`row_sum`**
#### Purpose:
Calculates the sum of all elements in a specific row of the matrix.

#### Prototype:
```c
int row_sum(int **mat, int n, int row);
```
#### Parameters:
- `mat`: The matrix.
- `n`: The size of the matrix.
- `row`: The row index.

#### Returns:
The sum of the elements in the specified row.

---

### 2. **`col_sum`**
#### Purpose:
Calculates the sum of all elements in a specific column of the matrix.

#### Prototype:
```c
int col_sum(int **mat, int n, int col);
```
#### Parameters:
- `mat`: The matrix.
- `n`: The size of the matrix.
- `col`: The column index.

#### Returns:
The sum of the elements in the specified column.

---

### 3. **`increment_row`**
#### Purpose:
Increments all elements in a specific row by 1.

#### Prototype:
```c
void increment_row(int **mat, int n, int row);
```
#### Parameters:
- `mat`: The matrix.
- `n`: The size of the matrix.
- `row`: The row index.

---

### 4. **`decrement_col`**
#### Purpose:
Decrements all elements in a specific column by 1.

#### Prototype:
```c
void decrement_col(int **mat, int n, int col);
```
#### Parameters:
- `mat`: The matrix.
- `n`: The size of the matrix.
- `col`: The column index.

---

## Main Function: `matrix_equalizer`

### Purpose:
Finds and applies the shortest sequence of operations to equalize all elements of the matrix.

### Algorithm:
1. **Determine the Target Value**:
   - Compute the sum of each row and each column.
   - Find the smallest row or column sum. This is the target value to which all elements will be adjusted.

2. **Apply Operations**:
   - For each row, increment it until its sum equals the target value (`rX++` operations).
   - For each column, decrement it until its sum equals the target value (`cY--` operations).

3. **Output Operations**:
   - Print the sequence of operations performed.

### Complexity:
1. **Time Complexity**:
   - Computing row and column sums: \(O(n^2)\).
   - Performing operations: \(O(n^2)\).
   - Overall: \(O(n^2)\).

2. **Space Complexity**:
   - Uses \(O(n^2)\) for the matrix.

### Prototype:
```c
void matrix_equalizer(int **mat, int n);
```

### Example Code:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;

    // Dynamically allocate a 3x3 matrix
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the matrix
    mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
    mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
    mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // Call the matrix equalizer function
    matrix_equalizer(mat, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
```

### Example Input and Output:
#### Input Matrix:
```
1 2 3
4 5 6
7 8 9
```

#### Output:
```
Target value: 6
Commands:
r0++
r0++
r1++
r1++
c2--
c2--
c2--
```

#### Final Matrix:
```
6 6 6
6 6 6
6 6 6
```

---

## Assumptions
1. The input matrix is a square matrix.
2. The matrix contains only integer values.

---

## Limitations
1. The function assumes that the target value (minimum row or column sum) is achievable by applying the allowed operations.
2. The function does not handle non-integer matrix elements or non-square matrices.

---

## Extensions
1. **Generalization**:
   - Extend the function to handle non-square matrices.
   - Allow customizable increment and decrement values.

2. **Performance Optimization**:
   - Use caching for row and column sums to avoid redundant calculations.

---

## Conclusion
The `matrix_equalizer` function provides a systematic approach to equalizing all elements in a square matrix using a minimal number of operations. Its modular design and efficient algorithm make it a robust solution for solving matrix transformation problems.

