#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 10

int dim(char *);
char **read_file(char *, int *);
void generate_patterns(char **, char *, int, int);

int main() {
    char file_name[MAX_STRING];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    int dimension;
    char **matrix = read_file(file_name, &dimension);
    if (matrix == NULL) {
        return -1;
    }

    char result[dimension + 1];
    result[dimension] = '\0';
    generate_patterns(matrix, result, 0, dimension);

    for (int i = 0; i < dimension; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int dim(char *file_name) {
    FILE *fp;
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Error opening the file %s\n", file_name);
        return -1;
    }

    char temp[MAX_STRING];
    int dim = 0;
    while ((fscanf(fp, "%s", temp)) != EOF)
        dim++;

    fclose(fp);
    return dim;
}

char **read_file(char *file_name, int *dimension) {
    FILE *fp;
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Error opening the file %s\n", file_name);
        return NULL;
    }

    *dimension = dim(file_name);
    if (*dimension == -1) {
        fclose(fp);
        return NULL;
    }

    char **matrix = (char **)malloc((*dimension) * sizeof(char *));
    if (matrix == NULL) {
        fprintf(stderr, "Error in memory allocation\n");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < *dimension; i++) {
        matrix[i] = (char *)malloc(MAX_STRING * sizeof(char));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(matrix[j]);
            free(matrix);
            fclose(fp);
            return NULL;
        }
        fscanf(fp, "%s", matrix[i]);
    }

    fclose(fp);
    return matrix;
}

void generate_patterns(char **matrix, char *result, int pos, int dimension) {
    if (pos == dimension) {
        printf("%s\n", result);
        return;
    }

    for (int i = 0; i < strlen(matrix[pos]); i++) {
        result[pos] = matrix[pos][i];
        generate_patterns(matrix, result, pos + 1, dimension);
    }
}
