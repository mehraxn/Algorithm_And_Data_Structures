#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENT_NAME_LENGTH 50

// Function to read the board and create the matrix
char ***board_read(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Read the dimensions of the board
    int rows, cols;
    if (fscanf(file, "%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Error reading dimensions from the file.\n");
        fclose(file);
        return NULL;
    }

    // Allocate the matrix
    char ***board = (char ***)malloc(rows * sizeof(char **));
    if (!board) {
        perror("Error allocating memory for the board");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        board[i] = (char **)malloc(cols * sizeof(char *));
        if (!board[i]) {
            perror("Error allocating memory for board row");
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(board[j]);
            }
            free(board);
            fclose(file);
            return NULL;
        }
        // Initialize all cells to NULL
        for (int j = 0; j < cols; j++) {
            board[i][j] = NULL;
        }
    }

    // Read the components and place them in the matrix
    int row, col;
    char component[MAX_COMPONENT_NAME_LENGTH + 1];
    while (fscanf(file, "%d %d %s", &row, &col, component) == 3) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            fprintf(stderr, "Error: Invalid position (%d, %d).\n", row, col);
            continue;
        }

        // Allocate memory for the component name and store it
        board[row][col] = strdup(component);
        if (!board[row][col]) {
            perror("Error allocating memory for component name");
            // Cleanup and return NULL
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    free(board[i][j]);
                }
                free(board[i]);
            }
            free(board);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);
    return board;
}

// Function to free the allocated memory for the board
void board_free(char ***board, int rows, int cols) {
    if (!board) return;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(board[i][j]);
        }
        free(board[i]);
    }
    free(board);
}

// Function to print the board
void board_print(char ***board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j]) {
                printf("%s\t", board[i][j]);
            } else {
                printf("NULL\t");
            }
        }
        printf("\n");
    }
}

// Main function to demonstrate the usage of board_read
int main() {
    char filename[] = "board.txt";

    // Read the board from the file
    char ***board = board_read(filename);
    if (!board) {
        fprintf(stderr, "Failed to read the board from the file.\n");
        return 1;
    }

    // Dimensions of the board (hardcoded here, should be dynamically passed or stored)
    int rows = 5, cols = 10;

    // Print the board
    printf("Board:\n");
    board_print(board, rows, cols);

    // Free the allocated memory
    board_free(board, rows, cols);

    return 0;
}
