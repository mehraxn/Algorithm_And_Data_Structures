# README: Multiplication Principle Combination Generator

## Overview

This program uses **the multiplication principle** from combinatorics to generate all possible words by taking **exactly one character** from each of a set of given strings. The code recursively explores every combination and prints them, along with a total count.

---

## The Multiplication Principle

In combinatorics, the multiplication principle states:

> If there are `a` ways to choose one item from set 1, `b` ways from set 2, ..., and `n` ways from set N, then the total number of ways to make one selection from each set is:

```
Total combinations = a × b × ... × n
```

This code applies that principle programmatically.

---

## Code Walkthrough

### 1. Struct Definition

```c
typedef struct array {
    char *string;
} array;
```

* Defines a structure `array` containing a single field `string`, which is a pointer to a character array (C-string).
* This lets us store multiple strings in an array of `array` structs.

### 2. Recursive Function: `multiplication_principles`

```c
int multiplication_principles(array *array1, char *solution, int n, int count, int pos)
```

* **`array1`**: The array of strings to pick characters from.
* **`solution`**: A character array storing the current word being built.
* **`n`**: Number of strings.
* **`count`**: Keeps track of how many complete words have been generated so far.
* **`pos`**: The index of the current string we are picking a character from.

#### Base Case:

```c
if (pos >= n) {
    solution[pos] = '\0';  // Null-terminate the word
    printf("%s\n", solution);
    return count + 1;
}
```

* If `pos` reaches `n`, we've chosen one character from each string.
* Null-terminate `solution` so it becomes a valid C-string.
* Print the completed word.
* Return `count + 1` to increment the total combinations count.

#### Recursive Case:

```c
for (i = 0; i < (int)strlen(array1[pos].string); i++) {
    solution[pos] = array1[pos].string[i];
    count = multiplication_principles(array1, solution, n, count, pos + 1);
}
```

* Loop over every character in the current string (`array1[pos].string`).
* Place that character in `solution[pos]`.
* Recursively call `multiplication_principles` for the next position (`pos + 1`).
* The recursion continues until the base case is reached.

---

### 3. Main Function

```c
int main() {
    array arr[7] = {
        {"ALI"},
        {"HASSAN"},
        {"MAHMOUD"},
        {"KARIM"},
        {"ASLAN"},
        {"MEHRAN"},
        {"HAMED"}
    };

    char solution[100]; // Enough space for max length
    int total = multiplication_principles(arr, solution, 7, 0, 0);

    printf("Total combinations: %d\n", total);
    return 0;
}
```

* Initializes `arr` with 7 strings.
* Declares `solution` to store combinations.
* Calls `multiplication_principles` starting at position 0 with an initial count of 0.
* Prints the total number of combinations generated.

---

## Algorithm Complexity

* **Time Complexity**: O(L₁ × L₂ × ... × Lₙ) where Lᵢ is the length of the i-th string. This is because we try every possible character at every position.
* **Space Complexity**: O(n) for the recursion stack and O(max\_length) for `solution`.

---

## Example

If the strings are:

```
{"AB"}, {"CD"}, {"E"}
```

The program will generate:

```
ACE
ADE
BCE
BDE
```

Total combinations = 2 × 2 × 1 = 4.
