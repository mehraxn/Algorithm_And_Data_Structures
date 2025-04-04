#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for BFS
struct Queue {
    struct Node* items[MAX];
    int front, rear;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue operations
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* value) {
    if (q->rear == MAX - 1)
        return;

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->items[q->rear] = value;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q))
        return NULL;

    struct Node* item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;

    return item;
}

// Function to perform complete level-order traversal
void levelOrder(struct Node* root, int* output, int* outSize) {
    struct Queue* q = createQueue();
    enqueue(q, root);

    int count = 0;
    while (!isEmpty(q)) {
        struct Node* curr = dequeue(q);

        if (curr != NULL) {
            output[count++] = curr->data;
            enqueue(q, curr->left);
            enqueue(q, curr->right);
        } else {
            output[count++] = -1;
            enqueue(q, NULL);
            enqueue(q, NULL);
        }

        // Break if all remaining nodes are NULL
        int allNull = 1;
        for (int i = q->front; i <= q->rear && i != -1; i++) {
            if (q->items[i] != NULL) {
                allNull = 0;
                break;
            }
        }
        if (allNull)
            break;
    }

    *outSize = count;
    free(q); // Free the queue
}

// Recursive function to free tree memory
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main for testing
int main() {
    /*
          1
         / \
        2   3
       /     \
      4       5
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);

    int output[MAX];
    int size = 0;

    levelOrder(root, output, &size);

    printf("Level-order (with -1 for NULLs):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    freeTree(root); // Free all tree nodes
    return 0;
}
