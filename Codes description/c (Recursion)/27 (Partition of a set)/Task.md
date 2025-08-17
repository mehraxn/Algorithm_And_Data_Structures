# Partition of a Set - Specifications and Instructions

## Overview
The "Partition of a Set" task involves generating all possible partitions of a given set of elements. A partition of a set divides the elements into non-empty blocks that are pairwise disjoint and collectively form the original set.

In this task, you will write a program that partitions a set of elements into different blocks, following specific rules of disjoint sets and their union.

## Problem Definition
Given a set `S` of `n` elements, a collection `S = {S_i}` of non-empty blocks forms a partition of `S` if and only if both of the following conditions hold:

1. **Blocks are pairwise disjoint**:
   - For any `S_i, S_j` with `i ≠ j`, we have `S_i ∩ S_j = ∅`.

2. **Their union is `S`**:
   - `S = ∪_i S_i`.

The number of blocks `k` ranges from 1 to `n`.

### Example
Given a set `S = {1, 2, 3, 4}`, there are 14 possibilities to partition the elements into two sets. Each partition indicates the block to which each element belongs. Below is an example representation of the partitions:

- **Partition 1**: `{0001} -> {123} {4}`
- **Partition 2**: `{0010} -> {124} {3}`
- **Partition 3**: `{0100} -> {134} {2}`
- **Partition 4**: `{1000} -> {1234}` (single block)

There are **7 unique partitions** after considering symmetries.

## Task Description
1. **Input**: The input consists of a set of `n` elements, and a desired number of blocks `k`.
2. **Output**: The program prints all possible partitions of the given set into `k` blocks.
3. **Specifications**: The program should generate all possible partitions of the given set without worrying about symmetric blocks.

## Solution Approach
The solution uses a recursive function to generate all possible partitions by assigning each element of the set to one of the `k` blocks. The approach iteratively generates all combinations of element assignments.

1. **Recursive Function (`partition`)**:
   - The function takes an array of values representing the elements to be partitioned, an array for tracking which block each element belongs to, and parameters representing the current state of the partition generation.
   - It assigns each element to one of the `k` blocks and recursively continues until all elements have been assigned.
   - When all elements are assigned, it checks if the blocks are non-empty and then prints the partition.

## Code Structure
- The code starts by defining the set of elements and initializing an array to store the solution.
- The main function initializes the values and calls the recursive function (`partition`) to generate all partitions.
- The `partition` function handles the recursive generation of partitions and prints each valid partition to standard output.

## Running the Program
1. **Compilation**: Compile the code using a C compiler, for example:
   ```
   gcc partition_of_set.c -o partition_of_set
   ```

2. **Execution**: Run the compiled program:
   ```
   ./partition_of_set
   ```
   The program will generate and print all possible partitions of the set `{1, 2, 3, 4}` into `k` blocks.

## Notes
- The program dynamically allocates memory for storing the occurrences of each block. This helps in checking if all blocks are non-empty before printing the partition.
- The task of partitioning a set into `k` blocks can become computationally expensive for larger values of `n` and `k` due to the rapid growth in the number of possible partitions.
- The program provides an excellent opportunity to understand recursion, combinatorics, and the concept of set partitioning.

## Conclusion
The partition of a set is a classic problem in combinatorics, where the objective is to divide a set into non-empty subsets that are disjoint and collectively form the original set. This task demonstrates the application of recursion and partitioning techniques to generate all possible partitions, offering valuable insight into combinatorial problem-solving.

