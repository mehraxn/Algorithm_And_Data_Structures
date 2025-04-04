/*
Island Counting Problem in C

This program counts the number of islands in a given 2D grid.
An island is defined as a group of connected 1's (land) connected horizontally or vertically.
Zeroes represent water. When a land cell is visited, we "sink" it by marking it as 0,
so that it is not counted again.

How DFS is Integrated:
1. The program iterates through each cell in the grid.
2. When an unvisited land cell (with value 1) is encountered, the island count is incremented.
3. A DFS (Depth-First Search) is then started from that cell.
   - The DFS function recursively visits all neighboring cells (up, down, left, right) that are also land.
   - As each cell is visited, it is marked as visited by setting its value to 0. This effectively "sinks" the entire island.
4. This ensures that each island is only counted once.
5. The overall traversal has a time complexity of O(m*n), where m is the number of rows and n is the number of columns.

This method is efficient and well-suited for exploring connected components in a grid.
*/

#include <stdio.h>

// Define maximum possible grid dimensions (these can be adjusted as needed)
#define MAX_ROWS 300
#define MAX_COLS 300

// Function prototype for DFS helper function
void dfs(int grid[][MAX_COLS], int row, int col, int numRows, int numCols);

int main() {
    // Example grid (first test case provided in the explanation)
    // 1 represents land and 0 represents water
    int grid[][MAX_COLS] = {
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Define number of rows and columns for the grid
    int numRows = 4;
    int numCols = 5;

    // Variable to keep track of the number of islands
    int count = 0;

    // Loop through every cell in the grid
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // When a land cell (value 1) is found, it signifies part of an island.
            // Increment the island count and use DFS to mark the entire island as visited.
            if (grid[i][j] == 1) {
                count++;
                dfs(grid, i, j, numRows, numCols);
            }
        }
    }

    // Print the total number of islands found in the grid
    printf("Number of islands: %d\n", count);

    return 0;
}

/*
dfs: Depth-First Search function to explore and mark all connected land cells.

Parameters:
- grid: 2D array representing the map (land and water)
- row, col: current cell coordinates in the grid
- numRows, numCols: dimensions of the grid

Steps:
1. Base Case: If the current cell is out of grid bounds or it is water (value 0), return immediately.
2. Mark the current cell as visited by setting grid[row][col] to 0.
3. Recursively call dfs for the four adjacent directions (up, down, left, right).
   This ensures that all connected land cells are visited, effectively "sinking" the island.
*/
void dfs(int grid[][MAX_COLS], int row, int col, int numRows, int numCols) {
    // Check if the current cell is out-of-bounds or is water (already visited or not land)
    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] == 0)
        return;

    // Mark the cell as visited (sink the island cell) by setting its value to 0
    grid[row][col] = 0;

    // Recursively explore the neighboring cells:
    // Up, Down, Left, and Right
    dfs(grid, row - 1, col, numRows, numCols); // Up
    dfs(grid, row + 1, col, numRows, numCols); // Down
    dfs(grid, row, col - 1, numRows, numCols); // Left
    dfs(grid, row, col + 1, numRows, numCols); // Right
}
