#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold a set of characters (word) and its length
typedef struct letters letter;
struct letters {
    char *word;    // Pointer to a string of characters
    int length;    // Length of the string
};

// Function prototype for generating permutations
int permutation(letter *, char *, int, int, int);

int main() {
    int number = 7; // Length of the password to generate (odd length palindrome)
    letter array[4]; // Array to store character sets

    // Initialize character sets for lowercase letters, uppercase letters, digits, and symbols
    array[0].word = "abcdefghijklmnopqrstuvwxyz"; // Small letters
    array[0].length = 26;

    array[1].word = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Capital letters
    array[1].length = 26;

    array[2].word = "0123456789"; // Digits
    array[2].length = 10;

    array[3].word = "-+"; // Symbols
    array[3].length = 2;

    // Allocate memory to hold the solution (password) of length 'number'
    char *sol = (char *)malloc(number * sizeof(char));
    if (!sol) { // Check for memory allocation failure
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Call the permutation function to generate palindromes
    // Arguments: character sets, solution array, position, initial count, password length
    int total_permutation = permutation(array, sol, 0, 0, number);

    // Print the total number of generated palindrome permutations
    printf("The total number of permutations is: %d\n", total_permutation);

    free(sol); // Free the allocated memory for the solution array

    return 0;
}

// Function to generate palindrome permutations
// Parameters:
// - array: Array of character sets
// - sol: Array to store the current password being generated
// - pos: Current position in the palindrome (left side)
// - count: Counter to track the number of valid permutations generated
// - n: Total length of the password
int permutation(letter *array, char *sol, int pos, int count, int n) {
    int i;

    // Base case: If we reach the middle of the palindrome, print the solution
    if (pos >= n / 2 + 1) { // Only iterate up to the middle for efficiency
        for (i = 0; i < n; i++) // Print the current palindrome password
            printf("%c", sol[i]);
        printf("\n");
        return count + 1; // Increment and return the count of permutations
    }

    // Iterate over the characters in the current character set (array[pos])
    for (i = 0; i < array[pos].length; i++) {
        sol[pos] = array[pos].word[i];              // Set the left-side character
        sol[n - 1 - pos] = array[pos].word[i];      // Set the mirrored right-side character

        // Recursive call to fill the next position in the palindrome
        count = permutation(array, sol, pos + 1, count, n);
    }

    return count; // Return the total count of permutations
}

/*
Explanation of the Code:

1. **Structure Definition**:
   - A structure `letters` is defined to hold a character set (e.g., lowercase letters) and its length.
   - This allows us to pass an array of character sets to the function.

2. **Main Function**:
   - Four character sets are initialized:
     - Lowercase letters (a-z)
     - Uppercase letters (A-Z)
     - Digits (0-9)
     - Symbols (-+)
   - Memory is allocated to store the solution (password) of the specified length.
   - The `permutation` function is called to generate palindrome permutations.
   - The total number of permutations is printed, and allocated memory is freed.

3. **Permutation Function**:
   - **Base Case**: The recursion stops when the middle of the password is reached. At this point, the palindrome is complete and is printed.
   - **Recursive Case**:
     - For each position in the password, characters from the current character set are tried.
     - The character at the left side (`pos`) and its mirrored counterpart (`n - 1 - pos`) are set.
     - The function calls itself to fill the next position.
   - This ensures that the generated strings are palindromes since the characters are mirrored.

4. **Palindrome Logic**:
   - A palindrome reads the same forward and backward. The function ensures this by setting `sol[pos]` (left side) and `sol[n - 1 - pos]` (right side) to the same character.
   - For a password of length `n`, only the first half (and middle, if odd) needs to be decided, as the second half is mirrored.

5. **Efficiency**:
   - The recursion only runs until the middle of the string, reducing redundant computations.

6. **Output**:
   - All possible palindrome passwords of the specified length are printed.
   - The total number of such permutations is returned and displayed.
*/
