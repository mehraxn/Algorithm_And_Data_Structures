void traverse_list(list_t *head) {
    list_t *p = head;

    // Iterate through the list until reaching the end (NULL)
    while (p != NULL) {
        // Visit the current node - for example, print its key value
        printf("Node key: %d\n", p->key);

        // Move to the next node
        p = p->next;
    }
}