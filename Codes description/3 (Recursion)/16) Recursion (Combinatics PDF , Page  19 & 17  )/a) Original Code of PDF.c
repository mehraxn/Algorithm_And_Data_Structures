int mult_princ (val_t *val, int *sol,
                int n, int count, int pos) {

    int i;

    if (pos >= n) {
        for (i = 0; i < n; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count+1;
    }

    for (i = 0; i < val[pos].num_choice; i++) {
        sol[pos] = val[pos].choices[i];
        count = mult_princ(val, sol, n, count, pos+1);
    }

    return count;
}
