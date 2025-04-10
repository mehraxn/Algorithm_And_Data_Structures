#include <stdio.h>


int simple_arrangement(int * , int * , int * , int , int , int , int );
int arangement_rep (int *, int * ,int , int , int ,int );


int main() {

    int x[6] = {2,4,6,8,9,3};
    int n=6,k=4;
    int sol[4]={0};
    int mark[6]={0};

    printf("the arrangement of 4 choice of the numbers without repetitions are :\n");
    int count =simple_arrangement(x,sol,mark,n,k,0,0);
    printf("the total numbers are : %d \n",count);


    printf("the arrangement of 4 choice of the numbers with repetitions are :\n");
    count =arangement_rep(x,sol,n,k,0,0);
    printf("the total numbers are : %d \n",count);



    return 0;
}

int simple_arrangement(int * val, int * sol, int * mark, int n, int k , int count , int pos){

    if (pos>=k){
        for (int i=0; i<k;i++)
            printf("%d",sol[i]);
        printf("\n");
        return count +1;
    }

    for (int i=0;i < n; i++ ){
        if (mark[i]==0){
            mark[i]=1;
            sol[pos]=val[i];
            count= simple_arrangement(val,sol,mark,n,k,count , pos+1);
            mark[i]=0;
        }
    }


    return count ;
}


int arangement_rep (int * val , int * sol,int n , int k, int count,int pos ){

    if (pos>=k){
        for (int i=0 ; i<k ; i++){
            printf("%d",sol[i]);
        }
        printf("\n");
        return  count +1;
    }

    for (int i=0;i<n;i++){
        sol[pos]=val[i];
        count= arangement_rep(val,sol,n,k,count,pos+1);
    }

    return count;
}
