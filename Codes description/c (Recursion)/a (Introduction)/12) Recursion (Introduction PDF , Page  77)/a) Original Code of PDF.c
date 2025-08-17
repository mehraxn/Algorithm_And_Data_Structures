int main(void) {
    // Solve the Tower of Hanoi problem for 3 disks, moving from peg 0 to peg 2
    hanoi(3, 0, 2);
    return 0;
}

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
