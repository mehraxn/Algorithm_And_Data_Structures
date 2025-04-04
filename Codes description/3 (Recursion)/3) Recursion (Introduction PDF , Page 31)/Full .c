#include <stdio.h>

// Version One
// This function calculates the factorial of a number using recursion.
// It returns 1 if n is 0 (base case), otherwise it returns n multiplied by the factorial of (n - 1).
long int fact_v1(long int n) {
    if (n == 0)
        return 1;
    return n * fact_v1(n - 1);
}

// Version Two
// This function also calculates the factorial of a number using recursion.
// It uses a separate variable to store the recursive result before multiplying by n.
long int fact_v2(long int n) {
    long int f;
    if (n == 0)
        return 1;
    f = fact_v2(n - 1);
    return n * f;
}

// Main function to demonstrate both versions of the factorial function
int main() {
    long int n;
    printf("Input n: ");
    scanf("%ld", &n);

    // Calculate factorial using version one
    long int result_v1 = fact_v1(n);
    printf("Version 1: %ld! = %ld\n", n, result_v1);

    // Calculate factorial using version two
    long int result_v2 = fact_v2(n);
    printf("Version 2: %ld! = %ld\n", n, result_v2);

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

1. fact_v1 Function:
   - The `fact_v1` function calculates the factorial of a number using a simple recursive approach.
   - It directly returns `n * fact_v1(n - 1)` for all `n > 0` and returns `1` when `n` is `0`.
   - This version is straightforward and easy to understand.

2. fact_v2 Function:
   - The `fact_v2` function also calculates the factorial of a number recursively but uses an intermediate variable (`f`) to store the result of `fact_v2(n - 1)` before multiplying it by `n`.
   - This approach provides the same result as `fact_v1`, but with an extra step of storing the intermediate result.

3. main Function:
   - The `main` function takes an input number `n` from the user and calculates its factorial using both `fact_v1` and `fact_v2`.
   - It then prints the results from both versions and verifies that they are the same.
   - This demonstrates that both implementations produce identical results, despite minor differences in their structure.
*/
