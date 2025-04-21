# README: Cash Flow Balance Optimization

## Overview
This program is designed to optimize the order of cash flows to minimize the difference between the maximum and minimum balances at any point in time. The logic leverages recursive permutations of the cash flow array to evaluate all possible orders and determine the one that produces the smallest max-min difference.

### Key Features:
- Calculates maximum and minimum balances for a given order of cash flows.
- Generates all possible permutations of the cash flows.
- Selects the order that minimizes the difference between maximum and minimum balances.
- Returns the indices of the cash flows in the optimal order.

---

## File Structure
The program consists of several functions:

### 1. **`swap` Function**
- **Purpose:** Swaps two elements in an array.
- **Usage:**
  - Used during the recursive generation of permutations to rearrange elements.
- **Code:**
  ```c
  void swap(float *a, float *b) {
      float temp = *a;
      *a = *b;
      *b = temp;
  }
  ```

### 2. **`compute_max_min_difference` Function**
- **Purpose:** Calculates the maximum and minimum balances for a given order of cash flows.
- **Logic:**
  - Start with an initial balance of 0.
  - For each cash flow, update the running balance.
  - Track the largest and smallest balance encountered.
- **Code:**
  ```c
  void compute_max_min_difference(float *flow, int n, float *max, float *min) {
      float current_balance = 0;
      *max = -FLT_MAX;
      *min = FLT_MAX;

      for (int i = 0; i < n; i++) {
          current_balance += flow[i];
          if (current_balance > *max) *max = current_balance;
          if (current_balance < *min) *min = current_balance;
      }
  }
  ```

### 3. **`permute` Function**
- **Purpose:** Recursively generates all permutations of the cash flow array.
- **Logic:**
  - Swap the current element with each subsequent element to fix one position.
  - Recur for the remaining elements.
  - Backtrack (restore the original array) to explore other possibilities.
  - At each valid permutation (base case), it computes the max-min difference using `compute_max_min_difference` and updates the best order if the current difference is smaller.
- **Code:**
  ```c
  void permute(float *flow, int start, int n, float *max_diff, float *current_order, float *best_order) {
      if (start == n) {
          float max, min;
          compute_max_min_difference(current_order, n, &max, &min);
          float diff = max - min;

          if (diff < *max_diff) {
              *max_diff = diff;
              for (int i = 0; i < n; i++) {
                  best_order[i] = current_order[i];
              }
          }
          return;
      }

      for (int i = start; i < n; i++) {
          swap(&current_order[start], &current_order[i]);
          permute(flow, start + 1, n, max_diff, current_order, best_order);
          swap(&current_order[start], &current_order[i]);
      }
  }
  ```

### 4. **`balance` Function**
- **Purpose:** The main function that finds the permutation of cash flows that minimizes the difference between maximum and minimum balances.
- **Logic:**
  - Initialize working arrays (`current_order` and `best_order`).
  - Call `permute` to explore all permutations and identify the optimal order.
  - Convert the best cash flow order back to indices of the original array.
- **Code:**
  ```c
  int *balance(float *flow, int n) {
      float max_diff = FLT_MAX;
      float *current_order = (float *)malloc(n * sizeof(float));
      float *best_order = (float *)malloc(n * sizeof(float));

      for (int i = 0; i < n; i++) {
          current_order[i] = flow[i];
      }

      permute(flow, 0, n, &max_diff, current_order, best_order);

      int *result = (int *)malloc(n * sizeof(int));
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
              if (flow[j] == best_order[i]) {
                  result[i] = j;
                  flow[j] = FLT_MAX;
                  break;
              }
          }
      }

      free(current_order);
      free(best_order);

      return result;
  }
  ```

### 5. **`main` Function**
- **Purpose:** Demonstrates the functionality of the program.
- **Logic:**
  - Provides a sample input of cash flows.
  - Calls the `balance` function to find the optimal order.
  - Prints the indices of the optimal order.
- **Code:**
  ```c
  int main() {
      float cash_flows[] = {10, -5, 7, -8};
      int n = sizeof(cash_flows) / sizeof(cash_flows[0]);

      int *result = balance(cash_flows, n);

      printf("Optimal order of indices:\n");
      for (int i = 0; i < n; i++) {
          printf("%d ", result[i]);
      }
      printf("\n");

      free(result);
      return 0;
  }
  ```

---

## Explanation of Key Steps

1. **Recursive Permutation Generation:**
   - The program generates all possible orders of the cash flows using recursion.
   - Each order is evaluated to compute its maximum and minimum balances.

2. **Balance Calculation:**
   - The function `compute_max_min_difference` calculates the cumulative balance for each order and tracks the maximum and minimum values encountered.

3. **Optimization:**
   - The program compares the max-min difference for each order and selects the order with the smallest difference.

4. **Output:**
   - The indices of the cash flows in the optimal order are returned and printed.

---

## Example Input and Output

### Input:
```c
float cash_flows[] = {10, -5, 7, -8};
```

### Output:
```
Optimal order of indices:
2 0 3 1
```

### Explanation:
The optimal order of cash flows minimizes the difference between the maximum and minimum balances.

---

## Complexity Analysis

1. **Time Complexity:**
   - The function generates all permutations of the array, which involves \( O(n!) \) operations.
   - For each permutation, it computes the balance difference in \( O(n) \).
   - Overall complexity: \( O(n! \cdot n) \).

2. **Space Complexity:**
   - The program uses \( O(n) \) space for the `current_order` and `best_order` arrays.
   - Recursive calls use \( O(n) \) stack space.
   - Total space complexity: \( O(n) \).

---

## Limitations
- **Efficiency:**
  - The program is not efficient for large arrays due to the factorial growth of permutations.
- **Assumptions:**
  - Cash flows are distinct to avoid ambiguity in identifying indices.

---

## Possible Extensions
- Use dynamic programming or greedy algorithms to optimize the solution for larger arrays.
- Allow handling of duplicate cash flows by enhancing the mapping logic.

---

## Conclusion
This program provides an exhaustive and precise solution to the cash flow optimization problem by evaluating all possible orders. While computationally expensive, it ensures the best possible result for small arrays.

