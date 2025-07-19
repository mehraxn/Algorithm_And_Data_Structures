# Recursive Alphabetic String Generator - README

## 📄 Project Title

**Recursive Alphabetic String Generator with Vowel Constraint**

---

## ✅ Task Description

Write a program that **generates all possible alphabetic strings of a given length** using a custom character set provided by the user. The program must use **recursion** and **dynamic memory allocation** to build strings that follow a specific pattern constraint.

---

## 🔍 Inputs

1. **An integer `n`** — the length of strings to generate (e.g., 3, 4, 5).
2. **A string of characters** — custom character set provided by the user (e.g., `abcde`, `pqrs`, `aeiouxyz`).

---

## 🔚 Output

* Print **all valid strings** of length `n` that can be formed using the character set and satisfy the **vowel-consonant constraint**.
* Each valid string is printed on a new line.

---

## ✅ Constraints

1. **Length (`n`) must be a positive integer** (n ≥ 3 for constraints to apply meaningfully).

2. **Character set must not be empty**.

3. **Only valid strings should be printed**, which meet the following rule:

   > **Vowel Constraint:** Whenever **two vowels** appear in a string, there must be **exactly one non-vowel (consonant or other)** character between them.

   Examples:

   * Valid: `apa`, `ipi`, `oru`, `eze`
   * Invalid: `aei`, `aou`, `eai` (two vowels adjacent without a non-vowel in between)

4. Treat the following as **vowels**: `a, e, i, o, u`

---

## 💡 Recursive Strategy

* Use recursion to build strings character-by-character.
* Maintain a dynamic array (string) to track the current combination.
* At each recursive step:

  * Add one character from the character set.
  * Validate the partial string based on the vowel constraint.
* Once a valid string of length `n` is formed, print it.

---

## ✋ Hints

* Use a helper function to check if a character is a vowel.
* Use a recursive function `generate(int depth, int n, char* charset, char* current)`.
* Validate partial strings efficiently to prune invalid paths early.

---

## 📉 Example

**Input:**

```
Length of strings: 3
Character set: api
```

**Output:**

```
apa
ipi
```

Explanation:

* `apa` is valid: 'a' (vowel) - 'p' (non-vowel) - 'a' (vowel)
* `ipi` is valid: 'i' (vowel) - 'p' (non-vowel) - 'i' (vowel)
* `aai` is invalid (two vowels together)

---

## 🚀 Advanced Challenge

* Optimize for large character sets and high `n` values.
* Consider parallelizing recursive calls or caching partial results (optional).

---

## 🔄 Summary

This task tests your skills in:

* Recursion
* Constraint-based generation
* Dynamic memory management
* Character pattern analysis

It's a step up in difficulty from simple binary generation and introduces **context-aware recursive exploration**.

---

Would you like the full implementation of this in C as well?
