node_t *search_r(node_t *root, char *key) {
    if (root == NULL)
        return (NULL);
    if (strcmp(key, root->key) < 0)
        return (search_r(root->l, key));
    if (strcmp(key, root->key) > 0)
        return (search_r(root->r, key));
    return root;
}

node_t *search_i(node_t *root, char *key) {
    while (root != NULL) {
        if (strcmp(key, root->key) == 0)
            return (root);
        if (strcmp(key, root->key) < 0)
            root = root->l;
        else
            root = root->r;
    }
    return (root);
}
