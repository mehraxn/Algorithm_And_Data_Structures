node_t *insert_r(node_t *root, char *key) {
    if (root == NULL)
        return (new_node(key, NULL, NULL));
    if (strcmp(key, root->key) < 0)
        root->l = insert_r(root->l, key);
    else
        root->r = insert_r(root->r, key);
    return root;
}

node_t *insert_i(node_t *root, char *key) {
    node_t *p, *r;
    if (root == NULL) {
        return (new_node(key, NULL, NULL));
    }
    r = root;
    p = r;
    while (r != NULL) {
        p = r;
        r = (strcmp(key, r->key) < 0) ? r->l : r->r;
    }
    r = new_node(key, NULL, NULL);
    if (strcmp(key, p->key) < 0)
        p->l = r;
    else
        p->r = r;
    return root;
}
