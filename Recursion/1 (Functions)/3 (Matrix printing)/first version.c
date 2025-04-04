#include <stdio.h>
#define SIZE 10

// Function to print the matrix row by row recursively
void print_row_wise(char matrix[SIZE][SIZE], int row, int col) {
    if (row >= SIZE) {
        return; // Base case: all rows printed
    }
    if (col >= SIZE) {
        printf("\n"); // End of current row, move to next line
        print_row_wise(matrix, row + 1, 0); // Recurse to next row
    } else {
        printf("%c ", matrix[row][col]); // Print current element
        print_row_wise(matrix, row, col + 1); // Recurse to next column
    }
}

// Function to print the matrix column by column recursively
void print_col_wise(char matrix[SIZE][SIZE], int col, int row) {
    if (col >= SIZE) {
        return; // Base case: all columns printed
    }
    if (row >= SIZE) {
        printf("\n"); // End of current column, move to next line
        print_col_wise(matrix, col + 1, 0); // Recurse to next column
    } else {
        printf("%c ", matrix[row][col]); // Print current element
        print_col_wise(matrix, col, row + 1); // Recurse to next row in current column
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

    printf("Printing matrix row-wise:\n");
    print_row_wise(matrix, 0, 0);

    printf("\nPrinting matrix column-wise:\n");
    print_col_wise(matrix, 0, 0);

    return 0;
}