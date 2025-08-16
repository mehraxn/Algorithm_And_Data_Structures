int strlen (char str[]) {
    int cnt;
    cnt = 0;
    while (str[cnt] != '\0')
        cnt++;
    return cnt;
}

int strlen (char *str) {
    int cnt;
    cnt = 0;
    while (*str != '\0') {
        cnt++;
        str++;
    }
    return cnt;
}
int strlen (char str[]) {
    int cnt;
    char *p;
    cnt = 0;
    p = &str[0];
    while (*p != '\0') {
        cnt++;
        p++;
    }
    return cnt;
}


int strlen (char *str) {
    char *p;
    p = str;
    while (*p != '\0') {
        p++;
    }
    return (p - str);
}
