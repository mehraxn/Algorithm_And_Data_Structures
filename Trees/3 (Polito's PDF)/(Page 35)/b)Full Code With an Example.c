#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototype for evaluating a prefix expression
float eval_r(char *expr, int *pos_ptr);

int main(int argc, char *argv[]) {
    float result;
    int pos = 0;

    // Check if the user provided an expression as an argument
    if (argc < 2) {
        fprintf(stderr, "Error: missing parameter.\n");
        fprintf(stderr, "Run as: %s prefix_expression\n", argv[0]);
        return 1;
    }

    // Evaluate the prefix expression
    result = eval_r(argv[1], &pos);

    // Print the result to the standard output
    fprintf(stdout, "Result = %.2f\n", result);
    return EXIT_SUCCESS;
}

// Function to evaluate a prefix expression recursively
float eval_r(char *expr, int *pos_ptr) {
    float left, right, result;
    char operator;
    int k = *pos_ptr;

    // Skip any spaces in the expression
    while (isspace(expr[k])) {
        k++;
    }

    // Check if the current character is an operator
    if (expr[k] == '+' || expr[k] == '*' || expr[k] == '-' || expr[k] == '/') {
        operator = expr[k++]; // Store the operator and move to the next character

        // Recursively evaluate the left and right operands
        left = eval_r(expr, &k);
        right = eval_r(expr, &k);

        // Perform the operation based on the operator
        switch (operator) {
            case '+':
                result = left + right;
                break;
            case '*':
                result = left * right;
                break;
            case '-':
                result = left - right;
                break;
            case '/':
                result = left / right;
                break;
        }
    } else {
        // If the current character is a number, read the value
        sscanf(&expr[k], "%f", &result);

        // Move the position index past the number
        while (isdigit(expr[k]) || expr[k] == '.') {
            k++;
        }
    }

    // Update the position pointer
    *pos_ptr = k;
    return result;
}

/*
Explanation of the Functions in the Code:

1. `main(int argc, char *argv[])`:
   - This is the entry point of the program.
   - It checks if a prefix expression is provided as a command-line argument.
   - If the argument is missing, it prints an error message and exits.
   - Otherwise, it calls the `eval_r` function to evaluate the expression and prints the result.

2. `eval_r(char *expr, int *pos_ptr)`:
   - This function evaluates a prefix expression recursively.
   - It takes two parameters: the expression (`expr`) and a pointer to the current position (`pos_ptr`).
   - It skips spaces, checks if the current character is an operator or a number, and evaluates accordingly.
   - If the character is an operator (`+`, `-`, `*`, `/`), it recursively evaluates the left and right operands and performs the operation.
   - If the character is a number, it reads the value and updates the position pointer.
   - The function returns the result of the evaluation.

Overall, the program reads a prefix expression from the command line and uses a recursive function (`eval_r`) to evaluate it. The expression can contain basic arithmetic operators (`+`, `-`, `*`, `/`) and floating-point numbers. The `eval_r` function uses recursion to break down the expression into smaller parts and compute the final result.

Example:
- Input Prefix Expression: "* + 5.3 12.1 3.7"
- Explanation:
  - The expression is evaluated as follows:
    - `+ 5.3 12.1` is evaluated first to get `17.4`.
    - Then, `* 17.4 3.7` is evaluated to get `64.38`.
- Output: `Result = 64.38`
*/
