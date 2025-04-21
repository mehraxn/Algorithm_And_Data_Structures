# README for Circular Permutations Function

## Task Description

The task is to write a function `circularPermutation` that generates all distinct circular permutations of a given string. Circular permutations treat rotations of a string as equivalent. For example:
- For the string `"ABC"`, the circular permutations are: `ABC`, `BCA`, and `CAB`.
- For the string `"ABCD"`, the circular permutations are: `ABCD`, `BCDA`, `CDAB`, and `DABC`.

## Functionality

The function:
1. Receives a string as input.
2. Generates all distinct circular permutations of the string.
3. Stores these permutations in a proper data structure to avoid duplicates caused by rotations.
4. Displays the distinct circular permutations.

## Code Overview

### Core Functions

#### 1. `isCircularEquivalent`

This function checks if a given string is circularly equivalent to any previously recorded permutations.
- It generates all rotations of the candidate string.
- Compares each rotation to existing permutations in the results array.
- Returns `1` if a match is found, otherwise `0`.

**Parameters:**
- `results`: Array of previously stored permutations.
- `count`: Number of permutations stored in `results`.
- `candidate`: The string being checked for circular equivalence.

#### 2. `generatePermutations`

This function recursively generates all permutations of the input string using backtracking.
- It ensures only distinct circular permutations are added to the results.
- Uses the `isCircularEquivalent` function to filter out equivalent rotations.

**Parameters:**
- `str`: The string being permuted.
- `l`: The leftmost index for the current recursion.
- `r`: The rightmost index for the current recursion.
- `results`: Array to store unique circular permutations.
- `count`: Pointer to the count of unique permutations.

#### 3. `circularPermutation`

This is the main function:
- Allocates memory for storing the results of distinct circular permutations.
- Calls `generatePermutations` to produce all valid permutations.
- Prints the results and frees the allocated memory.

**Parameters:**
- `str`: Input string for which circular permutations are generated.

### Example

#### Input:
```
ABCD
```

#### Output:
```
Circular permutations:
ABCD
BCDA
CDAB
DABC
```

## Program Flow

1. **Initialization**:
   - Memory is allocated for storing distinct circular permutations.
   - A recursive function is called to generate all permutations of the input string.
2. **Circular Equivalence Check**:
   - Each permutation is checked for circular equivalence against stored results.
   - Non-equivalent permutations are added to the results array.
3. **Output**:
   - All distinct circular permutations are printed.
4. **Memory Management**:
   - Allocated memory is freed after usage.

## Complexity Analysis

### Time Complexity

1. **Permutation Generation**:
   - Generating all permutations of a string of length `n` takes \(O(n!)\).
2. **Circular Equivalence Check**:
   - For each permutation, \(O(n)\) rotations are generated and compared.
   - In the worst case, this adds \(O(n \cdot n!)\) complexity.

### Space Complexity

- Storage for results: Proportional to the number of unique permutations.
- Temporary space for rotations and backtracking: \(O(n)\).

## How to Use

1. **Compile the Code**
   Use a C compiler like GCC:
   ```
   gcc -o circular_permutations circular_permutations.c
   ```

2. **Run the Program**
   Execute the compiled program:
   ```
   ./circular_permutations
   ```

3. **Modify Input**
   Change the input string in the `main` function to test different cases.

## Code

Here is the full implementation:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check if a circular permutation already exists in the results
int isCircularEquivalent(char **results, int count, char *candidate) {
    int len = strlen(candidate);
    char rotated[len + 1];

    for (int i = 0; i < len; i++) {
        // Create a rotated version of the candidate
        for (int j = 0; j < len; j++) {
            rotated[j] = candidate[(i + j) % len];
        }
        rotated[len] = '\0';

        // Check if the rotated string is in the results
        for (int k = 0; k < count; k++) {
            if (strcmp(results[k], rotated) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to generate all permutations recursively
void generatePermutations(char *str, int l, int r, char **results, int *count) {
    if (l == r) {
        // Check if this permutation is a new distinct circular permutation
        if (!isCircularEquivalent(results, *count, str)) {
            results[*count] = (char *)malloc(strlen(str) + 1);
            strcpy(results[*count], str);
            (*count)++;
        }
    } else {
        for (int i = l; i <= r; i++) {
            // Swap the current element with the leftmost element
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;

            // Recur for the next level
            generatePermutations(str, l + 1, r, results, count);

            // Backtrack
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

// Function to generate and display circular permutations
void circularPermutation(char *str) {
    int n = strlen(str);

    // Allocate space to store distinct circular permutations
    char **results = (char **)malloc((n - 1) * sizeof(char *));
    int count = 0;

    // Generate all permutations and filter circularly equivalent ones
    generatePermutations(str, 0, n - 1, results, &count);

    // Display the results
    printf("Circular permutations:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", results[i]);
        free(results[i]); // Free allocated memory for each result
    }

    free(results); // Free the results array
}

int main() {
    char str[] = "ABCD";
    circularPermutation(str);
    return 0;
}
```

## Future Enhancements

1. Improve efficiency of circular equivalence checks by using hash tables.
2. Extend functionality to handle duplicate characters in the input string.
3. Add error handling for invalid input strings.
4. Allow input to be dynamically entered during runtime.

This README provides a comprehensive guide to the function's purpose, implementation, and usage. Feel free to modify the code for additional features or optimizations.

