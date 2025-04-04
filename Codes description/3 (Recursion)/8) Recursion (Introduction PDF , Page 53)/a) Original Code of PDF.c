// Function to traverse the linked list in reverse order and print elements
void traverse_reverse(list_t *p) {
    if (p == NULL)
        return;
    traverse_reverse(p->next);
    printf("%d ", p->key);
}

// Function to delete a node with a specific value from the linked list
list_t* delete(list_t *p, int val) {
    if (p == NULL)
        return NULL;
    if (p->key == val) {
        list_t *t = p->next;
        free(p);
        return t;
    }
    p->next = delete(p->next, val);
    return p;
}