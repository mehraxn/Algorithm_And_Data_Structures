#include <stdio.h>

#define MAX_ITEMS 10  // Maximum number of items in the warehouse

// Direct Address Table structure to represent item availability
int directAccessTable[MAX_ITEMS];

// Function to initialize the table, setting all items as not available
void initializeTable() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        directAccessTable[i] = 0;  // 0 means the item is not in stock
    }
}

// Function to add an item to the stock (set availability to 1)
void addItemToStock(int itemID) {
    if (itemID >= 0 && itemID < MAX_ITEMS) {
        directAccessTable[itemID] = 1;
    } else {
        printf("Invalid Item ID!\n");
    }
}

// Function to remove an item from stock (set availability to 0)
void removeItemFromStock(int itemID) {
    if (itemID >= 0 && itemID < MAX_ITEMS) {
        directAccessTable[itemID] = 0;
    } else {
        printf("Invalid Item ID!\n");
    }
}

// Function to check if an item is in stock
int isItemInStock(int itemID) {
    if (itemID >= 0 && itemID < MAX_ITEMS) {
        return directAccessTable[itemID];
    } else {
        printf("Invalid Item ID!\n");
        return -1;  // Return -1 if the ID is invalid
    }
}

// Function to print the status of all items
void printStockStatus() {
    printf("Item Availability (1 = In Stock, 0 = Out of Stock):\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Item %d: %s\n", i, directAccessTable[i] == 1 ? "In Stock" : "Out of Stock");
    }
}

int main() {
    // Initialize the Direct Access Table (set all items to "Out of Stock")
    initializeTable();

    // Add some items to stock
    addItemToStock(3);  // Item 3 is now in stock
    addItemToStock(5);  // Item 5 is now in stock
    addItemToStock(8);  // Item 8 is now in stock

    // Remove an item from stock
    removeItemFromStock(3);  // Item 3 is now out of stock

    // Check if specific items are in stock
    printf("Is Item 5 in stock? %s\n", isItemInStock(5) ? "Yes" : "No");
    printf("Is Item 3 in stock? %s\n", isItemInStock(3) ? "Yes" : "No");

    // Print the current stock status
    printStockStatus();

    return 0;
}
