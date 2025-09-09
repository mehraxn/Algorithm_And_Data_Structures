#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node_e {
    char *s;
    struct node_e *next;
} node_t;

void string_to_fifo(char *, node_t **, node_t **);
void enqueue(node_t **, char *);
node_t *new_node();
// Only for Debug
void traversal(node_t *);

int main(int argc, char **argv) {
    node_t *letter, *digit;

#if 1
    letter = digit = NULL;
    string_to_fifo("abc12345xyz333fgew", &letter, &digit);
#endif
#if 0
    letter = digit = NULL;
    string_to_fifo(argv[1], &letter, &digit);
#endif
    // Only for Debug
    fprintf(stdout, "Digit List : ");
    traversal(digit);
    fprintf(stdout, "Letter List: ");
    traversal(letter);
    // Must free letter and digit ... !!!
    return 1;
}

void string_to_fifo(char *s, node_t **letter, node_t **digit) {
    // nld = nothing-digit-letter = 0-1-2
    int i, ndl;
    char *p, *tmp;

    tmp = malloc((strlen(s) + 1) * sizeof(char));
    if (tmp == NULL) {
        fprintf(stderr, "Allocation error.\n");
        exit(0);
    }
    ndl = i = 0;

    for (p = s; *p != '\0'; p++) {
        if (ndl == 0) {
            tmp[i++] = *p;
            if (isdigit(*p))
                ndl = 1;
            else
                ndl = 2;
        } else {
            if (isdigit(*p)) {
                if (ndl == 2) {
                    tmp[i++] = '\0';
                    enqueue(letter, tmp);
                    ndl = 1;
                    i = 0;
                    tmp[i++] = *p;
                } else {
                    tmp[i++] = *p;
                }
            } else {
                if (ndl == 1) {
                    tmp[i++] = '\0';
                    enqueue(digit, tmp);
                    ndl = 2;
                    i = 0;
                    tmp[i++] = *p;
                } else {
                    tmp[i++] = *p;
                }
            }
        }
    }

    if (ndl == 1) {
        tmp[i++] = '\0';
        enqueue(digit, tmp);
    } else {
        tmp[i++] = '\0';
        enqueue(letter, tmp);
    }
    return;
}

void enqueue(node_t **tail, char *s) {
    node_t *p, *tmp;
    tmp = *tail;
    p = new_node();
    p->s = strdup(s);
    if (tmp == NULL) {
        tmp = p;
        tmp->next = tmp;
    } else {
        p->next = tmp->next;
        tmp->next = p;
        tmp = p;
    }
    *tail = tmp;
    return;
}

node_t *new_node() {
    node_t *p;
    p = (node_t *)malloc(sizeof(node_t));
    if (p == NULL) {
        fprintf(stderr, "Allocation failed.");
        exit(EXIT_FAILURE);
    }
    return p;
}

// Only for Debug
void traversal(node_t *tail) {
    node_t *tmp;
    fprintf(stdout, "tail ");
    if (tail == NULL) {
        fprintf(stdout, "-> NULL\n");
    } else {
        tmp = tail->next;
        do {
            fprintf(stdout, "-> %s ", tmp->s);
            tmp = tmp->next;
        } while (tmp != tail->next);
    }
    fprintf(stdout, "\n");
    return;
}
