#include <stdio.h>

// Function 1: Using array indexing to calculate string length
int strlen1(char str[]) {
    int cnt;
    cnt = 0; // Initialize counter to 0
    while (str[cnt] != '\0') { // Loop until the null character is found
        cnt++; // Increment the counter for each character
    }
    return cnt; // Return the length of the string
}

// Function 2: Using pointer increment to calculate string length
int strlen2(char *str) {
    int cnt;
    cnt = 0; // Initialize counter to 0
    while (*str != '\0') { // Loop until the null character is found
        cnt++; // Increment the counter for each character
        str++; // Move pointer to the next character
    }
    return cnt; // Return the length of the string
}

// Function 3: Using a pointer variable to traverse the string
int strlen3(char str[]) {
    int cnt;
    char *p; // Declare a pointer variable
    cnt = 0; // Initialize counter to 0
    p = &str[0]; // Point to the first character of the string
    while (*p != '\0') { // Loop until the null character is found
        cnt++; // Increment the counter for each character
        p++; // Move pointer to the next character
    }
    return cnt; // Return the length of the string
}

// Function 4: Using pointer arithmetic to calculate string length
int strlen4(char *str) {
    char *p; // Declare a pointer variable
    p = str; // Point to the first character of the string
    while (*p != '\0') { // Loop until the null character is found
        p++; // Move pointer to the next character
    }
    return (p - str); // Return the difference between pointers, which is the length of the string
}

int main() {
    char str[] = "Hello, World!"; // Input string

    // Calculate string length using different functions and print the results
    printf("Length of the string using strlen1: %d\n", strlen1(str));
    printf("Length of the string using strlen2: %d\n", strlen2(str));
    printf("Length of the string using strlen3: %d\n", strlen3(str));
    printf("Length of the string using strlen4: %d\n", strlen4(str));

    return 0; // End of program
}

/*
Explanation of Functions:
1. Function strlen1 uses array indexing to calculate the length of the string.
   It iterates through each character using an index variable until it finds the null character ('\0').

2. Function strlen2 uses pointer increment to traverse the string.
   It increments both the pointer and a counter variable to determine the length.

3. Function strlen3 uses a pointer variable, similar to strlen2, but explicitly points to the first character of the string.
   It then increments the pointer and a counter until the null character is found.

4. Function strlen4 uses pointer arithmetic to calculate the string length.
   It keeps incrementing the pointer until the null character is found, and then returns the difference between the final pointer position and the initial position.

All four functions achieve the same result of calculating the length of the string, but they use different approaches involving array indexing or pointers.
*/
