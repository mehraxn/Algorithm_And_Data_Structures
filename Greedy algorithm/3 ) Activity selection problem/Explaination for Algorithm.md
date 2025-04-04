# Activity Selection Problem - Greedy Algorithm

## Introduction
The **Activity Selection Problem** is a classic **Greedy Algorithm** problem used to select the maximum number of **non-overlapping activities** that can be scheduled within a given time frame. The goal is to maximize the number of activities while ensuring that no two selected activities overlap in time.

This problem is widely used in **scheduling**, **resource allocation**, and **event management** applications.

## Problem Statement
Given **N activities**, each with a **start time** and an **end time**, the objective is to select the maximum number of activities that **do not overlap**.

### Example:
Consider the following set of activities:

| Activity | Start Time | End Time |
|----------|-----------|----------|
| A        | 1         | 3        |
| B        | 2         | 5        |
| C        | 4         | 6        |
| D        | 6         | 8        |
| E        | 5         | 7        |
| F        | 8         | 9        |

### Expected Output:
The maximum number of non-overlapping activities that can be selected are:
- **A (1-3)**
- **C (4-6)**
- **D (6-8)**
- **F (8-9)**

## Approach: Greedy Algorithm
The **Greedy Algorithm** is an **optimal approach** for solving this problem. The key idea is:
1. **Sort** the activities by their **end times** (in ascending order).
2. **Select** the first activity (the one that finishes earliest).
3. **Iterate** through the remaining activities and select the next **non-overlapping** activity.
4. **Repeat** until no more activities can be selected.

## Algorithm Steps
1. **Sort** all activities by their **end times** in ascending order.
2. **Pick the first activity** (since it has the earliest end time).
3. **For each remaining activity:**
   - If the activity’s **start time is greater than or equal to the last selected activity’s end time**, select it.
   - Update the latest selected activity’s end time.
4. **Continue** until all activities are checked.

## Implementation (C Language)
```c
#include <stdio.h>
#include <stdlib.h>

// Define a structure for activities
typedef struct {
    int start, stop;
} Activity;

// Comparison function to sort activities by end time
int cmp(const void *a, const void *b) {
    return ((Activity*)a)->stop - ((Activity*)b)->stop;
}

// Function to select the maximum number of non-overlapping activities
void activitySelection(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), cmp);
    
    int count = 1;
    int last_end_time = activities[0].stop;
    printf("Selected Activities: (Start, Stop)\n");
    printf("(%d, %d)\n", activities[0].start, activities[0].stop);

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= last_end_time) {
            printf("(%d, %d)\n", activities[i].start, activities[i].stop);
            last_end_time = activities[i].stop;
            count++;
        }
    }
    printf("Total Selected Activities: %d\n", count);
}

int main() {
    Activity activities[] = {{1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 7}, {8, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);
    activitySelection(activities, n);
    return 0;
}
```

## Explanation of the Code
1. **Sorting**: The activities are sorted by their **end time** using `qsort()` and `cmp()`.
2. **Greedy Selection**:
   - The first activity is always selected.
   - Each subsequent activity is checked against the last selected activity’s end time.
   - If it **does not overlap**, it is selected.
3. **Output**:
   - The program prints the selected activities and the total count of activities chosen.

## Time Complexity Analysis
- **Sorting the activities**: `O(N log N)` (due to `qsort()`)
- **Iterating through activities**: `O(N)`
- **Overall Complexity**: **`O(N log N)`**, which is efficient for large inputs.

## Why is the Greedy Algorithm Optimal?
- By selecting the activity that **finishes first**, we leave the **maximum remaining time** for other activities.
- The **earliest finishing activity** allows us to fit in more activities later.
- **Mathematical proof (greedy stays ahead)** shows that this approach always leads to an optimal solution.

## Applications of Activity Selection Algorithm
- **Task scheduling**: Choosing the maximum number of non-overlapping jobs.
- **Event management**: Scheduling conference talks in a hall.
- **CPU job scheduling**: Selecting jobs that minimize idle CPU time.
- **Meeting room allocation**: Optimizing room usage based on end times.

## Conclusion
The **Activity Selection Problem** is a fundamental **Greedy Algorithm** that efficiently finds the **maximum number of non-overlapping activities**. This approach is widely used in scheduling, resource allocation, and optimization problems.

By following the **greedy strategy of selecting the earliest finishing activity**, we ensure that we maximize the number of activities that can be performed.

---

**📌 Summary:**
- **Sort activities by end time**.
- **Select the first activity**.
- **Iterate and pick non-overlapping activities**.
- **Efficient `O(N log N)` solution using greedy approach**.

🚀 **This method is optimal and widely used in real-world applications!**

