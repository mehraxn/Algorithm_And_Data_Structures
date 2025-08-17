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

#### Code Explanation
The provided C code is an implementation of the Knight's Tour using a recursive backtracking approach. Below is a breakdown of the main components and how the algorithm works:

1. **Constants and Offsets**: 
   - `N` is defined as the size of the chessboard (in this case, `6x6`). To change the board size, you only need to modify the value of `N`.
   - The arrays `offset_x` and `offset_y` define the possible moves a knight can make in chess. There are 8 possible moves, corresponding to the way the knight moves in an "L" shape (two squares in one direction and one square in the perpendicular direction).

2. **Function Prototypes**:
   - `int move_r(int movement, int x, int y, int board[N][N])` is the function responsible for attempting to find a valid sequence of moves for the knight.

3. **Main Function**:
   - Initializes a `board` of size `N x N` to represent the chessboard, with all values set to `0`, indicating unvisited squares.
   - The user is prompted to input the starting position for the knight, which is then marked on the board with `1`.
   - The function `move_r()` is called to start the knight's tour from the given position, with `movement` initialized to `2` to indicate the next move.
   - If a solution is found, the board is printed with the sequence of moves. Otherwise, a message indicating that no solution was found is displayed.

4. **Recursive Function (`move_r()`)**:
   - The function `move_r()` is responsible for recursively exploring all possible moves from the current position.
   - If `movement` reaches `N * N + 1`, it means that all squares have been successfully visited, and the function returns `1` to indicate success.
   - The function iterates through all 8 possible moves (`for (i = 0; i < 8; i++)`) and calculates the new position `(xx, yy)` using the offsets.
   - It checks if the new position is within bounds and if the square is unvisited (`board[xx][yy] == 0`). If so, it marks the square with the current `movement` value and recursively calls `move_r()` to continue the tour.
   - If a move leads to a dead end, it backtracks by resetting the square to `0` and trying the next possible move.

#### Why 8 Moves?
The number `8` is used in the loop inside `move_r()` because a knight always has up to 8 possible moves on a standard chessboard. These moves are defined by the `offset_x` and `offset_y` arrays, which represent the relative positions a knight can move to from any given square. These 8 moves ensure that all potential paths are explored during the tour.

#### Changing the Board Size
To change the size of the chessboard, you only need to modify the value of `N`. For example, if you want to solve the Knight's Tour for an `8x8` board, simply set `#define N 8`. The algorithm will then adapt to the new board size.

#### Feasibility of Brute Force for Large Boards
Using a brute-force approach for large boards is impractical because the number of possible sequences grows exponentially. For an `N x N` board, there are `(N * N)!` possible sequences of moves, which becomes infeasible for even moderately large values of `N`. The recursive backtracking approach helps reduce the number of possibilities by eliminating paths that lead to dead ends early, but it is still computationally expensive for large boards. For larger boards, optimization techniques like Warnsdorff's heuristic are often used to find a solution more efficiently.

#### Input
- The starting position of the knight is read from standard input, formatted as the row index and column index (e.g., `0 3`).

#### Output
- If a solution is found, the program will display the chessboard with the sequence of moves the knight has taken.
- If no solution exists, an appropriate message will be printed.

