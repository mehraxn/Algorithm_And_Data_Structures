# Matrix Path Finding Task

### Problem Statement

A map is represented as a matrix of integer values. The starting cell of the map is always at the top-left corner (element `[0, 0]`), while the ending cell is always at the bottom-right corner (element `[r-1, c-1]`, where `r` and `c` are the numbers of rows and columns of the matrix, respectively). It is possible to walk (i.e., visit) the map by moving from one cell to any adjacent element (at most 8 directions), but each cell must be visited only once.

Write the recursive C function `matVisit` that is able to find a path from the starting point to the ending point whose sum of the content of the visited cells is maximum. The function receives four parameters: the matrix `mat`, its number of rows `r`, its number of columns `c`, and a flag `f`:

```c
void mat_visit(int **mat, int r, int c, int f);
```

If there are multiple paths with the same (maximum) sum, the function must display the shortest path if `f = 0` and the longest one if `f = 1`. The desired path must be displayed with a format similar to the following example.

### Example

The following figure illustrates a matrix `mat`, with `r = 2` and `c = 2` (left-hand side), and the corresponding solution (right-hand side):

- The indicated path should be reported with a format similar to the following one:

  ```
  [0,0]1 - [0,1]2 - [1,2]7 - [2,2]4 - sum = 24
  ```

### Requirements

- Write the entire program using standard C libraries but implement all required personal libraries.
- Modularize the program adequately.
- Report a brief description of the data structure and the adopted logic in plain English.
- Unclear or overly complex solutions may be penalized in terms of final evaluation.

### Additional Notes

- The function must consider all possible paths from the starting cell to the ending cell.
- The path with the maximum sum should be displayed, and its format should be clear and readable as per the example.
- If `f = 0`, the shortest path among those with the maximum sum should be chosen. If `f = 1`, the longest path should be chosen.

