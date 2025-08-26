#include <stdio.h>
#include <stdlib.h>   // ADDED: for malloc/free
#include <string.h>   // ADDED: for strdup/sscanf

typedef struct list_string list;
typedef struct BST bst;
typedef struct BST bst_t;

struct list_string {
    char * string;
    list * next;
};

struct BST {
    int key ;
    list * head;
    bst * left ;
    bst * right ;
};

list * create_node_list (char *string){
    list * head =(list *)malloc(sizeof(list));
    // CHANGED: use head (not list), allocate/copy the string
    head->string = strdup(string);  // CHANGED: dynamic copy of string
    head->next = NULL;              // CHANGED: use head, not list
    return head;
}

bst * create_node_bst (int value){
    bst * head =(bst *)malloc(sizeof(bst));
    head->key = value;
    head->head = NULL;
    head->left = NULL;
    head->right = NULL;    // CHANGED: fixed typo "haed->right"
    return head;           // CHANGED: fixed typo "retutn"
}

// insert a key into the BST (no list update here)
bst *insert_node (bst * root , int value ){
    if (root==NULL) return create_node_bst(value);

    if (value < root->key) {                    // CHANGED: correct comparison/recursion
        root->left = insert_node(root->left, value);
    } else if (value > root->key) {             // CHANGED: correct comparison/recursion
        root->right = insert_node(root->right, value);
    }
    return root;
}

int number_node (char * name){
    FILE *fp = fopen(name,"r");
    if (!fp) return 0; // ADDED: basic safety
    char temp_string[256];
    int counter = 0;
    while (fgets(temp_string, sizeof(temp_string), fp) != NULL){ // CHANGED: sizeof + fixed var name
        counter++;
    }
    fclose (fp);
    return counter;
}

// append the given string to the list stored at node with 'value'
void check_string_in_BST (bst *root , int value , char *string){
    if (root == NULL) return;                 // ADDED: guard

    if (root->key == value){                  // CHANGED: '==' instead of '='
        if (root->head == NULL) {             // ADDED: handle empty list on the node
            root->head = create_node_list(string);
            return;
        }
        list * temp = root->head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = create_node_list(string);
        return;                                // CHANGED: remove stray character
    }

    if (value < root->key) check_string_in_BST (root->left, value, string);
    else                   check_string_in_BST (root->right, value, string);
    return ;
}

bst_t *insert (char *name){
    int number = number_node(name);

    FILE * fp = fopen(name,"r");
    if (!fp) return NULL;                      // ADDED: safety

    // collect unique keys first (kept your approach)
    int *array = (int *)malloc(number * sizeof(int));
    int counter = 0;
    char temp[256];

    while (fgets(temp, sizeof(temp), fp) != NULL){
        int temp_number;
        if (sscanf(temp, "%d", &temp_number) != 1) continue; // CHANGED: correct sscanf usage
        int flag = 0;
        for (int i = 0 ; i < counter ; i++){
            if (array[i] == temp_number) { flag = 1; break; }
        }
        if (flag == 0) array[counter++] = temp_number;        // CHANGED: missing semicolon
    }
    fclose(fp);                                               // CHANGED: close here

    bst * head = NULL;
    for (int j = 0; j < counter; j++)
        head = insert_node(head, array[j]);                   // CHANGED: fixed name/return

    // second pass: attach strings to their node lists
    fp = fopen(name , "r");                                   // CHANGED: reuse variable, reopen
    if (!fp) { free(array); return head; }                    // ADDED: safety

    while (fgets(temp, sizeof(temp), fp) != NULL){
        char final_String[128];                               // CHANGED: slightly larger buffer
        int temp_num;
        if (sscanf(temp, "%d %127s", &temp_num, final_String) == 2) { // CHANGED: correct parse + bounds
            check_string_in_BST(head, temp_num, final_String);
        }
    }
    fclose(fp);                                               // ADDED

    free(array);                                              // ADDED: free temp array
    return head;                                              // ADDED: return the built BST
}
