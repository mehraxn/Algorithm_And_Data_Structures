#include <stdio.h>

// Define the hash function
// This function computes a hash value for a given string 'v'.
// 'M' is the size of the hash table (number of slots/buckets).
// The function returns the corresponding index in the hash table based on the string 'v'.

int hash(char *v, int M) {
    int h = 0;      // Initialize the hash value to 0
    int base = 128; // Base value for the hash function. 128 corresponds to the number of ASCII characters.

    // Iterate through each character of the string 'v'
    while (*v != '\0') {
        // Update the hash value: multiply the current hash by the base and add the ASCII value of the character.
        // Take modulo M to ensure the hash value fits within the range of the hash table.
        h = (h * base + *v) % M;

        // Move to the next character in the string
        v++;
    }

    // Return the computed hash value
    return h;
}

int main() {
    // Example usage of the hash function

    // Define the parameters
    char *key = "example";  // The string to be hashed
    int M = 10;             // The size of the hash table (number of buckets)

    // Compute the hash value using the defined parameters
    int hashValue = hash(key, M);

    // Print the result
    printf("Hash value for string \"%s\": %d\n", key, hashValue);

    return 0;
}

/*
    Explanation of the functions:

    1. hash(char *v, int M):
        - This function computes a hash value for the given string 'v'.
        - The hash value is computed using a rolling hash technique. The string is processed character by character.
        - Each character's ASCII value is used to update the hash value. The hash value is updated by multiplying the previous value by the base (128) and then adding the ASCII value of the current character.
        - To ensure the hash value fits within the bounds of the hash table, the result is taken modulo 'M', which gives the final hash value (an index in the range [0, M-1]).
        - The base value of 128 is chosen because there are 128 ASCII characters. This helps in spreading out the values uniformly.

    2. main():
        - The main function demonstrates an example of how to use the hash function.
        - We define a string (`"example"`) and a hash table size `M = 10`.
        - The hash function is called with these parameters to compute the corresponding hash value.
        - The result is printed to show the index that corresponds to the string in the hash table.

    Conclusion:
        The `hash()` function uses a simple rolling hash technique to map strings to hash table indices. By processing each character in the string and updating the hash value using a combination of multiplication by a base (128, corresponding to the number of ASCII characters) and addition of the character's ASCII value, the function generates a hash value. The modulo operation ensures that the resulting hash value fits within the range of the hash table size `M`.

        This hashing method is simple but effective for many situations where strings need to be mapped to a fixed number of buckets (such as in hash tables). The choice of base (128) helps to spread the hash values more evenly across the hash table. However, in practice, for more complex hashing needs or larger datasets, additional techniques such as handling collisions (e.g., separate chaining, open addressing) might be necessary for optimal performance in a hash table.
*/
