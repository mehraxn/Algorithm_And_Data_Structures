int perm (int *val, int *sol, int *mark,
          int n, int count, int pos) {

    int i;

    if (pos >= n) {
        for (i = 0; i < n; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count + 1;
    }

    for (i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            sol[pos] = val[i];
            count = perm(val, sol, mark, n, count, pos + 1);
            mark[i] = 0;
        }
    }

    return count;
}
