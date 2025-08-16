// Function to extract (remove) an element from a sorted linked list
list_t* extract(list_t *head, int val) {
    list_t *p, *q = head;

    // If the list is empty, print an error message and return NULL
    if (head == NULL) {
        fprintf(stderr, "Error: empty list\n");
        return NULL;
    }

    // If the value to be removed is the head node
    if (val == head->key) {
        p = head->next;
        free(head);  // Free the head node
        return p;    // Return the new head of the list
    }

    // Traverse the list to find the node to be removed
    while (q->next != NULL && val > q->next->key) {
        q = q->next;
    }

    // Add further logic to handle the removal if the element is found
    if (q->next != NULL && val == q->next->key) {
        p = q->next;
        q->next = q->next->next;
        free(p);  // Free the node to be removed
    } else {
        fprintf(stderr, "Error: value not found in the list\n");
    }

    return head;  // Return the updated head of the list
}
