#include <stdio.h>
#include <stdlib.h>

/* Function prototype */
int partition(int *, int *, int, int, int, int);

int main(int argc, char *argv[]) {
    int value[4] = {1, 2, 3, 4};
    int solution[4] = {0, 0, 0, 0};

    int n = 4, k = 2, pos = 0, count = 0;
    int i, total;

    fprintf(stdout, "Partition (%d elements = ", n);
    for (i = 0; i < n; i++) {
        fprintf(stdout, "%d ", value[i]);
    }
    fprintf(stdout, ")\n\n");

    total = partition(value, solution, n, k, pos, count);
    fprintf(stdout, "\nTotal Number: %d\n", total);

    return EXIT_SUCCESS;
}

int partition(int *value, int *solution, int n, int k, int pos, int count) {
    int i, j, end, *occurrences;

    if (pos >= n) {
        occurrences = calloc(k, sizeof(int));
        if (occurrences == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }

        for (j = 0; j < n; j++) {
            occurrences[solution[j]]++;
        }

        for (end = 0, j = 0; j < k && end == 0; j++) {
            if (occurrences[j] == 0) {
                end = 1;
            }
        }

        free(occurrences);

        if (end == 1) {
            return count;
        }

        // Print solution vector
        fprintf(stdout, "Partition %2d: ", count + 1);
        fprintf(stdout, "{ ");
        for (i = 0; i < n; i++) {
            fprintf(stdout, "%d ", solution[i]);
        }
        fprintf(stdout, "}  ->  ");

        // Print actual element groups
        for (i = 0; i < k; i++) {
            fprintf(stdout, "{ ");
            for (j = 0; j < n; j++) {
                if (solution[j] == i) {
                    fprintf(stdout, "%d ", value[j]);
                }
            }
            fprintf(stdout, "} ");
        }

        fprintf(stdout, "\n");
        return count + 1;
    }

    for (i = 0; i < k; i++) {
        solution[pos] = i;
        count = partition(value, solution, n, k, pos + 1, count);
    }

    return count;
}
