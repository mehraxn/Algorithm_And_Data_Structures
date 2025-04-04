#include <stdio.h>

// Define the hash function
// This function computes a hash value for a given integer key 'k'.
// 'M' is the size of the hash table, and the function returns the corresponding
// index in the hash table based on the key 'k'.

int hash(int k, int M) {
    // The hash value is calculated by taking the modulus of 'k' with respect to 'M'.
    // This ensures that the result is an index within the range of [0, M-1].
    // The modulus operation helps to distribute the keys uniformly in the hash table.
    return k % M;
}

int main() {
    // Example usage of the hash function

    // Define parameters
    int key = 15;    // The key to be hashed
    int M = 10;      // The size of the hash table (number of buckets)

    // Compute the hash value
    int hashValue = hash(key, M);

    // Print the result
    printf("Hash value for key %d: %d\n", key, hashValue);

    return 0;
}

/*
    Explanation of the functions:

    1. hash(int k, int M):
        - This function computes a hash value of the given key 'k' and returns the index
          in a hash table of size 'M'.
        - The hash function is based on the modulus operation. It maps the key 'k' to
          an index in the range [0, M-1] by computing the remainder when 'k' is divided by 'M'.
        - The key 'k' can be any integer, and the modulus operation helps ensure that the
          resulting hash value is always within the bounds of the hash table size 'M'.

    2. main():
        - The main function demonstrates an example of how the hash function is used.
        - We define the key to be hashed (15) and the size of the hash table (10).
        - The hash value is computed by calling the hash function with the specified parameters,
          and the result is printed.

    Conclusion:
        The hash function here is very simple and works by using the modulus operation.
        It's a basic method for mapping an integer key to a hash table index.
        While simple, this method can be quite effective for certain key distributions,
        but for more complex scenarios (like handling collisions or achieving better distribution),
        more sophisticated hashing techniques may be needed.
*/
