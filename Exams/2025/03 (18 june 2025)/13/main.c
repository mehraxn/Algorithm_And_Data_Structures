#include <stdlib.h>
#include <string.h>
#include <float.h>

const int dr[]   = { -1,  1,  0,  0,  -2,  2,  0,  0,  -3,  3,  0,  0 };
const int dc[]   = {  0,  0, -1,  1,   0,  0, -2,  2,   0,  0, -3,  3 };
const float cost[] = { 0.3f,0.3f,0.3f,0.3f, 0.2f,0.2f,0.2f,0.2f, 0.1f,0.1f,0.1f,0.1f };
const int M = 12;

int in_bounds(int n, int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void dfs_best_path(
    int **mat, int **visited, int **bestMat,
    int r0, int c0, int step, float curCost, float *bestCost,
    int n
) {
    int i;
    if (curCost >= *bestCost) return;
    if (step == n * n - 1) {
        *bestCost = curCost;
        for (i = 0; i < n; ++i) memcpy(bestMat[i], mat[i], n * sizeof(int));
        return;
    }
    for (i = 0; i < M; ++i) {
        int nr = r0 + dr[i];
        int nc = c0 + dc[i];
        if (!in_bounds(n, nr, nc)) continue;
        if (visited[nr][nc]) continue;
        visited[nr][nc] = 1;
        mat[nr][nc] = step + 1;
        dfs_best_path(mat, visited, bestMat, nr, nc, step + 1,
                      curCost + cost[i], bestCost, n);
        visited[nr][nc] = 0;
        mat[nr][nc] = -1;
    }
}

float visit(int **board, int n, int r, int c) {
    int i, j;
    if (n <= 0 || board == 0 || !in_bounds(n, r, c)) return 0.0f;

    int **visited = (int **)malloc(n * sizeof(*visited));
    int **cur  = (int **)malloc(n * sizeof(*cur));
    int **best = (int **)malloc(n * sizeof(*best));
    if (!visited || !cur || !best) { free(visited); free(cur); free(best); return 0.0f; }

    for (i = 0; i < n; ++i) {
        visited[i] = (int *)calloc(n, sizeof(int));
        cur[i]  = (int *)malloc(n * sizeof(int));
        best[i] = (int *)malloc(n * sizeof(int));
        if (!visited[i] || !cur[i] || !best[i]) {
            int k; for (k = 0; k <= i; ++k) { free(visited[k]); free(cur[k]); free(best[k]); }
            free(visited); free(cur); free(best); return 0.0f;
        }
        for (j = 0; j < n; ++j) { cur[i][j] = -1; best[i][j] = -1; }
    }

    visited[r][c] = 1;
    cur[r][c] = 0;

    {
        float bestCost = FLT_MAX;
        dfs_best_path(cur, visited, best, r, c, 0, 0.0f, &bestCost, n);
        if (bestCost < FLT_MAX) {
            for (i = 0; i < n; ++i) memcpy(board[i], best[i], n * sizeof(int));
        } else {
            bestCost = 0.0f;
        }
        for (i = 0; i < n; ++i) { free(visited[i]); free(cur[i]); free(best[i]); }
        free(visited); free(cur); free(best);
        return bestCost;
    }
}
