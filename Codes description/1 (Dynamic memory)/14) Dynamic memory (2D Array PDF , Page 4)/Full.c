#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100  // Maximum size for each string in the structure

// Define a structure that contains a static string
typedef struct e_s {
    char str[N];  // Static array of characters
} e_t;

// Function to fill the array of structures with example strings
void fillArray(e_t *v, int n) {
    for (int i = 0; i < n; i++) {
        // Use snprintf to safely write into the static array
        snprintf(v[i].str, N, "String %d", i + 1);
    }
}

// Function to print all the strings in the array of structures
void printArray(e_t *v, int n) {
    for (int i = 0; i < n; i++) {
        // Print each string in the array
        printf("%s\n", v[i].str);
    }
}

int main() {
    int n;  // Number of elements to allocate

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of structures
    e_t *v = (e_t *)malloc(n * sizeof(e_t));

    // Check if memory allocation succeeded
    if (v == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit the program if memory allocation fails
    }

    // Fill the array with data
    fillArray(v, n);

    // Print the content of the array
    printArray(v, n);

    // Free the allocated memory
    free(v);

    return 0;  // Indicate successful program execution
}

/*
 * Explanation of the Functions:
 *
 * 1. fillArray(e_t *v, int n):
 *    - This function populates the array of structures with example strings.
 *    - Each string is formatted as "String X", where X is the index + 1.
 *    - snprintf is used to avoid buffer overflow and ensure safe string formatting.
 *
 * 2. printArray(e_t *v, int n):
 *    - This function prints the strings stored in the array of structures.
 *    - A loop iterates through the array, and each string is printed to the console.
 *
 * 3. main():
 *    - The main function is the entry point of the program.
 *    - It prompts the user to input the number of elements.
 *    - Memory is dynamically allocated for the array of structures using malloc.
 *    - The fillArray function fills the array, and the printArray function displays its content.
 *    - Memory allocated with malloc is released using free to prevent memory leaks.
 *
 * Key Concepts Demonstrated:
 *    - Dynamic memory allocation using malloc.
 *    - Use of structures to store data.
 *    - Handling static strings within structures.
 *    - Safe string manipulation using snprintf.
 */
