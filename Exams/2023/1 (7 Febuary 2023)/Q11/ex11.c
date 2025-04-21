#include <stdio.h>
#include <stdlib.h>


#define M 6

void check (char **m, int n);
void printMatrix(char **m, int n);

int main() {
    char **mat;

    char s0[M] = {'X', 'A', 'E', 'I', 'O', 'U'};
    char s1[M] = {'P', 'X', 'A', 'E', 'I', 'O'};
    char s2[M] = {'P', 'U', 'X', 'A', 'E', 'I'};
    char s3[M] = {'I', 'O', 'U', 'X', 'A', 'E'};
    char s4[M] = {'P', 'I', 'O', 'U', 'X', 'A'};
    char s5[M] = {'P', 'Y', 'Z', 'X', 'Y', 'X'};

    mat = malloc(M * sizeof(int));
    for(int i = 0; i < M; i++)
        mat[i] = malloc(M * sizeof(int));

    mat[0] = s0;
    mat[1] = s1;
    mat[2] = s2;
    mat[3] = s3;
    mat[4] = s4;
    mat[5] = s5;


    printMatrix(mat, M);
    check(mat, M);

    return 0;
}

void check (char **m, int n) {

    //Creates an array counting the occurrences of each letter
    int *occurrence = calloc(26, sizeof(int));
    int maxRep = -1;    //The maximum numbers of repetitions of the same letter in a row or column
    int repRow = -1;    //The row with the most repetitions
    int repCol = -1;    //The column with the most repetitions
    if(occurrence == NULL)
        return;

    //We first count the occurrences of letters among a row
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            occurrence[m[i][j]-'A'] += 1;               //We assume all letters are uppercase, and we add 1 to its respective counter
            if(maxRep < occurrence[m[i][j]-'A']) {      //If we have more repetition of a letter along a row than the previusly held record
                maxRep = occurrence[m[i][j]-'A'];       //We update the value of the most amount of repetitions
                repRow = i;                             //And store the number of the row that containing said repetitions
                repCol = -1;
            }
        }

        for(int z = 0; z < 26; z++)                     //If no duplicate letters have been found along a row we reset all counters
            occurrence[z] = 0;
    }

    //We now perform the same set of operation along the columns
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {

            occurrence[m[i][j]-'A'] += 1;

            if(maxRep < occurrence[m[i][j]-'A']) {
                maxRep = occurrence[m[i][j]-'A'];
                repCol = j;
                repRow = -1;
            }

        }
        for(int z = 0; z < 26; z++)
            occurrence[z] = 0;
    }

    if(repRow != -1) {                              //repRow is different from -1 only if a row had the most amount of repetitions
        for(int c = 0; c < n; c++)
            printf("%c ", m[repRow][c]);     //And in that case we print said row
        printf("\n");
    } else if (repCol != -1) {                      //Otherwise, if the biggest amount of repetitions was on a column
        for(int c = 0; c < n; c++)
            printf("%c ", m[c][repCol]);     //We print said column
        printf("\n");
    }

    free(occurrence);
}

void printMatrix(char **m, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}