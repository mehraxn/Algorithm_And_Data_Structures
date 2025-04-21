# README: Sparse Matrix Linked List Representation and Transposition

## Overview
This program implements a sparse matrix representation using linked lists and provides functionality to transpose the matrix. The matrix is read from a file, and only non-zero elements are stored to save memory. The transposed matrix is computed by rearranging rows and columns, maintaining the sparse representation.

---

## Features
- **Sparse Matrix Representation**: Efficiently stores only non-zero elements.
- **Matrix Transposition**: Creates a transposed version of the matrix.
- **Dynamic Memory Management**: Ensures efficient use of memory by dynamically allocating and freeing memory.
- **File Input Support**: Reads matrix data from a file.
- **Human-Readable Output**: Prints the matrix in a row-column-value format.

---

## Code Structure
### Main Data Structures

#### 1. **list_t2**
```c
typedef struct t2 {
    int col;
    int value;
    struct t2* next;
} list_t2;
```
- Represents a column-value pair for a specific row in the sparse matrix.
- **Fields**:
  - `col`: The column index.
  - `value`: The value of the matrix at the corresponding row-column pair.
  - `next`: Pointer to the next column-value pair in the row.

#### 2. **list_t1**
```c
typedef struct t1 {
    int row;
    list_t2* col_list;
    struct t1* next;
} list_t1;
```
- Represents a row in the sparse matrix.
- **Fields**:
  - `row`: The row index.
  - `col_list`: Pointer to the head of the column-value linked list for this row.
  - `next`: Pointer to the next row in the matrix.

---

### Main Functions

#### 1. **insert_t2**
```c
void insert_t2(list_t2** head, int col, int value);
```
- **Purpose**: Inserts a new column-value pair into the `list_t2` linked list.
- **Parameters**:
  - `head`: Pointer to the head of the column list.
  - `col`: The column index.
  - `value`: The value to insert.
- **Logic**:
  - Allocates memory for a new `list_t2` node.
  - Adds the node to the end of the column list.

#### 2. **insert_t1**
```c
void insert_t1(list_t1** head, int row, int col, int value);
```
- **Purpose**: Inserts a new row or updates an existing row in the sparse matrix.
- **Parameters**:
  - `head`: Pointer to the head of the row list.
  - `row`: The row index.
  - `col`: The column index.
  - `value`: The value to insert.
- **Logic**:
  - Finds or creates a `list_t1` node for the specified row.
  - Inserts the column-value pair into the corresponding `list_t2` list.

#### 3. **print_list**
```c
void print_list(list_t1* head);
```
- **Purpose**: Prints the sparse matrix in a human-readable format.
- **Parameters**:
  - `head`: Pointer to the head of the row list.
- **Logic**:
  - Iterates through the row list and prints each row's column-value pairs.

#### 4. **transpose**
```c
void transpose(list_t1* head1, list_t1** head2);
```
- **Purpose**: Computes the transpose of the sparse matrix.
- **Parameters**:
  - `head1`: Pointer to the head of the original matrix.
  - `head2`: Pointer to the head of the transposed matrix.
- **Logic**:
  - Iterates through each row and column-value pair of the original matrix.
  - Inserts each value into the corresponding column as a row in the transposed matrix.

#### 5. **free_list**
```c
void free_list(list_t1* head);
```
- **Purpose**: Frees all dynamically allocated memory for the sparse matrix.
- **Parameters**:
  - `head`: Pointer to the head of the row list.
- **Logic**:
  - Frees each `list_t2` column list and then each `list_t1` row node.

---

### Main Function
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Reads the matrix from a file (`input.txt`).
  - Constructs the sparse matrix using linked lists.
  - Prints the original matrix.
  - Computes and prints the transposed matrix.
  - Frees all allocated memory.

---

## Input File Format
The input file should contain:
1. The number of columns in the matrix (first line).
2. The matrix elements (space-separated).

### Example (`input.txt`):
```
3
1 0 0
0 2 0
0 0 3
```
- Represents a 3x3 matrix:
  - Row 0: `1 0 0`
  - Row 1: `0 2 0`
  - Row 2: `0 0 3`

---

## Output
### Original Matrix
```
Row: 0
Column: 0, Value: 1

Row: 1
Column: 1, Value: 2

Row: 2
Column: 2, Value: 3
```

### Transposed Matrix
```
Row: 0
Column: 0, Value: 1

Row: 1
Column: 1, Value: 2

Row: 2
Column: 2, Value: 3
```

---

## Memory Management
- Allocates memory dynamically for row and column lists.
- Frees all allocated memory to avoid memory leaks.

---

## How to Compile and Run
1. Save the code in a file (e.g., `sparse_matrix.c`).
2. Compile the program:
   ```bash
   gcc -o sparse_matrix sparse_matrix.c
   ```
3. Run the program:
   ```bash
   ./sparse_matrix
   ```
4. Ensure `input.txt` is in the same directory as the executable.

---

## Limitations
- Assumes the input file format is correct; no extensive validation is performed.
- Inefficient for dense matrices due to overhead from linked list operations.

---

## Future Improvements
- Add validation for input file format and values.
- Optimize insertion functions for large matrices.
- Extend support for user-defined input during runtime.

