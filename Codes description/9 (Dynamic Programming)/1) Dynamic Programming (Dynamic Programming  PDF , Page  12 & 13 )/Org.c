#include <stdio.h>
#include <stdlib.h>

int fib_dp (int n, int *known);

int main (void) {
    int *known, i, n;
    fprintf(stdout, "Input n: ");
    scanf("%d", &n);
    known = (int *) malloc ((n+1) * sizeof(int));
    if (known == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i <= n; i++) {
        known[i] = -1;
    }
    fprintf(stdout, "Fibonacci %d-th term = %d\n", n, fib_dp(n, known));
    free(known);
    return EXIT_SUCCESS;
}

int fib_dp (int n, int *known) {
    if (known[n] < 0) {
        if (n == 0 || n == 1) {
            known[n] = n;
        } else {
            known[n] = fib_dp(n-1, known) + fib_dp(n-2, known);
        }
    }
    return known[n];
}
