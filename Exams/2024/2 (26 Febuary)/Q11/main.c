#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int is_sorted_and_alphabetic(const char *str);
char *merge_string(const char *s1, const char *s2);

// Function to check if a string is alphabetically sorted and contains only lowercase letters
int is_sorted_and_alphabetic(const char *str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!islower(str[i]) || (i > 0 && str[i] < str[i - 1])) {
            return 0; // Not sorted or contains invalid characters
        }
    }
    return 1; // Valid string
}

// Function to merge two alphabetically sorted strings
char *merge_string(const char *s1, const char *s2) {
    // Validate input strings
    if (!is_sorted_and_alphabetic(s1) || !is_sorted_and_alphabetic(s2)) {
        fprintf(stderr, "Error: Input strings must be alphabetically sorted and contain only lowercase letters.\n");
        return NULL;
    }

    // Calculate lengths of input strings
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Allocate memory for the merged string
    char *merged = (char *)malloc(len1 + len2 + 1);
    if (!merged) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Merge the strings
    size_t i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (s1[i] <= s2[j]) {
            merged[k++] = s1[i++];
        } else {
            merged[k++] = s2[j++];
        }
    }

    // Append remaining characters from s1 or s2
    while (i < len1) {
        merged[k++] = s1[i++];
    }
    while (j < len2) {
        merged[k++] = s2[j++];
    }

    // Null-terminate the merged string
    merged[k] = '\0';

    return merged;
}

// Example usage
int main() {
    const char *s1 = "abcdxyz";
    const char *s2 = "abcdefgh";

    char *result = merge_string(s1, s2);
    if (result) {
        printf("Merged string: %s\n", result);
        free(result); // Free allocated memory
    }

    return 0;
}
