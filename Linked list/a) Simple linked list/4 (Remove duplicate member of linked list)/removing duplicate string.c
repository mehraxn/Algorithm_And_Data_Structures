#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List list;
struct List {
    char *name;
    list *next;
};

list *remove_duplicate_members(list *head) {
    if (head == NULL || head->next == NULL)
        return head;

    list *temp = head;

    while (temp != NULL) {
        char *temp_string = temp->name;
        list *temp_temp = temp;

        while (temp_temp->next != NULL) {
            if (strcmp(temp_temp->next->name, temp_string) == 0) {
                list *duplicate = temp_temp->next;
                temp_temp->next = temp_temp->next->next;  // Skip duplicate node
                free(duplicate->name); // Free allocated name
                free(duplicate);       // Free node
            } else {
                temp_temp = temp_temp->next;
            }
        }

        temp = temp->next;
    }

    return head;
}



