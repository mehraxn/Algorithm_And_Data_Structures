#include <stdio.h>
#include <stdlib.h>

int time_counter = 0;

void dfs_util(int **graph, int n, int vertex, int *visited, int *discovery, int *finish) {
    visited[vertex] = 1;
    discovery[vertex] = ++time_counter;

    printf("Discovered vertex %d at time %d\n", vertex, discovery[vertex]);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs_util(graph, n, i, visited, discovery, finish);
        }
    }

    finish[vertex] = ++time_counter;
    printf("Finished vertex %d at time %d\n", vertex, finish[vertex]);
}

void dfs(int **graph, int n, int *discovery, int *finish) {
    int *visited = (int*)calloc(n, sizeof(int));
    time_counter = 0;

    for (int i = 0; i < n; i++) {
        discovery[i] = -1;
        finish[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("\nStarting DFS from vertex %d:\n", i);
            dfs_util(graph, n, i, visited, discovery, finish);
        }
    }

    free(visited);
}
