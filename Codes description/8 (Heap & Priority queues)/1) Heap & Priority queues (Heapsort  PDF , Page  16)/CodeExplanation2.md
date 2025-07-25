# `heapify` Function Explanation

This document explains the purpose and inner workings of the `heapify` function shown in the image, and describes the role of the helper `item_greater` comparator.

---

## Code Listing

```c
void heapify(heap_t heap, int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    // Step 1: Compare current node with left child
    if ((l < heap->heapsize) &&
        item_greater(heap->A[l], heap->A[i]))
        largest = l;
    else
        largest = i;

    // Step 2: Compare the larger of (current, left) with right child
    if ((r < heap->heapsize) &&
        item_greater(heap->A[r], heap->A[largest]))
        largest = r;

    // Step 3: If the largest is not the current node, swap and recurse
    if (largest != i) {
        swap(heap, i, largest);
        heapify(heap, largest);
    }
}
```

---

## Purpose of `heapify`

`heapify` restores the **heap property** in a subtree rooted at index `i` of a heap stored in an array `heap->A`. A heap requires that each parent node compares "greater" (or "smaller" for min-heaps) than its children. When a node at `i` may violate this, `heapify` "sifts down" the element at `i` by swapping it with its largest (or smallest) child until the subtree becomes a valid heap.

### Detailed Steps

1. **Compute child indices**

   ```c
   int l = LEFT(i);   // index of left child = 2*i + 1
   int r = RIGHT(i);  // index of right child = 2*i + 2
   ```
2. **Find the largest (or "winner")**

   * Initialize `largest` to the index of the larger between the node at `i` and its left child.
   * Then compare the current `largest` with the right child to get the final `largest` index.
3. **Swap and recurse**

   * If `largest != i`, the node at `i` is out of place.
   * Call `swap(heap, i, largest)` to exchange the two elements.
   * Recursively call `heapify(heap, largest)` on the child index where the swap occurred, to continue restoring the heap property.

This process ensures that the subtree rooted at `i` becomes a valid heap, assuming its children were already valid heaps.

---

## Role of `item_greater`

The function `item_greater(a, b)` abstracts the comparison logic between heap elements. Instead of using a fixed operator (`>` or `<`), it:

* **Returns `true`** if `a` should be considered "greater" than `b` under the desired heap order.
* **Enables max-heap behavior** when implemented as:

  ```c
  bool item_greater(int a, int b) {
      return a > b;
  }
  ```
* **Enables min-heap behavior** when implemented as:

  ```c
  bool item_greater(int a, int b) {
      return a < b;
  }
  ```
* **Supports custom ordering** (e.g., comparing struct fields, or composite keys).

By using `item_greater`, `heapify` becomes **modular** and **reusable** across different comparison semantics.

---

## Example

Given the array representation of a max-heap:

```
Index: 0  1  2  3  4  5
Value: 1  5  3  4  2  6
```

Calling `heapify(heap, 0)` will:

1. Compare `A[0]=1` with `A[1]=5` → `largest = 1`
2. Compare `A[1]=5` with `A[2]=3` → `largest` remains `1`
3. Swap `A[0]` and `A[1]` → array becomes `[5, 1, 3, 4, 2, 6]`
4. Recurse on index `1`, continuing until the subtree is valid.

The final heap after restoration will satisfy the max-heap property for all nodes.
