#include <stdio.h>

int perm_rep (int * , int * ,int *,int ,int , int ,int );


int main() {
    int n=5;
    int n_dist=3;

    int array[3]={9,3,6,};
    int mark[3]={1,2,2};
    int sol[5];

    int count = perm_rep(array,sol,mark,n,n_dist,0,0);
    printf("number of the counter is %d \n",count);

    return 0;
}


int perm_rep (int * val  , int * sol ,int * mark ,int n,int n_dist , int count ,int pos ){

    int i;

    if (pos>=n){
        for (i=0 ; i<n ; i++)
            printf("%d",sol[i]);
        printf("\n");
        return count +1;
    }

    for (i=0 ; i<n_dist ; i++){             //Pay attention that you need both n_distinct and n
        if (mark[i]>0){
            mark[i]--;
            sol[pos]=val[i];
            count = perm_rep(val,sol,mark,n,n_dist,count ,pos+1);
            mark[i]++;
        }
    }

    return count ;
}
