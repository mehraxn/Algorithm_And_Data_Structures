# Readme: Symmetric Binary Tree Checker

## Overview
This C program checks whether a given binary tree is symmetric around its center using an iterative approach with a queue. The program consists of:

- **TreeNode struct**: Represents a node in the binary tree.
- **NodePair struct**: Holds a pair of tree nodes for comparison.
- **Queue struct**: Implements a queue for breadth-first traversal.
- **Queue functions**: Handles queue operations (enqueue, dequeue, check empty/full, and free memory).
- **isSymmetric function**: Checks if a binary tree is symmetric.

---

## Structs Explanation

### `TreeNode` Struct
```c
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
```
- Represents a node in the binary tree.
- `val`: Stores the integer value of the node.
- `left`: Pointer to the left child.
- `right`: Pointer to the right child.

### `NodePair` Struct
```c
typedef struct {
    struct TreeNode* left;
    struct TreeNode* right;
} NodePair;
```
- Holds two tree nodes that need to be compared.
- `left`: Pointer to the left node.
- `right`: Pointer to the right node.

### `Queue` Struct
```c
typedef struct {
    NodePair* data;
    int front;
    int rear;
    int capacity;
} Queue;
```
- Implements a queue for breadth-first traversal.
- `data`: Array of `NodePair` elements.
- `front`: Index of the first element in the queue.
- `rear`: Index of the next available position in the queue.
- `capacity`: Maximum number of elements the queue can hold.

---

## Functions Explanation

### `createQueue`
```c
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
```
- Dynamically allocates memory for a `Queue`.
- Initializes `front` and `rear` to 0.
- Allocates memory for `data` (array of `NodePair`).
- Returns `NULL` if memory allocation fails.

### `isQueueFull`
```c
bool isQueueFull(Queue* q) {
    return q->rear == q->capacity;
}
```
- Checks if the queue is full by comparing `rear` to `capacity`.

### `isQueueEmpty`
```c
bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}
```
- Checks if the queue is empty by comparing `front` and `rear`.

### `enqueue`
```c
void enqueue(Queue* q, struct TreeNode* l, struct TreeNode* r) {
    if (isQueueFull(q)) {
        return;
    }
    q->data[q->rear].left = l;
    q->data[q->rear].right = r;
    q->rear++;
}
```
- Adds a `NodePair` to the queue.
- Checks if the queue is full before adding.
- Increments `rear` after insertion.

### `dequeue`
```c
NodePair dequeue(Queue* q) {
    NodePair pair = {NULL, NULL};
    if (isQueueEmpty(q)) {
        return pair;
    }
    pair = q->data[q->front];
    q->front++;
    return pair;
}
```
- Removes and returns the front `NodePair` from the queue.
- Checks if the queue is empty before removing.
- Increments `front` after removal.

### `freeQueue`
```c
void freeQueue(Queue* q) {
    if (q) {
        free(q->data);
        free(q);
    }
}
```
- Frees allocated memory for the queue and its data.

### `isSymmetric`
```c
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
```
- **Base Case**: If the tree is empty (`root == NULL`), return `true`.
- **Initialize Queue**: Create a queue and enqueue the left and right child of `root`.
- **Iterate through Queue**:
  - Dequeue `NodePair` and extract `leftNode` and `rightNode`.
  - If both are `NULL`, continue.
  - If only one is `NULL` or values are different, return `false`.
  - Enqueue corresponding children to check symmetry.
- **Return true**: If all comparisons pass, the tree is symmetric.

---

## Complexity Analysis
- **Time Complexity**: O(n), where `n` is the number of nodes in the tree. Each node is visited once.
- **Space Complexity**: O(n) in the worst case when all nodes are stored in the queue.

---

## Summary
This program efficiently checks for tree symmetry using an iterative breadth-first approach. The queue ensures nodes are compared level by level, making it a robust solution for large binary trees.

