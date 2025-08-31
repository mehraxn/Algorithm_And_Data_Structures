#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list2_s {
        int n;
        int rep;
        struct list2_s *next;
};

struct list1_s {
        char *name;
        struct list2_s *list;
        struct list1_s *next;
};

typedef struct list1_s list1_t;
typedef struct list2_s list2_t;

list1_t *insert(char *name);

int main() {
        list1_t *res = insert("input.txt");
        // show everything (and while we are here, let's free everything
        list1_t *curr = res;
        while(curr != NULL ) {
                printf("%s\n   ",curr->name);
                list2_t *inner = curr->list;
                while(inner != NULL ) {
                        printf("-> %d (%d) ",inner->n,inner->rep);
                        list2_t *temp = inner;
                        inner = inner->next;
                        free(temp);
                }
                printf("\n");
                list1_t *temp = curr;
                curr = curr->next;
                free(temp);
        }
        return 0;
}

list1_t *search(list1_t *list, char *name) {
        while(list != NULL ) {
                if( strcmp(list->name,name) == 0 ) {
                        return list;
                }
                list = list->next;
        }
        return NULL;
}
list1_t *add_n(list1_t *item, int n) {
        list2_t *curr = item->list;
        while(curr != NULL ) {
                if( curr->n == n ) {
                        (curr->rep)++;
                        return item;
                }
                curr = curr->next;
        }
        // create a new list2_t item
        list2_t *new = (list2_t *)malloc(sizeof(list2_t));
        new->n = n;
        new->rep = 1;
        // update pointer
        new->next = item->list;
        item->list = new;
        return item;
}

list1_t *insert(char *filename) {
        FILE *f = fopen(filename,"r");
        char name[101];
        int n;
        list1_t *head = NULL;
        while( fscanf(f,"%s %d",name, &n) != EOF ) {
                if( head == NULL ) {
                        head = (list1_t *)malloc(sizeof(list1_t));
                        head->name = strdup(name);
                        head->list = NULL;
                        head->next = NULL;
                }
                list1_t *ref = search(head, name);
                if( ref == NULL ) {
                        ref = (list1_t *)malloc(sizeof(list1_t));
                        ref->name = strdup(name);
                        ref->list = NULL;
                        ref->next = head;
                        head = ref;
                }
                add_n(ref,n);
        }
        return head;
}
