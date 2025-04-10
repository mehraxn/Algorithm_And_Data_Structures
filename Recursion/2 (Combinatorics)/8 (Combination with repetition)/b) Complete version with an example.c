#include <stdio.h>

// Function to generate combinations with repetition
int comb_rep(int *val, int *sol, int n, int k, int start, int count, int pos) {
    int i;

    // Termination condition: if we have filled all positions in the solution array
    if (pos >= k) {
        // Print the current combination
        for (i = 0; i < k; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return count + 1;  // Increment the count of combinations and return
    }

    // Iterate over possible values from 'start' onwards
    for (i = start; i < n; i++) {
        sol[pos] = val[i];  // Fill sol[pos] with the value val[i]
        // Recur to fill the next position
        count = comb_rep(val, sol, n, k, i, count, pos + 1);
    }

    return count;  // Return the total count of combinations
}

int main() {
    int val[] = {1, 2, 3};  // Array of values to choose from
    int n = 3;  // Number of elements in 'val'
    int k = 2;  // Length of each combination
    int sol[k];  // Array to store the current combination

    // Generate and print all combinations with repetition
    int total_combinations = comb_rep(val, sol, n, k, 0, 0, 0);
    printf("Total combinations: %d\n", total_combinations);

    return 0;
}

/*
Explanation of the Code:

1. **Headers and Main Function**:
   - The code starts by including the `stdio.h` header to use input-output functions like `printf()`.
   - The `main()` function initializes an array `val` with values `{1, 2, 3}`. It also sets `n` to the number of elements in `val` (3) and `k` to the length of combinations we want to generate (2).
   - `sol[k]` is used to store the current combination.
   - The `comb_rep()` function is called to generate and print all combinations.

2. **comb_rep Function**:
   - The function `comb_rep()` generates combinations with repetition using recursion.
   - **Parameters**:
     - `val[]`: The array of available values.
     - `sol[]`: The array to store the current combination.
     - `n`: Number of elements in `val`.
     - `k`: Length of each combination.
     - `start`: Index from where to start choosing values for the combination.
     - `count`: Tracks the number of combinations generated.
     - `pos`: The current position in the `sol[]` array that needs to be filled.
   - **Base Case**: If `pos` reaches `k`, all positions in `sol[]` are filled, and the combination is printed.
   - **Loop and Recursion**:
     - The loop starts from the `start` index to ensure combinations with repetition.
     - The recursive call fills the next position (`pos + 1`) while maintaining the current value as the minimum choice for future positions.

3. **Output**:
   - The combinations generated are printed to the console, and finally, the total number of combinations is displayed.

The code effectively demonstrates generating combinations with repetition using a recursive approach. The idea is to keep track of the current position and ensure that subsequent values can repeat or come after the current value, allowing for combinations like `{1, 1}`, `{1, 2}`, etc. The `start` parameter plays a crucial role in managing repetition and avoiding permutations.
*/
