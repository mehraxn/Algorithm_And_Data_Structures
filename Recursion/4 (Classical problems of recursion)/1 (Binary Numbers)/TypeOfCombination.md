# Binary Numbers Generator - README

## Overview

This program generates all possible binary numbers of a specified bit length **n** using a recursive approach. The user provides **n** as input, and the program prints all **2^n** binary numbers, each of exactly **n** bits.

Example: For **n = 3**, the program prints:

```
000
001
010
011
100
101
110
111
```

## Key Requirements Fulfilled

* Input: User inputs number of bits (**n**).
* Output: All binary numbers with **n** bits.
* Technique: **Recursive generation**.
* Memory: **Dynamically allocated array** to hold the bit values.

---

## ❓ What Kind of Combinatorics Is This?

> **This project implements *Permutations With Repetition***.

### 📄 Definition:

* You are selecting **n elements** (bits) where **each element can be repeated**.
* The source set is `{0, 1}` (two elements).
* All positions are filled **independently** from this set.
* **Order matters**, so `010` is different from `100`.

This results in `2^n` total combinations.

---

## Complete Code Explanation

```c
#include <stdio.h>
#include <stdlib.h>
```

* `#include <stdio.h>`: Required for input/output operations (`scanf`, `printf`, etc.).
* `#include <stdlib.h>`: Provides functions for memory allocation (`malloc`, `free`) and program control (`exit`).

```c
#define BASE 2
```

* Defines the base used in binary number generation (base 2: digits are 0 and 1).

```c
void binary_r(int *array, int depth, int n);
```

* Function prototype for the recursive binary number generator.

---

### `main()` Function

```c
int main(void) {
    int n, *array;
```

* Declares `n` for number of bits.
* Declares pointer `array` for dynamic array to store current binary digits.

```c
    fprintf(stdout, "Number of bits: ");
    scanf("%d", &n);
```

* Prompts the user for input.
* Reads value of `n` from standard input.

```c
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
```

* Dynamically allocates memory for an array of `n` integers.
* Checks if allocation failed and exits with error message if so.

```c
    fprintf(stdout, "Binary numbers\n");
    binary_r(array, 0, n);
```

* Prints header for output.
* Calls the recursive function `binary_r()` to begin generation with depth = 0.

```c
    free(array);
    return EXIT_SUCCESS;
}
```

* Frees the allocated memory.
* Returns success code (0).

---

### Recursive Function: `binary_r()`

```c
void binary_r(int *array, int depth, int n) {
    int i;
```

* Takes the current bit array, current recursion depth, and bit length `n` as parameters.
* Declares local loop variable `i`.

```c
    if (depth >= n) {
        for (i = 0; i < n; i++) {
            fprintf(stdout, "%d", array[i]);
        }
        fprintf(stdout, "\n");
        return;
    }
```

* Base case: When `depth == n`, the array holds a complete binary number.
* Prints the current binary number stored in `array`.
* Returns from the function.

```c
    for (i = 0; i < BASE; i++) {
        array[depth] = i;
        binary_r(array, depth + 1, n);
    }
}
```

* Recursive step:

  * Iterates over binary digits 0 and 1 (`BASE = 2`).
  * Sets the current bit (`array[depth]`) to 0 or 1.
  * Recursively calls itself with the next depth level.

---

## Summary

* This program recursively builds each binary number by exploring all possibilities (0 and 1) at each bit position.
* It uses dynamic memory allocation to ensure flexibility for user-defined input size `n`.
* The recursive function mimics a tree structure to enumerate all `2^n` combinations.
* This is a classic example of **permutations with repetition**, where elements are selected independently and may repeat.

---

## Sample Output

```
Number of bits: 2
Binary numbers
00
01
10
11
```

This program efficiently demonstrates recursion, dynamic memory management, and combinatorial logic in C.
