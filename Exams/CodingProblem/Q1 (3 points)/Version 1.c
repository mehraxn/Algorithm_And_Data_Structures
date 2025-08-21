/* Program to find the path in a matrix with the maximum sum */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100 // Maximum number of rows for the matrix
#define MAX_COLS 100 // Maximum number of columns for the matrix

// Struct to store information about a cell, including its position, sum, path length, and path as a string
typedef struct {
    int row; // Row index of the cell
    int col; // Column index of the cell
    int sum; // Sum of the values along the path to this cell
    int path_length; // Number of cells in the path
    char path[1024]; // String representation of the path
} Cell;

// Function prototypes
void mat_visit(int **mat, int r, int c, int f);
void find_path(int **mat, int visited[MAX_ROWS][MAX_COLS], Cell *current, Cell *best, int r, int c, int f);

// Main program logic
int main() {
    int rows = 3, cols = 3; // Define the number of rows and columns in the matrix

    // Dynamically allocate memory for the matrix
    int **matrix = malloc(rows * sizeof(int *));

    // Initialize a sample matrix
    int input_matrix[3][3] = {
            {1, 2, 3},
            {9, 7, 4},
            {1, 2, 8}
    };

    // Copy the sample matrix into the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = input_matrix[i][j];
        }
    }

    // Find and print the path with the maximum sum and shortest path length
    printf("Finding path with maximum sum:\n");
    mat_visit(matrix, rows, cols, 0);

    // Find and print the path with the maximum sum and longest path length
    printf("Finding path with maximum sum (longest path):\n");
    mat_visit(matrix, rows, cols, 1);

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

// Function to start finding the path with the maximum sum
void mat_visit(int **mat, int r, int c, int f) {
    int visited[MAX_ROWS][MAX_COLS] = {0}; // Initialize a visited array to track visited cells

    // Initialize the starting cell (top-left corner)
    Cell current = {0, 0, mat[0][0], 1, ""};
    sprintf(current.path, "[%d,%d]%d", 0, 0, mat[0][0]);

    Cell best = {0, 0, 0, 0, ""}; // Initialize the best path found so far

    // Recursively find the best path
    find_path(mat, visited, &current, &best, r, c, f);

    // Print the best path and its sum
    printf("%s - sum = %d\n", best.path, best.sum);
}

// Recursive function to explore all paths and find the one with the maximum sum
void find_path(int **mat, int visited[MAX_ROWS][MAX_COLS], Cell *current, Cell *best, int r, int c, int f) {
    // Define the possible moves (8 directions)
    static int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, // Up-left, up, up-right
            {0, -1},           {0, 1},  // Left,       right
            {1, -1}, {1, 0}, {1, 1}     // Down-left, down, down-right
    };

    // If the current cell is the bottom-right corner (destination)
    if (current->row == r - 1 && current->col == c - 1) {
        // Check if the current path is better than the best path found so far
        if (current->sum > best->sum ||
            (current->sum == best->sum && ((f == 0 && current->path_length < best->path_length) ||
                                           (f == 1 && current->path_length > best->path_length)))) {
            // Update the best path
            best->sum = current->sum;
            best->path_length = current->path_length;
            strcpy(best->path, current->path);
        }
        return;
    }

    // Mark the current cell as visited
    visited[current->row][current->col] = 1;

    // Explore all 8 possible moves
    for (int i = 0; i < 8; i++) {
        int new_row = current->row + directions[i][0]; // Calculate the new row index
        int new_col = current->col + directions[i][1]; // Calculate the new column index

        // Check if the new cell is within bounds and not visited
        if (new_row >= 0 && new_row < r && new_col >= 0 && new_col < c && !visited[new_row][new_col]) {
            // Create a new Cell object for the next step
            Cell next = *current;
            next.row = new_row;
            next.col = new_col;
            next.sum += mat[new_row][new_col]; // Update the sum
            next.path_length++; // Increment the path length

            // Append the new cell to the path
            char next_step[32];
            sprintf(next_step, " - [%d,%d]%d", new_row, new_col, mat[new_row][new_col]);
            strcat(next.path, next_step);

            // Recursively explore the new cell
            find_path(mat, visited, &next, best, r, c, f);
        }
    }

    // Backtrack: Unmark the current cell as visited
    visited[current->row][current->col] = 0;
}
