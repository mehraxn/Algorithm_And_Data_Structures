#include <stdbool.h>

/**
 * Function to erase all duplicate characters from a string.
 *
 * @param str The string from which duplicates will be removed.
 */
void erase_duplicate(char *str) {
    // Boolean array to keep track of characters that have already been seen.
    // This array uses ASCII character codes (0-255) as indices.
    bool seen[256] = {false}; // Initialize all characters as unseen.

    int write_index = 0; // Index to write unique characters in the string.

    // Loop through each character in the string using read_index.
    for (int read_index = 0; str[read_index] != '\0'; read_index++) {
        char current_char = str[read_index]; // Get the current character from the string.

        // Check if the current character has not been encountered before.
        if (!seen[(unsigned char)current_char]) {
            // Mark the character as seen by setting its position in the array to true.
            seen[(unsigned char)current_char] = true;

            // Copy the current character to the write_index position.
            str[write_index++] = current_char;
        }
        // If the character is already seen, it is skipped (not copied).
    }

    // After the loop, terminate the string with a null character to ensure it's valid.
    str[write_index] = '\0';
}

/**
 * Explanation of the `erase_duplicate` function:
 *
 * This function modifies a given string by removing all duplicate characters while retaining
 * the first occurrence of each character. The approach is as follows:
 *
 * 1. **Tracking Seen Characters:**
 *    - A boolean array `seen` is used to track whether each ASCII character (0-255) has been
 *      encountered in the string. Each index in this array corresponds to an ASCII value.
 *
 * 2. **Two-Pointer Technique:**
 *    - `read_index` iterates through the original string, character by character.
 *    - `write_index` keeps track of where the next unique character should be placed in the string.
 *
 * 3. **Logic:**
 *    - For each character in the string:
 *      - If it hasn't been seen before, mark it as seen and copy it to the `write_index` position.
 *      - If it has been seen, skip it.
 *
 * 4. **Null-Termination:**
 *    - After processing all characters, the string is terminated with a `\0` to ensure it remains valid.
 *
 * **Example:**
 * Input: "aa;;;bbbab"
 * Output: "a;b"
 *
 * The function is efficient and uses O(n) time complexity, where `n` is the length of the string,
 * and O(1) additional space for the `seen` array (constant size of 256).
 */
