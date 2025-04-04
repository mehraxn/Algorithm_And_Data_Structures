int count(list_t *p) {
    if (p == NULL)
        return 0;
    return (1 + count(p->next));
}

// Function to traverse and print the elements of the linked list
// This function prints the value of each node starting from the given node `p`.
void traverse(list_t *p) {
    if (p == NULL)
        return;
    printf("%d ", p->key);
    traverse(p->next);
}