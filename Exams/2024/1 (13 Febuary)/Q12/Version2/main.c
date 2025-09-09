#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s node_t;
struct node_s {
    char *letter;
    node_t *next;
};

node_t *create_node(char *key) {
    node_t *new_node;
    new_node = (node_t *)malloc(sizeof(node_t));
    new_node->letter = strdup(key);
    new_node->next = NULL;
    return new_node;
}

void string_to_fifo(char *s, node_t **letter, node_t **digit) {
    node_t *head_string = *letter;
    node_t *head_string_temp = head_string;

    char *temp = s;
    char temp_string[strlen(s) + 1];
    int counter = 0;

    while (*s != '\0') {
        if (*s >= '0' && *s <= '9') {
            if (counter == 0) { s++; continue; }
            else {
                temp_string[counter] = '\0';
                node_t *next_move = create_node(temp_string);

                if (head_string_temp == NULL) {
                    head_string_temp = head_string = *letter = next_move;
                } else {
                    head_string_temp->next = next_move;
                    head_string_temp = next_move;
                }
                counter = 0;
            }
        }
        else if (*s >= 'a' && *s <= 'z') {
            temp_string[counter] = *s;
            counter++;
        }
        s++;
    }

    if (counter != 0) {
        temp_string[counter] = '\0';
        node_t *next_move = create_node(temp_string);
        if (head_string_temp == NULL) {
            head_string_temp = head_string = *letter = next_move;
        } else {
            head_string_temp->next = next_move;
            head_string_temp = next_move;
        }
    }

    node_t *head_digit = *digit;
    node_t *head_digit_temp = head_digit;

    s = temp;
    counter = 0;

    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') {
            if (counter == 0) { s++; continue; }
            else {
                temp_string[counter] = '\0';
                node_t *next_move = create_node(temp_string);

                if (head_digit_temp == NULL) {
                    head_digit_temp = head_digit = *digit = next_move;
                } else {
                    head_digit_temp->next = next_move;
                    head_digit_temp = next_move;
                }
                counter = 0;
            }
        }
        else if (*s >= '0' && *s <= '9') {
            temp_string[counter] = *s;
            counter++;
        }
        s++;
    }

    if (counter != 0) {
        temp_string[counter] = '\0';
        node_t *next_move = create_node(temp_string);
        if (head_digit_temp == NULL) {
            head_digit_temp = head_digit = *digit = next_move;
        } else {
            head_digit_temp->next = next_move;
            head_digit_temp = next_move;
        }
    }
}
