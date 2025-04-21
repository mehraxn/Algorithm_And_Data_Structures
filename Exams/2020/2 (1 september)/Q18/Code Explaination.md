# README: Matrix Partition Function

## Overview
The `find_partition` function identifies all valid partitions of a rectangular matrix where:
- Each partition contains the same set of capital letters (number and type).
- The wildcard character `'*'` can substitute for any letter, effectively making it equivalent to all letters.
- The solution outputs all valid partitions along with the row and column indices of elements in each partition.

---

## Function Prototype
```c
void find_partition(char matrix[MAX_R][MAX_C], int rows, int cols, int num_parts);
```

### Parameters:
1. `char matrix[MAX_R][MAX_C]`: A rectangular matrix containing only capital letters and the wildcard character `'*'`.
2. `int rows`: Number of rows in the matrix.
3. `int cols`: Number of columns in the matrix.
4. `int num_parts`: Number of subsets (partitions) to divide the matrix into.

---

## Key Helper Functions

### 1. `is_equivalent`
#### Purpose:
Determines if two characters are equivalent, considering `'*'` as a wildcard that can match any letter.

#### Prototype:
```c
bool is_equivalent(char a, char b);
```
#### Parameters:
- `char a, b`: The two characters to compare.

#### Returns:
- `true` if the characters are equivalent, otherwise `false`.

---

### 2. `count_letters`
#### Purpose:
Counts the occurrences of each letter (ignoring `'*'`) in a subset of the matrix.

#### Prototype:
```c
void count_letters(char matrix[MAX_R][MAX_C], int rows, int cols, int *subset, int subset_size, int *letter_counts);
```
#### Parameters:
- `matrix`: The input matrix.
- `rows, cols`: Dimensions of the matrix.
- `subset`: An array of indices representing the cells in the current subset.
- `subset_size`: Number of elements in the subset.
- `letter_counts`: An array to store the counts of each letter (indexed by 'A' to 'Z').

#### Logic:
1. Iterate through each index in `subset`.
2. Compute the row and column from the index.
3. If the character is not `'*'`, increment the corresponding position in `letter_counts`.

---

### 3. `validate_partition`
#### Purpose:
Validates whether all subsets in the current partition contain the same letter counts.

#### Prototype:
```c
bool validate_partition(int letter_counts[][26], int num_parts);
```
#### Parameters:
- `letter_counts`: A 2D array where each row represents the letter counts for a subset.
- `num_parts`: Number of subsets (partitions).

#### Returns:
- `true` if all subsets have identical letter counts, otherwise `false`.

#### Logic:
1. Compare the letter counts of all subsets against the first subset.
2. If any mismatch is found, return `false`.

---

### 4. `print_solution`
#### Purpose:
Prints the coordinates of all elements in each subset of a valid partition.

#### Prototype:
```c
void print_solution(int **partitions, int num_parts, int *partition_sizes, int rows, int cols);
```
#### Parameters:
- `partitions`: A 2D array where each row represents the indices of elements in a subset.
- `num_parts`: Number of subsets.
- `partition_sizes`: An array where each element represents the size of a corresponding subset.
- `rows, cols`: Dimensions of the matrix.

#### Output:
- Prints the subsets in the format:
  ```
  {{(r1,c1), (r2,c2)}, {(r3,c3), (r4,c4)}, ...}
  ```

---

## Main Recursive Function: `find_partitions_recursive`

### Purpose:
Recursively assigns each cell of the matrix to one of the subsets and validates the partitions.

### Prototype:
```c
void find_partitions_recursive(char matrix[MAX_R][MAX_C], int rows, int cols,
                               int **partitions, int num_parts, int *partition_sizes,
                               int start, int *letter_counts, int solution_count[]);
```

### Parameters:
- `matrix`: The input matrix.
- `rows, cols`: Dimensions of the matrix.
- `partitions`: A 2D array where each row represents a subset.
- `num_parts`: Number of subsets.
- `partition_sizes`: An array storing the size of each subset.
- `start`: The current index in the matrix being assigned.
- `letter_counts`: A temporary array for letter counts.
- `solution_count`: A pointer to count the number of valid partitions.

### Logic:
1. **Base Case**:
   - If all cells have been assigned (`start == rows * cols`):
     - Count the letters in each subset.
     - Validate the partitions.
     - If valid, print the solution and increment `solution_count`.

2. **Recursive Step**:
   - For each subset, add the current cell to the subset and recurse for the next cell.
   - Backtrack after returning from recursion by removing the cell from the subset.

---

## Wrapper Function: `find_partition`

### Purpose:
Initializes data structures and invokes the recursive function to find valid partitions.

### Prototype:
```c
void find_partition(char matrix[MAX_R][MAX_C], int rows, int cols, int num_parts);
```

### Logic:
1. Allocate memory for subsets and their sizes.
2. Call the recursive function `find_partitions_recursive` with the initialized data.
3. Print the total number of valid partitions.
4. Free all dynamically allocated memory.

---

## Example Usage

### Input:
```c
char matrix[MAX_R][MAX_C] = {
    {'F', 'O', 'O', 'F'},
    {'O', 'F', 'O', 'F'},
    {'F', 'O', 'O', 'F'}
};
int rows = 3, cols = 4, num_parts = 3;
find_partition(matrix, rows, cols, num_parts);
```

### Output:
```
Partitions:
{{(0,0), (0,1), (0,2), (1,1)}, {(1,0), (2,0), (2,1), (2,2)}, {(0,3), (1,2), (1,3), (2,3)}}
...
Total Solutions: X
```

---

## Complexity

1. **Time Complexity**:
   - Exponential due to recursive exploration of all possible assignments.

2. **Space Complexity**:
   - Proportional to the number of cells in the matrix and the number of subsets.

---

## Edge Cases
1. **Matrix with Wildcards Only**:
   - All cells are `'*'`.
   - Any valid partition is acceptable.

2. **Single Subset**:
   - Input: `num_parts = 1`.
   - Output: Entire matrix in a single subset.

3. **Impossible Partition**:
   - Input: `num_parts > rows * cols`.
   - Output: No solutions.

---

## Extensions
1. **Dynamic Programming**:
   - Optimize by caching intermediate results to avoid redundant computations.

2. **Custom Rules**:
   - Add constraints for partition sizes or specific letter distributions.

3. **Parallelization**:
   - Parallelize the recursive calls to improve performance for large matrices.

---

## Conclusion
The `find_partition` function systematically explores all valid ways to partition a matrix into subsets with identical letter distributions, including wildcards. It uses recursion and backtracking to ensure correctness and completeness while maintaining flexibility for various input scenarios.

