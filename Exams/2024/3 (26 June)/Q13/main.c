#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

// Helper function prototypes
void read_input(const char *filename, char **strings, int *n);
void generate_acronyms(char **strings, int n, char *current_acronym, int index, FILE *output);
int is_valid_acronym(const char *acronym);

// Main acronym function
void acronym(const char *nameI, const char *nameO) {
    int n;
    char **strings;

    // Open the output file
    FILE *output = fopen(nameO, "w");
    if (!output) {
        perror("Failed to open output file");
        return;
    }

    // Read input
    strings = (char **)malloc(MAX_STRING_LENGTH * sizeof(char *));
    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
        strings[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    }
    read_input(nameI, strings, &n);

    // Allocate memory for the current acronym
    char *current_acronym = (char *)malloc((n + 1) * sizeof(char));
    current_acronym[n] = '\0';

    // Generate all valid acronyms recursively
    generate_acronyms(strings, n, current_acronym, 0, output);

    // Free memory and close files
    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
        free(strings[i]);
    }
    free(strings);
    free(current_acronym);
    fclose(output);
}

// Function to read input file
void read_input(const char *filename, char **strings, int *n) {
    FILE *input = fopen(filename, "r");
    if (!input) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    fscanf(input, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(input, "%s", strings[i]);
    }

    fclose(input);
}

// Recursive function to generate acronyms
void generate_acronyms(char **strings, int n, char *current_acronym, int index, FILE *output) {
    if (index == n) {
        // Base case: Check if the acronym is valid and write to output file
        if (is_valid_acronym(current_acronym)) {
            fprintf(output, "%s\n", current_acronym);
        }
        return;
    }

    // Recursive case: Iterate through all characters in the current string
    for (int i = 0; i < strlen(strings[index]); i++) {
        current_acronym[index] = strings[index][i];
        generate_acronyms(strings, n, current_acronym, index + 1, output);
    }
}

// Function to check if an acronym is valid
int is_valid_acronym(const char *acronym) {
    for (int i = 0; acronym[i] != '\0'; i++) {
        if (i % 2 == 0) {
            // Even indices: Should be a letter
            if (!isalpha(acronym[i])) {
                return 0;
            }
        } else {
            // Odd indices: Should be a digit
            if (!isdigit(acronym[i])) {
                return 0;
            }
        }
    }
    return 1;
}

// Main function
int main() {
    const char *input_file = "input.txt";
    const char *output_file = "output.txt";

    // Call the acronym function
    acronym(input_file, output_file);

    printf("Acronyms have been generated and written to %s\n", output_file);
    return 0;
}
