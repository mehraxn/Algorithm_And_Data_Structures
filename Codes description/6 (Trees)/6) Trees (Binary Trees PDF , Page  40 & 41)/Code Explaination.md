# Postfix Expression Evaluator

This project provides a simple implementation of a program that evaluates a postfix (Reverse Polish Notation) expression using a stack. Postfix expressions are mathematical notations where operators follow their operands, which eliminates the need for parentheses to define order of operations.

## Overview

The code is written in C and uses a custom stack to handle operations for evaluating postfix expressions. The key operations include pushing operands onto the stack and popping them off when an operator is encountered.

### Postfix Notation

In postfix notation, operators follow their operands. For example:

- Infix: `5 + 3`
- Postfix: `5 3 +`

The advantage of postfix is that it does not require parentheses for precedence, simplifying evaluation using stacks.

### Features

- Evaluates postfix expressions with basic arithmetic operators: `+`, `-`, `*`, and `/`.
- Uses a stack to keep track of operands during the evaluation process.
- Includes proper error handling for stack overflow and underflow.

## Files

- **main.c**: The main program file that contains the implementation of the stack-based postfix evaluator.

## How to Compile and Run

To compile the program, use a C compiler such as GCC:

```sh
gcc main.c -o postfix_evaluator
```

To run the program, provide a postfix expression as a command-line argument:

```sh
./postfix_evaluator "5 3 + 2 *"
```

### Example

```sh
./postfix_evaluator "5 3 + 2 *"
```

Output:

```
Result = 16.00
```

## Functions Explained

### 1. `stack_t* stack_init(int size)`

- **Purpose**: Initializes a stack with a given size and allocates memory for storing values.
- **Parameters**: `size` - the maximum number of elements that can be stored in the stack.
- **Returns**: A pointer to the newly created stack.

### 2. `void stack_push(stack_t *stack, float value)`

- **Purpose**: Pushes a value onto the stack.
- **Parameters**: `stack` - the stack to push the value onto, `value` - the value to be pushed.
- **Error Handling**: Checks for stack overflow, which occurs if the stack is full.

### 3. `float stack_pop(stack_t *stack)`

- **Purpose**: Pops a value from the stack.
- **Parameters**: `stack` - the stack to pop the value from.
- **Returns**: The value at the top of the stack.
- **Error Handling**: Checks for stack underflow, which occurs if the stack is empty.

### 4. `void stack_dispose(stack_t *stack)`

- **Purpose**: Frees the memory allocated for the stack.
- **Parameters**: `stack` - the stack to be disposed of.

### 5. `int main(int argc, char *argv[])`

- **Purpose**: The main function that evaluates a postfix expression.
- **Parameters**: `argc` - the argument count, `argv` - the argument vector containing the postfix expression.
- **Description**: This function reads the postfix expression from the command line, initializes the stack, and processes each character in the expression. It handles both operands and operators, performs the corresponding arithmetic operations, and finally outputs the result.

## How It Works

1. **Initialization**: The program takes a postfix expression from the command line and initializes a stack to store operands.
2. **Processing**: The expression is processed character by character.
   - If the character is a digit, it is pushed onto the stack.
   - If the character is an operator (`+`, `-`, `*`, `/`), two operands are popped from the stack, and the operation is performed.
3. **Final Result**: The final result is popped from the stack and displayed.
4. **Cleanup**: The stack is disposed of to free allocated memory.

## Error Handling

- **Stack Overflow**: If the stack is full and a push operation is attempted, the program prints an error message and exits.
- **Stack Underflow**: If the stack is empty and a pop operation is attempted, the program prints an error message and exits.
- **Invalid Input**: Any invalid characters (non-digits, non-operators) are ignored, and whitespace characters are skipped.

## Limitations

- The program only supports basic arithmetic operators (`+`, `-`, `*`, `/`).
- Only valid postfix expressions should be provided, as the program does not perform full validation of postfix syntax.
- It does not handle negative numbers or more complex numerical expressions (e.g., trigonometric functions).

## Future Improvements

- Add support for more advanced mathematical operations.
- Implement full validation of the input expression.
- Enhance error handling for invalid postfix expressions.

## License

This project is open source and available under the MIT License. Feel free to modify and distribute it as needed.

## Contact

If you have any questions or suggestions, feel free to reach out via the repository or email.

