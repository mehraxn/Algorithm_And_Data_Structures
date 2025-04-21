#include <stdio.h>
#include <stdlib.h>
// load_truck is directly derived from powerset
void load_truck (float *, float *, int, float);
void powerset_r (float *, float *, int, float, int *, int, int, int, float *, int *, int *);

int main (int argc, char *argv[]) {
    float weight[] = {10.0, 15.0, 25.5, 39.5, 17.0};
    float value[] = {19.99, 9.50, 15.00, 27.50, 11.40};
    int n = 5;
    float load = 50;
    load_truck (weight, value, n, load);
    return EXIT_SUCCESS;
}

// Powerset
void load_truck (float *weight, float *value, int n, float load) {
    int *solution, *best_solution;
    float best_value = 0;
    int best_size = 0;
    int i;

    solution = calloc (n, sizeof (int));
    best_solution = calloc (n, sizeof (int));
    if (solution == NULL || best_solution == NULL) {
        fprintf (stderr, "Allocation error.\n");
        exit (0);
    }

    for (i = n; i > 0; i--) {
        powerset_r (weight, value, n, load, solution, i, 0, 0, &best_value, best_solution, &best_size);
    }

    fprintf (stdout, "Solution: ");
    for (i = 0; i < best_size; i++) {
        fprintf (stdout, "%d ", best_solution[i]);
    }
    fprintf (stdout, "\n");
    return;
}

void powerset_r (float *weight, float *value, int n, float load, int *solution, int i,
                 int pos, int start, float *best_value, int *best_solution, int *best_size) {
    int j;
    float w, v;

    if (pos == i) {
        w = v = 0;
        // DEBUG: printf("{ ");
        for (j = 0; j < i; j++) {
            // DEBUG: printf("%d ", solution[j]);
            w = w + weight[solution[j]];
            v = v + value[solution[j]];
        }
        if (w < load && v > *best_value) {
            *best_value = v;
            for (j = 0; j < i; j++) {
                best_solution[j] = solution[j];
            }
            *best_size = i;
        }
        // DEBUG: printf("} %f %f %f %f\n", w, v, load, *best_value);
        return;
    }

    for (j = start; j < n; j++) {
        solution[pos] = j;
        powerset_r (weight, value, n, load, solution, i, pos + 1, j + 1, best_value, best_solution, best_size);
    }
    return;
}
