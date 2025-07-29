#include <stdlib.h>

typedef struct ListNode list;
struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

static struct ListNode* merge(struct ListNode* a, struct ListNode* b) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    // 1) split
    struct ListNode* mid   = findMiddle(head);
    struct ListNode* right = mid->next;
    mid->next = NULL;
    // 2) sort each half
    struct ListNode* left_sorted  = sortList(head);
    struct ListNode* right_sorted = sortList(right);
    // 3) merge
    return merge(left_sorted, right_sorted);
}
