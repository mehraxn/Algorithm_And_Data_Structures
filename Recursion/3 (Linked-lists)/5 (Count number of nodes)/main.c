#include <stdio.h>

 typedef struct list_t list_t;
 struct list_t{
    int val;
    struct list_t * next ;
};


 int count (list_t *p) {
    if (p == NULL)
    return 0;
 return (1 + count(p->next));
 }