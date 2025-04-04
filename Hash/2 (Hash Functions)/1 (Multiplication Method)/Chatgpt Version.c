#include <stdio.h>
#include <math.h>

// Function to calculate the hash value using the multiplication method
unsigned int hash_function(float key, float s, float t, unsigned int M) {
    // Step 1: Normalize the key within the range [s, t]
    // (key - s) / (t - s) gives a value between 0 and 1
    float normalized_key = (key - s) / (t - s);

    // Step 2: Scale the normalized key by the hash table size (M)
    // This helps to distribute the keys across the hash table slots
    float scaled_key = normalized_key * M;

    // Step 3: Apply the floor function to get the final hash value
    // The floor function ensures that the result is an integer that can be used as an index
    unsigned int hash_value = (unsigned int)floor(scaled_key);

    // Return the computed hash value
    return hash_value;
}

int main() {
    // Example usage of the hash_function
    float key = 0.513871;  // Key to be hashed
    float s = 0.0;         // Lower bound of the key range
    float t = 1.0;         // Upper bound of the key range
    unsigned int M = 97;   // Size of the hash table

    // Calculate the hash value for the given key
    unsigned int hash_value = hash_function(key, s, t, M);

    // Print the hash value
    printf("Hash value for key %.6f is: %u\n", key, hash_value);

    return 0;
}
