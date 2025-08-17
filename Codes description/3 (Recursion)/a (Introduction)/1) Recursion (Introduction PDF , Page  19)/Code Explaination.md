# Recursive Print Demo

## Overview
This program demonstrates the use of recursion to print segments of an array. It contains two different versions of a function (`show1` and `show2`) that are used to recursively display segments of an integer array. The primary purpose is to highlight how the order of operations within a recursive function affects its behavior and output.

## Functions Explained

### 1. `show1` Function
The `show1` function is a recursive function that takes three parameters:
- `v[]`: The array of integers to be printed.
- `l`: The starting index of the segment.
- `r`: The ending index of the segment.

#### Key Characteristics:
- **Printing Before Base Case Check**: The `show1` function prints the segment of the array before checking if it has reached the base case (`l >= r`).
- **Always Prints Segments**: Since the printing happens before the base case check, it always prints the segment even when `l == r`, meaning it will also print single-element segments.
- **Recursive Calls**: After printing the current segment, it finds the midpoint (`c = (r + l) / 2`) and recursively calls itself to process the left and right halves of the array.

### 2. `show2` Function
The `show2` function is also a recursive function that takes the same parameters as `show1`.

#### Key Characteristics:
- **Base Case Check Before Printing**: In `show2`, the base case (`l >= r`) is checked before any printing occurs. If the base case is met, the function returns immediately.
- **Avoids Printing Single-Element Segments**: Since the base case check is done first, the function only prints segments where `l < r`. This results in fewer lines of output compared to `show1`, as it avoids printing single-element segments.
- **Recursive Calls**: Similar to `show1`, it finds the midpoint and recursively processes the left and right halves of the array.

## Main Function
The `main()` function is used to demonstrate the difference between `show1` and `show2`. It defines an integer array (`v[] = {1, 2, 3, 4, 5}`) and calls both versions of the `show` function to illustrate their different behaviors.

### Demonstration Steps:
1. **Output of `show1`**: The function prints the array segments even in the base case, resulting in more detailed output, including single-element segments.
2. **Output of `show2`**: The function skips printing when the base case is reached, resulting in fewer lines of output, focusing only on segments where `l < r`.

## Compilation and Execution
To compile and execute the program, use the following commands in your terminal:

```sh
gcc recursive_print_demo.c -o recursive_print_demo
./recursive_print_demo
```

### Expected Output
The output will show the difference in behavior between `show1` and `show2`:

```
--- Output of show1 (Prints even in base case) ---
v = 1 2 3 4 5
v = 1 2 3
v = 1 2
v = 1
v = 2
v = 3
v = 4 5
v = 4
v = 5

--- Output of show2 (Skips printing in base case) ---
v = 1 2 3 4 5
v = 1 2 3
v = 1 2
v = 4 5
```

## Summary
The key difference between `show1` and `show2` is in the order of operations:
- **`show1`** prints the segment before checking if it has reached the base case, resulting in more detailed output, including single-element segments.
- **`show2`** checks the base case before printing, which results in fewer printed segments and avoids single-element outputs.

This simple modification in the order of operations has a significant impact on the behavior of the recursive function and the amount of output produced. Understanding these differences is crucial when designing recursive functions, as the placement of base case checks and operations can change the outcome drastically.

