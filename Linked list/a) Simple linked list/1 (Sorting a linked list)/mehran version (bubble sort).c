#include <stdio.h>

typedef struct ListNode list;
struct ListNode {
    int val;
    struct ListNode *next;
};

list* sorting_a_linked_list(list* head) {
    if (head == NULL)
        return NULL;

    int flag = 1;
    while (flag) {
        flag = 0;
        list* temp = head;
        while (temp->next != NULL) {
            if (temp->val > temp->next->val) {
                int temp_number = temp->val;
                temp->val = temp->next->val;
                temp->next->val = temp_number;
                flag = 1;
            }
            temp = temp->next;
        }
    }
    return head;
}