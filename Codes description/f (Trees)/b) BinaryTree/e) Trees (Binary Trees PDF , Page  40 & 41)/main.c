#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a stack structure for float values
typedef struct {
    float *data; // Array to hold stack values
    int top;     // Index of the top element
    int size;    // Maximum capacity of the stack
} stack_t;

// Function to initialize the stack
stack_t* stack_init(int size) {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    stack->data = (float *)malloc(size * sizeof(float));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Function to push a value onto the stack
void stack_push(stack_t *stack, float value) {
    if (stack->top < stack->size - 1) {
        stack->data[++stack->top] = value;
    } else {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

// Function to pop a value from the stack
float stack_pop(stack_t *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

// Function to free the memory allocated for the stack
void stack_dispose(stack_t *stack) {
    free(stack->data);
    free(stack);
}

// Main function to evaluate a postfix expression
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <postfix_expression>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float result, left, right;
    int length, k = 0;
    stack_t *sp = NULL;
    char *expr;

    expr = argv[1];                    // Get the postfix expression from command line
    length = strlen(expr);             // Length of the expression
    sp = stack_init(length);           // Initialize the stack

    while (k < length) {
        if (isdigit(expr[k]) || expr[k] == '.') { // Check if the character is a digit
            sscanf(&expr[k], "%f", &result);      // Read the number
            stack_push(sp, result);              // Push the number onto the stack
            while (isdigit(expr[k]) || expr[k] == '.') {
                k++;                             // Move to the next character
            }
        } else if (expr[k] == '+' || expr[k] == '*' || expr[k] == '-' || expr[k] == '/') {
            // If the character is an operator, pop two operands from the stack
            right = stack_pop(sp);
            left = stack_pop(sp);
            switch (expr[k]) {
                case '+': result = left + right; break;
                case '*': result = left * right; break;
                case '-': result = left - right; break;
                case '/': result = left / right; break;
                default:
                    fprintf(stderr, "Invalid operator %c\n", expr[k]);
                    return EXIT_FAILURE;
            }
            stack_push(sp, result); // Push the result back onto the stack
            k++; // Move to the next character
        } else {
            k++; // Skip any invalid or whitespace characters
        }
    }

    // Pop the final result from the stack
    result = stack_pop(sp);
    printf("Result = %.2f\n", result);

    // Free the stack
    stack_dispose(sp);
    return EXIT_SUCCESS;
}

/*
Summary of Functions:

1. `stack_t* stack_init(int size)`: Initializes a stack with a given size and allocates memory for it.

2. `void stack_push(stack_t *stack, float value)`: Pushes a float value onto the stack, checking for overflow.

3. `float stack_pop(stack_t *stack)`: Pops a float value from the stack, checking for underflow.

4. `void stack_dispose(stack_t *stack)`: Frees the memory allocated for the stack.

5. `main`: Evaluates a postfix expression provided as a command-line argument. It uses a stack to perform operations on operands and handles basic arithmetic operators (`+`, `-`, `*`, `/`). The final result is displayed, and memory is cleaned up.

This code demonstrates how to evaluate a postfix expression using a stack. It validates the input, processes digits and operators, and manages the stack's memory. Proper error handling for stack overflow and underflow ensures robustness.
*/
