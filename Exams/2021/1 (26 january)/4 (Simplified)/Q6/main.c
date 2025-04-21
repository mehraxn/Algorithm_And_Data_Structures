#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check if a circular permutation already exists in the results
int isCircularEquivalent(char **results, int count, char *candidate) {
    int len = strlen(candidate);
    char rotated[len + 1];

    for (int i = 0; i < len; i++) {
        // Create a rotated version of the candidate
        for (int j = 0; j < len; j++) {
            rotated[j] = candidate[(i + j) % len];
        }
        rotated[len] = '\0';

        // Check if the rotated string is in the results
        for (int k = 0; k < count; k++) {
            if (strcmp(results[k], rotated) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to generate all permutations recursively
void generatePermutations(char *str, int l, int r, char **results, int *count) {
    if (l == r) {
        // Check if this permutation is a new distinct circular permutation
        if (!isCircularEquivalent(results, *count, str)) {
            results[*count] = (char *)malloc(strlen(str) + 1);
            strcpy(results[*count], str);
            (*count)++;
        }
    } else {
        for (int i = l; i <= r; i++) {
            // Swap the current element with the leftmost element
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;

            // Recur for the next level
            generatePermutations(str, l + 1, r, results, count);

            // Backtrack
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

// Function to generate and display circular permutations
void circularPermutation(char *str) {
    int n = strlen(str);

    // Allocate space to store distinct circular permutations
    char **results = (char **)malloc((n - 1) * sizeof(char *));
    int count = 0;

    // Generate all permutations and filter circularly equivalent ones
    generatePermutations(str, 0, n - 1, results, &count);

    // Display the results
    printf("Circular permutations:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", results[i]);
        free(results[i]); // Free allocated memory for each result
    }

    free(results); // Free the results array
}

int main() {
    char str[] = "ABCD";
    circularPermutation(str);
    return 0;
}
