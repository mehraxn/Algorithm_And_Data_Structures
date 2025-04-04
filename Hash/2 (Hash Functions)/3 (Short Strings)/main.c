#include <stdio.h>
#include <string.h>

int polynomialHash(char *key, int base) {
    int hashValue = 0;
    int length = strlen(key);

    // Calculate the polynomial hash value
    for (int i = 0; i < length; i++) {
        hashValue = hashValue * base + key[i];
    }

    return hashValue;
}

int hash(char *key, int M, int base) {
    // Get the polynomial hash value
    int hashValue = polynomialHash(key, base);

    // Apply the modulo method to get the final hash value
    return hashValue % M;
}

int main() {
    char key[] = "1234";
    int base = 256;  // Use base 256 for better differentiation of characters
    int M = 19;      // Size of the hash table

    int hashValue = hash(key, M, base);
    printf("Hash value of key '%s': %d\n", key, hashValue);

    return 0;
}
