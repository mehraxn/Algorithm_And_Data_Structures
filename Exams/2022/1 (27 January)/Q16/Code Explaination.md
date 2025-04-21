# Matrix Path with Maximum Sum

This program computes the path in a matrix that has the maximum sum. It explores all possible paths in the matrix and identifies the one with the maximum sum, either with the shortest or longest path length, depending on the user’s preference. The program uses a recursive backtracking approach to achieve this.

---

## Features
1. **Matrix Initialization**: Dynamically allocates a 2D matrix.
2. **Path Finding**: Computes the path with the maximum sum.
3. **Two Modes**:
   - Shortest path length for ties in maximum sum.
   - Longest path length for ties in maximum sum.
4. **Dynamic Programming Concepts**: Implements backtracking to explore paths and maintain state using a `Cell` structure.

---

## Code Overview

### 1. **Constants and Structs**

- **`MAX_ROWS` and `MAX_COLS`**: Define the maximum matrix size.
- **`Cell` Structure**:
  - **`row`**: Current row index.
  - **`col`**: Current column index.
  - **`sum`**: Sum of values along the path to the cell.
  - **`path_length`**: Number of steps in the path.
  - **`path`**: String representation of the path for easier debugging and visualization.

### 2. **Matrix Initialization**

The matrix is initialized dynamically and populated with sample values:

```c
int input_matrix[3][3] = {
    {1, 2, 3},
    {9, 7, 4},
    {1, 2, 8}
};
```

This creates a 3x3 matrix with predefined values.

### 3. **Main Program Logic**

1. **Matrix Allocation**:
   The program dynamically allocates memory for the matrix to handle variable sizes.
   ```c
   int **matrix = malloc(rows * sizeof(int *));
   for (int i = 0; i < rows; i++) {
       matrix[i] = malloc(cols * sizeof(int));
   }
   ```

2. **Calling Path Finder**:
   The program finds paths with two different criteria:
   - **Shortest path length** for maximum sum.
   - **Longest path length** for maximum sum.

   ```c
   mat_visit(matrix, rows, cols, 0); // Shortest path
   mat_visit(matrix, rows, cols, 1); // Longest path
   ```

3. **Memory Deallocation**:
   After computation, the dynamically allocated memory is freed:
   ```c
   for (int i = 0; i < rows; i++) {
       free(matrix[i]);
   }
   free(matrix);
   ```

### 4. **`mat_visit` Function**

This function initializes the starting conditions and invokes the recursive `find_path` function:

```c
Cell current = {0, 0, mat[0][0], 1, ""};
sprintf(current.path, "[%d,%d]%d", 0, 0, mat[0][0]);
```

- **Parameters**:
  - `mat`: Pointer to the matrix.
  - `r`: Number of rows in the matrix.
  - `c`: Number of columns in the matrix.
  - `f`: Flag to determine criteria:
    - `0` for shortest path length.
    - `1` for longest path length.
- **Purpose**: Tracks the "best" path using the `Cell` structure.

### 5. **`find_path` Function**

This recursive function explores all possible paths in the matrix using backtracking.

#### **Parameters**:
- `mat`: Pointer to the matrix.
- `visited`: A 2D array to mark visited cells.
- `current`: Pointer to the current cell being evaluated.
- `best`: Pointer to the best path found so far.
- `r`, `c`: Dimensions of the matrix.
- `f`: Flag for tie-breaking criteria (shortest or longest path).

#### **Logic**:
1. **Base Case**: If the current cell is the bottom-right corner, update the best path if conditions are met.
   ```c
   if (current->row == r - 1 && current->col == c - 1) {
       if (current->sum > best->sum || ... ) {
           // Update best path
       }
       return;
   }
   ```

2. **Exploration**: Move in 8 possible directions (up, down, left, right, and diagonals) if the next cell is within bounds and not visited.
   ```c
   for (int i = 0; i < 8; i++) {
       int new_row = current->row + directions[i][0];
       int new_col = current->col + directions[i][1];
       if (new_row >= 0 && new_row < r && new_col >= 0 && new_col < c && !visited[new_row][new_col]) {
           find_path(mat, visited, &next, best, r, c, f);
       }
   }
   ```

3. **Backtracking**: Unmark the current cell after exploring all possibilities.
   ```c
   visited[current->row][current->col] = 0;
   ```

#### **Tie-Breaking Logic**:
- For paths with equal sums:
  - Shortest path length if `f == 0`.
  - Longest path length if `f == 1`.

### 6. **Output**

For the example matrix, the program outputs:

- **Shortest Path with Maximum Sum**:
  ```
  [0,0]1 - [1,0]9 - [1,1]7 - [2,2]8 - sum = 25
  ```

- **Longest Path with Maximum Sum**:
  ```
  [0,0]1 - [1,0]9 - [1,1]7 - [2,1]2 - [2,2]8 - sum = 25
  ```

---

## Key Concepts and Challenges

1. **Dynamic Programming vs Backtracking**:
   This program uses backtracking, which is less efficient for large matrices compared to dynamic programming.

2. **Tie-Breaking**:
   Handling ties between paths with the same sum is achieved using a flexible flag (`f`).

3. **Memory Management**:
   Proper allocation and deallocation of memory ensure efficient use of resources.

4. **Edge Cases**:
   - Single cell matrix.
   - All cells with equal values.

---

## Potential Improvements

1. **Optimize for Large Matrices**:
   Use dynamic programming to reduce redundant calculations.

2. **Path Storage**:
   Instead of a string, consider storing paths as arrays for better performance.

3. **Add Input Handling**:
   Allow user-defined matrices instead of hardcoding values.

4. **Diagonal Moves**:
   Provide an option to include/exclude diagonal moves.

---

## How to Run

1. Compile the program using a C compiler:
   ```bash
   gcc -o matrix_path matrix_path.c
   ```

2. Run the executable:
   ```bash
   ./matrix_path
   ```

