#include <stdio.h>

int powerset_1 (int *val, int *sol,
int k, int count, int pos) {

    int j;
    if (pos >= k) {
        printf("{ \t");
        for (j = 0; j < k; j++)
            if (sol[j] != 0)
                printf("%d \t", val[j]);
        printf("} \n");
        return count + 1;
    }

    sol[pos] = 0;
    count = powerset_1(val, sol, k, count, pos + 1);
    sol[pos] = 1;
    count = powerset_1(val, sol, k, count, pos + 1);
    return count;
}
