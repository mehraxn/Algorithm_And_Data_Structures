### Task: The Eight Queen Problem

**Problem Definition**:
The eight queens puzzle is the problem of placing eight chess queens on an 8 × 8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal.

**Goal**:
The task is to write a program capable of solving the eight-queen problem. Generalize the original problem to boards of size (N × N), where N is a pre-defined constant value.

**Approaches**:
Considerations on Complexity: The problem can be computationally expensive. First of all, it is important to avoid very trivial approaches such as using brute-force methods to try every possible combination of queen placements, which is inefficient and impractical due to the exponential growth in possibilities as N increases.

#### Notes:
- **Using arrangements with repetitions**: One could set a queen (1) or not (0) in each cell of the 8x8 grid, which yields an enormous space to investigate. The complexity is very high, approximately \( D_{r, k} = D_{64, 2} = 2^{64} = 1.84 	imes 10^{19} \). Most arrangements would be invalid since they would not conform to the rule that no two queens can share the same row, column, or diagonal. Luckily, this approach is highly redundant as there is no reason to place more than eight queens on the board.
- **Using simple arrangements**: We could consider placing k = 8 queens among 64 cells, leading to fewer redundant configurations. The number of combinations can be represented as \( D_{n, k} = D_{64, 8} = 64 	imes 63 	imes ... 	imes 77 = 1.78 	imes 10^{14} \) cases. This reduces complexity, but still yields many unnecessary permutations. Symmetric solutions should also be avoided, as they do not provide new valid outcomes.
- **Combinatorial approaches**: If we calculate the number of valid combinations of selecting 8 positions out of 64, it can be expressed as \( C_{n, k} = C_{64, 8} = \frac{64!}{(64-8)!8!} = 4,426,165,368 = 4.42 	imes 10^{9} \). This is still a very large number, so it is important to reduce computation by avoiding repeated or symmetrical solutions. Using techniques like pruning and backtracking helps efficiently find valid configurations by discarding invalid placements early.

Unfortunately, it can be proved that there are only 92 valid solutions for the eight-queen problem, considering symmetrical ones such as rotations and reflections. Using approaches like pruning and backtracking will allow us to efficiently eliminate these redundant paths and find the valid configurations. The number of distinct valid configurations drops significantly when symmetries are considered, ultimately resulting in 92 unique solutions.

Chess composer Max Bezzel published the eight queens puzzle in 1848. Franz Nauck published the first solutions in 1850. Since then, many mathematicians have worked on the problem and its generalized form. Optimal approaches require considering the chessboard's structure to avoid redundant placements, such as avoiding obvious invalid cells.

When implementing your solution, try to use efficient methods such as backtracking and branch pruning to eliminate unnecessary combinations. Aim to write a program that efficiently places N queens on an N x N chessboard, following the no-threat rule.

