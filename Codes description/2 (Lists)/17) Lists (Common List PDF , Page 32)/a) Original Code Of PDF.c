// Function to insert a new element into a sorted linked list
list_t* insert(list_t *head, int val) {
    list_t *p, *q = head;
    p = new_element();  // Create a new element
    p->key = val;
    p->next = NULL;

    // If the list is empty or the new value is smaller than the head's value
    if (head == NULL || val < head->key) {
        p->next = head;  // Insert at the beginning
        return p;        // New element becomes the new head
    }

    // Traverse the list to find the correct position for the new value
    while (q->next != NULL && val > q->next->key) {
        q = q->next;
    }

    // Insert the new element in its correct position
    p->next = q->next;
    q->next = p;

    return head;  // Return the updated head of the list
}
