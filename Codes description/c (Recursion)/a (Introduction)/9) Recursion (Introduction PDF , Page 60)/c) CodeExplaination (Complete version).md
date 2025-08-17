#GCD Calculation Program

## Overview
This program demonstrates the use of recursion to calculate the Greatest Common Divisor (GCD) of two integers using the Euclidean algorithm. It is implemented in C and consists of two main components:
1. The `gcd` function: A recursive function that calculates the GCD of two given numbers.
2. The `main` function: A function that takes user input, calls the `gcd` function, and displays the result.

## Function Descriptions

### 1. `gcd` Function
The `gcd` function is designed to find the greatest common divisor of two integers using the Euclidean algorithm. It follows these steps:
- **Input Parameters**: Takes two integers (`x` and `y`) as input.
- **Base Case**: If the two numbers are equal (`x == y`), the function returns `x` (or `y`), as that value is the GCD.
- **Recursive Step**: If `x` is greater than `y`, the function calls itself with the arguments `x - y` and `y`. If `y` is greater than `x`, it calls itself with `x` and `y - x`.
- **Recursive Reduction**: This process of reduction continues until the two numbers are equal, at which point the GCD is returned.

The recursive nature of the function makes the implementation elegant and easy to follow, allowing the problem to be solved by continuously reducing the input values until a solution is found.

### 2. `main` Function
The `main` function handles user interaction and demonstrates the usage of the `gcd` function:
- **User Input**: Prompts the user to input two integers (`x` and `y`).
- **GCD Calculation**: Calls the `gcd` function with the provided values to compute their GCD.
- **Output**: Prints the result of the GCD calculation to the console, providing a clear demonstration of the recursive function in action.

The `main` function serves as a simple interface for the user to understand and use the GCD calculation, while showcasing the power of recursion.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc gcd_function_code.c -o gcd_function
./gcd_function
```

### Expected Output
The program will prompt the user to input two numbers and then display their GCD. For example:

```
Input x and y: 48 18
gcd of 48 and 18: 6
```

## Summary
The GCD calculation program is a straightforward demonstration of how recursion can be used to solve a classic mathematical problem. The **`gcd` function** uses the Euclidean algorithm, which is an efficient method for computing the GCD by reducing the problem size at each step until the solution is found.

The **`main` function** provides a simple user interface to input values and view the result, making the program accessible for anyone looking to understand how recursion works in practice. By breaking down the problem into smaller subproblems, the recursive approach not only simplifies the code but also illustrates the elegance of recursive solutions for problems involving repeated calculations.

This program is an excellent resource for learning about recursion, the Euclidean algorithm, and how to apply these concepts in C programming.

