#include "item.h"

#define MAX 100

/*
 *  read an item from file
 */
int item_read(FILE *fp, void **data_ptr)
{
  char word[MAX];

  if (fscanf(fp, "%s", word) == EOF) {
    return EOF;
  }

  *data_ptr = util_strdup(word);

  return 1;
}

/*
 *  print an item on file
 */
void item_print(FILE *fp, void *ptr)
{
  item_t data = (item_t)ptr;
  fprintf(fp, "%s", data);
}

/*
 *  compare two items 
 */
int item_compare(void *ptr1, void *ptr2)
{
  item_t data1 = (item_t)ptr1;
  item_t data2 = (item_t)ptr2;

  return strcmp(data1, data2);
}

/*
 *  free an item 
 */
void item_dispose(void *ptr)
{
  free(ptr);
}
