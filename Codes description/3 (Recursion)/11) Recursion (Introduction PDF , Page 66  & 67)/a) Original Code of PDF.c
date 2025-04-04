// Function to calculate the determinant of an n x n matrix using recursion
int det(int m[][MAX], int n) {
    int sum, c;
    int tmp[MAX][MAX];
    sum = 0;

    // Base case for 2x2 matrix
    if (n == 2)
        return (det2x2(m));

    // Iterate through each column to expand along the first row
    for (c = 0; c < n; c++) {
        // Create the minor matrix by excluding the current row and column
        minor(m, 0, c, n, tmp);
        // Calculate the determinant recursively
        sum = sum + m[0][c] * pow(-1, c) * det(tmp, n - 1);
    }

    return sum;
}

// Function to calculate the determinant of a 2x2 matrix
int det2x2(int m[][MAX]) {
    return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
}

// Function to create a minor matrix by excluding a given row and column
void minor(int m[][MAX], int i, int j, int n, int m2[][MAX]) {
    int r, c, rr, cc;
    for (rr = 0, r = 0; r < n; r++) {
        if (r != i) {
            for (cc = 0, c = 0; c < n; c++) {
                if (c != j) {
                    m2[rr][cc] = m[r][c];
                    cc++;
                }
            }
            rr++;
        }
    }
}