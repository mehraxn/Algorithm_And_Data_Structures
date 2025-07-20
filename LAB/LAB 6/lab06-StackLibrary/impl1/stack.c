#include "stackPrivate.h"

/*
 *  create a new empty stack
 */
stack_t *stack_init(int size)
{
  stack_t *sp;

  sp = (stack_t *)util_malloc(sizeof(stack_t));
  sp->size = size;
  sp->index = 0;
  sp->array = (void **)util_malloc(size*sizeof(void *));
  return sp;
}

/*
 *  return the number of elements stored in the stack
 */
int stack_count(stack_t *sp)
{
  return (sp!=NULL) ? sp->index : 0;
}

/*
 *  store a new value in the stack (LIFO policy)
 */
int stack_push(stack_t *sp, void *data)
{
  if (sp==NULL || sp->index>=sp->size) {
    return 0;
  }

  sp->array[sp->index++] = data;
  return 1;
}

/*
 *  extract a value from the stack (LIFO policy)
 */
int stack_pop(stack_t *sp, void **data_ptr)
{
  if (sp==NULL || sp->index<=0) {
    return 0;
  }

  *data_ptr = sp->array[--sp->index];
  return 1;
}

/*
 *  print all the stack elements (LIFO policy)
 */
void stack_print(FILE *fp, stack_t *sp, void (*print)(FILE *, void *))
{
  int i;

  if (sp != NULL) {
    for (i=sp->index-1; i>=0; i--) {
      print(fp, sp->array[i]);
      fprintf(fp, "\n");
    }
  }
}

/*
 *  deallocate all the memory associated to the stack
 */
void stack_dispose(stack_t *sp, void (*quit)(void *))
{
  int i;

  if (sp != NULL) {
    if (quit != NULL) {
      for (i=0; i<sp->index; i++) {
        quit(sp->array[i]);
      }
    }
    free(sp->array);
    free(sp);
  }
}
