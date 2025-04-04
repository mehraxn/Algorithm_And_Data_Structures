#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** reading_array(char *, int *);
char ** sorting_array(char**, int );
void write_in_a_file(char * ,char**,int);


int main() {
    char * input_file_name="../input.txt";
    char * output_file_name="../output.txt";
    int  number;
    char ** array=reading_array(input_file_name,&number);

    if (array== NULL){
        printf("EROR OF ASIGNING ARRAY . \n" );
        return 1;
    }

    array= sorting_array(array,number);

    for (int i=0; i <  number ; i++)
        printf("THE %d WORD IS %s \n",i,array[i]);

    write_in_a_file(output_file_name,array,number);

    for (int i=0 ; i < number ;i++)
        free(array[i]);
    free(array);

    return 0;
}



char ** reading_array(char * file_name, int * number){
    FILE *fp;

    if ((fp=fopen(file_name,"r")) == NULL ){
        printf("ERROR READING FILE %s\n",file_name);
        return NULL;
    }

    if ((fscanf(fp,"%d",number))!=1){
        printf("ERORR READING FIRST NUMBER OF THE FILE");
        fclose(fp);
        return NULL;
    }

    char ** array=malloc((*number) * sizeof(char *));

    if (array==NULL){
        printf("Mmory allocation failed . \n");
        free(array);
        fclose(fp);
        return NULL;
    }


    for (int i=0 ; i < *number ; i++){

        array[i]= malloc(100 *sizeof(char));

        if (array[i]==NULL){
            for(int j=0 ; j <i;j++)
                free(array[j]);
            free(array);
            fclose(fp);
            return NULL;

        }



        if (fscanf(fp,"%s",array[i])!=1){
            for(int j=0 ; j <i;j++)
                free(array[j]);
            free(array);
            fclose(fp);
            return NULL;
        }
    }



    fclose(fp);
    return array;


}


char ** sorting_array(char ** array, int number){

    char *temp;

    for (int i=0; i < number-1 ; i++){
        for (int j=0 ; j< number - i - 1 ; j++){
            if (strcmp(array[j+1],array[j]) < 0 ){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }

        }

    }


    return array;

}

void write_in_a_file(char *file_name, char **array, int number) {
    FILE *fp;

    if ((fp = fopen(file_name, "w")) == NULL) {
        printf("ERROR OPENING THE FILE\n");
        return;
    }

    for (int i = 0; i < number; i++) {
        fprintf(fp, "%s\n", array[i]);  // Adding newline after each string
    }

    fclose(fp);
}