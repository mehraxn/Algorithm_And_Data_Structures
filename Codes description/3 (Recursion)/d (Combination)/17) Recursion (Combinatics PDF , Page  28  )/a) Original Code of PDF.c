int arr (int *val, int *sol, int *mark,
         int n, int k, int count, int pos) {

    int i;

    if (pos >= k) {
        for (i = 0; i < k; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count + 1;
    }

    for (i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            sol[pos] = val[i];
            count = arr(val, sol, mark, n, k, count, pos + 1);
            mark[i] = 0;
        }
    }

    return count;
}
