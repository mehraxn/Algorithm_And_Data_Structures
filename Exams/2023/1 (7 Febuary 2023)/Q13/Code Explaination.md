# README: Equal Sum Digits Generator Program

## Overview
This program generates all possible `n`-digit numbers such that the sum of digits at even indices equals the sum of digits at odd indices. The numbers are written to a specified output file. It uses recursion to explore all combinations of digits and dynamically calculates the sums.

---

## Features
- **Digit Generation**: Generates numbers with `n` digits.
- **Equality Condition**: Ensures the sum of digits at even indices equals the sum of digits at odd indices.
- **File Output**: Writes the generated numbers to a specified file.
- **Dynamic Memory Management**: Allocates and frees memory dynamically for efficient number generation.

---

## Code Structure
### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Calls the `generate` function to generate numbers and write them to `output.txt`.

---

#### 2. **generate**
```c
void generate(char *name, int n);
```
- **Purpose**: Initializes resources for number generation and calls the recursive function.
- **Parameters**:
  - `name`: Name of the output file.
  - `n`: Number of digits in each generated number.
- **Logic**:
  - Opens the output file for writing.
  - Allocates memory for storing the digits of the number.
  - Calls `recursiveGenerate` to begin the generation process.
  - Frees allocated memory and closes the file.

---

#### 3. **recursiveGenerate**
```c
void recursiveGenerate(int *num, int size, int i, int evenSum, int oddSum, FILE *f);
```
- **Purpose**: Recursively generates all possible numbers and checks the equality condition.
- **Parameters**:
  - `num`: Array to store the digits of the current number.
  - `size`: Total number of digits in the number.
  - `i`: Current index being generated.
  - `evenSum`: Sum of digits at even indices.
  - `oddSum`: Sum of digits at odd indices.
  - `f`: File pointer to write the numbers.
- **Logic**:
  - Base Case: If all digits are generated (`i >= size`), checks if `evenSum == oddSum`.
  - If the condition is satisfied, writes the number to the output file.
  - Recursive Case: For each index, generates all valid digits (`0, 2, 4, 6, 8` for even and `1, 3, 5, 7, 9` for odd indices).
  - Adjusts the sums dynamically during the recursive calls.

---

## Example Execution

### Input
- `n = 5`: Generate all 5-digit numbers.
- Output File: `output.txt`

### Output in `output.txt`
```
13524
13542
15324
15342
...
```
- The file contains all 5-digit numbers such that the sum of digits at even indices equals the sum of digits at odd indices.

---

## Data Structures

### Array for Digits
- An array `num` is used to store the digits of the current number being generated.

### Sums
- `evenSum`: Tracks the sum of digits at even indices.
- `oddSum`: Tracks the sum of digits at odd indices.

---

## Memory Management
- **Dynamic Allocation**:
  - Allocates memory for the `num` array based on the number of digits (`n`).
- **Deallocation**:
  - Frees the allocated memory after processing.
  - Ensures no memory leaks by handling all edge cases.

---

## Limitations
- **File Handling**: Assumes the file can be opened and written to without errors.
- **Fixed Digit Set**: Only generates numbers using base-10 digits (0-9).
- **Performance**: The program may become computationally expensive for large values of `n`.

---

## Future Improvements
- Add error handling for file operations.
- Extend the program to allow user-defined digit sets.
- Optimize recursion for larger values of `n`.
- Provide command-line arguments for input parameters.

---

## How to Compile and Run
1. Save the code in a file (e.g., `equal_sum_digits.c`).
2. Compile the program:
   ```bash
   gcc -o equal_sum_digits equal_sum_digits.c
   ```
3. Run the program:
   ```bash
   ./equal_sum_digits
   ```
4. Check the output in the specified file (e.g., `output.txt`).

