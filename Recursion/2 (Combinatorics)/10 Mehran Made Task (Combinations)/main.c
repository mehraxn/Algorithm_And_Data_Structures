#include <stdio.h>
#include <stdlib.h>


int simple_arrangement_without_repetitions(int * , int * , int * , int , int , int ,int );

int main(){

    int n=6;
    int *array, * sol , * mark ;
    array=(int *)malloc(n*sizeof(int));
    sol=(int *)calloc(n ,sizeof(int));
    mark=(int *)calloc(n ,sizeof(int));
    int j;
    for (j=0;j<n ; j++)
        array[j]=j+3;


    int total_number=0;
    for (j = 1; j <= n; j++) {
        printf("Arrangements of size %d:\n", j);
        total_number += simple_arrangement_without_repetitions(array, sol, mark, n, j, 0, 0);
    }

    printf("the total number of different numbers we can make is %d \n",total_number);


    free(array);
    free(sol);
    free(mark);

    return 0;
}

int simple_arrangement_without_repetitions(int * array, int * sol, int * mark, int n , int k, int count ,int pos){

    int i;


    if (pos >= k){
        for (i=0; i <k ; i++)
            printf("%d ",sol[i]);
        printf("\n");
        return count +1 ;
    }



    for (i=0 ; i<n ; i++){
        if (mark[i]==0){
            mark[i]=1;
            sol[pos]=array[i];
            count = simple_arrangement_without_repetitions(array,sol,mark,n,k,count ,pos+1);
            mark[i]=0;
        }
    }

    return count;

}
