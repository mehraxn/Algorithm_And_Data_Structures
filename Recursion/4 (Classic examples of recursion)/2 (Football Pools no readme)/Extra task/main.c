#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5  // Matrix dimensions based on the output structure


// Function to read input from a file and fill two arrays for further processing
void readMatrixFromFile(const char *filename, char matrix[SIZE][SIZE]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    char line[10];
    int row = 0;

    // Filling the matrix as per task requirements
    while (fgets(line, sizeof(line), file) && row < SIZE) {
        int col = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] != ' ' && line[i] != '\n') {
                matrix[row][col] = line[i];
                col++;
            }
        }
        row++;
    }
    fclose(file);
}

// Recursive function to print the middle matrix
void recursiveMiddleMatrix(char matrix[SIZE][SIZE], int i, int j) {
    if (i >= SIZE) return;  // Base case: Reached end of matrix

    printf("%c ", matrix[i][j]);

    if (j == SIZE - 1) {  // Move to the next row when end of current row is reached
        printf("\n");
        recursiveMiddleMatrix(matrix, i + 1, 0);
    } else {
        recursiveMiddleMatrix(matrix, i, j + 1);  // Move to the next column
    }
}

// Recursive function to print combinations based on 'X'
void recursiveLowerMatrix(char matrix[SIZE][SIZE], int row, char current[SIZE * 2], int level) {
    if (row == SIZE) {  // End of matrix, print the current combination
        current[level] = '\0';  // Null-terminate the string
        printf("%s\n", current);
        return;
    }

    for (int col = 0; col < SIZE; col++) {
        if (matrix[row][col] == 'X') {
            current[level] = '1';
            recursiveLowerMatrix(matrix, row + 1, current, level + 1);

            current[level] = '2';
            recursiveLowerMatrix(matrix, row + 1, current, level + 1);
        } else {
            current[level] = matrix[row][col];
            recursiveLowerMatrix(matrix, row + 1, current, level + 1);
        }
    }
}

int main() {
    char matrix[SIZE][SIZE] = {0};  // Matrix initialization
    readMatrixFromFile("./file.txt", matrix);  // Read input from file

    printf("Middle Output Matrix:\n");
    recursiveMiddleMatrix(matrix, 0, 0);

    printf("\nLower Matrix Output Combinations:\n");
    char current[SIZE * 2];  // To store combinations
    recursiveLowerMatrix(matrix, 0, current, 0);

    return 0;
}
