#include <stdio.h>


int arr_rep (int * , int * , int , int , int , int );


int main() {

    int n=5;
    int k=3;
    int array[5]={1,2,3,4,5};   // Main array size should be equal to n
    int sol[3];                                     // Sol array size should be equal to n

    printf("Subsets with %d number are : \n",k);
    int count =arr_rep(array,sol,n,k,0,0);
    printf("number of total subset with %d members is %d \n",k,count);



    return 0;
}


int arr_rep(int * val, int * sol  , int n ,int k , int count , int pos){

    //Recursion base
    if (k<=pos){                                   //Pay attention that pos>= k not k>= pos
        for(int i=0 ; i< k ; i++)
            printf("%d",sol[i]);
        printf("\n");
        return count +1;
    }

    for(int i=0 ; i< n ; i++){

            sol[pos]=val[i];
            count = arr_rep(val,sol,n,k,count ,pos+1);
    }

    return count ;
}

