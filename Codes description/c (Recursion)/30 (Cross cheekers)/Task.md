# Cross Checkers Puzzle

## Specifications

The task is to find a solution to the following puzzle called **Cross Checkers**. The board contains 33 cells with an initial configuration of 32 pawns. The goal is to reduce the number of pawns to just one by executing valid moves.

### Initial Board Configuration

The board's shape resembles a cross, with the following configuration:
- There are 33 cells, 32 of which contain pawns, and 1 cell is empty.

![Initial Configuration](example.png) *(You can visualize a cross-like board with 32 filled cells and one empty cell in the center)*

### Goal

Find a sequence of moves such that, at the end of the game, only one pawn remains on the board. A move is valid if a pawn can jump over an adjacent pawn in a horizontal or vertical direction into an empty space, thereby removing the jumped-over pawn from the board. The solution should ensure that at most **31 moves** are performed.

### Rules
1. Pawns can only jump over an adjacent pawn into an empty cell directly next to the jumped-over pawn.
2. Moves are limited to **horizontal** or **vertical** directions (no diagonal moves).
3. After a pawn jumps over another pawn, the jumped-over pawn is **removed** from the board.

## Solution Strategy

The logic behind solving the puzzle is based on recursive exploration:
- Since there are 32 pawns, a solution will consist of up to 31 moves, leaving only **one pawn** remaining on the board.
- The solution involves trying all possible moves recursively until a configuration is found where only one pawn remains.

## Implementation

The provided solution includes a C program that uses recursive backtracking to search for the correct sequence of moves. It stores each valid move and backtracks if no valid moves are possible from the current state.

To run the solution, compile the C program and execute it to see if a valid sequence of moves exists. The program prints each move in the format:

```
<x1> <y1> -> <x3> <y3>
```

Where `(x1, y1)` represents the starting position of the pawn, and `(x3, y3)` represents the destination cell after the move.

