#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string{
    char *string;
};


struct string* read_file(char [], int *);
struct string *sorting_the_struct(struct string*  , int );
void putting_in_the_third_file(struct string*, int , char *);


 int main() {

    char input[]="./input.txt";
    char output[]="./output.txt";

    int number_of_string=0;
    struct string* Project= read_file(input, &number_of_string);
    struct string *final_project= sorting_the_struct(Project,number_of_string);
    putting_in_the_third_file(final_project,number_of_string,output);


    for(int j=0 ; j< number_of_string ; j++){
        printf("%s \n",final_project[j].string);
    }


    for (int i = 0; i < number_of_string; i++) {
        free(final_project[i].string);
    }

    free(final_project);


    return 0;
}


struct string* read_file(char file_name[] , int *number_final){

    FILE *fp;
    fp=fopen(file_name,"r");

    if (!fp) {
        printf("READING OF THE FILE %s FACED A PROBLEM ",file_name);
        return NULL;
    }

    int number;
     if (fscanf(fp,"%d",&number) != 1){
         printf("ERROR READING THE FIRST NUMBER OF THE FILE ");
         fclose(fp);
         return NULL;
     }



    struct string *Word;
    Word=(struct string *)malloc(number *sizeof(struct string));

    if (Word==NULL){
    printf("Memory Allocation Failed .\n");
    fclose(fp);
    return NULL;
    }


   for (int i=0 ; i<number ; i++ ){
       Word[i].string=(char *)malloc(100 * sizeof (char));
       (*number_final)++ ;
       if (Word[i].string == NULL){
           printf("MEMORY ALLOCATION IS WRONG FOR THE %d MEMEBER OF THE ARRAY",i);
        for(int j=0; j < i ; j++){
            free(Word[j].string);
        }
           free(Word);
        fclose(fp);
    return NULL;
       }


      if ( fscanf(fp,"%s",Word[i].string) !=1 ){
          printf("ERROR READING THE FILE \n");
          for(int j=0 ; j < i ; j++){
              free(Word[j].string);
          }
          free(Word);
          fclose(fp);
          return NULL;
      }



   }

    fclose(fp);
    return Word;
}


struct string *sorting_the_struct(struct string* unsorted , int size){

    char *temp=NULL;
    int i;

    for (i=0 ; i<size-1; i++ ){
        for (int j=0 ; j < size -1 -i ;j++){
            if ( (strcmp(unsorted[j].string,unsorted[j+1].string)) > 0  ){
                temp=unsorted[j].string;
                unsorted[j].string=unsorted[j+1].string;
                unsorted[j+1].string=temp;
            }

        }

    }


    return unsorted;

}

void putting_in_the_third_file(struct string* array ,int size ,char *output){
    FILE * fp;

    fp= fopen(output,"w");
    if (fp==NULL){
    printf("EROR OF THE PUTTING THE SECOND FILE ");
        fclose(fp);
        return;
    }

    for(int i=0 ; i < size ; i++){
        fprintf(fp,"%s \n",array[i].string);
    }

    fclose(fp);
    return;
}