#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100  // Maximum size for input string

// Define a structure that contains a dynamic string pointer
typedef struct e_s {
    char *str;  // Pointer to a dynamically allocated string
} e_t;

int main() {
    int n;  // Number of elements to allocate
    char s[N];  // Buffer to hold the input string temporarily

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of structures
    e_t *v = (e_t *)malloc(n * sizeof(e_t));

    // Check if memory allocation for array of structures succeeded
    if (v == NULL) {
        printf("Memory allocation failed for the structure array!\n");
        return 1;  // Exit the program if memory allocation fails
    }

    // Loop to get input strings from the user and allocate memory for each string
    for (int i = 0; i < n; i++) {
        // Read a string from user input
        printf("Enter string %d: ", i + 1);
        scanf("%s", s);

        // Allocate memory for the string based on its length (+1 for null terminator)
        v[i].str = (char *)malloc((strlen(s) + 1) * sizeof(char));

        // Check if memory allocation for the string succeeded
        if (v[i].str == NULL) {
            printf("Memory allocation failed for string %d!\n", i + 1);
            return 1;  // Exit if memory allocation fails
        }

        // Copy the input string to the dynamically allocated memory
        strcpy(v[i].str, s);
    }

    // Use the strings (printing them out in this case)
    printf("\nStored strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", v[i].str);
    }

    // Free the memory allocated for each string
    for (int i = 0; i < n; i++) {
        free(v[i].str);
    }

    // Free the memory allocated for the array of structures
    free(v);

    return 0;  // Indicate successful program execution
}
