#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LIST2 list2;
typedef struct LIST1 list1;

struct LIST1 {
    char *name_state;
    int size;       // number of actors expected in that state
    list1 *next;
    list2 *right;   // linked list of actors
};

struct LIST2 {
    char *name_actor;
    int size;       // length of actor's name
    list2 *next;
};

// Create new actor node, size = length of actor's name
list2* create_actor(char *name) {
    list2 *new_actor = (list2 *)malloc(sizeof(list2));
    new_actor->name_actor = strdup(name);
    new_actor->size = strlen(name);
    new_actor->next = NULL;
    return new_actor;
}

// Create new state node, size = number of actors
list1* create_state(char *name, int size) {
    list1 *new_state = (list1 *)malloc(sizeof(list1));
    new_state->name_state = strdup(name);
    new_state->size = size;
    new_state->next = NULL;
    new_state->right = NULL;
    return new_state;
}

// Add actor to state's actor linked list
void add_actor(list1 *state, char *actor_name) {
    list2 *new_actor = create_actor(actor_name);
    if (state->right == NULL) {
        state->right = new_actor;
    } else {
        list2 *temp = state->right;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_actor;
    }
}

// Parse the input file and build the list of states and actors
list1* parse_file(FILE *fp) {
    char line[256];
    list1 *head = NULL;
    list1 *current_state = NULL;

    while (fgets(line, sizeof(line), fp)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        // Skip empty lines
        if (strlen(line) == 0) continue;

        int num;
        char state_name[50];

        // Check if line starts with number and a state name
        if (sscanf(line, "%d %49s", &num, state_name) == 2) {
            list1 *new_state = create_state(state_name, num);
            if (head == NULL) {
                head = new_state;
            } else {
                current_state->next = new_state;
            }
            current_state = new_state;
        } else {
            // Otherwise treat line as actor name
            if (current_state != NULL) {
                add_actor(current_state, line);
            }
        }
    }
    return head;
}

// Print the entire list structure for verification
void print_list(list1 *head) {
    list1 *temp_state = head;
    while (temp_state != NULL) {
        printf("State: %s, Number of actors: %d\n", temp_state->name_state, temp_state->size);
        list2 *temp_actor = temp_state->right;
        while (temp_actor != NULL) {
            printf("  Actor: %s (Length: %d)\n", temp_actor->name_actor, temp_actor->size);
            temp_actor = temp_actor->next;
        }
        temp_state = temp_state->next;
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    list1 *list = parse_file(fp);
    fclose(fp);

    print_list(list);

    // Note: add code to free allocated memory if desired.

    return 0;
}
