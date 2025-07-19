# README: Detailed Line-by-Line Explanation of the Eight-Queens Solver

This document explains every part of the provided C program for solving the Eight Queens problem. Each line or logical block is annotated with its purpose and rationale.

---

## 1. Header and Includes

```c
#include <stdio.h>
#include <stdlib.h>
```

* **`#include <stdio.h>`**: Imports the Standard I/O library for functions like `fprintf` to print output to `stdout` or `stderr`.
* **`#include <stdlib.h>`**: Imports the Standard Library for functions and definitions like `EXIT_SUCCESS` and memory management (not used here but good practice).

```c
#define N 8
```

* **`#define N 8`**: Sets a macro `N` representing the board size (8×8) and the number of queens. Using a macro makes it easy to change the problem size by editing one line.

---

## 2. Function Prototypes

```c
/* function prototypes */
int place_r(int board[][N], int, int, int);
int check_solution(int board[][N]);
```

* **`place_r`**: Declares the recursive function that attempts to place `N` queens on the board. Parameters:

  * `board[][N]`: 2D array holding the board state.
  * `int`: `r0`, the row index of the last placed queen.
  * `int`: `c0`, the column index of the last placed queen.
  * `int`: `n`, the count of how many queens have been placed so far.
* **`check_solution`**: Declares the function that validates the current board state, ensuring no two queens threaten each other.

Prototyping before `main` allows these functions to be defined later in the file while still being visible to `main`.

---

## 3. `main` Function

```c
int main(void) {
    int i, j;
    int board[N][N];
```

* Declares loop counters `i` and `j`.
* Declares `board` as an `N×N` integer array. Each cell will be `0` (empty) or a positive integer marking the placement order of a queen.

```c
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            board[i][j] = 0;
        }
    }
```

* **Board Initialization**: Sets all cells to `0` to represent an empty board.
* **Why nested loops?**: 2D arrays in C require nested loops to initialize rows and columns.

```c
    if (place_r(board, 0, -1, 0)) {
        fprintf(stdout, "Solution found:\n");
        for (i=0; i<N; i++) {
            for (j=0; j<N; j++) {
                if (board[i][j] != 0) {
                    fprintf(stdout, "Q");
                } else {
                    fprintf(stdout, ".");
                }
            }
            fprintf(stdout, "\n");
        }
    } else {
        fprintf(stdout, "Solution NOT found!\n");
    }
```

* **`place_r(board, 0, -1, 0)`**:

  * Starts recursion with no queens placed (`n=0`).
  * `r0=0`, `c0=-1` are dummy values ensuring the first placement loop begins at `(0,0)`.
* If it returns `1`, a valid arrangement was found:

  * Print `Solution found:`.
  * Loop through `board` to print `Q` for queens and `.` for empty squares, giving a visual representation.
* If it returns `0`, print `Solution NOT found!`.

```c
    return EXIT_SUCCESS;
}
```

* Returns `0` to the operating system, indicating successful execution.

---

## 4. Recursive Placement: `place_r`

```c
int place_r(int board[N][N], int r0, int c0, int n) {
    int r, c;
```

* **Parameters**:

  * `board`: current state of the chessboard.
  * `r0, c0`: last-placed queen coordinates, used to continue searching from the next position.
  * `n`: how many queens have already been placed.
* Local variables `r` and `c` for scanning rows and columns.

```c
    if (n == N) {
        if (check_solution(board) == 1) {
            return 1;
        } else
            return 0;
    }
```

* **Base case**: If `n == N`, all queens have been placed. Invoke `check_solution`:

  * If valid, return `1` (found solution).
  * Otherwise return `0`, triggering backtracking.

```c
    for (r=0; r<N; r++) {
        for (c = ((r==0) ? (c0+1) : 0); c<N; c++) {
```

* **Iterate all board positions** in row-major order, but resume from `(r0,c0+1)` when `r == r0`. This ensures we do not revisit cells already tried in previous recursion levels.

```c
            // Set queen
            board[r][c] = n+1;
```

* Place the next queen by marking the cell with `n+1` (an identifier showing the order of placement). Non-zero distinguishes queens from empty slots.

```c
            if (place_r(board, r, c, n-1) == 1) {
                return 1;
            }
```

* **Recursive call**: Attempt to place the remaining queens, passing current queen's coordinates as the new starting point and incrementing the placed count (`n+1`).
* If it returns `1`, propagate success upward immediately.

```c
            // Remove queen = backtrack
            board[r][c] = 0;
```

* **Backtracking**: If deeper recursion fails, remove the queen to restore the board state before trying the next position.

```c
        }
    }

    return 0;
}
```

* If no position in the entire board leads to a valid solution at this recursion level, return `0`.

---

## 5. Validation: `check_solution`

```c
int check_solution(int board[N][N]) {
    int r, c, d, n;
```

* Local counters:

  * `r, c`: row/column indices.
  * `d`: diagonal index.
  * `n`: count of queens in the current line.

### 5.1 Row Check

```c
    // check rows
    for (r=0; r<N; r++) {
        for (n=0, c=0; c<N; c++) {
            if (board[r][c] != 0) {
                n++;
            }
        }
        if (n>1) {
            return 0;
        }
    }
```

* For each row `r`, count queens. If more than one (`n>1`), they can attack each other horizontally.

### 5.2 Column Check

```c
    // check columns
    for (c=0; c<N; c++) {
        for (n=0, r=0; r<N; r++) {
            if (board[r][c] != 0) {
                n++;
            }
        }
        if (n>1) {
            return 0;
        }
    }
```

* Similar logic for columns.

### 5.3 Main Diagonal Check

```c
    // check diagonals
    for (d=0; d<2*N-1; d++) {
        n = 0;
        for (r=0; r<N; r++) {
            c = d - r;
            if ((c>=0) && (c<N)) {
                if (board[r][c] != 0) {
                    n++;
                }
            }
        }
        if (n>1) {
            return 0;
        }
    }
```

* **Main diagonals** run from bottom-left to top-right when indexing by `r+c` constant. Here `d` iterates possible sums `0...(2N-2)`, and for each `r` we compute `c=d-r`.
* Count queens on each diagonal; more than one means a conflict.

### 5.4 Reverse Diagonal Check

```c
    // check reverse diagonals
    for (d=0; d<2*N-1; d++) {
        n = 0;
        for (r=0; r<N; r++) {
            c = r - d + N - 1;
            if ((c>=0) && (c<N)) {
                if (board[r][c] != 0) {
                    n++;
                }
            }
        }
        if (n>1) {
            return 0;
        }
    }
```

* **Reverse diagonals** run from top-left to bottom-right when indexing by `r-c` constant. By shifting `d` over `-(N-1)...(N-1)`, we cover all.

```c
    return 1;
}
```

* If no conflicts found, the board is a valid solution.

---

## Summary of Key Techniques

1. **Backtracking recursion** (`place_r`): systematically tries all combinations, leveraging call stack to backtrack.
2. **Board state validation** (`check_solution`): enforces queen constraints in rows, columns, and both diagonals.
3. **Macro for board size**: allows easy adaptation to `N×N` queens.
4. **Order of search**: row-major scanning with resume logic ensures all cells are explored without repetition.
5. **Cell markings**: storing `n+1` per queen gives optional tracing of placement order, though only non-zero vs. zero is strictly needed.

This completes the detailed walkthrough of the Eight-Queens solver.
