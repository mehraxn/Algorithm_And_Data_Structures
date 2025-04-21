# README: Longest Palindrome Substring Function

This document provides a comprehensive explanation of the `palindrome` function, which finds the length of the longest palindrome substring in a given string. A palindrome is a string that reads the same backward as forward.

## Function Signature
```c
int palindrome(char *str);
```

- **Parameters:**
  - `str`: A pointer to the input string for which the longest palindrome substring is to be found.
- **Return Value:**
  - Returns an integer representing the length of the longest palindrome substring in `str`. Returns `0` if no palindrome is found or if the input string is empty or null.

## Problem Statement
Given a string, find the length of the longest contiguous substring that is a palindrome. For example:
- Input: `"1234554abccbaxyY"`
- Output: `6` (The substring `"abccba"` is the longest palindrome.)

## Algorithm Description
The algorithm uses the concept of expanding around the center to efficiently find palindrome substrings. Each character (and the space between each pair of characters) is treated as a potential center of a palindrome.

### Key Steps:
1. **Expand Around Center:**
   - A helper function `expandAroundCenter` is used to calculate the length of the palindrome by expanding outward from a given center.
   - Odd-length palindromes are checked by considering the same character as both left and right centers.
   - Even-length palindromes are checked by considering adjacent characters as left and right centers.
2. **Iterate Through All Centers:**
   - For each character in the string, calculate the maximum palindrome length by checking both odd and even palindromes.
   - Update the global maximum palindrome length (`maxLength`) if a longer palindrome is found.
3. **Return the Result:**
   - After processing all centers, the function returns the length of the longest palindrome substring found.

### Complexity:
- **Time Complexity:** \(O(n^2)\)
  - Each center is processed in linear time due to the expansion, and there are \(O(n)\) centers.
- **Space Complexity:** \(O(1)\)
  - The function uses constant space (besides the input string).

## Implementation

### Helper Function: Expand Around Center
```c
int expandAroundCenter(char *str, int left, int right) {
    int length = strlen(str);
    while (left >= 0 && right < length && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Length of the palindrome
}
```

- **Parameters:**
  - `str`: The input string.
  - `left`: The starting index of the left center.
  - `right`: The starting index of the right center.
- **Logic:**
  - Expands outward as long as the characters at `left` and `right` are equal.
  - Stops when the bounds are exceeded or the characters are not equal.
  - Returns the length of the palindrome found during the expansion.

### Palindrome Function
```c
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
```

- **Logic:**
  - Iterates through each character in the string, treating it as a potential center.
  - For each character:
    - Checks odd-length palindromes by calling `expandAroundCenter` with the same `left` and `right` index.
    - Checks even-length palindromes by calling `expandAroundCenter` with adjacent `left` and `right` indices.
  - Updates the global maximum palindrome length.
- **Edge Case:**
  - Returns `0` if the input string is empty or null.

### Example Usage
```c
int main() {
    char str[] = "1234554abccbaxyY";
    int result = palindrome(str);
    printf("Length of the longest palindrome substring: %d\n", result);
    return 0;
}
```

#### Input:
```
"1234554abccbaxyY"
```
#### Output:
```
Length of the longest palindrome substring: 6
```

### How It Works:
1. **Odd-Length Palindromes:**
   - For example, the substring `"abccbaxyY"` has odd-length palindromes like `"bcb"`.
2. **Even-Length Palindromes:**
   - For example, the substring `"abccba"` is an even-length palindrome.
3. **Global Maximum:**
   - The longest palindrome substring is `"abccba"` with a length of `6`.

## Key Points
1. **Efficiency:**
   - The algorithm avoids generating all substrings explicitly, making it more efficient.
2. **Simplicity:**
   - The code is concise and uses modular functions for better readability.
3. **Scalability:**
   - The function can handle strings of reasonable lengths within \(O(n^2)\) time.

## Limitations
1. **Time Complexity:**
   - Although \(O(n^2)\) is efficient for most cases, it can be slow for very large strings.
2. **Assumption of Input:**
   - Assumes the input is a valid null-terminated string.

## Conclusion
The `palindrome` function efficiently finds the longest palindrome substring in a given string using an intuitive approach based on expanding around potential centers. Its modular design and simplicity make it easy to understand and extend, and it is well-suited for most practical applications.

