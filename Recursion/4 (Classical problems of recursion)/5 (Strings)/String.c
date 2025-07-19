#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function prototypes */
void generate(int depth, int n, char *charset, int charset_size, char *current);
int is_vowel(char c);
int is_valid(char *current, int length);

/* Main program */
int main(void) {
    int n, charset_size;
    char input_charset[100], *charset, *current;

    printf("Length of strings: ");
    scanf("%d", &n);

    if (n < 3) {
        fprintf(stderr, "Length must be at least 3 for vowel constraint to apply.\n");
        return EXIT_FAILURE;
    }

    printf("Enter character set (no spaces): ");
    scanf("%s", input_charset);

    charset_size = strlen(input_charset);
    if (charset_size == 0) {
        fprintf(stderr, "Character set cannot be empty.\n");
        return EXIT_FAILURE;
    }

    charset = (char *)malloc(charset_size * sizeof(char));
    if (!charset) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }
    strcpy(charset, input_charset);

    current = (char *)malloc((n + 1) * sizeof(char));  // +1 for null terminator
    if (!current) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(charset);
        return EXIT_FAILURE;
    }

    printf("Valid strings:\n");
    generate(0, n, charset, charset_size, current);

    free(charset);
    free(current);
    return EXIT_SUCCESS;
}

/* Recursive function to generate strings */
void generate(int depth, int n, char *charset, int charset_size, char *current) {
    if (depth == n) {
        current[n] = '\0';  // Null-terminate the string
        if (is_valid(current, n)) {
            printf("%s\n", current);
        }
        return;
    }

    for (int i = 0; i < charset_size; i++) {
        current[depth] = charset[i];
        generate(depth + 1, n, charset, charset_size, current);
    }
}

/* Helper function to check if a character is a vowel */
int is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

/* Function to check the vowel constraint */
int is_valid(char *current, int length) {
    for (int i = 0; i < length - 2; i++) {
        if (is_vowel(current[i]) && is_vowel(current[i + 2])) {
            if (is_vowel(current[i + 1])) {
                return 0;  // Invalid if there's a vowel between two vowels
            }
        }
    }
    return 1;  // Valid string
}
