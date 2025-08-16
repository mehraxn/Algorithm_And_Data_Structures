void free2d(char ***m, int r) {
    char **lm;
    int i;

    // Set lm to the address of the matrix
    lm = *m;

    // Free each row
    for (i = 0; i < r; i++) {
        free(lm[i]);
    }

    // Free the row pointers
    free(lm);

    // Set the pointer to NULL to avoid dangling pointers
    *m = NULL;

    return;
}
