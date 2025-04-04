#include <stdio.h>      // Standard input-output library for functions like printf, fopen
#include <stdlib.h>     // Standard library for functions like malloc, exit
#include <string.h>     // String manipulation functions like strdup

// Define constants for the maze elements
#define MAX 100          // Maximum size for input lines
#define EMPTY ' '        // Represents an empty cell in the maze
#define START '@'        // Represents the starting point in the maze
#define STOP '#'         // Represents the target point in the maze
#define PATH 'S'         // Marks a cell as part of the solution path
#define DONE ','         // Marks a cell as visited but not part of the solution

// Define movement offsets for navigating the maze in four directions (left, down, right, up)
const int xOff[4] = {0, 1, 0, -1}; // Row offsets for movement
const int yOff[4] = {-1, 0, 1, 0}; // Column offsets for movement

// Function prototypes
void display(char **, int);                                // Function to display the maze
int move_r_one(char **, int, int, int, int);               // Function to find one solution in the maze
int move_r_all(char **, int, int, int, int, int, int);     // Function to find all possible solutions
int move_r_best(char **, int, char **, int, int, int, int, int); // Function to find the best (shortest) solution
FILE *util_fopen(char *, char *);                          // Utility function to open a file with error checking
void *util_malloc(int);                                    // Utility function to allocate memory with error checking
char *util_strdup(char *);                                 // Utility function to duplicate a string with error checking

// Main function: The entry point of the program
int main(int argc, char *argv[]) {
    // Declare variables to store the starting position, maze dimensions, and results
    int r = -1, c = -1;            // Starting row (r) and column (c)
    int i, j, nr, nc, res;         // Loop counters, number of rows (nr), columns (nc), and result
    char **mazeCurr, **mazeBest;   // Pointers to store the current maze and the best solution maze
    char line[MAX];                // Buffer to store each line of the input maze
    FILE *fp;                      // File pointer for reading the maze input

    // Check if the user provided a file name as an argument
    if (argc < 2) {
        fprintf(stderr, "Error: missing parameter.\n"); // Print error to standard error
        fprintf(stdout, "Run as: %s <maze_file>\n", argv[0]); // Suggest how to run the program
        exit(EXIT_FAILURE); // Exit the program with a failure code
    }

    // Open the input file containing the maze
    fp = util_fopen(argv[1], "r");

    // Read the maze dimensions (number of rows and columns) from the file
    fgets(line, MAX, fp);          // Read the first line of the file
    sscanf(line, "%d %d", &nr, &nc); // Parse the dimensions (nr = rows, nc = columns)

    // Allocate memory for the current maze and the best solution maze
    mazeCurr = (char **)util_malloc(nr * sizeof(char *)); // Allocate memory for rows of mazeCurr
    mazeBest = (char **)util_malloc(nr * sizeof(char *)); // Allocate memory for rows of mazeBest

    // Read each line of the maze and store it in mazeCurr and mazeBest
    for (i = 0; i < nr; i++) {
        fgets(line, MAX, fp);            // Read a line from the file
        mazeCurr[i] = util_strdup(line); // Duplicate the line into mazeCurr
        mazeBest[i] = util_strdup(line); // Duplicate the line into mazeBest

        // Check each character in the line to find the starting position
        for (j = 0; j < nc; j++) {
            if (mazeCurr[i][j] == START) { // If the character is the start point
                r = i; // Store the row of the start point
                c = j; // Store the column of the start point
            }
        }
    }

    // Check if a starting position was found
    if (r < 0 || c < 0) {
        fprintf(stdout, "Error: no starting position found!\n"); // Print error message
        exit(EXIT_FAILURE); // Exit the program with a failure code
    }

    // Find one solution to the maze
    fprintf(stdout, "Find one solution:\n"); // Notify the user
    mazeCurr[r][c] = EMPTY;                  // Mark the starting position as empty
    res = move_r_one(mazeCurr, nr, nc, r, c); // Call the function to find one solution
    if (res == 1) {                          // If a solution was found
        mazeCurr[r][c] = START;              // Restore the starting position
        display(mazeCurr, nr);               // Display the maze with the solution
    } else {
        fprintf(stdout, "NO solution found!\n"); // Notify the user if no solution was found
    }

    // Clean the maze for subsequent searches
    for (i = 0; i < nr; i++) {                // Loop through each row
        for (j = 0; j < nc; j++) {            // Loop through each column
            if (mazeCurr[i][j] == PATH || mazeCurr[i][j] == DONE) { // If the cell was marked as PATH or DONE
                mazeCurr[i][j] = EMPTY;       // Reset it to EMPTY
            }
        }
    }

    // Find all solutions in the maze
    fprintf(stdout, "Find all solutions:\n"); // Notify the user
    mazeCurr[r][c] = EMPTY;                   // Reset the starting position
    res = move_r_all(mazeCurr, nr, nc, r, c, r, c); // Call the function to find all solutions

    // Find the best (shortest) solution in the maze
    fprintf(stdout, "Find the best solutions:\n"); // Notify the user
    mazeCurr[r][c] = EMPTY;                        // Reset the starting position
    res = move_r_best(mazeCurr, 0, mazeBest, nr * nc, nr, nc, r, c); // Call the function to find the best solution
    if (res > 0) {                                 // If a solution was found
        fprintf(stdout, "Solution:\n");
        mazeBest[r][c] = START;                    // Restore the starting position in the best maze
        display(mazeBest, nr);                     // Display the best solution
    } else {
        fprintf(stdout, "NO solution found!\n");   // Notify the user if no solution was found
    }

    // Free the allocated memory for the mazes
    for (r = 0; r < nr; r++) { // Loop through each row
        free(mazeCurr[r]);     // Free memory for each row in mazeCurr
        free(mazeBest[r]);     // Free memory for each row in mazeBest
    }
    free(mazeCurr);            // Free the memory for the mazeCurr pointer
    free(mazeBest);            // Free the memory for the mazeBest pointer

    return EXIT_SUCCESS;       // Exit the program successfully
}

// Function definitions follow with detailed comments for each function...


/*
 * Function: move_r_one
 * --------------------
 * Recursively finds one solution to the maze.
 *
 * Parameters:
 *  - mazeCurr: The current maze layout.
 *  - nr: Number of rows in the maze.
 *  - nc: Number of columns in the maze.
 *  - row: Current row position.
 *  - col: Current column position.
 *
 * Returns:
 *  - 1 if a solution is found.
 *  - 0 otherwise.
 */
int move_r_one(char **mazeCurr, int nr, int nc, int row, int col) {
    int k, r, c; // k is for looping through directions, r and c are next positions

    if (mazeCurr[row][col] == STOP) { // If the current cell is the target
        return 1;                    // A solution is found
    }
    if (mazeCurr[row][col] != EMPTY) { // If the current cell is not traversable
        return 0;                     // No solution through this path
    }

    mazeCurr[row][col] = PATH;        // Mark the current cell as part of the path
    for (k = 0; k < 4; k++) {         // Explore all 4 possible directions
        r = row + xOff[k];            // Calculate the next row
        c = col + yOff[k];            // Calculate the next column
        if (r >= 0 && r < nr && c >= 0 && c < nc) { // Ensure the next position is within bounds
            if (move_r_one(mazeCurr, nr, nc, r, c) == 1) { // Recur to the next position
                return 1; // If a solution is found in this direction, return success
            }
        }
    }
    mazeCurr[row][col] = DONE; // Backtrack: Mark the cell as visited but not part of the solution

    return 0; // No solution found from this path
}

/*
 * Function: move_r_all
 * --------------------
 * Recursively finds all possible solutions to the maze.
 *
 * Parameters:
 *  - mazeCurr: The current maze layout.
 *  - nr: Number of rows in the maze.
 *  - nc: Number of columns in the maze.
 *  - row: Current row position.
 *  - col: Current column position.
 *  - row0: Starting row position (used for resetting START position).
 *  - col0: Starting column position (used for resetting START position).
 *
 * Returns:
 *  - 1 if at least one solution is found.
 *  - 0 otherwise.
 */
int move_r_all(char **mazeCurr, int nr, int nc, int row, int col, int row0, int col0) {
    int k, r, c;            // k is for looping through directions, r and c are next positions
    static int solN = 0;    // Solution counter (static to retain value across calls)

    if (mazeCurr[row][col] == STOP) { // If the current cell is the target
        solN++;                       // Increment the solution counter
        fprintf(stdout, "Solution #%d:\n", solN); // Print the solution number
        mazeCurr[row0][col0] = START; // Restore the START position in the maze
        display(mazeCurr, nr);        // Display the current solution
        mazeCurr[row0][col0] = EMPTY; // Reset the START position
        return 1; // Solution found
    }
    if (mazeCurr[row][col] != EMPTY) { // If the cell is not traversable
        return 0; // No solution through this path
    }

    mazeCurr[row][col] = PATH;        // Mark the current cell as part of the path
    for (k = 0; k < 4; k++) {         // Explore all 4 possible directions
        r = row + xOff[k];            // Calculate the next row
        c = col + yOff[k];            // Calculate the next column
        if (r >= 0 && r < nr && c >= 0 && c < nc) { // Ensure the next position is within bounds
            move_r_all(mazeCurr, nr, nc, r, c, row0, col0); // Recur to the next position
        }
    }
    mazeCurr[row][col] = EMPTY; // Backtrack: Reset the cell to EMPTY

    return 0; // No solution found from this path
}

/*
 * Function: move_r_best
 * ---------------------
 * Recursively finds the shortest solution (best solution) to the maze.
 *
 * Parameters:
 *  - mazeCurr: The current maze layout.
 *  - stepCurr: Current step count.
 *  - mazeBest: The best solution maze layout.
 *  - stepBest: Shortest step count found so far.
 *  - nr: Number of rows in the maze.
 *  - nc: Number of columns in the maze.
 *  - row: Current row position.
 *  - col: Current column position.
 *
 * Returns:
 *  - The updated shortest step count.
 */
int move_r_best(char **mazeCurr, int stepCurr, char **mazeBest, int stepBest, int nr, int nc, int row, int col) {
    int k, r, c; // k is for looping through directions, r and c are next positions

    if (stepCurr >= stepBest) { // If the current path exceeds the shortest path found so far
        return stepBest;        // Return the shortest step count
    }
    if (mazeCurr[row][col] == STOP) { // If the current cell is the target
        if (stepCurr < stepBest) {    // If this path is shorter than the shortest path so far
            stepBest = stepCurr;     // Update the shortest step count
            for (r = 0; r < nr; r++) { // Copy the current maze state to the best maze
                for (c = 0; c < nc; c++) {
                    mazeBest[r][c] = mazeCurr[r][c];
                }
            }
        }
        return stepBest; // Return the updated shortest step count
    }

    if (mazeCurr[row][col] != EMPTY) { // If the cell is not traversable
        return stepBest; // Return the shortest step count
    }

    mazeCurr[row][col] = PATH;        // Mark the current cell as part of the path
    for (k = 0; k < 4; k++) {         // Explore all 4 possible directions
        r = row + xOff[k];            // Calculate the next row
        c = col + yOff[k];            // Calculate the next column
        if (r >= 0 && r < nr && c >= 0 && c < nc) { // Ensure the next position is within bounds
            stepBest = move_r_best(mazeCurr, stepCurr + 1, mazeBest, stepBest, nr, nc, r, c); // Recur to the next position
        }
    }
    mazeCurr[row][col] = EMPTY; // Backtrack: Reset the cell to EMPTY

    return stepBest; // Return the shortest step count
}

/*
 * Function: display
 * -----------------
 * Prints the maze layout to the console.
 *
 * Parameters:
 *  - maze: The maze layout to display.
 *  - nr: Number of rows in the maze.
 */
void display(char **maze, int nr) {
    for (int i = 0; i < nr; i++) {   // Loop through each row
        fprintf(stdout, "%s", maze[i]); // Print each row to the console
    }
}

/*
 * Function: util_fopen
 * --------------------
 * Opens a file and checks for errors.
 *
 * Parameters:
 *  - name: Name of the file to open.
 *  - mode: Mode to open the file in ("r", "w", etc.).
 *
 * Returns:
 *  - A pointer to the opened file.
 */
FILE *util_fopen(char *name, char *mode) {
    FILE *fp = fopen(name, mode); // Open the file
    if (fp == NULL) { // If the file could not be opened
        fprintf(stdout, "File open error (file=%s).\n", name); // Print error message
        exit(EXIT_FAILURE); // Exit the program with a failure code
    }
    return fp; // Return the file pointer
}

/*
 * Function: util_malloc
 * ---------------------
 * Allocates memory and checks for errors.
 *
 * Parameters:
 *  - size: Size of memory to allocate.
 *
 * Returns:
 *  - A pointer to the allocated memory.
 */
void *util_malloc(int size) {
    void *ptr = malloc(size); // Allocate memory
    if (ptr == NULL) { // If memory allocation fails
        fprintf(stdout, "Memory allocation error.\n"); // Print error message
        exit(EXIT_FAILURE); // Exit the program with a failure code
    }
    return ptr; // Return the allocated memory pointer
}

/*
 * Function: util_strdup
 * ---------------------
 * Duplicates a string and checks for errors.
 *
 * Parameters:
 *  - src: The source string to duplicate.
 *
 * Returns:
 *  - A pointer to the duplicated string.
 */
char *util_strdup(char *src) {
    char *dst = strdup(src); // Duplicate the string
    if (dst == NULL) { // If duplication fails
        fprintf(stdout, "Memory allocation error.\n"); // Print error message
        exit(EXIT_FAILURE); // Exit the program with a failure code
    }
    return dst; // Return the duplicated string
}
