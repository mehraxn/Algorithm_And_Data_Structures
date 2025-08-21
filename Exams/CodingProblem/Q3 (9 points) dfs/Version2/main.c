#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_ROWS 100
#define MAX_COLS 100

/* Single function that does both setup and recursion */
void dfs(int **mat, int r, int c,
         /* in/out: these are used only to read results after call returns */
         int best_path[MAX_ROWS][MAX_COLS],
         int worst_path[MAX_ROWS][MAX_COLS],
         int *max_sum)
{
    /* --- static storage used for recursion; initialized on first call --- */
    static int initialized = 0;
    static int visited[MAX_ROWS][MAX_COLS];
    static int cur_path[MAX_ROWS][MAX_COLS];
    static int best_len, worst_len;

    /* entry-point setup */
    if (!initialized) {
        memset(visited, 0, sizeof(visited));
        memset(cur_path, 0, sizeof(cur_path));
        memset(best_path, 0, MAX_ROWS * MAX_COLS * sizeof(int));
        memset(worst_path, 0, MAX_ROWS * MAX_COLS * sizeof(int));
        *max_sum = INT_MIN;   /* allow negative matrices */
        best_len = 0;
        worst_len = 0;
        initialized = 1;

        /* start real recursion from (0,0) with its value and length=1 */
        dfs(mat, r, c, best_path, worst_path, max_sum);
        initialized = 0;      /* reset for next external call */
        return;
    }

    /* --- recursive body (uses top of recursion's coordinates) --- */
    static int row_stack[MAX_ROWS * MAX_COLS];
    static int col_stack[MAX_ROWS * MAX_COLS];
    static int sum_stack[MAX_ROWS * MAX_COLS];
    static int len_stack[MAX_ROWS * MAX_COLS];
    static int sp = -1; /* stack pointer */

    /* first real frame push: (0,0) */
    if (sp < 0) {
        row_stack[++sp] = 0;
        col_stack[sp]   = 0;
        sum_stack[sp]   = mat[0][0];
        len_stack[sp]   = 1;
    }

    static const int directions[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        { 0,-1},        { 0,1},
        { 1,-1},{ 1,0},{ 1,1}
    };

    /* Manual DFS using our stacks to stay within a single function */
    while (sp >= 0) {
        int row = row_stack[sp];
        int col = col_stack[sp];
        int cur_sum = sum_stack[sp];
        int cur_len = len_stack[sp];

        if (!visited[row][col]) {
            visited[row][col] = 1;
            cur_path[row][col] = 1;

            /* goal? */
            if (row == r - 1 && col == c - 1) {
                if (cur_sum > *max_sum) {
                    *max_sum  = cur_sum;
                    best_len  = cur_len;
                    worst_len = cur_len;
                    for (int i = 0; i < r; ++i)
                        for (int j = 0; j < c; ++j) {
                            best_path[i][j]  = cur_path[i][j];
                            worst_path[i][j] = cur_path[i][j];
                        }
                } else if (cur_sum == *max_sum) {
                    if (best_len == 0 || cur_len < best_len) {
                        best_len = cur_len;
                        for (int i = 0; i < r; ++i)
                            for (int j = 0; j < c; ++j)
                                best_path[i][j] = cur_path[i][j];
                    }
                    if (cur_len > worst_len) {
                        worst_len = cur_len;
                        for (int i = 0; i < r; ++i)
                            for (int j = 0; j < c; ++j)
                                worst_path[i][j] = cur_path[i][j];
                    }
                }
            }

            /* push first unvisited neighbor (if any) */
            int pushed = 0;
            for (int d = 0; d < 8 && !pushed; ++d) {
                int nr = row + directions[d][0];
                int nc = col + directions[d][1];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && !visited[nr][nc]) {
                    row_stack[++sp] = nr;
                    col_stack[sp]   = nc;
                    sum_stack[sp]   = cur_sum + mat[nr][nc];
                    len_stack[sp]   = cur_len + 1;
                    pushed = 1;
                }
            }

            if (pushed) continue; /* go deeper */
        }

        /* backtrack from current cell */
        cur_path[row][col] = 0;
        visited[row][col] = 0;
        --sp;

        /* after backtracking, try to find another neighbor of the previous frame */
        if (sp >= 0) {
            int prow = row_stack[sp];
            int pcol = col_stack[sp];
            int psum = sum_stack[sp];
            int plen = len_stack[sp];

            /* resume search from last tried direction: we recompute and skip visited */
            int advanced = 0;
            for (int d = 0; d < 8; ++d) {
                int nr = prow + directions[d][0];
                int nc = pcol + directions[d][1];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && !visited[nr][nc]) {
                    row_stack[++sp] = nr;
                    col_stack[sp]   = nc;
                    sum_stack[sp]   = psum + mat[nr][nc];
                    len_stack[sp]   = plen + 1;
                    advanced = 1;
                    break;
                }
            }
            if (advanced) continue;
        }
    }
}

int main(void)
{
    int r = 3, c = 3;

    int **mat = malloc(r * sizeof(int *));
    int sample[3][3] = {
        {1, 2, 3},
        {9, 7, 4},
        {1, 2, 8}
    };
    for (int i = 0; i < r; ++i) {
        mat[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; ++j) mat[i][j] = sample[i][j];
    }

    int best_path[MAX_ROWS][MAX_COLS] = {0};
    int worst_path[MAX_ROWS][MAX_COLS] = {0};
    int max_sum;

    /* Only two functions exist: main and dfs. dfs does setup + recursion. */
    dfs(mat, r, c, best_path, worst_path, &max_sum);

    printf("Maximum sum = %d\n\n", max_sum);

    printf("BEST path (shortest among max-sum):\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) printf("%d ", best_path[i][j]);
        printf("\n");
    }

    printf("\nWORST path (longest among max-sum):\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) printf("%d ", worst_path[i][j]);
        printf("\n");
    }

    for (int i = 0; i < r; ++i) free(mat[i]);
    free(mat);
    return 0;
}
