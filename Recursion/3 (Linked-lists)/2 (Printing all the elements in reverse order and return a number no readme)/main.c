#include <string.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode * next;
};

int print_r(struct ListNode * head) {
    if (head == NULL)
        return 0;

    int reversed_number= print_r(head->next);
    printf("%d ", head->val);
   return reversed_number*10 + head -> val;
}
