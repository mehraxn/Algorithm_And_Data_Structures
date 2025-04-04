int bin_search(int v[], int l, int r, int k) {
    int c;
    if (l > r)
        return -1;
    c = (l + r) / 2;
    if (k < v[c])
        return bin_search(v, l, c - 1, k);
    if (k > v[c])
        return bin_search(v, c + 1, r, k);
    return c;
}