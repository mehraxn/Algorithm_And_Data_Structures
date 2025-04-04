#include <stdio.h>


int perm (char *, char * ,int *,int ,int ,int);


int main() {

    char val[5]={'A','B','C','D','E'};
    int mark[5]={0,0,0,0,0};
    char sol[5];

    int count= perm(val,sol,mark,5,0,0);
    printf("the number of counter is %d",count);

    return 0;
}

int perm(char * val, char * sol,int * mark, int n ,int count ,int pos){


    if (n <= pos && sol[0] == 'A'){
        for(int i=0 ; i<n ;i++)
            printf("%c ",sol[i]);
        printf("\n");
        return count +1;
    }
    else if (pos >= n){
        return count;
    }


    for (int i=0 ; i<n ; i++){
        if (mark[i]==0){
            mark[i]=1;
            sol[pos]=val[i];
            count=perm(val,sol,mark,n,count,pos+1);
            mark[i]=0;
        }

    }



    return count;
}