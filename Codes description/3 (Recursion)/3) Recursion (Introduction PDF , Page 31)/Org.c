// Version One
long int fact(long int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

void main() {
    long int n;
    printf("Input n: ");
    scanf("%ld", &n);
    printf("%ld! = %ld\n", n, fact(n));
}

// Version Two
long int fact(long int n) {
    long int f;
    if (n == 0)
        return 1;
    f = fact(n - 1);
    return n * f;
}
