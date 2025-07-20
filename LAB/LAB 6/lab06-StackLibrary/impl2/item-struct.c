#include "item.h"

#define MAX 100

/* structure declarations */
struct item {
  int id;
  char *name;
  int exams;
  float avg;
};

/*
 *  read an item from file
 */
int item_read (FILE *fp, void **data_ptr) {
  int result, id, exams;
  char name[MAX];
  float avg;
  item_t data;

  result = fscanf(fp, "%d %s %d %f", &id, name, &exams, &avg);
  if (result != EOF) {
    data = (struct item *)util_malloc(sizeof(struct item));
    data->id = id;
    data->name = util_strdup(name);
    data->exams = exams;
    data->avg = avg;
    *data_ptr = data;
  }

  return result;
}

/*
 *  print an item on file
 */
void item_print (FILE *fp, void *ptr) {
  item_t data = (item_t)ptr;
  fprintf(fp, "%7d %-20s %2d %.2f", data->id, data->name, data->exams, data->avg);
}

/*
 *  compare two items 
 */
int item_compare (void *ptr1, void *ptr2) {
  item_t data1 = (item_t)ptr1;
  item_t data2 = (item_t)ptr2;

  return data1->id - data2->id;
}

/*
 *  free an item 
 */
void item_dispose (void *ptr) {
  item_t data = (item_t)ptr;
  free(data->name);
  free(data);
}
