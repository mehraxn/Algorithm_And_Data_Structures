# README: Partitioning a Set into k Blocks with C

## Overview

This C program partitions a set of integers into `k` blocks using arrangements with repetition. It generates all valid partitions without considering symmetric duplicates.

The program is based on the explanation from Example 6.18 (image provided), which illustrates 14 ways to partition a 4-element set `{1,2,3,4}` into 2 subsets.

---

## Suitability

This program is suitable for:

* **Small sets**: such as 3 to 7 elements. The number of partitions grows exponentially, so it's best for small datasets.
* **Sets of small integers or characters**: since the program just uses their position, not their magnitude.
* **Educational or combinatoric use**: such as demonstrating how set partitioning works.

This program is **not recommended** for:

* Very large sets (e.g. more than 10 elements): due to exponential time complexity.
* High-performance environments: since it doesn’t avoid redundant (symmetric) partitions.

**Note on character sets**:
If the `value` array contains characters (e.g., `{'A', 'B', 'C', 'D'}`), the logic remains valid as long as the `solution` array continues to use integers. The `solution` array tracks which partition (0 to k-1) each element belongs to — this is independent of the data type of the values themselves.

For example:

* `value[] = {'A', 'B', 'C', 'D'}`
* `solution[] = {0, 1, 1, 0}`

This means:

* 'A' and 'D' are in block 0
* 'B' and 'C' are in block 1

The important point is:

> `solution[j]` is **not** a character — it's an integer indicating the group number. Even when working with character sets, `solution` must remain an `int[]` so it can safely index into arrays like `occurrences[]`.

---

## Code Breakdown

```c
#include <stdio.h>
#include <stdlib.h>
```

These are standard library includes:

* `stdio.h`: for input/output operations (e.g., `fprintf`).
* `stdlib.h`: for memory allocation (`calloc`) and exit handling (`exit`, `EXIT_SUCCESS`).

---

```c
int partition(int *, int *, int, int, int, int);
```

**Function Prototype:** Declares a recursive function named `partition` which returns an `int` and accepts:

* a value array (set elements),
* a solution array (partition index per element),
* `n`: total number of elements,
* `k`: number of partitions,
* `pos`: current position (index in recursion),
* `count`: current valid partition count.

---

```c
int main(int argc, char *argv[]) {
```

**Main function**. Arguments `argc` and `argv[]` are unused but follow standard C signature.

```c
    int value[4] = {1, 2, 3, 4};
```

Initializes the set to be partitioned.

```c
    int solution[4] = {0, 0, 0, 0};
```

Keeps track of partition index (block number 0 to k-1) for each element.

```c
    int n = 4, k = 2, pos = 0, count = 0;
```

Initial values:

* `n = 4`: number of elements
* `k = 2`: number of partitions (blocks)
* `pos = 0`: starting position in recursion
* `count = 0`: no valid partitions found yet

```c
    int i, total;
```

Local variables for loops and total partition count.

```c
    fprintf(stdout, "Partition (%d elements = ", n);
    for (i = 0; i < n; i++) {
        fprintf(stdout, "%d ", value[i]);
    }
    fprintf(stdout, ")\n\n");
```

Prints the elements being partitioned.

```c
    total = partition(value, solution, n, k, pos, count);
    fprintf(stdout, "\nTotal Number: %d\n", total);
```

Calls the recursive partition function and prints the total valid partitions found.

```c
    return EXIT_SUCCESS;
}
```

Exits successfully.

---

### Recursive Function: `partition`

```c
int partition(int *value, int *solution, int n, int k, int pos, int count) {
```

Recursive function to explore all combinations.

```c
    int i, j, end, *occurrences;
```

Local variables:

* `occurrences`: array to track if each partition has at least one element.
* `end`: flag to indicate invalid partitions.

```c
    if (pos >= n) {
```

Base case: all elements assigned.

```c
        occurrences = calloc(k, sizeof(int));
```

Dynamically allocate space to count how many elements are assigned to each block.

```c
        if (occurrences == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
```

Error handling for memory allocation.

```c
        for (j = 0; j < n; j++) {
            occurrences[solution[j]]++;
        }
```

Count number of elements in each block.

```c
        for (end = 0, j = 0; j < k && end == 0; j++) {
            if (occurrences[j] == 0) {
                end = 1;
            }
        }
```

Check if any block is empty; if yes, mark as invalid.

```c
        free(occurrences);
```

Clean up memory.

```c
        if (end == 1) {
            return count;
        }
```

Skip printing invalid partitions.

```c
        fprintf(stdout, "Partition %2d: ", count + 1);
        fprintf(stdout, "{ ");
        for (i = 0; i < n; i++) {
            fprintf(stdout, "%d ", solution[i]);
        }
        fprintf(stdout, "}  ->  ");
```

Print internal block assignment (`solution[]`).

```c
        for (i = 0; i < k; i++) {
            fprintf(stdout, "{ ");
            for (j = 0; j < n; j++) {
                if (solution[j] == i) {
                    fprintf(stdout, "%d ", value[j]);
                }
            }
            fprintf(stdout, "} ");
        }
        fprintf(stdout, "\n");
```

Print the actual partitioning of `value[]` based on `solution[]`.

```c
        return count + 1;
    }
```

Return updated count after printing.

---

```c
    for (i = 0; i < k; i++) {
        solution[pos] = i;
        count = partition(value, solution, n, k, pos + 1, count);
    }
```

Recursive call: try assigning current element (`pos`) to each of the `k` blocks.

```c
    return count;
}
```

Return total number of valid partitions found so far.

---

## Output

The output lists all valid (non-symmetric) partitions of the set `{1, 2, 3, 4}` into `k=2` blocks. It prints the partition vector and actual groupings, followed by the total number of valid partitions.

---

## Conclusion

This program exhaustively and recursively generates all valid partitions of a set into `k` non-empty subsets using arrangements with repetition. It's efficient for small `n` and `k`, and avoids symmetric duplicates.

You can extend this code for:

* Different values of `n` and `k`
* Filtering only symmetric-free partitions
* Output in a graphical format
* Parallelization for large sets
