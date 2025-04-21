# README for Dynamic Histogram Representation

## Overview
This program dynamically creates and manages a 2D matrix representation of a histogram based on an integer array. The histogram is stored in a dynamically allocated 2D character matrix, where each row corresponds to a row of a histogram made up of `*` characters. The program demonstrates efficient memory allocation, manipulation, and cleanup in C.

---

## Features
1. **Dynamic Memory Management**:
   - Memory for the histogram and the array is allocated dynamically using `malloc`.
   - Ensures memory safety and proper cleanup with `free`.

2. **User Input Driven**:
   - Accepts the size of the array and its elements as input from the user.
   - Dynamically adjusts the size of the histogram based on user input.

3. **Modular Functions**:
   - The code is organized into clear functions for creating, displaying, and cleaning up the histogram.

---

## Detailed Explanation of Functions

### 1. `char **array_to_histogram(int *vet, int n)`
#### Purpose:
- Converts an integer array `vet` of size `n` into a dynamically allocated 2D matrix that represents a histogram.

#### Parameters:
- `vet`: Pointer to an integer array containing the heights of the histogram bars.
- `n`: Size of the array `vet`.

#### Steps:
1. Allocate memory for `n` rows using `malloc`.
2. For each row `i`:
   - Allocate memory for `vet[i]` columns to hold the histogram stars.
   - Fill the allocated row with `*` characters.
3. Return the pointer to the dynamically allocated matrix.

#### Error Handling:
- If memory allocation fails at any step, the program:
  - Prints an error message.
  - Frees any previously allocated memory.
  - Exits with `EXIT_FAILURE`.

---

### 2. `void print_histogram(char **matrix, int *vet, int n)`
#### Purpose:
- Prints the histogram in a human-readable format.

#### Parameters:
- `matrix`: Pointer to the 2D matrix containing the histogram.
- `vet`: Pointer to the integer array containing the heights of the histogram bars.
- `n`: Number of rows in the histogram.

#### Steps:
1. Iterate through each row of the matrix.
2. Print the row index and the `*` characters corresponding to the height stored in `vet`.

---

### 3. `void free_histogram(char **matrix, int n)`
#### Purpose:
- Frees the dynamically allocated memory for the histogram matrix.

#### Parameters:
- `matrix`: Pointer to the 2D matrix to be freed.
- `n`: Number of rows in the matrix.

#### Steps:
1. Free each row of the matrix using `free`.
2. Free the memory allocated for the matrix pointer itself.

---

### 4. `int main()`
#### Purpose:
- Main function to drive the program.

#### Steps:
1. Prompts the user for the size of the array (`n`).
2. Allocates memory for the integer array `vet`.
3. Prompts the user to input the array elements.
4. Calls `array_to_histogram` to create the histogram matrix.
5. Displays the histogram using `print_histogram`.
6. Frees all allocated memory using `free_histogram` and `free` for the array.
7. Exits successfully.

#### Error Handling:
- Checks the result of `malloc` for the array and prints an error message if allocation fails.
- Terminates with `EXIT_FAILURE` if memory allocation fails.

---

## Example Execution
### Input:
```
Enter the number of elements in the array: 4
Enter 4 integers:
3 5 2 4
```

### Output:
```
Histogram:
Row 0: ***
Row 1: *****
Row 2: **
Row 3: ****
```

---

## Memory Safety
- The program ensures no memory leaks by:
  - Freeing each dynamically allocated row in the matrix.
  - Freeing the matrix itself.
  - Freeing the input integer array.
- It checks for memory allocation failures and handles errors gracefully by cleaning up and exiting.

---

## Edge Cases
1. **Empty Array (`n = 0`)**:
   - No memory is allocated for the matrix, and the program exits gracefully.

2. **Large Values in Array**:
   - The program can handle large values as long as sufficient system memory is available.

3. **Negative Values in Array**:
   - The program assumes all input values are non-negative. Negative values would result in undefined behavior (e.g., incorrect allocation).

---

## Limitations
- Assumes valid user input (non-negative integers).
- Does not handle inputs with negative numbers or invalid characters.

---

## How to Compile and Run
1. Save the code in a file (e.g., `histogram.c`).
2. Compile using:
   ```
   gcc -o histogram histogram.c
   ```
3. Run the executable:
   ```
   ./histogram
   ```

---

## Conclusion
This program demonstrates efficient use of dynamic memory allocation in C to represent a histogram. It is modular, robust, and a great example of memory-safe programming practices.

