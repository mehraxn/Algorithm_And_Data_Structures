# Understanding the `occurrences` Array in Partitioning C Program

## Purpose of the `occurrences` Array

In the C program that partitions a set into `k` blocks, the `occurrences` array plays a crucial role in **validating each partition**.

Its purpose is to:

* Count how many elements are assigned to each of the `k` blocks
* **Reject any partition where one or more blocks are empty**

This ensures that only **non-empty, complete partitions** are printed and counted.

---

## Where It Appears in Code

Inside the recursive `partition()` function:

```c
if (pos >= n) {
    occurrences = calloc(k, sizeof(int));
    ...
    for (j = 0; j < n; j++) {
        occurrences[solution[j]]++;
    }
    for (j = 0; j < k; j++) {
        if (occurrences[j] == 0) {
            // Invalid partition
            return count;
        }
    }
    // Valid partition, print it
}
```

---

## Detailed Example

### Assume:

* `value[] = {1, 2, 3, 4}`
* `n = 4`, `k = 2`
* One possible `solution[] = {0, 1, 1, 0}`

This means:

* `1 → block 0`
* `2 → block 1`
* `3 → block 1`
* `4 → block 0`

### Step-by-Step: How `occurrences[]` Is Populated

Start:

```c
occurrences = calloc(2, sizeof(int));  // {0, 0}
```

Loop through `solution[]`:

```c
for (j = 0; j < 4; j++) {
    occurrences[solution[j]]++;
}
```

Walkthrough:

* j = 0 → `solution[0] = 0` → `occurrences[0]++` → `{1, 0}`
* j = 1 → `solution[1] = 1` → `occurrences[1]++` → `{1, 1}`
* j = 2 → `solution[2] = 1` → `occurrences[1]++` → `{1, 2}`
* j = 3 → `solution[3] = 0` → `occurrences[0]++` → `{2, 2}`

Final `occurrences[] = {2, 2}`

### Validity Check:

Loop through `occurrences[]`:

```c
for (j = 0; j < 2; j++) {
    if (occurrences[j] == 0) return count;
}
```

All entries are non-zero → partition is **valid** and printed.

---

## What If a Block Is Empty?

Try: `solution[] = {0, 0, 0, 0}` → all elements in block 0

Results in:

* `occurrences[] = {4, 0}`

Block 1 is empty → skipped.

```c
if (occurrences[1] == 0) → return count;  // Not printed
```

---

## Summary

| Concept          | Meaning                                                |
| ---------------- | ------------------------------------------------------ |
| `solution[j]`    | Tells which block value\[j] goes into                  |
| `occurrences[i]` | Counts how many items go into block `i`                |
| Empty block      | If any `occurrences[i] == 0`, the partition is invalid |

The `occurrences[]` array is a simple but powerful way to enforce that each partition has at least one element in every block — which is a core requirement for valid set partitions in this context.
