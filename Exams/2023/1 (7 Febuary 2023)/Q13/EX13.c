#include <stdio.h>
#include <stdlib.h>

void recursiveGenerate(int *num, int size, int i, int evenSum, int oddSum, FILE *f);
void generate (char *name, int n);

int main() {
    generate("output.txt", 5);
    return 0;
}

//Wrapper function
void generate (char *name, int n) {
    int *num;
    FILE *f;
    if((f = fopen(name, "w")) == NULL) return;

    num = calloc(n, sizeof(int));
    if(num == NULL) return;

    recursiveGenerate(num, n, 0,  0, 0, f);
    free(num);
}

void recursiveGenerate(int *num, int size, int i, int evenSum, int oddSum, FILE *f) {
    if(i >= size) {                             //After we have generated enough digits
        if(evenSum == oddSum) {                 //If the sum of odds and even digit is the same
            for(int j = 0; j < size; j++)       //We write all the digits in the file
                fprintf(f,"%d", num[j]);
            fprintf(f,"\n");
        }
        return;                                 //And return
    }

    int isOdd = (i+1)%2;                       //1 means we are on an odd index, 0 means we are on an even one. A +1 is needed because of 0-indexing

    for(int j = 0; j < 10; j+=2) {              //Generation of the digits 0 2 4 6 8
        num[i] = j+isOdd;                       //If we are at an odd index we add 1, so we will insert 1 3 5 7 9

        if(isOdd == 1) oddSum += j+1;           //We add values to either the odd or even counter
        else evenSum += j;                      //depending on the index we are on

        recursiveGenerate(num, size, i+1, evenSum, oddSum,f); //We call the function recursively going to the next index

        if(isOdd == 1) oddSum -= (j+1);         //We decrease either counter by the same amount we incremented before
        else evenSum -= j;
    }
    return;
}
