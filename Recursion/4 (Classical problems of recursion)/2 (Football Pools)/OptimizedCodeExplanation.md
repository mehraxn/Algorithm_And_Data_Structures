# README - Football Pool Pattern Generator

## Overview

This project solves a classic recursive problem related to football match prediction patterns. The goal is to generate all possible match result patterns based on a predefined set of possible outcomes for each match.

### Problem Context

In football pools, each match can result in:

* `1`: Home team wins
* `2`: Home team loses
* `X`: Match ends in a draw

The input is a file where each line represents a match and contains the possible outcomes for that match. The task is to generate and print all valid combinations of match results.

---

## Features

* Reads an input file containing possible results per match
* Determines the number of matches from the file
* Recursively generates and prints all valid result combinations

---

## Example

### Input File:

```
1
1
X2
2
12X
```

This specifies:

* Match 1: only possible result is 1
* Match 2: only possible result is 1
* Match 3: either X or 2
* Match 4: only possible result is 2
* Match 5: 1, 2, or X

### Output:

```
11X21
11X22
11X2X
11221
11222
1122X
```

Each line represents one valid combination of match results.

---

## Code Explanation

### Main Components:

* `dim(char *file_name)`

  * Counts how many lines (matches) are in the input file.

* `char **read_file(char *file_name, int *dimension)`

  * Reads the input file and stores each line (string of possible outcomes) in a dynamically allocated array.

* `void generate_patterns(char **matrix, char *result, int pos, int dimension)`

  * Recursive function to build combinations:

    * At each recursion step, it appends one of the possible outcomes for the current match.
    * Once a complete result (length == number of matches) is formed, it is printed.

* `main()`

  * Manages the program flow:

    1. Prompts the user for file name
    2. Calls `read_file` to load possible outcomes
    3. Uses `generate_patterns` to print all combinations

---

## Type of Combination Used

This program uses the **Cartesian Product**, which is a type of combination (not permutation):

* For each match, it considers a set of possible outcomes (e.g., "1", "2", "X")
* Generates all possible sequences by choosing one item from each match's outcome set
* This is a classic example of **combinatorics without repetition** where the order of positions (matches) matters, but the elements (choices per match) are selected independently

The recursion mimics nested loops: for each match index, it loops through its available options and continues recursively to the next match.

This is not a permutation because we do not rearrange a fixed set of items, and it is not a combination in the mathematical sense (e.g., choosing k items from n), but rather a Cartesian product of character sets.

Example:
If input is:

```
1
X2
```

The Cartesian product is:

* `1X`
* `12`

---

## Memory Management

* Uses dynamic allocation (`malloc`) to build the matrix storing match outcomes
* Frees all memory after usage to prevent leaks

---

## How to Run

1. Compile using:

   ```bash
   gcc -o football_pool football_pool.c
   ```
2. Prepare an input file with one line per match, listing possible outcomes
3. Run the program:

   ```bash
   ./football_pool
   ```
4. Enter the file name when prompted

---

## Notes

* The number of combinations grows exponentially with the number of matches and possible outcomes per match
* Recursive approach is well-suited for generating combinatorial sequences like this

---

## Enhancements (Optional)

* Handle invalid inputs more gracefully
* Support writing output to a file
* Add command-line arguments for automation

---

## License

Free to use for learning and educational purposes.
