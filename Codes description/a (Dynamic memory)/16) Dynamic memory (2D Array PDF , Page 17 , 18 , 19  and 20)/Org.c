#include <stdio.h>
#include <stdlib.h>

int **allocate_int_matrix(int *r, int *c) {
    int i;
    int **mat;

    printf("Number of rows: ");
    scanf("%d", r);

    mat = (int **)malloc(*r * sizeof(int *));
    if (mat == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    printf("Number of columns: ");
    scanf("%d", c);

    for (i = 0; i < *r; i++) {
        mat[i] = (int *)malloc(*c * sizeof(int));
        if (mat[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(1);
        }
    }

    return mat;
}


void manipulate_and_free_matrix(int **mat, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Matrix manipulation goes on...

    for (i = 0; i < r; i++) {
        free(mat[i]);
    }
    free(mat);
}


char **allocate_string_matrix(int *r) {
    int i;
    char s[N], **mat;

    printf("Number of rows: ");
    scanf("%d", r);

    mat = (char **)malloc(*r * sizeof(char *));
    if (mat == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    for (i = 0; i < *r; i++) {
        scanf("%s", s);
        mat[i] = malloc((strlen(s) + 1) * sizeof(char));
        if (mat[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(1);
        }
        strcpy(mat[i], s);
    }

    return mat;
}



void sizeof_demo() {
    int mat[6][5];

    // Size calculations for statically allocated array
    printf("sizeof(mat): %lu\n", sizeof(mat));     // 6 * 5 * sizeof(int) = 120
    printf("sizeof(mat[i]): %lu\n", sizeof(mat[0]));  // 5 * sizeof(int) = 20
    printf("sizeof(mat[i][j]): %lu\n", sizeof(mat[0][0])); // sizeof(int) = 4

    int r = 6, c = 5, **dyn_mat;
    dyn_mat = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        dyn_mat[i] = (int *)malloc(c * sizeof(int));
    }

    // Size calculations for dynamically allocated array
    printf("sizeof(dyn_mat): %lu\n", sizeof(dyn_mat));     // Size of pointer, typically 8 (or 4 on 32-bit systems)
    printf("sizeof(dyn_mat[i]): %lu\n", sizeof(dyn_mat[0]));  // Size of pointer, typically 8 (or 4)
    printf("sizeof(dyn_mat[i][j]): %lu\n", sizeof(dyn_mat[0][0])); // sizeof(int) = 4

    for (int i = 0; i < r; i++) {
        free(dyn_mat[i]);
    }
    free(dyn_mat);
}
