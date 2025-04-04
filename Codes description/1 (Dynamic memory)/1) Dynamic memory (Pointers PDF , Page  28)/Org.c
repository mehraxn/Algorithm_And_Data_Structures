#include <stdio.h>  // Standard input/output library
#define L 10        // Define L as the length of the array

// Function prototypes
void readAndPrintArray1(int v[], int length);   // Reads and prints an array using array indexing
void readAndPrintArray2(int v[], int length);   // Reads and prints an array using a pointer and pointer arithmetic in a loop
void readAndPrintArray3(int v[], int length);   // Reads and prints an array using a pointer and pointer offset arithmetic

// Function to read and print the array using array indexing
void readAndPrintArray1(int v[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        scanf("%d", &v[i]);    // Read integer value from user and store it in the array
        printf("%d ", v[i]);   // Print the value just read
    }
    printf("\n");
}

// Function to read and print the array using a pointer in the loop
void readAndPrintArray2(int v[], int length) {
    int *p;  // Declare a pointer to integer
    int i;

    for (i = 0, p = v; i < length; i++, p++) {
        scanf("%d", p);        // Read integer value from user and store it in the array using the pointer
        printf("%d ", *p);     // Print the value pointed to by p
    }
    printf("\n");
}

// Function to read and print the array using a pointer and pointer offset
void readAndPrintArray3(int v[], int length) {
    int *p = &v[0];  // Initialize pointer to point to the beginning of the array
    int i;

    for (i = 0; i < length; i++) {
        scanf("%d", (p + i));   // Read integer value from user and store it in the array using pointer offset
        printf("%d ", *(p + i)); // Print the value at the pointer offset
    }
    printf("\n");
}
