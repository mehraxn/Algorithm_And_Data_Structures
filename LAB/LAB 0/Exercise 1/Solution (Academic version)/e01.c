#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH   20
#define MAX_WORD_NUMBER  100
#define MAX_LINE_LENGTH  100

/* structure declaration */
typedef struct {
  char word[MAX_WORD_LENGTH+1];
  int occurrences;
} index_t;

/* function prototypes */
void read_words(char *, index_t [], int *);
void read_text(char *, index_t [], int);
void display_index(index_t [], int);
int compare(char *, char *);

/*
 *  main program
 */
int main(int argc, char *argv[])
{
  index_t index[MAX_WORD_NUMBER];
  int n;

  if (argc < 3) {
    printf("Error: missing parameter.\n");
    printf("Run as: %s <text_file> <word_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  read_words(argv[2], index, &n);
  read_text(argv[1], index, n);
  display_index(index, n);

  return EXIT_SUCCESS;
}

/*
 *  read the words file; return the index array
 */
void read_words(char *name, index_t index[], int *num_ptr)
{
  FILE *fp;
  int i;

  fp = fopen(name, "r");
  if (fp == NULL) {
    printf("Error opening file %s.\n", name);
    exit(EXIT_FAILURE);
  }

  i = 0;
  while (i<MAX_WORD_NUMBER && fscanf(fp, "%s", index[i].word)!=EOF) {
    index[i].occurrences = 0;
    i++;
  }
  *num_ptr = i;

  fclose(fp);
  return;
}

/*
 *  read the text file; complete the index infos
 */
void read_text(char *name, index_t index[], int n)
{
  char word[MAX_LINE_LENGTH+1];
  int i, j;
  FILE *fp;

  fp = fopen(name, "r");
  if (fp == NULL) {
    printf("Error opening file %s.\n", name);
    exit(EXIT_FAILURE);
  }

  while (fscanf(fp, "%s", word) != EOF) {
    /* look for the word in the index */
    for (j=0; j<n; j++) {
      if (compare(word, index[j].word) == 1) {
        /* found an occurrence for a word */
        index[j].occurrences++; 
      }	
    }
  }

  fclose(fp);
}

/*
 *  output the index contents
 */
void display_index(index_t index[], int n)
{
  int i;
	
  for (i=0; i<n; i++) {
    printf("%s - %d occurrence(s)\n", index[i].word, index[i].occurrences);
  }
}

/*
 *  case insensitive comparison between two strings
 *  return 1 if the strings are equal, 0 otherwise
 */
int compare(char *str1, char *str2)
{
  int i;

  if (strlen(str1) != strlen(str2)) {
    return 0;
  }

  for (i=0; i<strlen(str1); i++) {
    if (tolower(str1[i]) != tolower(str2[i])) {
      return 0;
    }
  }

  return 1;
}
