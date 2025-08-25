#include <stdio.h>
#include <stdlib.h>

/*
  Generate all assignments of n items to k blocks (0..k-1),
  and print only those where every block is non-empty.
  sol[i] holds the block index for val[i].
*/

void check_and_display(const int *val, const int *sol, int n, int k);
void arr_rep(const int *val, int *sol, int n, int k, int pos);

void arr_rep(const int *val, int *sol, int n, int k, int pos) {
    int i;

    if (pos >= n) {
        check_and_display(val, sol, n, k);
        return;
    }

    for (i = 0; i < k; i++) {
        sol[pos] = i;
        arr_rep(val, sol, n, k, pos + 1);
    }
}

void check_and_display(const int *val, const int *sol, int n, int k) {
    int i, j, end = 0;
    int *occ = (int *)calloc((size_t)k, sizeof(int));
    if (occ == NULL) {
        fprintf(stderr, "calloc failed\n");
        return;
    }

    /* Count how many items went into each block. */
    for (j = 0; j < n; j++) occ[sol[j]]++;

    /* Reject solutions with any empty block. */
    for (j = 0; j < k && end == 0; j++) {
        if (occ[j] == 0) end = 1;
    }
    free(occ);
    if (end == 1) return;

    /* Print the partition: k blocks, showing the values in each. */
    printf("Partition: ");
    for (i = 0; i < k; i++) {
        printf("{ ");
        for (j = 0; j < n; j++) {
            if (sol[j] == i) printf("%d ", val[j]);
        }
        printf("} ");
    }
    printf("\n");
}

int main(void) {
    int n, k, i;

    printf("Enter number of elements (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid n\n");
        return 1;
    }

    int *val = (int *)malloc((size_t)n * sizeof(int));
    int *sol = (int *)malloc((size_t)n * sizeof(int));
    if (!val || !sol) {
        fprintf(stderr, "Memory allocation failed\n");
        free(val);
        free(sol);
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &val[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(val);
            free(sol);
            return 1;
        }
    }

    printf("Enter number of blocks (k): ");
    if (scanf("%d", &k) != 1 || k <= 0) {
        fprintf(stderr, "Invalid k\n");
        free(val);
        free(sol);
        return 1;
    }

    printf("\nAll partitions into %d non-empty blocks:\n", k);
    arr_rep(val, sol, n, k, 0);

    free(val);
    free(sol);
    return 0;
}
