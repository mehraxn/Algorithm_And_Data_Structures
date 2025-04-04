
// Function to sort a linked list
list_t* list_sort(list_t *head1) {
    list_t *tmp, *head2 = NULL;
    while (head1 != NULL) {
        pop(&head1, &tmp);
        head2 = insert(head2, tmp);
    }
    return head2;
}

