#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void single_row (char *string ,int size , int *final_counter ,char *final){

    int i;
    int *x = (int *)calloc(size, sizeof(int));
    for (i = 0; i < size; i++){
        int counter = 1;
        for (int j = 0; j < size; j++){
            if (i == j) continue;
            if (string[i] == string[j]) counter++;
        }
        x[i] = counter;
    }

    int z = 0;
    for (int i = 0; i < size; i++){
        if (x[i] > z) z = x[i];
    }

    if (z > *final_counter) {
        *final_counter = z;
        strncpy(final, string, size);
        final[size] = '\0';
    }

    free(x);
    return;
}

void check(char **m , int n){

    int row = -1;
    int final_counter = 1;
    char *final_string = (char *)malloc((n + 1) * sizeof(char));

    for (int l = 0; l < n; l++){
        single_row(m[l], n, &final_counter, final_string);
    }

    if (final_counter > 1)
        printf("%s\n", final_string);

    free(final_string);
}
