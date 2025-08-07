#include <stdio.h>
#include <math.h>

#define MAX 10

// Function prototypes
int det(int m[][MAX], int n);
int det2x2(int m[][MAX]);
void minor(int m[][MAX], int i, int j, int n, int m2[][MAX]);
void printMatrix(int m[][MAX], int n);

int det (int m[] [MAX], int n) {
    int sum, c;
    int tmp[MAX][MAX];
    sum = 0;

    if (n == 2)
        return (det2x2(m));

    for (c=0; c<n; c++) {
        minor (m, 0, c, n, tmp);
        sum = sum + m[0][c] * pow(-1,c) * det (tmp,n-1);
    }

    return (sum);
}

int det2x2(int m[][MAX]) {
    return(m[0][0]*m[1][1] - m[0][1]*m[1][0]);
}

void minor(
    int m[][MAX],int i,int j,int n,int m2[][MAX]
) {
    int r, c, rr, cc;

    for (rr = 0, r = 0; r < n; r++)
        if (r != i) {
            for (cc = 0, c = 0; c < n; c++)
                if (c != j) {
                    m2[rr][cc] = m[r][c];
                    cc++;
                }
            rr++;
        }
}

// Helper function to print matrix
void printMatrix(int m[][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix3x3[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix2x2[MAX][MAX] = {
        {1, 2},
        {3, 4}
    };

    int matrix4x4[MAX][MAX] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("2x2 Matrix:\n");
    printMatrix(matrix2x2, 2);
    printf("Determinant: %d\n\n", det(matrix2x2, 2));

    printf("3x3 Matrix:\n");
    printMatrix(matrix3x3, 3);
    printf("Determinant: %d\n\n", det(matrix3x3, 3));

    printf("4x4 Matrix:\n");
    printMatrix(matrix4x4, 4);
    printf("Determinant: %d\n\n", det(matrix4x4, 4));

    return 0;
}