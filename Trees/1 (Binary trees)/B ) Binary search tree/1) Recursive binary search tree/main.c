#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    char* key;
    struct node_t* left;
    struct node_t* right;
} node;

// Function declaration
node* binary_search_tree(node* root, char* key_search);

int main() {
    printf("Hello, World!\n");
    return 0;
}

// Binary search function for strings in a binary search tree
node* binary_search_tree(node* root, char* key_search) {


    if (root == NULL)
        return NULL;


    if (strcmp(key_search, root->key) < 0)
        return binary_search_tree(root->left, key_search);


    else if (strcmp(key_search, root->key)  > 0)
        return binary_search_tree(root->right, key_search);


    else
        return root;

}
