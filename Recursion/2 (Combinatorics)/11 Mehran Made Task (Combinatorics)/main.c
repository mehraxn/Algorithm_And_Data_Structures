#include <stdio.h>
#include <stdlib.h>

typedef struct character lists;
struct character{
    char * array_inner;
    int number_choice;
};

int multiplication_principle(lists * ,char * , int  , int , int );

int vowel_check(char * , int );

int main(){

    lists array[3];

    array[0].number_choice=3;
    array[0].array_inner=(char *)malloc(array[0].number_choice * sizeof(char));
    array[0].array_inner[0]='A';
    array[0].array_inner[1]='B';
    array[0].array_inner[2]='C';


    array[1].number_choice=3;
    array[1].array_inner=(char *)malloc(array[1].number_choice * sizeof(char));
    array[1].array_inner[0]='O';
    array[1].array_inner[1]='D';
    array[1].array_inner[2]='E';



    array[2].number_choice=3;
    array[2].array_inner=(char *)malloc(array[2].number_choice * sizeof(char));
    array[2].array_inner[0]='X';
    array[2].array_inner[1]='I';
    array[2].array_inner[2]='Y';

    char * solution=(char *)malloc (sizeof(char ) * 3);

    int total_combinations = multiplication_principle(array, solution, 3, 0, 0);
    printf("Total combinations: %d\n", total_combinations);

    for (int i =0; i<3 ; i++)
        free(array[i].array_inner);

    free(solution);


}


int multiplication_principle(lists * array ,char * solution , int number , int count , int pos ){

    int i;

    if (pos >= number ){
        if (vowel_check(solution,number)){
            for (i=0; i<number ; i++)
                printf("%c",solution[i]);
            printf("\n");
            return count +1 ;
        }
        return count;
    }

    for (i=0 ; i <array[pos].number_choice ; i++ ){
        solution[pos]=array[pos].array_inner[i];
        count = multiplication_principle(array,solution,number,count,pos + 1);
    }

    return count;
}

int vowel_check(char * word  ,int length){

    for (int i=0 ; i <length-1 ; i++)
        if ((word[i]=='A' || word[i]=='E' || word[i]=='O'  || word[i]=='U' || word[i]=='I') &&
        (word[i+1]=='A' || word[i+1]=='E' || word[i+1]=='O'  || word[i+1]=='U' || word[i+1]=='I'))
        return 0;

    return 1;
}