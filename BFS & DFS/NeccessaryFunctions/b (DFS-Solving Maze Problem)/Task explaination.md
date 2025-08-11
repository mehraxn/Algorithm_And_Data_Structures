# Solving Maze Problems - README

## **Problem Statement**
You are given an `m x n` 2D grid representing a maze. The maze consists of open paths (`1`) and walls (`0`). You must find a path from a given **starting position** `(sr, sc)` to a **destination position** `(dr, dc)`. You can only move **up, down, left, or right** (not diagonally).

Return `true` if a valid path exists; otherwise, return `false`.

Additionally, if required, return the **shortest path** from start to destination.

---

## **Example 1** - Path Exists

### **Input Grid**
```
1 1 0 1 1
0 1 0 1 0
1 1 1 1 1
0 1 0 0 1
1 1 1 1 1
```

#### **Start Position:** `(0, 0)`, **Destination Position:** `(4, 4)`

### **Output**
```
true
```

### **Explanation**
A valid path exists:
```
(S) → (0,1) → (1,1) → (2,1) → (2,2) → (2,3) → (2,4) → (3,4) → (4,4) (D)
```

---

## **Example 2** - No Path Exists

### **Input Grid**
```
1 1 0 0 1
0 1 0 1 0
1 1 0 1 1
0 1 0 0 1
1 1 1 1 1
```

#### **Start Position:** `(0, 0)`, **Destination Position:** `(4, 4)`

### **Output**
```
false
```

### **Explanation**
There is no possible way to reach `(4,4)` due to walls blocking the way.

---

## **Understanding the Problem Deeply**

### **What is a Maze Problem?**
A maze is a grid-based structure where we must find a way from a **start** point to an **end** point while avoiding walls.

### **What Defines a Valid Path?**
- A sequence of connected `1`s leading from the start to the destination.
- Only moves in four directions: **up, down, left, right**.
- No diagonal movement.

### **What is NOT a Valid Path?**
- Any movement into a `0` (wall) is not allowed.
- A path that **goes out of bounds** is invalid.
- If the start or destination is on a `0`, return `false` immediately.

### **Input Constraints**
- `1 ≤ m, n ≤ 1000` (large grid size suggests an efficient algorithm is needed).
- The grid consists only of `1`s (open) and `0`s (walls).
- `0 ≤ sr, sc < m`, `0 ≤ dr, dc < n` (valid indices inside the grid).

### **Output Format**
- A boolean (`true/false`) indicating whether a path exists.
- (Optional) The shortest path as a list of coordinates if required.

---

## **Approach to Solve the Problem**
There are two main approaches to solve a maze problem:

### **1. Depth-First Search (DFS) - For Checking Path Existence**
DFS is useful to **check if a path exists** but does not guarantee the shortest path.

#### **Steps to Solve Using DFS:**
1. **Start DFS from `(sr, sc)`**.
2. **Mark visited cells** to avoid infinite loops.
3. **Explore all possible moves** (up, down, left, right).
4. **If we reach `(dr, dc)`, return `true`**.
5. If no valid path is found, return `false`.

#### **Time Complexity:**
- **O(m × n)** in the worst case (explores the entire grid).

---

### **2. Breadth-First Search (BFS) - For Finding the Shortest Path**
Since BFS explores level by level, it finds the shortest path **first**.

#### **Steps to Solve Using BFS:**
1. **Use a queue** and start from `(sr, sc)` with `0` steps.
2. **Mark cells as visited when enqueuing them**.
3. **Explore all four directions** (up, down, left, right).
4. **If we reach `(dr, dc)`, return the number of steps**.
5. If the queue is exhausted without reaching the destination, return `-1`.

#### **Time Complexity:**
- **O(m × n)** (each cell is processed at most once).
- BFS is optimal for shortest path problems in unweighted grids.

---

## **Common Mistakes & Edge Cases**

### **1. No Path Exists**
- If the destination is surrounded by `0`s, return `false`.
- If the start position itself is a `0`, return `false` immediately.

### **2. Revisiting Cells**
- If we don’t mark visited cells, DFS may run indefinitely or BFS may take longer.
- Always **mark cells as visited when enqueuing** to prevent unnecessary reprocessing.

### **3. Handling Large Grids Efficiently**
- DFS can lead to **stack overflow** on large grids.
- BFS with a queue is better for handling large grid sizes efficiently.

### **4. Edge Cases**
- **Start and End at the Same Position:**
  - If `(sr, sc) == (dr, dc)`, return `true` immediately.
- **Grid Borders:**
  - Ensure you don’t move out of bounds when checking adjacent cells.

---

## **Final Thought**
Maze solving is an important problem in pathfinding, AI, and robotics.
- **DFS is good for checking if a path exists**.
- **BFS is optimal for finding the shortest path**.

Understanding these algorithms will help in game development, AI navigation, and real-world applications like robotic motion planning.

Happy coding! 🚀

