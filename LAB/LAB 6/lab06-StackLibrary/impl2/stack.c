#include <stdio.h>
#include <stdlib.h>
#include "stackPrivate.h"
#include "util.h"

/*
 *  create a new empty stack
 */
stack_t *stack_init(int size)
{
  stack_t *sp;

  sp = (stack_t *)util_malloc(sizeof(stack_t));
  sp->head = NULL;
  sp->num = 0;

  return sp;
}

/*
 *  return the number of elements stored in the stack
 */
int stack_count(stack_t *sp)
{
  return (sp!=NULL) ? sp->num : 0;
}

/*
 *  store a new value in the stack (LIFO policy)
 */
int stack_push(stack_t *sp, void *data)
{
  node_t *node;

  if (sp == NULL) {
    return 0;
  }

  node = (node_t *)util_malloc(sizeof(node_t));
  node->data = data;
  node->next = sp->head;
  sp->head = node;
  sp->num++;

  return 1;
}

/*
 *  extract a value from the stack (LIFO policy)
 */
int stack_pop(stack_t *sp, void **data_ptr)
{
  node_t *node;

  if (sp==NULL || sp->head==NULL) {
    return 0;
  }

  node = sp->head;
  *data_ptr = node->data;
  sp->head = node->next;
  free(node);
  sp->num--;

  return 1;
}

/*
 *  print all the stack elements (LIFO policy)
 */
void stack_print(FILE *fp, stack_t *sp, void (*print)(FILE *, void *))
{
  node_t *node;

  if (sp != NULL) {
    node = sp->head;
    while (node != NULL) {
      print(fp, node->data);
      node = node->next;
      fprintf(fp, "\n");
    }
  }
}

/*
 *  deallocate all the memory associated to the stack
 */
void stack_dispose(stack_t *sp, void (*quit)(void *))
{
  node_t *node;

  if (sp != NULL) {
    while (sp->head != NULL) {
      node = sp->head;
      sp->head = node->next;
      if (quit != NULL) {
        quit(node->data);
      }
      free(node);
    }
    free(sp);
  }
}
