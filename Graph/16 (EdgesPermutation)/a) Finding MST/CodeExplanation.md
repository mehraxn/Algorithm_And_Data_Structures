# Maximum-Weight Path by Brute-Force Edge Permutations (C)

---

## Source Code (as provided)

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int src;
    int destination;
    int weight;
} edge;

edge *build_edge_array(int row, int col, int matrix[row][col], int *counter) {

    *counter = 0;
    edge *edges = malloc(sizeof(edge) * row * col);
    if (!edges) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] > 0) {
                edges[*counter].src         = i;
                edges[*counter].destination = j;
                edges[*counter].weight      = matrix[i][j];
                (*counter)++;
            }
        }
    }
    return edges;
}

void find_the_best_path(int *solution,
                        int k,
                        edge *edges,
                        int *maxNumber,
                        int *bestVertices,
                        int *bestLen)
{
    for (int i = 0; i + 1 < k; i++) {
        if (edges[ solution[i] ].destination != edges[ solution[i+1] ].src)
            return;
    }

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += edges[ solution[i] ].weight;

    if (sum > *maxNumber) {
        *maxNumber = sum;
        *bestLen   = k;
        for (int i = 0; i < k; i++)
            bestVertices[i] = solution[i];
    }
}

// Generate all k‐permutations of the edge‐indices in value[0..n),
// track which are used in mark[], build each candidate in solution[].
void permute_edges(int *value,
                   int *solution,
                   int *mark,
                   int n,
                   int k,
                   int pos,
                   edge *edges,
                   int *maxNumber,
                   int *bestVertices,
                   int *bestLen)
{
    if (pos == k) {
        find_the_best_path(solution, k, edges, maxNumber, bestVertices, bestLen);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            mark[i] = 1;
            solution[pos] = value[i];
            permute_edges(value, solution, mark,
                          n, k, pos+1,
                          edges, maxNumber, bestVertices, bestLen);
            mark[i] = 0;
        }
    }
}

int main(void) {
    int matrix[6][6] = {
        {  0,   0,   0,   0,   0,   3},
        {  0,   0,  73,   0,   0,   0},
        {  0,   0,   0,   0, 193,   0},
        {  0,   0,   0,   0,   0,   5},
        {  0,   0,   0,  61,   0,   0},
        {137,   0,   0,   0,   0,   0}
    };

    int edgeCount;
    edge *edges = build_edge_array(6, 6, matrix, &edgeCount);

    int maxWeight = INT_MIN;
    int *bestPath      = malloc(sizeof(int) * edgeCount);
    int *value         = malloc(sizeof(int) * edgeCount);
    int *solution      = malloc(sizeof(int) * edgeCount);
    int *mark          = calloc(edgeCount, sizeof(int));
    int bestLen        = 0;

    // initialize the list of available edge‐indices [0..edgeCount)
    for (int i = 0; i < edgeCount; i++)
        value[i] = i;

    // try all path‐lengths from 1 up to edgeCount
    for (int k = 1; k <= edgeCount; k++) {
        permute_edges(value, solution, mark,
                      edgeCount, k, 0,
                      edges, &maxWeight, bestPath, &bestLen);
    }

    // output result
    printf("Max weight: %d\n", maxWeight);
    printf("Path (edge indices in the array):");
    for (int i = 0; i < bestLen; i++)
        printf(" %d", bestPath[i]);
    printf("\n");

    // clean up
    free(edges);
    free(bestPath);
    free(value);
    free(solution);
    free(mark);

    return 0;
}
```

---

## Deep, Line-by-Line Explanation

Below, we go **statement by statement**, explaining purpose, lifetime, data flow, edge cases, and how everything fits together.

### Headers and Type Definitions

```c
#include <stdio.h>
```

* Brings in **I/O** facilities: `printf`, `perror`, etc.

```c
#include <stdlib.h>
```

* Provides general utilities: `malloc`, `calloc`, `free`, `exit`, `EXIT_FAILURE`.

```c
#include <limits.h>
```

* Exposes integer limits like `INT_MIN`, used to initialize the best weight with the smallest possible `int`.

```c
typedef struct {
    int src;
    int destination;
    int weight;
} edge;
```

* Defines a compact record for a **directed, weighted edge**:

  * `src`: the **source** vertex index.
  * `destination`: the **target** vertex index.
  * `weight`: the integer weight of this edge.
* `typedef ... edge;` creates the alias `edge` for ease of use.

---

### `build_edge_array`: Extract positive-weight edges from the matrix

**Signature**

```c
edge *build_edge_array(int row, int col, int matrix[row][col], int *counter)
```

* `row`, `col`: matrix dimensions.
* `matrix[row][col]`: a **variable-length array (VLA) parameter** (C99+), the adjacency matrix.
* `*counter`: output parameter; the function writes back the **number of edges found**.

**Body**

```c
*counter = 0;
```

* Initialize the found-edge counter.

```c
edge *edges = malloc(sizeof(edge) * row * col);
```

* Allocate the **upper bound** number of possible edges (if every matrix cell were positive). This simplifies the code to one pass for extraction.
* Potentially **over-allocates**, but is safe and simple.

```c
if (!edges) {
    perror("malloc");
    exit(EXIT_FAILURE);
}
```

* Defensive check: on allocation failure, print system error and terminate with a **non-zero** status.

```c
for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        if (matrix[i][j] > 0) {
            edges[*counter].src         = i;
            edges[*counter].destination = j;
            edges[*counter].weight      = matrix[i][j];
            (*counter)++;
        }
    }
}
```

* Double loop to visit **every** cell `matrix[i][j]`.
* `if (matrix[i][j] > 0)` treats only **positive** entries as edges. Zeros and negatives are ignored.
* For each positive cell:

  * Fill the next `edge` slot: `(src=i, destination=j, weight=matrix[i][j])`.
  * Increment the `counter` of found edges.

```c
return edges;
```

* Returns ownership of the allocated `edges` array to the caller, who must `free()` it later.

**Key properties & caveats**

* Complexity: `O(row*col)` time, `O(row*col)` worst-case memory (though only `*counter` entries are valid).
* Requires C99+ for VLA parameter syntax. If portability is a concern, accept `int **matrix` or `int *matrix` with manual indexing.

---

### `find_the_best_path`: Validate candidate trail; update best if better

**Signature**

```c
void find_the_best_path(int *solution,
                        int k,
                        edge *edges,
                        int *maxNumber,
                        int *bestVertices,
                        int *bestLen)
```

* `solution[0..k-1]`: a **candidate sequence of edge indices** (into `edges`).
* `k`: candidate length (number of edges).
* `edges`: the master edge array.
* `*maxNumber`: current best total weight found so far.
* `bestVertices`: buffer to store the **edge indices** of the best trail found.
* `*bestLen`: how many edges are in the current best trail.

**Body**

```c
for (int i = 0; i + 1 < k; i++) {
    if (edges[ solution[i] ].destination != edges[ solution[i+1] ].src)
        return;
}
```

* **Continuity check** for a directed trail:

  * For each adjacent pair in `solution`, ensure the **destination** of edge `solution[i]` equals the **source** of edge `solution[i+1]`.
  * If any pair fails, **reject** the candidate immediately by returning (no scoring or updates).
* Guarantees that accepted sequences represent a valid edge-by-edge traversal.

```c
int sum = 0;
for (int i = 0; i < k; i++)
    sum += edges[ solution[i] ].weight;
```

* Compute the **total weight** of the candidate trail by summing constituent edges' weights.

```c
if (sum > *maxNumber) {
    *maxNumber = sum;
    *bestLen   = k;
    for (int i = 0; i < k; i++)
        bestVertices[i] = solution[i];
}
```

* If the candidate beats the current best total, **record** it:

  * Update the best score and best length.
  * Copy the entire candidate (edge indices) into `bestVertices`.

**Notes**

* Because candidates contain **unique edges** (enforced by the permutation generator), this function checks only **continuity**; it does not need to prevent reusing edges.
* Vertices **may repeat**; only edges are unique.

---

### `permute_edges`: Generate all k-permutations (without repetition)

**Signature**

```c
void permute_edges(int *value,
                   int *solution,
                   int *mark,
                   int n,
                   int k,
                   int pos,
                   edge *edges,
                   int *maxNumber,
                   int *bestVertices,
                   int *bestLen)
```

* `value[0..n)`: the pool of **edge indices** available to choose from (typically `0..edgeCount-1`).
* `solution[0..k)`: holds the **current partial permutation** under construction.
* `mark[0..n)`: boolean flags (`0/1`), whether `value[i]` has been used already in `solution`.
* `n`: total number of available items (`edgeCount`).
* `k`: target permutation length for this call (varies from `1` to `edgeCount`).
* `pos`: current fill position in `solution` (from `0` up to `k`).
* Remaining parameters forward references for scoring the finished candidate.

**Body**

```c
if (pos == k) {
    find_the_best_path(solution, k, edges, maxNumber, bestVertices, bestLen);
    return;
}
```

* **Base case**: when `solution` is filled with `k` choices, validate and score it.

```c
for (int i = 0; i < n; i++) {
    if (!mark[i]) {
        mark[i] = 1;
        solution[pos] = value[i];
        permute_edges(value, solution, mark,
                      n, k, pos+1,
                      edges, maxNumber, bestVertices, bestLen);
        mark[i] = 0;
    }
}
```

* **Backtracking loop** over all available items:

  * Skip `i` if already used (`mark[i]` is true).
  * Choose it: set `mark[i]=1`, write the chosen edge index `value[i]` into the next `solution` slot, and **recurse** to fill the next position.
  * After returning, **un-choose** it (`mark[i]=0`) so other branches can reuse it.

**Notes**

* This generates exactly the set of **k-permutations without repetition**.
* This function does **not** check continuity early; continuity is checked only when a full `k`-length candidate is formed. (See the Optimizations section for pruning ideas.)

---

### `main`: Wiring it all together

```c
int matrix[6][6] = {
    {  0,   0,   0,   0,   0,   3},
    {  0,   0,  73,   0,   0,   0},
    {  0,   0,   0,   0, 193,   0},
    {  0,   0,   0,   0,   0,   5},
    {  0,   0,   0,  61,   0,   0},
    {137,   0,   0,   0,   0,   0}
};
```

* A **6×6 adjacency matrix** of a directed weighted graph.
* Positive entries indicate directed edges with that weight:

  * `0→5(3)`, `1→2(73)`, `2→4(193)`, `3→5(5)`, `4→3(61)`, `5→0(137)`.

```c
int edgeCount;
edge *edges = build_edge_array(6, 6, matrix, &edgeCount);
```

* Extracts all positive edges into a flat array `edges`.
* Writes the number of edges into `edgeCount` (here, `6`).

```c
int maxWeight = INT_MIN;
```

* Initialize the best-so-far score to the **lowest possible int**, so the first valid trail will improve it.

```c
int *bestPath      = malloc(sizeof(int) * edgeCount);
int *value         = malloc(sizeof(int) * edgeCount);
int *solution      = malloc(sizeof(int) * edgeCount);
int *mark          = calloc(edgeCount, sizeof(int));
int bestLen        = 0;
```

* Allocate helper arrays of size `edgeCount`:

  * `bestPath`: will store the **edge indices** of the best trail found.
  * `value`: the available item list for permutations (initialized to `0..edgeCount-1`).
  * `solution`: a working buffer to build each candidate permutation.
  * `mark`: usage flags; `calloc` zero-initializes the array.
  * `bestLen`: best trail length recorded so far; starts at 0.

```c
for (int i = 0; i < edgeCount; i++)
    value[i] = i;
```

* Initialize `value` as `[0,1,2,...,edgeCount-1]` — the canonical list of edge indices.

```c
for (int k = 1; k <= edgeCount; k++) {
    permute_edges(value, solution, mark,
                  edgeCount, k, 0,
                  edges, &maxWeight, bestPath, &bestLen);
}
```

* For every **length `k`** from 1 up to all edges:

  * Generate all k-permutations and evaluate them.
* This ensures we consider **every possible trail length**.

```c
printf("Max weight: %d\n", maxWeight);
printf("Path (edge indices in the array):");
for (int i = 0; i < bestLen; i++)
    printf(" %d", bestPath[i]);
printf("\n");
```

* Print the **maximum total weight** and the **sequence of edge indices** that achieves it.

```c
free(edges);
free(bestPath);
free(value);
free(solution);
free(mark);
```

* Release all heap-allocated memory. Good hygiene prevents leaks.

```c
return 0;
```

* Return success status to the OS.

---

## Execution Walkthrough (with the given matrix)

1. `build_edge_array` finds **6** edges in this order (because it scans row-major):

   1. `0→5 (3)`
   2. `1→2 (73)`
   3. `2→4 (193)`
   4. `3→5 (5)`
   5. `4→3 (61)`
   6. `5→0 (137)`

2. For each `k = 1..6`, `permute_edges` enumerates all k-permutations of `{0,1,2,3,4,5}` (no repeats), e.g. for `k=3`: `(0,1,2)`, `(0,1,3)`, ..., `(5,4,3)`.

3. For any full candidate, `find_the_best_path` checks continuity pairwise; only sequences that chain (dest == next src) survive.

4. The highest-sum valid trail uses **all 6 edges** in the order: `1,2,4,3,5,0`:

   * `1→2 (73)` → `2→4 (193)` → `4→3 (61)` → `3→5 (5)` → `5→0 (137)` → `0→5 (3)`
   * Total = `73 + 193 + 61 + 5 + 137 + 3 = 472`.

---

## Complexity Analysis

Let **E** = number of edges (positive entries in the matrix).

* The outer loop tries `k = 1..E`.
* For a fixed `k`, we generate all **k-permutations** of `E` distinct items: `P(E,k) = E! / (E-k)!`.
* Total candidate count explored: `\(\sum_{k=1}^{E} P(E,k)\)`, which grows on the order of `E!`.
* Each candidate performs up to `k-1` continuity checks and `k` additions.
* **Time:** factorial growth → practical only for small **E**.
* **Space:** `O(E)` auxiliary arrays + `O(E)` edges.

---

## Robustness, Portability, and Edge Cases

* **Zero/negative weights:** Ignored. To include them, change `if (matrix[i][j] > 0)` to `if (matrix[i][j] != 0)` (or remove the condition entirely if every cell is an edge).
* **Empty graph:** If `edgeCount == 0`, no candidate is ever accepted. You might want to handle this explicitly (e.g., print a friendly message and exit) instead of leaving `INT_MIN` as the result.
* **C standard:** The VLA parameter requires C99+. For maximum portability, refactor the function to accept a flat pointer and manual indexing.
* **Memory:** `build_edge_array` over-allocates up to `row*col` edges. For tighter memory, do a two-pass approach: count, allocate exactly, then fill.

---

## Suggested Improvements (with precise hooks)

1. **Early Pruning on Continuity** (significant speedup):

   * When extending `solution` at `pos`, require that the chosen edge’s `src` matches the last chosen edge’s `destination` (except at `pos==0`).
   * This avoids generating almost all invalid permutations.
   * Implementation sketch inside `permute_edges`:

     ```c
     if (pos > 0) {
         int lastEdge = solution[pos-1];
         if (edges[value[i]].src != edges[lastEdge].destination) continue; // prune
     }
     ```

2. **Adjacency Lists** to avoid scanning all edges when extending a trail:

   * Build `vector`/arrays of edge indices by `src` vertex.
   * Then, at each step, iterate only over **continuation candidates**.

3. **Start/End Constraints:**

   * Add parameters `requiredStart` / `requiredEnd` and enforce them either during generation or in `find_the_best_path`.

4. **Return Vertex Sequence:**

   * Translate `bestPath` to a vertex sequence for user-friendly output.

5. **Branch and Bound:**

   * Track `currentSum` and an optimistic upper bound of what remains (e.g., sum of the `k-pos` largest unused edge weights). If `currentSum + bound <= maxWeight`, prune the branch.

6. **Detect Eulerian Trails/Cycles** (when they exist):

   * For certain graphs, the maximum-weight trail will use **all edges**. You could test Eulerian conditions first and, if they hold, compute the best ordering faster by sorting candidate edges appropriately.

---

## Testing Plan (what to verify)

1. **Trivial:** a matrix with a single positive entry.
2. **No edges:** all zeros — program should report gracefully.
3. **Two disjoint edges:** ensure the best is the heavier single edge.
4. **Simple chain:** `A→B`, `B→C`, `C→D` — only one valid 3-edge trail.
5. **Branching:** multiple outgoing edges from a vertex — verify selection chooses the heavier chaining.
6. **Cycles:** ensure cycles are allowed and handled.
7. **Negative weights (if enabled):** confirm handling and correctness.

---

## (Optional) Friendly Printing of the Best Trail

Add a helper to print vertices and weights, not only edge indices:

```c
void print_trail(edge *edges, int *path, int len) {
    if (len == 0) return;
    printf("Trail: %d", edges[path[0]].src);
    for (int i = 0; i < len; i++) {
        printf(" -> %d(%d)", edges[path[i]].destination, edges[path[i]].weight);
    }
    printf("\n");
}
```

Then, after computing the best path in `main`:

```c
print_trail(edges, bestPath, bestLen);
```

---

## Summary

* The program enumerates every edge-simple directed trail obtainable from the positive entries of the adjacency matrix, scores them by total weight, and reports the maximum.
* It’s **correct** for small graphs, but factorial in runtime.
* The clearest wins for performance are **early pruning** on continuity and building an **adjacency-indexed** expansion.
