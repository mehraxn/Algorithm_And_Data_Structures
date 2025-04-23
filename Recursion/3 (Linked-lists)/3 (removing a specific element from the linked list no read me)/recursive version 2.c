#include <stdio.h>
#include <stdlib.h>

typedef struct list_t list_t;
struct list_t{
    int val;
    struct list_t * next ;
};

list_t *delete_recursive(list_t * head , int key){
    if (head==NULL)
        return head;

    if (head->val == key){
        list_t *temp=head->next;
        return temp;
    }

    head->next= delete_recursive(head->next,key);
    return head;
}