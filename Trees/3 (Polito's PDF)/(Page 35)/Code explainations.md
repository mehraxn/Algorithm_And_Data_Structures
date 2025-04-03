# Prefix Expression Evaluator

## Overview
This program is a **Prefix Expression Evaluator** implemented in C. It takes a **prefix arithmetic expression** as a command-line argument and evaluates it using **recursion**. Prefix notation, also known as **Polish notation**, is an arithmetic notation in which the operator precedes their operands, making parentheses unnecessary for defining the order of operations.

The program can handle the basic arithmetic operations (`+`, `-`, `*`, `/`) and floating-point numbers. The main logic is implemented in a recursive function (`eval_r`), which breaks down the expression and evaluates each sub-expression step by step.

## Features
- Evaluates prefix arithmetic expressions.
- Supports the four basic arithmetic operations: **addition**, **subtraction**, **multiplication**, and **division**.
- Handles **floating-point numbers**.
- Uses a **recursive approach** to evaluate the expression.

## How to Use
### Compilation
To compile the program, use a C compiler such as **GCC**:
```sh
gcc -o prefix_evaluator prefix_evaluator.c
```
This command generates an executable named `prefix_evaluator`.

### Running the Program
To run the program, provide the prefix expression as a command-line argument. Note that you need to wrap the expression in double quotes to handle spaces:
```sh
./prefix_evaluator "* + 5.3 12.1 3.7"
```
### Example
- **Input**: `"* + 5.3 12.1 3.7"`
- **Output**: `Result = 64.38`

### Input Format
- The input must be a **prefix arithmetic expression**.
- **Operators** (`+`, `-`, `*`, `/`) must be provided before the operands.
- The expression should be properly formatted with spaces between operators and operands.

### Explanation of Example
- Given the expression `* + 5.3 12.1 3.7`:
  - First, `+ 5.3 12.1` is evaluated to give `17.4`.
  - Then, `* 17.4 3.7` is evaluated to give `64.38`.
- The final output is `Result = 64.38`.

## Code Structure and Functions

### 1. `main(int argc, char *argv[])`
- **Purpose**: Entry point of the program.
- **Parameters**:
  - `argc`: Argument count (number of arguments provided).
  - `argv[]`: Array of arguments (the prefix expression).
- **Functionality**:
  - Checks if an expression is provided.
  - If no expression is provided, an error message is displayed, and the program exits.
  - Calls `eval_r()` to evaluate the expression and prints the result.

### 2. `eval_r(char *expr, int *pos_ptr)`
- **Purpose**: Recursively evaluates a prefix arithmetic expression.
- **Parameters**:
  - `expr`: The prefix expression to be evaluated.
  - `pos_ptr`: Pointer to the current position in the expression.
- **Functionality**:
  - Skips any whitespace.
  - Checks if the current character is an operator (`+`, `-`, `*`, `/`).
  - If it is an operator, the function recursively evaluates the left and right operands, then performs the operation.
  - If it is a number, it reads the value and updates the position pointer.
  - Returns the result of the evaluation.

## Implementation Details
- The **recursive approach** is well-suited for prefix expressions since it allows breaking down the expression into smaller sub-expressions until we reach the base case (numbers).
- **Whitespace** is ignored to ensure proper parsing of the expression.
- **Operators** are handled before operands, matching the prefix notation logic.

## Example Walkthrough
Consider the input: `* + 5.3 12.1 3.7`
1. **Step 1**: The `*` operator is found, so we recursively evaluate the next part.
2. **Step 2**: The `+` operator is found, so we recursively evaluate its operands (`5.3` and `12.1`).
   - Result: `17.4`.
3. **Step 3**: Multiply `17.4` (result of `+`) with `3.7` (next operand).
   - Result: `64.38`.
4. **Output**: `Result = 64.38`.

## Error Handling
- If no expression is provided, the program prints an **error message** indicating that a parameter is missing and exits with status `1`.
- The program expects a properly formatted prefix expression; incorrect formats may lead to undefined behavior.

## Limitations
- The program does not handle **invalid expressions** (e.g., missing operands, incorrect operators).
- Division by zero is not explicitly handled and will result in undefined behavior.
- The expression must be properly formatted with **spaces** between operators and operands.

## Extending the Program
- **Additional Operators**: Extend the code to support more arithmetic operations or functions (e.g., power, modulus).
- **Error Handling**: Add more robust error checking for invalid expressions or division by zero.
- **User Input**: Allow users to input the expression interactively rather than via command-line arguments.

## Conclusion
This **Prefix Expression Evaluator** provides a simple demonstration of evaluating prefix arithmetic expressions using a recursive approach. It highlights the power of recursion in breaking down complex expressions into smaller, manageable sub-problems, ultimately providing an effective solution for evaluating mathematical expressions in prefix notation.

