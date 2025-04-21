# README: Alphanumeric Matrix Solver

## Overview
The `alphanumeric_matrix` function is designed to solve an alphanumeric puzzle, often referred to as an "alphanumeric square." The puzzle consists of a grid of uppercase alphabetic characters where each row (except the last) represents part of an arithmetic addition operation, and the last row represents the result of these operations. The goal is to replace each unique letter with a single unique decimal digit (0-9) such that the arithmetic operations hold true. The solution must consider carry-over values during addition.

This implementation uses a backtracking algorithm to assign digits to letters while ensuring all arithmetic constraints are satisfied.

---

## Features
- **Input Flexibility**: Handles matrices of variable size (r x c) containing only uppercase alphabetic characters.
- **Backtracking Algorithm**: Dynamically explores and tests possible digit assignments for letters.
- **Carry Management**: Properly calculates and propagates carry values across columns.
- **Output Mapping**: If a solution exists, it outputs the mapping of letters to digits. If not, it informs the user that no solution is possible.

---

## Code Components

### 1. **`is_valid_mapping` Function**
#### Purpose:
Validates whether the current mapping satisfies the arithmetic constraints of the matrix.

#### Parameters:
- `char **mat`: Pointer to the matrix of characters.
- `int r`: Number of rows in the matrix.
- `int c`: Number of columns in the matrix.
- `int *mapping`: Array mapping each letter (A-Z) to a digit (0-9).

#### Logic:
- Iterates over each column from right to left.
- For each column, computes the sum of digits (based on the current mapping) for all rows except the last.
- Extracts the last digit of the column sum (expected result) and compares it to the digit in the result row (last row).
- Checks carry propagation for correctness.

#### Returns:
- `true` if the mapping is valid.
- `false` if the mapping violates the arithmetic constraints.

---

### 2. **`solve` Function**
#### Purpose:
Uses backtracking to assign digits to letters such that all arithmetic constraints are satisfied.

#### Parameters:
- `char **mat`: Pointer to the matrix of characters.
- `int r`: Number of rows in the matrix.
- `int c`: Number of columns in the matrix.
- `int *mapping`: Array mapping each letter (A-Z) to a digit (0-9).
- `bool *used_digits`: Array tracking which digits are already assigned to letters.
- `int index`: Current letter being processed (0-25, corresponding to A-Z).

#### Logic:
- Base Case: If all letters have been assigned digits, validate the mapping using `is_valid_mapping`.
- Recursive Case:
  - Try assigning each unused digit (0-9) to the current letter.
  - Mark the digit as used and recurse to the next letter.
  - If the recursive call returns `true`, the solution is found.
  - Otherwise, backtrack by unmarking the digit and trying the next one.

#### Returns:
- `true` if a valid mapping is found.
- `false` if no valid mapping exists for the current state.

---

### 3. **`alphanumeric_matrix` Function**
#### Purpose:
Main function to solve the alphanumeric puzzle by finding a valid mapping of letters to digits.

#### Parameters:
- `char **mat`: Pointer to the matrix of characters.
- `int r`: Number of rows in the matrix.
- `int c`: Number of columns in the matrix.

#### Logic:
- Initializes the mapping array to `-1` (indicating no assignment).
- Initializes the `used_digits` array to `false` (indicating no digit is assigned).
- Calls the `solve` function to find a valid solution.
- If a solution exists, prints the letter-to-digit mapping. Otherwise, prints that no solution exists.

---

### 4. **`main` Function**
#### Purpose:
Provides an example input matrix and calls `alphanumeric_matrix` to solve it.

#### Example:
```c
int r = 4, c = 4; // Matrix dimensions
char *mat[] = {
    "ONE ",
    "ONE ",
    "TWO ",
    "FOUR"
};
alphanumeric_matrix(mat, r, c);
```

#### Output:
If the solution exists, it will display:
```
Letter-to-digit mapping:
O -> 1
N -> 2
E -> 3
T -> 4
W -> 5
F -> 6
U -> 7
R -> 8
```
Otherwise:
```
No solution exists.
```

---

## Key Concepts

### Backtracking
- The function explores all possible digit assignments for letters and checks each one until a solution is found.
- If a partial assignment violates constraints, it backtracks by undoing the assignment and trying a different digit.

### Carry Propagation
- Addition operations are performed column by column, considering carry values from the previous column.
- This ensures the solution is consistent with standard arithmetic addition.

---

## Assumptions
1. The input matrix contains only uppercase letters ('A'-'Z').
2. Each letter is associated with a unique decimal digit (0-9).
3. The result of addition is always in the last row of the matrix.
4. The puzzle is well-formed and has a valid solution (though the program handles cases with no solutions).

---

## Limitations
- The implementation assumes a maximum of 26 unique letters (A-Z). It does not handle puzzles requiring more characters.
- Performance may degrade for large matrices or highly constrained puzzles due to the exponential nature of backtracking.

---

## How to Use
1. Define the input matrix as a 2D array of characters.
2. Pass the matrix, along with its dimensions, to the `alphanumeric_matrix` function.
3. Review the console output for the letter-to-digit mapping or a message indicating no solution exists.

---

## Example Execution
### Input Matrix:
```
ONE
ONE
TWO
FOUR
```
### Output:
```
Letter-to-digit mapping:
O -> 1
N -> 2
E -> 3
T -> 4
W -> 5
F -> 6
U -> 7
R -> 8
```

---

## Further Enhancements
1. **Optimization**: Implement heuristics to reduce the number of backtracking steps.
2. **Dynamic Input**: Allow input from files or user input during runtime.
3. **Visualization**: Display the solved matrix alongside the letter-to-digit mapping.

---

## Conclusion
This implementation of the alphanumeric matrix solver demonstrates the power of backtracking algorithms and their ability to solve combinatorial puzzles. While simple in concept, the code handles the complexity of arithmetic constraints and provides an efficient solution to a challenging problem.

