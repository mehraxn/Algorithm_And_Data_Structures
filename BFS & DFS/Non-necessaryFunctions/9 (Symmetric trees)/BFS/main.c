#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode* left;
    struct TreeNode* right;
} NodePair;

typedef struct {
    NodePair* data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;
    q->data = (NodePair*)malloc(sizeof(NodePair) * capacity);
    if (!q->data) {
        free(q);
        return NULL;
    }
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

bool isQueueFull(Queue* q) {
    return q->rear == q->capacity;
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, struct TreeNode* l, struct TreeNode* r) {
    if (isQueueFull(q)) {
        return; // Avoid buffer overflow
    }
    q->data[q->rear].left = l;
    q->data[q->rear].right = r;
    q->rear++;
}

NodePair dequeue(Queue* q) {
    NodePair pair = {NULL, NULL};
    if (isQueueEmpty(q)) {
        return pair;
    }
    pair = q->data[q->front];
    q->front++;
    return pair;
}

void freeQueue(Queue* q) {
    if (q) {
        free(q->data);
        free(q);
    }
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) {
        return true;
    }
    Queue* queue = createQueue(10000);
    if (!queue) return false;

    enqueue(queue, root->left, root->right);

    while (!isQueueEmpty(queue)) {
        NodePair pair = dequeue(queue);
        struct TreeNode* leftNode = pair.left;
        struct TreeNode* rightNode = pair.right;

        if (!leftNode && !rightNode) {
            continue;
        }
        if (!leftNode || !rightNode || leftNode->val != rightNode->val) {
            freeQueue(queue);
            return false;
        }

        enqueue(queue, leftNode->left, rightNode->right);
        enqueue(queue, leftNode->right, rightNode->left);
    }

    freeQueue(queue);
    return true;
}
