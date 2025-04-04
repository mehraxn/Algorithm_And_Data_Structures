typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* sentinel_search(Node* head, int value) {
    // Create a sentinel node and set its key to the target value
    Node sentinel;
    sentinel.key = value;
    sentinel.next = NULL;

    // Set the end of the linked list to point to the sentinel
    Node* p = head;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = &sentinel;

    // Search for the value in the list
    while (value != p->key) {
        p = p->next;
    }

    // Restore the list by removing the sentinel
    tail->next = NULL;

    // Check if the value was found (if p is not the sentinel node)
    if (p != &sentinel) {
        // Value found
        return p;
    } else {
        // Value not found
        return NULL;
    }
}

// Example usage:
// Node* result = sentinel_search(head, target_value);
// if (result != NULL) { /* Value found */ } else { /* Value not found */ }
