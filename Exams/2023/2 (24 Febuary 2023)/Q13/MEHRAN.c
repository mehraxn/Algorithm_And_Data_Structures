#include <stdio.h>
#include <stdlib.h>

typedef struct EDGES edge;
struct EDGES {
    int source, destination;
};

int edge_permutation(edge array[], int edge_counter,
    int *value, int *mark, int *solution, int n, int k, int pos);

void check(edge array[], int edge_counter, int *solution, int k) {
    for (int i = 0; i < k; i++) {
        if (array[solution[i]].destination != array[solution[(i+1) % k]].source) {
            return;
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", array[solution[i]].source);
    }
    printf("\n");
}

void loop(int **mat, int n, int k) {
    edge array[n*n];
    int edge_counter = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] > 0) {
                array[edge_counter].source = i;
                array[edge_counter].destination = j;
                edge_counter++;
            }
        }
    }

    int *value = (int *)calloc(edge_counter, sizeof(int));
    int *mark = (int *)calloc(edge_counter, sizeof(int));
    for (int i = 0; i < edge_counter; i++) {
        value[i] = i;
    }
    int *solution = (int *)calloc(k, sizeof(int));

    edge_permutation(array, edge_counter, value, mark, solution, n, k, 0);

    free(value);
    free(mark);
    free(solution);
}

int edge_permutation(edge array[], int edge_counter,
    int *value, int *mark, int *solution, int n, int k, int pos) {

    if (pos >= k) {
        check(array, edge_counter, solution, k);
        return 0;
    }

    for (int i = 0; i < edge_counter; i++) {
        if (!mark[i]) {
            mark[i] = 1;
            solution[pos] = value[i];
            edge_permutation(array, edge_counter, value, mark, solution, n, k, pos + 1);
            mark[i] = 0;
        }
    }
    return 0;
}
