#include <stdio.h>

typedef struct List list;
struct List {
    int val;
    list *next;
};

list *reverse_of_a_linked_list(list *head) {
    list *prev = NULL;    // Previous node (starts as NULL)
    list *current = head; // Current node (starts at head)
    list *next = NULL;    // Temporary pointer to store the next node

    while (current != NULL) {
        next = current->next;   // Store next node
        current->next = prev;   // Reverse the current node's pointer
        prev = current;         // Move `prev` to current
        current = next;         // Move `current` to next
    }

    return prev; // `prev` will be the new head of the reversed list
}
