#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s list_t;
struct list_s {
    char name[20];
    char surname[20];
    list_t *next;
};

int order_insert(list_t *list, char *surname, char *name) {

    // Check if person already exists
    list_t *temp = list;
    while (temp) {
        if (strcmp(temp->name, name) == 0 && strcmp(temp->surname, surname) == 0) {
            return 0;  // Person already exists
        }
        temp = temp->next;
    }

    // Create new node
    list_t *node = (list_t *)malloc(sizeof(list_t));
    if (node == NULL) {
        return 0;  // Memory allocation failed
    }
    strcpy(node->name, name);
    strcpy(node->surname, surname);
    node->next = NULL;

    // If list is empty, cannot insert (limitation of this signature)
    if (list == NULL) {
        free(node);
        return 0;
    }

    // Check if new node should be inserted after first node but before second
    if (list->next == NULL ||
        strcmp(list->next->surname, surname) > 0 ||
        (strcmp(list->next->surname, surname) == 0 && strcmp(list->next->name, name) > 0)) {
        node->next = list->next;
        list->next = node;
        return 1;
    }

    // Find correct position to insert
    temp = list;
    while (temp->next != NULL) {
        // Check if we should insert between temp and temp->next
        if (strcmp(temp->next->surname, surname) > 0 ||
            (strcmp(temp->next->surname, surname) == 0 && strcmp(temp->next->name, name) > 0)) {
            node->next = temp->next;
            temp->next = node;
            return 1;
        }
        temp = temp->next;
    }

    // Insert at end
    temp->next = node;
    return 1;
}

// Test function
void print_list(list_t *list) {
    while (list) {
        printf("%s, %s\n", list->surname, list->name);
        list = list->next;
    }
    printf("\n");
}

void free_list(list_t *list) {
    while (list) {
        list_t *temp = list;
        list = list->next;
        free(temp);
    }
}
