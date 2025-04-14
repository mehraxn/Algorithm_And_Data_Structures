#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define EMPTY ' '
#define START '@'
#define STOP '#'
#define PATH '%'
#define DONE '.'

const int xoff[4] = { 0, 1, 0, -1 };
const int yoff[4] = { -1, 0, 1, 0 };

void display(char **maze, int nr);
int move_r_one(char **mazeCurr, int nr, int nc, int row, int col);
int move_r_all(char **mazeCurr, int nr, int nc, int row, int col, int row0, int col0);
int move_r_best(char **mazeCurr, int stepCurr, char **mazeBest, int stepBest, int nr, int nc, int row, int col);
FILE *util_fopen(char *name, char *mode);
void *util_malloc(int size);
char *util_strdup(char *src);

int main(int argc, char *argv[]) {
    int r = -1, c = -1, i, j, nr, nc, res;
    char **mazeCurr, **mazeBest;
    char line[MAX];
    FILE *fp;

    if (argc < 2) {
        fprintf(stdout, "Error: missing parameter.\n");
        fprintf(stdout, "Run as: %s <maze_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = util_fopen(argv[1], "r");
    fgets(line, MAX, fp);
    sscanf(line, "%d %d", &nr, &nc);

    mazeCurr = (char **)util_malloc(nr * sizeof(char *));
    mazeBest = (char **)util_malloc(nr * sizeof(char *));

    for (i = 0; i < nr; i++) {
        fgets(line, MAX, fp);
        mazeCurr[i] = util_strdup(line);
        mazeBest[i] = util_strdup(line);
        for (j = 0; j < nc; j++) {
            if (mazeCurr[i][j] == START) {
                r = i;
                c = j;
            }
        }
    }

    if (r < 0 || c < 0) {
        fprintf(stdout, "Error: no starting position found!\n");
        exit(EXIT_FAILURE);
    }

    // Find one solution
    fprintf(stdout, "Find one solution:\n");
    mazeCurr[r][c] = EMPTY;
    res = move_r_one(mazeCurr, nr, nc, r, c);
    if (res == 1) {
        mazeCurr[r][c] = START;
        display(mazeCurr, nr);
    } else {
        fprintf(stdout, "NO solution found!\n");
    }

    // Clean matrix
    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            if (mazeCurr[i][j] == PATH || mazeCurr[i][j] == DONE) {
                mazeCurr[i][j] = EMPTY;
            }
        }
    }

    // Find all solutions
    fprintf(stdout, "Find all solutions:\n");
    mazeCurr[r][c] = EMPTY;
    res = move_r_all(mazeCurr, nr, nc, r, c, r, c);

    // Find the best solution
    fprintf(stdout, "Find the best solution:\n");
    mazeCurr[r][c] = EMPTY;
    res = move_r_best(mazeCurr, 0, mazeBest, nr * nc, nr, nc, r, c);
    if (res > 0) {
        fprintf(stdout, "Solution:\n");
        mazeBest[r][c] = START;
        display(mazeBest, nr);
    } else {
        fprintf(stdout, "NO solution found!\n");
    }

    for (i = 0; i < nr; i++) {
        free(mazeCurr[i]);
        free(mazeBest[i]);
    }
    free(mazeCurr);
    free(mazeBest);
    return EXIT_SUCCESS;
}

// Find the first solution
int move_r_one(char **mazeCurr, int nr, int nc, int row, int col) {
    int k, r, c;

    if (mazeCurr[row][col] == STOP) return 1;
    if (mazeCurr[row][col] != EMPTY) return 0;

    mazeCurr[row][col] = PATH;
    for (k = 0; k < 4; k++) {
        r = row + xoff[k];
        c = col + yoff[k];
        if (r >= 0 && r < nr && c >= 0 && c < nc) {
            if (move_r_one(mazeCurr, nr, nc, r, c) == 1) return 1;
        }
    }
    mazeCurr[row][col] = DONE;
    return 0;
}

// Find all solutions
int move_r_all(char **mazeCurr, int nr, int nc, int row, int col, int row0, int col0) {
    int k, r, c;
    static int solN = 0;

    if (mazeCurr[row][col] == STOP) {
        solN++;
        fprintf(stdout, "Solution #%d:\n", solN);
        mazeCurr[row0][col0] = START;
        display(mazeCurr, nr);
        mazeCurr[row0][col0] = EMPTY;
        return 1;
    }

    if (mazeCurr[row][col] != EMPTY) return 0;

    mazeCurr[row][col] = PATH;
    for (k = 0; k < 4; k++) {
        r = row + xoff[k];
        c = col + yoff[k];
        if (r >= 0 && r < nr && c >= 0 && c < nc) {
            move_r_all(mazeCurr, nr, nc, r, c, row0, col0);
        }
    }
    mazeCurr[row][col] = EMPTY;
    return 0;
}

// Find the best solution
int move_r_best(char **mazeCurr, int stepCurr, char **mazeBest, int stepBest, int nr, int nc, int row, int col) {
    int k, r, c;

    if (stepCurr >= stepBest) return stepBest;
    if (mazeCurr[row][col] == STOP) {
        if (stepCurr < stepBest) {
            stepBest = stepCurr;
            for (r = 0; r < nr; r++) {
                for (c = 0; c < nc; c++) {
                    mazeBest[r][c] = mazeCurr[r][c];
                }
            }
        }
        return stepBest;
    }
    if (mazeCurr[row][col] != EMPTY) return stepBest;

    mazeCurr[row][col] = PATH;
    for (k = 0; k < 4; k++) {
        r = row + xoff[k];
        c = col + yoff[k];
        if (r >= 0 && r < nr && c >= 0 && c < nc) {
            stepBest = move_r_best(mazeCurr, stepCurr + 1, mazeBest, stepBest, nr, nc, r, c);
        }
    }
    mazeCurr[row][col] = EMPTY;
    return stepBest;
}

// Display the maze
void display(char **maze, int nr) {
    int i;
    for (i = 0; i < nr; i++) {
        fprintf(stdout, "%s", maze[i]);
    }
}

// Utility functions
FILE *util_fopen(char *name, char *mode) {
    FILE *fp = fopen(name, mode);
    if (fp == NULL) {
        fprintf(stdout, "File open error (file=%s).\n", name);
        exit(EXIT_FAILURE);
    }
    return fp;
}

void *util_malloc(int size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stdout, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

char *util_strdup(char *src) {
    char *dst = strdup(src);
    if (dst == NULL) {
        fprintf(stdout, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    return dst;
}