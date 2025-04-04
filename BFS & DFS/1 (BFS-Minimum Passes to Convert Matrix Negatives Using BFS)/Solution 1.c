#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Data structure to store the cell coordinates of the matrix
typedef struct Point {
    int x, y; // x and y represent the row and column indices of a matrix cell
} Point;

// Function to check whether given coordinates is a valid cell or not
bool isValid(int i, int j, int rows, int cols) {
    // A cell is valid if it lies within the bounds of the matrix
    return (i >= 0 && i < rows) && (j >= 0 && j < cols);
}

// Arrays representing possible movements (up, left, right, down)
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

// Function to check if the matrix contains any negative values
bool hasNegative(int **mat, int rows, int cols) {
    // Iterate through the entire matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // If a negative value is found, return true
            if (mat[i][j] < 0) {
                return true;
            }
        }
    }
    // Return false if no negative values are found
    return false;
}

// Function to find the minimum number of passes required to convert all negative values to positive
int findMinPasses(int **mat, int rows, int cols) {
    // Base case: if the matrix is empty, no passes are required
    if (rows == 0 || cols == 0) {
        return 0;
    }

    // Create a queue to store cell coordinates of positive integers
    Point *queue = (Point *)malloc(rows * cols * sizeof(Point)); // Dynamic allocation for queue
    int front = 0, rear = 0; // Initialize front and rear indices for the queue

    // Enqueue all positive numbers in the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] > 0) {
                queue[rear++] = (Point){i, j}; // Add positive cell to the queue
            }
        }
    }

    // Initialize the number of passes required to 0
    int passes = 0;

    // Process the queue until no more cells can be converted
    while (front != rear) {
        // Number of elements in the current pass
        int currentLevelSize = rear - front;

        /* Start of the current pass */

        // Process all cells in the queue for the current pass
        for (int i = 0; i < currentLevelSize; i++) {
            // Dequeue the front element
            Point current = queue[front++];

            // Check all four possible adjacent cells
            for (int k = 0; k < 4; k++) {
                int newX = current.x + row[k]; // New row index
                int newY = current.y + col[k]; // New column index

                // Check if the adjacent cell is valid and negative
                if (isValid(newX, newY, rows, cols) && mat[newX][newY] < 0) {
                    // Convert the negative cell to positive
                    mat[newX][newY] = -mat[newX][newY];

                    // Enqueue the newly positive cell
                    queue[rear++] = (Point){newX, newY};
                }
            }
        }

        /* End of the current pass */

        // Increment the number of passes after processing all cells in the current level
        passes++;
    }

    // Free the allocated memory for the queue
    free(queue);

    // Return the number of passes, or -1 if some cells remain negative
    return hasNegative(mat, rows, cols) ? -1 : (passes - 1);
}

int main() {
    // Define the size of the matrix
    int rows = 4, cols = 5;

    // Dynamically allocate memory for the matrix
    int **mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the input matrix
    int input[4][5] = {
            { -1, -9, 0, -1, 0 },
            { -8, -3, -2, 9, -7 },
            { 2, 0, 0, -6, 0 },
            { 0, -7, -3, 5, -4 }
    };

    // Copy input matrix to dynamically allocated matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = input[i][j];
        }
    }

    // Call the function to find the minimum number of passes
    int pass = findMinPasses(mat, rows, cols);

    // Output the result
    if (pass != -1) {
        printf("The total number of passes required is %d\n", pass);
    } else {
        printf("Invalid Input\n");
    }

    // Free the allocated memory for the matrix
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}

/*
Explanation of each function:

1. isValid:
   - Checks if the given row and column indices are within the matrix bounds.
   - Returns true if valid, false otherwise.

2. hasNegative:
   - Scans the matrix to check if any cell contains a negative value.
   - Returns true if a negative value is found, false otherwise.

3. findMinPasses:
   - Implements the core logic to calculate the minimum number of passes required to convert all negative values to positive.
   - Uses a BFS-like approach to process cells level by level.
   - Returns the number of passes or -1 if some cells remain negative.

4. main:
   - Initializes the input matrix and dynamically allocates memory.
   - Calls findMinPasses and displays the result.
   - Frees dynamically allocated memory to avoid memory leaks.
*/
