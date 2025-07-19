#include <stdio.h>
#include <stdlib.h>

typedef struct value_s {
    int num;
    char *element;  // changed from array to pointer
} value_t;

/* Function prototype */
int multiplication_principle(value_t *, char *, int, int, int);

/* Main program */
int main(int argc, char *argv[]) {
    value_t *value;
    char solution[3];
    int n = 3, pos = 0, count = 0;
    int total;

    // Allocate memory for sets
    value = (value_t *)malloc(n * sizeof(value_t));
    if (value == NULL) {
        fprintf(stderr, "Memory allocation for value array failed\n");
        return EXIT_FAILURE;
    }

    // Allocate and assign elements for set 0
    value[0].num = 2;
    value[0].element = (char *)malloc(value[0].num * sizeof(char));
    value[0].element[0] = 'A';
    value[0].element[1] = 'B';

    // Allocate and assign elements for set 1
    value[1].num = 2;
    value[1].element = (char *)malloc(value[1].num * sizeof(char));
    value[1].element[0] = '0';
    value[1].element[1] = '1';

    // Allocate and assign elements for set 2
    value[2].num = 3;
    value[2].element = (char *)malloc(value[2].num * sizeof(char));
    value[2].element[0] = 'X';
    value[2].element[1] = 'Y';
    value[2].element[2] = 'Z';

    fprintf(stdout, "Multiplication Principle:\n");
    total = multiplication_principle(value, solution, n, pos, count);
    fprintf(stdout, "\nTotal Number: %d\n", total);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(value[i].element);
    }
    free(value);

    return EXIT_SUCCESS;
}

/* Multiplication Principle Function */
int multiplication_principle(value_t *value, char *solution, int n, int pos, int count) {
    int i;

    if (pos >= n) {
        fprintf(stdout, "{ ");
        for (i = 0; i < n; i++) {
            fprintf(stdout, "%c ", solution[i]);
        }
        fprintf(stdout, "}\n");
        return count + 1;
    }

    for (i = 0; i < value[pos].num; i++) {
        solution[pos] = value[pos].element[i];
        count = multiplication_principle(value, solution, n, pos + 1, count);
    }

    return count;
}
