#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

// Type definition for the secondary list node
typedef struct list2 {
    int value;
    struct list2 *next;
} list2_t;

// Type definition for the primary list node
typedef struct list1 {
    char *name;
    list2_t *values;
    struct list1 *next;
} list1_t;

// Function to create a new primary list node
list1_t *create_list1_node(const char *name) {
    list1_t *node = (list1_t *)malloc(sizeof(list1_t));
    node->name = strdup(name);
    node->values = NULL;
    node->next = NULL;
    return node;
}

// Function to create a new secondary list node
list2_t *create_list2_node(int value) {
    list2_t *node = (list2_t *)malloc(sizeof(list2_t));
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to add a value to the secondary list without duplication
void add_value_to_list2(list2_t **head, int value) {
    list2_t *current = *head;
    while (current) {
        if (current->value == value) {
            return; // Value already exists, no duplication
        }
        current = current->next;
    }
    // Add new value at the head
    list2_t *new_node = create_list2_node(value);
    new_node->next = *head;
    *head = new_node;
}

// Function to find a primary list node by name
list1_t *find_list1_node(list1_t *head, const char *name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to add or update a primary list node
void add_or_update_list1(list1_t **head, const char *name, int *values, int count) {
    list1_t *node = find_list1_node(*head, name);
    if (!node) {
        // Create a new primary list node if it doesn't exist
        node = create_list1_node(name);
        node->next = *head;
        *head = node;
    }
    // Add values to the secondary list
    for (int i = 0; i < count; i++) {
        add_value_to_list2(&(node->values), values[i]);
    }
}

// Function to parse the file and create the list of lists
list1_t *file_to_list_of_lists(const char *name) {
    FILE *file = fopen(name, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    list1_t *head = NULL;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        char string[MAX_STRING_LENGTH];
        int count;

        // Parse the first field (string) and the second field (integer count)
        if (sscanf(line, "%s %d", string, &count) != 2) {
            continue; // Invalid line format, skip
        }

        int *values = (int *)malloc(count * sizeof(int));
        char *ptr = line;
        // Skip the string and count in the line
        ptr += strlen(string) + 1 + (count >= 10 ? 2 : 1);

        // Extract the integer values
        for (int i = 0; i < count; i++) {
            if (sscanf(ptr, "%d", &values[i]) != 1) {
                break;
            }
            ptr = strchr(ptr, ' ') + 1;
        }

        // Add or update the list
        add_or_update_list1(&head, string, values, count);
        free(values);
    }

    fclose(file);
    return head;
}

// Function to print the list of lists
void print_list_of_lists(list1_t *head) {
    while (head) {
        printf("%s: ", head->name);
        list2_t *values = head->values;
        while (values) {
            printf("%d ", values->value);
            values = values->next;
        }
        printf("\n");
        head = head->next;
    }
}

// Function to free the list of lists
void free_list_of_lists(list1_t *head) {
    while (head) {
        list1_t *temp = head;
        head = head->next;

        // Free secondary list
        list2_t *values = temp->values;
        while (values) {
            list2_t *temp2 = values;
            values = values->next;
            free(temp2);
        }

        free(temp->name);
        free(temp);
    }
}

int main() {
    const char *filename = "input.txt";
    list1_t *list = file_to_list_of_lists(filename);

    if (list) {
        printf("List of lists:\n");
        print_list_of_lists(list);
        free_list_of_lists(list);
    }

    return 0;
}
