# Combinations with Repetition Program

## Overview
This program demonstrates how to generate all possible combinations of a given set of values, allowing repetition, using recursion. In combinatorics, combinations with repetition are selections of items where each item can be chosen more than once, and the order of selection does not matter. The program generates and prints all possible combinations of a specified length (`k`) from an input set of values (`val`).

The program is implemented in C and includes two main components:
1. **`arr_rep` Function**: A recursive function that generates all possible combinations of the given values, allowing repetition.
2. **`main` Function**: A function that initializes the input set and calls `arr_rep` to generate and print all combinations.

## Function Descriptions

### 1. `arr_rep` Function
The `arr_rep` function is responsible for generating all possible combinations of the given set of values, allowing repetition.
- **Input Parameters**:
  - **`val`**: The input set of values from which combinations are generated.
  - **`sol`**: An array used to store the current combination.
  - **`n`**: The total number of elements in the input set.
  - **`k`**: The length of each combination to be generated.
  - **`count`**: A counter used to keep track of the total number of combinations generated.
  - **`pos`**: The current position in the combination being constructed.

- **Recursive Approach**:
  - The function starts by checking if the current position (`pos`) is equal to or greater than the length of the combination (`k`). If so, it prints the current combination and increments the count.
  - Otherwise, the function iterates over all values in the input set (`val`). Each value is added to the current position in the combination (`sol`), and the function recurses to the next position.

The `arr_rep` function systematically explores all possible combinations of the input set, allowing for repetitions in each combination. The recursive approach provides a clear and concise method for exploring all options.

### 2. `main` Function
The `main` function serves as the entry point for the program and is responsible for setting up the initial data required for generating combinations.
- **Array Initialization**:
  - The input set of values (`val`) is initialized with the numbers `{1, 2, 3}`.
  - The solution array (`sol`) is allocated to store the current combination being generated.

- **Generating Combinations**:
  - The `arr_rep` function is called with the initialized arrays to generate all combinations of a specified length (`k`). In this example, `k` is set to `2`.

- **Printing Results**:
  - The program prints all generated combinations and the total count of combinations.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc main.c -o combinations_program
./combinations_program
```

### Expected Output
The program will print all possible combinations of the given length (`k`) from the input set, allowing for repetition. For example:

```
All combinations with repetition of length 2:
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2
3 3
Total combinations: 9
```

## Summary
The combinations with repetition program is a practical demonstration of using recursion to explore combinatorial possibilities. The **`arr_rep` function** generates all possible combinations of a given length, allowing values to be repeated. This function systematically iterates over each value in the input set, recursively constructing all possible combinations and printing them.

The **`main` function** provides a straightforward demonstration by initializing the input set, invoking the recursive function, and managing the generated combinations. This recursive approach simplifies the process of generating combinations, making the program a useful educational tool for understanding recursion and combinatorics with repetition.

## Code Summary
The program begins by initializing the input set and solution array (`sol`). The recursive **`arr_rep`** function is then called to generate all possible combinations, allowing repetition of values. Each time a complete combination is formed, it is printed to the console, and the recursive function continues to explore other possible combinations. The program also prints the total number of combinations generated, providing a complete overview of the possibilities.

This program is ideal for those looking to understand the fundamentals of combinations with repetition, recursion, and how to apply these concepts in practical programming scenarios.

