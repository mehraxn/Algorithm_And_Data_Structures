#include <stdio.h>

int perm_rep(int *val_dist, int *sol, int *mark,
             int n, int n_dist, int count, int pos) {
    int i;
    if (pos >= n) {
        for (i = 0; i < n; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count + 1;
    }

    for (i = 0; i < n_dist; i++) {
        if (mark[i] > 0) {
            mark[i]--;
            sol[pos] = val_dist[i];
            count = perm_rep(val_dist, sol, mark, n, n_dist, count, pos + 1);
            mark[i]++;
        }
    }
    return count;
}

int main() {
    int val_dist[] = {1, 2, 3,4,5,6};  // Distinct values
    int n_dist = sizeof(val_dist)/sizeof(val_dist[0]);
    int n = 8;                   // Permutation length
    int sol[n];                  // Solution array
    int mark[] = {1, 1, 1,2,2,1};      // Max occurrences for each value

    int total = perm_rep(val_dist, sol, mark, n, n_dist, 0, 0);
    printf("\nTotal permutations: %d\n", total);
    return 0;
}