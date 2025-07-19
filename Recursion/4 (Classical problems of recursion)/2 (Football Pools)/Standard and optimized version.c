#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototypes */
char **read_file(int *dim);
void play_r(char **scheme, char *column, int n, int row, FILE *fp);

/*
 * main program
 */
int main (void) {
    char *column, **scheme;
    char filename[20];
    FILE *fp;
    int n, i;

    scheme = read_file(&n);
    column = (char *)malloc((n+1) * sizeof(char));
    if (column == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    column[n] = '\0';

    fprintf(stdout, "Output file name? ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Open file allocation error.\n");
        exit(EXIT_FAILURE);
    }

    play_r(scheme, column, n, 0, fp);
    fclose(fp);

    for (i = 0; i < n; i++) {
        free(scheme[i]);
    }
    free(scheme);
    free(column);

    return EXIT_SUCCESS;
}

/*
 * load the input scheme from file
 */
char **read_file (int *dim) {
    char filename[20], line[10], **scheme;
    int i, n = 0;
    FILE *fp;

    fprintf(stdout, "Input file name? ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    /* count the number of rows */
    while (fscanf(fp, "%s", line) != EOF) {
        n++;
    }
    fclose(fp);

    /* read and store the input scheme */
    scheme = (char **)malloc(n * sizeof(char *));
    if (scheme == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Open file allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++) {
        fscanf(fp, "%s", line);
        scheme[i] = strdup(line);
    }
    fclose(fp);

    *dim = n;
    return scheme;
}

/*
 * column expansion, recursive function
 */
void play_r (char **scheme, char *column, int n, int row, FILE *fp) {
    int i;

    if (row >= n) {
        fprintf(fp, "%s\n", column);
        return;
    }

    for (i = 0; i < strlen(scheme[row]); i++) {
        column[row] = scheme[row][i];
        play_r(scheme, column, n, row + 1, fp);
    }

    return;
}
