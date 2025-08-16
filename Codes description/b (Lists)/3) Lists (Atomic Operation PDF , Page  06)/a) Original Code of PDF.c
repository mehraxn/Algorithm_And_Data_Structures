list_t *find_node(list_t *head, int value) {
    list_t *p = head;

    while (p != NULL) {
        if (value == p->key) {
            return p;  // If the value matches, return the pointer to the node
        } else {
            p = p->next;  // Move to the next node
        }
    }

    return NULL;  // If the value is not found, return NULL
}
