#include <stdio.h>
#include <stdlib.h>

typedef struct t2 {
    int col;
    int value;
    struct t2* next;
} list_t2;

typedef struct t1 {
    int row;
    list_t2* col_list;
    struct t1* next;
} list_t1;

void insert_t2(list_t2** head, int col, int value) {
    list_t2* new_t2 = (list_t2*)malloc(sizeof(list_t2));
    if (new_t2 == NULL) {
        printf("Error allocating memory\n");
        exit(-1);
        }
    new_t2->col = col;
    new_t2->value = value;
    new_t2->next = NULL;

    if (*head == NULL) {
        *head = new_t2;
    } else {
        list_t2* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_t2;
    }
}
void insert_t1(list_t1** head, int row, int col, int value) {
    list_t1* new_t1 = *head;
    list_t1* prev_t1 = NULL;

    while (new_t1 != NULL && new_t1->row < row) {
        prev_t1 = new_t1;
        new_t1 = new_t1->next;
    }

    if (new_t1 == NULL || new_t1->row > row) {
        list_t1* temp = (list_t1*)malloc(sizeof(list_t1));
        if (temp==NULL){
            printf("Error allocating memory \n");
            exit(-1);
        }
        temp->row = row;
        temp->next = new_t1;
        temp->col_list = NULL;

        if (prev_t1 != NULL) {
            prev_t1->next = temp;
        } else {
            *head = temp;
        }

        new_t1 = temp;
    }

    insert_t2(&(new_t1->col_list), col, value);
}

void print_list(list_t1* head) {
    list_t1* temp = head;
    while (temp != NULL) {
        printf("Row: %d\n", temp->row);
        list_t2* col_list = temp->col_list;
        while (col_list != NULL) {
            printf("Column: %d, Value: %d\n", col_list->col, col_list->value);
            col_list = col_list->next;
        }
        temp = temp->next;
        printf("\n"); 
    }
}

void transpose(list_t1* head1, list_t1** head2) {
    list_t1* temp1 = head1;
    while (temp1 != NULL) {
        list_t2* col_list = temp1->col_list;
        while (col_list != NULL) {
            insert_t1(head2, col_list->col, temp1->row, col_list->value);
            col_list = col_list->next;
        }
        temp1 = temp1->next;
    }
}

void free_list(list_t1* head) {
    list_t1* temp1 = head;
    while (temp1 != NULL) {
        list_t2* temp2 = temp1->col_list;
        while (temp2 != NULL) {
            list_t2* next = temp2->next;
            free(temp2);
            temp2 = next;
        }
        list_t1* next = temp1->next;
        free(temp1);
        temp1 = next;
    }
}

int main() {
    FILE* fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    list_t1* head1 = NULL;
    int value=0;
    int col=0;
    int row=0;
    int file_cols=0;
    fscanf(fin,"%d",&file_cols);
    while (fscanf(fin, "%d", &value) == 1) {
        if(value!=0)
        insert_t1(&head1, row, col, value);
        col++;
        if (col == file_cols) {
            col = 0;
            row++;
        }
    }

    fclose(fin);

    printf("Starting Matrix:\n");
    print_list(head1);

    list_t1* head2 = NULL;
    transpose(head1, &head2);

    printf("Transposed Matrix:\n");
    print_list(head2);

    free_list(head1);
    free_list(head2);

    return 0;
}
