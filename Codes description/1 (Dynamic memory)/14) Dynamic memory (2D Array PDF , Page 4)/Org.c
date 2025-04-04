#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100  // Maximum size of the static strings

typedef struct e_s {
    char str[N];  // Static string of size N
} e_t;

void fillArray(e_t *v, int n) {
    for (int i = 0; i < n; i++) {
        snprintf(v[i].str, N, "String %d", i + 1);  // Fill each string with example text
    }
}

void printArray(e_t *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", v[i].str);  // Print each string
    }
}

