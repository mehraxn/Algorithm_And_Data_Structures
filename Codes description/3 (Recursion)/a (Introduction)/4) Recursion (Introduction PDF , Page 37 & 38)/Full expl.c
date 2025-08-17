#include <stdio.h>

// First Version
// This function calculates the nth Fibonacci number using recursion.
// It returns n if n is 0 or 1 (base cases), otherwise it returns the sum of the previous two Fibonacci numbers.
long int fib_v1(long int n) {
    if (n == 0 || n == 1)
        return n;
    return fib_v1(n - 2) + fib_v1(n - 1);
}

// Second Version
// This function also calculates the nth Fibonacci number using recursion.
// It uses the same approach as the first version, calculating the sum of the two preceding numbers.
long int fib_v2(long int n) {
    if (n == 0 || n == 1)
        return n;
    return fib_v2(n - 2) + fib_v2(n - 1);
}

// Main function to demonstrate both versions of the Fibonacci function
int main() {
    long int n;
    printf("Input n: ");
    scanf("%ld", &n);

    // Calculate Fibonacci using version one
    long int result_v1 = fib_v1(n);
    printf("Version 1: Fibonacci of %ld is: %ld\n", n, result_v1);

    // Calculate Fibonacci using version two
    long int result_v2 = fib_v2(n);
    printf("Version 2: Fibonacci of %ld is: %ld\n", n, result_v2);

    // Show that both versions produce the same result
    if (result_v1 == result_v2) {
        printf("Both versions produce the same result: %ld\n", result_v1);
    } else {
        printf("The results are different, which indicates an error.\n");
    }

    return 0;
}

/*
Summary of the Functions:

1. fib_v1 Function:
   - The `fib_v1` function calculates the nth Fibonacci number using a simple recursive approach.
   - It directly returns `n` if `n` is `0` or `1`, which are the base cases of the Fibonacci sequence.
   - For any other value of `n`, it returns the sum of `fib_v1(n - 2)` and `fib_v1(n - 1)`, effectively reducing the problem size until it reaches the base cases.

2. fib_v2 Function:
   - The `fib_v2` function calculates the nth Fibonacci number using the same recursive approach as `fib_v1`.
   - It follows the exact same logic as `fib_v1` but is presented as a separate implementation for demonstration purposes.

3. main Function:
   - The `main` function takes an input number `n` from the user and calculates its Fibonacci value using both `fib_v1` and `fib_v2`.
   - It then prints the results from both versions and verifies that they are the same.
   - This demonstrates that both implementations produce identical results, despite being written separately.
*/
