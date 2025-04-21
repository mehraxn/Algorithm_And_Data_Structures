# README: Subarray Analysis Program

## Overview
This program analyzes an array of floating-point numbers to identify:
1. The subarray of length `k` with the maximum sum.
2. The subarray of length `k` with the maximum difference (difference between the maximum and minimum values in the subarray).

It uses a sliding window approach to compute the desired properties efficiently.

---

## Features
- **Maximum Sum Subarray**: Identifies and prints the subarray of length `k` with the highest sum.
- **Maximum Difference Subarray**: Identifies and prints the subarray of length `k` with the largest range (max - min).
- **Dynamic Array Support**: Handles arrays of any size and subarray length.

---

## Code Structure

### Main Functions

#### 1. **searchSubArray**
```c
void searchSubArray(float *v, int n, int k);
```
- **Purpose**: Identifies and prints the subarrays with the maximum sum and maximum difference.
- **Parameters**:
  - `v`: Pointer to the array of floating-point numbers.
  - `n`: Length of the array.
  - `k`: Length of the subarray.
- **Logic**:
  - Iterates through all possible subarrays of length `k`.
  - For each subarray:
    - Computes the sum of the elements.
    - Tracks the minimum and maximum values to compute the difference.
  - Updates the indices of the subarrays with the maximum sum and maximum difference.
- **Output**:
  - Prints the subarray with the maximum sum and its sum.
  - Prints the subarray with the maximum difference and its difference.

---

#### 2. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Initializes an array of floating-point numbers.
  - Specifies the length of the array (`n`) and subarray length (`k`).
  - Calls `searchSubArray` to analyze the array.
  - Prints the results.

---

## Example Execution

### Input
- Array: `{12.5, 2.1, 3.3, 4.1, 5.4, 6.2, 7.9, 8.3, -9.9, 5.1}`
- `n = 10`: Length of the array.
- `k = 3`: Length of the subarray.

### Output
```
Maximum sum subarray: 7.900000 8.300000 -9.900000 (Sum: 21.600000)
Maximum difference subarray: 12.500000 2.100000 3.300000 (Difference: 10.400000)
```

---

## Data Structures

### Input Array
- The input is a simple array of floating-point numbers, with size `n` specified.

### Sliding Window
- Iterates through all possible subarrays of length `k` in a single pass.

---

## Memory Management
- The program does not dynamically allocate memory for the input array.
- No explicit deallocation is required since the array is statically allocated in `main`.

---

## Limitations
- **Fixed Subarray Length**: The subarray length `k` must be specified and cannot exceed `n`.
- **Sequential Processing**: The program recalculates sums and differences for each subarray, which could be optimized for large arrays.
- **Single Subarray Length**: Only analyzes subarrays of one length per execution.

---

## Future Improvements
- Implement a sliding window algorithm for improved efficiency in sum calculation.
- Extend the program to handle multiple subarray lengths in a single execution.
- Add support for dynamic input from the user or a file.
- Include error handling for invalid inputs, such as `k > n`.

---

## How to Compile and Run
1. Save the code in a file (e.g., `subarray_analysis.c`).
2. Compile the program:
   ```bash
   gcc -o subarray_analysis subarray_analysis.c
   ```
3. Run the program:
   ```bash
   ./subarray_analysis
   ```

