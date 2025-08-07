#include <stdio.h>

typedef struct List list;
struct List {
    int val;
    list *next;
};

list * remove_element(list * head, int specific_val){

    if (head==NULL)
        return NULL;

    head->next=remove_element(head->next,specific_val);

    if(head->val == specific_val)
        return head->next;

    return head;


}
