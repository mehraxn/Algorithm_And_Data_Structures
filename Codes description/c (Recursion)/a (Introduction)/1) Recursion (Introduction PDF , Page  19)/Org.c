#include <stdio.h>

// First version of show function
void show1(int v[], int l, int r) {
    int i, c;
    printf("v = ");
    for (i = l; i <= r; i++)
        printf("%d ", v[i]);
    printf("\n");
    if (l >= r) {
        return;
    }
    c = (r + l) / 2;
    show1(v, l, c);
    show1(v, c + 1, r);
    return;
}

// Second version of show function
void show2(int v[], int l, int r) {
    int i, c;
    if (l >= r) {
        return;
    }
    printf("v = ");
    for (i = l; i <= r; i++)
        printf("%d ", v[i]);
    printf("\n");
    c = (r + l) / 2;
    show2(v, l, c);
    show2(v, c + 1, r);
    return;
}
