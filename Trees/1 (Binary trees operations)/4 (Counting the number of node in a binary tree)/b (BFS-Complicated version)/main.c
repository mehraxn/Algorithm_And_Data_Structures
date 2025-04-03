#include <stdio.h>   // Provides declarations for I/O functions like printf, scanf, etc.
#include <stdlib.h>  // Provides declarations for memory allocation functions like malloc, free, etc.

// Example struct definition
typedef struct node_t {
    int key;                // 'key' stores the integer data for this node
    struct node_t* left;    // Pointer to the left child node
    struct node_t* right;   // Pointer to the right child node
} node;

// A simple queue node for BFS
typedef struct queue_node {
    node* treeNode;             // This holds a pointer to a 'node' from the binary tree
    struct queue_node* next;    // Pointer to the next element in the queue
} queue_node;

// Enqueue function
void enqueue(queue_node** front, queue_node** rear, node* treeNode) {
    queue_node* newNode = (queue_node*)malloc(sizeof(queue_node)); // Dynamically allocate memory for a new queue_node
    newNode->treeNode = treeNode;                                  // Set the tree node pointer in the new queue node
    newNode->next = NULL;                                          // The new node will be inserted at the end, so next is NULL

    if (*rear) {                   // If the queue is not empty (rear is not NULL)
        (*rear)->next = newNode;   // Link the current 'rear' node to the new node
    } else {
        *front = newNode;          // If the queue is empty, 'front' will also point to the new node
    }
    *rear = newNode;               // Update 'rear' to point to the newly added node
}

// Dequeue function
node* dequeue(queue_node** front, queue_node** rear) {
    if (!*front) {    // If the queue is empty (front is NULL), return NULL
        return NULL;
    }

    queue_node* temp = *front;    // Temporarily store the current front
    node* treeNode = temp->treeNode;  // Extract the tree node from the queue node
    *front = (*front)->next;      // Move the front pointer to the next element in the queue

    if (!*front) {    // If the queue became empty after dequeuing
        *rear = NULL; // Set 'rear' to NULL as well
    }

    free(temp);       // Free the memory of the dequeued queue node
    return treeNode;  // Return the tree node that was stored in the dequeued element
}

// Iterative BFS approach to count the number of nodes
int count_nodes_bfs(node* root) {
    if (root == NULL) {   // If the tree is empty, return 0
        return 0;
    }

    queue_node* front = NULL;  // 'front' pointer for the queue
    queue_node* rear = NULL;   // 'rear' pointer for the queue
    int count = 0;             // Will keep track of the number of nodes

    enqueue(&front, &rear, root);  // Enqueue the root node to start the BFS

    while (front != NULL) {            // While there are nodes in the queue
        node* current = dequeue(&front, &rear);  // Dequeue the front node
        count++;                                 // Increment the count for each node processed

        if (current->left) {                  // If the left child exists
            enqueue(&front, &rear, current->left);  // Enqueue the left child
        }
        if (current->right) {                 // If the right child exists
            enqueue(&front, &rear, current->right); // Enqueue the right child
        }
    }

    return count;  // Return the total number of nodes after BFS completes
}
