#include <stdio.h>

typedef struct List list;
struct List {
    int val;
    list *next;
};

list * remove_specific_element(list * head , int val){

    list *current;
    list *prev;

    while(head!= NULL && head->val==val)
        head=head->next;

    if (head==NULL)
        return NULL;

    current=head;
    prev=NULL;

    while (current ->next != NULL){
        if(current->val ==val){
            prev->next=current->next;
            current=current->next;
        }
        else{
            prev=current;
            current=current->next;
        }
    }
    if (current->val == val)
        prev->next=NULL;

    return head;
}


