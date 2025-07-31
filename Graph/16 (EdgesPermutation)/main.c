#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int src;
    int destination;
    int weight;
} edge;

edge *build_edge_array(int row, int col, int matrix[row][col], int *counter) {

    *counter = 0;
    edge *edges = malloc(sizeof(edge) * row * col);
    if (!edges) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] > 0) {
                edges[*counter].src         = i;
                edges[*counter].destination = j;
                edges[*counter].weight      = matrix[i][j];
                (*counter)++;
            }
        }
    }
    return edges;
}

void find_the_best_path(int *solution,
                        int k,
                        edge *edges,
                        int *maxNumber,
                        int *bestVertices,
                        int *bestLen)
{
    for (int i = 0; i + 1 < k; i++) {
        if (edges[ solution[i] ].destination != edges[ solution[i+1] ].src)
            return;
    }

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += edges[ solution[i] ].weight;

    if (sum > *maxNumber) {
        *maxNumber = sum;
        *bestLen   = k;
        for (int i = 0; i < k; i++)
            bestVertices[i] = solution[i];
    }
}

// Generate all k‐permutations of the edge‐indices in value[0..n),
// track which are used in mark[], build each candidate in solution[].
void permute_edges(int *value,
                   int *solution,
                   int *mark,
                   int n,
                   int k,
                   int pos,
                   edge *edges,
                   int *maxNumber,
                   int *bestVertices,
                   int *bestLen)
{
    if (pos == k) {
        find_the_best_path(solution, k, edges, maxNumber, bestVertices, bestLen);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            mark[i] = 1;
            solution[pos] = value[i];
            permute_edges(value, solution, mark,
                          n, k, pos+1,
                          edges, maxNumber, bestVertices, bestLen);
            mark[i] = 0;
        }
    }
}

int main(void) {
    int matrix[6][6] = {
        {  0,   0,   0,   0,   0,   3},
        {  0,   0,  73,   0,   0,   0},
        {  0,   0,   0,   0, 193,   0},
        {  0,   0,   0,   0,   0,   5},
        {  0,   0,   0,  61,   0,   0},
        {137,   0,   0,   0,   0,   0}
    };

    int edgeCount;
    edge *edges = build_edge_array(6, 6, matrix, &edgeCount);

    int maxWeight = INT_MIN;
    int *bestPath      = malloc(sizeof(int) * edgeCount);
    int *value         = malloc(sizeof(int) * edgeCount);
    int *solution      = malloc(sizeof(int) * edgeCount);
    int *mark          = calloc(edgeCount, sizeof(int));
    int bestLen        = 0;

    // initialize the list of available edge‐indices [0..edgeCount)
    for (int i = 0; i < edgeCount; i++)
        value[i] = i;

    // try all path‐lengths from 1 up to edgeCount
    for (int k = 1; k <= edgeCount; k++) {
        permute_edges(value, solution, mark,
                      edgeCount, k, 0,
                      edges, &maxWeight, bestPath, &bestLen);
    }

    // output result
    printf("Max weight: %d\n", maxWeight);
    printf("Path (edge indices in the array):");
    for (int i = 0; i < bestLen; i++)
        printf(" %d", bestPath[i]);
    printf("\n");

    // clean up
    free(edges);
    free(bestPath);
    free(value);
    free(solution);
    free(mark);

    return 0;
}
