# Island Counting Problem - README

## **Problem Statement**
You are given a 2D grid (matrix) consisting of `1`s (land) and `0`s (water). Your task is to determine the number of distinct islands present in the grid. An island is formed by connecting adjacent `1`s **horizontally or vertically** (but not diagonally).

You must write an algorithm to count the number of islands efficiently.

---

## **Example**

### **Input Grid**
```
11110
11010
11000
00000
```

### **Output**
```
1
```
**Explanation:** All `1`s in the top-left form a single connected island.

---

### **Example 2**

#### **Input Grid**
```
11000
11000
00100
00011
```

#### **Output**
```
3
```
**Explanation:** There are three distinct islands:
1. The top-left `1`s form the first island.
2. The middle `1` forms the second island.
3. The two `1`s in the bottom-right corner form the third island.

---

## **Understanding the Problem Deeply**

1. **What is an Island?**
   - A group of `1`s (land) that are connected **vertically or horizontally** but not diagonally.
   - Two `1`s are considered part of the same island if they share an edge.
   - Each isolated landmass is considered an independent island.

2. **What is NOT an Island?**
   - `0`s (water) do not count as part of an island.
   - Two `1`s that are diagonally adjacent **do not** belong to the same island.

3. **Input Constraints**
   - The grid is an `m x n` matrix (`m` rows and `n` columns).
   - The grid consists of only `0`s and `1`s.
   - `1 ≤ m, n ≤ 300` (which means a brute-force solution may be inefficient).

4. **Output Format**
   - Return a single integer, representing the number of islands in the grid.

---

## **Approach to Solve the Problem**
We can use **Depth-First Search (DFS)** or **Breadth-First Search (BFS)** to traverse the grid and count the number of islands.

### **Steps to Solve Using DFS:**
1. **Loop through every cell** in the matrix.
2. If a `1` (land) is found:
   - **Increase the island count** by 1.
   - **Start a DFS traversal** to mark all connected `1`s as visited.
3. **Mark visited land** by changing `1` to `0` (or using a `visited` array).
4. Continue until the entire grid is traversed.

### **Time Complexity Analysis**
- Each cell is visited once, and all its neighbors are explored once.
- Time complexity: **O(m × n)**
- Space complexity:
  - **Recursive DFS:** O(m × n) (due to recursion depth for worst-case scenario)
  - **Iterative DFS or BFS:** O(m × n) (due to explicit stack or queue)

---

## **Common Mistakes & Edge Cases**

1. **Diagonal Connections:**
   - Remember that `1`s connected **diagonally** do not belong to the same island.

2. **Handling Large Grids Efficiently:**
   - Ensure that your solution does not use excessive memory, as the maximum grid size can be 300x300.
   - Using an explicit `visited` matrix can add extra memory overhead. Instead, modify the grid in-place by marking visited `1`s as `0`.

3. **Islands at the Edges:**
   - Ensure that `1`s touching the border of the grid are handled correctly.

4. **All Water Case:**
   - If the entire grid consists of `0`s, the output should be `0`.

5. **Single Large Island:**
   - A grid completely filled with `1`s should count as a **single** island.

---

## **Final Thought**
The island counting problem is an excellent example of using graph traversal (DFS/BFS) in a matrix. Understanding this problem thoroughly will help in solving similar problems related to connected components in graphs.

Happy coding! 🚀

