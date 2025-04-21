#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reorder a string based on an integer array
char *reorder_string(char *s1, int *v) {
    // Get the length of the string
    size_t len = strlen(s1);

    // Allocate memory for the new string
    char *s2 = (char *)malloc((len + 1) * sizeof(char));
    if (!s2) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Initialize all elements in s2 to null terminator
    memset(s2, '\0', len + 1);

    // Validate the array v
    for (size_t i = 0; i < len; i++) {
        if (v[i] < 0 || v[i] >= (int)len) {
            fprintf(stderr, "Invalid index %d in array v\n", v[i]);
            free(s2);
            return NULL;
        }
    }

    // Reorder the string based on array v
    for (size_t i = 0; i < len; i++) {
        s2[v[i]] = s1[i];
    }

    return s2;
}

// Main function to demonstrate the usage of reorder_string
int main() {
    // Example inputs
    char s1[] = "abcdefgh";
    int v[] = {7, 4, 3, 0, 1, 2, 5, 6};

    // Call reorder_string and get the reordered string
    char *s2 = reorder_string(s1, v);

    // Check for errors and print the result
    if (s2) {
        printf("Original string: %s\n", s1);
        printf("Reordered string: %s\n", s2);
        free(s2);
    } else {
        printf("Error in reordering string.\n");
    }

    return 0;
}