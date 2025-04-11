# Understanding Queue Full Condition in BFS Implementation

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

