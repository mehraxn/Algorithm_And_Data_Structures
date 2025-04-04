#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to heapify the subtree rooted at index i in the array
// This ensures the subtree rooted at index i maintains the heap property (max heap).
void heapify(char arr[][100], int n, int i) {
    int largest = i;  // Assume the largest element is at the root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2;  // Right child index

    // If left child exists and is larger than the root, set largest to left child
    if (left < n && strcmp(arr[left], arr[largest]) > 0) {
        largest = left;
    }

    // If right child exists and is larger than the largest so far, set largest to right child
    if (right < n && strcmp(arr[right], arr[largest]) > 0) {
        largest = right;
    }

    // If the largest element is not the root, swap and heapify the affected subtree
    if (largest != i) {
        char temp[100];
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[largest]);
        strcpy(arr[largest], temp);

        // Recursively heapify the affected subtree to ensure the heap property is maintained
        heapify(arr, n, largest);
    }
}

// Function to build a max heap from the given array
// This function converts the given array into a max heap by calling heapify on all non-leaf nodes.
void buildHeap(char arr[][100], int n) {
    // Start from the last non-leaf node (n / 2 - 1) and call heapify on each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to perform heap sort
// The heap sort algorithm sorts the array in ascending order by first building a max heap and
// then repeatedly extracting the largest element from the heap and placing it at the end of the array.
void heapSort(char arr[][100], int n) {
    // First, build a max heap from the input array
    buildHeap(arr, n);

    // Now, one by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (the largest element) to the end of the array
        char temp[100];
        strcpy(temp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], temp);

        // Call heapify on the reduced heap (exclude the last sorted element)
        heapify(arr, i, 0);
    }
}

// Function to print the array of names
// This function simply prints each name in the array.
void printArray(char arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

// Main function where the program starts
int main() {
    // Array of 15 names to be sorted
    char names[15][100] = {
            "John",
            "Alex",
            "Mary",
            "Eve",
            "Charlie",
            "Grace",
            "David",
            "Michael",
            "Zara",
            "Sophia",
            "Liam",
            "Noah",
            "Olivia",
            "Emma",
            "Lucas"
    };

    int n = 15;  // Number of names in the array

    // Print the original array of names before sorting
    printf("Original list of names:\n");
    printArray(names, n);

    // Perform heap sort to sort the names array
    heapSort(names, n);

    // Print the sorted list of names
    printf("\nSorted list of names:\n");
    printArray(names, n);

    return 0;
}
