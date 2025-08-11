#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Direction vectors for up, down, left, right movements
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Function to check if a position is valid
int isValid(int x, int y, int rows, int cols, int** grid, int** visited) {
    return (x >= 0 && x < rows && y >= 0 && y < cols &&
            grid[x][y] == 1 && visited[x][y] == 0);
}

// DFS function to find shortest path
void dfs(int** grid, int** visited, int x, int y, int dr, int dc,
         int rows, int cols, int currentSteps, int* minSteps) {

    // If we reached the destination
    if (x == dr && y == dc) {
        if (currentSteps < *minSteps) {
            *minSteps = currentSteps;
        }
        return;
    }

    // Pruning: if current steps >= minSteps, no need to continue
    if (currentSteps >= *minSteps) {
        return;
    }

    // Mark current cell as visited
    visited[x][y] = 1;

    // Explore all 4 directions
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, rows, cols, grid, visited)) {
            dfs(grid, visited, newX, newY, dr, dc, rows, cols,
                currentSteps + 1, minSteps);
        }
    }

    // Backtrack: unmark current cell as visited
    visited[x][y] = 0;
}

// Main function to find shortest path
int shortestPath(int** grid, int rows, int cols, int sr, int sc, int dr, int dc) {
    // Check if start and destination are the same
    if (sr == dr && sc == dc) {
        return 0;
    }

    // Check if start or destination is blocked
    if (grid[sr][sc] == 0 || grid[dr][dc] == 0) {
        return -1;
    }

    // Create visited matrix
    int** visited = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        visited[i] = (int*)calloc(cols, sizeof(int));
    }

    int minSteps = INT_MAX;

    // Start DFS from source
    dfs(grid, visited, sr, sc, dr, dc, rows, cols, 0, &minSteps);

    // Free visited matrix
    for (int i = 0; i < rows; i++) {
        free(visited[i]);
    }
    free(visited);

    return (minSteps == INT_MAX) ? -1 : minSteps;
}

// Helper function to create a 2D grid
int** createGrid(int rows, int cols) {
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
    }
    return grid;
}

// Helper function to free a 2D grid
void freeGrid(int** grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Function to print the grid
void printGrid(int** grid, int rows, int cols) {
    printf("Grid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Test function
void testShortestPath() {
    printf("=== Testing Shortest Path with DFS ===\n\n");

    // Test Case 1: Example from README
    printf("Test Case 1:\n");
    int rows1 = 4, cols1 = 5;
    int** grid1 = createGrid(rows1, cols1);

    // Initialize grid from README example
    int gridData1[4][5] = {
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1}
    };

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            grid1[i][j] = gridData1[i][j];
        }
    }

    printGrid(grid1, rows1, cols1);
    int result1 = shortestPath(grid1, rows1, cols1, 0, 0, 3, 4);
    printf("Start: (0,0), Destination: (3,4)\n");
    printf("Shortest path length: %d\n\n", result1);

    // Test Case 2: No path exists
    printf("Test Case 2 - No Path:\n");
    int rows2 = 3, cols2 = 3;
    int** grid2 = createGrid(rows2, cols2);

    int gridData2[3][3] = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}
    };

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            grid2[i][j] = gridData2[i][j];
        }
    }

    printGrid(grid2, rows2, cols2);
    int result2 = shortestPath(grid2, rows2, cols2, 0, 0, 2, 2);
    printf("Start: (0,0), Destination: (2,2)\n");
    printf("Shortest path length: %d\n\n", result2);

    // Test Case 3: Same start and destination
    printf("Test Case 3 - Same Start and Destination:\n");
    int result3 = shortestPath(grid1, rows1, cols1, 1, 1, 1, 1);
    printf("Start: (1,1), Destination: (1,1)\n");
    printf("Shortest path length: %d\n\n", result3);

    // Test Case 4: Simple path
    printf("Test Case 4 - Simple Path:\n");
    int rows4 = 2, cols4 = 3;
    int** grid4 = createGrid(rows4, cols4);

    int gridData4[2][3] = {
        {1, 1, 1},
        {1, 1, 1}
    };

    for (int i = 0; i < rows4; i++) {
        for (int j = 0; j < cols4; j++) {
            grid4[i][j] = gridData4[i][j];
        }
    }

    printGrid(grid4, rows4, cols4);
    int result4 = shortestPath(grid4, rows4, cols4, 0, 0, 1, 2);
    printf("Start: (0,0), Destination: (1,2)\n");
    printf("Shortest path length: %d\n\n", result4);

    // Free allocated memory
    freeGrid(grid1, rows1);
    freeGrid(grid2, rows2);
    freeGrid(grid4, rows4);
}

int main() {
    testShortestPath();
    return 0;
}

// Alternative optimized version with early termination
int shortestPathOptimized(int** grid, int rows, int cols, int sr, int sc, int dr, int dc) {
    // Check if start and destination are the same
    if (sr == dr && sc == dc) {
        return 0;
    }

    // Check if start or destination is blocked
    if (grid[sr][sc] == 0 || grid[dr][dc] == 0) {
        return -1;
    }

    // Manhattan distance as lower bound for pruning
    int manhattanDistance = abs(sr - dr) + abs(sc - dc);

    // Create visited matrix
    int** visited = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        visited[i] = (int*)calloc(cols, sizeof(int));
    }

    int minSteps = manhattanDistance + 10; // Initial upper bound

    // Start DFS from source
    dfs(grid, visited, sr, sc, dr, dc, rows, cols, 0, &minSteps);

    // Free visited matrix
    for (int i = 0; i < rows; i++) {
        free(visited[i]);
    }
    free(visited);

    return (minSteps == INT_MAX || minSteps > rows * cols) ? -1 : minSteps;
}