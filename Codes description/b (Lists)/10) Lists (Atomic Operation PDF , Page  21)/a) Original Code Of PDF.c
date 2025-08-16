// Function to dispose of the entire linked list
void dispose_list(list_t *head) {
    list_t *p;
    while (head != NULL) {  // Traverse the list
        p = head;           // Set p to point to the current head
        head = head->next;  // Move head to the next node
        free(p);            // Free the current node to prevent memory leaks
    }
}
