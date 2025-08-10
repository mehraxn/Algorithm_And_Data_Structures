#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getFrequencyArray(char* str, int* returnSize) {
    if (str == NULL || strlen(str) == 0) {
        *returnSize = 0;
        return NULL;
    }

    int len = strlen(str);
    int* freq = (int*)malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (str[i] == str[j]) {
                count++;
            }
        }
        freq[i] = count;
    }

    *returnSize = len;
    return freq;
}
