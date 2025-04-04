#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to evaluate a prefix expression
float eval_r(char *expr, int *pos_ptr) {
    float left, right, result;
    char operator;
    int k = *pos_ptr;

    // Skip spaces
    while (isspace(expr[k])) {
        k++;
    }

    // Check if the current character is an operator
    if (expr[k] == '+' || expr[k] == '*' || expr[k] == '-' || expr[k] == '/') {
        operator = expr[k++];  // Store the operator and move ahead

        // Recursively evaluate left operand
        left = eval_r(expr, &k);

        // Recursively evaluate right operand
        right = eval_r(expr, &k);

        // Perform the operation
        switch (operator) {
            case '+': result = left + right; break;
            case '*': result = left * right; break;
            case '-': result = left - right; break;
            case '/': result = left / right; break;
        }
    } else {
        // Terminal case: Read a real value
        sscanf(&expr[k], "%f", &result);
        // Move to the end of the number
        while (isdigit(expr[k]) || expr[k] == '.') {
            k++;
        }
    }

    *pos_ptr = k;  // Update the position pointer
    return result;
}

int main(int argc, char *argv[]) {
    float result;
    int pos = 0;

    if (argc < 2) {
        fprintf(stderr, "Error: missing parameter.\n");
        fprintf(stderr, "Run as: %s prefix_expression\n", argv[0]);
        return 1;
    }

    result = eval_r(argv[1], &pos);
    fprintf(stdout, "Result = %.2f\n", result);
    return EXIT_SUCCESS;
}

/*
Expression: " * + 5.3 12.1 3.7"
Command line argument within " " to include spaces

(5.3 + 12.1) * 3.7 = * + 5.3 12.1 3.7 = 64.38
*/
