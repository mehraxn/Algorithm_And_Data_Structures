#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26 // Number of uppercase alphabetic characters

// Helper function to check if the current mapping satisfies the arithmetic operations in the matrix
bool is_valid_mapping(char **mat, int r, int c, int *mapping) {
    int carry = 0; // To keep track of the carry during addition

    // Traverse the matrix column by column, from right to left
    for (int col = c - 1; col >= 0; col--) {
        int column_sum = carry; // Start with the carry from the previous column

        // Add values for the current column, excluding the last row (which contains the result)
        for (int row = 0; row < r - 1; row++) {
            column_sum += mapping[mat[row][col] - 'A'];
        }

        // Extract the last digit (expected result for this column)
        int expected_digit = column_sum % 10;
        carry = column_sum / 10; // Update carry for the next column

        // Check if the expected digit matches the result in the last row of this column
        if (mapping[mat[r - 1][col] - 'A'] != expected_digit) {
            return false; // If not, the current mapping is invalid
        }
    }

    // The mapping is valid if no carry is left after processing all columns
    return carry == 0;
}

// Recursive function to assign digits to letters using backtracking
bool solve(char **mat, int r, int c, int *mapping, bool *used_digits, int index) {
    // Base case: if all letters have been assigned a digit, validate the mapping
    if (index == ALPHABET_SIZE) {
        return is_valid_mapping(mat, r, c, mapping);
    }

    // Try assigning digits (0-9) to the current letter
    for (int digit = 0; digit <= 9; digit++) {
        // Skip this digit if it is already used
        if (!used_digits[digit]) {
            // Assign the digit to the current letter
            mapping[index] = digit;
            used_digits[digit] = true;

            // Recursively try the next letter
            if (solve(mat, r, c, mapping, used_digits, index + 1)) {
                return true; // If a solution is found, propagate success
            }

            // Backtrack: undo the assignment and try the next digit
            used_digits[digit] = false;
        }
    }

    // If no valid digit assignment works, return false
    return false;
}

// Main function to solve the alphanumeric matrix problem
void alphanumeric_matrix(char **mat, int r, int c) {
    int mapping[ALPHABET_SIZE];    // Array to store digit assignments for each letter
    bool used_digits[10] = {false}; // Array to track which digits are already used

    // Initialize the mapping array with -1 (indicating no assignment yet)
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        mapping[i] = -1;
    }

    // Attempt to find a valid solution using backtracking
    if (solve(mat, r, c, mapping, used_digits, 0)) {
        // If a solution is found, print the letter-to-digit mapping
        printf("Letter-to-digit mapping:\n");
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (mapping[i] != -1) { // Only print letters that are part of the matrix
                printf("%c -> %d\n", 'A' + i, mapping[i]);
            }
        }
    } else {
        // If no solution exists, inform the user
        printf("No solution exists.\n");
    }
}

int main() {
    // Example input matrix
    int r = 4, c = 4; // Dimensions of the matrix
    char *mat[] = {
            "ONE ",  // Row 1
            "ONE ",  // Row 2
            "TWO ",  // Row 3
            "FOUR"   // Row 4 (result row)
    };

    // Call the function to solve the alphanumeric matrix
    alphanumeric_matrix(mat, r, c);

    return 0;
}
