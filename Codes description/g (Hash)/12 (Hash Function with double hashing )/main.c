#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Size of the hash table

// Define the hash table structure
typedef struct {
    int key;          // The key (integer)
    char *value;      // The value associated with the key (string)
} HashTableEntry;

// Define the hash table (array of entries)
HashTableEntry *hashTable[TABLE_SIZE];

// First hash function (Primary Hash)
int hash1(int key) {
    return key % TABLE_SIZE;  // Simple hash function using modulo operation
}

// Second hash function (Secondary Hash)
int hash2(int key) {
    return 7 - (key % 7);  // A prime number is typically used to avoid secondary clustering
}

// Function to insert a key-value pair into the hash table using double hashing
void insert(int key, char *value) {
    int index = hash1(key);  // Compute the hash index using the first hash function
    int originalIndex = index;  // Store the original index to detect full table
    int i = 1;  // Step size for double hashing (i starts from 1)

    // Double hashing for collision resolution
    while (hashTable[index] != NULL && hashTable[index]->key != -1) {
        // If the key already exists, we update the value
        if (hashTable[index]->key == key) {
            hashTable[index]->value = value;
            return;
        }

        // Double hashing: calculate the next index using both hash functions
        index = (originalIndex + i * hash2(key)) % TABLE_SIZE;
        i++;

        // If we have cycled through the entire table, we are in trouble (table full)
        if (index == originalIndex) {
            printf("Error: Hash table is full.\n");
            return;
        }
    }

    // If an empty slot is found, insert the key-value pair
    if (hashTable[index] == NULL) {
        hashTable[index] = (HashTableEntry*)malloc(sizeof(HashTableEntry));
    }
    hashTable[index]->key = key;  // Store the key
    hashTable[index]->value = value;  // Store the value
}

// Function to search for a key in the hash table
char* search(int key) {
    int index = hash1(key);  // Compute the hash index using the first hash function
    int originalIndex = index;
    int i = 1;  // Step size for double hashing (i starts from 1)

    // Double hashing to search for the key
    while (hashTable[index] != NULL) {
        // If the key matches, return the associated value
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }

        // Double hashing: calculate the next index using both hash functions
        index = (originalIndex + i * hash2(key)) % TABLE_SIZE;
        i++;

        // If we have cycled through the entire table, key is not found
        if (index == originalIndex) {
            break;
        }
    }

    // If key is not found, return NULL
    return NULL;
}

// Function to display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL && hashTable[i]->key != -1) {
            printf("Index %d: %d -> %s\n", i, hashTable[i]->key, hashTable[i]->value);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

// Main function to demonstrate the hash table with double hashing
int main() {
    // Initialize the hash table (set all entries to NULL initially)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert key-value pairs
    insert(12, "apple");
    insert(22, "banana");
    insert(32, "grape");
    insert(42, "orange");
    insert(52, "kiwi");
    insert(62, "melon");

    // Search for specific keys
    printf("Searching for key 22: %s\n", search(22));  // Should return "banana"
    printf("Searching for key 32: %s\n", search(32));  // Should return "grape"
    printf("Searching for key 99: %s\n", search(99));  // Should return NULL (not found)

    // Display the contents of the hash table
    printf("\nHash Table:\n");
    display();

    return 0;
}

/*
    Explanation of the Functions:

    1. hash1(int key):
        - This is the primary hash function. It computes the hash value by taking the modulo of the key with the table size.
        - This gives the initial index where the key should be stored.

    2. hash2(int key):
        - This is the secondary hash function. It helps resolve collisions in the hash table.
        - In this case, we use the formula `7 - (key % 7)` where 7 is a prime number.
        - The purpose of using a secondary hash function is to minimize the clustering effect that may occur with linear or quadratic probing.

    3. insert(int key, char *value):
        - This function inserts a key-value pair into the hash table.
        - First, it computes the index using the primary hash function `hash1(key)`.
        - If a collision occurs (i.e., the slot is already occupied), it uses **double hashing** to find the next available slot.
        - The next index is calculated as `index = (originalIndex + i * hash2(key)) % TABLE_SIZE`, where `i` starts from 1 and is incremented with each collision.
        - The loop continues until an empty slot is found or the table is full.

    4. search(int key):
        - This function searches for a specific key in the hash table.
        - It first computes the hash index using the primary hash function.
        - If a collision occurs, it uses **double hashing** to check the next indices in the table.
        - If the key is found, the function returns the associated value; otherwise, it returns `NULL`.

    5. display():
        - This function prints the contents of the hash table.
        - It iterates over each index and displays the key-value pair if the slot is occupied.
        - If the slot is empty, it prints "Empty."

    Conclusion:
        This program demonstrates how to implement **double hashing** to resolve collisions in a hash table. Double hashing uses two hash functions: one for the initial hash and another to compute the step size for subsequent probes. The second hash function helps reduce clustering by providing a better distribution of keys across the table.
        While double hashing reduces clustering compared to linear and quadratic probing, it still has potential drawbacks, such as secondary clustering (keys that collide will follow the same probing pattern). However, it is often a good choice for efficient collision resolution in hash tables.
*/
