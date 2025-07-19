# 🤩 Partitioning a Set into Two Subsets

## 📝 Problem Description

Given a set of 4 elements:

```
value = {1, 2, 3, 4}
```

Your task is to write a program that generates **all possible partitions** of these elements into **2 non-empty subsets**, following a specific rule:

* Each element is assigned to either subset 1 or subset 2.
* The assignment can be represented using a binary vector, e.g., `{0001}` means elements `{1, 2, 3}` are in one subset, and `{4}` is in the other.
* You **do not** need to eliminate symmetric partitions (i.e., `{123}, {4}` and `{4}, {123}` are both valid and distinct).

---

## 💡 Example Partitions

Here are the 14 possible partitions of the set `{1, 2, 3, 4}` into 2 subsets:

| Partition | Binary Representation | Subset 1  | Subset 2  |
| --------: | --------------------- | --------- | --------- |
|         1 | `{0001}`              | `{1,2,3}` | `{4}`     |
|         2 | `{0010}`              | `{1,2,4}` | `{3}`     |
|         3 | `{0011}`              | `{1,2}`   | `{3,4}`   |
|         4 | `{0100}`              | `{1,3,4}` | `{2}`     |
|         5 | `{0101}`              | `{1,3}`   | `{2,4}`   |
|         6 | `{0110}`              | `{1,4}`   | `{2,3}`   |
|         7 | `{0111}`              | `{1}`     | `{2,3,4}` |
|         8 | `{1000}`              | `{2,3,4}` | `{1}`     |
|         9 | `{1001}`              | `{2,4}`   | `{1,3}`   |
|        10 | `{1010}`              | `{2,3}`   | `{1,4}`   |
|        11 | `{1011}`              | `{2}`     | `{1,3,4}` |
|        12 | `{1100}`              | `{3,4}`   | `{1,2}`   |
|        13 | `{1101}`              | `{3}`     | `{1,2,4}` |
|        14 | `{1110}`              | `{4}`     | `{1,2,3}` |

---

## ✅ Requirements

* Generate **all 14 partitions** (do not eliminate symmetric duplicates).
* Represent the output clearly, showing which elements belong to each subset.
* Do **not** worry about sorting or minimizing symmetrical results.

---

## 🛠️ Suggested Output Format

```
Partition 1: {1, 2, 3} | {4}
Partition 2: {1, 2, 4} | {3}
...
Partition 14: {4} | {1, 2, 3}
```

---

## 📌 Note

While there are only 7 unique partitions if we ignore symmetric blocks, for this task you are required to **list all 14**, treating `{A} | {B}` and `{B} | {A}` as **different**.
