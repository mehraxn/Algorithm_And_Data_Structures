#include <stdio.h>

// Function to calculate the GCD of two numbers using recursion
int gcd(int x, int y);

// Main function to demonstrate the GCD calculation
int main() {
    int x, y;
    printf("Input x and y: ");
    scanf("%d%d", &x, &y);
    printf("gcd of %d and %d: %d\n", x, y, gcd(x, y));
    return 0;
}

// Recursive function to calculate the GCD
int gcd(int x, int y) {
    if (x == y)
        return x;
    if (x > y)
        return gcd(x - y, y);
    else
        return gcd(x, y - x);
}
