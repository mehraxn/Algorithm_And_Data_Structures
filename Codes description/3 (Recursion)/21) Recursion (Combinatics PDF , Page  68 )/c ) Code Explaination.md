# Permutations and Combinations with Repetition - C Program

## Overview
This program generates all possible permutations and combinations of a given set of distinct values, where repetition is allowed. It uses a recursive approach combined with backtracking to achieve this, ensuring that every valid permutation or combination is printed and counted.

The program contains two main functions:

- `perm_rep()`: Recursively generates permutations.
- `comb_rep()`: Recursively generates combinations.
- `main()`: Sets up the initial values and calls the appropriate function based on the user's choice.

## Files Included

- `combinations_permutations.c`: The source code of the C program that generates the permutations and combinations.

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

### `comb_rep()`

- **Purpose**: Generates all possible combinations with repetition allowed for a given set of distinct values (`val_dist`), of length `k`.

- **Parameters**:
  - `int *val`: Array of distinct values to be used in combinations.
  - `int *sol`: Array used to store the current combination.
  - `int n`: Number of distinct values in `val`.
  - `int k`: Length of each combination to generate.
  - `int start`: Starting index for each iteration, ensuring that values are considered from this point onward to maintain the order of combinations.
  - `int count`: Keeps track of the number of valid combinations generated so far.
  - `int pos`: The current position in the combination that needs to be filled.

- **Working**: The function works recursively by iterating through each value in `val` from the `start` index onwards, placing it in the current position (`pos`), and then moving to the next position (`pos + 1`).

  - **Base Case**: When all positions are filled (`pos >= k`), the current combination is printed, and the count of combinations is incremented.
  - **Recursive Case**: For each possible value from `start` onwards, the value is placed in the current position (`sol[pos]`), and the function recurs to fill the next position.

- **Return Value**: The function returns the total number of combinations generated.

### `main()`

- **Purpose**: Initializes the required variables and calls the appropriate function (`perm_rep()` or `comb_rep()`) to generate permutations or combinations.

- **Variables**:
  - `val_dist[]`: Array of distinct values (`{1, 2, 3}` in this case).
  - `n_dist`: The number of distinct values in `val_dist` (3).
  - `n`: Length of the permutations or combinations to generate (3).
  - `sol[]`: Array to store the current permutation or combination.
  - `mark[]`: Array to track the remaining occurrences for each value in `val_dist` (all set to 1 initially).
  - `count`: Counter to keep track of the total number of permutations or combinations generated.

- **Working**: The `main()` function asks the user to choose between generating permutations or combinations. Based on the choice, it calls either `perm_rep()` or `comb_rep()` with initial values to generate all permutations or combinations. After all permutations or combinations are generated, it prints the total count.

## How to Compile and Run

1. Save the file as `combinations_permutations.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc combinations_permutations.c -o combinations_permutations
   ```
4. Run the compiled program:
   ```bash
   ./combinations_permutations
   ```

## Example Output

For Permutations:
```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
Total permutations: 6
```

For Combinations:
```
1 1 1
1 1 2
1 1 3
1 2 2
1 2 3
1 3 3
2 2 2
2 2 3
2 3 3
3 3 3
Total combinations: 10
```

## Explanation of Key Concepts
- **Backtracking**: The program uses backtracking to explore all possible permutations or combinations. After placing an element, the function recurs to place the next one. Once all positions are filled, it backtracks by restoring the element's availability to explore other possibilities.
- **Recursive Function**: Both `perm_rep()` and `comb_rep()` functions are recursive, meaning they call themselves to fill each position of the permutation or combination until all positions are filled.

## Customization
- **Changing the Values**: To change the set of values to be permuted or combined, modify the `val_dist` array in `main()`. For example, use `{4, 5, 6}` for different values.
- **Changing the Length of Permutation/Combination**: Modify the `n` or `k` variable in `main()` to change the length of each permutation or combination.

## Limitations
- The current implementation only allows each distinct value to be used once (`mark[]` is initialized with `1` for each value). To allow more repetitions, increase the corresponding value in `mark[]`.
- The array sizes are hardcoded, so increasing the number of distinct values or the length of the permutation/combination requires updating the respective variables accordingly.

## Conclusion
This program provides a basic demonstration of how to generate permutations and combinations with repetition using recursion and backtracking. It is useful for learning the principles of recursion, backtracking, and understanding how to systematically generate all possible combinations or permutations of a given set of values.

