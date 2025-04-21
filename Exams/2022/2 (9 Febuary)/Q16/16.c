#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Function Prototypes
void calculate_balance_difference(float *flow, int n, float *max_diff, float *best_order);
void permute(float *flow, int start, int n, float *max_diff, float *current_order, float *best_order);
void compute_max_min_difference(float *flow, int n, float *max, float *min);
void swap(float *a, float *b); // Utility function to swap two elements

// Helper function to swap two elements in an array
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compute the maximum and minimum balances for a given cash flow order
void compute_max_min_difference(float *flow, int n, float *max, float *min) {
    float current_balance = 0; // Initialize the current balance as 0
    *max = -FLT_MAX;           // Set max to a very small value initially
    *min = FLT_MAX;            // Set min to a very large value initially

    // Calculate the balance at each step and track max and min balances
    for (int i = 0; i < n; i++) {
        current_balance += flow[i]; // Update the balance
        if (current_balance > *max) *max = current_balance; // Update max balance
        if (current_balance < *min) *min = current_balance; // Update min balance
    }
}

// Recursive function to generate all permutations and evaluate the balance difference
void permute(float *flow, int start, int n, float *max_diff, float *current_order, float *best_order) {
    if (start == n) {
        // Base case: A full permutation is generated
        float max, min; // Variables to store max and min balances
        compute_max_min_difference(current_order, n, &max, &min);
        float diff = max - min; // Calculate the difference between max and min balances

        // Update the best order if the current difference is smaller
        if (diff < *max_diff) {
            *max_diff = diff;
            for (int i = 0; i < n; i++) {
                best_order[i] = current_order[i]; // Copy the current permutation to best_order
            }
        }
        return; // Return to explore the next permutation
    }

    // Recursive case: Generate permutations by swapping elements
    for (int i = start; i < n; i++) {
        swap(&current_order[start], &current_order[i]);       // Fix one element by swapping
        permute(flow, start + 1, n, max_diff, current_order, best_order); // Recur for the rest
        swap(&current_order[start], &current_order[i]);       // Backtrack to restore original order
    }
}

// Main function to find the optimal order of cash flows that minimizes the max-min difference
int *balance(float *flow, int n) {
    float max_diff = FLT_MAX; // Initialize the minimum difference as a very large value
    float *current_order = (float *)malloc(n * sizeof(float)); // Temporary array for permutations
    float *best_order = (float *)malloc(n * sizeof(float));    // Array to store the best order

    // Initialize current_order with the original cash flows
    for (int i = 0; i < n; i++) {
        current_order[i] = flow[i];
    }

    // Generate all permutations and find the best one
    permute(flow, 0, n, &max_diff, current_order, best_order);

    // Convert best_order to an array of indices representing their positions in the original array
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flow[j] == best_order[i]) {
                result[i] = j; // Store the index of the value in the original array
                flow[j] = FLT_MAX; // Mark it to avoid duplicate matches
                break;
            }
        }
    }

    // Free temporary arrays
    free(current_order);
    free(best_order);

    return result; // Return the indices representing the optimal order
}

// Test function to demonstrate the solution
int main() {
    float cash_flows[] = {10, -5, 7, -8}; // Example input
    int n = sizeof(cash_flows) / sizeof(cash_flows[0]); // Calculate the size of the array

    int *result = balance(cash_flows, n); // Call the main function

    // Print the indices of the optimal order
    printf("Optimal order of indices:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the result array
    free(result);
    return 0;
}

/*
Comprehensive Explanation of Functions:

// swap Function
// A utility function to swap two elements in an array.
// It is used during the recursive generation of permutations to rearrange elements.

// compute_max_min_difference Function
// Purpose: Calculates the maximum and minimum balances for a given order of cash flows.
// Logic:
// Start with an initial balance of 0.
// For each cash flow, update the running balance.
// Track the largest and smallest balance encountered.

// permute Function
// Purpose: Recursively generates all permutations of the cash flow array.
// Logic:
// Swap the current element with each subsequent element to fix one position.
// Recur for the remaining elements.
// Backtrack (restore the original array) to explore other possibilities.
// At each valid permutation (base case), it computes the max-min difference using compute_max_min_difference
// and updates the best order if the current difference is smaller.

// balance Function
// Purpose: Main function that:
// Initializes the recursive permutation process.
// Finds the permutation of cash flows that minimizes the difference between maximum and minimum balances.
// Converts the optimal order into an array of indices representing positions in the original cash flow array.
// Logic:
// Initialize working arrays (current_order and best_order).
// Call permute to explore all permutations and identify the optimal order.
// Convert the best cash flow order back to indices of the original array.

// main Function
// Provides a sample input of cash flows.
// Calls the balance function to find the optimal order.
// Prints the indices of the optimal order.

// Summary
// Recursive Permutation: The program generates all possible orders of cash flows.
// Balance Calculation: For each permutation, it calculates the balances and tracks the max-min difference.
// Optimization: The optimal order is selected as the one with the smallest difference between maximum and minimum balances.
// Output: The program returns the indices of the cash flows in the optimal order.
*/
