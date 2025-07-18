#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

/* function prototypes */
void generate_r(char *word, char *anagram, int *used, int length, int n);

/* main program */
int main(void) {
    char word[MAX], anagram[MAX];
    int used[MAX];
    int length, i;

    fprintf(stdout, "Input a word: ");
    scanf("%s", word);
    length = strlen(word);
    anagram[length] = '\0';
    for (i = 0; i < length; i++) {
        used[i] = 0;
    }

    fprintf(stdout, "Anagrams:\n");
    generate_r(word, anagram, used, length, 0);
    return EXIT_SUCCESS;
}

/* add a char in position n of the anagram taking it from the (unused) available chars in the word */
void generate_r(char *word, char *anagram, int *used, int length, int n) {
    int i;

    if (n == length) {
        fprintf(stdout, " %s\n", anagram);
        return;
    }

    for (i = 0; i < length; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            anagram[n] = word[i];
            generate_r(word, anagram, used, length, n + 1);
            used[i] = 0;
        }
    }

    return;
}
