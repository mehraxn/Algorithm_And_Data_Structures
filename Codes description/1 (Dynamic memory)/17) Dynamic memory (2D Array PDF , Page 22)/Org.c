char **malloc2d(int r, int c) {
    int i;
    char **mat;

    // Allocate memory for row pointers
    mat = (char **) malloc(r * sizeof(char *));
    if (mat == NULL) {
        // Handle memory allocation error
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Allocate memory for each row
    for (i = 0; i < r; i++) {
        mat[i] = (char *) malloc(c * sizeof(char));
        if (mat[i] == NULL) {
            // Handle memory allocation error
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            fprintf(stderr, "Memory allocation error.\n");
            exit(1);
        }
    }

    return mat;
}
