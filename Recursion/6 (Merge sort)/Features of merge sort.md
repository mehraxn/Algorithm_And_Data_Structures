# 📚 Merge Sort

## 🔍 Overview

**Merge Sort** is a classic, efficient, and stable **divide-and-conquer** sorting algorithm. It divides the input array into two halves, recursively sorts them, and then merges the sorted halves to produce the final sorted array.

---

## ✨ Features

### ✅ Stable Sort
- Maintains the relative order of equal elements.
- Useful when the order of duplicate items matters.

### ✅ Divide-and-Conquer Strategy
- Splits the problem into smaller subproblems (subarrays), solves them recursively, and merges the results.
  
### ✅ Consistent Time Complexity
- Performs consistently well regardless of input (already sorted, reverse sorted, or random).
- No worst-case degradation like with Quick Sort.

### ✅ Efficient for Large Datasets
- Merge Sort has predictable performance and is especially good for sorting large files or lists.

### ✅ External Sorting
- Works well with external storage and large datasets that don’t fit into RAM because it processes data in chunks.

### ✅ Recursive and Iterative Versions
- Can be implemented using recursion or using an iterative bottom-up approach.

---

## ⏱️ Time and Space Complexity

| Complexity | Value        |
|------------|--------------|
| Time (Best) | `O(n log n)` |
| Time (Avg)  | `O(n log n)` |
| Time (Worst)| `O(n log n)` |
| Space       | `O(n)`       |

- **Time Complexity** is consistently `O(n log n)` because it always divides the array and merges in linear time.
- **Space Complexity** is `O(n)` due to the use of a temporary array during merging.

---

## 🔁 Recurrence Relation

The recursive behavior of merge sort can be expressed in the general divide-and-conquer form:

```
T(n) = D(n) + aT(n/b) + C(n)
```

### For Merge Sort:
- `a = 2` (we divide the array into two parts)
- `b = 2` (each part is half of the original)
- `D(n) = 0` (no significant work is done before the recursive calls)
- `C(n) = O(n)` (merging two sorted arrays takes linear time)

So, the recurrence becomes:
```
T(n) = 2T(n/2) + O(n)
```

### Solving the Recurrence:
Using the **Master Theorem**, we get:
- `T(n) = O(n log n)`

---

## 🔧 How It Works (Steps)

1. **Divide**: Split the array into two halves.
2. **Conquer**: Recursively sort both halves.
3. **Combine**: Merge the two sorted halves into one sorted array.

---

## 📌 Example

Input:
```
[38, 27, 43, 3, 9, 82, 10]
```

Steps:
```
Split → [38, 27, 43] and [3, 9, 82, 10]
Sort → [27, 38, 43] and [3, 9, 10, 82]
Merge → [3, 9, 10, 27, 38, 43, 82]
```

---

## 🛠️ Sample Code (C)

```c
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("Sorted array: \n");
    printArray(arr, arr_size);
    return 0;
}
```

---

## 📘 Conclusion

Merge Sort is a powerful sorting algorithm known for its stability, predictable performance, and suitability for large datasets. Its `O(n log n)` time complexity makes it an excellent choice for many applications, especially when stable sorting is required.

