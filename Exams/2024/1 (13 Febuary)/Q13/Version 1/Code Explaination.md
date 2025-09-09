# README: Load Truck Optimization Program

## Overview
This program solves the problem of maximizing the value of parcels loaded onto a truck, given constraints on the truck’s load capacity. It uses a recursive powerset approach to evaluate all possible combinations of parcels and identifies the combination with the highest total value that fits within the truck's weight capacity.

## Problem Statement
Given:
- An array of weights of parcels.
- An array of corresponding values of parcels.
- A maximum load capacity of the truck.

The goal is to determine which parcels to load onto the truck such that the total value of the selected parcels is maximized, while ensuring the total weight does not exceed the truck's capacity.

## Functionalities
The program includes the following components:

### Main Function (`main`)
1. Initializes arrays `weight` and `value` with the weights and values of parcels.
2. Defines the number of parcels (`n`) and the maximum load capacity of the truck (`load`).
3. Calls the `load_truck` function to compute the solution.
4. Prints the result and terminates successfully.

### `load_truck`
This function serves as a wrapper for the recursive powerset function and manages memory allocation for intermediate solutions.

#### Parameters:
- `weight`: Pointer to the array of parcel weights.
- `value`: Pointer to the array of parcel values.
- `n`: Number of parcels.
- `load`: Maximum load capacity of the truck.

#### Process:
1. Allocates memory for two arrays:
   - `solution`: Tracks the current combination of parcels being evaluated.
   - `best_solution`: Stores the combination of parcels with the highest value found so far.
2. Iteratively invokes the recursive function `powerset_r` for combinations of sizes ranging from 1 to `n`.
3. Prints the indices of parcels in the best solution.
4. Frees allocated memory and returns.

### `powerset_r`
This recursive function explores all combinations of parcels and evaluates their total weight and value.

#### Parameters:
- `weight`: Pointer to the array of parcel weights.
- `value`: Pointer to the array of parcel values.
- `n`: Number of parcels.
- `load`: Maximum load capacity of the truck.
- `solution`: Array storing the current combination of parcel indices.
- `i`: Current size of the combination being evaluated.
- `pos`: Current position in the `solution` array.
- `start`: Starting index for the next parcel to include in the combination.
- `best_value`: Pointer to the highest total value found so far.
- `best_solution`: Pointer to the array storing the best combination of parcels.
- `best_size`: Pointer to the size of the best solution.

#### Process:
1. **Base Case:**
   - If the size of the current combination (`pos`) equals `i`:
     - Calculate the total weight (`w`) and total value (`v`) of the parcels in `solution`.
     - If the total weight is within the truck's capacity and the total value exceeds the current `best_value`:
       - Update `best_value`.
       - Copy the current `solution` to `best_solution`.
       - Update `best_size`.
     - Return to explore other combinations.

2. **Recursive Case:**
   - Iterate through the indices of remaining parcels starting from `start`.
   - Add the current parcel index to `solution`.
   - Recur with the next position in `solution`, advancing the starting index.

## Example
**Input:**
- `weight = {10.0, 15.0, 25.5, 39.5, 17.0}`
- `value = {19.99, 9.50, 15.00, 27.50, 11.40}`
- `n = 5`
- `load = 50`

**Output:**
```
Solution: 0 3
```

**Explanation:**
- The best combination is parcels 0 and 3.
- Total weight: 10.0 + 39.5 = 49.5 (within capacity).
- Total value: 19.99 + 27.50 = 47.49 (maximum value).

## Data Structures
### Arrays:
- `weight` and `value` store the weights and values of parcels.
- `solution` temporarily stores indices of the current combination.
- `best_solution` permanently stores indices of the best combination.

### Variables:
- `best_value`: Tracks the maximum value of parcels found.
- `best_size`: Tracks the number of parcels in the best solution.

## Key Logic
The program uses a recursive powerset algorithm to explore all subsets of the parcels. It leverages backtracking to build and evaluate each combination, updating the best solution dynamically.

## Memory Management
- Dynamic memory allocation (`calloc`) is used for `solution` and `best_solution` arrays.
- Proper error handling ensures the program exits if memory allocation fails.
- Allocated memory is freed after use.

## Limitations
- The program may become slow for a large number of parcels due to the exponential time complexity of generating all subsets.
- Assumes input arrays are valid and properly sized.

## Compilation and Execution
1. Save the code to a file (e.g., `load_truck.c`).
2. Compile the program using a C compiler:
   ```bash
   gcc -o load_truck load_truck.c
   ```
3. Run the executable:
   ```bash
   ./load_truck
   ```

## Conclusion
This program provides an effective solution for maximizing the value of parcels loaded onto a truck under weight constraints. It demonstrates the use of recursive algorithms and dynamic memory management in C to solve combinatorial optimization problems.

