# Recursive Matrix Processing in C

## Task Overview
This project involves reading a matrix from a file and generating two different outputs based on the matrix. The outputs are created using recursive functions, adhering to specific rules. The task includes:

1. Reading a matrix from a file.
2. Printing the matrix in a specific recursive manner.
3. Generating combinations recursively based on specific matrix elements (e.g., 'X' rules).

## Program Structure
### Files
- **input.txt**: The input file containing the matrix.
- **main.c**: The C program file containing the functions and main logic.

### Functions
#### 1. `void readMatrixFromFile(const char *filename, char matrix[SIZE][SIZE]);`
This function reads a matrix from the input file. It opens the file, reads each character or digit into the matrix according to the input rules, and then closes the file.

#### 2. `void recursiveMiddleMatrix(char matrix[SIZE][SIZE], int i, int j);`
This recursive function prints the middle output matrix row by row. It uses recursion to iterate through the matrix elements, printing them in the specified format.

#### 3. `void recursiveLowerMatrix(char matrix[SIZE][SIZE], int row, char current[SIZE * 2], int level);`
This recursive function generates all combinations based on the matrix. When encountering an 'X', it branches into creating two separate combinations, one with '1' and one with '2'. It prints each valid combination when it reaches the end of a row.

### Main Program
The `main` function calls:
1. `readMatrixFromFile()` to read the matrix from the file.
2. `recursiveMiddleMatrix()` to print the matrix in the middle output style.
3. `recursiveLowerMatrix()` to generate the lower matrix output combinations.

## Example
### Sample Input (in input.txt)
```
1
1
X 2
2
1 2 X
```

### Output
```
Middle Output Matrix:
1 1 1 1 1
1 1 1 1 1
X X X 2 2 2
2 2 2 2 2
1 2 X 1 2 X

Lower Matrix Output Combinations:
11X21
11X22
11X2X
11221
11222
1122X
```

## Compilation and Execution
To compile and run the program:
```bash
gcc main.c -o matrix_processor
./matrix_processor
```

## Customization
- **Matrix Size**: The matrix size is currently fixed at 5x5. To adjust, modify the `SIZE` constant.
- **Input File**: Change the input filename in the `readMatrixFromFile()` function call if needed.

## Notes
- Ensure that the input file follows the required format (i.e., single characters or pairs separated by spaces).
- The recursive functions handle branching based on 'X' to create various combinations.

