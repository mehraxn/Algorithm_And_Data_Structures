#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst_t bst_t;
typedef struct list_t list_t;


struct list_t {
    char *str;
    list_t *next;
} ;

struct bst_t {
    bst_t *left, *rigth;
    list_t *l_head;
    int key;
} ;



bst_t *insert (char *name);
bst_t *new_node(int key);
list_t *add_list(list_t *head, char *str);

void traverse(bst_t *root);
void freeAll(bst_t *root);

int main() {
    bst_t *root = insert("infile.txt");
    traverse(root);
    freeAll(root);
    printf("%d", root->key);
    return 0;
}

bst_t *insert (char *name) {
    FILE *f;
    bst_t *root;
    bst_t *tmp;
    list_t *list_tmp;
    int n;
    char s[100];

    if((f = fopen(name, "r")) == NULL) {
        printf("Error while opening the file '%s'\n", name);
        return NULL;
    }

    if(fscanf(f, "%d %s", &n, s) != 2)
        return NULL;

    root = new_node(n);                             //Creation of the head node of the bst
    root->l_head = add_list(root->l_head, s);

    while(fscanf(f, "%d %s", &n, s) == 2) { //while we read new lines in the file
        tmp = root;                                      //we create a node to traverse the bst
        while(tmp->key != n) {
            if(tmp->key > n) {
                //Move to the right
                if(tmp->rigth == NULL) {                //If the key we are looking for is not present in the bst we create it
                    tmp->rigth = new_node(n);
                    tmp = tmp->rigth;
                } else
                    tmp = tmp->rigth;                    //If we have not found the key we are looking for we move to the right
            }
            else {
                //We perform the same set of operations but moving left instead
                if(tmp->left== NULL) {
                    tmp->left = new_node(n);
                    tmp = tmp->left;
                } else
                    tmp = tmp->left;
            }
        }
        //We add a new element to the list related to the node we are on
        tmp->l_head = add_list(tmp->l_head, s);
    }

    fclose(f);
    return root;
}

bst_t *new_node(int key) {
    bst_t *new;
    new = malloc(sizeof(bst_t));
    new->key = key;
    new->left = NULL;
    new->rigth = NULL;
    new->l_head = NULL;
}

list_t *add_list(list_t *head, char *str) {
    list_t *tmp;
    tmp = malloc(sizeof(list_t));
    tmp->next = head;
    tmp->str = strdup(str);
    return tmp;
}

void traverse(bst_t *root) {
    if(root == NULL)
        return;

    list_t *tmp;
    printf("- %d ", root->key);
    tmp = root->l_head;
    while(tmp != NULL) {
        printf("- %s ", tmp->str);
        tmp = tmp->next;
    }
    printf("\n");
    traverse(root->left);
    traverse(root->rigth);
    return;
}

void freeAll(bst_t *root) {
    if(root == NULL)
        return;

    list_t *tmp, *tmp2;
    tmp = root->l_head;
    while(tmp != NULL) {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }

    freeAll(root->left);
    freeAll(root->rigth);
    free(root);
    return;
}