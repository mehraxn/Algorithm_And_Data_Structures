#include <stdio.h>

typedef struct List list;
struct List {
    int val;
    list *next;
};


list *reverse_of_a_linked_list(list *head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }


    list *new_head = reverse_of_a_linked_list(head->next);


    head->next->next = head;
    head->next = NULL;

    return new_head;  
}
