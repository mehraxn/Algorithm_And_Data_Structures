#include <stdio.h>
#include <stdlib.h>

void DFS(int **graph, int *marked, int n,int k, int vert, int start, int *count, int *path, int fixed_k)
{
    marked[vert] = 1;
    path[k] = vert;

    if (k == 0) {
        marked[vert] = 0;
        if (graph[vert][start]) {
            (*count)++;
            printf("Cycle %d: ", *count);
            for (int i = fixed_k - 1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }
        else
            return;
    }

    for (int i = 0; i < n; i++) {
        if (!marked[i] && graph[vert][i])
            DFS(graph, marked,n, k- 1, i, start, count, path, fixed_k);
    }

    marked[vert] = 0;
}

void loop(int **mat, int n, int k)
{
    int *marked = (int *)calloc(n, sizeof(int));
    int count = 0;
    int *path = (int *)calloc(k + 1, sizeof(int));
    int fixed_k = k;
    for (int i = 0; i < n; i++) {
        DFS(mat, marked,n, k - 1, i, i, &count, path, fixed_k);
    }

    printf("Total cycles of length %d are %d\n", k, count);

    free(marked);
    free(path);
}

int main()
{
    int k = 3;
    int n = 4;

    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    mat[0][0] = 0; mat[0][1] = 1; mat[0][2] = 1; mat[0][3] = 0;
    mat[1][0] = 0; mat[1][1] = 0; mat[1][2] = 1; mat[1][3] = 0;
    mat[2][0] = 0; mat[2][1] = 0; mat[2][2] = 0; mat[2][3] = 1;
    mat[3][0] = 1; mat[3][1] = 0; mat[3][2] = 0; mat[3][3] = 0;

    loop(mat, n, k);

    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
