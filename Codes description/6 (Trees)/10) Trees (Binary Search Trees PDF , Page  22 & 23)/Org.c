node_t *delete_r(node_t *root, char *key) {
    node_t *p;
    char *val;

    if (root == NULL)
        return (root);

    if (strcmp(key, root->key) < 0) {
        root->l = delete_r(root->l, key);
        return (root);
    }

    if (strcmp(key, root->key) > 0) {
        root->r = delete_r(root->r, key);
        return (root);
    }

    // Node to be deleted found
    p = root;

    if (root->r == NULL) {
        root = root->l;
        free(p);
        return (root);
    }

    if (root->l == NULL) {
        root = root->r;
        free(p);
        return (root);
    }

    // Replace with the max value from the left subtree
    root->l = max_delete_r(&val, root->l);
    root->key = val;

    return (root);
}
