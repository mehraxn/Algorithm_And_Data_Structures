int comb_rep(int *val, int *sol, int n, int k, int start, int count, int pos) {
    int i;

    // Termination condition: if we have filled all positions in the solution array
    if (pos >= k) {
        for (i = 0; i < k; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return count + 1;
    }

    // Iteration on choices: iterate over possible values from 'start' onwards
    for (i = start; i < n; i++) {
        sol[pos] = val[i];  // Fill sol[pos] with the value val[i]
        // Recur to fill the next position
        count = comb_rep(val, sol, n, k, i, count, pos + 1);
    }

    return count;  // Return the total count of combinations
}
