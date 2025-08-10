#include <stdlib.h>
#include <stdio.h>
void merge (int * array , int * B , int l , int c , int r){
    int i , j , k;
    for (i=l , k =l , j=c+1 ;i<=c && j<=r;){
        if (array[i]<=array[j])
            B[k++]=array[i++];
        else
            B[k++]=array[j++];
    }
    while(i<=c) B[k++]=array[i++];
    while(j<=r) B[k++]=array[j++];
    for(i=l;i<=r;i++) array[i]=B[i];
}
void mergeSort_r (int * array ,int * B , int l , int r){
    if(l<r){
        int c= (l + r)/2;
        mergeSort_r (array , B ,l ,c);
        mergeSort_r (array , B ,c+1 ,r);
        merge(array , B , l , c,r);
    }
}
void mergeSort(int * array , int size) {
    int * B= (int *)malloc(size * sizeof(int));
    mergeSort_r(array , B , 0 , size-1 );
    free(B);
}