#include <stdio.h>
#include <stdlib.h>

int combination_repetition(int * , int * , int , int  , int , int , int );

int main() {

    int n=5,k=3;
    int *array=(int *)malloc(n*sizeof(int));

    for (int j=0 ; j<6 ; j++)
        array[j]=j+1;

    int * sol=(int *)calloc(k , sizeof(int ));
    int total_number= combination_repetition(array,sol,n,k,0,0,0);
    printf("the total number of the combination is  %d ",total_number);

    free(array);
    free(sol);


    return 0;
}

int combination_repetition(int * array, int * sol, int n, int k , int start, int count, int pos){

    int i;

    if (pos >= k){
        for (i=0 ; i< k ;i++)
            printf("%d",sol[i]);
        printf("\n");
        return count +1;
    }


    for (i=start ; i<n ;i++){
        sol[pos]=array[i];
        count =combination_repetition(array,sol,n,k,i,count,pos+1);
    }

    return count;
}
