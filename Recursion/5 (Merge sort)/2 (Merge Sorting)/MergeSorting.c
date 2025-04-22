#include <stdio.h>
#include <stdlib.h>


int min(int ,int);
void bottom_up_merge_sort(int * , int );
void merge(int * , int * , int , int , int );



void bottom_up_merge_sort(int * A, int size ){
    int * B=(int*)malloc(size * sizeof(int ));
    for (int m=1;m<size;m=m+m)
        for (int i=0;i<size-m;i+=m+m)
            merge(A,B,i,i+m-1,min(size-1,i+m+m-1));


    free(B);

}
void merge(int * A, int * B, int l, int c , int r ){

    int i,j,k;

    for (i=l ,j=c+1, k=l ;i<=c && j<=r;)
        if(A[i]<=A[j])  //THIS = is very important in the <= because this make the sort stable
            B[k++]=A[i++];
        else
            B[k++]=A[j++];

    while (i<=c)
        B[k++]=A[i++];

    while (j<=r)
        B[k++]=A[j++];

    for (k=l;k<=r;k++)
        A[k]=B[k];


}







int min(int A,int B){
    if(A<B)
        return A;
    else
        return B;
}