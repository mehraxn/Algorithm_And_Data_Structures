int arr_rep (int *val, int *sol,
             int n, int k, int count, int pos) {

    int i;

    if (pos >= k) {
        for (i = 0; i < k; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count + 1;
    }

    for (i = 0; i < n; i++) {
        sol[pos] = val[i];
        count = arr_rep(val, sol, n, k, count, pos + 1);
    }

    return count;
}
