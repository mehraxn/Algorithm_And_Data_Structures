# DFS Best Path — README

## What is the question asking?

You are given an **n × n grid** and a starting cell `(r, c)`. A single piece must move so that it **visits every cell exactly once** (a Hamiltonian path). The piece can only move **horizontally or vertically** by **1**, **2**, or **3** squares at a time, and **each move has a cost**:

* Move 3 squares → **cost 0.1**
* Move 2 squares → **cost 0.2**
* Move 1 square  → **cost 0.3**

Among all possible full-coverage paths starting from `(r, c)`, you must find the one with the **minimum total cost**. While constructing the path, you must fill an `n × n` matrix (`board`) where each cell stores the **visit order**:

* `board[r][c] = 0` for the start cell
* The next visited cell is `1`, then `2`, … up to `n*n - 1`

If no full path exists, you must return `0.0` (and the content of `board` can be ignored).

---

## What should we build?

Implement the function

```c
float visit(int **board, int n, int r, int c);
```

**Inputs**

* `board`: an allocated `n × n` **int** matrix (output buffer) to be filled with visit indices
* `n`: size of the grid
* `r`, `c`: starting row and column (0-based indices)

**Outputs**

* Returns a `float` equal to the **minimum total cost** over all Hamiltonian paths that start at `(r, c)` and visit every cell exactly once
* If no such path exists, return `0.0`
* On success, `board[i][j]` contains the step index (0…`n*n-1`) when the cell `(i, j)` is visited

---

## Required approach and constraints

* Use **Depth-First Search (DFS) with backtracking** to explore paths
* Maintain a **2D visited matrix** of type **int** (`int**`), with values `0` (not visited) or `1` (visited)
* Do **not** use `static`, `inline`, or `struct`
* Prefer exploring moves in **increasing cost order** (distance 3 first, then 2, then 1) to help reach cheaper solutions sooner and enable pruning
* Use **global constant arrays** for move deltas and costs if desired (e.g., `dr[]`, `dc[]`, `cost[]`)

---

## Allowed moves and costs

From a cell `(r, c)`, you may move to any of these destinations, **staying within bounds** and **not revisiting** a cell:

* `(r ± 3, c)` or `(r, c ± 3)` with **cost 0.1**
* `(r ± 2, c)` or `(r, c ± 2)` with **cost 0.2**
* `(r ± 1, c)` or `(r, c ± 1)` with **cost 0.3**

For implementation convenience, define parallel arrays (globals):

```c
const int   dr[]  = { -3,  3,  0,  0,  -2,  2,  0,  0,  -1,  1,  0,  0 };
const int   dc[]  = {  0,  0, -3,  3,   0,  0, -2,  2,   0,  0, -1,  1 };
const float cost[] = { 0.1f,0.1f,0.1f,0.1f, 0.2f,0.2f,0.2f,0.2f, 0.3f,0.3f,0.3f,0.3f };
```

The ordering (all distance-3 moves first, then 2, then 1) helps the DFS find cheaper paths earlier for better pruning.

---

## High-level algorithm (DFS + backtracking)

1. Initialize an `int** visited` of size `n × n` with zeros.
2. Set `visited[r][c] = 1` and `board[r][c] = 0`.
3. Recursively attempt all legal moves `(nr, nc)` from `(r, c)` in the pre-defined order:

   * Skip out-of-bounds or already visited cells
   * Mark the next cell visited, set its step index, and add the corresponding move **cost** to the running total
   * If all `n*n` cells are visited, **update the best (minimum) cost** and store a copy of the current numbering
   * Otherwise, continue searching from `(nr, nc)`
   * **Backtrack**: unmark `visited[nr][nc]` and reset `board[nr][nc]` to allow exploring other branches
4. Keep a global or external `bestCost` initialized to `FLT_MAX`; **prune** any recursive branch whose `currentCost >= bestCost`.
5. After DFS completes, if `bestCost` was updated, copy the best numbering into the caller-provided `board` and return `bestCost`; otherwise return `0.0`.

---

## Edge cases and assumptions

* If `n ≤ 0`, `(r, c)` is out of range, or memory allocation fails → return `0.0`
* If no Hamiltonian path exists from the chosen start → return `0.0`
* Indices are **0-based**
* `board` is assumed to be allocated by the caller as `n` pointers to `n`-element `int` arrays
* Movement is strictly orthogonal (no diagonals)

---

## Complexity

* Worst-case exponential time due to Hamiltonian search: \~`O(12^(n*n))` in the naive upper bound; effective branching is much lower due to bounds, visited checks, order, and pruning
* Memory: `O(n^2)` for `visited`, `board`, and any temporary copy of the best solution

---

## How to use and test

1. Allocate `board` as an `int**` (`n` rows × `n` cols)
2. Call `visit(board, n, r, c)`
3. If the return value > 0, print `board` to see the visiting order and the minimal total cost

### Minimal driver example (for local testing)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 4, i, j;
    int **board = (int**)malloc(n * sizeof(*board));
    for (i = 0; i < n; ++i) board[i] = (int*)malloc(n * sizeof(int));

    float ans = visit(board, n, 0, 0);

    if (ans > 0.0f) {
        printf("Cost = %.3f\n", ans);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) printf("%3d ", board[i][j]);
            printf("\n");
        }
    } else {
        printf("No full path found or invalid input.\n");
    }

    for (i = 0; i < n; ++i) free(board[i]);
    free(board);
    return 0;
}
```

> **Note**: Keep your implementation consistent with the constraints: no `static`, no `inline`, no `struct`; use a **2D `int` visited** matrix; explore moves in cost order; and return the **minimum cost** as a `float`.
