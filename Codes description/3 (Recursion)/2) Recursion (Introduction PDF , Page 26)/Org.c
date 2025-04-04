int max(int v[], int l, int r) {
    int c, m1, m2;
    if (l >= r)
        return v[l];
    c = (l + r) / 2;
    m1 = max(v, l, c);
    m2 = max(v, c + 1, r);
    if (m1 > m2)
        return m1;
    else
        return m2;
}
