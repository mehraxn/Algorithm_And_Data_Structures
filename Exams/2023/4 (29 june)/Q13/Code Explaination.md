# README: Partitioning Algorithm Program

## Overview
This program partitions an array into `k` subsets such that:
1. Each subset satisfies the constraint `(n/k) <= size <= (n/k) + 1`.
2. The variance of the sums of elements in the subsets is minimized.

The program uses a recursive approach to generate all possible valid partitions and selects the one that minimizes the variance of subset sums.

---

## Features
- Generates all possible partitions of an array into `k` subsets.
- Ensures subset sizes meet the specified constraints.
- Selects the partition with the minimum variance of subset sums.
- Outputs the optimal partition and its subsets.

---

## Code Structure
### Main Functions

#### 1. **main**
```c
int main();
```
- **Purpose**: Entry point of the program.
- **Logic**:
  - Initializes the input array.
  - Calls the `partition` function to compute and display the optimal partition.

#### 2. **partition**
```c
void partition(int *vet, int n, int k);
```
- **Purpose**: Initializes partitioning by allocating necessary arrays and calling the recursive partitioning function.
- **Parameters**:
  - `vet`: The input array to be partitioned.
  - `n`: The size of the input array.
  - `k`: The number of partitions.
- **Logic**:
  - Allocates arrays for tracking partitions and the best partition.
  - Calls `assign_partitions` to begin recursive partitioning.
  - Outputs the optimal partition and its subsets.

#### 3. **assign_partitions**
```c
void assign_partitions(int *vet, int n, int k, int *partitions, int *best_partitions);
```
- **Purpose**: Wrapper function for recursive partition assignment.
- **Parameters**:
  - `vet`: The input array.
  - `n`: The size of the input array.
  - `k`: The number of partitions.
  - `partitions`: Array to track current partition assignments.
  - `best_partitions`: Array to store the best partition found.
- **Logic**:
  - Initializes the best variance as an invalid value.
  - Calls the recursive function `assign_partitions_r`.

#### 4. **assign_partitions_r**
```c
void assign_partitions_r(int *vet, int n, int k, int *partitions, int *best_partitions, float *best_var, int pos);
```
- **Purpose**: Recursively generates all possible partitions.
- **Parameters**:
  - `vet`: The input array.
  - `n`: The size of the input array.
  - `k`: The number of partitions.
  - `partitions`: Array to track current partition assignments.
  - `best_partitions`: Array to store the best partition found.
  - `best_var`: Pointer to the current best variance.
  - `pos`: Current position in the input array being partitioned.
- **Logic**:
  - Checks if the base case (`pos == n`) is reached.
  - Evaluates the partition if it satisfies size constraints and updates the best partition if its variance is smaller.
  - Explores all possible partition assignments for the current position.

#### 5. **check_suitable_partition_sizes**
```c
int check_suitable_partition_sizes(int *partitions, int n, int k);
```
- **Purpose**: Ensures each partition meets the size constraints.
- **Parameters**:
  - `partitions`: Array of partition assignments.
  - `n`: Size of the input array.
  - `k`: Number of partitions.
- **Logic**:
  - Counts the number of elements in each partition.
  - Verifies the count lies between `(n/k)` and `(n/k) + 1`.
- **Returns**: `1` if constraints are met; `0` otherwise.

#### 6. **variance**
```c
float variance(int *vet, int *partitions, int n, int k);
```
- **Purpose**: Computes the variance of subset sums for a given partition.
- **Parameters**:
  - `vet`: The input array.
  - `partitions`: Array of partition assignments.
  - `n`: Size of the input array.
  - `k`: Number of partitions.
- **Logic**:
  - Computes the sum of elements in each partition.
  - Calculates the average and variance of these sums.
- **Returns**: The variance of the subset sums.

#### 7. **copy_partitions**
```c
void copy_partitions(int *part, int *best, int n);
```
- **Purpose**: Copies the current partition into the best partition array.
- **Parameters**:
  - `part`: Current partition array.
  - `best`: Array to store the best partition.
  - `n`: Size of the input array.

---

### Supporting Logic
#### Partitioning Constraints
- Each partition must have a size between `(n/k)` and `(n/k) + 1`.
- This ensures an even distribution of elements across partitions.

#### Variance Calculation
Variance is computed to ensure the sums of elements in the partitions are as close as possible. Lower variance indicates a better partition.

---

## Example Execution

### Input
- `vet`: `{1, 2, 3, 4, 5}`
- `k`: `4`

### Output
```
partition 1: 1
partition 2: 2
partition 3: 3
partition 4: 4 5
```

### Explanation
The program partitions the array into 4 subsets such that:
- Each subset satisfies size constraints.
- The variance of subset sums is minimized.

---

## Limitations
- **Brute-Force Nature**: The recursive approach generates all possible partitions, which can be computationally expensive for large arrays or large values of `k`.
- **No Dynamic Input**: Input values are hardcoded in the `main` function.

---

## Future Improvements
- Implement dynamic programming to optimize partition generation.
- Allow user input for the array and the number of partitions.
- Enhance variance computation to include other statistical measures.
- Include additional constraints, such as balancing partitions by weight or other criteria.

---

## How to Compile and Run
1. Save the code in a file (e.g., `partitioning.c`).
2. Compile the program:
   ```bash
   gcc -o partitioning partitioning.c
   ```
3. Run the program:
   ```bash
   ./partitioning
   ```

