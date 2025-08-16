// Function to enqueue a new element into a circular queue
queue_t* enqueue(queue_t *tail, int val) {
    queue_t *new = new_element();  // Step 1: Create a new element
    new->key = val;

    if (tail == NULL) {
        // If the queue is empty, the new node points to itself
        tail = new;
        tail->next = tail;
    } else {
        // Step 2: Point the new node to the current head (tail->next)
        new->next = tail->next;
        // Step 3: Set the tail's next to the new node
        tail->next = new;
        // Step 4: Update the tail to the new node
        tail = new;
    }

    return tail;
}
