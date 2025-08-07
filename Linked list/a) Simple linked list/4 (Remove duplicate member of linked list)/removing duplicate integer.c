struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *temp = head;
    int temp_number;
    if (temp == NULL)
        return NULL;

    else if (temp->next == NULL)
        return head;

    while (temp) {
        struct ListNode *temp_temp = temp;
        temp_number = temp->val;

        while (temp_temp->next != NULL) {

            if (temp_temp->next->val == temp_number) {

                struct ListNode *p = temp_temp->next;
                temp_temp->next = temp_temp->next->next;
                free(p);
                
            } else {
                temp_temp = temp_temp->next;
            }
        }
        temp = temp->next;
    }

    return head;
}
