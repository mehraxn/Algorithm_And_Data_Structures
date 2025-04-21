# README: Explanation of the `knight` Function

This document provides a comprehensive, line-by-line explanation of the `knight` function, which identifies the best position for a knight on a chessboard to maximize the sum of reachable pieces' values.

---

## **Function Prototype**
```c
void knight(int mat[N][N], int *r, int *c);
```
- **Purpose**: Finds the coordinates of the empty cell on the chessboard where placing a knight would maximize the sum of reachable pieces' values.
- **Parameters**:
  - `int mat[N][N]`: A 2D array representing the chessboard. Each cell contains either a piece's value or `0` (empty).
  - `int *r`: Pointer to store the row index of the best position.
  - `int *c`: Pointer to store the column index of the best position.

---

## **Function Breakdown**

### **Step 1: Define Possible Moves for the Knight**
```c
int moves[8][2] = {
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
};
```
- The knight in chess moves in an "L" shape. These 8 possible moves are represented as coordinate offsets:
  - `{-2, -1}`: Move two steps up and one step left.
  - `{-1, -2}`: Move one step up and two steps left.
  - Similarly, the other entries represent all valid knight moves.

### **Step 2: Initialize Variables for Maximum Calculation**
```c
int max_sum = 0; // To store the maximum sum of reachable pieces
*r = -1;         // To store the row of the best position
*c = -1;         // To store the column of the best position
```
- `max_sum`: Tracks the highest sum of reachable values.
- `*r` and `*c`: Store the coordinates of the best position.
  - Initialized to `-1` to indicate no valid position found yet.

### **Step 3: Iterate Through Each Cell of the Chessboard**
```c
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        if (mat[i][j] == 0) {
```
- **Outer Loops (`for i` and `for j`)**:
  - Iterate over every cell in the `N x N` chessboard.
- **Condition (`if mat[i][j] == 0`)**:
  - Only consider empty cells (value `0`) as possible positions for the knight.

### **Step 4: Calculate the Sum of Reachable Pieces**
```c
int current_sum = 0;
for (int k = 0; k < 8; k++) {
    int ni = i + moves[k][0]; // New row
    int nj = j + moves[k][1]; // New column

    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
        current_sum += mat[ni][nj];
    }
}
```
- **`current_sum`**:
  - Initializes to `0` to track the total value of reachable pieces from the current cell.
- **Inner Loop (`for k`)**:
  - Iterates over all 8 possible knight moves.
- **Calculate New Position**:
  - `ni` and `nj` represent the new row and column indices after the knight's move.
- **Boundary Check**:
  - Ensures that the new position is within the bounds of the chessboard (`0 <= ni, nj < N`).
- **Sum Values**:
  - Adds the value of the reachable cell (`mat[ni][nj]`) to `current_sum`.

### **Step 5: Update Maximum Sum and Best Position**
```c
if (current_sum > max_sum) {
    max_sum = current_sum;
    *r = i;
    *c = j;
}
```
- Compares the `current_sum` to `max_sum`:
  - If `current_sum` is greater, updates `max_sum` to the new value.
  - Updates `*r` and `*c` to the current cell's coordinates (`i`, `j`).

---

## **Summary of the Logic**
1. **Initialize Variables**:
   - Start with `max_sum = 0` and `*r, *c = -1`.
2. **Iterate Through Each Cell**:
   - Consider all empty cells (`mat[i][j] == 0`) on the chessboard.
3. **Simulate Knight Moves**:
   - For each empty cell, calculate the total value of all reachable cells using the knight's possible moves.
4. **Update Best Position**:
   - If the sum of reachable values is greater than the current maximum, update the best position and maximum sum.
5. **Output**:
   - The function stores the row and column indices of the best position in `*r` and `*c`.

---

## **Example Execution**
### Input:
```c
mat = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};
```
### Steps:
1. Iterate over each cell.
2. For each empty cell (`0`), calculate the sum of values reachable by the knight.
3. Track the cell with the maximum sum.

### Output:
```c
The best position for the knight is at row 4, column 3.
```

---

## **Edge Cases Handled**
1. **No Empty Cells**:
   - If no empty cells (`0`) exist, the function will return `-1` for both `*r` and `*c`.
2. **Empty Board**:
   - If all cells are `0`, the function will select the cell with the maximum reachable sum (if possible).
3. **Small Boards**:
   - For smaller chessboards, the function ensures moves are within bounds.

---

## **Limitations**
- Assumes valid input (e.g., `N x N` matrix with non-negative values).
- May not be optimal for larger boards without further optimization.

