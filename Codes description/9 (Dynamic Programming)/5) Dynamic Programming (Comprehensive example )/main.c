#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;  // Returns the maximum of a and b
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int weight[], int value[], int n) {
    // dp[i][w] will store the maximum value that can be obtained with the first i items and capacity w
    // We need a (n+1) x (W+1) table to store the results of subproblems
    int dp[n+1][W+1];  // dp[i][w] represents the max value for the first i items with capacity w

    // Build the dp table in a bottom-up manner
    for (int i = 0; i <= n; i++) {  // Loop over the items (0 to n)
        for (int w = 0; w <= W; w++) {  // Loop over all possible capacities (0 to W)

            // Base case: if no items or zero capacity, max value is 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // No items or no capacity, so max value = 0
            }
            else if (weight[i-1] <= w) {
                // Case 1: If the current item can be included in the knapsack
                // We have two choices:
                // 1. Exclude the current item: dp[i-1][w]
                // 2. Include the current item: value[i-1] + dp[i-1][w - weight[i-1]]
                dp[i][w] = max(dp[i-1][w], value[i-1] + dp[i-1][w - weight[i-1]]);
            } else {
                // Case 2: If the current item cannot be included (weight[i-1] > w)
                // We take the value from the previous row (exclude the item)
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // The maximum value will be stored in dp[n][W] after filling the table
    return dp[n][W];  // The answer is in the bottom-right corner of the table
}

int main() {
    // Example input: number of items
    int n = 4;

    // Weights of the items
    int weight[] = {2, 3, 4, 5};

    // Values of the items
    int value[] = {3, 4, 5, 6};

    // Capacity of the knapsack
    int W = 5;

    // Function call to solve the knapsack problem
    int result = knapsack(W, weight, value, n);

    // Output the result
    printf("Maximum value in Knapsack = %d\n", result);

    return 0;
}

/*
Detailed Explanation of the Dynamic Programming Concept:

1. Dynamic Programming Approach:
    - The idea of Dynamic Programming (DP) is to solve complex problems by breaking them into smaller subproblems and storing the solutions of these subproblems to avoid redundant work.
    - The DP solution builds up the answer using overlapping subproblems (solving the same problem multiple times with different parameters) and an optimal substructure (the solution to a problem can be constructed from the solutions to its subproblems).

2. State Representation (dp[i][w]):
    - dp[i][w] represents the maximum value that can be obtained using the first i items and a knapsack of capacity w. This helps us break the problem down into smaller subproblems.
    - We need to iterate over all items and capacities to fill out the DP table.

3. Base Case:
    - If there are no items to consider (i == 0) or if the capacity of the knapsack is zero (w == 0), then the maximum value is zero because no items can be included, or there is no capacity to include any items.

4. Recursive Transition:
    - For each item i and each capacity w, we have two choices:
        1. Exclude the item: The value will be the same as when considering the first i-1 items with the same capacity w. This is represented by dp[i-1][w].
        2. Include the item (if it fits): The value will be the value of the current item plus the value obtained from the remaining capacity, i.e., value[i-1] + dp[i-1][w - weight[i-1]].
    - The maximum of these two choices is stored in dp[i][w].

5. Time Complexity:
    - The time complexity is O(n * W), where n is the number of items and W is the capacity of the knapsack. This is because we are filling an (n+1) by (W+1) table, and for each entry, the computation involves a constant amount of work.

6. Space Complexity:
    - The space complexity is also O(n * W) due to the storage of the 2D DP table dp[n+1][W+1]. In the worst case, the table size is proportional to the product of the number of items and the knapsack capacity.

Key Concepts to Master:

1. Optimal Substructure: Understanding that the solution to the problem can be derived from the solutions to its subproblems.
2. Overlapping Subproblems: Recognizing that the same subproblems appear multiple times during the execution of the algorithm, and hence we can avoid redundant computations by storing the results.
3. Memoization: Though this is a bottom-up approach, the idea of memoization (storing results of recursive calls) is essential in dynamic programming. You can implement a top-down version of the DP algorithm using recursion and a cache to store previously computed results.

What You Need to Learn:

- Knapsack Problem: The 0/1 Knapsack problem is a standard example in dynamic programming. Understanding the recursive formulation and how it can be transformed into a DP solution is critical.
- 2D Array Operations: Learn how to work with 2D arrays, which are often used in DP problems to store results of subproblems.
- Dynamic Programming Patterns: There are several other classic DP problems such as Longest Common Subsequence, Fibonacci Sequence, and Coin Change Problem that follow similar principles. Practicing them will help you understand DP better.

By going through this annotated code, you can grasp how dynamic programming works and how the 0/1 Knapsack problem is solved using this technique. Let me know if you need further clarification!
*/

main.c