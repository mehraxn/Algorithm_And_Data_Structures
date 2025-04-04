# README for String Length Functions in C

## Overview
This project contains four different implementations of a function to calculate the length of a string in the C programming language. Each function uses a different technique involving pointers or array indexing to determine the length of the given string. The primary purpose of this project is to demonstrate the flexibility of C in handling strings and pointers, showcasing multiple approaches that yield the same result.

## Functions
The program consists of four functions, all named `strlen1`, `strlen2`, `strlen3`, and `strlen4`, each of which takes a string as input and returns its length. These functions are implemented differently, and their details are provided below:

### Function 1: `strlen1(char str[])`
This function uses **array indexing** to determine the length of the string. It iterates through the characters of the string using an index variable (`cnt`) until it finds the null character (`'\0'`). The number of iterations is equal to the length of the string.

### Function 2: `strlen2(char *str)`
This function uses **pointer increment** to traverse the string. It keeps moving the pointer (`str`) and increments a counter (`cnt`) until the null character is found. This approach highlights the use of pointers as an alternative to array indexing.

### Function 3: `strlen3(char str[])`
This function uses a **pointer variable** (`p`) to traverse the string, starting by pointing to the first character of the string. The pointer is incremented in a loop until the null character is reached. A counter variable (`cnt`) is used to keep track of the number of characters in the string.

### Function 4: `strlen4(char *str)`
This function utilizes **pointer arithmetic** to calculate the length of the string. The pointer (`p`) starts at the beginning of the string and is incremented until the null character is found. The difference between the final pointer position and the initial pointer (`str`) gives the length of the string.

## How to Run the Code
To run the code, compile it using a C compiler (e.g., `gcc`) and execute the resulting binary. Here are the steps to compile and run the code:

```sh
gcc string_length_functions.c -o string_length_functions
./string_length_functions
```

Upon running, the program will print the length of the input string calculated by each of the four functions.

### Example Output
```
Length of the string using strlen1: 13
Length of the string using strlen2: 13
Length of the string using strlen3: 13
Length of the string using strlen4: 13
```

## Explanation of Results
All four functions calculate the length of the same string, and each one returns the same value. This demonstrates that different approaches involving array indexing and pointers can be used interchangeably to achieve the same outcome.

## Key Concepts Demonstrated
- **Array Indexing**: Accessing string elements using an index.
- **Pointers**: Using pointers to traverse and manipulate strings.
- **Pointer Arithmetic**: Calculating distances between pointers to determine lengths.

## Learning Objectives
By studying and running this code, you will:
- Understand different techniques to traverse strings in C.
- Learn how pointers and arrays can be used interchangeably in many scenarios.
- Gain insight into the use of pointers for arithmetic operations.

## Prerequisites
- Basic knowledge of C programming.
- Understanding of arrays, pointers, and strings.

## Conclusion
This project provides four different approaches to calculate the length of a string, all of which demonstrate the versatility of pointers and array indexing in C. By understanding these implementations, you will gain a deeper insight into how memory manipulation and string operations can be performed in different ways.

Feel free to experiment with the code and modify the functions to deepen your understanding of pointers and strings in C.

