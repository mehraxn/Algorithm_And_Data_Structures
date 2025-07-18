#include <stdio.h>


void merge(int * v1 , int * v2 , int *v3 ,int n){

    int i1=0 , i2=0 ,i3=0;

    while (i1<n && i2<n){
        if(v1[i1] < v2[i2])
            v3[i3++]=v1[i1++];
        else
            v3[i3++]=v2[i2++];
    }

    while (i2<n)
        v3[i3++]=v2[i2++];

    while(i1<n)
        v3[i3++]=v1[i1++];

    return;

}
