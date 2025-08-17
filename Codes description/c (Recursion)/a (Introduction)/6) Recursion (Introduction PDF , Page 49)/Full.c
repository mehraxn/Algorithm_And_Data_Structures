#include <stdio.h>
#define MAX 100

// Function to reverse print a string recursively
// This function takes a character pointer `s` as input and prints the string in reverse order.
// It uses recursion to traverse to the end of the string and then prints each character on the way back.
void reverse_print(char *s) {
    // Base case: if we reach the end of the string, return
    if (*s == '\0') {
        return;
    }
    // Recursive call with the next character
    reverse_print(s + 1);
    // Print the current character after the recursive call
    printf("%c", *s);
    return;
}

// Main function to get user input and call reverse_print
// This function prompts the user for a string and then prints it in reverse using reverse_print
int main() {
    char str[MAX + 1];
    // Prompt the user for input
    printf("Input string: ");
    scanf("%s", str);
    // Print the reverse of the input string
    printf("Reverse string is: ");
    reverse_print(str);
    printf("\n");
    return 0;
}

/*
Summary of the Functions:

1. reverse_print Function:
   - The `reverse_print` function takes a character pointer (`s`) and prints the string in reverse order.
   - It uses recursion to navigate to the end of the string before printing each character.
   - The base case is when the end of the string (`\0`) is reached, at which point the function starts printing characters as it returns back through the recursive calls.
   - This approach is a simple example of how recursion can be used to solve problems that involve sequential processing.

2. main Function:
   - The `main` function is responsible for getting the input from the user and calling the `reverse_print` function.
   - It defines a character array (`str`) to store the input string and reads the input using `scanf`.
   - After getting the input, it calls `reverse_print` to display the reversed string.
   - The program then ends after printing the reversed string, demonstrating the use of recursion in string manipulation.
*/
