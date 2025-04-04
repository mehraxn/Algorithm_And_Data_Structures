#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 21

/* function prototypes */
char ***read_file(int *Rptr, int *Cptr);
char **merge_matrix(char ***matrix, int R, int C);
void print_result(char **array, int dim);
void free_memory(char ***matrix, char **array, int R, int C);

/*
 *  main program
 */
int main(void) {
  char ***matrix, **array;
  int R, C;

  matrix = read_file(&R, &C); 
  array = merge_matrix(matrix, R, C);
  print_result(array, R*C);
  free_memory(matrix, array, R, C);

  return EXIT_SUCCESS;
}

/*
 *  load the string matrix
 */
char ***read_file(int *Rptr, int *Cptr) {
  char word[MAX_LEN], ***mx;
  int r, c, i, j;
  FILE *fp;

  printf("Input file name: ");
  scanf("%s", word);
  fp = fopen(word, "r");
  if (fp == NULL) {
    printf("Error opening the input file.\n");
    exit(EXIT_FAILURE);
  }

  /* read dimensions and allocate the matrix */
  fscanf(fp, "%d %d", &r, &c);
  mx = (char ***)malloc(r * sizeof(char **));
  if (mx == NULL) {
    printf("Memory allocation error.\n");
    exit(EXIT_FAILURE);
  }
  for (i=0; i<r; i++) {
    mx[i] = (char **)malloc(c * sizeof(char *));
    if (mx[i] == NULL) {
      printf("Memory allocation error.\n");
      exit(EXIT_FAILURE);
    }
  }

  /* parse the file contents */
  for (i=0; i<r; i++) {
    for (j=0; j<c; j++) {
      fscanf(fp, "%s", word);
      /* check that the i-th row is sorted */
      if ((j>0) && (strcmp(mx[i][j-1], word)>0)) {
        printf("Error: row %d NOT sorted.\n", i+1);
        exit(EXIT_FAILURE);
      }
      mx[i][j] = strdup(word);
      if (mx[i][j] == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
      }
    }
  }

  fclose(fp);
  *Rptr = r;
  *Cptr = c;
  return mx;
}

/*
 *  merge the matrix rows into a sorted array
 */
char **merge_matrix(char ***matrix, int R, int C) {
  int i, j, min_idx, *idx;
  char **array, *min_word;

  /* allocate the final array, plus an auxiliary one */
  array = (char **)malloc(R * C * sizeof(char *));
  idx = (int *)calloc(R, sizeof(int));
  if ((array == NULL) || (idx == NULL)) {
    printf("Memory allocation error.\n");
    exit(EXIT_FAILURE);
  }

  /* merge the matrix rows */
  i = 0;
  while (i < R*C) {
    min_idx = -1;
    for (j=0; j<R; j++) {
      if (idx[j] < C) {
        if ((min_idx==-1) || (strcmp(matrix[j][idx[j]], min_word)<0)) {
          min_idx = j;
          min_word = matrix[min_idx][idx[min_idx]];
        }
      }
    }
    array[i++] = matrix[min_idx][idx[min_idx]++];
  }

  free(idx);
  return array;
}

/*
 *  print the output file
 */
void print_result(char **array, int dim) {
  char name[MAX_LEN];
  FILE *fp;
  int i;

  printf("Output file name: ");
  scanf("%s", name);
  fp = fopen(name, "w");
  if (fp == NULL) {
    printf("Error opening the output file.\n");
    exit(EXIT_FAILURE);  
  }

  fprintf(fp, "%d\n", dim);
  for (i=0; i<dim; i++) {
    fprintf(fp, "%s\n", array[i]);
  }

  fclose(fp);
}

/*
 *  quit all the allocated memory
 */
void free_memory(char ***matrix, char **array, int R, int C) {
  int i, j;

  for (i=0; i<R; i++) {
    for (j=0; j<C; j++) {
      free(matrix[i][j]);
    }
    free(matrix[i]);
  }
  free(matrix);
  free(array);
}
