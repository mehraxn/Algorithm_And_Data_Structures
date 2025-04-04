// Function to dequeue an element from a circular queue
queue_t* dequeue(queue_t *tail, int *val, int *status) {
    if (tail == NULL) {
        // If the queue is empty, set status to FAILURE
        *status = FAILURE;
        return NULL;
    }

    queue_t *old = tail->next;  // Step 1: Get the head node (tail->next)
    *val = old->key;            // Step 2: Retrieve the value from the head node

    if (old == tail) {
        // If the queue has only one element
        tail = NULL;
    } else {
        // Step 3: Update the tail's next to skip the old head
        tail->next = old->next;
    }

    free(old);  // Step 4: Free the old head node
    *status = SUCCESS;  // Set status to SUCCESS

    return tail;  // Return the updated tail pointer
}
