#include <stdio.h>

// Function to compute the hash using the modulo method
int hash(int k, int M) {
    return k % M;
}

int main() {
    int M = 19; // Size of the hash table
    int keys[] = {11, 31, 29};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        int hashValue = hash(keys[i], M);
        printf("Hash value of key %d: %d\n", keys[i], hashValue);
    }

    return 0;
}
