
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD 26
#define N 20

#define filein "text.txt"
#define filesq "sequences.txt"

int searchWord(char seq[MAX_WORD]);
int readWord(FILE *fp, char word[MAX_WORD]);

int main() {
    int i, n;
    char seq[MAX_WORD];
    FILE *fsq;

    fsq = fopen(filesq, "r");
    if (fsq == NULL)
        exit(-1);

    fscanf(fsq, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(fsq, "%s", seq);
        printf("Sequence %s is contained in: \n", seq);
        if (searchWord(seq)==0) {
            printf("Sequence not found\n");
        }
        printf("\n");
    }

    fclose(fsq);

    return 0;
}

int stristr(char *s1, char *s2) {
    //put comment
    int i = 0, j = 0;

    while(s1[i] != '\0'  && s2[j] != '\0') {
        if(tolower(s1[i]) == tolower(s2[j])) {
            j++ ;
        } else {
            j = 0 ;
        }
        i++;
    }
    return (s2[j] == '\0') ;
}

int searchWord(char seq[MAX_WORD]) {
    FILE *fp;
    char word[MAX_WORD];
    int i, count;

    fp = fopen(filein, "r");
    if (fp == NULL) {
        printf("Error opening words file\n");
        exit(-1);
    }

    for (i=1,count=0; readWord(fp,word)>0; i++) {
        if (stristr(word, seq)) {
            printf("%s (position %d)\n", word, i);
            count++;
        }
    }

    fclose(fp);

    return count;
}

int readWord(FILE *fp, char word[MAX_WORD]) {
    int i;
    // look for first alphanumeric character
    do {
        fscanf(fp, "%c", &word[0]);
    } while (!feof(fp) && !isalnum(word[0]));

    if (feof(fp)) return 0;

    // look for first non-alphanumeric character
    i=0;
    do {
        fscanf(fp, "%c", &word[++i]);
    } while (!feof(fp) && isalnum(word[i]));
    // add newline
    word[i] = '\0';
    //  printf("word: %s\n", word);
    return i;
}

