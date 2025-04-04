int perm_rep (int *val_dist, int *sol, int *mark,
              int n, int n_dist, int count, int pos) {

    int i;

    if (pos >= n) {
        for (i = 0; i < n; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return count + 1;
    }

    for (i = 0; i < n_dist; i++) {
        if (mark[i] > 0) {  // Check if occurrences are available
            mark[i]--;  // Use one occurrence of val_dist[i]
            sol[pos] = val_dist[i];  // Place the element in the solution array
            count = perm_rep(val_dist, sol, mark, n, n_dist, count, pos + 1);  // Recur to next position
            mark[i]++;  // Backtrack: restore the occurrence for other iterations
        }
    }

    return count;  // Return the total count of permutations
}
