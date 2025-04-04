#include <stdio.h>

// Function to solve the Tower of Hanoi problem
// This function moves `n` disks from the source peg (`src`) to the destination peg (`dest`) using an auxiliary peg (`aux`).
void hanoi(int n, int src, int dest) {
    int aux;

    // Termination condition: if there are no disks to move, return
    if (n <= 0) {
        return;
    }

    // Determine the auxiliary peg (0, 1, or 2)
    aux = 3 - (src + dest);

    // Move `n-1` disks from `src` to `aux` peg
    hanoi(n - 1, src, aux);

    // Move the nth disk from `src` to `dest` peg
    printf("Disk %d from peg %d to peg %d\n", n, src, dest);

    // Move the `n-1` disks from `aux` to `dest` peg
    hanoi(n - 1, aux, dest);
}

// Main function to demonstrate the Tower of Hanoi solution
// This function calls the `hanoi` function to solve the problem for a given number of disks
int main(void) {
    // Solve the Tower of Hanoi problem for 3 disks, moving from peg 0 to peg 2
    hanoi(3, 0, 2);
    return 0;
}

/*
Summary of the Functions:

1. hanoi Function:
   - The `hanoi` function is a recursive function used to solve the Tower of Hanoi problem.
   - It takes three parameters: the number of disks (`n`), the source peg (`src`), and the destination peg (`dest`).
   - The function uses recursion to move `n-1` disks to an auxiliary peg, then moves the nth disk to the destination peg, and finally moves the `n-1` disks from the auxiliary peg to the destination peg.
   - The auxiliary peg is determined using the formula `aux = 3 - (src + dest)`.
   - The base case is when `n` is less than or equal to 0, at which point the function returns without performing any operations.

2. main Function:
   - The `main` function serves as the entry point for the program.
   - It calls the `hanoi` function to solve the Tower of Hanoi problem for 3 disks, moving them from peg 0 to peg 2.
   - The function prints each move step-by-step, providing a clear demonstration of how the disks are moved according to the rules of the Tower of Hanoi.

The Tower of Hanoi is a classic problem that demonstrates the power of recursion. The `hanoi` function breaks down the problem into smaller subproblems, moving smaller stacks of disks recursively until the entire stack is transferred from the source peg to the destination peg.
*/
