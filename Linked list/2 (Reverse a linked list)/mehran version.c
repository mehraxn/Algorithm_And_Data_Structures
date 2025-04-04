#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode list;
struct ListNode {
    int val;
    struct ListNode *next;
};

int * array_linked_list(list * head,int *num){
    list *temp=head;

    int count =0;

    if (temp==NULL)
        return NULL;

    while (temp!=NULL){
        count++;
        temp=temp->next;
    }
    (*num)=count;

    temp=head;
    int i=0;
    int *array=(int *)malloc(count * sizeof(int));

    while (temp!=NULL){
       array[i]=temp->val;
       temp=temp->next;
       i++;
    }


    return array;
}

list * reverse_linked_list(list * head ){

    int size;
    int *array= array_linked_list(head,&size);


    list *temp=head;
    int i=size-1;
    while (temp!=NULL){
        temp->val=array[i];
        i--;
        temp=temp->next;
    }

    free(array);

    return head;
}


