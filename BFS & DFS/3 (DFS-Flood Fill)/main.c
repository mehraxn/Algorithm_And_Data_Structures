#include <stdio.h>

// Define the dimensions of the image (matrix).
#define ROWS 3
#define COLS 3

/*
 * The floodFill function is the main entry point for the flood fill algorithm.
 * It takes the image (a 2D matrix), the starting pixel coordinates (sr, sc),
 * the new color to apply, and the dimensions of the image.
 *
 * This function first determines the original color at the starting pixel.
 * If the new color is the same as the original color, no changes are required,
 * and the function returns immediately. Otherwise, it calls the recursive
 * DFS helper function floodFillUtil to fill all connected pixels of the same color.
 */
void floodFill(int image[][COLS], int sr, int sc, int newColor, int rows, int cols);

/*
 * The floodFillUtil function implements the DFS strategy.
 *
 * It checks the current pixel to ensure it is within bounds and that its color
 * matches the original color that needs to be replaced (prevColor). If the check
 * passes, it updates the pixel with the new color.
 *
 * Then, the function recursively calls itself for the four adjacent pixels (up, down,
 * left, and right). This recursive call is the DFS in action: it dives deep into the region
 * of connected pixels that share the same original color.
 */
void floodFillUtil(int image[][COLS], int r, int c, int prevColor, int newColor, int rows, int cols);

void floodFill(int image[][COLS], int sr, int sc, int newColor, int rows, int cols) {
    // Store the original color at the starting position.
    int prevColor = image[sr][sc];

    // If the new color is the same as the original color, return immediately.
    // This check prevents unnecessary work and potential infinite recursion.
    if (prevColor == newColor) return;

    // Start the DFS-based flood fill from the starting pixel.
    floodFillUtil(image, sr, sc, prevColor, newColor, rows, cols);
}

void floodFillUtil(int image[][COLS], int r, int c, int prevColor, int newColor, int rows, int cols) {
    // Base conditions:
    // 1. Check if the current pixel is outside the boundaries of the image.
    // 2. Check if the current pixel's color is not equal to the original color.
    if (r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != prevColor) {
        return;
    }

    // Change the current pixel's color to the new color.
    image[r][c] = newColor;

    /*
     * DFS Integration Explanation:
     *
     * The DFS approach is used here to explore and fill all pixels that are connected
     * to the starting pixel and share the same original color. DFS works by exploring
     * as deep as possible along one branch before backtracking. In this flood fill algorithm,
     * once we fill a pixel, we recursively call floodFillUtil for its four adjacent pixels:
     * - Up: (r-1, c)
     * - Down: (r+1, c)
     * - Left: (r, c-1)
     * - Right: (r, c+1)
     *
     * These recursive calls ensure that every connected pixel (by four-way connectivity)
     * that matches the original color is visited and updated to the new color. This process
     * continues until the entire region has been filled.
     *
     * Note: In scenarios where the region to be filled is very large, the recursive DFS
     * might lead to a stack overflow. In such cases, an iterative approach using a stack
     * or a breadth-first search (BFS) using a queue would be a more robust alternative.
     */
    // Recursively call DFS on the adjacent pixels.
    floodFillUtil(image, r - 1, c, prevColor, newColor, rows, cols); // Up
    floodFillUtil(image, r + 1, c, prevColor, newColor, rows, cols); // Down
    floodFillUtil(image, r, c - 1, prevColor, newColor, rows, cols); // Left
    floodFillUtil(image, r, c + 1, prevColor, newColor, rows, cols); // Right
}

int main() {
    // Initialize a sample 2D image matrix.
    // This matrix represents the "image" where each number is a pixel's color.
    int image[ROWS][COLS] = {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1}
    };

    // Define the starting pixel coordinates (sr, sc) and the new color.
    int sr = 1, sc = 1;
    int newColor = 2;

    /*
     * Detailed Explanation:
     *
     * The flood fill algorithm implemented here mimics the "paint bucket" tool found in many image
     * editing programs. It starts at the specified pixel (sr, sc) and uses a Depth-First Search (DFS)
     * strategy to recursively visit every pixel that is connected (via up, down, left, or right) and
     * has the same color as the starting pixel. Each visited pixel is updated to the new color.
     *
     * The DFS traversal is key because it allows the algorithm to "dive" into each branch of connected
     * pixels, ensuring that the entire region is filled. Once all pixels have been processed, the modified
     * image is printed.
     */

    // Perform the flood fill operation on the image.
    floodFill(image, sr, sc, newColor, ROWS, COLS);

    // Output the modified image to the console.
    printf("Modified image after flood fill:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
