#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculator(int *v, int n, int result);

int main() {
        int v[] = {3,2,25,5};
        calculator(v,4,5);
}

int calculate(int *numbers, char *symbols, int n) {
        int result = numbers[0];
        for(int i=1;i<n;i++) {
                switch(symbols[i-1]) {
                        case '+':
                                result += numbers[i];
                                break;
                        case '-':
                                result -= numbers[i];
                                break;
                        case '*':
                                result *= numbers[i];
                                break;
                        case '/':
                                result /= numbers[i];
                                break;
                }
        }
        return result;
}

void evalute_expression(int *numbers, char *symbols, int n, int result) {
        int i,res;
        if( (res = calculate(numbers, symbols, n)) == result ) {
                printf(" %d",numbers[0]);
                for(i=0;i<n-1;i++) {
                        printf(" %c",symbols[i]);
                        printf(" %d",numbers[i+1]);
                }
                printf(" = %d\n", res);
        }
}

void perm_rep(char *val_dist, char *sol, int *mark, int n, int n_dist, int pos, int *numbers, int result) {
        int i;
        if(pos >= n) {
                evalute_expression(numbers, sol, n+1, result);
                return;
        }
        for(i=0;i<n_dist;i++) {
                if( mark[i] > 0 ) {
                        mark[i]--;
                        sol[pos] = val_dist[i];
                        perm_rep(val_dist, sol, mark, n, n_dist, pos+1, numbers, result);
                        mark[i]++;
                }
        }
}

void call_second_rec(int *numbers, int n, int result) {
        char symbols[] = {'+','-','*','/'};
        char *sol = (char *)malloc(sizeof(char) * (n-1));
        int  *mark = (int *)malloc(sizeof(int)  * (n-1));
        for(int i = 0; i < 4; i++ ) mark[i] = n-1;
        perm_rep(symbols,sol,mark,n-1,4,0,numbers,result);
}

void perm(int *val, int *sol, int *mark, int n, int pos, int result) {
        int i;
        if(pos >= n) {
                // here we have a permutation ready to be evaluated
                call_second_rec(sol,n,result);
                return;
        }
        for(i=0;i<n;i++) {
                if(mark[i] == 0) {
                        mark[i] = 1;
                        sol[pos] = val[i];
                        perm(val, sol, mark, n, pos+1, result);
                        mark[i] = 0;
                }
        }
}

void calculator(int *v, int n, int result) {
        // let's consider an expression as a sequence of number/sign, eg:
        // n1 s1 n2 s2 n3 s3 n4
        // where {n1,n2,n3,n4} are the four numbers in vector v
        // while {s1,s2,s3} are symbols in the {+,-,*,/} set
        // Finding {n1,n2,n3,n4} means to find all permutations
        // while {s1,s2,s3} are permutation with repetitions of the {+,-,*,/} set
        // We split the problem in two parts:
        // 1) find all permutation of n numbers
        // 2) for each permutation P, find all permutations of {+,-,*,/} such
        // that the corresponding expression does get the expected result

        int *sol = (int *)calloc(n,sizeof(int));
        int *mark = (int *)calloc(n,sizeof(int));
        perm(v,sol,mark,n,0, result);
}
