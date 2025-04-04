#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to evaluate a prefix expression
// This function takes a prefix expression as a string and a pointer to the current position
// It evaluates the prefix expression recursively, handling operators and operands appropriately
float eval_r(char *expr, int *pos_ptr) {
    float left, right, result;
    char operator;
    int k = *pos_ptr;

    // Skip any spaces in the expression
    while (isspace(expr[k])) {
        k++;
    }

    // Check if the current character is an operator (+, -, *, /)
    if (expr[k] == '+' || expr[k] == '*' || expr[k] == '-' || expr[k] == '/') {
        operator = expr[k++];  // Store the operator and move to the next character

        // Recursively evaluate the left operand
        left = eval_r(expr, &k);

        // Recursively evaluate the right operand
        right = eval_r(expr, &k);

        // Perform the operation based on the operator
        switch (operator) {
            case '+': result = left + right; break;
            case '*': result = left * right; break;
            case '-': result = left - right; break;
            case '/': result = left / right; break;
            default:
                fprintf(stderr, "Error: unknown operator '%c'\n", operator);
                exit(EXIT_FAILURE);
        }
    } else {
        // Terminal case: Read a real value (operand)
        sscanf(&expr[k], "%f", &result);
        // Move the position pointer to the end of the number
        while (isdigit(expr[k]) || expr[k] == '.') {
            k++;
        }
    }

    // Update the position pointer
    *pos_ptr = k;
    return result;
}

// Main function to run the program
int main(int argc, char *argv[]) {
    float result;
    int pos = 0;

    // Check if the expression is provided as a command line argument
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

/*
Summary of Functions in the Code:

1. eval_r(char *expr, int *pos_ptr):
   - This function evaluates a prefix expression recursively.
   - It handles both operators and operands by parsing the given string.
   - If an operator is found, it recursively evaluates the left and right operands and performs the corresponding arithmetic operation.
   - If an operand is found, it reads the value and returns it.
   - The function uses a position pointer to keep track of the current location in the expression.
   - The time complexity is O(n), where n is the number of tokens (operators and operands) in the expression.

2. main(int argc, char *argv[]):
   - The main function takes command line arguments, with the prefix expression passed as an argument.
   - It checks if the argument is provided, and if not, it displays an error message.
   - It calls the eval_r() function to evaluate the prefix expression and prints the result.
   - The program returns EXIT_SUCCESS upon successful execution.
*/