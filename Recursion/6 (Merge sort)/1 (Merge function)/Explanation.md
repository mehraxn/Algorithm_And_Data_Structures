# README: Understanding the `merge` Function in C

## Overview
This README explains the `merge` function written in C that merges two **already sorted arrays** (`v1` and `v2`) into a third array (`v3`) in sorted order. This is a classic operation used in merge sort and other algorithms where merging sorted data is required.

---

## Function Signature
```c
void merge(int * v1 , int * v2 , int * v3 , int n);
```
- **v1**: Pointer to the first sorted array of size `n`.
- **v2**: Pointer to the second sorted array of size `n`.
- **v3**: Pointer to the destination array of size `2n`.
- **n**: The number of elements in each of the source arrays `v1` and `v2`.

---

## How It Works
### 1. **Initialization**
```c
int i1=0 , i2=0 , i3=0;
```
These are index variables for `v1`, `v2`, and `v3` respectively.

### 2. **Main Loop (Comparing Elements)**
```c
while (i1<n && i2<n) {
    if (v1[i1] < v2[i2])
        v3[i3++] = v1[i1++];
    else
        v3[i3++] = v2[i2++];
}
```
This loop continues as long as both arrays have elements left. The function compares the current elements of `v1` and `v2`, and copies the smaller one to `v3`. It maintains the sorted order.

### 3. **Copy Remaining Elements**
Once one of the arrays is exhausted, the remaining elements of the other array are directly copied into `v3`:
```c
while (i2<n)
    v3[i3++] = v2[i2++];

while (i1<n)
    v3[i3++] = v1[i1++];
```
This ensures all elements from both arrays are merged into `v3`.

---

## Example
### Input:
```c
v1 = {1, 3, 5};
v2 = {2, 4, 6};
n = 3;
```
### Output:
```c
v3 = {1, 2, 3, 4, 5, 6};
```

---

## Properties
- **Time Complexity**: O(n) for each array, so total O(2n) = O(n).
- **Space Complexity**: Requires a third array of size `2n`.
- **Stability**: The current implementation is **not stable** if `v1[i1] == v2[i2]`, because it picks `v2` first. To make it stable, use `<=` instead of `<` in the comparison.

---

## Conclusion
This `merge` function is a simple and efficient way to merge two pre-sorted arrays into a single sorted array. It assumes both arrays have the same size `n` and works in linear time. It is an essential building block in algorithms like merge sort.

