# The Magic Square Problem

## Definition

In recreational mathematics, a **magic square** is an \( n 	imes n \) square grid (matrix) filled with distinct positive integers in the range 1, 2, …, \( n^2 \), such that each cell contains a different integer and the sum of the integers in each row, column, and diagonal is equal. This constant sum is called the **magic constant** or **magic sum** of the magic square.

For example, in a \( 3 	imes 3 \) magic square, the magic sum is calculated as follows:

\[
\text{Magic sum} = \frac{n (n^2 + 1)}{2}
\]

For a \( 3 	imes 3 \) magic square, the magic sum is \( 15 \). An example of a valid magic square is:

```
2  7  6
9  5  1
4  3  8
```

## Task Description

The task is to write a program that, given a positive integer value \( n \), prints out a magic square of size \( n 	imes n \). The solution should involve constructing the matrix such that the sum of all rows, columns, and diagonals is equal to the magic sum for that size.

## Specifications

1. **Input**: A positive integer \( n \) representing the size of the magic square.
2. **Output**: A \( n 	imes n \) matrix that forms a magic square, or a message indicating that it is not possible to construct a magic square for the given \( n \).
3. **Constraints**: The input should be a positive integer (typically \( n \geq 3 \)).

### Example

If the input value \( n \) is 3, the program should output a magic square similar to:

```
2  7  6
9  5  1
4  3  8
```

The sum of each row, column, and diagonal in this example is \( 15 \), which is the magic sum for \( n = 3 \).

## Approach

The problem can be approached using recursive backtracking or other algorithms specifically designed to generate magic squares. The provided code utilizes a recursive function to fill the grid while ensuring the magic properties are maintained throughout the process. The recursion continues until a solution is found or all possibilities are exhausted.

### Key Points
- **Backtracking** is used to try different numbers in the grid while maintaining the magic property.
- The function ensures no repeated numbers and checks the sum condition for rows, columns, and diagonals.
- If a solution is found, the program prints the magic square; otherwise, it indicates that a solution does not exist.

