# Permutations with Repetition - C Program

## Overview
This program generates all possible permutations of a given set of distinct values, where repetition is allowed up to a certain limit for each value. It uses a recursive approach combined with backtracking to achieve this, ensuring that every valid permutation is printed and counted.

The program contains two main functions:
- `perm_rep()`: Recursively generates permutations.
- `main()`: Sets up the initial values and calls `perm_rep()`.

## Files Included
- `permutations.c`: The source code of the C program that generates the permutations.

## Function Details

### `perm_rep()`
- **Purpose**: Generates all possible permutations with repetition allowed for a given set of distinct values (`val_dist`), of length `n`.
- **Parameters**:
  - `int *val_dist`: Array of distinct values to be used in permutations.
  - `int *sol`: Array used to store the current permutation.
  - `int *mark`: Array to track the remaining occurrences of each value in `val_dist`.
  - `int n`: Length of each permutation to generate.
  - `int n_dist`: Number of distinct values in `val_dist`.
  - `int count`: Keeps track of the number of valid permutations generated so far.
  - `int pos`: The current position in the permutation that needs to be filled.

- **Working**: The function works recursively by placing each possible value at a specific position (`pos`) in the permutation and moving to the next position (`pos + 1`).
  - **Base Case**: When all positions are filled (`pos >= n`), the current permutation is printed, and the count of permutations is incremented.
  - **Recursive Case**: For each possible value in `val_dist`, if occurrences are still available (`mark[i] > 0`), that value is placed in the current position (`sol[pos]`). The function then recurs for the next position, and the occurrence is restored afterward (backtracking).

- **Return Value**: The function returns the total number of permutations generated.

### `main()`
- **Purpose**: Initializes the required variables and calls the `perm_rep()` function to generate permutations.
- **Variables**:
  - `val_dist[]`: Array of distinct values (`{1, 2, 3}` in this case).
  - `n_dist`: The number of distinct values in `val_dist` (3).
  - `n`: Length of the permutations to generate (3).
  - `sol[]`: Array to store the current permutation.
  - `mark[]`: Array to track the remaining occurrences for each value in `val_dist` (all set to 1 initially).
  - `count`: Counter to keep track of the total number of permutations generated.

- **Working**: The `main()` function calls `perm_rep()` with initial values to generate all permutations. After all permutations are generated, it prints the total count.

## How to Compile and Run
1. Save the file as `permutations.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc permutations.c -o permutations
   ```
4. Run the compiled program:
   ```bash
   ./permutations
   ```

## Example Output
```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
Total permutations: 6
```

## Explanation of Key Concepts
- **Backtracking**: The program uses backtracking to explore all possible permutations. After placing an element, the function recurs to place the next one. Once all positions are filled, it backtracks by restoring the element's availability to explore other possibilities.
- **Recursive Function**: The `perm_rep()` function is recursive, meaning it calls itself to fill each position of the permutation until all positions are filled.

## Customization
- **Changing the Values**: To change the set of values to be permuted, modify the `val_dist` array in `main()`. For example, use `{4, 5, 6}` for different values.
- **Changing the Length of Permutation**: Modify the `n` variable in `main()` to change the length of each permutation.

## Limitations
- The current implementation only allows each distinct value to be used once (`mark[]` is initialized with `1` for each value). To allow more repetitions, increase the corresponding value in `mark[]`.
- The array sizes are hardcoded, so increasing the number of distinct values or the length of the permutation requires updating the respective variables accordingly.

## Conclusion
This program provides a basic demonstration of how to generate permutations with repetition using recursion and backtracking. It is useful for learning the principles of recursion, backtracking, and understanding how to systematically generate all possible combinations of a given set of values.

