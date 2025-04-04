#include <stdio.h>

// Function to calculate the GCD of two numbers using the Euclidean algorithm
// This function returns the greatest common divisor of two integers `m` and `n`.
int gcd(int m, int n);

// Main function to demonstrate the GCD calculation
// This function takes user input for two numbers and calculates their GCD using the `gcd` function.
int main() {
    int m, n, r;
    // Prompt the user for input
    printf("Input m and n: ");
    scanf("%d%d", &m, &n);

    // Ensure the first argument is greater for the GCD calculation
    if (m > n)
        r = gcd(m, n);
    else
        r = gcd(n, m);

    // Print the result of the GCD calculation
    printf("gcd of (%d, %d) = %d\n", m, n, r);

    return 0;
}

// Recursive function to calculate the GCD
// Uses the Euclidean algorithm: GCD(m, n) = GCD(n, m % n) when n is not zero
// If `n` is zero, the function returns `m` as the GCD.
int gcd(int m, int n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

/*
Summary of the Functions:

1. gcd Function:
   - The `gcd` function calculates the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
   - It takes two integers (`m` and `n`) as input parameters.
   - If `n` is zero, it returns `m` as the GCD.
   - Otherwise, it recursively calls itself with `n` and `m % n` until `n` becomes zero, at which point `m` is the GCD.

2. main Function:
   - The `main` function is responsible for handling user interaction and demonstrating the usage of the `gcd` function.
   - It prompts the user to enter two integers (`m` and `n`) and calls the `gcd` function to calculate their GCD.
   - The result is printed to the console, providing a simple and clear demonstration of the GCD calculation.

The program demonstrates the use of recursion to solve the classic problem of finding the greatest common divisor. The Euclidean algorithm is an efficient method for computing the GCD, and using recursion makes the implementation elegant and easy to understand.
*/
