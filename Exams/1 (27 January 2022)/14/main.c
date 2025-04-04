#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert_string(char *s1, char **s2) {
    int length = strlen(s1);
    *s2 = (char *)malloc((length + 1) * sizeof(char));
    if (*s2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int s2_index = 0;
    int start = 0;

    while (start < length) {
        int end = start;
        // Find the end of the current ascending subsequence
        while (end + 1 < length && s1[end] < s1[end + 1]) {
            end++;
        }
        // Copy the subsequence in reverse order to s2
        for (int i = end; i >= start; i--) {
            (*s2)[s2_index++] = s1[i];
        }
        // Move to the next subsequence
        start = end + 1;
    }

    (*s2)[s2_index] = '\0';
}

int main() {
    char s1[] = "ABCDDDZYXWEFG";
    char *s2 = NULL;

    invert_string(s1, &s2);
    printf("Input string: %s\n", s1);
    printf("Output string: %s\n", s2);

    // Free the allocated memory
    free(s2);
    return 0;
}