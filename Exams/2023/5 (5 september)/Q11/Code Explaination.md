# README: Longest Common Substring (LCS) Program

## Overview
This program finds the longest common substring (LCS) between two strings using two approaches:
1. **Iterative Comparison**: Compares all substrings of the two input strings to find the longest common substring.
2. **Recursive LCS**: Uses recursion to find the LCS but includes redundant computations.

The program outputs the length of the LCS and the substring itself.

---

## Features
- Finds the LCS using a brute-force iterative method.
- Includes a recursive approach for conceptual understanding.
- Prints both the length and the substring of the LCS.

---

## Code Structure
### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Initializes two test strings.
  - Calls the `common_substring` function to find the LCS length.
  - Outputs the length of the LCS.

#### 2. **common_substring**
```c
int common_substring(char* str1, char* str2);
```
- **Purpose**: Implements an iterative approach to find the LCS.
- **Parameters**:
  - `str1`: First input string.
  - `str2`: Second input string.
- **Logic**:
  - Iterates through all substrings of `str1` and `str2`.
  - Finds and prints the longest common substring.
- **Returns**: Length of the LCS.
- **Output**:
  - Prints the matching substrings during the computation.

#### 3. **lcs**
```c
int lcs(char* str1, char* str2, int n, int m, int count, int* start);
```
- **Purpose**: Implements a recursive approach to find the LCS.
- **Parameters**:
  - `str1`: First input string.
  - `str2`: Second input string.
  - `n`: Length of the current substring in `str1`.
  - `m`: Length of the current substring in `str2`.
  - `count`: Current count of matching characters.
  - `start`: Pointer to store the starting index of the LCS in `str1`.
- **Logic**:
  - Checks character-by-character matches at the end of substrings.
  - Recursively explores all possible substring matches.
  - Updates the starting index of the LCS.
- **Returns**: Length of the LCS.

#### 4. **max**
```c
int max(int a, int b);
```
- **Purpose**: Utility function to find the maximum of two integers.
- **Parameters**:
  - `a`: First integer.
  - `b`: Second integer.
- **Returns**: The maximum of `a` and `b`.

---

### Code Logic
1. **Iterative Approach (common_substring)**
   - Loops through all starting positions of `str1` and `str2`.
   - Matches characters from the current positions until a mismatch occurs.
   - Updates the maximum length and starting index of the LCS.
   - Prints the LCS and returns its length.

2. **Recursive Approach (lcs)**
   - Checks the last characters of the current substrings of `str1` and `str2`.
   - If the characters match:
     - Increases the count of the current match.
     - Recursively calls `lcs` with shortened substrings.
     - Updates the starting index of the LCS.
   - Explores other possibilities by skipping characters in `str1` or `str2`.
   - Returns the maximum length among all possibilities.

---

## Example Execution

### Input
- `str1`: `123ABCD34EFG`
- `str2`: `XXXABCiDE123AB4YACD`

### Output
```
up: A A 4
ABCD
Length of LCS is 4
```
- The program identifies `ABCD` as the LCS with a length of 4.

---

## Limitations
- **Brute-Force Nature**: The iterative approach has a high time complexity of O(n * m), making it inefficient for long strings.
- **Redundancy in Recursive Approach**: The recursive implementation recalculates overlapping subproblems, which can be optimized using dynamic programming.
- **No Dynamic Input**: Strings are hardcoded in the `main` function.

---

## Future Improvements
- Implement dynamic programming to optimize the LCS computation.
- Allow user input for strings instead of hardcoding.
- Enhance the program to handle edge cases such as empty strings or very large inputs.
- Include additional functionality, such as displaying all common substrings of maximum length.

---

## How to Compile and Run
1. Save the code in a file (e.g., `lcs.c`).
2. Compile the program:
   ```bash
   gcc -o lcs lcs.c
   ```
3. Run the program:
   ```bash
   ./lcs
   ```

