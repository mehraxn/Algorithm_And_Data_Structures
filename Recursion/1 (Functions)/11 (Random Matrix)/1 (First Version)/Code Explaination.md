# findSumRecursive Function Documentation

## Overview
The `findSumRecursive` function checks if there exist three numbers in a given 2D matrix whose sum equals a specified target. It achieves this using recursion to explore all possible combinations of three numbers.

This README provides a comprehensive, line-by-line explanation of the function and the associated program.

---

## Code Explanation

### Includes and Definitions

```c
#include <stdio.h>

#define ROWS 3
#define COLS 3
```
- **`#include <stdio.h>`**: Includes the standard input-output library to use functions like `printf`.
- **`#define ROWS 3` and `#define COLS 3`**: Defines the dimensions of the 2D matrix as 3x3. These constants make the code adaptable to matrices of this size.

---

### Function Declaration

```c
int findSumRecursive(int matrix[ROWS][COLS], int r, int c, int count, int sum, int target);
```
- **`matrix[ROWS][COLS]`**: The 2D matrix being processed.
- **`r`**: Current row index.
- **`c`**: Current column index.
- **`count`**: Number of elements chosen so far.
- **`sum`**: The cumulative sum of chosen elements.
- **`target`**: The target sum to check against.

This function returns `1` if there exist three numbers in the matrix whose sum equals `target`. Otherwise, it returns `0`.

---

### Base Cases

```c
if (count == 3) {
    return sum == target ? 1 : 0;
}
```
- **`count == 3`**: If three numbers have been selected:
  - **`sum == target`**: Checks if their sum equals the target. If true, return `1`.
  - Otherwise, return `0`.

```c
if (r >= ROWS) {
    return 0;
}
```
- **`r >= ROWS`**: If the row index exceeds the matrix bounds, all elements have been explored. Return `0`.

---

### Handling Column Overflow

```c
if (c >= COLS) {
    return findSumRecursive(matrix, r + 1, 0, count, sum, target);
}
```
- **`c >= COLS`**: If the column index exceeds the bounds of the current row, move to the next row by incrementing `r` and resetting `c` to `0`.
- Recursively call `findSumRecursive` with updated indices.

---

### Recursive Calls

#### Including the Current Element

```c
if (findSumRecursive(matrix, r, c + 1, count + 1, sum + matrix[r][c], target)) {
    return 1;
}
```
- **`count + 1`**: Increment the count of selected numbers.
- **`sum + matrix[r][c]`**: Add the current element to the sum.
- **`c + 1`**: Move to the next column.
- If this recursive call returns `1`, it means a valid combination has been found, so return `1` immediately.

#### Excluding the Current Element

```c
return findSumRecursive(matrix, r, c + 1, count, sum, target);
```
- Skip the current element by leaving `count` and `sum` unchanged.
- Move to the next column with `c + 1`.

---

### Main Function

```c
int main() {
    int matrix[ROWS][COLS] = {
        {4, 6, 3},
        {7, 1, 2},
        {8, 9, 5}
    };

    int target = 17;

    if (findSumRecursive(matrix, 0, 0, 0, 0, target)) {
        printf("Yes, there exist three numbers in the matrix whose sum is %d.\n", target);
    } else {
        printf("No, there do not exist three numbers in the matrix whose sum is %d.\n", target);
    }

    return 0;
}
```

#### Input
- **`matrix`**: A static 3x3 matrix with predefined integers.
- **`target`**: The target sum, set to 17 in this example.

#### Output
- If three numbers exist in the matrix whose sum equals the target, print:
  > "Yes, there exist three numbers in the matrix whose sum is 17."
- Otherwise, print:
  > "No, there do not exist three numbers in the matrix whose sum is 17."

---

### Example Walkthrough
#### Matrix:
```
4  6  3
7  1  2
8  9  5
```
#### Target: 17

1. Start at `(0, 0)` (value = 4), include it in the sum.
2. Move to `(0, 1)` (value = 6), include it in the sum.
3. Move to `(0, 2)` (value = 3), include it in the sum.
   - Total: `4 + 6 + 3 = 13`. Not equal to `17`.
4. Backtrack and explore other combinations, e.g., `(0, 0)`, `(0, 1)`, `(1, 0)`, etc.
5. Eventually, the combination `(0, 0)`, `(1, 1)`, `(2, 2)` yields `4 + 1 + 12 = 17`.

---

## Key Features
- **Recursive Exploration**: Explores all combinations of three elements.
- **Matrix Navigation**: Handles row and column boundaries gracefully.
- **Efficient Backtracking**: Stops exploring a branch as soon as a valid combination is found.

---

## Complexity Analysis

- **Time Complexity**: `O(nCr)` where `n` is the number of elements in the matrix and `r` is 3 (since we are choosing 3 elements).
  - For a 3x3 matrix, there are `9C3 = 84` combinations to check.
- **Space Complexity**: `O(ROWS * COLS)` due to recursive function calls and stack usage.

---

## Customization
- To modify the size of the matrix, change the `ROWS` and `COLS` macros.
- To change the target sum, update the `target` variable in the `main` function.

---

## Conclusion
The `findSumRecursive` function provides a clear and recursive method to check for a specific sum in a matrix, demonstrating efficient backtracking and recursion.

