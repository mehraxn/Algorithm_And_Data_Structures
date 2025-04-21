# README: Merging Alphabetically Sorted Strings in C

## Overview
This project demonstrates a C program that validates and merges two input strings, provided they are alphabetically sorted and contain only lowercase letters. The merged output is also alphabetically sorted, combining the characters of both strings while preserving the sorting order.

---

## Features
1. **Validation of Input Strings**:
   - Ensures that the input strings consist of only lowercase alphabetic characters (`a-z`).
   - Confirms that the strings are alphabetically sorted (e.g., `abcd`, `aaabc`).

2. **String Merging**:
   - Merges two validated strings into a single alphabetically sorted string.
   - Handles edge cases, such as empty strings or strings of unequal lengths.

3. **Memory Management**:
   - Dynamically allocates memory for the merged string.
   - Ensures memory is freed after use.

---

## Function Details

### 1. `is_sorted_and_alphabetic`
#### **Prototype**
```c
int is_sorted_and_alphabetic(const char *str);
```

#### **Purpose**
Checks if a string is:
- Sorted in ascending order.
- Composed of only lowercase alphabetic characters.

#### **Parameters**
- `const char *str`: Pointer to the input string to validate.

#### **Returns**
- `1` (true): If the string is valid (sorted and contains only lowercase letters).
- `0` (false): Otherwise.

#### **Implementation Details**
- Iterates through the string, checking each character to ensure it:
  - Is a lowercase letter using `islower()`.
  - Is alphabetically ordered relative to the previous character.

#### **Example**
```c
printf("%d\n", is_sorted_and_alphabetic("abcd")); // Output: 1
printf("%d\n", is_sorted_and_alphabetic("abCde")); // Output: 0
```

---

### 2. `merge_string`
#### **Prototype**
```c
char *merge_string(const char *s1, const char *s2);
```

#### **Purpose**
Merges two alphabetically sorted strings into a single alphabetically sorted string.

#### **Parameters**
- `const char *s1`: First input string (must be sorted and alphabetic).
- `const char *s2`: Second input string (must be sorted and alphabetic).

#### **Returns**
- Pointer to the merged string.
- `NULL`: If the input strings are invalid.

#### **Implementation Details**
1. **Validation**:
   - Uses `is_sorted_and_alphabetic` to validate both input strings.
   - Prints an error message and returns `NULL` if either string is invalid.

2. **Memory Allocation**:
   - Dynamically allocates memory to store the merged string.
   - Allocates enough memory to hold all characters of both input strings plus a null terminator (`len1 + len2 + 1`).

3. **Merging Process**:
   - Compares characters from both strings, adding the smaller character to the merged string.
   - If one string is exhausted, appends the remaining characters from the other string.

4. **Null-Termination**:
   - Ensures the merged string is null-terminated (`\0`).

#### **Example**
```c
const char *s1 = "abcdxyz";
const char *s2 = "abcdefgh";
char *result = merge_string(s1, s2);
if (result) {
    printf("Merged string: %s\n", result); // Output: aabbccddeefghxyz
    free(result);
}
```

#### **Error Handling**
- Prints an error message to `stderr` if the input strings are invalid:
```c
Error: Input strings must be alphabetically sorted and contain only lowercase letters.
```
- Exits the program with an error message if memory allocation fails:
```c
Memory allocation failed
```

---

## Example Usage

### Code Example
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    const char *s1 = "abcdxyz";
    const char *s2 = "abcdefgh";

    char *result = merge_string(s1, s2);
    if (result) {
        printf("Merged string: %s\n", result);
        free(result);
    }

    return 0;
}
```

### Output
```
Merged string: aabbccddeefghxyz
```

---

## Error Scenarios
1. **Invalid Input**:
   - Example: Input strings containing uppercase letters or unsorted characters.
   - Output: Error message and `NULL` return value.

2. **Memory Allocation Failure**:
   - If `malloc` fails, the program prints an error message and terminates.

---

## Notes
- Ensure strings passed to `merge_string` are validated to prevent unexpected results.
- Always free memory allocated by `merge_string` to avoid memory leaks.

---

## Dependencies
- Standard libraries:
  - `<stdio.h>`: For input/output operations.
  - `<stdlib.h>`: For memory allocation and exit handling.
  - `<string.h>`: For string manipulation.
  - `<ctype.h>`: For character classification.

---

## License
This project is open-source and can be used or modified freely.

