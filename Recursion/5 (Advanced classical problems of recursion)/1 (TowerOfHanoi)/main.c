#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void hanoi_r(int n, int src, int dst);

/*
  main program
*/
int main(void) {
    int n;
    fprintf(stdout, "Number of disks: ");
    scanf("%d", &n);
    hanoi_r(n, 0, 2);  // Start with peg A (0) to peg C (2)

    return EXIT_SUCCESS;
}

/* Generate the Hanoi moves using recursion */
void hanoi_r(int n, int src, int dst) {
    int aux;

    if (n > 0) {
        aux = 3 - (src + dst);  // Calculate auxiliary peg (0=A, 1=B, 2=C)
        hanoi_r(n - 1, src, aux);
        fprintf(stdout, "Disk %d from peg %c to peg %c\n",
                n, 'A' + src, 'A' + dst);
        hanoi_r(n - 1, aux, dst);
    }
    return;
}