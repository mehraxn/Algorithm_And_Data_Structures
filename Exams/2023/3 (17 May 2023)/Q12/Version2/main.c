#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list2_s list2_t;
typedef struct list1_s list1_t;

struct list2_s {
    int value;
    int number;
    list2_t *right;
};

struct list1_s {
    char   *key;
    list1_t *next;
    list2_t *head;
};

list1_t *create_main_list(const char *string) {
    list1_t *root = (list1_t *)malloc(sizeof(list1_t));
    if (!root) return NULL;
    root->key  = strdup(string);
    root->head = NULL;
    root->next = NULL;
    return root;
}
// create_main_list: allocates a new main list node with a string key
// initializes its secondary list pointer and next pointer as NULL.

list2_t *create_secondary_list(int first, int second) {
    list2_t *root = (list2_t *)malloc(sizeof(list2_t));
    if (!root) return NULL;
    root->value  = first;
    root->number = second;
    root->right  = NULL;
    return root;
}
// create_secondary_list: allocates a new secondary list node with a value
// and an initial count, sets its right pointer to NULL.

list1_t *find_main(list1_t *root, const char *key) {
    while (root) {
        if (strcmp(root->key, key) == 0) return root;
        root = root->next;
    }
    return NULL;
}
// find_main: searches the main list for a node with the given key string.
// returns the matching node or NULL if not found.

void add_secondary(list1_t *owner, int value) {
    list2_t *p = owner->head;
    while (p) {
        if (p->value == value) {
            p->number += 1;
            return;
        }
        p = p->right;
    }
    list2_t *node = create_secondary_list(value, 1);
    node->right = owner->head;
    owner->head = node;
}
// add_secondary: adds a value into the secondary list of a main node.
// if the value already exists, increments its count. otherwise creates
// a new secondary node and prepends it to the list.

list1_t *insert(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    char buffer[512];
    char temp_string[256];
    int number;
    list1_t *root = NULL;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "%255s %d", temp_string, &number) == 2) {
            list1_t *node = find_main(root, temp_string);
            if (!node) {
                node = create_main_list(temp_string);
                node->next = root;
                root = node;
            }
            add_secondary(node, number);
        }
    }

    fclose(fp);
    return root;
}
// insert: reads "string integer" pairs from a file. for each line, it
// finds or creates a main node for the string, then adds the integer
// into its secondary list (incrementing count if repeated). returns
// the head of the built main list.
