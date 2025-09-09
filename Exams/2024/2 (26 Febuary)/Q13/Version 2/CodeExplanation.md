# Longest Weight Path (DAG, Alternating Colors) — README

This README documents a C implementation of the function required by the prompt:

```c
void longest_weight_path (int **g, int *color, char **vertex_id, int n);
```

> **Task**: In a **weighted, directed, acyclic** graph `G` with `n` vertices, stored as an adjacency matrix `g`, find and **display the identifiers** of the vertices on a path whose **sum of edge weights is maximum** **and** whose vertices have **alternating colors** (WHITE, BLACK, WHITE, … or BLACK, WHITE, …). Edge weights are positive integers. Each vertex is either `WHITE` or `BLACK` (e.g., two constants or an enum). The function prints the vertex IDs in travel order.

---

## Inputs & Representation

* `g`: an `n×n` adjacency matrix. If `g[i][j] > 0`, there is a directed edge `i → j` with integer weight `g[i][j]`. If `g[i][j] == 0`, the edge is absent.
* `color[0..n-1]`: the color of each vertex. Use two distinct codes (e.g., `0=WHITE`, `1=BLACK`).
* `vertex_id[0..n-1]`: printable identifiers (strings) for each vertex.
* `n`: number of vertices.

### Derived edge list

For efficient iteration, the code converts the matrix to a flat list of edges:

```c
typedef struct EDGES { int source, destination, weight; } edge;
```

Each present edge becomes an `edge {i, j, g[i][j]}` and is placed in `array[]`.

---

## What qualifies as a valid path?

A sequence of directed edges `e0, e1, …, e(k-1)` is a valid path iff:

1. **Continuity**: for every `t`, `e_t.destination == e_(t+1).source`.
2. **Alternating colors**: for every `edge u→v` in the sequence, `color[u] != color[v]` (WHITE↔BLACK alternation along the path).
3. **No edge reuse** in the same candidate (prevents trivial cycles with parallel edges, though the graph is acyclic).

The printed path is the **vertex sequence**: the source of the first edge, then every subsequent destination, e.g., `A B C D`.

---

## High‑Level Algorithm (what this code does)

Although the graph is a DAG, the current implementation solves the problem via **systematic backtracking over edge sequences**, which is simple and exact for small graphs.

1. **Extract edges** from `g` into `array[]` and let `m = edge_counter`.
2. **Try all possible path lengths** `k = 1..m`.
3. **Backtrack** to build all length‑`k` sequences of *distinct* edges while **enforcing continuity early**.
4. For each complete candidate, **validate** it (color alternation + continuity) and **sum weights**.
5. Keep the **best** candidate (highest weight) as the answer.

This approach is exhaustive; it guarantees optimality but has exponential worst‑case time.

---

## Core Functions

### `void longest_weight_path (int **g, int *color, char **vertex_id, int n)`

**Role**: Orchestrates the computation and prints the winning vertex sequence and its total weight.

**Steps**

1. Build `edge array[]` from `g` (one entry per `g[i][j] > 0`).
2. Allocate and initialize working arrays: `solution[]` (current candidate), `mark[]` (edge‑usage flags), `final_numbers[]` (best candidate), `final_maximum` (best weight).
3. For each `k` from `1` to `edge_counter`, call `find_maximum(...)` to explore all length‑`k` paths.
4. Print the best vertex sequence using `vertex_id[]` and its total weight.

### \`void find\_maximum(edge array\[], int edge\_counter, int \*color, int nv,

```
int *solution, int *mark, int n, int k, int pos,
int *final_numbers, int *final_maximum)`
```

**Role**: Depth‑first search (backtracking) that constructs candidate paths of exactly `k` edges.

* **Base case**: `pos >= k` → call `check(...)` to validate and possibly update the global best.
* **Recursive step**:

  * Iterate over all edges `i`.
  * Skip if already used (`mark[i] == 1`).
  * If `pos > 0`, enforce **continuity** by requiring `array[solution[pos-1]].destination == array[i].source`; otherwise skip.
  * Choose edge `i`: set `mark[i]=1`, `solution[pos]=i`, recurse with `pos+1`, then backtrack (`mark[i]=0`).

This early continuity test prunes many impossible sequences.

### \`int check(edge array\[], int edge\_counter, int \*color, int nv,

```
int *solution, int k, int *final_numbers, int *final_maximum)`
```

**Role**: Validates a *complete* candidate path and updates the best‑so‑far result.

* **Color alternation**: for each edge `u→v` in the candidate, confirm `color[u] != color[v]`.
* **Continuity**: defensively re‑check that consecutive edges connect (safe redundancy).
* **Scoring**: compute `temp = Σ weight` of the candidate.
* **Update**: if `temp > *final_maximum`, copy `solution[0..k-1]` into `final_numbers` and set `*final_maximum = temp`.
* **Return**: `1` if improved, else `0`.

---

## Output Format

The function prints the **vertex identifiers** in order along the best path, followed by the total weight. Example (shape only):

```
Path with maximum weight: abc def … path - Weight: 17
```

Printing is derived from the saved edge indices: output the `source` of the first edge, then the `destination` of each subsequent edge, mapping vertex indices to strings via `vertex_id[]`.

---

## Why this works for the exam setting (DAG + alternating colors)

* The DAG property guarantees **no directed cycles**; our search will not loop indefinitely and the best path exists.
* The **alternating color** rule is enforced locally on each edge and thus automatically ensures the vertex sequence alternates WHITE/BLACK/WHITE…
* Because all weights are **positive integers**, a longer valid path generally tends to have higher weight, but we still try all lengths to guarantee the maximum.

---

## Complexity

Let `m` be the number of edges. The search considers permutations of up to `m` edges that satisfy continuity, so:

* **Time (worst case)**: `O(m!)` (heavily pruned by continuity and colors; practical for small `m`).
* **Space**: `O(m)` for recursion and arrays.

> **Note**: Since the graph is a **DAG**, a dynamic‑programming solution exists in `O(n + m)` time after a topological sort (augment states by color parity). The current implementation favors clarity and directness and is adequate for small/medium instances typical of exercises.

---

## Testing Checklist

* **Single edge**: one valid `u→v` with different colors → that two‑vertex path is printed.
* **Color violation**: add an edge `u→v` with `color[u]==color[v]` → it must never appear in the path.
* **Continuity**: edges `A→B` and `C→D` cannot form a two‑edge path.
* **Multiple candidates**: ensure the maximum by weight is chosen; ties currently keep the first encountered.

---

## Possible Improvements (if you want to leverage the DAG fully)

1. **DP on DAG**: After topological sorting, compute `best[v][parity]` = max weight to reach `v` when the next required color parity is `parity`; transition along edges with permitted color alternation.
2. **Branch‑and‑bound**: In backtracking, maintain a partial sum and a provable upper bound to cut branches early.
3. **Start‑vertex restriction**: Anchor the search at each vertex as a start to reduce branching and simplify output assembly.

---

*This README aligns with the prompt: a DAG, integer weights, two colors, and the requirement to print a maximum‑weight alternating‑color path. The provided implementation accomplishes this via exact backtracking; alternative DAG‑DP solutions are noted for larger inputs.*
