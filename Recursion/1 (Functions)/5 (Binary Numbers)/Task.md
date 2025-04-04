# Binary Numbers Generation Task

## Specifications

The goal of this task is to write a program that generates binary numbers with **n** bits, where **n** is provided as input by the user. The program should read **n** from standard input and generate all possible binary numbers of that length.

### Example
- If **n = 3**, the program should generate and print all the possible 3-bit binary numbers, such as:
  
  ```
  000, 001, 010, 011, 100, 101, 110, 111
  ```
  
  The order of the binary numbers does not matter.

### Important Notes
- The program **does not need to perform numeric conversions** (such as from decimal to binary). Instead, it should generate binary numbers directly using a **recursive approach**.

## Solution Approach

The solution requires that:
- All binary numbers should be printed out with **n** bits.
- Bits should be stored in an array of length **n**.
- Since the value of **n** is provided during runtime, the array must be **dynamically allocated**.

### Recursive Method
- The solution will make use of a **recursive function** to generate binary numbers.
- With **n = 3** as an example, the program would recursively generate each combination, effectively building a **recursion tree** that explores every possible bit combination.

### Summary of Requirements
- The program should take **n** as input from the user.
- Generate all possible binary numbers of **n** bits using recursion.
- **Dynamically allocate** an array to hold the bits.
- Print each generated binary number, ensuring it contains exactly **n** bits.

