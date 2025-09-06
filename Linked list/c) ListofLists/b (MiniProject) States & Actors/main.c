#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct LIST2 list2;
typedef struct LIST1 list1;

struct LIST1 {
    char *name_state;
    list1 *next;
    list2 *right;
};

struct LIST2 {
    char *name_actor;
    list2 *next;
};

list2* create_actor(char *name) {
    list2 *new_actor = (list2 *)malloc(sizeof(list2));
    new_actor->name_actor = strdup(name);
    new_actor->next = NULL;
    return new_actor;
}

list1* create_state(char *name) {
    list1 *new_state = (list1 *)malloc(sizeof(list1));
    new_state->name_state = strdup(name);
    new_state->next = NULL;
    new_state->right = NULL;
    return new_state;
}

void add_actor(list1 *state, char *actor_name) {
    list2 *new_actor = create_actor(actor_name);
    if (state->right == NULL) {
        state->right = new_actor;
    } else {
        list2 *temp = state->right;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new_actor;
    }
}

void trim_newline(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) s[--len] = '\0';
}

void trim_space(char *s) {
    char *start = s;
    while (*start && isspace((unsigned char)*start)) start++;
    if (start != s) memmove(s, start, strlen(start) + 1);
    size_t len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) s[--len] = '\0';
}

list1* find_state(list1 *head, const char *name) {
    for (list1 *p = head; p; p = p->next) {
        if (strcmp(p->name_state, name) == 0) return p;
    }
    return NULL;
}

list1* parse_file(FILE *fp) {
    char line[256];
    list1 *head = NULL, *tail = NULL;

    while (fgets(line, sizeof(line), fp)) {
        trim_newline(line);
        if (line[0] == '\0') continue;

        char *dash = strchr(line, '-');
        if (!dash) continue;
        *dash = '\0';
        char *state = line;
        char *actor = dash + 1;
        trim_space(state);
        trim_space(actor);
        if (state[0] == '\0' || actor[0] == '\0') continue;

        list1 *s = find_state(head, state);
        if (!s) {
            s = create_state(state);
            if (!head) {
                head = tail = s;
            } else {
                tail->next = s;
                tail = s;
            }
        }
        add_actor(s, actor);
    }
    return head;
}

void print_list(list1 *head) {
    for (list1 *st = head; st; st = st->next) {
        int count = 0;
        for (list2 *a = st->right; a; a = a->next) count++;
        printf("State: %s, Number of actors: %d\n", st->name_state, count);
        for (list2 *a = st->right; a; a = a->next) {
            printf("  Actor: %s (Length: %zu)\n", a->name_actor, strlen(a->name_actor));
        }
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
    return 0;
}
