# Find Minimum Passes to Convert All Negative Values in a Matrix

## Problem Statement
You are given an **M x N** matrix of integers, where each cell can contain:
- A **negative** value,
- A **zero**, or
- A **positive** value.

The task is to determine the **minimum number of passes** required to convert all negative values in the matrix into positive values. 

### Conversion Rules
- A **positive** value in cell ‘(i, j)’ can convert negative values at its **adjacent cells** (up, down, left, and right) into positive values in one pass.
- Only cells with **non-zero positive values** can perform conversions.

### Constraints
1. The matrix can have dimensions M x N where 1 ≤ M, N ≤ 1000.
2. There may be unreachable negative cells (e.g., surrounded by zeroes or edges).
3. If it is **impossible** to convert all negative values to positive, return “-1.”

---

## Requirements

- Write a function that calculates the **minimum passes** to convert all negative values.
- If conversion is not possible, the function should return **-1**.

---

## Solution Approach (Hint: Use BFS Algorithm)
### Key Insights
1. **BFS (Breadth-First Search)** is ideal for this problem because it processes cells layer by layer (or level by level), which corresponds to the number of passes needed.
2. All positive cells at the start act as **sources**, and their propagation to adjacent negative cells can be modeled as a BFS traversal.

---

### What is a "Pass"?
A **pass** refers to one complete iteration where all the currently positive cells in the matrix try to convert their adjacent negative cells into positive cells. Think of it like a wave spreading from positive cells outward to adjacent negative cells.

#### Detailed Explanation with an Analogy
Imagine the matrix as a garden:

- Each positive number represents a **flower** that spreads its pollen.
- Each negative number represents a **weed** that can be converted into a flower if it is adjacent to a flower.
- A **pass** is like a single day in the garden: during the day, all flowers release their pollen to nearby weeds.

By the end of each pass (day), some weeds have turned into flowers, and in the next pass, the newly converted flowers help in spreading further.

---

### How Passes Work in the Matrix
1. **Start by identifying all positive cells** in the matrix. These cells will act as the "sources" of positivity in the first pass.
2. **In the first pass**:
    - Each positive cell converts its adjacent negative cells (up, down, left, right) into positive.
    - Once all positive cells have completed this process, the first pass ends.
3. **In the second pass**:
    - The cells that were converted into positive during the first pass now act as new sources of positivity.
    - They convert their adjacent negative cells into positive.
4. **This process continues pass by pass until**:
    - All negative cells are converted to positive, or
    - There are no more negative cells that can be reached.

---

### Example to Illustrate "Passes"
#### Input Matrix:
```plaintext
Matrix = [
    [0, -1, -3, 2, 0],
    [1, -2, -5, -1, -3],
    [3,  0,  0, -4, -2]
]
```

#### Step-by-Step Transformation:
1. **Initial State**:
    - Positive cells are: (0, 3), (1, 0), (2, 0).
    - Negative cells: All other negative values in the matrix.

2. **Pass 1**:
    - Positive cells spread their positivity to adjacent cells:
        - (0, 3) converts (0, 2) and (1, 3).
        - (1, 0) converts (1, 1).
        - (2, 0) converts (1, 0).
    - After Pass 1:
    ```plaintext
    [
        [0, -1,  2,  2,  0],
        [1,  2, -5,  2, -3],
        [3,  0,  0, -4, -2]
    ]
    ```

3. **Pass 2**:
    - Newly converted positive cells continue spreading:
        - (0, 2), (1, 1), and (1, 3) convert adjacent cells.
    - After Pass 2:
    ```plaintext
    [
        [0,  2,  2,  2,  0],
        [1,  2,  2,  2, -3],
        [3,  0,  0, -4, -2]
    ]
    ```

4. **Pass 3**:
    - Continue spreading:
    ```plaintext
    [
        [0,  2,  2,  2,  0],
        [1,  2,  2,  2,  2],
        [3,  0,  0,  2, -2]
    ]
    ```

5. **Pass 4**:
    - Final transformation (all negatives converted):
    ```plaintext
    [
        [0,  2,  2,  2,  0],
        [1,  2,  2,  2,  2],
        [3,  0,  0,  2,  2]
    ]
    ```

---

### Key Observations:
- A **pass** corresponds to one layer of BFS in the matrix.
- The **minimum number of passes** is the total number of BFS layers required to convert all negative cells into positive.

### Special Case: Impossible to Convert
If there are unreachable negative cells (e.g., surrounded by zeros or boundaries), they will never be converted. In such cases, the algorithm should return **-1**.

---

### Steps to Solve
1. **Initialize the Queue**:
    - Identify all positive cells in the matrix and add them to a queue.
    - Track the positions of negative cells and the total count of negative cells to verify at the end.

2. **BFS Traversal**:
    - For each cell in the queue, check its adjacent cells (up, down, left, and right).
    - If an adjacent cell contains a negative value, convert it to positive and add it to the queue for the next pass.

3. **Track Passes**:
    - Use a counter to keep track of the number of passes needed to propagate the positivity to all negative cells.

4. **Check Completion**:
    - After BFS finishes, verify if all negative cells have been converted. If not, return “-1.”

5. **Edge Cases**:
    - If there are no negative cells initially, return 0 passes.
    - If negative cells are surrounded by zeros (or matrix boundaries) and can never be reached, return “-1.”

---

### Why BFS?
- BFS ensures that all cells at the same "distance" (or pass) are processed before moving to the next level.
- This aligns with the problem’s requirement to count the **minimum number of passes**, as each level in BFS corresponds to one pass.

---

By following this approach, you’ll implement an efficient solution that correctly computes the minimum passes required to convert all negative values in the matrix to positive, or determines if it’s impossible.

