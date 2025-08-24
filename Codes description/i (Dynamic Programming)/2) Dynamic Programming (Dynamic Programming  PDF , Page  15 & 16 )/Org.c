void matrix_multiply(int r1, int c1, int c2, int m1[r1][c1], int m2[c1][c2], int m[r1][c2]) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            m[i][j] = 0;
            for (k = 0; k < c1; k++) {
                m[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
