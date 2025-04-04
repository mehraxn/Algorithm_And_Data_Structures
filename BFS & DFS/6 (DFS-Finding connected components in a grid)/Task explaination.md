# Finding Connected Components in a Grid - README

## **Problem Statement**
You are given an `m x n` 2D grid (matrix) where each cell contains either a `1` (representing a component) or a `0` (empty space). Your task is to **count the number of connected components** in the grid.

A **connected component** is a group of adjacent `1`s that are connected **vertically or horizontally** (but NOT diagonally). Each group of connected `1`s forms a distinct component.

Return the total number of connected components.

---

## **Example 1** - Simple Case

### **Input Grid**
```
1 1 0 0 1
0 1 0 1 1
1 0 0 0 0
0 0 1 1 1
1 0 0 1 1
```

### **Output**
```
5
```

### **Explanation**
There are **5 connected components** in the grid:
1. The top-left `1`s form one component.
2. The single `1` at `(0,4)` forms another.
3. The `1`s at `(1,3)` and `(1,4)` form another component.
4. The `1`s at `(3,2)`, `(3,3)`, and `(3,4)` form another.
5. The `1`s at `(4,0)` and `(4,3)` form another.

---

## **Understanding the Problem Deeply**

### **What is a Connected Component?**
- A group of `1`s that are **horizontally or vertically** connected.
- A component stops when we encounter `0` or the grid boundary.

### **What is NOT a Connected Component?**
- `0`s (empty spaces) do NOT count as components.
- `1`s that are **diagonally adjacent** are NOT part of the same component.

### **Input Constraints**
- The grid is an `m x n` matrix where `1 ≤ m, n ≤ 1000` (suggesting an efficient solution is needed).
- The grid contains only `0`s and `1`s.
- There will always be at least one cell in the grid.

### **Output Format**
- A single integer representing the number of connected components.

---

## **Approach to Solve the Problem**
The problem is best solved using **Depth-First Search (DFS)** or **Breadth-First Search (BFS)**.

### **1. Depth-First Search (DFS) - Recursive Approach**
DFS is useful for exploring **entire connected components** in a **recursive manner**.

#### **Steps to Solve Using DFS:**
1. **Loop through each cell** in the grid.
2. **If a `1` is found:**
   - Increase the **component count**.
   - Perform **DFS traversal** to mark all connected `1`s as visited.
3. **Mark visited cells** by changing them to `0` to avoid revisiting.
4. **Continue scanning** the grid for other components.

#### **Time Complexity:**
- **O(m × n)** in the worst case (when all cells are `1`).
- **Space Complexity:** O(m × n) for recursion depth.

---

### **2. Breadth-First Search (BFS) - Iterative Approach**
BFS can also be used to **explore an entire component level by level**.

#### **Steps to Solve Using BFS:**
1. **Use a queue** and start from a found `1`.
2. **Process all its neighbors** (up, down, left, right) iteratively.
3. **Mark visited cells** as `0`.
4. **Continue until all components are counted.**

#### **Time Complexity:**
- **O(m × n)** (each cell is processed once).
- **Space Complexity:** O(m × n) (for queue storage).

---

## **Common Mistakes & Edge Cases**

### **1. Handling Diagonal Connections Incorrectly**
- Ensure that **only horizontal and vertical** connections are counted.
- If diagonal connections are mistakenly considered, the count will be incorrect.

### **2. Revisiting Cells**
- If we do not mark visited cells, we may count the same component multiple times.
- Always **mark visited cells immediately** when processing them.

### **3. Edge Cases**
- **All `0`s:** If the grid has only `0`s, return `0`.
- **All `1`s:** If the grid is entirely `1`, the answer is `1`.
- **Irregular Component Shapes:** Ensure your DFS/BFS correctly follows all adjacent `1`s, even if they form odd shapes.

---

## **Final Thought**
The **Connected Components** problem is a fundamental application of **graph traversal algorithms**. Understanding it will help in **image processing, clustering problems, and network connectivity analysis**.

- **DFS is great for recursively exploring** each component.
- **BFS is more iterative and memory-efficient for large grids.**

Mastering this concept will be useful for solving related problems like **island counting, flood fill, and pathfinding**.

Happy coding! 🚀

