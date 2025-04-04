# Flood Fill Algorithm - README

## **Problem Statement**
You are given a 2D grid (matrix) representing an image. Each cell in the grid represents a pixel with a specific color. Your task is to implement a **flood fill algorithm**, similar to the paint bucket tool in image editing software.

Given a starting pixel `(sr, sc)` and a `newColor`, change the color of the starting pixel and all adjacent pixels with the **same original color** to the `newColor`. The adjacency is defined by **four-way connectivity** (top, bottom, left, right), meaning diagonal pixels are **not** affected.

You must return the modified image.

---

## **Example**

### **Input Grid (Before Filling)**
```
1 1 1
1 1 0
1 0 1
```

#### **Starting Position:** `(sr=1, sc=1)`, **New Color:** `2`

### **Output Grid (After Filling)**
```
2 2 2
2 2 0
2 0 1
```

**Explanation:**
- The pixel at `(1,1)` is originally `1`. All `1`s connected to it (top, bottom, left, right) get changed to `2`.
- The `0`s and `1`s that are not connected remain unchanged.

---

## **Understanding the Problem Deeply**

### **What is Flood Fill?**
Flood fill is an algorithm used in:
- **Image processing** (e.g., paint bucket tool in Photoshop/MS Paint).
- **Graph traversal problems** (e.g., exploring connected regions in a grid).
- **Game development** (e.g., filling regions in tile-based games).

### **What Should Be Changed?**
- The **starting pixel** and all its connected pixels **of the same original color**.
- Only four-way connected pixels are considered (**not diagonals**).

### **What Should NOT Be Changed?**
- Pixels that **do not match** the original color of the starting pixel.
- Pixels that are **outside the grid boundaries**.
- Pixels that are **diagonally connected** to the region.

### **Input Constraints**
- `image` is an `m x n` matrix where `1 ≤ m, n ≤ 50`.
- `0 ≤ image[i][j] ≤ 65535` (representing pixel colors).
- `0 ≤ sr < m, 0 ≤ sc < n` (valid starting position).
- The `newColor` is an integer between `0` and `65535`.

### **Output Format**
- A modified version of the input matrix with the applied flood fill operation.

---

## **Approach to Solve the Problem**
We can solve this using **Depth-First Search (DFS)** or **Breadth-First Search (BFS)**.

### **Steps to Solve Using DFS:**
1. **Store the original color** of the starting pixel.
2. **If the original color is already the new color, return the image as-is** (to avoid infinite recursion).
3. **Perform DFS:**
   - Change the current pixel to `newColor`.
   - Recursively apply the same operation to its four neighboring pixels **if they match the original color**.
4. **Continue until all connected pixels are filled**.

### **Steps to Solve Using BFS:**
1. **Use a queue instead of recursion**.
2. Start with the `(sr, sc)` pixel and apply the color change.
3. Add its four neighbors to the queue if they match the original color.
4. Process the queue iteratively until no more pixels need changing.

### **Time Complexity Analysis**
- Each pixel is visited at most once.
- **Time Complexity:** `O(m × n)` in the worst case (if the entire image is filled).
- **Space Complexity:** `O(m × n)` (for recursion depth in DFS or queue storage in BFS).

---

## **Common Mistakes & Edge Cases**

### **1. Changing the Same Color to Itself**
- If the `newColor` is the same as the **original color**, the function should return immediately to avoid unnecessary operations.
- Example:
  - `image = [[1,1,1],[1,1,0],[1,0,1]]`
  - `sr = 1, sc = 1, newColor = 1` → **Do nothing, return as-is**.

### **2. Handling Large Regions**
- Recursive DFS can lead to **stack overflow** for large connected regions.
- Solution: Use **BFS (queue-based approach)** to avoid deep recursion.

### **3. Diagonal Adjacency Misconception**
- Only consider **four-way connectivity** (top, bottom, left, right). Diagonal pixels are **not** affected.
- Example:
  - `1 1 1`
  - `1 1 0`
  - `1 0 1`
  - The bottom-right `1` is **not** filled because it is only diagonally connected.

### **4. Border Cases**
- If the starting pixel is at the **edge of the grid**, make sure not to access out-of-bounds indices.
- Example:
  - `sr = 0, sc = 0` (top-left corner)
  - `sr = m-1, sc = n-1` (bottom-right corner)

### **5. Non-Rectangular Grids**
- Ensure the algorithm works for non-square matrices (e.g., `3x5` or `5x3`).

---

## **Final Thought**
Flood Fill is a fundamental algorithm used in many real-world applications. Understanding it will help in mastering **graph traversal techniques** like DFS and BFS. Ensure your solution handles edge cases efficiently to avoid infinite loops or excessive memory usage.

Happy coding! 🎨🚀

