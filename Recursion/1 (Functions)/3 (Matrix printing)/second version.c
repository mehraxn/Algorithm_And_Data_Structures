#include <stdio.h>
#define SIZE 10

// Helper function to recursively print an array
void print_array_recursive(char *arr, int index, int size) {
    if (index >= size) {
        printf("\n");
        return;
    }
    printf("%c ", arr[index]);
    print_array_recursive(arr, index + 1, size);
}

// Function to print the matrix row-wise recursively
void print_row_wise(char matrix[SIZE][SIZE], int row, int col, char *current_row) {
    if (row >= SIZE) {
        return; // All rows have been processed
    }
    if (col < SIZE) {
        current_row[col] = matrix[row][col]; // Store current element
        print_row_wise(matrix, row, col + 1, current_row); // Move to next column
    } else {
        print_array_recursive(current_row, 0, SIZE); // Print the stored row
        print_row_wise(matrix, row + 1, 0, current_row); // Move to next row
    }
}

// Function to print the matrix column-wise recursively
void print_col_wise(char matrix[SIZE][SIZE], int col, int row, char *current_col) {
    if (col >= SIZE) {
        return; // All columns have been processed
    }
    if (row < SIZE) {
        current_col[row] = matrix[row][col]; // Store current element
        print_col_wise(matrix, col, row + 1, current_col); // Move to next row
    } else {
        print_array_recursive(current_col, 0, SIZE); // Print the stored column
        print_col_wise(matrix, col + 1, 0, current_col); // Move to next column
    }
}

int main() {
    char matrix[SIZE][SIZE] = {
            {'A','B','C','D','E','F','G','H','I','J'},
            {'K','L','M','N','O','P','Q','R','S','T'},
            {'U','V','W','X','Y','Z','a','b','c','d'},
            {'e','f','g','h','i','j','k','l','m','n'},
            {'o','p','q','r','s','t','u','v','w','x'},
            {'y','z','0','1','2','3','4','5','6','7'},
            {'8','9','!','@','#','$','%','^','&','*'},
            {'(',')','-','_','=','+','[',']','{','}'},
            {';',':',',','.','<','>','/','?','~','`'},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };

    char current_row[SIZE];
    printf("Matrix printed row-wise:\n");
    print_row_wise(matrix, 0, 0, current_row);

    char current_col[SIZE];
    printf("\nMatrix printed column-wise:\n");
    print_col_wise(matrix, 0, 0, current_col);

    return 0;
}