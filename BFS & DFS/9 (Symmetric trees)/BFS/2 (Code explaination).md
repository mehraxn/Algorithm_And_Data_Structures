# Queue Data Structure in BFS

## Overview
A queue is a fundamental data structure used in the Breadth-First Search (BFS) algorithm. It follows the **FIFO (First-In-First-Out)** principle, meaning elements are added at the rear and removed from the front. The queue ensures that nodes are processed in the correct order during traversal.

## Queue Structure
```c
typedef struct {
    NodePair* data;  // Array storing queue elements
    int front;       // Points to the front element (oldest)
    int rear;        // Points to the last element (newest)
    int capacity;    // Maximum number of elements in the queue
} Queue;
```

### **Front and Rear Explained**
- **front**: Points to the first (oldest) element in the queue.
- **rear**: Points to the position where the newest element has just been inserted (or where the next insertion will occur).

## Example Demonstration
Consider a queue with a **capacity of 5** that stores integer values.

### **Initial State (Empty Queue)**
```
Data: [ _, _, _, _, _ ]
front = -1
rear = -1
```
(No elements are present yet.)

### **Step 1: Enqueue(10)**
```
Data: [ 10, _, _, _, _ ]
front = 0  // First element inserted, front points here
rear = 0   // Rear also points here
```

### **Step 2: Enqueue(20)**
```
Data: [ 10, 20, _, _, _ ]
front = 0  // 10 is still the first element
rear = 1   // 20 is added at index 1
```

### **Step 3: Enqueue(30)**
```
Data: [ 10, 20, 30, _, _ ]
front = 0  // 10 remains the first element
rear = 2   // 30 is inserted at index 2
```

### **Step 4: Dequeue() (Removing 10)**
```
Data: [ x, 20, 30, _, _ ]  (10 is removed)
front = 1  // Now points to 20, the new front element
rear = 2   // 30 is still the newest element
```

### **Step 5: Enqueue(40)**
```
Data: [ x, 20, 30, 40, _ ]
front = 1  // Still pointing to 20
rear = 3   // 40 is inserted at index 3
```

## Key Takeaways
1. **front** moves forward when an element is dequeued.
2. **rear** moves forward when an element is enqueued.
3. If `front == rear + 1`, the queue is empty.
4. If `rear == capacity - 1`, the queue is full (in a non-circular queue implementation).
5. BFS relies on the queue to process nodes in order, ensuring a level-wise traversal of graphs or trees.

Understanding these principles will help you implement and debug BFS efficiently!

