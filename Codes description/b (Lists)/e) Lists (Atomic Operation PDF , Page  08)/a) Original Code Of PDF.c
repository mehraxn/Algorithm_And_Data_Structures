list_t *extract_head(list_t **head) {
    list_t *p = *head;  // Step 1: Set p to point to the head of the list
    if (*head != NULL) {
        *head = (*head)->next;  // Step 2: Update head to point to the next node
        free(p);  // Free the extracted head node
        return NULL;  // Return NULL after freeing the node
    }
    return NULL;  // Return NULL if the list was empty
}
