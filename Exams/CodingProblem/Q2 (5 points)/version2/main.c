/* ADDED: headers required for malloc/strcpy */
#include <stdlib.h>
#include <string.h>

struct node {
    char * string ;
    struct node * left ;
    struct node * right;
}; /* CHANGED: missing semicolon after struct */

struct node * create_node (char *string){

    /* CHANGED: allocate correct size for struct */
    struct node * temp =(struct node *)malloc(sizeof(struct node));
    /* CHANGED: allocate and copy dynamic string */
    temp->string = (char*)malloc(strlen(string) + 1);
    strcpy(temp ->string,string);
    temp->left = NULL;
    temp-> right =NULL;
    /* ADDED: return the created node */
    return temp;
}


void visit_left (struct node * root){

    if (root==NULL)	return ;

    /* CHANGED: save original children to avoid recursing into the new duplicate */
    struct node * old_left = root->left;
    struct node * old_right = root->right;

    /* CHANGED: use root->string (not undefined 'string') */
    struct node * new =create_node(root->string);
    new->left =old_left;
    new->right = NULL;
    root->left =new ;

    /* CHANGED: recurse on original children; fixed typo 'visir_left' */
    visit_left(old_left);
    visit_left(old_right);
}

/* ADDED: needed to support flag == 'R' */
void visit_right (struct node * root){

    if (root==NULL)	return ;

    struct node * old_left = root->left;   /* ADDED */
    struct node * old_right = root->right; /* ADDED */

    struct node * new =create_node(root->string); /* ADDED */
    new->right = old_right;                       /* ADDED */
    new->left = NULL;                             /* ADDED */
    root->right = new;                            /* ADDED */

    visit_right(old_left);                        /* ADDED */
    visit_right(old_right);                       /* ADDED */
}


void double_tree (struct node * root, char flag){
    /* ADDED: dispatch based on required side */
    if (flag=='L') visit_left(root);
    else if (flag=='R') visit_right(root);
}
