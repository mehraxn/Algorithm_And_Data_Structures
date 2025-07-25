# N-Queens Solver

This project implements a solution to the classic **N‑Queens problem**: placing N queens on an N×N chessboard so that no two queens attack each other. The approach uses a **recursive backtracking** algorithm, marking attack positions dynamically as queens are placed and removed.

---

## File: `nqueens.c`

Below is the complete source code with **line-by-line** explanation.

```c
 1  #include <stdio.h>
```

**Line 1**: Includes the Standard Input/Output library, providing functions like `printf`, `fprintf`, and `stdout`.

```c
 2  #include <stdlib.h>
```

**Line 2**: Includes the Standard Library header, providing macros and functions such as `EXIT_SUCCESS` and memory-management routines.

```c
 4  #define N 8
```

**Line 4**: Defines the macro `N` as `8`. This sets the chessboard size to 8×8. Everywhere `N` appears, the preprocessor substitutes `8`.

```c
 6  /* function prototypes */
 7  int move_r(int board[N][N], int n);
 8  void set_queen(int board[N][N], int r, int c, int val);
```

**Lines 6–8**: Declare the two functions used below:

* `move_r`: recursive function trying to place the next queen, given the current board state and count `n` of queens placed.
* `set_queen`: helper to mark (`val = +1`) or unmark (`val = -1`) cells attacked by a queen at position `(r,c)`.

```c
11 /*
12  * main program
13  */
 14 int main(void) {
```

**Lines 11–14**: Comment block and start of `main`, the program entry point. Uses `int main(void)` to indicate no command-line args.

```c
15     int i, j;
16     int board[N][N];
```

**Lines 15–16**: Declare loop counters `i`, `j` and a 2D array `board` of size N×N to track queen placements and attacked cells.

```c
17     for (i = 0; i < N; i++) {
18         for (j = 0; j < N; j++) {
19             board[i][j] = 0;
20         }
21     }
```

**Lines 17–21**: Nested loops initialize every cell of `board` to `0`, indicating no queen and no attacks yet.

```c
23     if (move_r(board, 0)) {
```

**Line 23**: Calls `move_r` with `n = 0` (no queens placed). If it returns non-zero (`1`), a solution was found.

```c
24         fprintf(stdout, "Solution found:\n");
```

**Line 24**: Prints header "Solution found:" to `stdout`.

```c
25         for (i = 0; i < N; i++) {
26             for (j = 0; j < N; j++) {
```

**Lines 25–26**: Loops over each row `i` and each column `j` to print the final board.

```c
27                 if (board[i][j] == 6) {
28                     fprintf(stdout, "Q");
29                 } else {
30                     fprintf(stdout, "*");
31                 }
```

**Lines 27–31**: Determines if a queen is at `(i,j)`. The code marks queens by adding `+1` in `set_queen` on the row and column, but the actual queen cell ends up with value `6` (1 for queen itself plus contributions from marking—N=8 but diagonal/vertical/horizontal adds up so that only the queen's own cell equals N? In practice this condition distinguishes the queen). If `board[i][j] == 6`, prints `Q`; otherwise prints `*`.

```c
32             }
33             fprintf(stdout, "\n");
34         }
```

**Lines 32–34**: Close inner loop and print newline after each row.

```c
35     } else {
36         fprintf(stdout, "Solution NOT found!\n");
37     }
```

**Lines 35–37**: If `move_r` returned `0`, no solution exists; print that message.

```c
39     return EXIT_SUCCESS;
40 }
```

**Lines 39–40**: End `main` by returning `EXIT_SUCCESS` (0), indicating normal termination.

```c
43 /*
44  * place N queens on the NxN board, recursive function
45  */
46 int move_r(int board[N][N], int n) {
```

**Lines 43–46**: Comment block and signature of `move_r`. Takes the current `board` and integer `n`, the number of queens already placed.

```c
47     int r, c;
```

**Line 47**: Declare `r`, `c` as loop counters for row and column scanning.

```c
48     if (n == N) {
49         return 1;
50     }
```

**Lines 48–50**: Base case: if `n` equals `N`, all queens have been placed successfully—return 1 to indicate success.

```c
51     for (r = 0; r < N; r++) {
52         for (c = 0; c < N; c++) {
```

**Lines 51–52**: Double loop: try every cell `(r,c)` on the board for placing the next queen.

```c
53             if (board[r][c] == 0) {
```

**Line 53**: Only consider cell `(r,c)` if it is not attacked (`0` means no attacks and no queen).

```c
54                 set_queen(board, r, c, +1);
```

**Line 54**: Call `set_queen` with `val = +1` to place a queen at `(r,c)` and mark all affected lines (row, column, both diagonals) by adding `+1`.

```c
55                 if (move_r(board, n + 1)) {
56                     return 1;
57                 }
```

**Lines 55–57**: Recursively attempt to place the remaining `N - (n+1)` queens. If that call returns `1`, propagate success upward by returning `1` immediately.

```c
59                 set_queen(board, r, c, -1);
60             }
61         }
62     }
```

**Lines 59–62**: If recursion did not find a solution, backtrack: call `set_queen` with `val = -1` to remove the queen and unmark attack positions. Then continue scanning other cells.

```c
64     return 0;
65 }
```

**Lines 64–65**: Exhausted all cells without placing all queens—return `0` to signal failure on this path.

```c
68 /*
69  * mark all the reachable cells when a queen is placed in position r,c
70  */
71 void set_queen(int board[N][N], int r, int c, int val) {
```

**Lines 68–71**: Comment block and signature of `set_queen`. `val` is `+1` for placing, `-1` for removing.

```c
72     int i, j;
```

**Line 72**: Declare loop counters for marking.

```c
73     for (j = 0; j < N; j++) {
74         board[r][j] += val;
75     }
```

**Lines 73–75**: Mark/unmark the entire row `r`: for each column `j`, add `val`.

```c
76     for (i = 0; i < N; i++) {
77         board[i][c] += val;
78     }
```

**Lines 76–78**: Mark/unmark the entire column `c`: for each row `i`, add `val`.

```c
79     for (i = r, j = c; i < N && j < N; i++, j++) {
80         board[i][j] += val;
81     }
```

**Lines 79–81**: Mark/unmark the down‑right diagonal starting from `(r,c)`.

```c
82     for (i = r, j = c; i >= 0 && j >= 0; i--, j--) {
83         board[i][j] += val;
84     }
```

**Lines 82–84**: Mark/unmark the up‑left diagonal.

```c
85     for (i = r, j = c; i < N && j >= 0; i++, j--) {
86         board[i][j] += val;
87     }
```

**Lines 85–87**: Mark/unmark the down‑left diagonal.

```c
88     for (i = r, j = c; i >= 0 && j < N; i--, j++) {
89         board[i][j] += val;
90     }
91 }
```

**Lines 88–91**: Mark/unmark the up‑right diagonal, completing the four diagonal directions. End of `set_queen`.

---

### How It Works, Step by Step

1. **Initialization** (lines 17–21): Zero out the board.
2. **Recursive Search** starts in `main` by calling `move_r(board, 0)`.
3. **Base Case** (lines 48–50 of `move_r`): If `n == N`, all queens are placed—report success.
4. **Placement Loop** (lines 51–62 of `move_r`): Iterate every cell; if not under attack, place a queen and recurse.
5. **Marking Attacks** via `set_queen` (lines 73–90): When placing, increment all squares along row, column, and diagonals; when backtracking, decrement to restore.
6. **Backtracking**: If recursive call fails, remove the queen and unmark, then try next position.
7. **Result Printing**: On success, print `Q` for queens and `*` for empty cells; on failure, print a not found message.

This exhaustive line-by-line walkthrough covers every declaration, loop, condition, and function call in the program, explaining its purpose and how it fits into the backtracking algorithm to solve the N‑Queens problem.
