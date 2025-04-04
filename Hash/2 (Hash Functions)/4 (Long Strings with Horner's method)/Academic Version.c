#include <stdio.h>

int hash(char *v, int M) {
    int h = 0;
    int base = 128;
    while (*v != '\0') {
        h = (h * base + *v) % M;
        v++;
    }
    return h;
}

int main() {
    char *long_string = "averylongkey";
    int mod = 1000000007;  // Example modulo value to prevent overflow

    int hash_result = hash(long_string, mod);
    printf("Hash value: %d\n", hash_result);

    return 0;
}
