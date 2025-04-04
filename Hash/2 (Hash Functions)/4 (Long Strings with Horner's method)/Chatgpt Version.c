#include <stdio.h>
#include <string.h>

unsigned long hash(const char *str, int base, unsigned long mod) {
    unsigned long hash_value = 0;
    int n = strlen(str);

    // Apply Horner's method
    for (int i = 0; i < n; i++) {
        hash_value = (hash_value * base + str[i]) % mod;
    }

    return hash_value;
}

int main() {
    const char *long_string = "averylongkey";
    int base = 128;  // The base used in ASCII encoding as per your example
    unsigned long mod = 1000000007;  // Example modulo value to prevent overflow

    unsigned long hash_result = hash(long_string, base, mod);
    printf("Hash value: %lu\n", hash_result);

    return 0;
}
