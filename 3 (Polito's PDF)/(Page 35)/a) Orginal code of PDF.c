#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float eval_r(char *expr, int *pos_ptr);

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

float eval_r(char *expr, int *pos_ptr) {
    float left, right, result;
    char operator;
    int k = *pos_ptr;

    // Skip spaces
    while (isspace(expr[k])) {
        k++;
    }

    if (expr[k] == '+' || expr[k] == '*' || expr[k] == '-' || expr[k] == '/') {
        operator = expr[k++];
        left = eval_r(expr, &k);
        right = eval_r(expr, &k);
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
        sscanf(&expr[k], "%f", &result);
        while (isdigit(expr[k]) || expr[k] == '.') {
            k++;
        }
    }

    *pos_ptr = k;
    return result;
}
