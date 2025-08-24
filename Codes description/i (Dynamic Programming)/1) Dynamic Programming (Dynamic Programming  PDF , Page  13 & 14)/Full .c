#include <stdio.h>
#include <stdlib.h>

// Function prototype declaration for the Fibonacci dynamic programming function
int fib_dp(int n, int *known);

int main(void) {
    int *known, i, n;

    // Prompt the user to input the value for n (the position of the Fibonacci number)
    fprintf(stdout, "Input n: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array to store Fibonacci numbers up to nth term
    known = (int *)malloc((n + 1) * sizeof(int));

    // Check if memory allocation is successful
    if (known == NULL) {
        // If memory allocation fails, print an error message and exit the program
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the known array with -1 (indicating that Fibonacci values are not yet computed)
    for (i = 0; i <= n; i++) {
        known[i] = -1;
    }

    // Call the Fibonacci dynamic programming function and print the result
    fprintf(stdout, "Fibonacci %d-th term = %d\n", n, fib_dp(n, known));

    // Free the dynamically allocated memory for the known array
    free(known);

    // Return success
    return EXIT_SUCCESS;
}

// Function to calculate Fibonacci number using dynamic programming (memoization)
int fib_dp(int n, int *known) {
    // If the Fibonacci number is not yet computed (i.e., value is -1)
    if (known[n] < 0) {
        // Base case: Fibonacci of 0 or 1 is just 0 or 1 respectively
        if (n == 0 || n == 1) {
            known[n] = n;  // Store the value in the known array
        } else {
            // Recursive case: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
            known[n] = fib_dp(n - 1, known) + fib_dp(n - 2, known);
        }
    }
    // Return the computed Fibonacci value for the nth term
    return known[n];
}

/*
Explanation of the Functions:

1. **`main()` function:**
   - This function is responsible for handling user input, allocating memory, and displaying the result.
   - First, it prompts the user to input the value of n (the term in the Fibonacci sequence).
   - It dynamically allocates memory for an array (`known`) that will store the Fibonacci numbers computed up to the nth term.
   - The array is initialized with `-1` to indicate that no Fibonacci values have been computed yet.
   - Then it calls the `fib_dp()` function to compute the nth Fibonacci number using dynamic programming.
   - Finally, the allocated memory is freed, and the program terminates successfully.

2. **`fib_dp()` function:**
   - This function calculates the nth Fibonacci number using dynamic programming (specifically memoization).
   - The function uses a `known` array to store previously computed Fibonacci numbers, which avoids redundant calculations.
   - If the Fibonacci number for a given `n` has already been computed (i.e., it's not `-1`), it directly returns the value.
   - If not, the function computes the value recursively by calling `fib_dp()` for `n-1` and `n-2`, stores the result in the `known` array, and returns the computed value.
   - This approach significantly reduces the number of recursive calls and improves performance, especially for larger values of `n`.
*/
