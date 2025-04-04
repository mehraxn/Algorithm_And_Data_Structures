# Permutation Generation with Recursion

## Overview

This project is a simple implementation of a program that generates all possible permutations of a given set of integers. It uses recursion combined with backtracking to explore all possible arrangements. The goal of this program is to demonstrate a fundamental concept in combinatorics—finding all permutations of a set—and to showcase a common recursive approach for solving such problems.

## How the Code Works

The program consists of two main components:

1. **The `perm` Function**: This is the core of the program, which recursively generates permutations by choosing elements from the input set, placing them in a solution array, and ensuring that each element is used only once per permutation. The function uses backtracking to explore all possible choices for each position in the permutation.

2. **The `main` Function**: This function initializes the input array and other variables, then calls the `perm` function to generate all permutations. It also prints the total number of permutations found.

## Detailed Function Descriptions

### 1. `perm(int *val, int *sol, int *mark, int n, int count, int pos)`

- **Purpose**: This function generates all possible permutations of the given input array using recursion.
- **Parameters**:
  - `int *val`: The input array of values to be permuted.
  - `int *sol`: The solution array that stores the current permutation.
  - `int *mark`: The array used to mark if an element is already included in the current permutation.
  - `int n`: The number of elements in the input array.
  - `int count`: A counter to keep track of the number of valid permutations generated.
  - `int pos`: The current position in the permutation that we are filling.
- **How It Works**:
  - The function first checks if all positions are filled (`pos >= n`). If so, it prints the current permutation and increments the count of valid permutations.
  - It then iterates over all elements in the input array, checking if they are already used in the current permutation.
  - If an element is not used, it marks the element, places it in the solution array, and recursively proceeds to fill the next position.
  - After each recursive call, it backtracks by unmarking the element so it can be used in other permutations.

### 2. `main()`

- **Purpose**: The `main` function initializes the input array, sets up auxiliary arrays, and starts the permutation generation process.
- **Steps**:
  - Initializes the input array (`val`) containing the elements to be permuted.
  - Calculates the number of elements (`n`) in the input array.
  - Creates two arrays—`sol` for storing the current permutation and `mark` to track used elements.
  - Initializes all elements of `mark` to zero, indicating that no elements are used initially.
  - Calls the `perm` function to generate all permutations starting from position 0.
  - Finally, it prints the total number of permutations generated.

## Backtracking Explanation

Backtracking is a general algorithmic technique for finding all (or some) solutions to computational problems that incrementally builds candidates to the solutions and abandons a candidate as soon as it determines that the candidate cannot possibly be completed to a valid solution.

In this program:
- We **mark** an element as used, place it in the current permutation (`sol`), and then recursively proceed to the next position.
- If we reach a complete permutation, we print it.
- After completing a permutation or reaching a state where no more elements can be added, we **unmark** the current element to allow it to be used in other possible permutations.

## Example

Consider the input array `{1, 2, 3}`:

1. The program starts with an empty solution array and iterates over the possible choices for the first position.
2. It places `1` in the first position, marks it as used, and proceeds to fill the next position.
3. Next, it places `2` in the second position, and so on, until a complete permutation (`1, 2, 3`) is generated.
4. The program then backtracks, unmarking `3` to explore other options for the last position, such as `2` and `1`.
5. This continues until all permutations (`1, 2, 3`, `1, 3, 2`, `2, 1, 3`, etc.) are generated.

## Compilation and Running

To compile and run this program:

1. Save the code to a file, for example, `perm.c`.
2. Compile it using a C compiler like `gcc`:
   ```
   gcc perm.c -o perm
   ```
3. Run the compiled program:
   ```
   ./perm
   ```

## Output

The program will print all possible permutations of the input array and display the total count at the end. For example, with the input `{1, 2, 3}`, the output will be:
```
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
Total permutations: 6
```

## Complexity

- **Time Complexity**: The time complexity of generating all permutations is `O(n!)`, where `n` is the number of elements in the input array. This is because there are `n!` possible permutations of `n` elements.
- **Space Complexity**: The space complexity is `O(n)` for storing the solution and mark arrays, plus the recursion stack.

## Summary

This program demonstrates the use of recursion and backtracking to generate all permutations of a given set of integers. By marking elements as used and then unmarking them during backtracking, it efficiently explores all possible arrangements, making it a good example of a classic combinatorial algorithm.