#include <stdio.h>  // Standard input/output library
#define L 10        // Define L as the length of the array

// Function prototypes
void readAndPrintArray1(int v[], int length);   // Reads and prints an array using array indexing
void readAndPrintArray2(int v[], int length);   // Reads and prints an array using a pointer and pointer arithmetic in a loop
void readAndPrintArray3(int v[], int length);   // Reads and prints an array using a pointer and pointer offset arithmetic

int main() {
    int v[L] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // Declare and initialize an array of length L

    // Call functions to print the array using different methods
    printf("Output using readAndPrintArray1:\n");
    readAndPrintArray1(v, L);   // Using array indexing

    printf("Output using readAndPrintArray2:\n");
    readAndPrintArray2(v, L);   // Using pointer and pointer arithmetic in a loop

    printf("Output using readAndPrintArray3:\n");
    readAndPrintArray3(v, L);   // Using pointer and pointer offset arithmetic

    return 0;   // Exit the program successfully
}

// Function to read and print the array using array indexing
void readAndPrintArray1(int v[], int length) {
    int i;  // Loop control variable
    for (i = 0; i < length; i++) {
        printf("%d ", v[i]);   // Print the value using array indexing
    }
    printf("\n");  // Print a newline character at the end
}

// Function to read and print the array using a pointer in the loop
void readAndPrintArray2(int v[], int length) {
    int *p;  // Declare a pointer to integer
    int i;   // Loop control variable

    for (i = 0, p = v; i < length; i++, p++) {
        printf("%d ", *p);     // Print the value pointed to by p using pointer dereferencing
    }
    printf("\n");  // Print a newline character at the end
}

// Function to read and print the array using a pointer and pointer offset
void readAndPrintArray3(int v[], int length) {
    int *p = &v[0];  // Initialize pointer to point to the beginning of the array
    int i;           // Loop control variable

    for (i = 0; i < length; i++) {
        printf("%d ", *(p + i)); // Print the value at the pointer offset using pointer dereferencing
    }
    printf("\n");  // Print a newline character at the end
}

/*
 * Explanation of the functions in the code:
 *
 * The code contains three functions for printing an array of integers.
 * Although the functions use different approaches to access the array elements, they produce the same result.
 *
 * 1. readAndPrintArray1: This function uses array indexing to print each element of the array. It uses the array notation v[i] to access the elements.
 *
 * 2. readAndPrintArray2: This function uses a pointer (p) and pointer arithmetic to print the array elements. The pointer is incremented inside the loop to point to each successive element.
 *
 * 3. readAndPrintArray3: This function also uses a pointer (p) but accesses elements using pointer offset notation (p + i). This approach allows accessing the elements by calculating the address offset from the base pointer.
 *
 * All three functions effectively perform the same task of printing the array values, demonstrating different ways of accessing array elements in C.
 */
