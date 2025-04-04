list_t *find_node(list_t *head, int value) {
    list_t *p;
    p = head;

    // Traverse the list until the value is found or the end is reached
    while ((p != NULL) && (p->key != value)) {
        p = p->next;
    }

    // Return the pointer to the node if found, otherwise return NULL
    return p;
}