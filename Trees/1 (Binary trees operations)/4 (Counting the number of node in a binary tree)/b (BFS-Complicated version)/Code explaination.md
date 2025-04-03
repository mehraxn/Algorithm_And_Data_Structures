# Breadth-First Search (BFS) Approach to Counting Nodes in a Binary Tree

## **Introduction**
This document explains a C program that implements **Breadth-First Search (BFS)** to count the number of nodes in a binary tree. The BFS approach is implemented using a **queue** to ensure that nodes are processed **level by level**.

The program consists of the following main components:
1. **Binary tree node structure**
2. **Queue node structure** (for BFS implementation)
3. **Queue operations (enqueue and dequeue)**
4. **BFS-based node counting function**

Each part is explained in detail below.

---

## **1. Header Files**
```c
#include <stdio.h>   // Provides declarations for I/O functions like printf, scanf, etc.
#include <stdlib.h>  // Provides declarations for memory allocation functions like malloc, free, etc.
```
- `#include <stdio.h>`: Used for input-output functions (e.g., `printf`).
- `#include <stdlib.h>`: Used for memory allocation (`malloc`, `free`) and other utility functions.

---

## **2. Defining a Binary Tree Node**
```c
typedef struct node_t {
    int key;                // 'key' stores the integer data for this node
    struct node_t* left;    // Pointer to the left child node
    struct node_t* right;   // Pointer to the right child node
} node;
```
### **Explanation:**
- Defines a **binary tree node**.
- `key`: Stores integer data.
- `left`: Pointer to the left child node.
- `right`: Pointer to the right child node.

---

## **3. Defining a Queue Node**
```c
typedef struct queue_node {
    node* treeNode;             // This holds a pointer to a 'node' from the binary tree
    struct queue_node* next;    // Pointer to the next element in the queue
} queue_node;
```
### **Explanation:**
- This structure implements a **queue node**, which stores:
  - A pointer (`treeNode`) to a binary tree node.
  - A `next` pointer to the next queue node.
- The queue is necessary for **BFS** because it processes nodes **level by level**.

---

## **4. Enqueue Function (Push into Queue)**
```c
void enqueue(queue_node** front, queue_node** rear, node* treeNode) {
    queue_node* newNode = (queue_node*)malloc(sizeof(queue_node)); // Allocate memory for a new queue node
    newNode->treeNode = treeNode;                                  // Assign the tree node
    newNode->next = NULL;                                          // It will be the last element in the queue

    if (*rear) {                   // If the queue is not empty
        (*rear)->next = newNode;   // Link the last node to the new node
    } else {
        *front = newNode;          // If empty, front points to the new node
    }
    *rear = newNode;               // Update rear to the new node
}
```
### **How Enqueue Works:**
- **Creates a new queue node** and assigns it a tree node.
- If the queue is **not empty**, it links the last node (`rear`) to this new node.
- If the queue **is empty**, both `front` and `rear` are set to the new node.
- Updates `rear` to point to the newly added node.

---

## **5. Dequeue Function (Remove from Queue)**
```c
node* dequeue(queue_node** front, queue_node** rear) {
    if (!*front) {    // If the queue is empty
        return NULL;
    }

    queue_node* temp = *front;    // Temporarily store the front node
    node* treeNode = temp->treeNode;  // Extract the tree node from the queue node
    *front = (*front)->next;      // Move the front pointer to the next element

    if (!*front) {    // If the queue is now empty
        *rear = NULL; // Reset the rear pointer
    }

    free(temp);       // Free memory of dequeued node
    return treeNode;  // Return the extracted tree node
}
```
### **How Dequeue Works:**
- If the queue is **empty**, return `NULL`.
- Store the `front` node temporarily.
- Move `front` to the next node.
- If the queue becomes **empty**, set `rear = NULL`.
- Free the memory of the dequeued node.
- Return the extracted tree node.

---

## **6. BFS to Count Nodes**
```c
int count_nodes_bfs(node* root) {
    if (root == NULL) {   // If the tree is empty, return 0
        return 0;
    }

    queue_node* front = NULL;  // 'front' pointer for the queue
    queue_node* rear = NULL;   // 'rear' pointer for the queue
    int count = 0;             // Node count

    enqueue(&front, &rear, root);  // Start BFS by enqueuing the root

    while (front != NULL) {        // While there are nodes in the queue
        node* current = dequeue(&front, &rear);  // Get the next node
        count++;                   // Count this node

        if (current->left) {  // If left child exists
            enqueue(&front, &rear, current->left);  // Enqueue left child
        }
        if (current->right) { // If right child exists
            enqueue(&front, &rear, current->right); // Enqueue right child
        }
    }

    return count;  // Return total node count
}
```

---

## **BFS (Breadth-First Search) Approach**
This function implements **BFS traversal**, processing the tree level by level:
1. **Start with the root** and add it to the queue.
2. **Dequeue each node** and process its children.
3. **Add left and right children** (if they exist) to the queue.
4. **Repeat until no nodes are left**.

### **Example Tree:**
```
       1
      / \
     2   3
    / \
   4   5
```
#### **BFS Order (Node Counting)**
| Step | Queue State   | Dequeued | Count |
|------|--------------|----------|-------|
| 1    | [1]          | 1        | 1     |
| 2    | [2, 3]       | 2        | 2     |
| 3    | [3, 4, 5]    | 3        | 3     |
| 4    | [4, 5]       | 4        | 4     |
| 5    | [5]          | 5        | 5     |
| 6    | []           | -        | 5     |

At the end, **count = 5**, which is the total number of nodes.

---

## **Final Thoughts**
- **BFS is used here to systematically count all nodes in a tree.**
- **Queue ensures level-order traversal** (visiting each level completely before moving to the next).
- **Space Complexity**: \(O(N)\) (worst case, when all nodes are in the queue).
- **Time Complexity**: \(O(N)\) (each node is processed once).

This implementation is efficient and ensures all nodes are counted properly. 🚀

