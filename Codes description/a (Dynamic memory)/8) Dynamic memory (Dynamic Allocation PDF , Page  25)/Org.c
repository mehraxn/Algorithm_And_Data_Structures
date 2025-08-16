#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v1, *v2, *v3;

    // Allocate memory for 50 integers
    v1 = malloc(50 * sizeof(int));
    if (v1 == NULL) {
        fprintf(stderr, "Memory allocation failed for v1.\n");
        return 1;
    }

    // Reallocate memory to hold 100 integers
    v2 = realloc(v1, 100 * sizeof(int));
    if (v2 == NULL) {
        fprintf(stderr, "Memory reallocation failed for v2.\n");
        free(v1); // Free the previously allocated memory
        return 1;
    }

    // Reallocate memory to hold 200 integers
    v3 = realloc(v2, 200 * sizeof(int));
    if (v3 == NULL) {
        fprintf(stderr, "Memory reallocation failed for v3.\n");
        free(v2); // Free the previously allocated memory
        return 1;
    }

    // Use the allocated memory (example: initialize all elements to zero)
    for (int i = 0; i < 200; i++) {
        v3[i] = 0;
    }

    // Free the allocated memory
    free(v3);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *p;
    int v[100];

    // Prompt the user to enter the value of n
    fprintf(stdout, "Introduce n (<= 100): ");
    scanf("%d", &n);

    // Check if n is within bounds
    if (n > 100) {
        fprintf(stderr, "Value of n exceeds array size limit.\n");
        return 1;
    }

    // Allocate memory for n integers
    p = (int *)malloc(n * sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return 1;
    }

    // Use p to access the allocated area (example: initialize all elements to one)
    for (int i = 0; i < n; i++) {
        p[i] = 1;
    }

    // Use v (example: initialize all elements to two)
    for (int i = 0; i < 100; i++) {
        v[i] = 2;
    }

    // Free the allocated memory
    free(p);

    return 0;
}
