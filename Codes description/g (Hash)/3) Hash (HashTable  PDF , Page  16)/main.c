#include <stdio.h>

// Define the hash function
// This function computes a hash value for a given integer key 'k'.
// 'M' is the size of the hash table, and 'A' is a constant multiplier (float).
// The function returns the corresponding index in the hash table based on the key 'k'.

int hash(int k, int M, float A) {
    // The key 'k' is multiplied by the constant 'A' and then cast to an integer
    // to obtain the floor value of the product.
    // The result is then taken modulo 'M' to ensure the hash value is within
    // the range [0, M-1], which is the valid index range for a hash table of size M.
    return (((int)(k * A)) % M);
}

int main() {
    // Example usage of the hash function

    // Define parameters
    int key = 15;    // The key to be hashed (integer)
    int M = 10;      // The size of the hash table (number of buckets)
    float A = 0.6180339887; // Constant multiplier (commonly used value is the golden ratio)

    // Compute the hash value using the defined parameters
    int hashValue = hash(key, M, A);

    // Print the result
    printf("Hash value for key %d: %d\n", key, hashValue);

    return 0;
}

/*
    Explanation of the functions:

    1. hash(int k, int M, float A):
        - This function computes a hash value for the given integer key 'k' using a multiplication technique.
        - The key 'k' is multiplied by the constant 'A' (a float), and the result is cast to an integer.
        - The result is then taken modulo 'M' (the size of the hash table) to map the value into the range [0, M-1].
        - This technique is sometimes referred to as the "multiplicative hashing" method and uses a constant multiplier 'A' (often chosen to be related to the golden ratio) to spread the keys more uniformly across the hash table.

    2. main():
        - The main function demonstrates an example of how to use the hash function.
        - We define the key to be hashed (15), the size of the hash table (10), and the constant multiplier 'A' (0.6180339887, which is the golden ratio).
        - The hash value is computed by calling the hash function with the defined parameters.
        - The result is printed to show the index that corresponds to the key in the hash table.

    Conclusion:
        This hashing method, known as multiplicative hashing, is a simple yet effective way to map integer keys to hash table indices. By multiplying the key with a constant value 'A' and then applying modulo 'M', this method helps to distribute the keys more evenly across the hash table. The constant 'A' is often chosen to be related to the golden ratio, which is an irrational number approximately equal to 0.6180339887. This choice helps in reducing patterns and improving the distribution of hash values, which is useful for creating more uniform hash tables. However, while this approach works well in many scenarios, handling collisions and ensuring optimal performance in large-scale applications may require additional techniques.
*/
