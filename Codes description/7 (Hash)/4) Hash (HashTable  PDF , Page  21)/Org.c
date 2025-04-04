
int hash(char *v, int M) {
    int h = 0;
    int base = 128;

    while (*v != '\0') {
        h = (h * base + *v) % M;

        v++;
    }

    return h;
}
