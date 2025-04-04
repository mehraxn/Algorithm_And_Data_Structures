#include <stdio.h>
#include <stdlib.h>


typedef struct val_s final_number;
struct val_s {
    int number;
    int *choices ;
};

int multiplication_principle(final_number * lists , int * sol , int pos , int count , int n){

    int  i;

    if ( pos >= n){
        for (i = 0 ; i < n ; i ++)
            fprintf(stdout,"%d",sol[i]);
        printf("\n");
        return count +1 ;
    }

    for (i=0 ; i < lists[pos].number ; i++){
        sol[pos] = lists[pos].choices[i];
        count= multiplication_principle(lists,sol,pos+1,count,n);
    }

    return count ;

}

int main() {
    final_number group[4];
    group[0].number=2;
    group[0].choices=(int *)malloc(sizeof(int ) * group[0].number);
    group[0].choices[0]=6;
    group[0].choices[1]=1;


    group[1].number=2;
    group[1].choices=(int *)malloc(sizeof(int ) * group[1].number);
    group[1].choices[0]=4;
    group[1].choices[1]=8;

    group[2].number=2;
    group[2].choices=(int *)malloc(sizeof(int ) * group[2].number);
    group[2].choices[0]=7;
    group[2].choices[1]=3;


    group[3].number=2;
    group[3].choices=(int *)malloc(sizeof(int ) * group[3].number);
    group[3].choices[0]=9;
    group[3].choices[1]=0;

    int sol[4];

    int total_count= multiplication_principle(group,sol,0,0,4);
    fprintf(stdout,"The total number of the combination is %d \n",total_count);

    for (int i =0 ; i <4 ; i++)
        free(group[i].choices);


    return 0;
}
