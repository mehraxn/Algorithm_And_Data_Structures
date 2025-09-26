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

// Hash function to compute the index for a given key
int hash(int key) {
    return key % TABLE_SIZE;  // Simple hash function using modulo operation
}

// Function to insert a key-value pair into the hash table
void insert(int key, char *value) {
    int index = hash(key);  // Compute the hash index
    int originalIndex = index;  // Store the original index to detect full table

    // Linear probing for collision resolution
    while (hashTable[index] != NULL && hashTable[index]->key != -1) {
        // If the key already exists, we update the value
        if (hashTable[index]->key == key) {
            hashTable[index]->value = value;
            return;
        }

        // Move to the next index (linear probing)
        index = (index + 1) % TABLE_SIZE;

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
    int index = hash(key);  // Compute the hash index
    int originalIndex = index;

    // Linear probing to search for the key
    while (hashTable[index] != NULL) {
        // If the key matches, return the associated value
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }

        // Move to the next index (linear probing)
        index = (index + 1) % TABLE_SIZE;

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

// Main function to demonstrate the hash table with linear probing
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

    1. hash(int key):
        - This function computes the hash value (index) for the given key using the modulo operation.
        - The hash value is simply the key value modulo the size of the hash table (TABLE_SIZE).
        - This ensures that the hash value is within the bounds of the table.

    2. insert(int key, char *value):
        - This function inserts a key-value pair into the hash table.
        - First, it computes the hash index for the key using the hash function.
        - If the slot at that index is occupied (i.e., a collision occurs), it uses **linear probing** to search for the next available slot. The index is incremented by 1 (modulo TABLE_SIZE) to ensure it stays within bounds.
        - If the key already exists, the function updates the value.
        - If an empty slot is found, it inserts the key-value pair into the table.

    3. search(int key):
        - This function searches for a key in the hash table.
        - It computes the hash index for the key and then performs linear probing to search for the key.
        - If the key is found, it returns the associated value.
        - If the key is not found, it returns NULL, indicating the key is not in the table.

    4. display():
        - This function prints the contents of the hash table.
        - It iterates over each index and prints the key-value pair if the slot is occupied.
        - If the slot is empty, it prints "Empty."

    Conclusion:
        This program demonstrates how to implement **linear probing** for collision resolution in a hash table. The hash table stores key-value pairs, and when collisions occur (i.e., when multiple keys hash to the same index), linear probing checks the next available slot by incrementing the index until an empty slot is found.
        This approach helps to efficiently handle collisions in the hash table. However, as the table becomes more full, performance may degrade because of clustering, and more probing might be required to find an empty slot.
*/
