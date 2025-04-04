#include <stdio.h>

// Function to calculate the GCD of two numbers using the Euclidean algorithm
int gcd(int m, int n);

// Main function to demonstrate the GCD calculation
int main() {
    int m, n, r;
    printf("Input m and n: ");
    scanf("%d%d", &m, &n);
    // Ensure the first argument is greater for the GCD calculation
    if (m > n)
        r = gcd(m, n);
    else
        r = gcd(n, m);
    printf("gcd of (%d, %d) = %d\n", m, n, r);
    return 0;
}

// Recursive function to calculate the GCD
// Uses the Euclidean algorithm: GCD(m, n) = GCD(n, m % n) when n is not zero
int gcd(int m, int n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}
