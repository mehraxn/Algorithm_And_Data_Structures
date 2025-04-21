#include <stdio.h>

// Function to recursively generate all valid palindrome passwords
// This function takes a partially filled password array and the current index to fill
void generatePasswords(char password[], int index) {
    // Base case: If the password is complete (index reaches 7), print it
    if (index == 7) {
        password[7] = '\0'; // Null-terminate the string to ensure it's a valid C string
        printf("%s\n", password); // Print the generated password
        return; // End the current recursive call
    }

    // Recursive step: Depending on the index, fill the character and proceed
    switch (index) {
        case 0: // First character - small letter (a-z)
        case 6: // Seventh character - mirror of the first
            for (char ch = 'a'; ch <= 'z'; ++ch) { // Iterate through all lowercase letters
                password[0] = password[6] = ch; // Set both the first and seventh characters
                generatePasswords(password, index + 1); // Recur to fill the next character
            }
            break;

        case 1: // Second character - capital letter (A-Z)
        case 5: // Sixth character - mirror of the second
            for (char ch = 'A'; ch <= 'Z'; ++ch) { // Iterate through all uppercase letters
                password[1] = password[5] = ch; // Set both the second and sixth characters
                generatePasswords(password, index + 1); // Recur to fill the next character
            }
            break;

        case 2: // Third character - digit (0-9)
        case 4: // Fifth character - mirror of the third
            for (char ch = '0'; ch <= '9'; ++ch) { // Iterate through all digits
                password[2] = password[4] = ch; // Set both the third and fifth characters
                generatePasswords(password, index + 1); // Recur to fill the next character
            }
            break;

        case 3: // Fourth character - '+' or '-' (fixed symbols)
            password[3] = '+'; // Set the fourth character as '+'
            generatePasswords(password, index + 1); // Recur to fill the next character
            password[3] = '-'; // Set the fourth character as '-'
            generatePasswords(password, index + 1); // Recur to fill the next character
            break;
    }
}

// Main function to initialize the password array and invoke the recursive function
int main() {
    char password[8]; // Array to store the password (7 characters + null terminator)

    printf("Generating all valid palindrome passwords:\n"); // Inform the user about the operation
    generatePasswords(password, 0); // Start generating passwords from the first index

    return 0; // Return 0 to indicate successful execution
}

/*
// Explanation of the Code:

1. **Purpose:**
   - The program generates all valid palindrome passwords of length 7 based on specific constraints:
     - Positions 1 and 7 (mirrored) must contain lowercase letters ('a' to 'z').
     - Positions 2 and 6 (mirrored) must contain uppercase letters ('A' to 'Z').
     - Positions 3 and 5 (mirrored) must contain digits ('0' to '9').
     - Position 4 must contain either '+' or '-'.

2. **Recursive Function - `generatePasswords`:**
   - This function recursively fills each character in the password based on its index:
     - **Index 0 and 6:** Iterates through all lowercase letters.
     - **Index 1 and 5:** Iterates through all uppercase letters.
     - **Index 2 and 4:** Iterates through all digits.
     - **Index 3:** Sets the fourth character as '+' or '-' and proceeds.
   - The recursion proceeds character by character until the password is completely filled.
   - When `index == 7`, the function prints the completed password.

3. **Base Case:**
   - When the index reaches 7, the password is complete, and it is printed to the standard output.

4. **Main Function:**
   - Initializes the password array and invokes the recursive function starting at index 0.

5. **Output:**
   - The program generates and prints all valid palindrome passwords, satisfying the given constraints.

// Key Notes:
   - The password array is mirrored, ensuring palindrome symmetry.
   - The recursion efficiently explores all possible combinations based on the constraints.
   - The program uses standard C libraries and adheres to modular and clean coding practices.
*/
