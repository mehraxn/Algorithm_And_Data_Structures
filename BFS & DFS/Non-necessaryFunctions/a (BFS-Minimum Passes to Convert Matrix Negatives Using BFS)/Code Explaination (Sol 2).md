# **README: Minimum Passes to Convert All Negative Values in a Matrix**

This program finds the **minimum number of passes** required to convert all negative values in a matrix into positive values, based on adjacency rules. It uses **Breadth-First Search (BFS)** to efficiently propagate the positivity through the matrix.

---

## **Features**
1. Converts all negative numbers to positive in the minimum number of "passes."
2. If it's impossible to convert all negatives (e.g., they are isolated), the program returns `-1`.
3. Efficient implementation using a queue for BFS traversal.

---

## **Problem Context**
We need to convert negative numbers in the matrix to positive, one "pass" at a time. A pass corresponds to all currently positive cells propagating their positivity to adjacent negative cells (up, down, left, and right).

The goal is to:
1. Count the **minimum number of passes** needed.
2. Return `-1` if it's impossible to convert all negatives.

---

## **Key Steps**

### **Initialization**
1. Start by scanning the matrix.
2. Add all positive numbers to a queue because these are the "starting points" or "sources" of positivity.
3. Keep track of the total number of negative numbers in the matrix to know when we’ve successfully converted them all.

### **Processing the Queue**
1. Each pass corresponds to processing all the elements currently in the queue.
2. For each positive number in the queue:
   - Check its neighboring cells (up, down, left, right).
   - If a neighboring cell contains a negative number, convert it to positive and add it to the queue.
3. Once all the positive numbers from the current pass are processed, increment the **pass count.**

### **End Condition**
1. The process continues until:
   - There are no more negative numbers left (`total_negatives == 0`), in which case the total number of passes is returned.
   - Or there are negative numbers that cannot be reached (surrounded by zeros or edges), in which case the function returns `-1.`

---

## **Why This Works**
The queue ensures that we process cells **level by level:**
1. In the first pass, we process all the initially positive numbers.
2. In the second pass, we process the numbers that were converted to positive in the first pass.
3. This continues until all reachable negative numbers are converted.

---

## **Example Walkthrough**

### **Input Matrix:**
```plaintext
[
    [0, -1, -3, 2, 0],
    [1, -2, -5, -1, -3],
    [3,  0,  0, -4, -2]
]
```

### **Step-by-Step Execution:**

#### **Initialization:**
- Positive numbers: `(0, 3), (1, 0), (2, 0)`.
- Queue: `[(0, 3), (1, 0), (2, 0)]`.
- Total negatives: `8.`

#### **Pass 1:**
1. Process `(0, 3)` → Converts `(0, 2)` and `(1, 3)`.
2. Process `(1, 0)` → Converts `(1, 1)`.
3. Process `(2, 0)` → Converts nothing new.
4. Queue after Pass 1: `[(0, 2), (1, 3), (1, 1)]`.
5. Remaining negatives: `5.`

#### **Pass 2:**
1. Process `(0, 2)` → Converts `(0, 1)`.
2. Process `(1, 3)` → Converts `(1, 2)` and `(1, 4)`.
3. Process `(1, 1)` → Converts nothing new.
4. Queue after Pass 2: `[(0, 1), (1, 2), (1, 4)]`.
5. Remaining negatives: `2.`

#### **Pass 3:**
1. Process `(0, 1)` → Converts nothing new.
2. Process `(1, 2)` → Converts `(2, 3)`.
3. Process `(1, 4)` → Converts `(2, 4)`.
4. Queue after Pass 3: `[(2, 3), (2, 4)]`.
5. Remaining negatives: `0.`

#### **Pass 4:**
1. All negatives are converted.
2. Queue is empty, and `total_negatives == 0.`

### **Output:**
```plaintext
4 passes.
```

---

## **Code Walkthrough**

### **1. Queue Implementation**

```c
// Define a structure for the queue
typedef struct {
    int x, y;
} Point;
```
- `Point`: Represents a cell in the matrix with its coordinates `(x, y)`.

```c
typedef struct {
    Point points[MAX * MAX];
    int front, rear;
} Queue;
```
- `Queue`: Stores an array of `Point` elements and maintains `front` and `rear` indices to manage the queue operations.

```c
void enqueue(Queue *q, int x, int y) {
    q->points[q->rear].x = x;
    q->points[q->rear].y = y;
    q->rear++;
}
```
- `enqueue`: Adds a new cell `(x, y)` to the rear of the queue and increments the `rear` index.

```c
Point dequeue(Queue *q) {
    return q->points[q->front++];
}
```
- `dequeue`: Removes and returns the cell at the front of the queue and increments the `front` index.

```c
int is_empty(Queue *q) {
    return q->front == q->rear;
}
```
- `is_empty`: Checks if the queue is empty by comparing `front` and `rear` indices.

### **2. Main BFS Logic**

```c
while (!is_empty(&queue)) {
    int size = queue.rear - queue.front;
    int converted = 0;

    for (int i = 0; i < size; i++) {
        Point p = dequeue(&queue);

        for (int d = 0; d < 4; d++) {
            int nx = p.x + directions[d][0];
            int ny = p.y + directions[d][1];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && matrix[nx][ny] < 0) {
                matrix[nx][ny] = 1;
                enqueue(&queue, nx, ny);
                total_negatives--;
                converted = 1;
            }
        }
    }

    if (converted) {
        passes++;
    }
}
```

#### **Key Points:**
- **`size`**: Determines how many cells to process in the current pass.
- **`converted`**: Tracks whether any negative cells were converted during this pass. If none were converted, BFS terminates.
- **`directions`**: Array that defines adjacent neighbors (up, down, left, right).

### **3. Termination Conditions**
1. BFS stops when:
   - The queue is empty (all possible conversions are done).
   - There are no more negative cells to convert.

---

## **Edge Cases**
1. **No Negative Cells:**
   - If the matrix has no negative values initially (`total_negatives == 0`), the function directly returns `0` (no passes needed).
2. **Unreachable Negatives:**
   - If negative cells are surrounded by `0` or boundaries (making them unreachable), `total_negatives > 0` after BFS, and the function returns `-1.`

---

## **Why BFS?**
1. BFS processes **layer by layer**, ensuring that each pass represents the spread of positivity to the nearest adjacent cells.
2. This approach matches the problem's requirements for counting **minimum passes**.

---

## **Time Complexity**
- **Initialization**: \(O(M \times N)\), where \(M\) and \(N\) are the matrix dimensions.
- **BFS Traversal**: Each cell is processed at most once, so \(O(M \times N)\).

### **Total Time Complexity**: \(O(M \times N)\).

---

## **Space Complexity**
- **Queue**: Stores at most \(O(M \times N)\) cells.
- **Total Space Complexity**: \(O(M \times N)\).

