#include <stdio.h>
#include <stdlib.h>

int isCorrect(int vertex, int **matrix, int *colors, int color, int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int generate_color(int vertex, int **matrix, int *colors, int numColors, int n) {
    if (vertex == n) {
        return 1;
    }

    for (int color = 1; color <= numColors; color++) {
        if (isCorrect(vertex, matrix, colors, color, n)) {
            colors[vertex] = color;

            if (generate_color(vertex + 1, matrix, colors, numColors, n)) {
                return 1;
            }

            colors[vertex] = 0;
        }
    }

    return 0;
}

void color(int **matrix, int n) {
    int *colors = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }
    int numColors = 1;

    while (!generate_color(0, matrix, colors, numColors, n)) {
        numColors++;
    }

    printf("Vertex;  Color\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }

    free(colors);
}

int** readAdjacencyMatrixFromFile(char* filename, int* n) {
    FILE* fin = fopen(filename, "r");
    if (fin == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    fscanf(fin, "%d", n);
    int** matrix = (int**)malloc(*n * sizeof(int*));
    for (int i = 0; i < *n; i++) {
        matrix[i] = (int*)malloc(*n * sizeof(int));
        for (int j = 0; j < *n; j++) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }

    fclose(fin);
    return matrix;
}

int main() {
    char* filename = "adjmatrix.txt";
    int n = 0;
    int** matrix = readAdjacencyMatrixFromFile(filename, &n);
    if (matrix == NULL) {
        return 1;
    }
    color(matrix, n);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
