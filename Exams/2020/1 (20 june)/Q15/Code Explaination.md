# README: Recursive Anagram Generator

## Overview
The `generate_r` function generates all possible anagrams of a given string (`word`) that do not start with a capital letter. It uses recursion and backtracking to explore all permutations of the string while ensuring that only anagrams satisfying the condition are displayed.

---

## Function Prototype
```c
void generate_r(char *word, char *anagram, int *used, int n);
```

### Parameters:
1. `char *word`: The input string for which anagrams are generated.
2. `char *anagram`: A buffer to store the current anagram being built.
3. `int *used`: An array of integers (0 or 1) that tracks which characters in `word` have already been used in the current anagram.
4. `int n`: The current depth in the recursion (index of the current character being added to `anagram`).

---

## Logic

### Recursive Approach
1. **Base Case**:
   - If `n` (the current depth) equals the length of `word`, the function has constructed a complete anagram.
   - At this point, the function checks if the anagram starts with a lowercase letter (not a capital letter). If it does, the anagram is printed.

2. **Recursive Case**:
   - For each character in `word`, if it has not been used in the current anagram, it is:
     - Marked as used.
     - Added to the current position in `anagram`.
     - The function recurses to fill the next position.
   - After returning from recursion, the character is unmarked as used (backtracking) to allow exploration of other permutations.

---

## Completed Code
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generate_r(char *word, char *anagram, int *used, int n) {
    int i;

    // Base case: If `n` equals the length of `word`, an anagram is complete
    if (n == strlen(word)) {
        // Check if the anagram starts with a lowercase letter
        if (!isupper(anagram[0])) {
            anagram[n] = '\0'; // Null-terminate the anagram
            printf("%s\n", anagram); // Print the valid anagram
        }
        return;
    }

    // Loop through all characters in `word`
    for (i = 0; i < strlen(word); i++) {
        if (used[i] == 0) { // If the character has not been used
            used[i] = 1; // Mark the character as used
            anagram[n] = word[i]; // Add it to the current anagram

            // Recurse to the next position
            generate_r(word, anagram, used, n + 1);

            used[i] = 0; // Backtrack: unmark the character as used
        }
    }
    return;
}

int main() {
    char word[] = "Abc"; // Example input word
    int len = strlen(word);

    char anagram[len + 1]; // Buffer to build anagrams
    int used[len]; // Array to track used characters

    // Initialize the `used` array to 0
    for (int i = 0; i < len; i++) {
        used[i] = 0;
    }

    printf("Anagrams of \"%s\" that do not start with a capital letter:\n", word);
    generate_r(word, anagram, used, 0);

    return 0;
}
```

---

## Example Execution

### Input:
```text
word = "Abc"
```

### Output:
```text
Anagrams of "Abc" that do not start with a capital letter:
bAc
bcA
cAb
cbA
```

---

## How It Works

### Base Case
At the deepest level of recursion (when `n` equals the length of `word`):
1. The function checks if the first character of `anagram` is not a capital letter using `isupper`.
2. If the condition is satisfied, the anagram is printed.

### Recursive Step
For each unused character in `word`:
1. The character is added to the current position in `anagram`.
2. It is marked as used by setting the corresponding index in `used` to `1`.
3. The function recurses to the next position.
4. After returning from recursion, the character is unmarked (set back to `0`) to allow exploration of other permutations (backtracking).

### Backtracking
Backtracking ensures that all possible anagrams are explored without duplicating characters in the same anagram.

---

## Key Features

1. **Recursive Depth-First Search (DFS)**:
   - The function systematically explores all possible permutations of `word`.

2. **Backtracking**:
   - Ensures that each character is used exactly once per anagram and allows exploration of all valid permutations.

3. **Character Classification**:
   - Uses the `isupper` function from `<ctype.h>` to ensure only anagrams that do not start with a capital letter are printed.

4. **Dynamic Construction**:
   - The `anagram` array is built incrementally as the recursion progresses.

---

## Edge Cases

1. **Empty String**:
   - Input: `""`
   - Output: No output (no anagrams).

2. **All Uppercase Letters**:
   - Input: `"ABC"`
   - Output: No output (all anagrams start with a capital letter).

3. **All Lowercase Letters**:
   - Input: `"abc"`
   - Output: All possible anagrams.

4. **Mixed Case**:
   - Input: `"Abc"`
   - Output: Only anagrams starting with lowercase letters.

---

## Complexity

1. **Time Complexity**:
   - Generating all permutations of a string of length \(n\) takes \(O(n!)\).
   - Filtering based on the first character does not add additional complexity.
   - Overall complexity: \(O(n!)\).

2. **Space Complexity**:
   - Uses \(O(n)\) space for the `anagram` and `used` arrays.
   - Recursion depth is \(O(n)\).
   - Overall space complexity: \(O(n)\).

---

## Limitations

1. Assumes `word` contains valid ASCII characters.
2. Does not handle non-ASCII characters (e.g., Unicode).
3. Outputs are case-sensitive and depend on `isupper` for classification.

---

## Extensions

1. **Support for Unicode**:
   - Extend character classification to handle non-ASCII letters.

2. **Custom Filters**:
   - Allow users to specify additional conditions (e.g., anagrams starting with vowels).

3. **Performance Optimization**:
   - Use iterative methods to generate permutations instead of recursion for large strings.

---

## Conclusion
The `generate_r` function is an efficient and flexible solution for generating and filtering anagrams of a string. By combining recursion, backtracking, and character classification, it ensures that only valid anagrams are displayed. Its modular design and straightforward implementation make it adaptable to a variety of use cases.

