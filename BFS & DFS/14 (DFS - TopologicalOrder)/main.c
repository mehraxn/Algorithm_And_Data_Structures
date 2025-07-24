#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void DFS(int u, int nv, int adj[][MAX_VERTICES], int *visited, int *scc_array, int isTranspose, int scc_id, int *stack, int *top) {
    visited[u] = 1;
    scc_array[u] = scc_id;

    for (int v = 0; v < nv; v++) {
        int edge = isTranspose ? adj[v][u] : adj[u][v];
        if (edge && !visited[v]) {
            DFS(v, nv, adj, visited, scc_array, isTranspose, scc_id, stack, top);
        }
    }

    if (!isTranspose) {
        stack[++(*top)] = u;
    }
}

int* getSCCFromMatrix(int nv, int adj[][MAX_VERTICES]) {
    int *visited = malloc(nv * sizeof(int));
    int *scc_array = malloc(nv * sizeof(int));
    int stack[MAX_VERTICES];
    int top = -1;

    for (int i = 0; i < nv; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < nv; i++) {
        if (!visited[i]) {
            DFS(i, nv, adj, visited, scc_array, 0, -1, stack, &top);
        }
    }

    for (int i = 0; i < nv; i++) {
        for (int j = i + 1; j < nv; j++) {
            int tmp = adj[i][j];
            adj[i][j] = adj[j][i];
            adj[j][i] = tmp;
        }
    }

    for (int i = 0; i < nv; i++) {
        visited[i] = 0;
    }

    int scc_id = 0;
    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            DFS(v, nv, adj, visited, scc_array, 1, scc_id++, stack, &top);
        }
    }

    free(visited);
    return scc_array;
}

int main() {
    int nv = 5;
    int adj[MAX_VERTICES][MAX_VERTICES] = {
        {0,1,0,0,0},
        {0,0,1,0,0},
        {1,0,0,1,0},
        {0,0,0,0,1},
        {0,0,0,1,0}
    };

    int *scc = getSCCFromMatrix(nv, adj);
    for (int i = 0; i < nv; i++) {
        printf("Vertex %d is in SCC %d\n", i, scc[i]);
    }

    free(scc);
    return 0;
}
