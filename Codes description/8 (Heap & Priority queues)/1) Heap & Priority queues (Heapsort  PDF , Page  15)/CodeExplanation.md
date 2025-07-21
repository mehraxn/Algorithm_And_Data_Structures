# README: Understanding the `heapify` Function

## Overview

This document explains the `heapify` function implemented in C for maintaining the **max-heap property** in a binary heap data structure. It is typically used in **heap sort** or **priority queue** implementations.

---

## Function Signature

```c
void heapify(heap_t heap, int i)
```

* **heap\_t heap**: A pointer to the heap structure. It contains:

  * `heap->A`: An array of elements in the heap.
  * `heap->heapsize`: The number of elements currently in the heap.
* **int i**: The index of the current node to be heapified.

---

## Goal of `heapify`

The goal of this function is to ensure that the subtree rooted at index `i` maintains the **max-heap property**:

* The value of a parent node must be **greater than or equal to** its children.

If the node at index `i` violates this property, the function swaps it with its largest child and recursively calls itself on the affected subtree.

---

## Helper Functions (Assumed to Be Defined Elsewhere)

* `LEFT(i)`: Returns the index of the left child of node `i`. Usually: `2*i + 1`
* `RIGHT(i)`: Returns the index of the right child of node `i`. Usually: `2*i + 2`
* `item_greater(a, b)`: Returns true if `a` is greater than `b`.
* `swap(heap, i, j)`: Swaps the elements at indices `i` and `j` in the heap.

---

## Step-by-Step Explanation

```c
int l, r, largest;
l = LEFT(i);
r = RIGHT(i);
```

* Compute the indices of the left and right children of node `i`.

```c
if ((l < heap->heapsize) && (item_greater(heap->A[l], heap->A[i])))
    largest = l;
else
    largest = i;
```

* Check if the left child exists and is greater than the current node.
* If so, mark it as the largest; otherwise, keep `i` as the largest.

```c
if ((r < heap->heapsize) && (item_greater(heap->A[r], heap->A[largest])))
    largest = r;
```

* Check if the right child exists and is greater than the current largest value.
* If so, update `largest` to the index of the right child.

```c
if (largest != i) {
    swap(heap, i, largest);
    heapify(heap, largest);
}
```

* If the current node is not the largest, swap it with the largest child.
* Recursively call `heapify` on the new index to continue the process.

```c
return;
```

* Return from the function when the max-heap property is satisfied.

---

## Time Complexity

* **Worst-case**: O(log n)

  * Because it may recurse from the root to the leaf in a complete binary tree.

## Use Case

* Used in building a heap from an array (called heap construction)
* Used in heap sort after extracting the max element to restore the heap property

---

## Example

Given an array representing a binary tree:

```
Index:     0   1   2   3   4
Array:    [10, 5, 8, 3, 2]
```

* Call `heapify(heap, 1)`
* `LEFT(1) = 3`, `RIGHT(1) = 4`
* Children: 3 and 2, current value: 5
* No child is greater, so no swap
* Heap remains the same

---

## Summary

The `heapify` function is a fundamental part of heap operations. It ensures that a binary tree maintains the max-heap property by comparing a node with its children and recursively adjusting the subtree as needed. This logic is key in efficient algorithms like heap sort and in implementing priority queues.

---

## Notes

* Be careful to check that child indices are within the current heap size.
* Always use recursive or iterative calls carefully to prevent stack overflow in deep trees (not common in heaps due to log n depth).
* Works only if the underlying array truly represents a heap or partial heap.

---

End of README.
