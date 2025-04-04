# Prefix Expression Evaluator

This repository contains a C implementation of a program that evaluates prefix arithmetic expressions. The program accepts a prefix expression as a command-line argument and computes its value. Prefix expressions, also known as Polish notation, place the operator before their operands, allowing for simple evaluation without parentheses.

## Overview

The program provides a recursive method to evaluate prefix expressions involving basic arithmetic operations (`+`, `-`, `*`, `/`). Prefix notation is useful because it eliminates the need for parentheses to denote operation precedence, making parsing simpler.

This implementation includes:
- A function to recursively evaluate the prefix expression (`eval_r`).
- A `main` function to handle user input and display the result.

## Files

- **prefix_eval.c**: The main implementation file that contains the definition of the prefix evaluation functions.

## Functions

### `float eval_r(char *expr, int *pos_ptr)`

This function recursively evaluates a prefix arithmetic expression.
- **Parameters**:
  - `char *expr`: The input prefix expression as a string.
  - `int *pos_ptr`: A pointer to the current position in the string.
- **Returns**:
  - A floating-point value representing the result of the evaluated expression.

**How it Works**:
- The function skips any spaces and checks if the current character is an operator (`+`, `-`, `*`, `/`).
- If an operator is found, it evaluates the left and right operands recursively and applies the operator to them.
- If an operand is found, it reads the number and returns it.

**Time Complexity**: O(n), where `n` is the number of tokens (operators and operands) in the expression.

### `int main(int argc, char *argv[])`

The main function that drives the program.
- **Parameters**:
  - `int argc`: The number of command-line arguments.
  - `char *argv[]`: An array of command-line arguments.
- **Description**:
  - It checks if the user has provided a prefix expression as an argument. If not, it prints an error message and terminates.
  - It calls `eval_r()` to evaluate the provided prefix expression and prints the result.
- **Example Command**:
  ```bash
  ./prefix_eval "* + 5.3 12.1 3.7"
  ```
  **Example Output**:
  ```
  Result = 64.38
  ```

## Compilation and Execution

To compile and run the program, you can use the `gcc` compiler as follows:

```bash
gcc prefix_eval.c -o prefix_eval
./prefix_eval "* + 5.3 12.1 3.7"
```

The above command will evaluate the given prefix expression and print the result.

## Expression Format

- The prefix expression must be provided as a single command-line argument, enclosed in quotes if it contains spaces.
- Supported operators: `+`, `-`, `*`, `/`.
- Operands can be real numbers (e.g., `5.3`, `12.1`).

## Example

For an input expression `"* + 5.3 12.1 3.7"`:
- The prefix notation means:
  - First, evaluate `5.3 + 12.1`.
  - Then, multiply the result by `3.7`.
- **Result**: `64.38`

## Memory Management

The program uses a recursive approach to evaluate the prefix expression. No dynamic memory allocation is required, so there is no need to manually free any memory.

## Contributions

Contributions are welcome! Feel free to submit a pull request or open an issue for any improvements or additional features you would like to see.

## License

This project is open-source and available under the MIT License. See the `LICENSE` file for more details.

## Contact

If you have any questions or suggestions, feel free to reach out to the repository maintainer.

