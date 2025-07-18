#include <stdio.h>
#include <string.h>


//Pay attention that size is the size of the first and second array
//For this code the size of the both array should be equal
void merge_characters(char ** first , char ** second ,char **third ,int size){

    int i1=0 , i2=0 , i3=0 ;

    while (i1< size && i2 < size){      // (i1 <= n && i2 <=n ) is a wrong approach
        if (strcmp(first[i1],second[i2]) <0)
            third[i3++]=first[i1++];
        else
            third[i3++]=second[i2++];
    }

    while (i1<size)
        third[i3++]=first[i1++];

    while ( i2 < size)
        third[i3++]=second[i2++];


}