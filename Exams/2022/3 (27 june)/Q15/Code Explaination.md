# README: Explanation of the `mul` Function

This document provides a detailed, line-by-line explanation of the `mul` function, which performs multiplication of two large numbers represented as arrays of digits.

---

## **Function Prototype**
```c
void mul(int *v1, int *v2, int n, int **pv);
```
- **Purpose**: Multiplies two large numbers stored in arrays `v1` and `v2`, each containing `n` digits, and stores the result in a dynamically allocated array referenced by `pv`.
- **Parameters**:
  - `int *v1`: Pointer to the first array, representing the first number.
  - `int *v2`: Pointer to the second array, representing the second number.
  - `int n`: Number of digits in both `v1` and `v2`.
  - `int **pv`: Pointer to the dynamically allocated array where the result will be stored.

---

## **Function Breakdown**

### **Step 1: Allocate Space for the Result Array**
```c
int result_size = 2 * n;
*pv = (int *)calloc(result_size, sizeof(int));
if (*pv == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
}
```
- **Purpose**: Allocates memory to store the result of the multiplication.
- **Logic**:
  - The result of multiplying two `n`-digit numbers can have at most `2 * n` digits.
  - `calloc` initializes all elements of the result array to `0`.
- **Error Handling**: If memory allocation fails, the function prints an error message and exits the program.

### **Step 2: Perform Multiplication Using Sum-and-Shift Algorithm**
```c
for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
        int product = v1[i] * v2[j];
        int pos = (n - 1 - i) + (n - 1 - j); // Calculate position in result array

        // Add product to the current position, including carry
        (*pv)[pos] += product;
        (*pv)[pos + 1] += (*pv)[pos] / 10; // Carry to the next position
        (*pv)[pos] %= 10; // Keep only the single digit
    }
}
```
- **Outer Loop (`for i`)**:
  - Iterates over each digit of the first number (`v1`) from right to left (least significant to most significant).
- **Inner Loop (`for j`)**:
  - Iterates over each digit of the second number (`v2`) from right to left.
- **Multiplication**:
  - Multiplies the `i`-th digit of `v1` with the `j`-th digit of `v2`.
  - The product is placed in the correct position (`pos`) in the result array.
  - **Carry Handling**:
    - If the sum of products at a position exceeds 9, the carry is propagated to the next position (`pos + 1`).
    - The current position is reduced to a single digit using modulo operation (`% 10`).

### **Step 3: Reverse the Result Array for Correct Order**
```c
for (int i = 0; i < result_size / 2; i++) {
    int temp = (*pv)[i];
    (*pv)[i] = (*pv)[result_size - 1 - i];
    (*pv)[result_size - 1 - i] = temp;
}
```
- **Purpose**: The result array is calculated in reverse order (least significant digit first). This step reverses the array to correct the digit order.
- **Logic**:
  - Iterates over the first half of the array and swaps each element with its corresponding element in the second half.
  - `temp` is used as a temporary variable to facilitate the swap.

---

## **Summary of the Logic**
1. **Memory Allocation**:
   - Allocates space for the result array to handle the maximum possible number of digits (`2 * n`).
2. **Sum-and-Shift Algorithm**:
   - Multiplies each digit of `v1` with each digit of `v2`.
   - Places the product in the correct position in the result array.
   - Handles carry propagation to ensure correct multi-digit arithmetic.
3. **Reversing the Result**:
   - Adjusts the result array to display the number in the correct order (most significant digit first).

---

## **Example Execution**
### Input:
```c
v1 = {0, 3, 2}; // Represents 32
v2 = {2, 4, 3}; // Represents 243
n = 3;          // Number of digits in each number
```
### Steps:
1. Multiply each digit of `v1` with each digit of `v2`.
2. Sum the intermediate results and propagate carry values.
3. Reverse the result array.

### Output:
```c
pv = {0, 0, 7, 7, 7, 6}; // Represents 7776 (32 * 243)
```

---

## **Edge Cases Handled**
1. **Leading Zeros**:
   - The function handles leading zeros in the input arrays correctly.
2. **Carry Propagation**:
   - Carry values are propagated efficiently across all digits of the result array.
3. **Large Inputs**:
   - Supports extremely large numbers by dynamically allocating memory for the result.

---

## **Limitations**
- The function assumes valid inputs (arrays containing only single-digit integers). Additional input validation may be required for broader use cases.

---

