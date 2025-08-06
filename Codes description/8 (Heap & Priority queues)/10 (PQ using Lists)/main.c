#include <stdio.h>
#include <stdlib.h>

// Define the structure for a priority queue item
typedef struct Node {
    int value;               // The value of the item
    struct Node* next;       // Pointer to the next node
} Node;

// Define the priority queue structure
typedef struct {
    Node* front;             // Pointer to the front of the priority queue (highest priority item)
} PriorityQueue;

// Function to initialize the priority queue
void pq_init(PriorityQueue* pq) {
    pq->front = NULL;  // Set the front pointer to NULL, indicating an empty priority queue
}

// Function to check if the priority queue is empty
int pq_is_empty(PriorityQueue* pq) {
    return pq->front == NULL;  // Return 1 if the queue is empty, otherwise 0
}

// Function to insert an item into the priority queue
void pq_insert(PriorityQueue* pq, int item) {
    Node* new_node = (Node*)malloc(sizeof(Node));  // Allocate memory for the new node
    new_node->value = item;  // Set the value of the new node
    new_node->next = NULL;   // Initially, the next pointer is NULL

    if (pq_is_empty(pq) || pq->front->value < item) {
        // If the queue is empty or the new item has a higher priority, insert at the front
        new_node->next = pq->front;  // Point the new node to the current front node
        pq->front = new_node;        // Set the new node as the front of the queue
    } else {
        // Traverse the queue to find the correct position for the new node
        Node* temp = pq->front;
        while (temp->next != NULL && temp->next->value >= item) {
            temp = temp->next;  // Move to the next node if the current node has higher priority
        }

        // Insert the new node after the found node
        new_node->next = temp->next;  // Point the new node to the next node
        temp->next = new_node;        // Point the previous node to the new node
    }
}

// Function to extract the highest priority item (front of the queue)
int pq_extract_max(PriorityQueue* pq) {
    if (pq_is_empty(pq)) {
        printf("Priority Queue is empty!\n");
        return -1;  // Return -1 if the queue is empty
    }

    Node* temp = pq->front;  // Get the front node
    int max_item = temp->value;  // The maximum item is at the front of the queue
    pq->front = pq->front->next;  // Set the front pointer to the next node
    free(temp);  // Free the memory allocated for the front node

    return max_item;  // Return the extracted maximum item
}

// Function to print the priority queue
void pq_print(PriorityQueue* pq) {
    Node* temp = pq->front;
    while (temp != NULL) {
        printf("%d ", temp->value);  // Print the value of each node
        temp = temp->next;  // Move to the next node
    }
    printf("\n");
}

// Main function to test the priority queue
int main() {
    PriorityQueue pq;
    pq_init(&pq);  // Initialize the priority queue

    // Insert items into the priority queue
    pq_insert(&pq, 20);
    pq_insert(&pq, 15);
    pq_insert(&pq, 30);
    pq_insert(&pq, 10);
    pq_insert(&pq, 50);

    printf("Priority Queue after insertions:\n");
    pq_print(&pq);  // Print the priority queue

    // Extract the maximum item from the priority queue
    printf("Extracted max item: %d\n", pq_extract_max(&pq));
    printf("Priority Queue after extraction:\n");
    pq_print(&pq);  // Print the priority queue after extraction

    return 0;
}
