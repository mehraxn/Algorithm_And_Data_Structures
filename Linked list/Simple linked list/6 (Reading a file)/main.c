#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20


typedef struct List list;
struct List {
    char * name;
    list * next;
};


int number_row (char * file_name){
    FILE *fp ;

    if ((fp=fopen(file_name,"r")) ==NULL){
        fprintf(stderr,"error of opening file \n");
        return -1;
    }

    char *line=(char *)malloc(MAX * sizeof(char ));

    if (line==NULL){
        fprintf(stderr,"error of memory allocation \n");
        return -2;
    }

    int counter=0;
    while ( (fgets(line,sizeof (line) ,fp)) != NULL){
        counter++;
    }

    free(line);
    fclose(fp);

    return counter;

}


list * read_file (char * file_name){

    int number= number_row(file_name);

    if (number <= 0){
        return NULL;
    }

    FILE * fp;
    if ((fp=fopen(file_name,"r")) ==NULL){
        fprintf(stderr,"error of opening file \n");
        return NULL;
    }

    list * head=NULL;
    list * temp=NULL;


    for (int i=0 ; i<number ; i++){
        list * second =(list * ) malloc((sizeof (list) ));
        second->name=(char *)malloc(MAX*sizeof(char));
        second->next=NULL;
        if (head==NULL){
            head=second;
            temp=second;
        }
        else {
            temp->next=second;
            temp=temp->next;
        }

    }

    free(temp);
    fclose(fp);

    return head;
}