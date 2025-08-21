node_t *min_r(node_t *root) {
    if (root == NULL)
        return (NULL);
    if (root->l == NULL)
        return (root);
    return min_r(root->l);
}

node_t *max_r(node_t *root) {
    if (root == NULL)
        return (NULL);
    if (root->r == NULL)
        return (root);
    return max_r(root->r);
}

node_t *min_i(node_t *root) {
    if (root == NULL)
        return (NULL);
    while (root->l != NULL)
        root = root->l;
    return (root);
}

node_t *max_i(node_t *root) {
    if (root == NULL)
        return (NULL);
    while (root->r != NULL)
        root = root->r;
    return (root);
}
