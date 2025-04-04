#include <stdio.h>
#include <stdlib.h>

struct node {
    char val;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *new_node(char value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
        return NULL;
    temp->val = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to double the tree
void double_tree(struct node *root, char flag) {
    if (root == NULL)
        return;

    if (flag == 'L') {
        // Create a duplicate node
        struct node *temp = new_node(root->val);
        // Link the duplicate to the left of the original node
        temp->left = root->left;
        root->left = temp;

        // Recur for the left and right subtrees of the original node
        double_tree(temp->left, 'L');  // Continue with the original left subtree
        double_tree(root->right, 'L');
    } else if (flag == 'R') {
        // Create a duplicate node
        struct node *temp = new_node(root->val);
        // Link the duplicate to the right of the original node
        temp->right = root->right;
        root->right = temp;

        // Recur for the left and right subtrees of the original node
        double_tree(root->left, 'R');
        double_tree(temp->right, 'R');  // Continue with the original right subtree
    }
}

