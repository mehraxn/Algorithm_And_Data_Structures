#include <stdio.h>

typedef struct List list ;
struct List{
    int val;
    list *next;
};

int number_of_linked_list(list *head){
    if (head==NULL)
        return 0;

    list *temp=head;

    int number=0;
    while(temp!= NULL){
        temp=temp->next;
        number++;
    }
    return number;
}

list * reverse_of_a_linked_list(list *head){

    if (head==NULL)
        return NULL;

    int number_linked_list= number_of_linked_list(head);

    list * temp = head;

    list *array_of_pointer[number_linked_list];

    for (int i=0 ; i<number_linked_list;i++){
        array_of_pointer[i]=temp;
        temp=temp->next;
    }

    for (int i=number_linked_list-1;i>=0;i--){
        array_of_pointer[i]->next=array_of_pointer[i-1];
    }
    array_of_pointer[0]->next=NULL;

    return array_of_pointer[number_linked_list - 1];
}
