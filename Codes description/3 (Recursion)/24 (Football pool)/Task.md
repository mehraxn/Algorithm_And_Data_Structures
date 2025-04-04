# Football Pool - Classic Recursive Problem

## Overview
The "Football Pool" problem is a classic recursive programming task that involves generating all possible match outcomes given a specific input format. In this problem, we work with three possible results for a football match:

- **1**: Home team wins.
- **2**: Home team loses.
- **X**: Draw.

The task requires a recursive program to manipulate a football system, where a list of possible match results is stored in a file, and the program generates all possible patterns based on these outcomes.

## Task Description
1. **Input**: The input file contains several lines, each representing possible outcomes for a match. For example, a line containing "1X2" represents that the home team can either win (1), draw (X), or lose (2).

2. **Output**: The program generates all possible combinations of outcomes for each match specified in the input file.

   For example, given the input:
   ```
   1
   X2
   2
   12X
   ```
   The program must generate combinations like "11X21", "11X22", etc., covering all possible match outcomes for all rows.

3. **Format**: The program reads the file name from standard input, and then generates the output by expanding each possible outcome for every match.

## Code Explanation
The provided C code implements the solution using recursive functions to generate all possible combinations:

1. **Main Program (`main`)**: Reads the input file and stores the data into an array (`scheme`). It then prompts the user for an output file name, where the results will be written. Memory is allocated for storing each possible outcome for each row.

2. **`read_file()` Function**: This function reads the input file and stores the possible outcomes of each match. It counts the number of rows and allocates memory accordingly, storing each outcome line.

3. **Recursive Function (`play_r`)**: The function `play_r()` generates all possible combinations by recursively exploring every character in each line of the input (`scheme`). It stores the generated combination in `column` and writes it to the output file once all matches are processed.

## Running the Program
1. **Compilation**: Compile the code using a C compiler, for example:
   ```
   gcc football_pool.c -o football_pool
   ```

2. **Execution**: Run the compiled program:
   ```
   ./football_pool
   ```
   The program will prompt for the input and output file names:
   - **Input file**: Contains possible outcomes for each match.
   - **Output file**: Will store all possible combinations of match outcomes.

## Example
Consider an input file `matches.txt` with the following content:
```
1
X2
2
12X
```
After running the program and providing `matches.txt` as input, it will generate an output file containing all possible combinations:
```
11X21
11X22
11221
...
```

## Notes
- The program dynamically allocates memory for storing the possible outcomes and combinations. It is crucial to handle memory allocation errors appropriately, as shown in the code.
- The recursive approach ensures that every combination is covered by iterating through each possible character for each row in the input file.
- This program demonstrates the power of recursion in systematically exploring every potential outcome in problems with combinatorial possibilities.

## Limitations
- The program does not handle excessively large input files efficiently, as the recursive approach can lead to significant memory usage and stack depth, potentially resulting in a stack overflow for large inputs.

## Conclusion
This recursive solution to the "Football Pool" problem provides a structured way to generate all possible match outcomes given a set of potential results. It is a good exercise in understanding recursion and handling dynamic memory allocation in C.

