struct node* create_node(const char *key) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = strdup(key); // Dynamically allocate memory for the key
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void double_tree(struct node *root, char flag) {
    if (root == NULL) {
        return;
    }

    // Recursively process left and right subtrees
    double_tree(root->left, flag);
    double_tree(root->right, flag);

    // Create a duplicate node
    struct node *duplicate = create_node(root->key);

    if (flag == 'L') {
        duplicate->left = root->left;
        root->left = duplicate;
    } else if (flag == 'R') {
        duplicate->right = root->right;
        root->right = duplicate;
    }
}
