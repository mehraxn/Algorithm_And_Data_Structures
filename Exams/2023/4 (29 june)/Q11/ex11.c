#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R 4
#define C 5

int getDiagMin(int **mat, int x, int y, int r, int c);
int getDiagMax(int **mat, int x, int y, int r, int c);
int max_diff (int **mat, int r, int c);

int main() {

    /*int mat[R][C] = {{0, -2, 1, 0, 0},
                     {0, 0, 1, 0, 2},
                     {0, 0, 0, 1, 1},
                     {1, 0, 5, 0, 0}};*/

    int **mat;
    mat = malloc(R*sizeof(int *));
    for(int i = 0; i < R; i++) {
        mat[i] = calloc(C, sizeof(int));
    }

    mat[0][1] = -2;
    mat[0][2] = 1;
    mat[1][2] = 1;
    mat[1][4] = 2;
    mat[2][3] = 1;
    mat[2][4] = 1;
    mat[3][0] = 1;
    mat[3][2] = 5;



    max_diff(mat, R, C);

    for(int i = 0; i < R; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}



int max_diff (int **mat, int r, int c) {
    //We first assume the cell providing the maximum difference to be (0, 0)
    int currMaxDiff = abs(getDiagMax(mat, 0, 0, r, c) - getDiagMin(mat, 0, 0, r, c));
    int x = 0, y = 0;   //These coordinates will contain the coordinated of the cell providing the maximum difference
    int currDiff = -1;

    for(int i = 0; i < r; i++) {            //For each row
        for(int j = 0; j < c; j++) {        //And for each column
            currDiff = abs(getDiagMax(mat, i, j, r, c) - getDiagMin(mat, i, j, r, c));  //We calculate the difference between the biggest and smallest elements of its diagonals
            if(currDiff > currMaxDiff) {    //And if the difference is greater than the one we already have
                currMaxDiff = currDiff;     //It will become the new maximum difference
                x = i; y = j;               //And we copy its coordinates
            }
        }
    }

    printf("Difference: %d\nX: %d --- Y: %d", currMaxDiff, x, y);
    return currMaxDiff;
}

//Returns the minimum value along the diagonal and anti-diagonals of cell at coordinates x y
int getDiagMin(int **mat, int x, int y, int r, int c) {
    //Moves are: (UP-LEFT); (UP-RIGHT); (DOWN-LEFT); (DOWN-RIGHT)
    int moveX[] = {-1, -1, 1, 1};
    int moveY[] = {-1, 1, -1, 1};

    int minX = x; int minY = y; //We first assume the cell we start from to be the smallest

    int n;                          //n will be the number of steps taken in a certain direction
    for(int i = 0; i < 4; i++) {    //for each direction
        n = 1;                      //We start with the first step, and as long as we are inside our matrix
        while(x+n*moveX[i] >= 0 && x+n*moveX[i] < r && y+n*moveY[i] >= 0 && y+n*moveY[i] < c ) {
            if(mat[x+n*moveX[i]][y+n*moveY[i]] < mat[minX][minY]) { //We check if the current cell contains a value smaller than the one we have
                minX = x+n*moveX[i];    //If it does, we copy its coordinates
                minY = y+n*moveY[i];
            }
            n++;                    //We go to the next step
        }
    }

    return mat[minX][minY];         //We return the smallest value found
}

//Returns the maximum value along the diagonal and anti-diagonals of cell at coordinates x y
int getDiagMax(int **mat, int x, int y, int r, int c) {
    //Moves are: (UP-LEFT); (UP-RIGHT); (DOWN-LEFT); (DOWN-RIGHT)
    int moveX[] = {-1, -1, 1, 1};
    int moveY[] = {-1, 1, -1, 1};

    int maxX = x; int maxY = y; //We first assume the cell we start from to be the biggest

    int n;                          //n will be the number of steps taken in a certain direction
    for(int i = 0; i < 4; i++) {    //for each direction
        n = 1;                      //We start with the first step, and as long as we are inside our matrix
        while(x+n*moveX[i] >= 0 && x+n*moveX[i] < r && y+n*moveY[i] >= 0 && y+n*moveY[i] < c ) {
            if(mat[x+n*moveX[i]][y+n*moveY[i]] > mat[maxX][maxY]) { //We check if the current cell contains a value bigger than the one we have
                maxX = x+n*moveX[i];                                //If it does, we copy its coordinates
                maxY = y+n*moveY[i];
            }
            n++;                    //We go to the next step
        }
    }

    return mat[maxX][maxY];          //We return the biggest value found
}