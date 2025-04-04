#include <stdio.h>
#include <stdlib.h>

#define BASE 2

/* function prototypes */
void binary_r(int *array, int depth, int n);

/* main program */
int main(void) {
    int n, *array;

    fprintf(stdout, "Number of bits: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Binary numbers\n");
    binary_r(array, 0, n);

    free(array);

    return EXIT_SUCCESS;
}

/* binary numbers generation, recursive function */
void binary_r(int *array, int depth, int n) {
    int i;

    if (depth >= n) {
        for (i = 0; i < n; i++) {
            fprintf(stdout, "%d", array[i]);
        }
        fprintf(stdout, "\n");
        return;
    }

    for (i = 0; i < BASE; i++) {
        array[depth] = i;
        binary_r(array, depth + 1, n);
    }
}
