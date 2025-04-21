#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100 // Maximum length of a line in the file

// Helper function to clean a string: remove spaces and convert to lowercase
void clean_string(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Helper function to check if a string is a palindrome
int is_palindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left++] != str[right--]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to construct the longest palindrome phrase
void palindrome_phrase(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    char **lines = NULL; // Dynamic array to store lines
    int num_lines = 0;   // Count of lines in the file
    char buffer[MAX_LINE_LENGTH];

    // Read all lines from the file
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Allocate space for the new line
        lines = realloc(lines, (num_lines + 1) * sizeof(char *));
        lines[num_lines] = strdup(buffer); // Duplicate the line
        num_lines++;
    }
    fclose(file);

    // Create the longest palindrome phrase
    char *longest_palindrome = NULL;
    int max_length = 0;

    // Generate all combinations of lines to form a phrase
    for (int i = 0; i < num_lines; i++) {
        for (int j = i; j < num_lines; j++) {
            // Concatenate lines[i] to lines[j] into a single string
            int phrase_length = 0;
            for (int k = i; k <= j; k++) {
                phrase_length += strlen(lines[k]);
            }

            char *phrase = malloc(phrase_length + 1);
            phrase[0] = '\0'; // Initialize empty string

            for (int k = i; k <= j; k++) {
                strcat(phrase, lines[k]);
            }

            // Clean and check the phrase
            clean_string(phrase);
            if (is_palindrome(phrase) && strlen(phrase) > max_length) {
                free(longest_palindrome); // Free previous palindrome
                longest_palindrome = strdup(phrase); // Store new longest palindrome
                max_length = strlen(phrase);
            }

            free(phrase);
        }
    }

    // Output the result
    if (longest_palindrome) {
        printf("Longest Palindrome Phrase: %s\n", longest_palindrome);
        free(longest_palindrome);
    } else {
        printf("No palindrome phrase found.\n");
    }

    // Free allocated memory for lines
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    // Test the function with a sample file
    char filename[] = "phrases.txt";
    palindrome_phrase(filename);
    return 0;
}
