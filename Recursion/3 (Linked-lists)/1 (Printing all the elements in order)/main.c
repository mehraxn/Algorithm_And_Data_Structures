#include <string.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode * next;
};

void print_r(struct ListNode * head) {
    if (head == NULL)
        return;
    printf("%d ", head->val);
    print_r(head->next);
}
