#include <stdio.h>
#include <stdlib.h>

void check(int **m, int n, int k);

int main() {
        int i,j;
        int square[6][6] = {
        {0,1,0,1,0,1},
        {1,0,1,0,1,0},
        {0,1,0,0,0,1},
        {1,0,1,0,1,0},
        {0,1,0,0,0,0},
        {3,0,1,0,2,0},
        };
        int *m[6];
        for( i = 0; i < 6; i++) {
                m[i] = (int *)malloc(sizeof(int) * 6);
                if(m[i] == NULL) exit(-1);
        }
        for( i = 0; i < 6; i++) {
                for( j = 0; j < 6; j++ ) {
                        m[i][j] = square[i][j];
                }
        }

        check(m,6,3);


        for( i = 0; i < 6; i++) free(m[i]);
        return 0;
}

void display_sub(int **m, int i, int j, int k) {
        int ik, jk;
        for(ik = 0; ik < k; ik++) {
                for(jk = 0; jk < k; jk++) {
                        printf("%d ",m[i+ik][j+jk]);
                }
                printf("\n");
        }
}

void check(int **m, int n, int k) {
        int i,j; int sum;
        int i_min, j_min = -1;int sum_min;
        int i_max, j_max = -1;int sum_max;

        for( i = 0; i < n-k+1; i++ ) {
                for( j = 0; j < n-k+1; j++) {
                        sum = 0;
                        for(int ik=0; ik<k; ik++) {
                                for(int jk=0;jk<k;jk++) {
                                        sum += m[i+ik][j+jk];
                                }
                        }
                        // update coordinates for max submatrix
                        // if j_max == -1 this is the first time we are
                        // considering a submatrix, so this is the current max
                        // one
                        if( j_max == -1 || sum > sum_max ) {
                                i_max = i;
                                j_max = j;
                                sum_max = sum;
                        }
                        // similarly for min
                        if( j_min == -1 || sum < sum_min ) {
                                i_min = i;
                                j_min = j;
                                sum_min = sum;
                        }
                }
        }
        printf("min submatrix:\n");
        display_sub(m,i_min,j_min,k);

        printf("max submatrix:\n");
        display_sub(m,i_max,j_max,k);
}
