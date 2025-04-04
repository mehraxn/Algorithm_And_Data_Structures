node_t *max_delete_r(char *val, node_t *root) {
    node_t *tmp;

    if (root->r == NULL) {
        *val = root->key;
        tmp = root->l;
        free(root);
        return (tmp);
    }

    root->r = max_delete_r(val, root->r);
    return (root);
}
