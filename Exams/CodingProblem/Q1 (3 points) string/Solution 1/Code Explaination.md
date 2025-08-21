# Readme for `invert_string` Function

## Overview
The `invert_string` function is a utility designed to transform an input string (`s1`) into an output string (`s2`) by reversing sections of characters in `s1` that are in ascending order. The result is stored in dynamically allocated memory and pointed to by `s2`.

The function ensures that the resulting string maintains the reversed subsequences while retaining the overall structure of `s1`.

---

## Function Signature
```c
void invert_string(char *s1, char **s2);
```

### Parameters:
1. `char *s1`:
   - A null-terminated string that serves as the input.
   - Contains characters that may have ascending subsequences to be reversed.

2. `char **s2`:
   - A pointer to a pointer where the resulting transformed string will be stored.
   - Memory for `*s2` is dynamically allocated within the function, and the caller is responsible for freeing it.

### Returns:
- The function does not return a value directly. The transformed string is stored in the memory pointed to by `*s2`.

---

## Code Breakdown

### Main Function (`invert_string`)
```c
void invert_string(char *s1, char **s2) {
    int len = strlen(s1);
    *s2 = calloc(len+1, sizeof(char));
    int i = 0;
    while(i < len) {
        int count = 0;
        // Termination of string s1 is not explicitly checked as the ascending condition fails at the end.
        while(s1[i+count] < s1[i+count+1])
            count++;
        // Reverse (count+1) letters
        for(int j = 0; j <= count; j++) {
            (*s2)[i+count-j] = s1[i+j];
        }
        i += count + 1;
    }
}
```

#### Steps:
1. **String Length Calculation:**
   - The length of the input string `s1` is calculated using `strlen`.
   - Memory for `*s2` is allocated with size `len + 1` to accommodate the null terminator.

2. **Iteration through the String:**
   - A while loop iterates through `s1` character by character.
   - A nested loop (`while(s1[i+count] < s1[i+count+1])`) identifies contiguous ascending subsequences in `s1`. The count of ascending characters is stored in `count`.

3. **Reversal of Ascending Subsequences:**
   - For the identified subsequence of length `count + 1`, the characters are reversed and written to the corresponding positions in `*s2`.
   - A for loop performs this reversal, using the index `j` to calculate the reversed position.

4. **Advancing the Index:**
   - The index `i` is incremented by `count + 1` to move to the next segment of `s1`.

---

### Main Function (`main`)
```c
int main() {
    char *res;
    invert_string("ABCDDDDZYXWEFGGAA", &res);
    printf("result: %s\n", res);
}
```

#### Steps:
1. **String Initialization:**
   - The input string `"ABCDDDDZYXWEFGGAA"` is passed to the `invert_string` function.

2. **Dynamic Memory Usage:**
   - The output string `res` is dynamically allocated inside `invert_string` and is accessible after the function call.

3. **Output:**
   - The transformed string stored in `res` is printed using `printf`.

---

## Example Execution

### Input:
```c
char *s1 = "ABCDDDDZYXWEFGGAA";
```

### Transformation Steps:
- **Step 1:** Identify ascending subsequences in `s1`:
  - "ABCD" (indices 0-3)
  - "ZYX" (indices 5-7)
  - "EFG" (indices 9-11)
  - "AA" (indices 14-15)

- **Step 2:** Reverse each subsequence:
  - "ABCD" → "DCBA"
  - "ZYX" → "ZYX"
  - "EFG" → "GFE"
  - "AA" → "AA"

- **Step 3:** Combine all subsequences into `*s2`:
```
DCBDDDDYXZWEGFFAA
```

### Output:
```plaintext
result: DCBDDDDYXZWEGFFAA
```

---

## Memory Considerations
1. **Dynamic Allocation:**
   - Memory for `*s2` is allocated using `calloc`. The caller is responsible for freeing it after use.

2. **Potential Memory Issues:**
   - If `*s2` is not freed, it could result in a memory leak.

---

## Edge Cases
1. **Empty String:**
   - If `s1` is an empty string, the function will allocate a single null character for `*s2`.

2. **Single Character String:**
   - If `s1` contains only one character, `*s2` will be identical to `s1`.

3. **No Ascending Subsequences:**
   - If `s1` has no ascending subsequences, all characters will remain in their original order.

4. **Fully Ascending String:**
   - If `s1` is entirely ascending, the entire string will be reversed.

---

## Complexity Analysis

1. **Time Complexity:**
   - Identifying ascending subsequences: **O(n)**, where `n` is the length of `s1`.
   - Reversing subsequences: **O(n)**.
   - Total: **O(n)**.

2. **Space Complexity:**
   - The function allocates **O(n)** additional space for `*s2`.

---

## Summary
The `invert_string` function is a versatile utility for reversing ascending subsequences within a string. It uses efficient techniques for traversal and transformation, ensuring that the output string is dynamically allocated and ready for further processing. Proper memory management and consideration of edge cases are essential when integrating this function into larger programs.

