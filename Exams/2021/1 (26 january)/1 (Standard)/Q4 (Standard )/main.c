#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 1000
#define MAX_LINE_LENGTH 256

// Struct to store each access record
typedef struct AccessRecord {
    char timestamp[20];
    char requestType[5];
    char resource[50];
    int statusCode;
    struct AccessRecord *next;
} AccessRecord;

// Struct for hash table entries
typedef struct HashTableEntry {
    char key[50]; // IP address or username
    AccessRecord *records; // Linked list of access records
    struct HashTableEntry *next;
} HashTableEntry;

// Hash table
HashTableEntry *hashTable[HASH_TABLE_SIZE];

// Hash function
unsigned int hash(const char *key) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = (hashValue * 31 + *key) % HASH_TABLE_SIZE;
        key++;
    }
    return hashValue;
}

// Insert record into the hash table
void insertRecord(const char *key, const char *timestamp, const char *requestType, const char *resource, int statusCode) {
    unsigned int index = hash(key);
    HashTableEntry *entry = hashTable[index];

    // Search for the key in the hash table
    while (entry != NULL && strcmp(entry->key, key) != 0) {
        entry = entry->next;
    }

    // If key not found, create a new entry
    if (entry == NULL) {
        entry = (HashTableEntry *)malloc(sizeof(HashTableEntry));
        strcpy(entry->key, key);
        entry->records = NULL;
        entry->next = hashTable[index];
        hashTable[index] = entry;
    }

    // Create a new access record
    AccessRecord *newRecord = (AccessRecord *)malloc(sizeof(AccessRecord));
    strcpy(newRecord->timestamp, timestamp);
    strcpy(newRecord->requestType, requestType);
    strcpy(newRecord->resource, resource);
    newRecord->statusCode = statusCode;
    newRecord->next = entry->records;
    entry->records = newRecord;
}

// Read data from file and populate the hash table
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char ip[50], username[50], timestamp[20], requestType[5], resource[50];
        int statusCode;
        sscanf(line, "%s %s [%[^]]] %s %s %d", ip, username, timestamp, requestType, resource, &statusCode);

        // Insert by IP
        insertRecord(ip, timestamp, requestType, resource, statusCode);

        // Insert by username
        insertRecord(username, timestamp, requestType, resource, statusCode);
    }

    fclose(file);
}

// Search for records by key (IP or username)
void searchRecords(const char *key) {
    unsigned int index = hash(key);
    HashTableEntry *entry = hashTable[index];

    // Find the entry
    while (entry != NULL && strcmp(entry->key, key) != 0) {
        entry = entry->next;
    }

    if (entry == NULL) {
        printf("No records found for key: %s\n", key);
        return;
    }

    // Print records
    printf("Records for key: %s\n", key);
    AccessRecord *record = entry->records;
    while (record != NULL) {
        printf("[%s] %s %s %d\n", record->timestamp, record->requestType, record->resource, record->statusCode);
        record = record->next;
    }
}

int main() {
    // Initialize hash table
    memset(hashTable, 0, sizeof(hashTable));

    // Read data from file
    readFile("web_access_log.txt");

    // Example searches
    searchRecords("34.52.1.33"); // Search by IP
    searchRecords("badguy");     // Search by username

    return 0;
}
