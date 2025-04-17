#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct words list;
struct words{
    int len;
    char * word;
};


list * read_and_store_file(char * );
int multiplication_principle(list * , char * ,int , int  ,int );

int main() {
    char * file_name="../file.txt";
    list * list_of_word= read_and_store_file(file_name);
    char * sol=(char *)malloc(256*sizeof(char));
    int final_number = multiplication_principle(list_of_word,sol,0,0,5);
    printf("%d \n",final_number);

    free(list_of_word);
    for (int i = 0; i < sizeof(list_of_word) / sizeof(list_of_word[0]); i++) {
        free(list_of_word[i].word);
    }
    free(sol);


    return 0;
}


list * read_and_store_file(char * file_name ){
    FILE * fp;
    if ((fp= fopen(file_name,"r"))==NULL){
        printf("READING THE FILE FAILED \n");
        return NULL;
    }
    int number ;
    if (fscanf(fp,"%d",&number)!= 1 ){
        printf("READING THE FIRST NUMBER OF THE FILE FAILED \n");
        fclose(fp);
        return NULL;
    }
    list * list_of_word=(list *)malloc(number * sizeof(struct words));

    if (! list_of_word){
        printf("MEMORY ALLOCATION FAILED \n");
        fclose(fp);
        return NULL;
    }


    char temp[256];
    for (int i =0 ; i < number ;i++){
        if (fscanf(fp, "%s", temp) != 1) {
            printf("READING WORD FAILED \n");
            fclose(fp);
            for (int j = 0; j < i; j++)
                free(list_of_word[j].word);
            free(list_of_word);
            fclose(fp);
            return NULL;
        }

        int length=strlen(temp);
        list_of_word[i].word=(char *)malloc((length+1) * sizeof (char ));

        if (! list_of_word[i].word){
            printf("MEMORY ALLOCATION FAILED \n");
            fclose(fp);
            for (int j=0 ; j< i ; j++)
                free(list_of_word[j].word);
            fclose(fp);
            return  NULL;
        }


        strcpy(list_of_word[i].word,temp);
        list_of_word[i].len=length;
    }
    fclose(fp);
    return list_of_word;

}

int multiplication_principle(list * list_of_word, char * sol ,int count , int pos , int n){
    int i ;

    if (pos >= n){
        for (i=0 ; i < n ; i++)
            printf("%c",sol[i]);
        printf("\n");
        return count +1;
    }


    for (i=0 ; i < list_of_word[pos].len ; i++ ){
    sol[pos]=list_of_word[pos].word[i];
    count = multiplication_principle(list_of_word,sol,count , pos +1 , n);

    }
    return count +1 ;


}