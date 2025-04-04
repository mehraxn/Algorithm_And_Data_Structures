#include <stdio.h>

// Function to calculate the GCD of two numbers using recursion
// The function returns the greatest common divisor of two integers `x` and `y`.
int gcd(int x, int y);

// Main function to demonstrate the GCD calculation
// This function takes user input for two numbers and calculates their GCD using the `gcd` function.
int main() {
    int x, y;
    // Prompt the user for input
    printf("Input x and y: ");
    scanf("%d%d", &x, &y);
    // Calculate and print the GCD of x and y
    printf("gcd of %d and %d: %d\n", x, y, gcd(x, y));
    return 0;
}

// Recursive function to calculate the GCD
// This function uses the Euclidean algorithm to find the greatest common divisor of two integers.
// If the two numbers are equal, it returns the value directly as the GCD.
// Otherwise, it recursively reduces the larger number until the GCD is found.
int gcd(int x, int y) {
    if (x == y)
        return x;
    if (x > y)
        return gcd(x - y, y);
    else
        return gcd(x, y - x);
}

/*
Summary of the Functions:

1. gcd Function:
   - The `gcd` function calculates the greatest common divisor (GCD) of two integers using recursion.
   - It follows the principles of the Euclidean algorithm: if `x` and `y` are equal, that value is the GCD.
   - If `x` is greater than `y`, it calls itself with the arguments `x - y` and `y`. If `y` is greater than `x`, it calls itself with `x` and `y - x`.
   - This recursive reduction continues until the two numbers are equal, which is then returned as the GCD.

2. main Function:
   - The `main` function is responsible for handling user interaction and demonstrating the usage of the `gcd` function.
   - It prompts the user to enter two integers (`x` and `y`) and calls the `gcd` function to calculate their GCD.
   - The result is printed to the console, providing a simple and clear demonstration of the GCD calculation.

The program demonstrates the use of recursion to solve a classic mathematical problem: finding the GCD of two numbers. The Euclidean algorithm is an efficient method for computing the GCD, and using recursion makes the implementation concise and easy to understand.
*/
