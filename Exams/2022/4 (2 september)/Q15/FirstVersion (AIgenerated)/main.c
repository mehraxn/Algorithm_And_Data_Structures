#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the list structure
typedef struct list list_t;

struct list {
    char *name;    // Pointer to dynamically allocated string for the name
    char *surname; // Pointer to dynamically allocated string for the surname
    list_t *next;  // Pointer to the next node in the list
};

/**
 * Function to insert a new person into the ordered list based on surname (primary key)
 * and name (secondary key). Returns 0 if the person is already present, 1 if insertion succeeds.
 */
int order_insert(list_t *list, char *surname, char *name) {
    list_t *head = list; // Pointer to traverse the list
    list_t *prev = NULL; // Pointer to keep track of the previous node

    // Traverse the list to check if the person already exists
    while (head != NULL) {
        if (strcmp(surname, head->surname) == 0 && strcmp(name, head->name) == 0) {
            return 0; // Person already exists
        }
        prev = head; // Update the previous node
        head = head->next; // Move to the next node
    }

    // Create a new node for the person
    list_t *new_node = (list_t *)malloc(sizeof(list_t));
    if (new_node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for surname and name
    new_node->surname = (char *)malloc(20 * sizeof(char));
    new_node->name = (char *)malloc(20 * sizeof(char));
    if (new_node->surname == NULL || new_node->name == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copy the surname and name into the new node
    strcpy(new_node->surname, surname);
    strcpy(new_node->name, name);
    new_node->next = NULL; // Initialize the next pointer to NULL

    // Insert the new node in the correct position
    head = list; // Reset head to the start of the list
    prev = NULL; // Reset prev to NULL

    while (head != NULL && (strcmp(surname, head->surname) > 0 ||
                            (strcmp(surname, head->surname) == 0 && strcmp(name, head->name) > 0))) {
        prev = head; // Update the previous node
        head = head->next; // Move to the next node
    }

    if (prev == NULL) {
        // Insert at the beginning if no previous node exists
        new_node->next = list;
        list = new_node;
    } else {
        // Insert between prev and head
        prev->next = new_node;
        new_node->next = head;
    }

    return 1; // Insertion succeeded
}

/**
 * Summary of the Function:
 * The `order_insert` function inserts a new node containing a person's name and surname into a linked list,
 * maintaining the order based on surname (primary sorting key) and name (secondary sorting key). If the person
 * already exists in the list (based on both surname and name), the function returns 0. Otherwise, it creates a new
 * node, dynamically allocates memory for the name and surname, and inserts it into the correct position in the list.
 */
