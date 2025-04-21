#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Recursive function to generate all anagrams of a string `word`
 * that do not start with a capital letter.
 *
 * @param word    The input word.
 * @param anagram The current anagram being built.
 * @param used    Array to track which letters have been used.
 * @param n       The current depth in the recursion (index of `anagram`).
 */
void generate_r(char *word, char *anagram, int *used, int n) {
    int i;

    // Base case: if `n` equals the length of `word`, the anagram is complete
    if (n == strlen(word)) {
        // Position 1: Check if the anagram starts with a capital letter
        if (!isupper(anagram[0])) {
            anagram[n] = '\0'; // Null-terminate the anagram
            printf("%s\n", anagram); // Print the anagram
        }
        return;
    }

    // Generate anagrams by trying each unused letter
    for (i = 0; i < strlen(word); i++) {
        if (used[i] == 0) { // If the letter at `i` is not yet used
            // Position 2: Mark the letter as used and add it to the anagram
            used[i] = 1;
            anagram[n] = word[i];

            // Recurse to fill the next position in the anagram
            generate_r(word, anagram, used, n + 1);

            // Backtrack: unmark the letter as used
            used[i] = 0;
        }
    }
    return;
}

int main() {
    char word[] = "Abc"; // Example word
    int len = strlen(word);

    char anagram[len + 1]; // Array to build anagrams
    int used[len]; // Array to track used letters

    // Initialize the `used` array to 0
    for (int i = 0; i < len; i++) {
        used[i] = 0;
    }

    printf("Anagrams of \"%s\" that do not start with a capital letter:\n", word);
    generate_r(word, anagram, used, 0);

    return 0;
}
