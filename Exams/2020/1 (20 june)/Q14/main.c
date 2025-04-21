#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the linked list
typedef struct list_s {
    char *last;           // Last name
    char *first;          // First name
    int n;                // Number of examinations passed
    struct list_s *right; // Pointer to the next element in the list
} list_t;

/**
 * Function to compare two nodes based on the sorting criteria:
 * 1. Last name
 * 2. First name
 * 3. Number of examinations passed
 */
int compare_nodes(list_t *a, list_t *b) {
    int cmp_last = strcmp(a->last, b->last);
    if (cmp_last != 0) {
        return cmp_last;
    }

    int cmp_first = strcmp(a->first, b->first);
    if (cmp_first != 0) {
        return cmp_first;
    }

    return a->n - b->n;
}

/**
 * Function to insert a node into a sorted list.
 */
list_t* sorted_insert(list_t *sorted, list_t *new_node) {
    // Special case: Insert at the beginning or before the head
    if (sorted == NULL || compare_nodes(new_node, sorted) < 0) {
        new_node->right = sorted;
        return new_node;
    }

    // Find the correct position to insert
    list_t *current = sorted;
    while (current->right != NULL && compare_nodes(new_node, current->right) >= 0) {
        current = current->right;
    }

    // Insert the new node
    new_node->right = current->right;
    current->right = new_node;

    return sorted;
}

/**
 * Function to sort the linked list using insertion sort.
 */
void sort_list(list_t **head) {
    list_t *sorted = NULL; // Start with an empty sorted list
    list_t *current = *head;

    while (current != NULL) {
        // Save the next node to process
        list_t *next = current->right;

        // Insert the current node into the sorted list
        sorted = sorted_insert(sorted, current);

        // Move to the next node
        current = next;
    }

    // Update the head to the new sorted list
    *head = sorted;
}

/**
 * Helper function to create a new node.
 */
list_t* create_node(const char *last, const char *first, int n) {
    list_t *node = (list_t *)malloc(sizeof(list_t));
    if (!node) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }

    node->last = strdup(last);
    node->first = strdup(first);
    node->n = n;
    node->right = NULL;

    return node;
}

/**
 * Helper function to print the list.
 */
void print_list(list_t *head) {
    while (head != NULL) {
        printf("Last: %s, First: %s, Exams: %d\n", head->last, head->first, head->n);
        head = head->right;
    }
}

/**
 * Helper function to free the list.
 */
void free_list(list_t *head) {
    while (head != NULL) {
        list_t *temp = head;
        head = head->right;
        free(temp->last);
        free(temp->first);
        free(temp);
    }
}

/**
 * Main function to demonstrate the sorting functionality.
 */
int main() {
    // Create a sample linked list
    list_t *head = NULL;

    head = create_node("Smith", "John", 5);
    head->right = create_node("Doe", "Jane", 10);
    head->right->right = create_node("Smith", "Alice", 3);
    head->right->right->right = create_node("Brown", "Bob", 7);

    printf("Original List:\n");
    print_list(head);

    // Sort the list
    sort_list(&head);

    printf("\nSorted List:\n");
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}
