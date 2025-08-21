#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert_string(char *s1 , char **s2 ) {
    int length = strlen(s1);
    char *temp_pointer = s1;

    *s2 = (char *) malloc((length + 1) * sizeof(char));

    int i = 0;
    int j = 0;

    while (i < length) {
        int start = i;

        while (i + 1 < length && s1[i] < s1[i + 1])
            i++;

        for (int k = i; k >= start; k--)
            (*s2)[j++] = s1[k];

        i++;
    }

    (*s2)[j] = '\0';
}
