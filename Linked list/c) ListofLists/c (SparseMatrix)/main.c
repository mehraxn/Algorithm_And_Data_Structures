#include <stdio.h>
#include <stdlib.h>

// Define column node
typedef struct ColNode {
    int value;
    int column;
    struct ColNode* next;
} ColNode;

// Define row node
typedef struct Row {
    int row;
    ColNode* cols;
    struct Row* next;
} Row;

// Create a new column node
ColNode* create_col_node(int value, int column) {
    ColNode* node = (ColNode*)malloc(sizeof(ColNode));
    node->value = value;
    node->column = column;
    node->next = NULL;
    return node;
}

// Create a new row node
Row* create_row(int row_index) {
    Row* row = (Row*)malloc(sizeof(Row));
    row->row = row_index;
    row->cols = NULL;
    row->next = NULL;
    return row;
}

// Add a column node to the end of a row's column list
void append_col(Row* row, int column_index, int value) {
    ColNode* new_col = create_col_node(value, column_index);
    if (row->cols == NULL) {
        row->cols = new_col;
    } else {
        ColNode* temp = row->cols;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_col;
    }
}

// Add a row node to the end of the matrix
void append_row(Row** head, Row* new_row) {
    if (*head == NULL) {
        *head = new_row;
    } else {
        Row* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_row;
    }
}

// Print the matrix
void print_matrix(Row* head) {
    while (head) {
        printf("Row %d: ", head->row);
        ColNode* col = head->cols;
        while (col) {
            printf("[Col %d = %d] ", col->column, col->value);
            col = col->next;
        }
        printf("\n");
        head = head->next;
    }
}

// Free the matrix
void free_matrix(Row* head) {
    while (head) {
        ColNode* col = head->cols;
        while (col) {
            ColNode* tmp_col = col;
            col = col->next;
            free(tmp_col);
        }
        Row* tmp_row = head;
        head = head->next;
        free(tmp_row);
    }
}

// Main
int main() {
    Row* matrix = NULL;

    for (int i = 0; i < 3; i++) {
        Row* new_row = create_row(i);
        for (int j = 0; j < 4; j++) {
            append_col(new_row, j, i * 10 + j);  // Example: value = row*10 + col
        }
        append_row(&matrix, new_row);
    }

    printf("Matrix (List of Lists):\n");
    print_matrix(matrix);

    free_matrix(matrix);
    return 0;
}
