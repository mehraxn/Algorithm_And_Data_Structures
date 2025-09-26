#include <stdio.h>

#define TABLE_SIZE 10  // The size of the table (supports keys from 0 to 9)

// Direct Access Table (Array)
int directAccessTable[TABLE_SIZE];

// Function to initialize the Direct Access Table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        directAccessTable[i] = -1;  // -1 indicates empty (or not initialized)
    }
}

// Function to insert a value into the table at a specific key
void insert(int key, int value) {
    if (key >= 0 && key < TABLE_SIZE) {
        directAccessTable[key] = value;
    } else {
        printf("Invalid key!\n");
    }
}

// Function to retrieve a value from the table based on the key
int retrieve(int key) {
    if (key >= 0 && key < TABLE_SIZE) {
        return directAccessTable[key];
    } else {
        printf("Invalid key!\n");
        return -1;  // Return -1 for invalid key
    }
}

// Function to print the current state of the table
void printTable() {
    printf("Direct Access Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Key %d: %d\n", i, directAccessTable[i]);
    }
}

int main() {
    // Initialize the table with default values
    initializeTable();

    // Insert some values into the table
    insert(0, 100);  // Key 0 -> Value 100
    insert(3, 200);  // Key 3 -> Value 200
    insert(7, 300);  // Key 7 -> Value 300

    // Retrieve and print values from the table
    printf("Value at key 0: %d\n", retrieve(0));  // Should print 100
    printf("Value at key 3: %d\n", retrieve(3));  // Should print 200
    printf("Value at key 7: %d\n", retrieve(7));  // Should print 300
    printf("Value at key 5: %d\n", retrieve(5));  // Should print -1 (not initialized)

    // Print the entire table
    printTable();

    return 0;
}
