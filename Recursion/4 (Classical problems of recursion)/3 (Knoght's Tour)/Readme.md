### Knight's Tour Problem - ReadMe

#### Overview
The Knight's Tour is a classic chess problem that involves moving a knight across a chessboard in such a way that it visits every square exactly once. The challenge is to find a sequence of moves where the knight never revisits a square until all squares have been covered.

If the knight's path ends on a square that is one move away from the starting position, allowing it to continue in a closed loop, it is referred to as a **closed tour**. Otherwise, the tour is classified as an **open tour**.

In this problem, the knight moves in an "L" pattern, characteristic of standard chess rules. The knight's possible moves are depicted in the image along with two examples of open tours.

#### Variations of the Problem
The Knight's Tour can be performed on various types of chessboards, not limited to the traditional 8x8 board. It can be adapted to different sizes or even irregularly shaped boards. This flexibility makes the problem more diverse and challenging.

#### Task
Your task is to create a program that finds a knight's tour on an `N x N` chessboard, where `N` is a predefined constant. The program should prompt the user to provide the initial starting cell `[i][j]`, and then attempt to find a complete tour starting from this position.

The solution should adopt a recursive approach to explore different possible moves and ensure all squares are covered, utilizing backtracking when needed.

#### Input
- The starting position of the knight is read from standard input, formatted as the row index and column index (e.g., `0 3`).

#### Output
- If a solution is found, the program will display the chessboard with the sequence of moves the knight has taken.
- If no solution exists, an appropriate message will be printed.