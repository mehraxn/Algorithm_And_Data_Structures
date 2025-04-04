# Maze Solver: README and Documentation

## Overview
This program is a comprehensive maze-solving application implemented in C. It reads a maze configuration from a file, processes the maze to solve it, and provides the following functionalities:

1. **Find One Solution**: Finds and displays one valid solution from the start (`@`) to the stop (`#`).
2. **Find All Solutions**: Displays all possible paths through the maze.
3. **Find the Best Solution**: Finds and displays the shortest path from start to stop.

The program uses recursive backtracking to explore paths through the maze and employs utility functions for efficient error handling, memory management, and file processing.

---

## Program Structure

The program is divided into several components:

1. **Constants and Definitions**
2. **Function Prototypes**
3. **Main Function**
4. **Maze Solver Functions**
5. **Utility Functions**

Below, each component is explained in detail.

---

### 1. Constants and Definitions

This section defines constants and movement offsets that the program uses to navigate the maze:

- **Constants**:
  - `MAX`: Maximum size of input lines.
  - `EMPTY`: Represents empty spaces in the maze.
  - `START`: Represents the starting point (`@`) in the maze.
  - `STOP`: Represents the target point (`#`) in the maze.
  - `PATH`: Marks a cell as part of the solution path (`S`).
  - `DONE`: Marks a cell as visited but not part of the final solution.

- **Movement Offsets**:
  These define the possible directions of movement (left, down, right, up):
  - `xOff[4]`: Adjusts rows.
  - `yOff[4]`: Adjusts columns.

These constants and offsets ensure code readability and simplify navigation logic.

---

### 2. Function Prototypes

Function prototypes are declared at the start to provide an outline of the program’s capabilities:

- **Display Function**:
  - `void display(char **, int);`
  - Prints the maze layout to the console.

- **Maze Solving Functions**:
  - `int move_r_one(char **, int, int, int, int);`
    - Finds one solution using recursive backtracking.
  - `int move_r_all(char **, int, int, int, int, int, int);`
    - Finds and displays all possible solutions.
  - `int move_r_best(char **, int, char **, int, int, int, int, int);`
    - Finds the shortest (optimal) solution.

- **Utility Functions**:
  - `FILE *util_fopen(char *, char *);`
    - Opens files with error handling.
  - `void *util_malloc(int);`
    - Allocates memory with error checking.
  - `char *util_strdup(char *);`
    - Duplicates strings with error checking.

---

### 3. Main Function

#### **Purpose**
The main function handles input processing, initializes the maze, and invokes the maze-solving functions.

#### **Steps**

1. **Input Validation**:
   - Checks for the presence of a file argument. If missing, it displays an error and exits.

2. **File Reading**:
   - Opens the maze file using `util_fopen`.
   - Reads the maze dimensions (number of rows and columns).

3. **Memory Allocation**:
   - Allocates memory for `mazeCurr` (current maze state) and `mazeBest` (shortest solution).

4. **Maze Initialization**:
   - Reads the maze line-by-line and duplicates it into both `mazeCurr` and `mazeBest`.
   - Identifies the starting position (`@`). If not found, exits with an error.

5. **Finding Solutions**:
   - **Find One Solution**:
     - Calls `move_r_one` to find a single solution and displays it.
   - **Find All Solutions**:
     - Calls `move_r_all` to find and display all valid solutions.
   - **Find the Best Solution**:
     - Calls `move_r_best` to find the shortest solution and displays it.

6. **Memory Cleanup**:
   - Frees all dynamically allocated memory before exiting.

---

### 4. Maze Solver Functions

#### **4.1 move_r_one**
- **Purpose**: Recursively finds one valid solution.
- **Logic**:
  - Starts from the given cell.
  - Explores all four possible directions.
  - Marks the path with `PATH` (`S`) and backtracks if the path is invalid.
  - Stops recursion when the `STOP` point (`#`) is reached.
- **Returns**: 1 if a solution is found, 0 otherwise.

#### **4.2 move_r_all**
- **Purpose**: Recursively finds and displays all possible solutions.
- **Logic**:
  - Similar to `move_r_one` but continues exploring all possible paths even after finding a solution.
  - Uses a static counter (`solN`) to track and number each solution.
  - Displays each solution as it is found.
- **Returns**: 1 if at least one solution is found, 0 otherwise.

#### **4.3 move_r_best**
- **Purpose**: Recursively finds the shortest path.
- **Logic**:
  - Keeps track of the current step count (`stepCurr`) and compares it with the shortest step count (`stepBest`).
  - Updates `stepBest` and `mazeBest` whenever a shorter solution is found.
  - Stops exploring paths that exceed the current best solution.
- **Returns**: The shortest step count.

---

### 5. Utility Functions

#### **5.1 display**
- **Purpose**: Prints the current maze layout to the console.
- **Logic**:
  - Loops through all rows of the maze and prints each row.

#### **5.2 util_fopen**
- **Purpose**: Opens a file and handles errors.
- **Logic**:
  - Attempts to open the file with the given mode (e.g., "r").
  - Exits the program if the file cannot be opened.

#### **5.3 util_malloc**
- **Purpose**: Allocates memory and handles errors.
- **Logic**:
  - Uses `malloc` to allocate memory.
  - Exits the program if memory allocation fails.

#### **5.4 util_strdup**
- **Purpose**: Duplicates a string and handles errors.
- **Logic**:
  - Uses `strdup` to create a duplicate of the given string.
  - Exits the program if memory allocation fails.

---

## Program Flow Example

1. **Input File**:
   ```
   5 5
   @####
   #   #
   # # #
   #   #
   #####
   ```

2. **Find One Solution**:
   ```
   Solution:
   S####
   #S  #
   #S# #
   #S  #
   ####S
   ```

3. **Find All Solutions**:
   Outputs all valid paths, each labeled with "Solution #".

4. **Find the Best Solution**:
   Displays the shortest path.

---

## Error Handling

1. **Missing Input File**:
   - Displays an error and exits if no file is provided.

2. **Invalid File**:
   - Displays an error and exits if the file cannot be opened.

3. **Memory Allocation Failures**:
   - Displays an error and exits if memory allocation fails.

---

## Key Concepts and Algorithms

1. **Recursive Backtracking**:
   - Explores all paths through the maze.
   - Backtracks when a dead-end is reached.

2. **Static Variables**:
   - Used in `move_r_all` to track the solution count across recursive calls.

3. **Optimization**:
   - `move_r_best` optimizes the search by pruning paths longer than the current best.

---

## How to Compile and Run

1. **Compile**:
   Use the `gcc` compiler:
   ```
   gcc -o maze_solver maze_solver.c
   ```

2. **Run**:
   Provide a maze file as input:
   ```
   ./maze_solver maze.txt
   ```

---

## Future Enhancements

1. Add visualization for maze traversal.
2. Support for larger mazes and dynamic resizing.
3. Implement multi-threading for parallel path exploration.

