#include <stdio.h>

int hash(float k, int M, float s, float t) {
    if (s == t) {
        // Avoid division by zero
        return 0;
    }

    // Normalization: Ensure the result is between 0 and M-1
    float normalized = (k - s) / (t - s);
    int hashValue = (int)(normalized * M);

    // Ensure the hash value is within bounds
    if (hashValue < 0) {
        hashValue = 0;
    } else if (hashValue >= M) {
        hashValue = M - 1;
    }

    return hashValue;
}

int main() {
    float k = 5.0, s = 0.0, t = 10.0;
    int M = 100;

    int result = hash(k, M, s, t);
    printf("Hash value: %d\n", result);

    return 0;
}
