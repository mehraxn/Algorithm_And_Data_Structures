# Priority Queue Implementation in C: From A to Z (0-Based Indexing)

## Table of Contents

1. [Introduction](#introduction)
2. [Data Structures](#data-structures)
3. [Macros and Helper Functions](#macros-and-helper-functions)
4. [pq\_insert: Insertion Algorithm (0-Based Heap)](#pq_insert-insertion-algorithm-0-based-heap)

   * [Step-by-Step Explanation](#step-by-step-explanation)
   * [Time Complexity](#time-complexity)
5. [Complete API Overview](#complete-api-overview)
6. [Usage Example](#usage-example)
7. [Implementation Considerations](#implementation-considerations)
8. [Memory Management and Error Handling](#memory-management-and-error-handling)
9. [Best Practices and Caveats](#best-practices-and-caveats)
10. [License](#license)

---

## Introduction

A **priority queue** is an abstract data type similar to a queue or stack, but each element has a "priority". Elements with higher priority are served before those with lower priority. A **binary heap** is a common implementation, offering efficient insertion and removal.

This README focuses on a **0-based** binary-heap priority queue in C, detailing the `pq_insert` function, supporting macros, and best practices.

---

## Data Structures

```c
// Opaque pointer for the priority queue
typedef struct priority_queue* pq_t;

// Item stored in the queue; e.g., a struct or primitive type
typedef SomeType Item;

struct priority_queue {
    Item *A;      // 0-based array storage for the heap
    int pqsize;   // Number of elements currently in the heap
    int capacity; // Total allocated capacity of A
};
```

* **A**: Array representing the heap; using **0-based** indexing means the root is at index 0.
* **pqsize**: Current element count (0 ≤ pqsize ≤ capacity).
* **capacity**: Maximum number of elements before needing to resize.

---

## Macros and Helper Functions

```c
// Parent, left child, and right child for 0-based indexing
#define PARENT(i)  (((i) - 1) / 2)
#define LEFT(i)    (2 * (i) + 1)
#define RIGHT(i)   (2 * (i) + 2)

// Comparison function: returns true if *a < *b* under the chosen heap policy
bool item_less(const Item *a, const Item *b);
```

* **PARENT(i)**: Calculates the parent index `(i - 1) / 2`; valid when `i > 0`.
* **LEFT(i)**, **RIGHT(i)**: Compute the child indices for node `i` in a 0-based heap.

### Implementation of `item_less`

The `item_less` function encapsulates the priority comparison logic for your heap. In a **max-heap**, it returns `true` when the priority of `*a` is strictly less than the priority of `*b`, so that during insertion or removal, higher-priority items "bubble" toward the top. For a **min-heap**, you would invert this comparison.

A typical signature and implementation might look like:

```c
// Example Item structure with a priority field
typedef struct {
    int priority;
    // other fields...
} Item;

// Returns true if a has lower priority than b (max-heap)
bool item_less(const Item *a, const Item *b) {
    return a->priority < b->priority;
}
```

**Key points**:

* Compare only the fields that determine ordering (e.g., `priority`).
* Use a strict comparison (`<` or `>`), not `<=`, to maintain heap invariant and prevent infinite loops during bubbling.
* If items can have equal priority and you require a stable ordering, include a tie-breaker (e.g., insertion timestamp) in the comparison.

---

## pq\_insert: Insertion Algorithm (0-Based Heap)

```c
void pq_insert(pq_t pq, Item item) {
    int i;

    // 1. Append item at the end of the array
    i = pq->pqsize++;

    // 2. Bubble-up: move item toward the root until heap property is restored
    while (i > 0 && item_less(&pq->A[PARENT(i)], &item)) {
        pq->A[i] = pq->A[PARENT(i)];  // Move parent down
        i = PARENT(i);               // Move up to parent index
    }

    // 3. Place the new item at its correct position
    pq->A[i] = item;
}
```

### Step-by-Step Explanation

1. **Append**: The new `item` is conceptually appended at the end of the heap array. We record its index `i` as the old `pqsize`, then increment `pqsize`.
2. **Bubble-up**: While `i > 0` (not at root) and the parent's key is less than the new item:

   * Copy the parent node down to position `i`.
   * Update `i` to the parent's index (calculated via `PARENT(i)`).
3. **Insert**: Finally, assign `item` to `A[i]`, placing it at the correct heap position.

This maintains the **max-heap property**: each parent’s priority ≥ its children’s priorities.

### Time Complexity

* **Worst-case**: O(log n), where *n* = `pqsize`, since the item may travel from a leaf to the root.
* **Amortized**: O(1), because most insertions stop before reaching the top.

---

## Complete API Overview

```c
pq_t pq_init(int capacity);
void  pq_insert(pq_t pq, Item item);
Item  pq_extract_max(pq_t pq);
Item  pq_peek_max(const pq_t pq);
bool  pq_is_empty(const pq_t pq);
void  pq_destroy(pq_t pq);
```

* **pq\_init**: Allocates and initializes a new priority queue with given capacity.
* **pq\_extract\_max**: Removes and returns the item with highest priority, then re-heapifies downward.
* **pq\_peek\_max**: Returns the highest-priority item without removing it.
* **pq\_is\_empty**: Checks if the queue is empty.
* **pq\_destroy**: Frees the heap array and the `pq` structure.

---

## Usage Example

```c
#include "priority_queue.h"
#include <stdio.h>

int main() {
    pq_t pq = pq_init(16);
    pq_insert(pq, make_item(5));
    pq_insert(pq, make_item(10));
    pq_insert(pq, make_item(3));

    while (!pq_is_empty(pq)) {
        Item top = pq_extract_max(pq);
        printf("Extracted: %d\n", top.priority);
    }

    pq_destroy(pq);
    return 0;
}
```

---

## Implementation Considerations

* **0-based indexing**: Root at index 0; allocate `capacity` elements.
* **Resizing**: If `pqsize == capacity`, double the array with `realloc`.
* **Heap type**: Swap sign in `item_less` for a min-heap.
* **Thread-safety**: Not inherently safe; external locking needed for concurrency.

---

## Memory Management and Error Handling

* **Allocation checks**: Verify `malloc`/`realloc` succeed in `pq_init` and resizing.
* **Cleanup**: `pq_destroy` must free both `A` and the `pq` struct.
* **Error reporting**: Consider replacing `void` returns with error codes.

---

## Best Practices and Caveats

* **Edge cases**: Test on empty and full queues.
* **Stability**: Heaps are not stable; equal priorities can reorder.
* **Alternatives**: For frequent merges, consider pairing or Fibonacci heaps.
* **Benchmarking**: Use profiling to confirm O(log n) behavior on large inputs.

---

## License

Distributed under the MIT License. See `LICENSE` for details.
