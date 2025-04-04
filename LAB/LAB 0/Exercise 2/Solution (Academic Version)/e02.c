#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE  4
#define MAX_REC  50

/* struct declaration */
typedef struct {
  float x;
  float y;
} point_t;

typedef struct {
  char code[MAX_CODE+1];
  point_t p1;
  point_t p2;
  float area;
  float perimeter;
} rectangle_t;

/* function prototypes */
void file_read (char *, rectangle_t [], int *);
void sort1 (rectangle_t [], int);
void sort2 (rectangle_t [], int);
void save (char *, rectangle_t [], int);

/*
 *  main program
 */
int
main (
  int argc,
  char *argv[]
  )
{
  rectangle_t rct[MAX_REC];
  int rectangle_num;

  if (argc!=4) {
    fprintf (stderr, "Wrong number of parameter.\n");
    return (1);
  }

  /* open files */
  file_read (argv[1], rct, &rectangle_num);
  sort1 (rct, rectangle_num);
  save (argv[2], rct, rectangle_num);
  sort2 (rct, rectangle_num);
  save (argv[3], rct, rectangle_num);

  return (EXIT_SUCCESS);
}

/*
 *  rectangle load
 */

void file_read (
  char *name,
  rectangle_t rct[],
  int *num
  )
{
  FILE *fin;
  float x, y, l1, l2;
  int i;

  fin = fopen(name, "r");
  if (fin == NULL) {
    fprintf (stderr, "Input file not readable!\n");
    exit (0);
  }

  *num = 0;
  while (fscanf(fin, "%s%f%f", name, &x, &y) != EOF && *num < MAX_REC) {
    for (i=0; i<*num; i++) 
      if (strcmp(name, rct[i].code) == 0)
        break;
    if (i == *num) {
      /* rectangle NOT found: first point */
      strcpy(rct[i].code, name);
      rct[i].p1.x = x;
      rct[i].p1.y = y;
      *num = *num + 1;
    } else {
      /* rectangle found: second point */
      rct[i].p2.x = x;
      rct[i].p2.y = y;
#if 0
      l1 = fabs (x - rct[i].p1.x);
      l2 = fabs (y - rct[i].p1.y);
      //printf ("fabs -> %f %f\n", l1, l2);
#else
      l1 = x - rct[i].p1.x;
      l2 = y - rct[i].p1.y;
      if (l1<0) l1 = (-l1);
      if (l2<0) l2 = (-l2);
      //printf ("if -> %f %f\n", l1, l2);
#endif
      rct[i].area = l1 * l2;
      rct[i].perimeter = 2 * (l1 + l2);
    }
  }

#if 0
  /* data structure initialization */
  for (i=0; i<*num; i++) {
    fprintf (stdout, "%s   (%.2f,%.2f)-(%.2f,%.2f)   area=%.2f   perimetro=%.2f\n",
      rct[i].code,
      rct[i].p1.x, rct[i].p1.y, rct[i].p2.x, rct[i].p2.y,
      rct[i].area, rct[i].perimeter);
  }
#endif

  fclose(fin);

  return;
}

/*
 *  rectangle sorting
 */
void
sort1 (
  rectangle_t rct[],
  int num_rct
) {
  rectangle_t current;
  int i, j;

  for (i=1; i<num_rct; i++) {
    current = rct[i];
    j = i;
    while ((--j >= 0) && (current.area > rct[j].area)) {
      rct[j+1] = rct[j];
    }
    rct[j+1] = current;
  }

  return;
}

/*
 *  rectangle sorting
 */
void
sort2 (
  rectangle_t rct[],
  int num_rct
) {
  rectangle_t current;
  int i, j;

  for (i=1; i<num_rct; i++) {
    current = rct[i];
    j = i;
    while ((--j >= 0) && (current.perimeter > rct[j].perimeter)) {
      rct[j+1] = rct[j];
    }
    rct[j+1] = current;
  }

  return;
}

/*
 *  result display
 */
void
save (
  char *name,
  rectangle_t rct[],
  int num_rct
  )
{
  FILE *fout;
  int i;

  fout = fopen (name, "w");
  if (fout == NULL) {
    fprintf (stderr, "Input file not readable!\n");
    return;
  }

  for (i=0; i<num_rct; i++) {
    fprintf (fout, "%s\n", rct[i].code);
  }

  fclose (fout);

  return;
}
