#Tower of Hanoi Program

## Overview
This program solves the classic Tower of Hanoi problem using recursion. The Tower of Hanoi is a well-known mathematical puzzle involving three pegs and a number of disks of different sizes. The goal is to move all the disks from the source peg to the destination peg, following these rules:
- Only one disk can be moved at a time.
- Each move consists of taking the upper disk from one of the stacks and placing it on another peg.
- No larger disk may be placed on top of a smaller disk.

The program includes two main components:
1. **`hanoi` Function**: A recursive function that performs the moves to solve the Tower of Hanoi problem.
2. **`main` Function**: A function that initializes the problem for a specific number of disks and calls the `hanoi` function.

## Function Descriptions

### 1. `hanoi` Function
The `hanoi` function is responsible for recursively solving the Tower of Hanoi problem. It takes the following parameters:
- **`n`**: The number of disks to be moved.
- **`src`**: The source peg from which disks are to be moved.
- **`dest`**: The destination peg where disks are to be moved.

The function follows these steps:
- **Termination Condition**: If `n` is less than or equal to `0`, the function returns without performing any operations. This serves as the base case for the recursion.
- **Determine Auxiliary Peg**: The function calculates the auxiliary peg (`aux`) using the formula `aux = 3 - (src + dest)`. The auxiliary peg is used to assist in moving the disks.
- **Recursive Steps**:
  1. First, it moves `n-1` disks from the source peg (`src`) to the auxiliary peg (`aux`), using the destination peg (`dest`) as a temporary holder.
  2. Then, it moves the nth (largest) disk directly from the source peg (`src`) to the destination peg (`dest`).
  3. Finally, it moves the `n-1` disks from the auxiliary peg (`aux`) to the destination peg (`dest`).

This recursive approach effectively breaks down the problem into smaller subproblems until the entire stack of disks is moved from the source peg to the destination peg.

### 2. `main` Function
The `main` function serves as the entry point for the program. It performs the following tasks:
- **Initialization**: Calls the `hanoi` function with `3` disks, specifying peg `0` as the source peg and peg `2` as the destination peg.
- **Output**: The `hanoi` function prints each move step-by-step to the console, clearly demonstrating how the disks are moved from the source peg to the destination peg according to the rules of the Tower of Hanoi.

## How to Compile and Run the Program
To compile and run the program, use the following commands in your terminal:

```sh
gcc tower_of_hanoi.c -o tower_of_hanoi
./tower_of_hanoi
```

### Expected Output
The program will print the steps required to move `3` disks from peg `0` to peg `2`:

```
Disk 1 from peg 0 to peg 2
Disk 2 from peg 0 to peg 1
Disk 1 from peg 2 to peg 1
Disk 3 from peg 0 to peg 2
Disk 1 from peg 1 to peg 0
Disk 2 from peg 1 to peg 2
Disk 1 from peg 0 to peg 2
```

This output shows the order in which the disks are moved to solve the Tower of Hanoi problem for 3 disks.

## Summary
The Tower of Hanoi program is a classic example of using recursion to solve a mathematical problem. The **`hanoi` function** breaks the problem into smaller subproblems, using an auxiliary peg to help move the disks step-by-step until the entire stack is transferred to the destination peg.

The **`main` function** initializes the problem for 3 disks and demonstrates the solution by calling the `hanoi` function. The step-by-step output provides a clear visualization of how the recursive solution works.

This program is an excellent demonstration of the power of recursion, particularly for problems that involve breaking down a task into similar sub-tasks. The Tower of Hanoi is often used as an educational example to teach the concept of recursion, problem decomposition, and algorithm design.