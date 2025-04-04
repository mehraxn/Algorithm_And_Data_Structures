#Fibonacci Calculation Program

## Overview
This program demonstrates two different implementations of a recursive function to calculate the Fibonacci sequence. The program includes two versions (`fib_v1` and `fib_v2`) of the Fibonacci function, both of which use recursion to calculate the Fibonacci value for a given number `n`. The main objective is to show how the same problem can be solved using different yet equivalent implementations and to verify that both produce identical results.

## Function Descriptions

### 1. `fib_v1` Function
The `fib_v1` function is designed to calculate the nth Fibonacci number using a simple recursive approach. It follows these steps:
- **Base Cases**: If `n` is `0` or `1`, the function returns `n`. These are the base cases, as the Fibonacci sequence starts with `0` and `1`.
- **Recursive Step**: For any other value of `n`, it returns the sum of `fib_v1(n - 2)` and `fib_v1(n - 1)`. This breaks the problem into smaller sub-problems until the base case is reached.

This straightforward implementation effectively reduces the problem size through recursive calls until the base cases are met.

### 2. `fib_v2` Function
The `fib_v2` function also calculates the nth Fibonacci number using recursion and follows the same logic as `fib_v1`. The key steps are:
- **Base Cases**: If `n` is `0` or `1`, the function returns `n`.
- **Recursive Step**: It calculates the sum of `fib_v2(n - 2)` and `fib_v2(n - 1)` to obtain the nth Fibonacci number.

This version is presented as an alternative implementation for demonstration purposes, highlighting that different versions can solve the same problem using similar logic.

### 3. `main` Function
The `main` function is responsible for interacting with the user and demonstrating the use of both Fibonacci versions:
- **Input Handling**: It prompts the user to input a value for `n`.
- **Calculation**: It calls both `fib_v1` and `fib_v2` to calculate the Fibonacci value of `n`.
- **Output**: It prints the results obtained from both functions and verifies that they match.
- **Verification**: If both versions produce the same result, the program prints a confirmation message. Otherwise, it indicates an error.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc fibonacci_functions.c -o fibonacci_functions
./fibonacci_functions
```

### Expected Output
The program will prompt the user to enter a number (`n`) and then display the Fibonacci number calculated by both versions of the function. It will also verify that both versions produce the same result:

```
Input n: 5
Version 1: Fibonacci of 5 is: 5
Version 2: Fibonacci of 5 is: 5
Both versions produce the same result: 5
```

## Summary
The Fibonacci calculation program is designed to illustrate the concept of recursion for calculating the Fibonacci sequence. It uses two slightly different recursive implementations (`fib_v1` and `fib_v2`) to solve the same problem. The `main` function demonstrates the functionality of both versions, verifying that they produce identical outputs.

Both `fib_v1` and `fib_v2` follow the same logic, where the problem is broken down recursively until the base cases are reached. The key takeaway from this program is understanding how recursive functions can be used to solve problems involving sequences and how equivalent implementations can be designed to achieve the same result.

This program also serves as a useful learning tool for understanding recursion, problem-solving, and the Fibonacci sequence, providing a clear example of how different implementations can be compared and validated.

