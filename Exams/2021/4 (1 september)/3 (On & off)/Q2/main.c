#include <stdio.h>
#include <ctype.h>

// Function prototype
void substring(char *str, int *letter, int *digit);

/**
 * The `substring` function processes the input string `str` to determine:
 * 1. The length of the longest sequence of consecutive lowercase alphabetic characters.
 * 2. The length of the longest sequence of consecutive decimal digits.
 *
 * @param str    The input string containing any characters.
 * @param letter Pointer to an integer to store the length of the longest lowercase sequence.
 * @param digit  Pointer to an integer to store the length of the longest digit sequence.
 */
void substring(char *str, int *letter, int *digit) {
    int max_letter = 0, max_digit = 0; // Variables to store the max lengths
    int current_letter = 0, current_digit = 0; // Variables to count the current sequence lengths

    // Traverse the string character by character
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the character is a lowercase letter
        if (islower(str[i])) {
            current_letter++;
            max_letter = (current_letter > max_letter) ? current_letter : max_letter;
            current_digit = 0; // Reset digit counter
        }
            // Check if the character is a digit
        else if (isdigit(str[i])) {
            current_digit++;
            max_digit = (current_digit > max_digit) ? current_digit : max_digit;
            current_letter = 0; // Reset letter counter
        }
            // For any other character, reset both counters
        else {
            current_letter = 0;
            current_digit = 0;
        }
    }

    // Store the results in the provided pointers
    *letter = max_letter;
    *digit = max_digit;
}

// Example usage
int main() {
    char str[] = "This is 1 string inclUding diGits: 12345 678 9";
    int letter = 0, digit = 0;

    // Call the substring function
    substring(str, &letter, &digit);

    // Print the results
    printf("Longest sequence of lowercase letters: %d\n", letter);
    printf("Longest sequence of digits: %d\n", digit);

    return 0;
}
