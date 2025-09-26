#include <stdio.h>

// Define the hash function
// This function computes a hash value for a given float key 'k'.
// 'M' is the size of the hash table, 's' is the minimum value of the key range,
// and 't' is the maximum value of the key range. The function returns the
// corresponding index in the hash table.

int hash(float k, int M, float s, float t) {
    // Normalize the key 'k' between the range [0, 1] by using the formula
    // (k - s) / (t - s), where s is the minimum key value and t is the maximum.
    // Then multiply by M to map it to a range from 0 to M-1 (the size of the hash table).
    // Finally, cast the result to an integer to get the index.
    return (int)(((k - s) / (t - s)) * M);
}

int main() {
    // Example usage of the hash function

    // Define parameters
    float key = 7.5;    // The key to be hashed
    int M = 10;         // The size of the hash table (number of buckets)
    float s = 0.0;      // Minimum value in the key range
    float t = 10.0;     // Maximum value in the key range

    // Compute the hash value
    int hashValue = hash(key, M, s, t);

    // Print the result
    printf("Hash value for key %.2f: %d\n", key, hashValue);

    return 0;
}

/*
    Explanation of the functions:

    1. hash(float k, int M, float s, float t):
        - This function computes the hash value of a given key 'k' and returns the corresponding index
          in a hash table of size 'M'.
        - The input 'k' is a float key that is being mapped into a range between 0 and M-1.
        - The parameters 's' and 't' define the range [s, t] over which the keys are distributed.
          The key 'k' is first normalized to a value between 0 and 1 by using the formula:
          (k - s) / (t - s).
        - The normalized value is then scaled by 'M' (the size of the hash table) to map it to an index
          in the range [0, M-1].
        - The result is cast to an integer to ensure the final index is an integer suitable for use
          in an array or hash table.

    2. main():
        - The main function demonstrates an example of how the hash function is used.
        - We define the key to be hashed (7.5), the size of the hash table (10), and the range of keys
          [0.0, 10.0].
        - The hash value is computed by calling the hash function with the specified parameters, and the
          result is printed.

    Conclusion:
        This is a basic hash function implementation, often used in hash table or hashing techniques.
        It maps a given float key to a hash table index by normalizing the key and then scaling it to fit
        within the size of the table. While this approach works well for certain key distributions, more
        advanced hash functions might be required for different types of data or use cases (e.g., collision
        handling, better distribution of hash values).
*/
