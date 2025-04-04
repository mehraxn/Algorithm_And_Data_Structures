#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 100

// Function prototypes
char **read_file(int *dim);
void play_r(char **scheme, char *column, int n, int row, FILE *fp);

// Main program
int main(void) {
    char **scheme, *column;
    char filename[20];
    FILE *fp;
    int n;

    scheme = read_file(&n);
    column = (char *)malloc((n + 1) * sizeof(char));
    if (column == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    column[n] = '\0';

    printf("Output file name? ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open output file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    play_r(scheme, column, n, 0, fp);
    fclose(fp);

    for (int i = 0; i < n; i++) {
        free(scheme[i]);
    }
    free(scheme);
    free(column);

    return EXIT_SUCCESS;
}

// Function to load the input scheme from file
char **read_file(int *dim) {
    char **scheme, filename[20], line[10];
    int i = 0;
    FILE *fp;

    printf("Input file name? ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open input file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Count the number of rows
    while (fscanf(fp, "%s", line) != EOF) {
        i++;
    }
    fclose(fp);

    *dim = i;
    scheme = (char **)malloc(i * sizeof(char *));
    fp = fopen(filename, "r");
    for (i = 0; i < *dim; i++) {
        fscanf(fp, "%s", line);
        scheme[i] = strdup(line);
    }
    fclose(fp);

    return scheme;
}

// Column expansion, recursive function
void play_r(char **scheme, char *column, int n, int row, FILE *fp) {
    int i;
    if (row == n) {
        fprintf(fp, "%s\n", column);
        return;
    }

    for (i = 0; i < strlen(scheme[row]); i++) {
        column[row] = scheme[row][i];
        play_r(scheme, column, n, row + 1, fp);
    }

    return;
}
