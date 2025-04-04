# Understanding Queue Full Condition in BFS Implementation

## Why Checking Only `rear == MAX - 1` is Insufficient?
In a **simple linear queue**, we increment `rear` when enqueuing and `front` when dequeuing. However, once `rear` reaches `MAX - 1`, the queue is considered full even if there is available space at the beginning due to dequeued elements.

### Example (Queue of Size 5)

| Operation  | Queue Content  | front | rear |
|------------|--------------|-------|------|
| Enqueue(1) | [1]          | 0     | 0    |
| Enqueue(2) | [1, 2]       | 0     | 1    |
| Enqueue(3) | [1, 2, 3]    | 0     | 2    |
| Dequeue()  | [X, 2, 3]    | 1     | 2    |
| Dequeue()  | [X, X, 3]    | 2     | 2    |
| Enqueue(4) | [X, X, 3, 4] | 2     | 3    |
| Enqueue(5) | [X, X, 3, 4, 5] | 2  | 4    |
| Enqueue(6) ❌ | **Queue is Full (incorrect!)** | 2 | 4 |

Even though there are empty slots at the start, the condition `rear == MAX - 1` **incorrectly** considers the queue as full.

---

## How to Fix This Issue?
### Solution: **Use a Circular Queue**
Instead of checking `rear == MAX - 1`, use the condition:

definition
```
(rear + 1) % MAX == front
```

This ensures that the queue is full only when there are no empty slots left.

### Circular Queue Behavior:
- When `rear` reaches `MAX - 1` and there is space at the beginning, it wraps around to index `0`.
- This allows full utilization of available space.

Would you like a C implementation of a **circular queue**? 🚀

