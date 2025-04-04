#include <stdio.h>       // Standard I/O library for input and output functions
#include <stdlib.h>      // Standard library for dynamic memory allocation and other utilities
#include <string.h>      // String manipulation functions like strcmp and strdup

#define TABLE_SIZE 10    // Define the size of the hash table to be 10

// Define the structure for a hash table entry
typedef struct entry {
    char *key;              // Key of the entry (string)
    int value;              // Value of the entry (integer)
    struct entry *next;     // Pointer to handle collisions using linked list chaining
} entry_t;

// Create the hash table as an array of entry pointers, initially NULL
entry_t *hash_table[TABLE_SIZE];

// Hash function to compute an index for a given key
unsigned int hash(const char *key) {
    unsigned int hash_value = 0;  // Initialize hash value to 0
    // Loop through each character of the key to calculate the hash value
    for (int i = 0; key[i] != '\0'; i++) {
        hash_value = (hash_value + key[i]) % TABLE_SIZE;  // Sum ASCII values and apply modulo TABLE_SIZE
    }
    return hash_value;  // Return the computed hash index
}

// Function to create a new entry
entry_t *create_entry(const char *key, int value) {
    // Allocate memory for the new entry
    entry_t *new_entry = (entry_t *)malloc(sizeof(entry_t));
    if (new_entry == NULL) {  // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed\n");  // Print error message
        exit(1);  // Exit program with an error code
    }
    // Allocate memory for the key string and copy the key value
    new_entry->key = strdup(key);  // strdup allocates memory and copies the key string
    new_entry->value = value;  // Set the value of the entry
    new_entry->next = NULL;  // Initialize the next pointer to NULL
    return new_entry;  // Return the newly created entry
}

// Function to insert a key-value pair into the hash table
void insert(const char *key, int value) {
    unsigned int index = hash(key);  // Compute the hash index for the given key
    entry_t *new_entry = create_entry(key, value);  // Create a new entry with the key and value

    // Handle collisions using linked list chaining
    if (hash_table[index] == NULL) {  // If the index is empty (no collision)
        hash_table[index] = new_entry;  // Insert the new entry directly
    } else {  // If there is already an entry at the index (collision)
        entry_t *current = hash_table[index];  // Start at the first entry in the linked list
        while (current->next != NULL) {  // Traverse to the end of the linked list
            current = current->next;
        }
        current->next = new_entry;  // Append the new entry at the end of the linked list
    }
}

// Function to search for a value by its key
int search(const char *key) {
    unsigned int index = hash(key);  // Compute the hash index for the given key
    entry_t *current = hash_table[index];  // Get the entry at the computed index

    // Traverse the linked list to find the key
    while (current != NULL) {  // While there are still entries to check
        if (strcmp(current->key, key) == 0) {  // Compare the current key with the search key
            return current->value;  // If found, return the associated value
        }
        current = current->next;  // Move to the next entry in the list
    }
    // If the key is not found, return -1
    return -1;
}

// Function to print the hash table
void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {  // Loop through each index in the hash table
        printf("Index %d: ", i);  // Print the current index
        entry_t *current = hash_table[i];  // Get the entry at the current index
        while (current != NULL) {  // Traverse the linked list at this index
            printf("(%s, %d) -> ", current->key, current->value);  // Print the key-value pair
            current = current->next;  // Move to the next entry in the list
        }
        printf("NULL\n");  // Indicate the end of the linked list
    }
}

// Main function to demonstrate the hash table operations
int main() {
    // Initialize hash table to NULL
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;  // Set each index of the hash table to NULL
    }

    // Insert some key-value pairs into the hash table
    insert("Apple", 100);     // Insert key "Apple" with value 100
    insert("Banana", 150);    // Insert key "Banana" with value 150
    insert("Orange", 200);    // Insert key "Orange" with value 200
    insert("Grape", 300);     // Insert key "Grape" with value 300
    insert("Cherry", 250);    // Insert key "Cherry" with value 250

    // Print the hash table
    printf("Hash Table:\n");
    print_table();  // Print the hash table to show the current state

    // Search for a key in the hash table
    char *key_to_search = "Banana";  // Key to search for
    int value = search(key_to_search);  // Search for the key
    if (value != -1) {  // If the key was found
        printf("Value associated with key '%s': %d\n", key_to_search, value);  // Print the value
    } else {  // If the key was not found
        printf("Key '%s' not found in the hash table.\n", key_to_search);  // Print not found message
    }

    return 0;  // Exit the program
}
