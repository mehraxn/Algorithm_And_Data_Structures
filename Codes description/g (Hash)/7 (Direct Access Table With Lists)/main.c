#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
typedef struct Node {
    int key;         // The key (used to locate the item)
    int value;       // The value associated with the key
    struct Node* next; // Pointer to the next node in the list
} Node;

// Function to create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new key-value pair into the Direct Access Table (linked list)
void insert(Node** head, int key, int value) {
    Node* newNode = createNode(key, value);
    newNode->next = *head;
    *head = newNode;
}

// Function to retrieve a value by key from the Direct Access Table
int retrieve(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;  // Return -1 if the key is not found
}

// Function to print all key-value pairs in the Direct Access Table
void printTable(Node* head) {
    Node* current = head;
    printf("Direct Access Table (Linked List):\n");
    while (current != NULL) {
        printf("Key %d: Value %d\n", current->key, current->value);
        current = current->next;
    }
}

// Function to free the memory allocated for the list
void freeTable(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* directAccessTable = NULL; // Initialize the Direct Access Table (empty list)

    // Insert some key-value pairs
    insert(&directAccessTable, 3, 100);  // Key 3 -> Value 100
    insert(&directAccessTable, 1, 200);  // Key 1 -> Value 200
    insert(&directAccessTable, 5, 300);  // Key 5 -> Value 300

    // Retrieve and print values by key
    printf("Value at key 3: %d\n", retrieve(directAccessTable, 3));  // Should print 100
    printf("Value at key 1: %d\n", retrieve(directAccessTable, 1));  // Should print 200
    printf("Value at key 5: %d\n", retrieve(directAccessTable, 5));  // Should print 300
    printf("Value at key 7: %d\n", retrieve(directAccessTable, 7));  // Should print -1 (not found)

    // Print the entire table
    printTable(directAccessTable);

    // Free allocated memory
    freeTable(directAccessTable);

    return 0;
}
