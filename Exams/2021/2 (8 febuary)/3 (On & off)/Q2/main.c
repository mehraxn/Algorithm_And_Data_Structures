#include <stdio.h>
#include <string.h>

// Helper function to expand around the center and find the length of a palindrome
int expandAroundCenter(char *str, int left, int right) {
    int length = strlen(str);
    while (left >= 0 && right < length && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Return length of the palindrome
}

// Function to find the longest palindrome substring
int palindrome(char *str) {
    if (!str || strlen(str) == 0) {
        return 0; // Return 0 if the string is empty or null
    }

    int maxLength = 0; // To store the length of the longest palindrome substring
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        // Find odd-length palindromes (centered at one character)
        int len1 = expandAroundCenter(str, i, i);
        // Find even-length palindromes (centered at two characters)
        int len2 = expandAroundCenter(str, i, i + 1);

        // Get the maximum length between odd and even palindromes
        int maxLenForCurrentCenter = len1 > len2 ? len1 : len2;

        // Update the overall maximum length
        if (maxLenForCurrentCenter > maxLength) {
            maxLength = maxLenForCurrentCenter;
        }
    }

    return maxLength;
}

// Example usage
int main() {
    char str[] = "1234554abccbaxyY";
    int result = palindrome(str);
    printf("Length of the longest palindrome substring: %d\n", result);
    return 0;
}
