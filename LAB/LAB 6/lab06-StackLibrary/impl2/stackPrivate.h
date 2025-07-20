#ifndef _STACK_PRIVATE
#define _STACK_PRIVATE

#include <stdio.h>
#include "stackPublic.h"
#include "util.h"

/* structure declarations */
typedef struct node {
  void *data;
  struct node *next;
} node_t;

struct stack {
  node_t *head;
  int num;
};

#endif
