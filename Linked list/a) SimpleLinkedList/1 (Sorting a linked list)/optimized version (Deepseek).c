#include <stdio.h>

typedef struct ListNode list;
struct ListNode {
    int val;
    struct ListNode *next;
};

list* merge(list* left, list* right) {
    list dummy; // Temporary dummy node
    list* tail = &dummy;
    dummy.next = NULL;

    while (left && right) {
        if (left->val <= right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = (left != NULL) ? left : right;
    return dummy.next;
}

void split(list* head, list** left, list** right) {
    list* slow = head;
    list* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

list* sorting_a_linked_list(list* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    list* left;
    list* right;

    split(head, &left, &right);

    left = sorting_a_linked_list(left);
    right = sorting_a_linked_list(right);

    return merge(left, right);
}