# README: Expression Calculator Program

## Overview
This program finds all possible permutations of a given set of numbers and mathematical operators (`+`, `-`, `*`, `/`) to construct expressions that evaluate to a specified target result. It uses recursive algorithms to generate permutations of numbers and operators and evaluates the generated expressions.

---

## Features
- Generates all permutations of the input numbers.
- Combines the permutations with all possible combinations of operators.
- Evaluates each expression and checks if it equals the target result.
- Outputs all valid expressions that match the target result.

---

## Code Structure
### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Initializes an example set of numbers (`v`) and target result.
  - Calls the `calculator` function to find and print all valid expressions.

---

#### 2. **calculator**
```c
void calculator(int *v, int n, int result);
```
- **Purpose**: Coordinates the permutation generation and evaluation process.
- **Parameters**:
  - `v`: Array of input numbers.
  - `n`: Size of the array.
  - `result`: Target result to match.
- **Logic**:
  - Generates all permutations of the input numbers using the `perm` function.
  - For each permutation, calls `call_second_rec` to handle operator combinations.

---

#### 3. **perm**
```c
void perm(int *val, int *sol, int *mark, int n, int pos, int result);
```
- **Purpose**: Generates all permutations of the input numbers.
- **Parameters**:
  - `val`: Array of input numbers.
  - `sol`: Array to store the current permutation.
  - `mark`: Array to track used numbers.
  - `n`: Size of the array.
  - `pos`: Current position in the permutation.
  - `result`: Target result.
- **Logic**:
  - Uses a recursive approach to generate all permutations of the numbers.
  - Passes each permutation to `call_second_rec` for further processing.

---

#### 4. **call_second_rec**
```c
void call_second_rec(int *numbers, int n, int result);
```
- **Purpose**: Handles the generation of operator combinations for a given permutation of numbers.
- **Parameters**:
  - `numbers`: Current permutation of numbers.
  - `n`: Size of the permutation.
  - `result`: Target result.
- **Logic**:
  - Calls `perm_rep` to generate all operator combinations.
  - Evaluates each combination using `evalute_expression`.

---

#### 5. **perm_rep**
```c
void perm_rep(char *val_dist, char *sol, int *mark, int n, int n_dist, int pos, int *numbers, int result);
```
- **Purpose**: Generates all permutations with repetition for the operators.
- **Parameters**:
  - `val_dist`: Array of available operators (`+`, `-`, `*`, `/`).
  - `sol`: Array to store the current operator combination.
  - `mark`: Array to track available operators.
  - `n`: Number of operators to select.
  - `n_dist`: Number of distinct operators.
  - `pos`: Current position in the operator combination.
  - `numbers`: Current permutation of numbers.
  - `result`: Target result.
- **Logic**:
  - Uses recursion to generate all operator combinations with repetition.
  - Passes each combination to `evalute_expression`.

---

#### 6. **evalute_expression**
```c
void evalute_expression(int *numbers, char *symbols, int n, int result);
```
- **Purpose**: Evaluates a given expression and checks if it matches the target result.
- **Parameters**:
  - `numbers`: Array of numbers.
  - `symbols`: Array of operators.
  - `n`: Number of numbers in the expression.
  - `result`: Target result.
- **Logic**:
  - Calls `calculate` to evaluate the expression.
  - If the result matches the target, prints the expression.

---

#### 7. **calculate**
```c
int calculate(int *numbers, char *symbols, int n);
```
- **Purpose**: Evaluates an expression based on given numbers and operators.
- **Parameters**:
  - `numbers`: Array of numbers.
  - `symbols`: Array of operators.
  - `n`: Number of numbers in the expression.
- **Logic**:
  - Iterates through the numbers and applies the corresponding operator.
  - Returns the final result of the expression.

---

## Example Execution

### Input
- Numbers: `{3, 2, 25, 5}`
- Target Result: `5`

### Output
```
3 + 2 - 25 + 5 = 5
3 - 2 + 25 - 5 = 5
```

### Explanation
- The program generates all permutations of `{3, 2, 25, 5}`.
- For each permutation, it generates all combinations of operators.
- It evaluates each expression and prints those that equal `5`.

---

## Limitations
- **Fixed Operators**: Only supports the operators `+`, `-`, `*`, and `/`.
- **Integer Division**: Division results are truncated to integers.
- **Efficiency**: Performance may degrade for larger input sizes due to exhaustive search.

---

## Future Improvements
- Extend support for floating-point numbers and division.
- Add support for additional operators or parentheses.
- Optimize the algorithm to avoid redundant evaluations.
- Allow dynamic input for numbers and target result.

---

## How to Compile and Run
1. Save the code in a file (e.g., `calculator.c`).
2. Compile the program:
   ```bash
   gcc -o calculator calculator.c
   ```
3. Run the program:
   ```bash
   ./calculator
   ```

