#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

void kruskalMST(int matrix[MAX][MAX], int n) {
    struct Edge edges[MAX * MAX];
    int edgeCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = matrix[i][j];
                edgeCount++;
            }
        }
    }

    qsort(edges, edgeCount, sizeof(struct Edge), compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in the Minimum Spanning Tree:\n");

    int mstWeight = 0;
    int edgesUsed = 0;

    for (int i = 0; i < edgeCount && edgesUsed < n - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        int setU = find(u);
        int setV = find(v);

        if (setU != setV) {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(setU, setV);
            edgesUsed++;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int n = 4;
    int matrix[MAX][MAX] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    kruskalMST(matrix, n);

    return 0;
}
