#include <stdio.h>
#include <stdlib.h>


typedef struct array_t array;
struct array_t{
    int number ;
    int *numbers;
};


int multiplication_principle(array * , int * , int  , int , int );

int main() {

    array arrays[3];

    arrays[0].number=2;
    arrays[0].numbers=(int *)malloc(2 * sizeof (int));
    arrays[0].numbers[0]=6;
    arrays[0].numbers[1]=9;

    arrays[1].number=3;
    arrays[1].numbers=(int *)malloc(3 * sizeof (int));
    arrays[1].numbers[0]=0;
    arrays[1].numbers[1]=1;
    arrays[1].numbers[2]=8;


    arrays[2].number=3;
    arrays[2].numbers=(int *)malloc(3 * sizeof (int));
    arrays[2].numbers[0]=3;
    arrays[2].numbers[1]=2;
    arrays[2].numbers[2]=4;

    int *sol=(int *) calloc(3 , sizeof(int ));

    printf("the numbers that we can make with these numbers are : \n");
    int total_number_permutation= multiplication_principle(arrays,sol , 0 ,0 , 3);
    printf("total number of permutation is %d \n",total_number_permutation);

    for (int i=0 ; i < 3 ; i++)
        free(arrays[i].numbers);
    free(sol);
    return 0;
}


int multiplication_principle(array * input, int * sol, int count , int pos , int n){

    int i ;

    if (pos >= n){
        int temp=0;
        for (i=0 ; i<n ; i++){
            temp+=sol[i];
        }
        if (temp % 3 ==0){
            for (i=0 ; i<n ; i++){
                printf("%d" ,sol[i]);
            }
            printf("\n");
            return count +1;
        }
        return count ;
    }

    for (i=0 ; i <input[pos].number;i++){
        sol[pos]=input[pos].numbers[i];
        count= multiplication_principle(input,sol,count,pos+1,n);
    }

    return count ;
}
