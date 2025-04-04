// First Version
#include <stdio.h>
long int fib(long int n);

int main() {
    long int n;
    printf("Input n: ");
    scanf("%ld", &n);
    printf("Fibonacci of %ld is: %ld\n", n, fib(n));
    return 0;
}

long int fib(long int n) {
    if (n == 0 || n == 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}

// Second Version
long int fib(long int n) {
    if (n == 0 || n == 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}
