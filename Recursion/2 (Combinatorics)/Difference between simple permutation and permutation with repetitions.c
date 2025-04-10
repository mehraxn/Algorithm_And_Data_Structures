#include <stdio.h>


int simple_permutation(int * , int * , int * , int , int , int );
int permutation_rep (int *, int *,int * ,int , int , int ,int );


int main() {

    int x[6] = {2,4,6,8,9,3};
    int n=6;
    int sol[4]={0};
    int mark[6]={0};

    int y[6]={3,3,3,2,4,6};
    int y_dist[4]={3,2,4,6};
    int mark_2[4]={3,1,1,1};
    int sol_y[6]={0};

    printf("the arrangement of 4 choice of the numbers without repetitions are :\n");
    int count =simple_permutation(x,sol,mark,n,0,0);
    printf("the total numbers are : %d \n",count);


    printf("the arrangement of 4 choice of the numbers with repetitions are :\n");
    count =permutation_rep(y,mark_2,sol,n,4,0,0);
    printf("the total numbers are : %d \n",count);



    return 0;
}

int simple_permutation(int * val, int * sol, int * mark, int n, int count , int pos){

    if (pos>=n){
        for (int i=0; i<n;i++)
            printf("%d",sol[i]);
        printf("\n");
        return count +1;
    }

    for (int i=0;i < n; i++ ){
        if (mark[i]==0){
            mark[i]=1;
            sol[pos]=val[i];
            count= simple_permutation(val,sol,mark,n,count , pos+1);
            mark[i]=0;
        }
    }


    return count ;
}


int permutation_rep (int * val , int * mark,int * sol,int n , int n_dist, int count,int pos ){

    if (pos>=n){
        for (int i=0 ; i<n ; i++){
            printf("%d",sol[i]);
        }
        printf("\n");
        return  count +1;
    }

    for (int i=0;i<n_dist;i++) {
        if (mark[i] > 0) {
            mark[i]--;
            sol[pos] = val[i];
            count = permutation_rep(val, mark, sol, n, n_dist, count, pos + 1);
            mark[i]++;
        }

    }

    return count;
}
