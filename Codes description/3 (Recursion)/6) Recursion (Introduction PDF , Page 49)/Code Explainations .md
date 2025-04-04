# Reverse String Program

## Overview
This program is designed to demonstrate the use of recursion for string manipulation. Specifically, it reverses and prints a user-provided string. The key components of the program are:
1. The `reverse_print` function: A recursive function that prints a string in reverse order.
2. The `main` function: A function that takes user input and calls `reverse_print` to display the reversed string.

## Function Descriptions

### 1. `reverse_print` Function
The `reverse_print` function is the core of the program, responsible for printing a given string in reverse order. It follows these steps:
- **Input Parameter**: Takes a character pointer (`s`) which represents the string to be reversed.
- **Base Case**: If the current character is the null terminator (`\0`), it means the end of the string has been reached, and the function simply returns.
- **Recursive Call**: The function calls itself with the next character (`s + 1`) before printing the current character.
- **Printing After Recursion**: The character is printed only after all subsequent characters have been processed by the recursive call, effectively reversing the order of the output.

This function demonstrates how recursion can be used to solve problems that involve sequential processing, such as reversing a string. By traversing the entire string until the null terminator and then printing each character during the return phase, the string is effectively printed in reverse.

### 2. `main` Function
The `main` function is responsible for handling user interaction and invoking the reverse print function:
- **User Input**: It prompts the user to input a string. The input is stored in a character array (`str`) of size `MAX + 1` to ensure it can accommodate the entered string plus the null terminator.
- **Reverse Printing**: After reading the input, the `main` function calls `reverse_print` to print the string in reverse order.
- **Output**: The program then prints a newline character for better readability.

The `main` function showcases the use of recursion in practical scenarios by connecting user input to the recursive function that performs the main task.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc reverse_string_functions.c -o reverse_string
./reverse_string
```

### Expected Output
The program will prompt the user to enter a string and then display the reversed string:

```
Input string: hello
Reverse string is: olleh
```

## Summary
The reverse string program is a simple demonstration of using recursion for string manipulation. The **`reverse_print`** function uses recursion to traverse to the end of the string and then prints each character in reverse order as it returns back through the recursive calls. The **`main`** function handles user input and calls `reverse_print` to demonstrate the functionality.

This program serves as a useful example of how recursion can be used effectively to solve problems involving sequential data, such as reversing a string. The recursive approach allows for elegant and concise solutions to problems that can be broken down into smaller sub-problems, making it a valuable concept in programming.

