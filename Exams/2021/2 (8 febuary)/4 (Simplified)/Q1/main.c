#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct element_s {
    char *name;
    struct element_s *left;
    struct element_s *right;
} element_t;

// Function to insert a string into the linked list
void insert(element_t **head, element_t **tail, char *str) {
    // Create a new node
    element_t *newNode = (element_t *)malloc(sizeof(element_t));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Allocate memory for the string and copy it
    newNode->name = strdup(str);
    if (!newNode->name) {
        fprintf(stderr, "Memory allocation for string failed\n");
        free(newNode);
        return;
    }

    newNode->left = NULL;
    newNode->right = NULL;

    // Handle the empty list case
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    // Traverse the list to find the correct position
    element_t *current = *head;
    while (current && strcmp(current->name, str) < 0) {
        current = current->right;
    }

    // Insert at the head
    if (current == *head) {
        newNode->right = *head;
        (*head)->left = newNode;
        *head = newNode;
        return;
    }

    // Insert at the tail
    if (current == NULL) {
        newNode->left = *tail;
        (*tail)->right = newNode;
        *tail = newNode;
        return;
    }

    // Insert in the middle
    newNode->right = current;
    newNode->left = current->left;
    if (current->left) {
        current->left->right = newNode;
    }
    current->left = newNode;
}

// Function to print the list from head to tail
void printListForward(element_t *head) {
    element_t *current = head;
    while (current) {
        printf("%s ", current->name);
        current = current->right;
    }
    printf("\n");
}

// Function to print the list from tail to head
void printListBackward(element_t *tail) {
    element_t *current = tail;
    while (current) {
        printf("%s ", current->name);
        current = current->left;
    }
    printf("\n");
}

// Free the entire list
void freeList(element_t *head) {
    while (head) {
        element_t *temp = head;
        head = head->right;
        free(temp->name);
        free(temp);
    }
}

// Example usage
int main() {
    element_t *head = NULL;
    element_t *tail = NULL;

    insert(&head, &tail, "delta");
    insert(&head, &tail, "alpha");
    insert(&head, &tail, "charlie");
    insert(&head, &tail, "bravo");

    printf("List from head to tail:\n");
    printListForward(head);

    printf("List from tail to head:\n");
    printListBackward(tail);

    freeList(head);

    return 0;
}
