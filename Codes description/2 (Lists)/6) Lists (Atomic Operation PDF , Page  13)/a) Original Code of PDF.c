#include <stdlib.h>

list_t *extract_tail(list_t *q) {
    list_t *p = q->next;  // Step 1: Set p to point to the node after q
    if (p != NULL) {
        q->next = p->next;  // Step 2: Update q->next to skip p and point to p's next node
    }

    // Free the extracted node to prevent memory leaks
    if (p != NULL) {
        free(p);
    }

    return NULL;  // Return NULL after freeing the extracted tail node
}
