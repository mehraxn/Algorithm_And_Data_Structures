#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
int powerset_ver1(int *value, int *solution, int pos, int k, int start, int count);
int powerset_ver2(int *value, int *solution, int pos, int k, int count);
int powerset_ver3(int *value, int *solution, int k);
int powerset_ver3_r(int *value, int *solution, int k, int n, int pos, int start);

/*
 * main program
 */
int main(int argc, char *argv[]) {
    const int k = 4;
    int value[] = {1, 2, 3, 4};
    int solution[4] = {0, 0, 0, 0};
    int pos = 0;
    int start = 0;
    int count = 0;
    int total;

    fprintf(stdout, "Powerset Version 01:\n");
    total = powerset_ver1(value, solution, pos, k, start, count);
    fprintf(stdout, "\nTotal Number: %d\n", total);

    fprintf(stdout, "Powerset Version 02:\n");
    total = powerset_ver2(value, solution, pos, k, count);
    fprintf(stdout, "\nTotal Number: %d\n", total);

    fprintf(stdout, "Powerset Version 03:\n");
    total = powerset_ver3(value, solution, k);
    fprintf(stdout, "\nTotal Number: %d\n", total);

    return EXIT_SUCCESS;
}

/*
 * Powerset Version 01
 */
int powerset_ver1(int *value, int *solution, int pos, int k, int start, int count) {
    int i;

    if (start >= k) {
        fprintf(stdout, "{ ");
        for (i = 0; i < pos; i++) {
            fprintf(stdout, "%d ", solution[i]);
        }
        fprintf(stdout, "}\n");
        return count + 1;
    }

    for (i = start; i < k; i++) {
        solution[pos] = value[i];
        count = powerset_ver1(value, solution, pos + 1, k, i + 1, count);
    }
    count = powerset_ver1(value, solution, pos, k, k, count);
    return count;
}

/*
 * Powerset Version 02
 */
int powerset_ver2(int *value, int *solution, int pos, int k, int count) {
    int i;

    if (pos >= k) {
        fprintf(stdout, "{ ");
        for (i = 0; i < k; i++) {
            if (solution[i] != 0) {
                fprintf(stdout, "%d ", value[i]);
            }
        }
        fprintf(stdout, "}\n");
        return count + 1;
    }

    solution[pos] = 0;
    count = powerset_ver2(value, solution, pos + 1, k, count);
    solution[pos] = 1;
    count = powerset_ver2(value, solution, pos + 1, k, count);
    return count;
}

/*
 * Powerset Version 03
 */
int powerset_ver3(int *value, int *solution, int k) {
    int count = 0, i;

    for (i = 0; i <= k; i++) {
        count += powerset_ver3_r(value, solution, k, i, 0, 0);
    }

    return count;
}

int powerset_ver3_r(int *value, int *solution, int k, int n, int pos, int start) {
    int count = 0, i;

    if (pos == n) {
        printf("{ ");
        for (i = 0; i < n; i++) {
            printf("%d ", solution[i]);
        }
        printf("}\n");
        return 1;
    }

    for (i = start; i < k; i++) {
        solution[pos] = value[i];
        count += powerset_ver3_r(value, solution, k, n, pos + 1, i + 1);
    }

    return count;
}
