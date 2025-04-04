#include  <stdio.h>
#include <stdlib.h>



int vowels_letters(char* , int );
int is_vowel(char );

int combination_with_repetition(char * , char * ,int  , int , int , int , int );


int main(){
    int n=26,k=5;
    char * array=(char *)malloc(n * sizeof(char));
    char * sol = (char *)malloc(k * sizeof (char));

    if (array == NULL || sol == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }


    char temp='a',s;
    int i;
    for (s=temp,i=0;s<='z';s++,i++)
        array[i]=s;

    printf("the words that two vowels letters appear next to each other  are : \n");
    int total_number= combination_with_repetition(array , sol , n , k , 0 , 0 , 0);
    printf("the total number of the words are %d \n ",total_number);





free(sol);
free(array);

return 0;
}





int combination_with_repetition(char * array, char * sol,int  n, int k , int start , int count  , int pos ){

    int i;


    if (pos >= k) {
        if (!vowels_letters(sol,k))
        return count;

        for (i = 0; i < k; i++)
            printf("%c",sol[i]);
        printf("\n");
        return count +1 ;

    }

    for (i=start ; i <n ; i++ ){
        sol[pos]= array[i];
        count = combination_with_repetition(array , sol , n , k  , i   , count , pos +1 );
    }

    return count;
}



int vowels_letters(char* array , int len){
    int i;

    for (i=0 ; i<len -1 ; i++) {
    if (is_vowel(array[i]) && is_vowel(array[i+1]))
        return 1;
    }


    return 0;
}

int is_vowel(char input){
    if (input=='a' || input=='e' || input=='o' || input=='u' || input=='i')
        return 1;
    else
        return 0;
}