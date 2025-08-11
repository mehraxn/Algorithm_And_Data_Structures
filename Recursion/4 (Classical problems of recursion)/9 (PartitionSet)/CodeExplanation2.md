# Set Partitioning Algorithm - Complete Guide

## Overview
This program generates all possible ways to partition a set of elements into **k non-empty subsets** using a recursive backtracking approach.

## What is Set Partitioning?
Set partitioning divides a set into non-overlapping subsets where:
- Every element appears in exactly one subset
- All subsets are non-empty
- The union of all subsets equals the original set

## Algorithm Explanation

### Core Loop Analysis
The heart of the algorithm is this recursive loop:

```c
for (i = 0; i < k; i++) {
    solution[pos] = i;
    count = partition(value, solution, n, k, pos + 1, count);
}
```

### How the Loop Works

#### Step-by-Step Breakdown:
1. **For each position `pos` in the array (0 to n-1)**
2. **Try assigning the element at that position to each possible subset (0 to k-1)**
3. **Recursively solve for the remaining positions**

## Complete Example: n=3, k=2

Let's trace through partitioning the set `{1, 2, 3}` into `2` subsets.

### Initial State:
- `value = {1, 2, 3}`
- `solution = {?, ?, ?}` (to be filled)
- `n = 3`, `k = 2`

### Recursion Tree:

```
Level 0 (pos=0): Assign element 1
├── solution[0] = 0 (element 1 → subset 0)
│   Level 1 (pos=1): Assign element 2
│   ├── solution[1] = 0 (element 2 → subset 0)
│   │   Level 2 (pos=2): Assign element 3
│   │   ├── solution[2] = 0 → {0,0,0} → {{1,2,3}, {}} → INVALID (subset 1 empty)
│   │   └── solution[2] = 1 → {0,0,1} → {{1,2}, {3}} → VALID ✓
│   └── solution[1] = 1 (element 2 → subset 1)
│       Level 2 (pos=2): Assign element 3
│       ├── solution[2] = 0 → {0,1,0} → {{1,3}, {2}} → VALID ✓
│       └── solution[2] = 1 → {0,1,1} → {{1}, {2,3}} → VALID ✓
└── solution[0] = 1 (element 1 → subset 1)
    Level 1 (pos=1): Assign element 2
    ├── solution[1] = 0 (element 2 → subset 0)
    │   Level 2 (pos=2): Assign element 3
    │   ├── solution[2] = 0 → {1,0,0} → {{2,3}, {1}} → VALID ✓
    │   └── solution[2] = 1 → {1,0,1} → {{2}, {1,3}} → VALID ✓
    └── solution[1] = 1 (element 2 → subset 1)
        Level 2 (pos=2): Assign element 3
        ├── solution[2] = 0 → {1,1,0} → {{3}, {1,2}} → VALID ✓
        └── solution[2] = 1 → {1,1,1} → {{}, {1,2,3}} → INVALID (subset 0 empty)
```

### Total Combinations Generated: 2³ = 8

| Solution Array | Subset 0 | Subset 1 | Valid? | Reason |
|---------------|----------|----------|---------|---------|
| `{0,0,0}`     | `{1,2,3}`| `{}`     | ❌      | Subset 1 is empty |
| `{0,0,1}`     | `{1,2}`  | `{3}`    | ✅      | Both subsets non-empty |
| `{0,1,0}`     | `{1,3}`  | `{2}`    | ✅      | Both subsets non-empty |
| `{0,1,1}`     | `{1}`    | `{2,3}`  | ✅      | Both subsets non-empty |
| `{1,0,0}`     | `{2,3}`  | `{1}`    | ✅      | Both subsets non-empty |
| `{1,0,1}`     | `{2}`    | `{1,3}`  | ✅      | Both subsets non-empty |
| `{1,1,0}`     | `{3}`    | `{1,2}`  | ✅      | Both subsets non-empty |
| `{1,1,1}`     | `{}`     | `{1,2,3}`| ❌      | Subset 0 is empty |

### Final Result: 6 valid partitions

## General Formula

For **n elements** and **k subsets**:
- **Total combinations generated**: k^n
- **Valid partitions**: Stirling number of the second kind S(n,k)

### Examples:
- n=3, k=2: 2³ = 8 total, 3 unique valid partitions
- n=4, k=2: 2⁴ = 16 total, 7 unique valid partitions
- n=4, k=3: 3⁴ = 81 total, 6 unique valid partitions

## Code Structure

### Main Components:

1. **Recursive Loop**: Generates all k^n possible assignments
```c
for (i = 0; i < k; i++) {
    solution[pos] = i;
    count = partition(value, solution, n, k, pos + 1, count);
}
```

2. **Validation Check**: Filters out invalid partitions
```c
for (j = 0; j < k; j++) {
    if (occurrences[j] == 0) {
        end = 1;  // Invalid - empty subset found
    }
}
```

3. **Output Generation**: Prints valid partitions
```c
// Print solution vector and actual subsets
```

## Time Complexity
- **Time**: O(k^n) - generates all possible assignments
- **Space**: O(n) - recursion depth + arrays
- **Practical limit**: Works well for small n (≤ 10) due to exponential growth

## Usage
Compile and run:
```bash
gcc -o partition main.c
./partition
```

The program will output all valid partitions of `{1,2,3,4}` into 2 non-empty subsets.

## Key Insights
1. The algorithm is **brute force** - it tries every possible assignment
2. **Backtracking** ensures all combinations are explored
3. **Validation** eliminates partitions with empty subsets
4. Results include **equivalent partitions** (subsets can be relabeled)
5. For unique partitions, additional deduplication would be needed